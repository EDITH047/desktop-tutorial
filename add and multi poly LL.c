#include <stdio.h>
#include <stdlib.h>
struct PolyNode {
    int coeff; 
    int exp;  
    struct PolyNode* next; 
};
struct PolyNode *poly1 = NULL;
struct PolyNode *poly2 = NULL;
struct PolyNode *result = NULL;
void insert_term(struct PolyNode** poly, int coeff, int exp) {
    struct PolyNode* new_node = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    if (*poly == NULL || (*poly)->exp < exp) {
        new_node->next = *poly;
        *poly = new_node;
    } else {
        struct PolyNode* temp = *poly;
        while (temp->next != NULL && temp->next->exp >= exp) {
            if (temp->next->exp == exp) {
                temp->next->coeff += coeff;
                free(new_node);
                return;
            }
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void add() {
    struct PolyNode* p1 = poly1;
    struct PolyNode* p2 = poly2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insert_term(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insert_term(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            insert_term(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insert_term(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert_term(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
}
void multiply() {
    struct PolyNode* p1 = poly1;
    struct PolyNode* p2 = poly2;
    while (p1 != NULL) {
        struct PolyNode* temp = p2;
        while (temp != NULL) {
            insert_term(&result, p1->coeff * temp->coeff, p1->exp + temp->exp);
            temp = temp->next;
        }
        p1 = p1->next;
    }
}
void display(struct PolyNode* poly) {
    struct PolyNode* temp = poly;
    while (temp != NULL) {
        if (temp->coeff > 0 && temp != poly) {
            printf("+");
        }
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("= 0");
    printf("\n");
}
void free_poly(struct PolyNode* poly) {
    struct PolyNode* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
    result = NULL;
}
int main()
{
    int choice, coeff, exp;
    while (1) {
        printf("1. Insert Polynomial 1\n");
        printf("2. Insert Polynomial 2\n");
        printf("3. Add Polynomials\n");
        printf("4. Multiply Polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter coefficient and exponent (-999 to stop): ");
            while (1) {
                scanf("%d", &coeff);
                if (coeff == -999) break;
                scanf("%d", &exp);
                insert_term(&poly1, coeff, exp);
            }
        } else if (choice == 2) {
            printf("Enter coefficient and exponent (-999 to stop): ");
            while (1) {
                scanf("%d", &coeff);
                if (coeff == -999) break;
                scanf("%d", &exp);
                insert_term(&poly2, coeff, exp);
            }
        } else if (choice == 3) {
            free_poly(result);
            add();
            printf("Resultant Polynomial: ");
            display(result);
        } else if (choice == 4) {
            free_poly(result);
            multiply();
            printf("Resultant Polynomial: ");
            display(result);
        } else if (choice == 5) {
            free_poly(result);
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
