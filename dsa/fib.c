#include <stdio.h>

int fib(int n) {
	if (n <= 1) 
		return n;
	return fib(n - 1) + fib(n - 2);
}

int main() {
	int n;
	if (scanf("%d", &n) == 1);
	int arr[100];
	
	for (int i = 0; i < n; i++)
		printf("%d ", fib(arr[i]));
	printf("\n");
	return 0;
}