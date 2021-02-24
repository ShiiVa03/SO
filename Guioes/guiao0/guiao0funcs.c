#include <stdio.h>

void fill (int *vector, int size, int value){
    for (int i = 0; i < size ; i++)
        vector[i] = value;
}

int find (int *vector, int size, int value){
    int ans;
    for (int i = 0; i < size; i++){
        if (vector[i]== value){
            ans = vector[i];
            return ans;
        }
    }
    return -1;
}
    