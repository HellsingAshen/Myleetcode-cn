#define DESC(str) 		1

#define MAX_INT(a, b) 	((a > b) ? a : b)

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
struct TreeNode* getNodeByVal(struct TreeNode* root, int iVal);


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

static int cmpstrlen(const void *p1, const void *p2)
{
    return (strlen((char*)p1) - strlen((char*)p2));
}
static int cmpn(const void *p1, const void *p2)
{
    return (*(int*)p1 - *(int*)p2);
}

static int cmpc(const void *p, const void *q)
{
    return (*(char*)p - *(char*)q);

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
/* 
 * reverse string 
 */
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

#if DESC("binary_tree")

int isLeafNode(struct TreeNode* pstNode)
{
    return (((pstNode->left == NULL) && (pstNode->right == NULL)) ? 1 : 0);
}

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
 *  ele in aiArr is different.
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
            pstNode =  getNodeByVal(pstRoot, aiArr[i]);
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

/*
 * @ desc:  get binary tree height 
 * @ in  :
 * @ out :
 * @ ret :
 */
int getBinTreeHeight(struct TreeNode* root)
{
    int                 iLeftHeight         = 0;
    int                 iRightHeight        = 0;

    if (!root) return 0;

    if (!root->left && !root->right) return 1;

    if (root->left)
    {
        iLeftHeight = getBinTreeHeight(root->left);
    }

    if (root->left)
    {
        iRightHeight = getBinTreeHeight(root->right);
    }
    return (MAX_INT(iLeftHeight, iRightHeight) + 1);
}

/*
 * @ desc: deserialization binary tree to arr 
 * @ in  : 
 *          root        in_tree
 * @ out : 
 *          iSize       arrSize
 * @ ret : 
 *          outPutArr
 */
int* deserialBinTree(struct TreeNode* root, int* piSize)
{
    int*                piOut               = NULL;
    int                 iHeight             = 0;
    int                 iSize               = 0;
    int                 i                   = 0;
    int                 iStart              = 0;
    struct TreeNode*    pstNode             = NULL;
    
    /* arrsize = 2 ^ iHeight - 1 */
    iHeight = getBinTreeHeight(root);
    if (iHeight > 16) return NULL;
    iSize = (1<<iHeight) - 1;

    piOut = malloc(sizeof(int) * iSize + 1);
    memset(piOut, 0, sizeof(int) * iSize + 1);

    piOut[0] = root->val;

    for (i = 0; i <= iSize; i++)
    {
        if (piOut[i])
        {
            pstNode = getNodeByVal(root, piOut[i]);
            if (!pstNode) 
            {
                goto error;
            }
            /* set val in arr by index */
            if (pstNode->left)
            {
                piOut[i * 2 + 1] = pstNode->left->val;
            }

            if (pstNode->right)
            {
                piOut[i * 2 + 2] = pstNode->right->val;
            }
        }
    }
    
    *piSize = iSize;
    return piOut;
    
error:
    free(piOut); 
    piOut = NULL;
    *piSize = 0;
    return NULL;    
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
        pstNode = getNodeByVal(root->left, iVal);
        if (pstNode) return (getBinNodeHeight(root->left, iVal) + 1);
    }
    if (root->right)
    {
        pstNode = getNodeByVal(root->right, iVal);
        if (pstNode) return (getBinNodeHeight(root->right, iVal) + 1);
    }
    return iHeight;

}
struct TreeNode* getNodeByVal(struct TreeNode* root, int iVal)
{
    struct TreeNode*    pstNode             = NULL;
    if (root)
    {
        if (iVal == root->val) return root;
    }
    if (root->left)
    {
        pstNode = getNodeByVal(root->left, iVal);
        if (pstNode) return pstNode;
    }
    if (root->right)
    {
        pstNode = getNodeByVal(root->right, iVal);
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
