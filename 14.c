#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "leetcode.h"

#define bool int
struct TreeNode* preTravel(struct TreeNode* root, int iVal);

/*
 *  leetcode 14:
 *  Level    : esay
 *  283. Move Zeroes
 *  Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 *  Example:
 *
 *  Input: [0,1,0,3,12]
 *  Output: [1,3,12,0,0]
 */

void prtArr(int* n, int num)
{
    for (int i = 0; i < num; i++)
        printf("%d ", n[i]);
    printf("\n");
    
}
void moveZeroes(int* nums, int numsSize) {
    int             i               = 0;
    int             j               = 0;

    j = numsSize;
    for (; i < numsSize; i++)
    {
        if (nums[i]) 
        {
            continue;
        }
        else
        {
            for (j = i + 1; j < numsSize; j++)
            {
                if (nums[j]) 
                {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }

    return;
}
int main(int argc, char** args)
{
    int             aiArr[] = {0,1,0,3,12};
    moveZeroes(aiArr, sizeof(aiArr) / sizeof(int));
    //sortn(aiArr, sizeof(aiArr) / sizeof(int));

    for (int i = 0; i < sizeof(aiArr) / sizeof(int); i++)
    printf("%d ", aiArr[i]);


    return 0;
}
