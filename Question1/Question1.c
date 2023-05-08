#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    DIV,
    FIBO
} TypeTag;

typedef struct Node {
    TypeTag type;
    int left;
    int right;
    int result;
} Node;

//function prototype
Node *makeFunc(TypeTag type, int left, int right);
int calc(Node *node);

int main() { 
    Node *add = makeFunc(ADD, 10, 6);
    calc(add);

    Node *mul = makeFunc(MUL, 5, 4);
    calc(mul);

    Node *sub = makeFunc(SUB, mul->result, add->result);
    calc(sub);

    Node *fibo = makeFunc(FIBO, sub->result, 0);
    calc(fibo);

    //freeing memory
    free(add);
    free(mul);
    free(sub);
    free(fibo);

    system("pause");

    return 0;
}

Node *makeFunc(TypeTag type, int left, int right) {
    Node *node = (Node*)malloc(sizeof(Node));

    node->left = left;
    node->right = right;
    node->type = type;

    return node;
}

int calc(Node *node) {
    int nth_fib_number;

    switch(node->type) {
        case ADD:
            node->result = node->left + node->right;
            printf("Addition : %d\n", node->result);
            break;

        case MUL:
            node->result = node->left * node->right;
            printf("Multiplication : %d\n", node->result);
            break;

        case SUB:
            node->result = node->right - node->left;
            printf("Subtraction : %d\n", node->result);
            break;

        case DIV:
            if(node->right == 0) {
                printf("Division by zero not allowed \n");
                exit(0);
            }
            node->result = node->right / node->left;
            printf("Division : %d\n", node->result);
            break;

        case FIBO:
            nth_fib_number = abs(node->left);
            if(nth_fib_number <= 1) node->result = 0;
            else {
                int first_num = 0, second_num = 1, temp;
                for(int i=2; i<nth_fib_number; i++) {
                    temp = second_num;
                    second_num += first_num;
                    first_num = temp;
                }
                node->result = second_num;
                printf("%dth fibonacci number : %d\n", nth_fib_number, node->result);
            }
            break;

        default:
            printf("Type Not allowed \n");
    }

    return node->result;
}