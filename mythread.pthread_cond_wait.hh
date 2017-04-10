// static const int ARRAYSIZE=1024;
static const int ARRAYSIZE=20;


class innerclass {

public:
    int *countaddr;
    int serialNum;
    pthread_t myThreadHandle;
    pthread_t myTid;
    pthread_mutex_t mymutex;
    pthread_cond_t mycond;

    innerclass(int *inpAddr, int sNum) ;
    virtual ~innerclass(void) ;

};


class outerclass {

public:

    int countarray[ARRAYSIZE];
    innerclass *classarray[ARRAYSIZE];


    outerclass(void) 
    {
        // cout << "RAVII: cnstr inner:" << __LINE__ << endl;
        //printf("RAVIII: cnst outer\n");
        memset(countarray, 0, sizeof(countarray));
        memset(classarray, 0, sizeof(classarray));
    };
    virtual ~outerclass(){ printf("RAVIII: destr outer\n"); };

    void mydo( void );
    void mydone( void );
    // void *mydothread(void * inparg);

};


