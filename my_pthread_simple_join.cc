#include <iostream>

using namespace std;

void * thread_child( void *input_args);



main()
{

    pthread_t thr_id;

    cout << "main: begin\n";




    pthread_create( &thr_id, 0, thread_child, 0);


    /* if needed, you can do some work here if you want...*/



    pthread_join( thr_id, 0);

    cout << "main: end\n";
}

void * thread_child( void *input_args)
{
    cout << "Child A\n";

    /* simulate doing some work */
    for (int i=1; i<2000000000; i++)   {

    }


    cout << "Child B\n";
}
