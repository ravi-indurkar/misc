#include <iostream>

using namespace std;

void * thread_child( void *input_args);
int myglob=0;


main()
{

    pthread_t thr_id;

    cout << "main: begin\n";




    pthread_create( &thr_id, 0, thread_child, 0);


    for (int i=1; i<20000000; i++)   {
        myglob++;
    }

    pthread_join( thr_id, 0);

    cout << "main: myglob " << myglob<<endl;
}

void * thread_child( void *input_args)
{
    cout << "Child A\n";

    for (int i=1; i<20000000; i++)   {
        myglob++;
    }


    cout << "Child B: myglob " << myglob<<endl;
}
