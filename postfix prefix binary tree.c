#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Expression Tree Node
struct Node {
    char data;
    struct Node *left, *right;
};

// Stack for Nodes
struct Node* stackNode[MAX];
int topNode = -1;

void pushNode(struct Node* n) {
    stackNode[++topNode] = n;
}
struct Node* popNode() {
    return stackNode[topNode--];
}

// Stack for operators
char stackOp[MAX];
int topOp = -1;

void pushOp(char c) {
    stackOp[++topOp] = c;
}
char popOp() {
    return stackOp[topOp--];
}
char peekOp() {
    return stackOp[topOp];
}
int isEmptyOp() {
    return topOp == -1;
}

int isp(char temp) {
    if ((temp == '-') || (temp == '+')) 
        return 2;
    else if ((temp == '*') || (temp == '/'))
        return 5;
    else if (temp == '^')
        return 8;
    else if (temp == '(') 
        return 0;
    else
        return -1;
}

int icp(char temp) {
    if ((temp == '-') || (temp == '+')) {
        return 2;
    } else if ((temp == '*') || (temp == '/')) {
        return 5;
    } else if (temp == '^')
        return 9;
    else if (temp == '(') {
        return 10;
    } else if (temp == ')') {
        return 0;
    } else {
        return -1;
    }
}

// Create new Node
struct Node* newNode(char c) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = c;
    temp->left = temp->right = NULL;
    return temp;
}

// Build expression tree from infix expression
struct Node* buildTree(char* infix) {
    int i;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (c == ' ') continue;

        if (isalnum(c)) {  // Operand
            pushNode(newNode(c));
        }
        else if (c == '(') {
            pushOp(c);
        }
        else if (c == ')') {
            while (!isEmptyOp() && peekOp() != '(') {
                char op = popOp();
                struct Node* right = popNode();
                struct Node* left = popNode();
                struct Node* n = newNode(op);
                n->left = left;
                n->right = right;
                pushNode(n);
            }
            popOp(); // remove '('
        }
        else { // Operator
            while (!isEmptyOp() && isp(peekOp()) >= icp(c)) {
                char op = popOp();
                struct Node* right = popNode();
                struct Node* left = popNode();
                struct Node* n = newNode(op);
                n->left = left;
                n->right = right;
                pushNode(n);
            }
            pushOp(c);
        }
    }

    while (!isEmptyOp()) {
        char op = popOp();
        struct Node* right = popNode();
        struct Node* left = popNode();
        struct Node* n = newNode(op);
        n->left = left;
        n->right = right;
        pushNode(n);
    }

    return popNode(); // Root of expression tree
}

// Traversals
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

int main() {
    char infix[MAX];
    printf("Enter an arithmetic expression (infix): ");
    scanf("%s", infix);

    struct Node* root = buildTree(infix);

    printf("Prefix Expression: ");
    preorder(root);
    printf("\n");

    printf("Postfix Expression: ");
    postorder(root);
    printf("\n");

    return 0;
}
