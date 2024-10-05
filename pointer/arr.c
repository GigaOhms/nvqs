#include <stdio.h>
#include <stdlib.h>

void input(int *len, int **arr){
	do {
		printf("Nhap mang: ");
		scanf("%d", len);
	} while (*len < 1);
	*arr = (int *)malloc(*len * sizeof(int));
	for (int i = 0; i < *len; i++)
		scanf("%d", (*arr + i));
}

void output(int n, int arr[]){
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(int argc, char const *argv[]){
	int *arr;
	int len;
	input(&len, &arr);
	output(len, arr);
}