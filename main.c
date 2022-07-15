#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv[]){
    if (argc != 2) {
        fprintf(stderr, "argument error");
        return 1;
    }

    printf(".intel_syntax noprefix\n");
    printf(".global_main\n");
    printf("main:\n");
    printf("    mov rax, %d\n", atoi(argv[1]));
    printf("    ret");
    return 0;
}
