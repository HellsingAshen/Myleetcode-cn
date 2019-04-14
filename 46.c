#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#include "leetcode.h"

#define bool int
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
    int                     aiArr1[]            = {1,2,3,0,0,0};
    int                     aiArr2[]            = {2, 5, 6};

    merge(aiArr1, 3,  aiArr2, 3);
#if 0
    char*                   pcA                 = "101111";
    char*                   pcB                 = "10";
    char*                   pcOut               = NULL;

    pcOut = addBinary(pcA, pcB);

    printf("%s.\n", pcOut);
#endif
    return 0;
}
