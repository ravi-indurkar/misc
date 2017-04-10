#include <iostream>

using namespace std;

void * thread_child( void *input_args);
pthread_mutex_t mymutex;
pthread_cond_t mycond;

main()
{

    pthread_t thr_id;

    cout << "main: begin\n";

    pthread_mutex_init( &mymutex, 0);
    pthread_cond_init( &mycond, 0);

    pthread_create( &thr_id, 0, thread_child, 0);


    /* if needed, you can do some work here if you want...*/



    pthread_cond_wait( &mycond, &mymutex);

    cout << "main: end\n";
}

void * thread_child( void *input_args)
{
    cout << "Child A\n";

    /* simulate doing some work */
    for (int i=1; i<2000000000; i++)   {
        if (i==1999000000) pthread_cond_signal( &mycond);
    }

    pthread_cond_signal( &mycond);
    cout << "Child B\n";
}
