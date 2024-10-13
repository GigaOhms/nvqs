#include <stdio.h>

#define bool _Bool
#define true 1
#define false 0
#define MAX 200000000

int arr[MAX];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort3(int a[], int n) {
	int first = a[0] < a[1] ? a[0] : a[1];
	int second = a[1] + a[0] - first;

	for (int i = 2; i < n; i++) {
		if (first > a[i]) {
			second = first;
			first = a[i];
		}
		if ((a[i] < second && a[i] != first) ||
			(a[i] != second && second == first))
			second = a[i];
	}

	printf("first = %d\n", first);
	printf("second = %d\n", second);
}

void show(int a[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	bool c = true;
	int n = 10;
	// int a[12] = {0, 0, 6, 7, 8, 3, 2, 3, 1, 5};
	// int a[12] = {0, 9, 6, 7, 8, 3, 2, 3, 1, 5};
	// int a[12] = {1, 2, 6, 7, 8, 3, 2, 3, 1, 5};
	// int a[12] = {1, 5, 6, 7, 8, 3, 2, 3, 1, 0};
	int a[12] = {0, 0, 0, 0, 0, 3, 2, 3, 1, 0};
	// int a[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	// int a[12] = {1, 0, 0, 0, 0, -1, 0, 0, 0, 0};
	// int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	// int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	bubbleSort3(a, n);
	printf("%d\n", c);
	return 0;
}