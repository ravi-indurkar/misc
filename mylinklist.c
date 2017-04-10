#include <stdio.h>
#include <stdlib.h>

struct mylist {
    int data;
    struct mylist *next;
};

typedef struct mylist mylist_t;


void
myinsert( int data, mylist_t ** address_of_ptr_to_list )
{
    mylist_t *new_element;
    mylist_t *ptr_to_list;

    ptr_to_list = *address_of_ptr_to_list;

    new_element = (mylist_t*) malloc( sizeof(mylist_t));

    if ( new_element == NULL) {
        printf("Malloc for new-element failed\n");
        return;
    }

    new_element->data = data;
    new_element->next = NULL;

    if ( *address_of_ptr_to_list == NULL) {
        *address_of_ptr_to_list = new_element;
    } else {
        while ( ptr_to_list->next != NULL) {
            ptr_to_list = ptr_to_list->next;
        }
        ptr_to_list->next = new_element;
    }
}

void
myprint( mylist_t * ptr_to_list)
{
    while ( ptr_to_list ) {
        printf("this:0x%x data:0x%x next:0x%x\n", ptr_to_list,
                                ptr_to_list->data, ptr_to_list->next);
        ptr_to_list = ptr_to_list->next;
    }
}

main()
{
    mylist_t *ravis_list;
    int i;
    ravis_list = 0;

    for (i=0; i<9; i++ ) {
        myinsert( i, &ravis_list);
    }

    myprint( ravis_list);
}

