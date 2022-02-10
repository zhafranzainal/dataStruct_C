#include <stdio.h>
#include <stdlib.h>

//Structure Declaration (Template)
struct Node{

    //Data Field
    char data;

    //Pointer (Link) Field
    struct Node *left, *right;};

//Function Declaration (Prototype)
struct Node *newNode(char data);
void create();
void printOutput(struct Node* node);

int main(void){

    create();
    printf("\n");

return 0;
}

struct Node *newNode(char data){

    struct Node *node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);

}

void create(){

    struct Node *root = newNode('x');
    root->left = newNode('t');
    root->right = newNode('d');
    root->left->left = newNode('v');
    root->right->right = newNode('w');
    root->left->right = newNode('k');
    root->right->left = newNode('y');
    root->left->right->left = newNode('p');
    root->right->right->left = newNode('z');
    root->right->left->left= newNode('m');

    printOutput(root);

}

void printOutput(struct Node* node){

    if(node==NULL){
        return;}

    printOutput(node->right);
    printf("%c ", node->data);
    printOutput(node->left);

}

