#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#include "leetcode.h"

#define bool int
/*
 * leetcode 50:
 * Level    : easy
 * 100. Same Tree
 * use recursive 
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) return true;
    if ((p && !q) || (!p && q)) return false;

    /* both not empty */
    if (p->val != q->val) return false;

    if (!isSameTree(p->left, q->left)) return false;
    if (!isSameTree(p->right, q->right)) return false;

    return true;
}
bool isSameTree1(struct TreeNode* p, struct TreeNode* q) {
    int*                piP                     = NULL;
    int*                piQ                     = NULL;
    int                 iPSize                  = 0;
    int                 iQSize                  = 0;
    int                 i                       = 0;
    int                 j                       = 0;
    int                 iRet                    = 1;

    piP = deserialBinTree(p, &iPSize);
    piQ = deserialBinTree(q, &iQSize);
    

    for (i = iPSize, j = iQSize; (i == j) && (i >= 0); i--, j--)
    {
        if (piP[i] != piQ[j])
        {
            iRet = 0;
            goto error;
        }
    }

    if (i != j) 
    {
        iRet = 0;
    }

error:
    free (piP);
    free (piQ);
    return iRet;
}


/*
 * leetcode 49:
 * Level    : easy
 * 88. Merge Sorted Array
 *
 */
void merge(int* nums1, int m, int* nums2, int n) {
    int                 i                        = 0;
    int                 j                        = 0;
    
    for (i = m, j = 0; j < n; j++, i++)
    {
        nums1[i] = nums2[j];
    } 

    qsort(nums1, m + n, sizeof(int), cmpn);

    return;
}

/*
 * leetcode 48:
 * Level    : easy
 * 83. Remove Duplicates from Sorted List
 *
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode*     pstList                = NULL;
    struct ListNode*     pstNext                = NULL;

    if (!head) return NULL;

    pstList = head;
    pstNext = pstList->next;

    while (pstNext)
    {
        if (pstList->val == pstNext->val)
        {
            pstList->next = pstNext->next;
            pstNext = pstNext->next;
            /* TODO: free pstNext */
            continue;
        }
        pstList = pstNext;
        pstNext = pstNext->next;
    }

    return head;
}

/*
 * leetcode 47:
 * Level    : easy
 * 69. Sqrt(x)
 *
 */
int mySqrt(int x) {
    int                 i                       = 1;

    if (x <= 0) return 0;    
    if (x >= 2147395600) return 46340;

    while (i * i <= x) i++;

    return (i-1);
}

/*
 * leetcode 46:
 * Level    : easy
 * 67. Add Binary
 *
 */
char* addBinary(char* a, char* b) {
    int                 iLen                    = 0;
    int                 i                       = 0;
    int                 iCarry                  = 0;
    int                 j                       = 0;
    char*               pcOut                   = NULL;

    iLen = MAX_INT(strlen(a), strlen(b));
    pcOut = malloc(sizeof(char) * (iLen + 1 + 1));
    memset(pcOut, 0, iLen + 2);

    for (i = strlen(a) - 1, j = strlen(b) - 1; (i >= 0) && (j >= 0); i--, j--, iLen--)
    {
        if(a[i] == b[j])
        {
            pcOut[iLen - 1] = (iCarry ? '1' : '0');
            iCarry = ((a[i] == '1') ? 1 : 0);
        }
        else
        {
            pcOut[iLen - 1] = (iCarry ? '0' : '1');
        }
    }

    /* pro left */
    while (i >= 0)
    {
        pcOut[i] = ((a[i] == '1') ? (iCarry ? ' 0' : '1') : (iCarry ? '1' : '0'));
        iCarry = ((a[i] == '0') ? 0 : iCarry); 
        i--;
    }

    while (j >= 0)
    {
        pcOut[j] = ((b[j] == '1') ? (iCarry ? ' 0' : '1') : (iCarry ? '1' : '0'));
        iCarry = ((b[j] == '0') ? 0 : iCarry); 
        j--;
    }

    if (iCarry)
    {
        iLen = MAX_INT(strlen(a), strlen(b));
        //strncpy(&pcOut[1], &pcOut[0], iLen);
        while (iLen > 0)
        {
            pcOut[iLen] = pcOut[iLen - 1];
            iLen--;
        }

        pcOut[0] = '1';
    }
    
    /* TODO: free pcOut */
    return pcOut;
}

int main()
{
    int             iRet                = 0;
    struct TreeNode *pstRoot1           = NULL;
    int             aiArr1[]            = {1, 2, 0, 4, 3};
    struct TreeNode *pstRoot2           = NULL;
    int             aiArr2[]            = {1, 6, 0, 4, 3};
 
    pstRoot1 = initBinaryTree(aiArr1, sizeof(aiArr1) / sizeof(int));
    pstRoot2 = initBinaryTree(aiArr2, sizeof(aiArr2) / sizeof(int));

    iRet = isSameTree(pstRoot1, pstRoot2);
    printf("%d.\n", iRet);
#if 0
    int                     aiArr1[]            = {1,2,3,0,0,0};
    int                     aiArr2[]            = {2, 5, 6};

    merge(aiArr1, 3,  aiArr2, 3);
    char*                   pcA                 = "101111";
    char*                   pcB                 = "10";
    char*                   pcOut               = NULL;

    pcOut = addBinary(pcA, pcB);

    printf("%s.\n", pcOut);
#endif
    return 0;
}
