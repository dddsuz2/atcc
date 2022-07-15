#include <stdio.h>
#include <stdlib.h>
#include "atcc.h"

int main(int argc, char **argv){
    if (argc != 2) {
        fprintf(stderr, "argument error");
        return 1;
    }

    token = tokenize(argv[1]);
    
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("    mov rax, %d\n", expected_number());

    while (!at_eof()) {
        if (consume('+')) {
            printf("    add rax, %d\n", expected_number());
            continue;
        }

        if (consume('-')) {
            printf("    sub rax, %d\n", expected_number());
            continue;
        }
    }

    printf("    ret\n");
    return 0;
}
