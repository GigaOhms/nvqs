#include <stdio.h>
#include <stdlib.h>

void heo(char **p){
	(*p)[0] = '1';
	(*p)[1] = '2';
	(*p)[2] = '3';
}

int main(int argc, char const *argv[]){
	char *a;
	char *b;

	a = (char *)malloc(4 * sizeof(char));
	b = (char *)malloc(4 * sizeof(char));

	char **p = &a;
	heo(&b);

	(*p)[0] = '1';
	(*p)[1] = '2';
	(*p)[2] = '3';

	printf("%s\n", a);
	printf("%s\n", b);

	return 0;
}