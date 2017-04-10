
Here is a very simple example from scratch.

http://tuxthink.blogspot.in/2011/04/wait-queues.html#!


and here is a second example which is broken in 6 chapters:

http://tuxthink.blogspot.com/2010/10/writing-example-driver-from-scratch.html
http://tuxthink.blogspot.com/2010/11/writing-example-driver-from-scratch.html
http://tuxthink.blogspot.com/2010/11/writing-example-driver-from-scratch_08.html
http://tuxthink.blogspot.in/2010/11/writing-example-driver-from-scratch_13.html
http://tuxthink.blogspot.in/2010/11/writing-example-driver-from-scratch_23.html
http://tuxthink.blogspot.in/2012/02/writing-example-driver-from-scratch.html


=============================================

http://tuxthink.blogspot.com/2010/10/writing-example-driver-from-scratch.html

 Writing an Example Driver From Scratch: Chapter-1 Header files
Chapter-1 Header files 

The series of posts explains writing a small example driver right from the scratch. There is no physical device, but we will take an array and consider it as our device for which the driver will be written.
The code is inspired by the example codes provided with the book "The Device Drivers" by Alessandro Rubini
Prerequisites
Basic knowledge of kernel programming and c Programming.

The driver being described is for 2.6.x kernels.

We will call the device  char_dev , which will be a structure as follows

struct device {
        char array[100];
        struct semaphore sem;
}char_dev;

So our device can hold a maximum of 100 characters and its concurrent access can be controlled using the semaphore "sem".

In this driver we will implement the following 4 operations for the device
Open.
Read.
Write.
Close.

As this is a basic driver we will not be implementing any control over the data being accepted from the user.

To begin with let us look at the possible header files we might need to write the driver.
As we are going to write a kernel program and it is going to be a module we would need the following two header files

linux/module.h
linux/kernel.h

Next to do the read and write we will make use of the functions copy__to_user and copy_from_user, for these operations we will need the header file

asm/uaccess.h

To make use of the semaphores as and when needed, we will need

linux/semaphore.h

And as we are going to write a character driver, we will need the following file

linux/cdev.h


So we can begin writing our module by including the required above files




#include < linux/module.h >
#include < linux/kernel.h >
#include < linux/fs.h>
#include < asm/uaccess.h >
#include < linux/semaphore.h >
#include < linux/cdev.h >


The next step is to figure out how do we write the init function. Init function that gets called the moment we insert the module into kernel.

=======================================================================
http://tuxthink.blogspot.com/2010/11/writing-example-driver-from-scratch.html

 Writing an Example Driver From Scratch: Chapter- 2 The init function
This is how our driver code looks as of now. We have the header files and the dummy device array.

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/semaphore.h>
#include <linux/cdev.h>
static int Major;

struct device {
 char array[100];
 struct semaphore sem;
}char_arr;

The next step is to start with the init function.

The new kernel versions use a cdev structure to keep track of all the character devices, hence we would need a cdev structure for our device too.

struct cdev *kernel_cdev;

Let us call our cdev as kernel_cdev as declared above.
We will use dynamic allocation of major number for our device as that is the safest way to assign a major number to your device.
The function that will help us allocate a major number dynamically is

int alloc_chrdev_region(dev_t *dev, unsigned int firstminor,unsigned int count, char *name);

The arguments being passed to the function are
dev -> The dev_t variable type,which will get the major number that the kernel allocates.
firstminor -> The first minor number in case you are looking for a series of minor numbers for your driver.
count -> The number of contiguous set of major numbers that you want to be allocated.
name -> Name of your device that should be associated with the major numbers. The same name will appear in /proc/devices.

The dev_t variable to be passed to the above function can be declared as follows.

dev_t devno

We will allocate minor numbers starting from 0, which is a common practice.
We need only one device number allocated as it is only a single driver for one device so count=1.
Name = char_arr_dev
you can select any name of your comfort. so our call to alloc_chrdev_region would look like this 



ret = alloc_chrdev_region( &dev_no , 0, 1,"char_arr_dev");



Where ret is an "int" variable. If alloc_chrdev_region returns a value less than 0, then the alloc_chrdev_region failed to allocate a major number, and your init function should exit with a error message.
Hence we add a check to confirm the allocation


if (ret < 0) {
  printk(KERN_INFO "Major number allocation is failed\n");
  return ret; 
 }


If the alloc_chrdev_region succeeds then the dev_no variable will have the combination major number that the kernel has allocated to your driver and the first minor number that we had selected.
To extract the major number from the dev_no we can use the macro MAJOR. MAJOR takes as input a dev_t variable and returns the major number in intiger format.


Major = MAJOR(dev_no)
printk("KERN_INFO "The major number is %d",Major); 


"
So that after doing an "insmod" of your driver you run the command dmesg and see the major number allocated which is printed by the printk.
If you were allocating the major number statically, then we would need to convert the integer number to dev_t format by combining it with the corresponding minor number which is done by the macro MKDEV.

MKDEV takes two integer numbers as input, Major number and minor number, and converts them into one dev_t type number.

dev_no = MKDEV(Major,0)

Where "dev_no" is a variable of type dev_t. This "dev" can be used for registering the driver.

Once we have the "dev_no" number we can create create our cdev structure.

Allocation:

kernel_cdev = cdev_alloc(); 

This will initialize the stand alone "kernel_cdev" structure at runtime.
Next step is allocating the fops to the cdev structure. (We will cover fops in the next chapter). 

kernel_cdev->ops = &fops; 
kernel->owner = THIS_MODULE; 

These two assignments sets up the structure as required for us. Now we can inform the kernel about this cdev structure using the cdev_add call.

int cdev_add(struct cdev *dev, dev_t num, unsigned int count);

Where
dev: is the cdev structure that we have setup num: is the dev_t number having the major and minor number in it, the first number the device responds to . count: The number of number of device numbers that are associated with this cdev structure.

I our case the call would as follows

 ret = cdev_add( kernel_cdev,dev_no,1);



Again, if the "ret" value is less than 0 then it means the kernel could not add the cdev structure and hence we need to exit the init module.

if(ret < 0 ) 
 {
 printk(KERN_INFO "Unable to add cdev");
 return ret;
 }

if the cdev_add happens with out any errors we are almost done with the init function. Only thing left is initializing the device semaphore. 

sema_init(&char_arr.sem,1);

Cleanup Function:

Cleanup is pretty simple.We just need to delete the cdev structure using the call cdev_del
void cdev_del(struct cdev *dev);

Which in our case would be 

cdev_del(kernel_cdev)


Then unregister the device using

void unregister_chrdev_region(dev_t first, unsigned int count);
Where
first: first dev_t number of a contagious set of drivers that we want to unregister.
count: The number of drivers to be unregistered.
In our case it would be 

unregister_chrdev_region(dev_no, 1);

Now we need to inform the kernel which are our init and cleanup functions
So we make use of the functions module_init and module_exit 


module_init("init function name")
module_exit("Cleanup function name")

==========================================================================
http://tuxthink.blogspot.com/2010/11/writing-example-driver-from-scratch_08.html


 Writing an Example Driver From Scratch: Chapter -3 fops implementatoin
From what we have learnt in the last two chapters, our code should look some thing like this

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // required for various structures related to files liked fops. 
#include <asm/uaccess.h> // required for copy_from and copy_to user functions 
#include <linux/semaphore.h>
#include <linux/cdev.h>   
static int Major;

struct device {
 char array[100];
 struct semaphore sem;
}char_arr;

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

 return 0;
}

void char_arr_cleanup(void) {
 printk(KERN_INFO " Inside cleanup_module\n");
 cdev_del(kernel_cdev);
 unregister_chrdev_region(Major, 1);
}
module_init(char_arr_init);
module_cleanup(char_arr_cleanup);


The next step now is to define the file operations that we wish to implement in our driver. For this we would need a structure of the kind file_operation. The structure is defined in linux/fs.h. The structure is basically a set of function pointers, and a driver can choose to implement what ever set of functions it wants to implement and declare them in the driver. For our case we had planned to support, read,write,open and release operations which can be done as follows.

struct file_operations fops = { read: read, write: write, open: open, release: release };

Please note that the format of the structure is very different from what you would come across in normal "c" structures. This format is specific to the kernel modules.

The column on the left is the name of the operation that we want to support and, the value on the right is the name of the function that will implement the operation. Which means "read" operation will be implemented by a function called "read", "write" operation will be implemented by a function called "write". The function names could be any thing of your choice as long as you use the same name in the structure as well as the actual implementation of the function.

By specifying the function names in this fashion using the file_operations structure, we are informing the kernel which function to call for which operation.

So when kernel wants to read from your device, it will get the pointer to function that will do the read operation from the file_operation structure.

Now that we have declared the operations supported by the driver, we have to actually implement the function in the driver.

Let us start from the "open" operation.

Open:

The open calls takes two arguments, the inode and the file pointer to the file being opened and should return 1 or 0 depending on failure or success of the function, respectively.

int open(struct inode *inode, struct file *filp)

For our device, there is nothing much we need to do in the open as we just have small array as a device.

We will just hold the semaphore so that only one process is allowed to open the device at a given time.

The function that will allow us to hold the semaphore is down_interruptible(struct *semaphore).

So for our device it would be

down_interruptible(&char_arr.sem)

If we fail to hold the semaphore we need to fail gracefully so we a put this call into a "if" condition.

if(down_interruptible(&char_arr.sem)) {
printk(KERN_INFO " could not hold semaphore");
return -1;
}

If any other process is holding the device, we would print the relevant message and fail.

In case there is no other process holding the device, we need to indicate success of the open call by a return 0

Once we have the device open, the next step would be either "read" data from the device or "write" data in to the device.

Let us look at the read function first.

Read :

The read function takes as arguments

A pointer to the struct file

A pointer to a char, which is a buffer into which the data from the device will be read into
A variable of the type size_t, a count of number bytes of data to be transfered into the buffer
A pointer of type loff_t, which is a pointer to the current position or the offset being read in the file.

The read function returns "ssize_t" which is the number of bytes read .

In our implementation of read, we need to put the data in our device, i.e. the array, which is the kernel space to the user space

. So we will make use of the function "copy_to_user" which takes the following arguments

A pointer to the location where data has to be copied , i.e. in our case the buffer that was passed to the read function
A Pointer the location from where the data has to be copied, i.e. in our case the array
A count of the number of bytes to be copied.


The function returns the number of bytes it could not read from the "count" number of bytes requested for. In case of successful read, it returns 0.

Therefore in our driver the call to "copy_to_user" would be

ret = copy_to_user(buff, char_arr.array, count);

Where "ret" is an unsigned long variable.

We will return the "ret" value as a return value of the read function. Thats is all that is required of our simple read function.

Write:

The write function is the opposite of read, we will have to write data into the device, i.e. in our case fill data into the array.

The write function also takes similar arguments as the read

A file pointer, to the file we are writing into.
A char buffer from which the data will be copied to the file or device.
A size_t variable to hold the number of bytes to be written
A pointer of type loff_t which will point to the current location of the file pointer in the file.


Therefore in our case the write function declaration would be

ssize_t write(struct file *filp, const char *buff, size_t count, loff_t *offp)

In the case of "write" we have to copy data from the user space to the kernel space. To achieve this we will use "copy_from_user" which will transfer the requested number of bytes of data from the user space to the kernel space.

copy_from_user take the similar arguments as the copy_to_user

A pointer to the location where data has to be copied , i.e. in our case this would be the array, char_arr.array.
A Pointer the location from where the data has to be copied, i.e. in our case this would be the pointer to the buffer area.
A count of the number of bytes to be copied


The return value of copy_from_user is the amount of data that was written, in case all the data was written successfully 0 is returned.

So the copy from user function call would be

ret = copy_from_user(char_arr.array, buff, count);

We will have to return the "ret" to indicate the amount of data that was not written successfully.

The only file operation left to be implemented is release.

Release

In our device there is nothing that we have to do in release as the device is only a simple array. We had held a semaphore when we had done the open call, now we will release the semaphore.

A semaphore is released using the function call up(semaphore *)

Therefore we will have to call

up(&char_arr.sem);

Now that we have seen all the four operations that our device supports add them to our driver code. We will see the full code of our example module in the next chapter and also read and write from the device using a user application.

=========================================================================

http://tuxthink.blogspot.in/2010/11/writing-example-driver-from-scratch_13.html

 Writing an Example Driver From Scratch: Chapter -4 Inserting into the kernel
Here is the full code of the driver that we have pieced together in the previous three chapters

Note: The code has been tested and found working on version 3.5.4 



#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // required for various structures related to files liked fops. 
#include <asm/uaccess.h> // required for copy_from and copy_to user functions 
#include <linux/semaphore.h>
#include <linux/cdev.h> 
static int Major;
dev_t dev_no,dev;
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
 ret = copy_to_user(buff, char_arr.array, count);
 return ret;
}

ssize_t write(struct file *filp, const char *buff, size_t count, loff_t *offp) { 
 unsigned long ret;
 printk(KERN_INFO "Inside write \n");
 ret = copy_from_user(char_arr.array, buff, count);
 return count;
}

struct file_operations fops = {
 read:  read,
 write:  write,
 open:   open,
 release: release
};


struct cdev *kernel_cdev;


int char_arr_init (void) {
 int ret;

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

 return 0;
}

void char_arr_cleanup(void) {
 printk(KERN_INFO " Inside cleanup_module\n");
 cdev_del(kernel_cdev);
 unregister_chrdev_region(Major, 1);
}
MODULE_LICENSE("GPL"); 
module_init(char_arr_init);
module_exit(char_arr_cleanup);



The above code being a kernel module, it needs a Makefile for compilation.

Makefile: 


ifneq ($(KERNELRELEASE),)
   obj-m := char_arr_dev.o
else

KERNELDIR ?= /lib/modules/$(shell uname -r)/build

PWD := $(shell pwd)

default:
 $(MAKE) -C $(KERNELDIR) M=$(PWD) modules 
endif




Note: The above makefile is taken from the Device Drivers book from Alessandro Rubini .

The make file checks if the KERNELRELEASE is set, because we need to know the location where the kernel Makefile is located, as it is that Makefile which we will use to compile our code.

If the KERNELRELEASE is not set then we set the KERNELDIR to the default location of the kernel tree, where we will find the Makefile.

After setting this we call make in the script, but this time we pass the "-c" option to indicate where the kernel makefile is located. The "M" option tells the make file where is the source code of the module that we want to compile into a kernel module. In our case the source code is present in the same folder so we pass value of present working directory.

Note that the name of the object code against "obj-m" in the makefile should be the name of your "c" file for the module, just replace the ".c" with ".o" .

Once you have created the file save it as Makefile (Note the capital "M"), in the same folder where your module is stored.

Open a terminal, and go to the file where you have the module and the Makefile, run the command 

make

If the command does not throw any errors, then your code has been compiled successfully. Run "ls" and see that you should have a file by same name as your "c" code only with the ".ko" as the extension.

To insert the module into the kernel we will use the command "insmod", you will need superuser privileges to run the command. 

sudo insmod char_arr_dev.ko


If there are no errors your module is a part of the kernel now, as we have added a "printk" to print the major number in our init function, run the command "dmesg" and you will find the line printed, with the major number, for eg : 

The major number for your device is 251 

Make a note of the number, we will need it again.

Once we have inserted the module, we need to have a device which will use the driver or the module. So we can create an entry like a device in /dev using the command "mknod"

Run the command

mknod /dev/"your device name"  c "major number" "minor number"

ie:

mknod /dev/char_arr c 251 0

If there are no errors we have a device ready that we can talk to using our driver.

NOTE: This code will not work with command "cat" , please use the application code in the next chapter. The updated code which will work with "cat" will be the chapter-6.

=========================================================================
http://tuxthink.blogspot.in/2010/11/writing-example-driver-from-scratch_23.html


 Writing an Example Driver From Scratch: Chapter -5 User access.
Now that we have our driver ready ,we need user application to talk to our device using the driver that we have written.

As the device only support read and write operations, we will write a simple C code that will just open the device and let the user either write into the device or read from the device.

The device node /dev/char_arr that we created by default would allow only root to do read and write. To let any user not having root privileges to read write we will have to change the permissions of the file, i.e of /dev/char_arr, which can be done by

sudo chmod 777 /dev/char_arr

Now to write our user application, we will use the following system calls.

open ( "file name" , "read or write access")

read ("File handle returned by open", "memory buffer to read the data into", "number of bytes of data to be read" )

write("File handle returned by open", "memory buffer to write data into", "number of bytes of data to be written" )

In our case we want to open the file "/dev/char_arr" and we want to do bot read as well as write operations on it, so the second argument will be O_RDWR

open returns a integer value which will act as a file handle to access the file for the rest of the program.

int fd;
fd = open("/dev/char_arr",O_RDWR);

The value of "fd" obtained above will be used to read and write into the file.

To read from the device file the system call would be

read(fd,read_buf,sizeof(read_buf))

Where read_buf is an array of characters, in which we will store the data that we read from the device.

To write into the device file the system call would be

write(fd,write_buf,sizeof(write_buf))

Where write_buf is an array of characters into which we will store the data that we want tor write into the device.

The header files that would be needed to have access to these system calls is fcntl.h

Using the above system calls provide switch case statement where the user can choose to read or write and then call the corresponding system call.

Once you write the "c" code using the above functions, compile it using gcc compiler, assuming the name of the file having the "c" code is user_app.c .

An example code for the user application is given below

user_app.c

#include <stdio.h>
#include <fcntl.h>


main ( ) {
        int i,fd;
        char ch, write_buf[100], read_buf[100];

        fd = open("/dev/char_dev", O_RDWR);

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

Compile it as follows

cc user_app.c -o user_app

This will generate an executable of the name user_app. Run the this executable.

$ ./user_app

Press r to read from device or w to write the device

(Enter w first time)

Enter the data to be written into device

(Enter any data)

Now run the application again

$ ./user_app

Press r to read from device or w to write the device

(Enter r the second time)

The data in the device is (What ever data you entered in the previous run)



From the above example we can see that the user application was able to store data into the device and retrieve from it when the corresponding calls were made.

Your first sample driver and the user application are ready you can try experimenting with them, and explore further.

Note : It would be safer if you did kernel programming in a virtual machine until you are confident about that you are code will not affect the system in any way

============================================================================
http://tuxthink.blogspot.in/2012/02/writing-example-driver-from-scratch.html

 Writing an example driver from scratch : Chapter -6
In the previous five chapters we walked through the steps of writing an simple charcater driver and for a virtual device and accessing it from the user space.

The limitation of driver written was it could not read using cat command . This was because the return value of the read function was not appropriate for the cat function.

The cat command continues to read from a file unless it is not informed that there is no further data to be read from the file, which is done by returning 0 when the end of file is reached.

To do this in our read function we have to keep count of the number of bytes that are written into the device. Hence we add a variable "written" into the write function which gets updated when data is written in to the device as follows

written = written + count ;

This value of written is assigned to another variable "read" every time device is opened. When the read function is called the variable "read" is compared with the variable "count", which indicates the number of bytes that the userspace wants to read. In case the count value is more than read, then we have to decrease the value of count to the amount of data present in the device i.e

if ( count > read)
count = read

And on every pass through the read function we keep decreasing the value of read by the count number of bytes that are read, and return the value of read.

Thus when end of file is reached the value of read becomes zero which when returned to cat, it would stop reading from the file.

Here is the drive code with the modified read and write functions. The steps to compile and insert the device are the same as in chapter-4 


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // required for various structures related to files liked fops. 
#include <asm/uaccess.h> // required for copy_from and copy_to user functions 
#include <linux/semaphore.h>
#include <linux/cdev.h> 
static int Major;
static int written,read;
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
 read = written;
 return 0;
}

int release(struct inode *inode, struct file *filp) {
 printk (KERN_INFO "Inside close \n");
 printk(KERN_INFO "Releasing semaphore");
 up(&char_arr.sem);
 return 0;
}

ssize_t read_char(struct file *filp, char *buff, size_t count, loff_t *offp) {
 unsigned long ret;
 printk("Inside read \n");
 if(count > read) 
 count = read;
 read = read -count;
 ret = copy_to_user(buff, char_arr.array, count);
 return count;
}

ssize_t write_char(struct file *filp, const char *buff, size_t count, loff_t *offp) { 
 unsigned long ret; 
 printk(KERN_INFO "Inside write \n");
 ret = copy_from_user(char_arr.array, buff, count); 
 written += count;
 return count;
}

struct file_operations fops = {
 
 owner:  THIS_MODULE,
 read:  read_char,
 write:  write_char,
 open:   open,
 release: release
};


struct cdev *kernel_cdev; 


int char_arr_init (void) {
 int ret;
 dev_t dev_no,dev;

 kernel_cdev = cdev_alloc(); 
  kernel_cdev->ops = &fops;
 kernel_cdev->owner = THIS_MODULE;
 printk (" Inside init module\n");
  ret = alloc_chrdev_region( &dev_no , 0, 1,"char_arr_dev");
    if (ret < 0) {
  printk("Major number allocation is failed\n");
  return ret; 
 }
    Major = MAJOR(dev_no);
 printk (KERN_INFO" The major number for your device is %d\n", Major); 


 init_MUTEX(&char_arr.sem);

 ret = cdev_add( kernel_cdev,dev_no,1);
 if(ret < 0 ) 
 {
 printk(KERN_INFO "Unable to allocate cdev");
 return ret;
 }

 return 0;
}

void char_arr_cleanup(void) {
 printk(KERN_INFO " Inside cleanup_module\n");
 cdev_del(kernel_cdev);
 unregister_chrdev_region(Major, 1);
}
MODULE_LICENSE("GPL"); 
module_init(char_arr_init);
module_exit(char_arr_cleanup);

Assuming we have created a device by the name /dev/temp, we can communicate with the device as follows

$ echo "hi" > /dev/temp
$ cat /dev/temp
hi

Or we can use the user application code as show in chapter-5 
