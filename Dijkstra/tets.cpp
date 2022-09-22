#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct AVLNode_t{
    int key ,height;
    struct AVLNode_t *left,*right;
}AVLNode;

typedef struct AVL_t{
    AVLNode *_root;
}AVL;

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->key = value;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
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

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0;
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),_getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),_getHeight(newParrent->right))+1;

    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),_getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),_getHeight(newParrent->right))+1;

    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVLNode* node,int value) {

    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(value < node->key)
        node->left = _insert_AVL(node->left,value);
    else if(value > node->key)
        node->right = _insert_AVL(node->right,value);

    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right));

    int balanceFactor=_getBalanceFactor(node);

    if(balanceFactor > 1 && value < node->left->key) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->key) //
        return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->key)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->key)
        return _rightLeftCaseRotate(node);

    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl->_root,value);
    }
}

void printHeight(AVL *avl, int value){
    AVLNode *temp = _search(avl->_root, value);
    int height = _getHeight(temp);
    printf("The gold at %d floor\n",height);
}

int main(){
    AVL tree;
    avl_init(&tree);
    int i,t,value;
    char input[10];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s %d",input,&value);
        if(strcmp(input,"room")==0)
            avl_insert(&tree,value);
        else if(strcmp(input,"gold")==0){
            if(avl_find(&tree,value))
                printHeight(&tree,value);
            else
                puts("Gold not found");
        }else
            puts("Sorry, I don't understand ninuninu");
    }
    return 0;
}

