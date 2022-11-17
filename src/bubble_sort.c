#include <stdio.h>

void bubbleSort(float *array, int n){
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            if (array[i] > array[j]){
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printArray(float *array, int n){
    for (int i = 0; i < n; ++i){
        printf("%f ", array[i]);
    }
    printf("\n");
}

void main(){
    float array[4] = {5.4, 3.7, 1.9, 10.8};
    int n = 4;

    bubbleSort(array, n);
    printArray(array, n);
    return 0;
}