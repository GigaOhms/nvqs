#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)                                                   \
	(byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'),                      \
		(byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'),                  \
		(byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'),                  \
		(byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')
// & data voi 0x1 == 0b1, 0x2 == 0b10, 0x3 == 0b100 ....

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

void printBits(size_t const size, void const *const ptr) {
	// Size is number of bit (1 is 8, 2 is 16);
	unsigned char *b = (unsigned char *)ptr;
	unsigned char byte;
	int i, j;
	for (i = size - 1; i >= 0; i--) {
		for (j = 7; j >= 0; j--) {
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("\n");
}

int main() {
	int bin = 0b111111111111;
	int dec = 4095;
	int hex = 0xFFF;
	int oct = 07777;
	printf("%x = %d\n", hex, hex);
	printf("%o = %d\n", oct, oct);
	printBits(2, &dec);
	dec2bin(0xfff);
	printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(100));
	return 0;
}