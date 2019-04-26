#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <math.h>

#include "leetcode.h"
/*
 * leetcode 72:
 * Level    : easy
 * 198. House Robber
 * f(n)=max(f(n-1),f(n-2)+nums[n])
 * 2 1 1 2
 *  int                 aiArr[]                 = {2,7,9,3,1};
 */
int rob(int* nums, int numsSize) {
    int                 i                   = 0;
    int                 iSum                = 0;
    int                 iTmp1               = 0;
    int                 iTmp2               = 0;

    if (numsSize == 0)  return 0;
    if (numsSize == 1)  return nums[0];
    if (numsSize == 2)  return MAX_INT(nums[0], nums[1]);

    iTmp1 = nums[0]; /* f1 */
    iTmp2 = MAX_INT(nums[1], nums[0]); /* f2 */
    for (i = 3; i <= numsSize; i++)
    {
        iSum = MAX_INT(iTmp2, iTmp1 + nums[i - 1]);
        iTmp1 = iTmp2;
        iTmp2 = iSum;
        printf("iTmp1 = [%d] iTmp2 = [%d].\n", iTmp1, iTmp2);
    }
    return iSum;
}

/*
 * leetcode 71:
 * Level    : easy
 * 190. Reverse Bits
 *
 */
uint32_t reverseBits(uint32_t n) {
    uint32_t            uiInt               = 0;
    int                 i                   = 0;
    while (n > 0)    
    {
        uiInt = uiInt * 2 + (n % 2);
        n = n / 2;
        i++;
    }
    return (uiInt<<(32 - i));
}

/*
 * leetcode 70:
 * Level    : easy
 * 172. Factorial Trailing Zeroes
 *
 */
int jc(int n)
{
    if ((n == 0) || (n == 1)) return 1;
    return n * jc(n - 1);
}
int trailingZeroes(int n) {
    int                 iCount              = 0;
    if (n <= 4) return 0;
    while (n)
    {
        n = n / 5; /* first pro 0 5 at first pos */
        iCount += n; /* 127 / 5 = 25  125 */
    }
    return iCount;
    
}
/*
 * leetcode 69:
 * Level    : easy
 * 171. Excel Sheet Column Number
 *
 */
int titleToNumber(char* s) {
    int                 i                   = 0;
    int                 j                   = 0;
    int                 iOut                = 0;
    for (i = strlen(s) - 1; i >= 0; i--, j++)
    {
        iOut += (s[i] - 'A' + 1) * pow(26, j);
    }
    return iOut;
}

/*
 * leetcode 68:
 * Level    : easy
 * 169. Majority Element
 *
 */
int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpn);
    return nums[numsSize / 2];
}

/*
 * leetcode 67:
 * Level    : easy
 * 168. Excel Sheet Column Title
 *
 */
char* convertToTitle(int n) {
    int                 iDividend           = 0;
    int                 iLen                = 0;    /* real len */
    char*               pcOut               = NULL;

    if (n <= 0) return NULL;

    iDividend = n;
    while (iDividend)
    {
        iDividend = (iDividend - 1) / 26;
        iLen++;
    }
    pcOut = malloc(iLen * sizeof(char) + 1);
    memset(pcOut, 0, sizeof(char) * iLen + 1);
    
    iLen--;
    iDividend = n;
    while (iDividend)
    {
        pcOut[iLen--] = (iDividend - 1) % 26 + 'A';
        iDividend = (iDividend - 1) / 26;
    }
    
    return pcOut;
}
/*
 * leetcode 66:
 * Level    : easy
 * 167. Two Sum II - Input array is sorted
 *
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int                 i                   = 0;
    int                 j                   = 0;
    int*                piOut               = NULL;

    for (j = numbersSize - 1; i < j;)
    {
        if (numbers[i] + numbers[j] > target)
        {
            j--;
        }
        else if (numbers[i] + numbers[j] < target)
        {
            i++;
        }
        else
        {
            piOut = malloc(sizeof(int) * 2);
            memset(piOut, 0, sizeof(int) * 2);
            piOut[0] = i + 1;
            piOut[1] = j + 1;
            *returnSize = 2;
            return piOut;
        }
    }
    return NULL;
}
/*
 * leetcode 65:
 * Level    : easy
 * 160. Intersection of Two Linked Lists
 *
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    /* 1. get ele A in B pos */
    struct ListNode*    pstStart            = NULL;
    struct ListNode*    pstStartB           = NULL;
    struct ListNode*    pstListA            = NULL;
    struct ListNode*    pstListB            = NULL;

    for (pstStart = headA; pstStart; pstStart = pstStart->next)
    {
        for(pstStartB = headB; pstStartB; pstStartB = pstStartB->next)
        {
            if (pstStart->val == pstStartB->val)
            {
                pstListA = pstStart;
                pstListB = pstStartB;
                while (pstListB && pstListA && (pstListA->val == pstListB->val))
                {
                    pstListA = pstListA->next;
                    pstListB = pstListB->next;
                }

                if (!pstListB) return pstStart;
                if (!pstListA) return pstStartB;
            }
        }
    }
    return NULL;
}
/*
 * leetcode 64:
 * Level    : easy
 * 155. Min Stack
 *
 */
typedef struct {
    int     iSize;
    int*    piEle;
    int     iTop; /* next aviable */
    int*    piMin;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack*           pstStk              = NULL;
    pstStk = malloc(sizeof(MinStack));
    memset(pstStk, 0, sizeof(MinStack));
    pstStk->iSize = maxSize;
    pstStk->piEle = malloc(sizeof(int) * maxSize);
    memset(pstStk->piEle, 0, sizeof(int) * maxSize);
    pstStk->iTop = 0;
    pstStk->piMin = NULL;
    return pstStk;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->iTop == obj->iSize) return;
    obj->piEle[obj->iTop++] = x;
    if ((!obj->piMin) || (x < *(obj->piMin)))
         obj->piMin = &(obj->piEle[obj->iTop - 1]);
    return;
}

void minStackPop(MinStack* obj) {
    int                 i                   = 0;
    if (!obj->iTop) return;
    obj->iTop--;
    if (0 == obj->iTop)
    {
        obj->piMin = NULL;
        return;
    }

    if (*(obj->piMin) == obj->piEle[obj->iTop])
    {
        obj->piMin = &obj->piEle[0];
        for (; i < obj->iTop; i++)
        {
            if (*(obj->piMin) > obj->piEle[i]) 
                obj->piMin = &(obj->piEle[i]);
        }
    }
    return;
}


int minStackTop(MinStack* obj) {
    return obj->piEle[obj->iTop - 1];
}

int minStackGetMin(MinStack* obj) {
    return *(obj->piMin);
}

void minStackFree(MinStack* obj) {
    free(obj->piEle);
    obj->piEle = NULL;
    obj->piMin = NULL;
    free(obj);
    obj = NULL;
    return;
}

/*
 * leetcode 63:
 * Level    : easy
 * 141. Linked List Cycle
 *
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode*    pstNext         = NULL;
    struct ListNode*    pstNNext        = NULL;

    if (!head || !head->next) return false;
    pstNext = head->next;
    if (!head->next->next) return false;

    pstNNext = pstNext->next;
    
    while (pstNext != pstNNext)
    {
        pstNext = pstNext->next;
        if (!pstNext) return false;
        if (!pstNNext->next || !pstNNext->next->next) return false;
        pstNNext = pstNNext->next->next;
    }
    
    return true;
}

/*
 * leetcode 62:
 * Level    : easy
 * 136. Single Number
 *
 *
 */
int singleNumber(int* nums, int numsSize) {
    int                 i               = 1;
    while (i < numsSize)
    {
        nums[0] ^= nums[i++];
    }

    return nums[0];
    
}
/*
 * leetcode 61:
 * Level    : easy
 * 125. Valid Palindrome
 *
 */
#define IS_P_VALID_CHAR(c) \
    (((c >='a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) ? true : false)
#define IS_FUZZY_EQUAL(a, b) \
    (toupper(a) == toupper(b) ? true : false)
bool isPalindrome(char* s) {
    int                 i               = 0;
    int                 j               = 0;

    for (j = strlen(s) - 1; i < j;)
    {
        if (!IS_P_VALID_CHAR(s[i])) {
            i++;
            continue;
        }
        if (!IS_P_VALID_CHAR(s[j])) {
            j--;
            continue;
        } 
        if (!IS_FUZZY_EQUAL(s[i], s[j])) return false;
        i++;
        j--;
    }

    return true;
}

/*
 * leetcode 60:
 * Level    : easy
 * 122. Best Time to Buy and Sell Stock II
 *
 */
int maxProfit(int* prices, int pricesSize) {
    int                 iMinPrice       = 0;
    int                 iMaxProfit      = 0;
    int                 i               = 0;

    if (pricesSize <= 0) return 0;
    for (iMinPrice = prices[0], i = 1; i < pricesSize; i++)
    {
        /* calc profit */
        if (prices[i] > iMinPrice)
        {
            iMaxProfit += prices[i] - iMinPrice;
        }
        iMinPrice = prices[i];
    }
    /* don't need to compare to maxProfitI */
        
    return iMaxProfit;
}    

/*
 * leetcode 59:
 * Level    : easy
 * 121. Best Time to Buy and Sell Stock
 *
 */
int maxProfitI(int* prices, int pricesSize) {
    int                 iMinPrice       = 0;
    int                 iMaxProfit      = 0;
    int                 i               = 0;

    if (pricesSize <= 0) return 0;
    for (iMinPrice = prices[0], i = 1; i < pricesSize; i++)
    {
        if (prices[i] < iMinPrice)
        {
            iMinPrice = prices[i];
        }
        else
        {
            if ( prices[i] - iMinPrice > iMaxProfit)
            {
                iMaxProfit = prices[i] - iMinPrice;
            }
        }
    }

    return iMaxProfit;
}
/*
 * leetcode 58:
 * Level    : easy
 * 119. Pascal's Triangle II
 *
 * use dp.
 */
int* getRow(int rowIndex, int* returnSize) {
    int                 i               = 0;
    int                 j               = 0;
    int**               ppOutArr        = NULL;
    int*                pOutSize        = NULL;

    if (rowIndex > 33 || rowIndex < 0) return NULL;

    ppOutArr = malloc((rowIndex + 1) * sizeof(int*));
    memset(ppOutArr, 0, sizeof(int*) * (rowIndex + 1));
    
    pOutSize = malloc(sizeof(int) * (rowIndex + 1));
    memset(pOutSize, 0, sizeof(int) * (rowIndex + 1));


    for (; i <= rowIndex; i++)
    {
        ppOutArr[i] = malloc((1 + i) * sizeof(int));
        memset(ppOutArr[i], 0, sizeof(int) * (i + 1));
        for (j = 0; j <= i; j++)
        {
            ppOutArr[i][j] = 1;
        }
        pOutSize[i] = i + 1;
    }
    if (rowIndex < 2) 
    {
        *returnSize = pOutSize[rowIndex];
        return ppOutArr[rowIndex];
    }

    for (i = 2; i <= rowIndex; i++)
    {
        for (j = 1; j < i; j++)
        {
            ppOutArr[i][j] = ppOutArr[i - 1][j - 1] + ppOutArr[i - 1][j];
        }
    }

    *returnSize = pOutSize[rowIndex];
    return ppOutArr[rowIndex];
}

/*
 * leetcode 56:
 * Level    : easy
 * 118. Pascal's Triangle
 * use dp.
 */
int** generate(int numRows, int** columnSizes) {
    int                 i               = 0;
    int                 j               = 0;
    int**               ppOutArr        = NULL;
    int*                pOutSize        = NULL;

    if (numRows <= 0) return NULL;

    ppOutArr = malloc(numRows * sizeof(int*));
    memset(ppOutArr, 0, sizeof(int*) * numRows);
    
    pOutSize = malloc(sizeof(int) * numRows);
    memset(pOutSize, 0, sizeof(int) * numRows);


    for (; i < numRows; i++)
    {
        ppOutArr[i] = malloc((1 + i) * sizeof(int));
        memset(ppOutArr[i], 0, sizeof(int) * (i + 1));
        for (j = 0; j <= i; j++)
        {
            ppOutArr[i][j] = 1;
        }
        pOutSize[i] = i + 1;
    }
    if (numRows <= 2) 
    {
        *columnSizes = pOutSize;
        return ppOutArr;
    }

    for (i = 2; i < numRows; i++)
    {
        for (j = 1; j < i; j++)
        {
            ppOutArr[i][j] = ppOutArr[i - 1][j - 1] + ppOutArr[i - 1][j];
        }
    }

    *columnSizes = pOutSize;
    return ppOutArr;
}
/*
 * leetcode 55:
 * Level    : easy
 * 112. Path Sum
 *
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    int                 iRet            = 0;
    if (!root) return false;
    if (isLeafNode(root))
    {
        if (sum == root->val) return true;
        return false;
    }

    if (root->left) 
    {
        iRet = hasPathSum(root->left, sum - root->val);
    }
    if (iRet) return iRet;

    if (root->right) 
    {
        iRet = hasPathSum(root->right, sum - root->val);
    }
    return iRet;
}


/*
 * leetcode 54:
 * Level    : easy
 * 111. Minimum Depth of Binary Tree
 *
 */
int minDepth(struct TreeNode* root) {
    int                 iLHeight        = 0;
    int                 iRHeight        = 0;
    if (!root) return 0;
    if (isLeafNode(root)) return 1;

    iLHeight = minDepth(root->left);
    iRHeight = minDepth(root->right);

    if (!(root->left)) return (iRHeight + 1);
    if (!(root->right)) return (iLHeight + 1);

    return (1 + MIN_INT(iRHeight, iLHeight));
}

/*
 * leetcode 53:
 * Level    : easy
 * 110. Balanced Binary Tree
 *
 */
bool isBalanced(struct TreeNode* root) {
    int                 iLHeight        = 0;
    int                 iRHeight        = 0;
    if (!root) return true;
    
    iLHeight = (root->left ? getBinTreeHeight(root->left) :0);
    iRHeight = (root->right ? getBinTreeHeight(root->right) :0);

    if (abs(iLHeight - iRHeight) > 1) return false;
    
    if (!isBalanced(root->left))  return false;;
    if (!isBalanced(root->right)) return false;

    return true;
}

/*
 * leetcode 52:
 * Level    : easy
 * 108. Convert Sorted Array to Binary Search Tree
 *
 */
struct TreeNode* InitBSTL(int iStart, int iEnd, int* nums) {
    struct TreeNode*    pstRoot         = NULL;
    struct TreeNode*    pstRight        = NULL;
    struct TreeNode*    pstLeft         = NULL;
    int                 iMid            = 0;

    if (iStart > iEnd) return NULL;

    pstRoot = malloc(sizeof(struct TreeNode));
    memset(pstRoot, 0, sizeof(*pstRoot));
    pstRoot->left = NULL;
    pstRoot->right = NULL;

    if (iStart == iEnd) 
    {
        pstRoot->val = nums[iStart];
        pstRoot->left = NULL;
        pstRoot->right = NULL;
        return pstRoot;
    }

    iMid = (iEnd + iStart) / 2;
    pstRoot->val = nums[iMid];

    pstLeft = InitBSTL(iStart, iMid - 1, nums);
    pstRight = InitBSTL(iMid + 1 , iEnd, nums);

    pstRoot->left = (pstLeft ? pstLeft : NULL);
    pstRoot->right = (pstRight ? pstRight : NULL);

    return pstRoot;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode*    pstRoot         = NULL;
    struct TreeNode*    pstRight        = NULL;
    struct TreeNode*    pstLeft         = NULL;
    int                 iMid            = 0;

    if (!numsSize) return NULL;

    iMid = (numsSize - 1) / 2;
    pstRoot = malloc(sizeof(struct TreeNode));
    memset(pstRoot, 0, sizeof(struct TreeNode));
    pstRoot->val = nums[iMid];
    pstRoot->left = NULL;
    pstRoot->right = NULL;
    
    pstLeft = InitBSTL(0, iMid - 1, nums);
    pstRight = InitBSTL(iMid + 1 , numsSize - 1, nums);

    pstRoot->left = (pstLeft ? pstLeft : NULL);
    pstRoot->right = (pstRight ? pstRight : NULL);

    return pstRoot;
}
/* mid using right */
struct TreeNode* InitBST(int iStart, int iEnd, int* nums) {
    struct TreeNode*    pstRoot         = NULL;
    struct TreeNode*    pstRight        = NULL;
    struct TreeNode*    pstLeft         = NULL;
    int                 iMid            = 0;

    if (iStart > iEnd) return NULL;

    pstRoot = malloc(sizeof(struct TreeNode));
    memset(pstRoot, 0, sizeof(*pstRoot));
    pstRoot->left = NULL;
    pstRoot->right = NULL;

    if (iStart == iEnd) 
    {
        pstRoot->val = nums[iStart];
        pstRoot->left = NULL;
        pstRoot->right = NULL;
        return pstRoot;
    }

    iMid = (iEnd + iStart + 1) / 2;
    pstRoot->val = nums[iMid];

    pstLeft = InitBST(iStart, iMid - 1, nums);
    pstRight = InitBST(iMid + 1 , iEnd, nums);

    pstRoot->left = (pstLeft ? pstLeft : NULL);
    pstRoot->right = (pstRight ? pstRight : NULL);

    return pstRoot;
}
struct TreeNode* sortedArrayToBST1(int* nums, int numsSize) {
    struct TreeNode*    pstRoot         = NULL;
    struct TreeNode*    pstRight        = NULL;
    struct TreeNode*    pstLeft         = NULL;
    int                 iMid            = 0;

    if (!numsSize) return NULL;

    iMid = numsSize / 2;
    pstRoot = malloc(sizeof(struct TreeNode));
    memset(pstRoot, 0, sizeof(struct TreeNode));
    pstRoot->val = nums[iMid];
    pstRoot->left = NULL;
    pstRoot->right = NULL;
    
    pstLeft = InitBST(0, iMid - 1, nums);
    pstRight = InitBST(iMid + 1 , numsSize - 1, nums);

    pstRoot->left = (pstLeft ? pstLeft : NULL);
    pstRoot->right = (pstRight ? pstRight : NULL);

    return pstRoot;
}

int main()
{
    int                 iRet                    = 0;
    int                 aiArr[]                 = {2,7,9,3,1};
    //int                 aiArr[]                 = {2,1,1,2};
    iRet = rob(aiArr, sizeof(aiArr) / sizeof(int));
    printf("iRet = [%d].\n", iRet);

#if 0
    iRet = trailingZeroes(51);
    printf("iRet = [%d].\n", iRet);

    long long             iRet                = 0;
    iRet = jc(30);
    printf("iRet = [%lld].\n", iRet);
    iRet = titleToNumber("ZY");
    printf("iRet = [%d].\n", iRet);
    char*           pcOut               = NULL;
    
    pcOut = convertToTitle(26);
    printf("iRet = [%s].\n", pcOut);
    int             iRet                = 0;
    //char*           pc1                 = "A man, a plan, a canal: Panama";
    char*           pc1                 = "0P";
    iRet = isPalindrome(pc1);
    printf("iRet = [%d].\n", iRet);
    struct TreeNode* pstRoot            = NULL;
    int             iArr[]              = {-10,-3,0,5,9};

    pstRoot = sortedArrayToBST(iArr, sizeof(iArr) / sizeof(int));
#endif
    
    return 0;
}
