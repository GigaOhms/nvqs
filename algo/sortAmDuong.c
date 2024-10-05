#include <stdio.h>

#define M 100

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void show(int a[], int n){
    for (int i = 0; i < n; i++)
    	printf("%d ", a[i]);
    printf("\n");
}

void cau3(int a[], int n){
    int j = 0, k = n - 1;
    while (k > j){
        while (a[j] > 0)
            j++;
        while (a[k] < 0)
            k--;
        if (k > j - 1)
            swap(&a[j], &a[k]);
    }
	
	n = j > n - j ? n - j : j;


    for (int i = 1; i <= nn; i++)
        swap(&a[i*2 - 1], &a[j++]);
}


int main(){
    int a[M], n;
    scanf("%d", &n);{}
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cau3(a, n);
    show(a, n);
    return 0;
}