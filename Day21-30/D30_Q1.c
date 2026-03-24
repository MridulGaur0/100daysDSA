#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

void printPolynomial(struct Term* head) {
    struct Term* current = head;
    int first = 1;
    
    while (current != NULL) {
        if (!first && current->coeff > 0) {
            printf(" + ");
        } else if (current->coeff < 0) {
            printf(" - ");
        }
        
        int absCoeff = abs(current->coeff);
        
        if (current->exp == 0) {
            printf("%d", absCoeff);
        } else if (current->exp == 1) {
            printf("%dx", absCoeff);
        } else {
            printf("%dx^%d", absCoeff, current->exp);
        }
        
        first = 0;
        current = current->next;
    }
    printf("\n");
}