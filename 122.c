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
 *  leetcode 1060:
 *  Level    : easy
 * 
 * 
 */  

#define TOTAL_CHAR_NUM (26)
int canBeConstruct(int* pi, int iSize, char* pcWord)
{
    int                 aiBaseChar[26]      = {0};
    int                 i                   = 0;
    
    memcpy(aiBaseChar, pi, iSize * sizeof(int));

    for (i = 0; i < strlen(pcWord); i++)
    {
        if (--aiBaseChar[pcWord[i] - 'a'] < 0) return 0;
    }
    return 1;
} 

int countCharacters(char ** words, int wordsSize, char * chars){
    int                 aiBase[26]          = {0};
    int                 i                   = 0;
    int                 iSumLength          = 0;

    for (; i < strlen(chars); i++)
    {
        aiBase[chars[i] - 'a']++;
    }
    
    for (i = 0; i < wordsSize; i++)
    {
        if (canBeConstruct(aiBase, TOTAL_CHAR_NUM, words[i]))
        {
            iSumLength += strlen(words[i]);
        }
    }

    return iSumLength;
}

/*
 *  leetcode 1071:
 *  Level    : easy
 * 
 * 
 */  

char* getMinSubStr(char* pcStr);
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
char * gcdOfStrings(char * str1, char * str2){
    char*               pcSub               = NULL;
    char*               pcShort             = NULL;
    char*               pcLong              = NULL;

    pcShort = ((strlen(str1) == MAX(strlen(str1), strlen(str2))) ? str2 : str1);
    pcLong  = ((strlen(str1) == MAX(strlen(str1), strlen(str2))) ? str1 : str2);
    pcSub   = getMinSubStr(pcShort);

    if (isDividedStr(pcLong, pcSub)) return pcSub;
    return "";
}

/* 0 -- not 
 * 1 -- ok
 */
int  isDividedStr(char * str1, char * str2){
    int                 i                   = 0;

    if (strlen(str1) % strlen(str2) != 0)  return 0;

    for (; i < strlen(str1); i = i + strlen(str2))
    {
        if (strncmp(str2, str1 + i, MIN(strlen(str2), strlen(str1 + i)))) return 0;
    }
    return 1;
}

char* getMinSubStr(char* pcStr){
    char*               pcOut               = NULL;
    int                 i                   = 1;

    pcOut   = malloc(strlen(pcStr) + 1);

    for (; i <= strlen(pcStr); i++)
    {
        memset(pcOut, 0, strlen(pcStr) + 1);
        memcpy(pcOut, pcStr, i);
        if (isDividedStr(pcStr, pcOut))
            return pcOut;
    } 
    return NULL;
}


/*
 *  leetcode 1046:
 *  Level    : easy
 * 
 * 
 */  
#define MAXP(a, b) ((*(int*)a >= *(int*)b) ? a : b)
#define MINP(a, b) ((*(int*)a < *(int*)b) ? a : b)

int* get2Big(int* piArr, int iSize, int iTag)
{
    int                 i                   = 0;
    int*                m                   = NULL;
    int*                n                   = NULL;

    for (m = MAXP(&piArr[0], &piArr[1]), n = MINP(&piArr[0], &piArr[1]), i = 2;
        i < iSize; 
        i++)
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
    int                *pm                  = NULL;
    int                *pn                  = NULL;

    if (1 == stonesSize) return stones[0];

    for (pm=get2Big(stones, stonesSize, 1), pn=get2Big(stones, stonesSize, 2); \
        (*pm != 0) && (*pn != 0); \
        pm=get2Big(stones, stonesSize, 1), pn=get2Big(stones, stonesSize, 2))
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
    //struct TreeNode*    t               = NULL; 
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
    int             aiArr[]             = {2, 2};
    iRet = lastStoneWeight(aiArr, sizeof(aiArr) / sizeof(int));
    printf("iRet is [%d]\n", iRet);
    
    return iRet;
}
