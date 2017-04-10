
Here is a very simple example from scratch.

http://tuxthink.blogspot.in/2011/04/wait-queues.html#!


and here is a second example which is broken in 6 chapters:

http://tuxthink.blogspot.com/2010/10/writing-example-driver-from-scratch.html
http://tuxthink.blogspot.com/2010/11/writing-example-driver-from-scratch.html
http://tuxthink.blogspot.com/2010/11/writing-example-driver-from-scratch_08.html
http://tuxthink.blogspot.in/2010/11/writing-example-driver-from-scratch_13.html
http://tuxthink.blogspot.in/2010/11/writing-example-driver-from-scratch_23.html
http://tuxthink.blogspot.in/2012/02/writing-example-driver-from-scratch.html

==========================================================

WAIT QUEUE  wait queue
http://tuxthink.blogspot.in/2011/04/wait-queues.html#!


Wait queues
While writing modules there might be situations where one might have to wait for input some condition to occur before proceeding further. Tasks that need such behavior can make use of the sleep functionality available in the kernel.
In Linux sleeping is handled by a data structure called wait queue, which is nothing but a list of processes waiting for an input or  event. 
The post explains an example module that makes use of the concept of sleeping.

To manage a wait queue ,we need a structure of the kind wait_queue_head_t, which is defined in linux/wait.h.

Wait queue head can be initialized in the following ways
Statically using :

DECLARE_WAIT_QUEUE_HEAD(name);

Dynamically using :


wait_queue_head_t my_queue;
init_waitqueue_head(name);

Where the "name" is the name of the queue on which task  will be put to sleep.

Once the wait queue has been created, we can put a task to sleep on the queue we created using one of the following.

wait_event("queue","condition") : The task will keep waiting on the queue as long as the condition does not become true.If put to sleep using this call, the task can not be interrupted.

wait_event_interruptible("queue","condition") : similar to wait_event, but it can be interrupted by other signals too. It is always preferable to use this interruptible way of sleeping so that the task can be stopped in case the condition never becomes true.

wait_event_timeout("queue","condition","timeout") : The task will sleep on the queue until the condition becomes
true or the timeout mentioned expires, which ever occurs first. The timeout is expressed in jiffies. Task can not be interrupted before the timeout if the condition does not become true.

wait_event_interruptible_timeout("queue","condition","timeout") : Similar to wait_event_timeout but it can be interrupted.

Once a task has been put to sleep we need to wake it up , which can be done using following :

wake_up(queue)  : In case the task has been put to non interruptible sleep.
wake_up_interruptible (queue) : In case the task has been put to an interruptible sleep.

The example below is the module that we created in "Writing a character driver from scratch".
A flag has been added to the module, which is verified when the module is read by any application. If the
flag is set to "n", then the task will be put to sleep as long as the value of the flag is not changed.

The modified read looks as follows.


ssize_t read(struct file *filp, char *buff, size_t count, loff_t *offp) {
    unsigned long ret;
    printk(KERN_INFO "Inside read \n");
    wait_event_interruptible(queue, flag != 'n'); // putting to sleep if flag is equal to "n".
    printk(KERN_INFO "Woken Up");
    ret = copy_to_user(buff, char_arr.array, count); // Sending data to user space.
    return ret;
}


To change the flag the module makes use of a proc entry. We can write a character to the proc entry /proc/wait, and the same will be assigned to flag. Then the wake_up is called to wake_up the sleeping tasks.

The code for the proc entry is as follows.

int write_proc(struct file *file,const char *buffer,unsigned long count,void *data)
{
int ret=0;
printk(KERN_INFO "procfile_write /proc/wait called");
ret = __get_user(flag,buffer); // The value sent by the user is assigned to flag.
wake_up_interruptible(&queue); //wake up all the tasks waiting on the queue.
return ret;
}

Here is complete code for the module.

######################read_wait.c##############################


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // required for various structures related to files liked fops.
#include <asm/uaccess.h> // required for copy_from and copy_to user functions
#include <linux/semaphore.h>
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/wait.h> // Required for the wait queues
#include <linux/sched.h> // Required for task states (TASK_INTERRUPTIBLE etc )


static int Major;
struct proc_dir_entry *Our_Proc_File;
wait_queue_head_t queue;
char flag = 'n';


struct device {
    char array[100];
    struct semaphore sem;
}char_arr;


int open(struct inode *inode, struct file *filp)
{
   
    printk(KERN_INFO "Inside open \n");
    if(down_interruptible(&char_arr.sem)) {
        printk(KERN_INFO " could not hold semaphore");
        return -1;
    }
    return 0;
}


int release(struct inode *inode, struct file *filp) {
    printk (KERN_INFO "Inside close \n");
    printk(KERN_INFO "Releasing semaphore");
    up(&char_arr.sem);
    return 0;
}


ssize_t read(struct file *filp, char *buff, size_t count, loff_t *offp) {
    unsigned long ret;
    printk("Inside read \n");
    wait_event_interruptible(queue, flag != 'n');
    printk(KERN_INFO "Woken Up");
    ret = copy_to_user(buff, char_arr.array, count);
    return ret;
}


ssize_t write(struct file *filp, const char *buff, size_t count, loff_t *offp) {   
    unsigned long ret;
    printk(KERN_INFO "Inside write \n");
    ret =    copy_from_user(char_arr.array, buff, count);
    return ret;
}






int write_proc(struct file *file,const char *buffer,unsigned long count,void *data)
{
int ret=0;
printk(KERN_INFO "procfile_write /proc/wait called");
ret = __get_user(flag,buffer);
printk(KERN_INFO "%c",flag);
wake_up_interruptible(&queue);
return ret;
}


void create_new_proc_entry()
{
Our_Proc_File = create_proc_entry("wait", 0666, NULL);
   
    if(Our_Proc_File == NULL) {
        remove_proc_entry("wait", NULL);
        printk(KERN_ALERT "Error: could not initialize /proc/wait\n");
        return -ENOMEM;
    }
    Our_Proc_File->write_proc = write_proc;
    printk(KERN_INFO "/proc/wait created \n");
   
}


struct file_operations fops = {
    read:        read,
    write:        write,
    open:         open,
    release:    release
};




struct cdev *kernel_cdev;




int char_arr_init (void) {
    int ret;
    dev_t dev_no,dev;


    kernel_cdev = cdev_alloc();   
     kernel_cdev->ops = &fops;
    kernel_cdev->owner = THIS_MODULE;
    printk (" Inside init module\n");
     ret = alloc_chrdev_region( &dev_no , 0, 1,"chr_arr_dev");
    if (ret < 0) {
        printk("Major number allocation is failed\n");
        return ret;   
    }
   
    Major = MAJOR(dev_no);
    dev = MKDEV(Major,0);
    sema_init(&char_arr.sem,1);   
    printk (" The major number for your device is %d\n", Major);
    ret = cdev_add( kernel_cdev,dev,1);
    if(ret < 0 )
    {
    printk(KERN_INFO "Unable to allocate cdev");
    return ret;
    }
    init_waitqueue_head(&queue);
    create_new_proc_entry();
    return 0;
}


void char_arr_cleanup(void) {
    printk(KERN_INFO " Inside cleanup_module\n");
    remove_proc_entry("wait",NULL);
    cdev_del(kernel_cdev);
    unregister_chrdev_region(Major, 1);
}
MODULE_LICENSE("GPL");   
module_init(char_arr_init);
module_exit(char_arr_cleanup);
#################################################################


########################Makefile####################################
ifneq ($(KERNELRELEASE),)
   obj-m := read_wait.o
else


KERNELDIR ?= /lib/modules/$(shell uname -r)/build


PWD := $(shell pwd)


default:
    $(MAKE) -C $(KERNELDIR) M=$(PWD) modules 
endif
clean:
    $(MAKE) -C $(KERNELDIR) M=$(PWD) clean


###########################################################




To test the example we will need a user application to read write from the device. The following can be used for the same.




###########################user_app.c#############################
#include <stdio.h>
#include <fcntl.h>




main ( ) {
        int i,fd;
        char ch, write_buf[100], read_buf[100];


        fd = open("/dev/temp", O_RDWR);


        if (fd == -1)
        {
                printf("Error in opening file \n");
                exit(-1);
        }
        printf ("Press r to read from device or w to write the device ");
        scanf ("%c", &ch); 




        switch (ch) {
                case 'w':
                       printf (" Enter the data to be written into device");
                        scanf (" %[^\n]", write_buf);
                        write(fd, write_buf, sizeof(write_buf));
                        break;
                case 'r':


                        read(fd, read_buf, sizeof(read_buf));
                        printf ("The data in the device is %s\n", read_buf);
                        break;


                default:
                        printf("Wrong choice \n");
                        break;
        }
        close(fd);
}


###################################################




Note: To understand the module completely you can go through the post "Writing a character driver from scratch".

To check the working of the code run the following commands

$ make
$ sudo insmod read_wait.ko
$ dmesg   //   You should see the major number allocated to the module, note the  same. Assume  it is 250.
$ sudo mknod /dev/temp c 250 0
$ cc user_app.c
$ sudo ./a.out
Press r to read from device or w to write the device  w     // Writing data to the device
 Enter the data to be written into device 1234


$ sudo ./a.out
Press r to read from device or w to write the device  r  // (Now the task should go sleep)

Open another terminal and run the command

$ echo "y" > /proc/wait

Now go back to the previous terminal, the read should have woken up and displayed the contents of the that we wrote before.

