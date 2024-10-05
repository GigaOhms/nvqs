#include <stdio.h>

int main() {
	char a = 125;
	_Bool c = 1000;
	char _buffer[20];
	float acs = 155550.6666;
	sprintf(_buffer, "%02u.%02u A ", (int)acs, (int)(acs * 100) % 100);
	printf("%u %s\n", a - 25, _buffer);
	return 0;
}