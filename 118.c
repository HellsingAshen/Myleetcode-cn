#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

#define true 1
#define false 0
#include "leetcode.h"
/*
 *  leetcode 120:
 *  Level    : easy
 *  941. Valid Mountain Array
 *
 */  
bool validMountainArray(int* A, int ASize){
    int i,j;
    /* up */
    for (i = 0; (i < ASize - 1) && (A[i] < A[i + 1]); i++);
    if ((i == 0) || (i == ASize - 1)) return false;

    for (j = i + 1; (j < ASize) && (A[j] < A[j - 1]); j++);
    if (j == ASize) return true;
    
    return false;
    
}

/*
 *  leetcode 119:
 *  Level    : easy
 *  1078. Occurrences After Bigram
 */  
char ** findOcurrences(char * text, char * first, char * second, int* returnSize){
    int             i               = 0;
    int             j               = 0;
    int             l               = 0;
    int             aiLen[500]      = {0};
    char*           aiAddr[500]     = {0};


    char*           pFirst          = NULL;
    char*           pPos            = NULL;
    char*           pcLeft          = NULL;
    char**          ppcOut          = NULL;

    assert(NULL != first && NULL != second);

    for (pFirst = strstr(text, first); pFirst != NULL; pFirst = strstr(pcLeft, first))
    {
        if (pFirst[strlen(first)] != ' ')
        {
            while (*pFirst != ' ') pFirst++;
            pcLeft = pFirst;
            continue;
        }
        else
        {
            pFirst = pFirst + strlen(first);
            while (*pFirst == ' ') pFirst++;
            if (!strncmp(pFirst, second, strlen(second)) && pFirst[strlen(second)] == ' ')
            {
                pFirst = pFirst + strlen(second) + 1;
                pcLeft = pFirst;
                /* get third */
                while (pFirst[j] && pFirst[j] != ' ')
                {
                    j++;
                }
                aiLen[l] = j;
                aiAddr[l] = pFirst;
                l++;
                j = 0;
            }
            else
            {
                /* reset pcLeft */
                //while (pFirst && *pFirst != ' ') pFirst++;
                pcLeft = pFirst;
            }
        }
printf("pcLeft = [%s]\n", pcLeft);

    }
printf("l = [%d]\n", l);
    
    *returnSize = l;
    ppcOut = malloc(l * sizeof(char*));
    memset(ppcOut, 0, l * sizeof(char*));

    for (i = 0; i < l; i++)
    {
        ppcOut[i] = malloc(aiLen[i] + 1);
        memset(ppcOut[i], 0, aiLen[i] + 1);
        strncpy((char*)ppcOut[i], (char*)aiAddr[i], aiLen[i]);
    }
    return ppcOut;
}

/*
 *  leetcode 118:
 *  Level    : easy
 *  1154. Day of the Year
 *  
 */

#define CHECK_VARIABLE(l,r) do{if(0 != r){fprintf(stderr,"[%s], err:[%d]\n",l,r);break;}}while(0);
#define RETURN_IF_ERR(ret) \
    if (0 != ret) {printf("Get errorcode = [%d] line = [%d].\n", ret, __LINE__); return ret;}

int dayOfYear(char * date){
    int aiMonth[12]  = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int iIsLeapYear = 0;
    int iYear   = 0;
    int iMonth  = 0;
    int iDay    = 0;

    char* apcSub[3] = {NULL, NULL, NULL};
    int i = 0;


    for (; i < 3; i++, date = NULL)
    {
        apcSub[i] = strtok(date, "-");
    }

    iYear = atoi(apcSub[0]);
    iMonth = atoi(apcSub[1]);
    iDay = atoi(apcSub[2]);


    iIsLeapYear = ((iYear % 4 != 0) ? 0 : ((iYear % 100 != 0) ? 1 : ((iYear % 400 == 0) ? 1 : 0)));
    
    for (i = 1; i < iMonth; i++)
    {
        iDay += aiMonth[i - 1];
    }
    

    return ((iMonth <= 2) ? iDay : iIsLeapYear + iDay);
}


int main()
{
    int   aiArr[] = {0,1,2,3,4,5,6,7,8,9};
    int   iRet = 0;

    iRet = validMountainArray(aiArr, sizeof(aiArr) / sizeof(int));

    printf("iRet = %s", (iRet == 0) ? "false" : "true");


#if 0
    char* text = "we will we will rock you";
    char* first = "we";
    char* second = "will";

    char** ppRet    = NULL;
    char* text = "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa";
    char* first = "kcyxdfnoa";
    char* second = "jkypmsxd";
    
    int             iRet            = 0;

    ppRet = findOcurrences(text, first, second, &iRet);

    int i = 0;
    for (; i < iRet; i++)
        printf("%s ", ppRet[i]);

#endif
    return iRet;
}
