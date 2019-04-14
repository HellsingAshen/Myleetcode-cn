#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#include "leetcode.h"

#define bool int
char *strrev(char *str);

/*
 * leetcode 45:
 * Level    : easy
 * 70. Climbing Stairs
 *
 */
/* dynamic planning */
int climbStairs(int n) {
    int                 i                   = 0; 
    int                 aiDp[n + 1];

    if ((1 == n) || (2 == n)) return n;

    memset(aiDp, 0, (n + 1) * sizeof(int));
    aiDp[1] = 1;
    aiDp[2] = 2;
    
    if (n <= 2) return aiDp[n];

    for (i = 3; i <= n; i++)
    {
        aiDp[i] = aiDp[i - 1] + aiDp[i - 2];
    }

    return aiDp[n];
}

int climbStairs_re(int n) {
    if (n < 1) return 0;
    if (2 >= n) return n;
    
    return (climbStairs(n - 1) + climbStairs(n - 2));
}

/*
 * leetcode 44:
 * Level    : easy
 * 66. Plus One
 *
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int                 i                   = 0;
    int                 iCarry              = 0;

    int*                piOut               = malloc(sizeof(int) * (digitsSize + 1) + 1);

    *returnSize = digitsSize;
    memset(piOut, 0, sizeof(int) * (digitsSize + 1) + 1);

    for (i = digitsSize - 1, iCarry = 1; i >= 0; i--)
    {
        if ((0 == (piOut[i] = (digits[i] + iCarry) % 10)) && (iCarry)) 
            iCarry = 1;
        else
            iCarry = 0;
    }

    if (0 == piOut[0])
    {
        //memcpy(piOut + 1, piOut, digitsSize * sizeof(int));
        //memcpy(&piOut[1], piOut, digitsSize * sizeof(int));
        strncpy((char*)&piOut[1], (char*)piOut, digitsSize * sizeof(int));
        *piOut = 1;
        *returnSize = *returnSize + 1;
    }

    return piOut;
}

/*
 * leetcode 43:
 * Level    : easy
 * 58. Length of Last Word
 *
 */
int lengthOfLastWord(char* s) {
    int                 j                   = 0;
    int                 iLen                = 0;

    if (!strlen(s)) return 0;
    iLen = strlen(s) - 1;

    while ((iLen >= 0) && (' ' == s[iLen])) iLen--;
    if (iLen < 0) return 0;
    
    for (j = iLen; (j >= 0) && (s[j] != ' '); j--);
    return (iLen-j);
}

/*
 * leetcode 42:
 * Level    : easy
 * 53. Maximum Subarray
 *
 */
/* use divide and conquer */
#define MAX_INT(a, b)  ((a > b) ? a : b)
int GetMidMax(int* nums, int iS, int iE)
{
    int                 iMid                = 0;
    int                 iMax                = 0;
    int                 iSum                = 0;
    int                 i                   = 0;
    
    iMid = (iS + iE) / 2;
    iSum = iMax = nums[iMid] + nums[iMid + 1];

    /* for pre */
    for (i = iMid - 1; i >= 0; i--)
    {
        iSum += nums[i];
        if (iSum > iMax) iMax = iSum;
    }

    /* for after */
    for (i = iMid + 2; i <= iE; i++)
    {
        iSum += nums[i];
        if (iSum > iMax) iMax = iSum;
    }
    
    return iMax;
}

int GetMaxSubRe(int* nums, int iS, int iE)
{
    int                 iMaxLeft            = 0;
    int                 iMaxRight           = 0;
    int                 iMaxMid             = 0;
    int                 iMid                = 0;

    if (iS == iE)
    {
        return nums[iS];
    }

    iMid = (iS + iE) / 2; /* mid pos */

    iMaxLeft = GetMaxSubRe (nums, iS, iMid);
    iMaxRight = GetMaxSubRe (nums, iMid + 1, iE);
    iMaxMid = GetMidMax(nums, iS, iE);
    
    return MAX_INT(MAX_INT(iMaxRight, iMaxLeft), iMaxMid);

}

int maxSubArray(int* nums, int numsSize) {
    int                 iRet                = 0;
    iRet = GetMaxSubRe(nums, 0, numsSize - 1);
    return iRet;
    
}

int maxSubArray1(int* nums, int numsSize) {
    int                 i                   = 0;    
    int                 j                   = 0;    
    int                 iSum                = 0;    
    int                 iMax                = nums[0];    
    
    for (; i < numsSize; iSum = 0, i++)
    {
        for (j = i; j< numsSize; j++)
        {
            iSum += nums[j];
            if (iMax < iSum) iMax = iSum;
        }
    }
    return iMax;
}


/*
 * leetcode 41:
 * Level    : easy
 * 38. Count and Say
 *
 */
char* ParseStr(char* pcIn){
    int                 iLen                = 0;
    int                 i                   = 0;
    int                 iCount              = 1;
    char*               pcOut               = NULL;

    iLen                = strlen(pcIn) * 2 + 1;
    pcOut = malloc(iLen * sizeof(char));
    memset(pcOut, 0, iLen);

    for (; i < strlen(pcIn) - 1; i++)
    {
        if (pcIn[i] == pcIn[i + 1])     
        {
            iCount++;
        }
        else
        {
            sprintf(pcOut + strlen(pcOut), "%d%c", iCount, pcIn[i]);
            iCount = 1;
        }
    }
    /* last ele */
    sprintf(pcOut + strlen(pcOut), "%d%c", iCount, pcIn[i]);

    return pcOut;
}

char* countAndSay(int n) {
    char*               pcOut               = NULL;

    if ((n > 30) || (n < 0)) return NULL;

    if (1 == n) 
    {
        return "1";
    }

    pcOut = countAndSay(n - 1);
    /* TODO: free pcOut */
    return ParseStr(pcOut);
}

/*
 * leetcode 40:
 * Level    : easy
 * 35. Search Insert Position
 *
 */
int searchInsert(int* nums, int numsSize, int target) {
    int             i                   = 0;

    for (; (i < numsSize) && (target > nums[i]); i++);

    return i;
}

/*
 * leetcode 39:
 * Level    : easy
 * 28. Implement strStr()
 *
 */
int strStr(char* haystack, char* needle) {
    int             i                   = 0;

    if (strlen(needle) > strlen(haystack)) return -1;
    if (!strlen(needle)) return 0;

    for (; i < strlen(haystack);)
    {
        while ((haystack[i] != needle[0]) && (i < strlen(haystack)))
        {
            i++;
        }
        if (!strncmp(&haystack[i], needle, strlen(needle))) return i;
        i++;
    }
    return -1;
}



/*
 * leetcode 38:
 * Level    : easy
 * 27. Remove Element
 *
 */
int removeElement(int* nums, int numsSize, int val) {
    int             i                   = 0;
    int             j                   = 0;

    for (; (i < numsSize) && (val != nums[i]); i++);
    if (i == numsSize) 
    {
        return numsSize;
    }

    for (j = i + 1; j < numsSize; j++)
    {
        if (val != nums[j]) 
        {
            nums[i++] = nums[j];
        }
    }

    return i;
}

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
    iRet = climbStairs(44);
    printf("[%d].\n", iRet);
#if 0
    //int             aiArr[]             = {9, 9};
    int             aiArr[]             = {1, 0, 0, 0, 0};
    int*            piOut               = NULL;
    piOut = plusOne(aiArr, sizeof(aiArr) / sizeof(int), &iRet);
    printf("[%d].\n", iRet);
    int i;
    for (i = 0; i < sizeof(aiArr)/ sizeof(int); i++) printf("%d ", piOut[i]);


    //char*           pcStr               = "hello world";
    char*           pcStr               = " ";

    iRet = lengthOfLastWord(pcStr);
    printf("[%d].\n", iRet);
    int             aiArr[]             = {-2,1,-3,4,-1,2,1,-5,4};
    //int             aiArr[]             = {-1};

    iRet = maxSubArray(aiArr, sizeof(aiArr) / sizeof(int));
    printf("[%d].\n", iRet);
    char*           pcOut               = NULL;
    pcOut = countAndSay(5);
    printf("[%s].\n", pcOut);
    
    //iRet = strStr("hello", "ll");
    iRet = strStr("", "");
    printf("%d.\n", iRet);
    

    //int             aiArr[]             = {3, 9, 20, 0, 0, 15, 7};
    int             aiArr[]             = {1, 2, 3, 4, 5};
    struct TreeNode* pstRoot            = NULL;

    pstRoot = initBinaryTree(aiArr, sizeof(aiArr) / sizeof(int));

    iRet = sumOfLeftLeaves(pstRoot);
    printf("%d.\n", iRet);
    

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
