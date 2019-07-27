#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

#include "leetcode.h"

/*
 *  leetcode 117:
 *  Level    : diff
 *  1117. Building H2O
 *  
 */

#define CHECK_VARIABLE(l,r) do{if(0 != r){fprintf(stderr,"[%s], err:[%d]\n",l,r);break;}}while(0);
#define SET_BIT(x, y)  (x |= (1<<y))
#define NEG_BIT(x, y)  (x ^= (1<<y))
#define GET_BIT(x, y)  ((x)>>y & 0x1)
#define RETURN_IF_ERR(ret) \
    if (0 != ret) {printf("Get errorcode = [%d] line = [%d].\n", ret, __LINE__); return ret;}


void releaseHydrogen()
{
    printf("H");
}

void releaseOxygen()
{
    printf("O");
}

typedef struct {
    /* User defined data may be declared here. */
    pthread_mutex_t tMutex;
    pthread_cond_t tCond;
    int iGuide;
} H2O;

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    
    /* Initialize user defined data here. */
    obj->iGuide = 0;
    pthread_mutex_init(&obj->tMutex, NULL);
    pthread_cond_init(&obj->tCond, NULL);

    return obj;
}

void hydrogen(H2O* obj) {
    
    /* releaseHydrogen() outputs "H". Do not change or remove this line. */
    while (1)
    {
        pthread_mutex_lock(&(obj->tMutex));
        while (GET_BIT(obj->iGuide, 1)) /* 010, 011 */
        {
            pthread_cond_wait(&(obj->tCond), &(obj->tMutex));
        }
    
        if (0 == GET_BIT(obj->iGuide, 1))
        {
            SET_BIT(obj->iGuide, 1);
        }
        
        SET_BIT(obj->iGuide, 0);
        releaseHydrogen();
        if (obj->iGuide == 7)
        {
            obj->iGuide = 0;
            pthread_cond_broadcast(&(obj->tCond));
        }
        pthread_mutex_unlock(&(obj->tMutex));
    }
    return;
    

}

void oxygen(H2O* obj) {
    
    /* releaseOxygen() outputs "O". Do not change or remove this line. */
    while (1)
    {
        pthread_mutex_lock(&(obj->tMutex));
        while (GET_BIT(obj->iGuide, 2)) /* 1xx  */
        {
            pthread_cond_wait(&(obj->tCond), &(obj->tMutex));
        }
    
        SET_BIT(obj->iGuide, 2);
        releaseOxygen();
        if (obj->iGuide == 7)
        {
            obj->iGuide = 0;
            pthread_cond_broadcast(&(obj->tCond));
        }
        pthread_mutex_unlock(&(obj->tMutex));
    }
    return;
}

void h2oFree(H2O* obj) {
    /* User defined data may be cleaned up here. */
    pthread_mutex_destroy(&obj->tMutex);
    pthread_cond_destroy(&obj->tCond);
    if (obj)
    {
        free(obj);
        obj = NULL;
    }
    return;
}

int main()
{
    int             iRet            = 0;
    int*            pvRet           = NULL;
    pthread_t       tTid1           = 0;
    pthread_t       tTid2           = 0;
    pthread_t       tTid3           = 0;

    H2O*            obj             = NULL;

#if 1
    obj = h2oCreate();
    RETURN_IF_ERR(obj == NULL);

    iRet = pthread_create(&tTid2, NULL, hydrogen, obj);
    iRet = pthread_create(&tTid1, NULL, oxygen, obj);

    iRet = pthread_join(tTid1, NULL);
    RETURN_IF_ERR(iRet);
    iRet = pthread_join(tTid2, NULL);
    RETURN_IF_ERR(iRet);


    h2oFree(obj);
#endif
    return iRet;
}
