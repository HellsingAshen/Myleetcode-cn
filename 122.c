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
    return iRet;
}
