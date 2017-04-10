
/** g++ -o mythread -g -lrt mythread.cc  **/
/** g++ -o mythread -g -lrt mythread.cc  **/
/** g++ -o mythread -g -lrt mythread.cc  **/


#include <iostream>
#include <cstdio>  // for printf
#include <cstring>  // for memset
// #include <ctime>  // for clock_nanosleep
// #include <cstdlib>  // for rand
#include "mythread.pthread_join.hh"

using namespace std;



innerclass::innerclass(int *inpAddr, int sNum) : countaddr(inpAddr), serialNum(sNum)
{
    //cout << "RAVII: cnstr inner:" << __LINE__ << endl;
}

innerclass::~innerclass(void) {
    //cout << "RAVII: destr inner:" << __LINE__ << endl;
}

void *mydothread(void * inparg)
{
    printf("RAVIII %s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__ );



    struct timespec request;
    request.tv_sec = 9;
    request.tv_nsec = 0;
    // clock_nanosleep(CLOCK_REALTIME, 0, &request, NULL);
    clock_nanosleep(CLOCK_MONOTONIC  , 0, &request, NULL);
    // clock_nanosleep(CLOCK_PROCESS_CPUTIME_ID, 0, &request, NULL);

    return((void*)0);
}

void
outerclass::mydo()
{
    //cout << "RAVII: mydo outer:" << __LINE__ << endl;


/*******
outer
  int countarray[ARRAYSIZE];
    innerclass *classarray[ARRAYSIZE];


inner
   int *countaddr;
    int serialNum;
    pthread_t myThreadHandle;
    pthread_t myTid;

*******/

    for (int ii=0; ii<ARRAYSIZE; ii++) {
        classarray[ii] = (innerclass*)new innerclass((int*)&countarray[ii], ii);


        if ( pthread_create( &classarray[ii]->myThreadHandle, NULL, mydothread, (void*)&classarray[ii])  ) {
            printf("pthread_create error\n");
	}

    }

    for (int ii=0; ii<ARRAYSIZE; ii++) {

	// printf("ii: %d, glbaddr=0x%x ptr=0x%x serial=%d, thrhandl=0x%x Tid=0x%x\n", ii, &countarray[ii], classarray[ii]->countaddr, classarray[ii]->serialNum, classarray[ii]->myThreadHandle, classarray[ii]->myTid);


	printf("ii: %d, ptr=0x%x serial=%d, thrhandl=0x%x Tid=0x%x \n", ii, classarray[ii]->countaddr, classarray[ii]->serialNum, classarray[ii]->myThreadHandle, classarray[ii]->myTid);

    }


}

void
outerclass::mydone()
{
    //cout << "RAVII: mydo outer:" << __LINE__ << endl;


    for (int ii=0; ii<ARRAYSIZE; ii++) {
	pthread_join(classarray[ii]->myThreadHandle, NULL);
    }

    for (int ii=0; ii<ARRAYSIZE; ii++) {
	delete classarray[ii];
    }

}

main()
{
    innerclass innerobj((int*)10, 11);
    outerclass outerobj;

    cout << "begin"<<endl;
    outerobj.mydo();
    cout << "clearing"<<endl;
    outerobj.mydone();
    cout << "end"<<endl;
}



