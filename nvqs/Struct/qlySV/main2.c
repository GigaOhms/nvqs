#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void flush(int c) {
	while ((c = getchar()) != '\n' && c != EOF) {}
}
int c;

typedef struct Student {
	char name[50];
	float score;
	char id[50];
	char rank;
};