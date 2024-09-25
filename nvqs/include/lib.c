#include "lib.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include <string.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// swap(&a[1], &a[2]);
// swap(&n, &m);

int StringEqual(char chuoi1[], char chuoi2[]){
    for (int i = 0; i < i + 1; i++){
        if(chuoi1[i] == '\0' && chuoi2[i] == '\0')
            return 1;
        else if (chuoi1[i] == '\0' || chuoi2[i] == '\0')
            return 0;
        else if (chuoi1[i] != chuoi2[i])
            return 0;
    }
}

int findMax(int a[], int n){
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}

int findMin(int a[], int n){
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (min > a[i])
            min = a[i];
    return min;
}

void insertionSort(int a[], int n){
    int k;
    for (int i = 1; i < n; i++){
        k = a[i];
        int j = i;
        while (j > 0 && a[j-1] > k){
            a[j] = a[j-1];
            j--;
        }
        a[j] = k;
    }
}

void selectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(&a[min], &a[i]);
    }
}

void bubbleSort(int a[], int n){
    for (int i = n-1; i > -1; i--){
        int flag = 1;
        for (int j = 0; j < i; j++){
            if (a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                flag = 0;
            }
        } if (flag) return;
    }
}

void bubbleSort2(int a[], int n){
    for (int i = n-1; i > -1; i--)
        for (int j = 0; j < i; j++)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}


void show(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* Swaps strings by swapping pointers */ 
void swap1(char **str1_ptr, char **str2_ptr) { 
  	char *temp = *str1_ptr; 
  	*str1_ptr = *str2_ptr; 
  	*str2_ptr = temp; 
}
  // char *str1 = "geeks"; 
  // char *str2 = "forgeeks"; 
  // swap1(&str1, &str2); 