#define DESC(str) 		1

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define true  1
#define false 0

/* Declare Function */
struct TreeNode* preTravel(struct TreeNode* root, int iVal);


static int
cmpstringp(const void *p1, const void *p2)
{
   /* The actual arguments to this function are "pointers to
*               pointers to char", but strcmp(3) arguments are "pointers
*                             to char", hence the following cast plus dereference */

   return strcmp(* (char * const *) p1, * (char * const *) p2);
}


static void
sortn(int* pi, int iSize)
{
    int             i               = 0;
    int             j               = 0;
    int             m               = 0;
    for (i = 0; i < iSize; i++)
    {
        for (j = i + 1; j < iSize; j++)
        {
            if (pi[i] > pi[j])
            {
                m = pi[i]; pi[i] = pi[j]; pi[j] = m;
            }
        }
    }
    return;
}

static int
cmpn(const void *p1, const void *p2)
{
    return (*(int*)p1 - *(int*)p2);
}

struct ListNode*  consList(int* pi, int iCount)
{
    struct ListNode*    pstRet          = NULL;
    struct ListNode*    pstTmp          = NULL;
    struct ListNode*    pstTail         = NULL;
    int                 i               = 0;
    while (i < iCount)
    {
        pstTmp = malloc (sizeof (struct ListNode));
        pstTmp->val = *(pi + i);
        pstTmp->next = NULL;

        if (!pstRet)
        {
            pstRet = pstTmp;
            pstTail = pstTmp;
        }
        else
        {
            pstTail->next = pstTmp;
            pstTail = pstTmp;
        }
        i++;
    }

    return pstRet;
}

struct ListNode* SortList(struct ListNode* head)
{
    struct ListNode* pstNode            = head;
    struct ListNode* pstSort            = NULL;
    struct ListNode* pstTail            = NULL;
    int             iCount              = 0;
    int             i                   = 0;
    int*            piArr               = NULL;
 
    while (pstNode)
    {
        iCount++;
        pstNode = pstNode->next;
    }

    piArr = malloc(sizeof(int) * iCount);
    memset(piArr, 0, sizeof(int) * iCount);

    
    iCount = 0;
    pstNode = head;
    while (pstNode)
    {
        piArr[iCount++] = pstNode->val;
        pstNode = pstNode->next;
    }

    qsort(piArr, iCount, sizeof(int), cmpn);

    while (i < iCount)
    {
        pstNode = malloc(sizeof(struct ListNode));
        memset(pstNode, 0, sizeof(sizeof(struct ListNode)));
        pstNode->next = NULL;

        if (!pstSort)
        {
            pstSort = pstNode;
            pstTail = pstNode;
        }
        pstNode->val = *(piArr + i);
        pstTail->next = pstNode;
        pstTail = pstNode;
        i++;
    }
    
    return pstSort;
}

void PrtList(struct ListNode* head)
{
    struct ListNode* pstNode            = head;
    while (pstNode)
    {
        printf("%d-", pstNode->val);
        pstNode = pstNode->next;
    }
}

void DestoryList(struct ListNode* head)
{
    struct ListNode* pstNode            = head;
    struct ListNode* pstNext            = head;
    while (pstNext)
    {
        pstNext = pstNode->next;
        free(pstNode);
        pstNode = pstNext;
    }

}
#if DESC("binary_tree")

/*
 * @ desc: initBinaryTree
 * @ in  :  
 *          aiArr 
 *          iSize
 * @ out :
 *         target binary tree
 * @ cautious :
 *  n pos in arr
 *  child pos is 2n + 1, 2n + 2
 *  
 *          0
 *      1       2
 *    3   4   5   6
 *  ...
 *  Child poionter is null that arr value is 0.
 */
struct TreeNode* initBinaryTree(int aiArr[], int iSize)
{
    struct TreeNode *pstNode            = NULL;
    struct TreeNode *pstLeft            = NULL;
    struct TreeNode *pstRight           = NULL;
    struct TreeNode *pstRoot            = NULL;
    int             i                   = 0;

    for (; i < iSize; i++)
    {
        if (0 == i)
        {
            /* as root */
            if (!aiArr[0]) return NULL;
            pstNode = malloc(sizeof(struct TreeNode));
            memset(pstNode, 0, sizeof(struct TreeNode));
            pstNode->val = aiArr[0];
            pstNode->left = NULL;
            pstNode->right = NULL;
            pstRoot = pstNode;
        }
        else
        {
            if (0 == aiArr[i])
            {
                continue;
            }
            pstNode =  preTravel(pstRoot, aiArr[i]);
            if (!pstNode) 
            {
                return NULL;
            }
        }

        /* construct child */
        if (iSize >= 2 * (i + 1) - 1)
        {
            if (aiArr[2 * i + 1])
            {
                pstLeft = malloc(sizeof(struct TreeNode));
                memset(pstLeft, 0, sizeof(struct TreeNode));
                pstLeft->val = aiArr[2 * i + 1];
                pstNode->left = pstLeft;
            }

            if ((iSize >= 2 * (i + 1) ) && (aiArr[2 * i + 2]))
            {
                pstRight = malloc(sizeof(struct TreeNode));
                memset(pstRight, 0, sizeof(struct TreeNode));
                pstRight->val = aiArr[2 * i + 2];
                pstNode->right = pstRight;
            }
        }
    }
    return pstRoot;
}
struct TreeNode* getBinNodeParent(struct TreeNode* root, int iVal)
{
    struct TreeNode*    pstNode             = NULL;
    if (!root || (iVal == root->val))
    {
        return NULL;
    }

    if (root->left)
    {
        if (iVal == root->left->val) return root;
        pstNode = getBinNodeParent(root->left, iVal);
        if (pstNode) return pstNode;
        pstNode = getBinNodeParent(root->right, iVal);
        if (pstNode) return pstNode;
    }
    if (root->right)
    {
        if (iVal == root->right->val) return root;
        pstNode = getBinNodeParent(root->left, iVal);
        if (pstNode) return pstNode;
        pstNode = getBinNodeParent(root->right, iVal);
        if (pstNode) return pstNode;
    }
    return pstNode;
}
int getBinNodeHeight(struct TreeNode* root, int iVal)
{
    struct TreeNode*    pstNode             = NULL;
    int                 iHeight             = 0;
    if (root)
    {
        if (iVal == root->val) return iHeight;
    }
    if (root->left)
    {
        pstNode = preTravel(root->left, iVal);
        if (pstNode) return (getBinNodeHeight(root->left, iVal) + 1);
    }
    if (root->right)
    {
        pstNode = preTravel(root->right, iVal);
        if (pstNode) return (getBinNodeHeight(root->right, iVal) + 1);
    }
    return iHeight;

}
struct TreeNode* preTravel(struct TreeNode* root, int iVal)
{
    struct TreeNode*    pstNode             = NULL;
    if (root)
    {
        if (iVal == root->val) return root;
    }
    if (root->left)
    {
        pstNode = preTravel(root->left, iVal);
        if (pstNode) return pstNode;
    }
    if (root->right)
    {
        pstNode = preTravel(root->right, iVal);
        if (pstNode) return pstNode;
    }
    return pstNode;

}

struct TreeNode* postTravel(struct TreeNode* root)
{
    if (root->left) postTravel(root->left);
    if (root->right) postTravel(root->right);
    printf("%d ", root->val);
    return root;
}
struct TreeNode* getFistNodeByPostTravel(struct TreeNode* pstRoot)
{
    return NULL;
}
struct TreeNode* getNextByPostTravel(struct TreeNode* pstRoot)
{
    struct TreeNode*    pstParentNode   = NULL;
    if (pstRoot->left) return pstRoot->left;
    if (pstRoot->right) postTravel(pstRoot->right);
    pstParentNode = getBinNodeParent(pstRoot, pstRoot->val);
    if (!pstParentNode) return NULL;
    return getNextByPostTravel(pstParentNode);
}
#endif
