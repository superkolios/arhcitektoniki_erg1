#include <stdio.h>

void bubbleSort(double *array, int n){
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            if (array[i] > array[j]){
                double temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printArray(double *array, int n){
    for (int i = 0; i < n; ++i){
        printf("%lf ", array[i]);
    }
    printf("\n");
}

int main(){
    double dummyArray[60] = {1.0, 5.0, 6.23, 7.555, 58.7, 1775.11234, 1435.77642, 9576.6653, 5.6, 2.5, 42223.1, 42223.2, 55642.101, 50.1, 23.88, 1000.0, 150.3, 77.45, 99.9999, 556.7331, 900012.442, 5.7, 6.888833, 9.11112222, 0.00123, 69.6969, 111.11111, 666.966, 456.0, 987.123, 654.789, 159.762, 544.712, 609.0023005, 113.1124, 556.101012, 889.5544, 103056.3034031, 6.09650965, 22.330033, 9999.003210321, 9898.88880088, 100.33, 66.66, 2134.6578, 60889.5543, 77.7767, 777.777, 555.555, 54444.0005054444, 951.062, 753.864975, 11109.111011109001, 5005006.45005600520078, 15351535.4535, 5389204.63717, 22.2200222, 10301.777798, 30000100.99999, 190000111.5 };
    int n = 60;

    bubbleSort(dummyArray, n);
    printArray(dummyArray, n);
    return 0;
}