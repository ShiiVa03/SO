#include <stdio.h>
#include "guiao0funcs.h"

int main () { 
    int vector[10];

    fill(vector, 10, 5);
    for (int i = 0; i < 10 ; i++)
        printf("%d\n", vector[i]);

    find(vector, 10, 4);

    return 0;

}