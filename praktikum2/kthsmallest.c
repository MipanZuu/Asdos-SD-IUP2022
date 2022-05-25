#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct bstnode_t {
    int key;
      struct bstnode_t *left, *right;
}     BSTNode;


typedef struct bst_t {
      BSTNode *_root;
      unsigned int _size;
} BST;


BSTNode* __bst__createNode(int value) {
  BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
  newNode->key = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
  if (root == NULL)
    return __bst__createNode(value);

  if (value < root->key)
    root->left = __bst__insert(root->left, value);
  
  else if (value > root->key)
      root->right = __bst__insert(root->right, value);
  
  return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
  while (root != NULL) {
    if (value < root->key)
      root = root->left;
    else if (value > root->key)
      root = root->right;
    else
      return root;
  }
  return root;
}

bool bst_find(BST *bst, int value) {
      BSTNode *temp = __bst__search(bst->_root, value);
      if (temp == NULL)
        return false;
  
      if (temp->key == value)
        return true;
      else
        return false;
}


void bst_init(BST *bst) {
      bst->_root = NULL;
      bst->_size = 0u;
}

void bst_insert(BST *bst, int value) {
      if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
  }
}
void printKthNode(BSTNode* root, int N)
{
   if(root == NULL)
       return;

   static int index = 0; 
   
   printKthNode(root->left, N);


   //Right has returned and now current node will be greatest
   if(++index == N)
   {
    printf("%d", root->key);
    return;
   }

   //And at last go to the left
   printKthNode(root->right, N);
}

void print (BST *bst, int k)
{
    printKthNode(bst->_root, k);
}

int main()
{
      BST Bakery;
      int chef, K, drigo[100];
      bst_init(&Bakery);

    scanf("%d %d", &chef, &K);
    for (int i = 0; i < chef; i++) {
        scanf("%d", &drigo[i]);
        bst_insert(&Bakery, drigo[i]);
    }
    print(&Bakery, K);
  return 0;
}
