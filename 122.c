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
 *  leetcode 1046:
 *  Level    : easy
 * 
 * 
 */  
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

int* Get2Big(int* piArr, int iSize, int iTag)
{
    int                 i                   = 0;
    int                 j                   = 0;
    int*                m                   = 0;
    int*                n                   = 0;
    for (m = &MAX(piArr[0], piArr[1]), n = &MIN(piArr[0], piArr[1]) i = 2 ; i < size; i++)
    {
        if (piArr[i] > *m) 
        {
            n = m;
            m = &piArr[i];
            
        }
        else if (piArr[i] > *n) 
            n = &piArr[i];
        else
        {}
    }
    if (iTag == 2) return n;
    return m;
}
int lastStoneWeight(int* stones, int stonesSize){
    int                 i                   = 0;
    int                 j                   = 0;
    int                *pm                  = NULL;
    int                *pn                  = NULL;


    for (pm=Get2Big(stones, stonesSize, 1), pn=Get2Big(stones, stonesSize, 2); 
        (*pm != 0 && *pn != 0); 
        pm=Get2Big(stones, stonesSize, 1), pn=Get2Big(stones, stonesSize, 2))
    {
            if (*pm == *pn)
                *pm = *pn = 0;
            else
            {
                *pm = *pm - *pn;
                *pn = 0;
            }
    }
    return *pm;
}


/*
 *  leetcode 1047:
 *  Level    : easy
 *  Remove All Adjacent Dulpicates In String
 *  stack 
 */  
char * removeDuplicates(char * S){
    char*               pcStk               = malloc(strlen(S) + 1);
    memset(pcStk, 0, strlen(S) + 1);

    int                 iTop                = 0;
    int                 i                   = 0;

    for (; i < strlen(S); i++)
    {
        if ((!iTop) || (S[i] != pcStk[iTop - 1]))
        {
            pcStk[iTop++] = S[i];
        }
        else
        {
            pcStk[--iTop] = '\0';
        }
    }

    return pcStk;

}
char * removeDuplicates1(char * S){
    int                 i                   = 0;
    int                 j                   = 0;

    for (; i < (int)(strlen(S) - 1); i++)
    {
        if (S[i] == S[i + 1])
        {
            for (j = i; j < (int)(strlen(S) - 2); j++)
            {
                S[j] = S[j + 2];
            }
            i = -1;
            S[strlen(S) - 2] = '\0';
        }
    }
    return S;
}

/*
 *  leetcode 1185:
 *  Level    : easy
 *  Day of the week
 *  dp
 */  
int isLeapYear(int year){
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}
char * dayOfTheWeek(int day, int month, int year){
    int                 iFirstDay           = 5;
    int                 i                   = 0; 
    int                 iDays               = day; 
    int                 aiMonth[12]         = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char*               aiWeekDay[7]        = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    assert(year > 1970);

    for (i=1971; i < year; i++)
    {
        if (isLeapYear(i)) 
            iFirstDay = (iFirstDay + 2) % 7;
        else
            iFirstDay++;
    }
printf(" iFirstDay = [%d].\n", iFirstDay);
    
    for (i = 0; i < month - 1; i++)
    {
        iDays += aiMonth[i];
    }

printf(" month day = [%d].\n", iDays);

    if (isLeapYear(year) 
        && (month > 2)) 
        iDays++;
printf(" iDayst = [%d].\n", iDays + iFirstDay - 1);

    iDays = (iDays + iFirstDay - 1) % 7;

printf(" iDays = [%d].\n", iDays);

    return aiWeekDay[iDays];
}

/*
 *  leetcode 122:
 *  Level    : easy
 *  617. Merge Two Binary Trees
 *
 */  
void dumpNode(struct TreeNode* sn, struct TreeNode** n)
{
    struct TreeNode*    rn              = NULL;
    struct TreeNode*    tn              = NULL;

    if (!sn) return;
    rn = malloc(sizeof(struct TreeNode));
    rn->val = sn->val;
    rn->left = rn->right = NULL;

    if (sn->left) {
        dumpNode(sn->left, &tn);
        rn->left = tn;
        tn = NULL;
    }

    if (sn->right) {
        dumpNode(sn->right, &tn);
        rn->right = tn;
        tn = NULL;
    }
    *n = rn;
    return;
}
void dumpTree(struct TreeNode* t1, struct TreeNode** rt)
{
    struct TreeNode*    t               = NULL; 
    struct TreeNode*    rn              = NULL; 

    if (t1){
        dumpNode(t1, &rn);
        *rt = rn;
    }
    return;
}
void  mergeNode(struct TreeNode* t1, struct TreeNode** t2){
    struct TreeNode*    n               = 0;

    if (!t1) return;
    if (!*t2){
        dumpTree(t1, &n);
        *t2 = n;
        return;
    }
    assert(t1->val == (*t2)->val);
    mergeNode(t1->left, &((*t2)->left));
    mergeNode(t1->right, &((*t2)->right));
    return;
}
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    /* 1. dump t1 to t3 */
    /* 2. add node from t2 to t3 */

    struct TreeNode*    t3              = 0;
    dumpTree(t1, &t3);

    mergeNode(t2, &t3);
    
    return t3;
}

int main()
{
    int             iRet                = 0;
    char* pc           = malloc(9);
    memcpy(pc, "aaaaaaaa", 8);
    char* p = removeDuplicates(pc);
    printf("p is [%s]\n", p ? p : "NULL");
    
    return iRet;
}
