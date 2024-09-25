#include <stdio.h>

void a0(void);
void b0(void);
void c0(void);
void fun(int a);
void (*fun_ptr)(void);

int a = 0;
int b = 0;
int c = 0;

int main() {
	//  void (*fun_ptr)(int);
	// fun_ptr = &fun;
	// (*fun_ptr)(10);

	fun_ptr = &a0;
	for (int i = 0; i < 10; i++)
		(*fun_ptr)();

	printf("%d %d %d\n", a, b, c);
	return 0;
}

void fun(int a) {
	printf("Value of a is %d\n", a);
}

void a0(void) {
	a++;
	fun_ptr = &b0;
}

void b0(void) {
	b++;
	fun_ptr = &c0;
}

void c0(void) {
	c++;
	fun_ptr = &a0;
}