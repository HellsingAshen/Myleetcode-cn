#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#include "leetcode.h"

#define bool int
char *strrev(char *str);

/*
 * leetcode 37:
 * Level    : easy
 * 404. Sum of Left Leaves
 *
 */

void GetValueByPT(struct TreeNode* root, int* piVal)
{
    if (root->left) 
    {
        if (isLeafNode(root->left))
        {
            *piVal += root->left->val;
        }
        else
        { 
            GetValueByPT(root->left, piVal);
        }
    }
    if (root->right) GetValueByPT(root->right, piVal);
    return;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int             iSum            = 0;

    if (!root) return iSum;

    GetValueByPT(root, &iSum);

    return iSum;
}


/*
 * leetcode 36:
 * Level    : easy
 * 14. Longest Common Prefix
 *
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    int             i               = 0;
    int             iLen            = 0;
    int             j               = 0;
    char*           pcCommon        = NULL;          

    if ( 1 > strsSize) return "";
    if ( 1 == strsSize) return *strs;

    pcCommon = (char*)malloc(strlen(*strs) + 1);
    memset(pcCommon, 0, strlen(*strs) + 1);

    /* 1. get common in 2 ele */
    for (; 
        (strs[0][i] == strs[1][i]) && (i < strlen(strs[0])) && (i < strlen(strs[1]));
         i++);
    iLen = i;
    
    /* 2. get common in othre */
    for (i = 2; (i < strsSize) && (iLen > 0); i++)
    {
        while (strncmp(strs[0], strs[i], iLen))    
        {
            iLen--;
        }
    }
    
    if (iLen > 0)
    {
        memcpy(pcCommon, strs[0], iLen);
        return pcCommon;
    }
    
    return "";
}

/*
 * leetcode 35:
 * Level    : easy
 * 13. Roman to Integer
 *
 */
typedef struct tagRomaNum_S
{
    char    acRoma[3];
    int     iVal;
}RomaNum_S;
RomaNum_S stRomas[] = {
    {"I", 1}, 
    {"V", 5}, 
    {"X", 10}, 
    {"L", 50}, 
    {"C", 100}, 
    {"D", 500}, 
    {"M", 1000}, 
    {"IV", 4}, 
    {"IX", 9}, 
    {"XL", 40}, 
    {"XC", 90}, 
    {"CD", 400}, 
    {"CM", 900}, 
};
int GetMapVal(char* pc, int iLen)
{
    int             i                   = 0;
    for (; i< sizeof(stRomas)/sizeof(RomaNum_S); i++)
    {
        if (!strncmp(stRomas[i].acRoma, pc, iLen))
        {
            return stRomas[i].iVal;
        }
    }
    return 0;
}
int romanToInt(char* s) {
    int             iRet                = 0;
    int             i                   = 0;

    for (; i < strlen(s);)
    {
       if ((s[i] == 'V') 
          || ((s[i] == 'I') && ((s[i + 1] != 'V') && (s[i + 1] != 'X')))
          || ((s[i] == 'X') && ((s[i + 1] != 'L') && (s[i + 1] != 'C')))
          || ((s[i] == 'C') && ((s[i + 1] != 'D') && (s[i + 1] != 'M')))
          || (s[i] == 'L') 
          || (s[i] == 'D') 
          || (s[i] == 'M'))
        {
            iRet += GetMapVal(&s[i], 1);
            i++;
        }
        else
        {
            iRet += GetMapVal(&s[i], 2);
            i = i + 2;
        }
    }

    return iRet;
}

/*
 * leetcode 34:
 * Level    : easy
 * 7. Reverse Integer
 */
int reverse(int x) {
    long long       iRet                = 0;
    int             iSign               = 0;
    int             iDiv                = 0;
    int             iLeft               = 0;
    
    if ((x > 2147483647) || (x <= (-2147483648))) return 0;
    if (x < 0)
    {
        iSign = 1;
        x = x * (-1);
    }
    iDiv = x;
    while (iDiv)
    {
        iLeft = iDiv % 10; 
        iDiv = iDiv / 10; 
        iRet = iRet * 10 + iLeft;
    }
    return (int)(iSign ? (iRet * (-1)) : iRet);    
}

int main(int argc, char** args)
{
    int             iRet                = 0;

    //int             aiArr[]             = {3, 9, 20, 0, 0, 15, 7};
    int             aiArr[]             = {1, 2, 3, 4, 5};
    struct TreeNode* pstRoot            = NULL;

    pstRoot = initBinaryTree(aiArr, sizeof(aiArr) / sizeof(int));

    iRet = sumOfLeftLeaves(pstRoot);
    printf("%d.\n", iRet);
    

#if 0
    char*           pcStr               = NULL;

    //char*          ppc[3] = {"flower","flow","flight"};
    char*          ppc[3] = {"dog","racecar","car"};
    pcStr = longestCommonPrefix(ppc, 3);
    printf("%s.\n", pcStr);

    //iRet    = romanToInt("III"); 
    //iRet    = romanToInt("IV"); 
    //iRet    = romanToInt("IX"); 
    //iRet    = romanToInt("LVIII"); 
    //iRet    = romanToInt("MCMXCIV"); 
    iRet    = romanToInt("DCXXI"); 
    printf("hello leetcode . iRet = [%d]\n", iRet);
    iRet    = reverse(1463847412);
    printf("hello leetcode . iRet = [%d]\n", iRet);
#endif
    return 0;
}
