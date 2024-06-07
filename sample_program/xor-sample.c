#include <stdio.h>
#include <stdlib.h>

int bool_xor(int x, int y) {
    int result= x^y;
    printf("%d\n", result);
    return 0;
}

int main(int argc, char **argv) {
    if (argc<3) {
        printf("Too few args.\n");
        exit(1);
    }

    return bool_xor( atoi(argv[1]), atoi(argv[2]) );
}