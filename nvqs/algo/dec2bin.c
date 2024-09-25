#include <stdio.h>

// t <= 10^5
// n <= 10^18

void dec2bin(int n) {
	char s[65];
	s[64] = 0;
	int l = 63;
	while (n) {
		s[l--] = n % 2 + '0';
		n /= 2;
	}
	printf("%s\n", s + l + 1);
}

int main(){
	int n;
	scanf("%d", &n);
	dec2bin(n);
}