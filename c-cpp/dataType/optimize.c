#include <stdio.h>
int main() {
	unsigned char a[20];	// max is 255, 256 is 0, 257 is 1
	for (int i = 0; i < 5; i++){
		a[i] = i + 254;
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}