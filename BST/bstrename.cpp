/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* bst_insert(BSTNode *root, int value) {
    if (root == NULL) 
        return createNode(value);

    if (value < root->key)
        root->left = bst_insert(root->left, value);
    else if (value > root->key)
        root->right = bst_insert(root->right, value);
    
    return root;
}

BSTNode* bst_search(BSTNode *root, int value) {
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

BSTNode* findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* bst_remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = bst_remove(root->right, value);
    else if (value < root->key) 
        root->left = bst_remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = findMinNode(root->right);
        root->key     = temp->key;
        root->right   = bst_remove(root->right, temp->key);
    }
    return root;
}

void bst_inorder(BSTNode *root) {
    if (root) {
        bst_inorder(root->left);
        printf("%d ", root->key);
        bst_inorder(root->right);
    }
}

void bst_postorder(BSTNode *root) {
    if (root) {
        bst_postorder(root->left);
        bst_postorder(root->right);
        printf("%d ", root->key);
    }
}

void bst_preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        bst_preorder(root->left);
        bst_preorder(root->right);
    }
}

// PRIMARY FUNCTION


void Initialization(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool find(BST *bst, int value) {
    BSTNode *temp = bst_search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void insert(BST *bst, int value) {
    if (!find(bst, value)) {
        bst->_root = bst_insert(bst->_root, value);
        bst->_size++;
    }
}

void remove(BST *bst, int value) {
    if (find(bst, value)) {
        bst->_root = bst_remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 FUNTION CALL:
 - Initialization
 - insert
 - remove
 - find
 - isEmpty
 - inorder
 */

void inorder(BST *bst) {
    bst_inorder(bst->_root);
}

void postorder(BST *bst) {
    bst_postorder(bst->_root);
}

void preorder(BST *bst) {
    bst_preorder(bst->_root);
}
 
int main()
{
    BST set;
    Initialization(&set);

    
    puts("");
    
    return 0;
}