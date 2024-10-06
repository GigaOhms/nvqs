#include <stdio.h>
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
} Student;

void outList(Student * stdLst, int lastStd) {
    printf("%s, %s, %.2f, %c\n", 
        stdLst[lastStd].id,
        stdLst[lastStd].name,
        stdLst[lastStd].score,
        stdLst[lastStd].rank);
    return;
}

void editList(Student * stdLst, int lastStd) {
        strcpy(stdLst[lastStd].id, "19502231");
        strcpy(stdLst[lastStd].name, "GigaOhms");
        stdLst[lastStd].score = 8.9;
        stdLst[lastStd].rank = 'A';
    return;
}

int main() {
	int n = 0;
	Student stdList[10];
    strcpy(stdList[1].id, "19502525");
    strcpy(stdList[1].name, "BCH BDBP");
    stdList[1].score = 4.5;
    stdList[1].rank = 'C';

    outList(stdList, 1);
    editList(stdList, 1);
    outList(stdList, 1);

    return 0;
}