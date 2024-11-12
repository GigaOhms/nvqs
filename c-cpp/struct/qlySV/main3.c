#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int c;
void flush(int c) {
	while ((c = getchar()) != '\n' && c != EOF) {}
}

typedef struct Student {
	char name[50];
	float score;
	char id[10];
	char rank;
} Student;

int loadList(Student * stdLst);
void saveList(Student * stdLst, int lenLst);


#define TRUE		1
#define FALSE		0
#define NOT_EXIST 	(-1)
#define MAX_ID_LEN 	8
_Bool checkValidID(char id[]);
int checkIdExists(Student * stdLst, char newID[], int lenLst);
void addID(Student * stdLst, int lenLst, int index);
void addName(Student * stdLst, int index);
void addScore(Student * stdLst, int index);
void addStd(Student * stdLst, int * lenLstAdd, int index);
void printLstStd(Student * stdLst, int lenLst);

void updateInfoStd(Student * stdLst, int * lenLstAdd);

#define MIN_SCORE_INDEX 0
#define MAX_SCORE_INDEX 1
#define RATIO_A_INDEX 	2
#define RATIO_B_INDEX 	3
#define RATIO_C_INDEX 	4
#define RATIO_D_INDEX 	5
void rankScore(Student * stdLst, int index);
void statisScore(Student * stdLst, float * ratioLst, int lenLst);
void statisStd(Student * stdLst, int lenLst);

void clearStd(Student * stdLst, int *lenLstAdd, int index);
void delStd(Student * stdLst, int * lenLstAdd);

#define FIND_ID		1
#define FIND_NAME	2
int checkNameExists(Student * stdLst, char newID[], int lenLst);
void findStdByName(Student * stdLst, int lenLst);
void findStd(Student * stdLst, int lenLst);

void swapStd(Student * std1, Student * std2);
void sortByScore(Student * stdLst, int lenLst);

void addStudent(Student * stdLst, int * lenLstAdd);
void updateInfo(Student * stdLst, int * lenLstAdd);
void scoreAnalysis(Student * stdLst, int * lenLstAdd);
void deleteStudent(Student * stdLst, int * lenLstAdd);
void findStudent(Student * stdLst, int * lenLstAdd);
void sortStudent(Student * stdLst, int * lenLstAdd);
void printStudent(Student * stdLst, int * lenLstAdd);
void writeFile(Student * stdLst, int * lenLstAdd);
typedef void (*makeSelect)();

int main() {
	int lenList;
	int selectFuntion;
	Student listStudent[100];

	lenList = loadList(listStudent);

	while (1) {
		printf("\n---------------------> MENU <----------------\n");
		printf("1 - Add a student to the list\n");
		printf("2 - Update student information by ID\n");
		printf("3 - Score analysis\n");
		printf("4 - Delete student information by ID\n");
		printf("5 - Find information students\n");
		printf("6 - Sort student information by score\n");
		printf("7 - Show student list\n");
		printf("8 - Save list to list.txt\n");
		printf("0 - Exit\n");
		printf("---------------------><----------------------\n");
		printf("\nSelect a function: ");
		scanf("%d", &selectFuntion);

		switch (selectFuntion) {
		case 1:
			addStdToLst(listStudent, &lenList);
			break;
		case 2:
			updateInfo(listStudent, &lenList);
			break;
		case 3:
			scoreAnalysis(listStudent, &lenList);
			break;
		case 4:
			deleteStudent(listStudent, &lenList);
			break;
		case 5:
			findStudent(listStudent, &lenList);
			break;
		case 6:
			sortStudent(listStudent, &lenList);
			break;
		case 7:
			printStudent(listStudent, &lenList);
			break;
		case 8:
			writeFile(listStudent, &lenList);
			break;
		case 0:
			printf("Exit program !!\n");
			printf("Thank you for using !!\n");
			return 0;
		default:
			printf("This function is not available !!\n");
			printf("Please select again.\n");
			break;
		}
	}
}

void addStudent(Student * stdLst, int * lenLstAdd) {
	printf("Add a student to the list\n");
	addStd(stdLst, lenLstAdd, *lenLstAdd);
}

void updateInfo(Student * stdLst, int * lenLstAdd) {
	printf("Update student information by ID\n");
	updateInfoStd(stdLst, lenLstAdd);
}

void scoreAnalysis(Student * stdLst, int * lenLstAdd) {
	printf("Score analysis!\n");
	statisStd(stdLst, *lenLstAdd);
}

void deleteStudent(Student * stdLst, int * lenLstAdd) {
	printf("Delete student information by ID\n");
	delStd(stdLst, lenLstAdd);
}

void findStudent(Student * stdLst, int * lenLstAdd) {
	printf("Find information students\n");
	findStd(stdLst, *lenLstAdd);
}

void sortStudent(Student * stdLst, int * lenLstAdd) {
	printf("Sort student information by score\n");
	sortByScore(stdLst, *lenLstAdd);
}

void printStudent(Student * stdLst, int * lenLstAdd) {
	printf("Show student list\n");
	printLstStd(stdLst, *lenLstAdd);
}

void writeFile(Student * stdLst, int * lenLstAdd) {
	printf("Save list\n");
	saveList(stdLst, *lenLstAdd);
}

int loadList(Student * stdLst) {
	FILE *f;
	int lastStdNum = 0;
	f = fopen("list.txt", "r");
	if (f == NULL)
		fclose(f);
	else {
		while (fscanf(
				f,
				"ID: %s\t\tName: %100[^\t]\t\tMarks: %f\tRank: %c\n",
				stdLst[lastStdNum].id,
				stdLst[lastStdNum].name,
				&stdLst[lastStdNum].score,
				&stdLst[lastStdNum].rank) != EOF)
			lastStdNum++;
		fclose(f);
	}
	return lastStdNum;
}

void saveList(Student * stdLst, int lenLst) {
	FILE *f;
	f = fopen("list2.txt", "w");
	for (int i = 0; i < lenLst; i++) {
		fprintf(f, "ID: %s", stdLst[i].id);
		fprintf(f, "\t\tName: %s", stdLst[i].name);
		fprintf(f, "\t\tMarks: %.1f", stdLst[i].score);
		fprintf(f, "\tRank: %c\n", stdLst[i].rank);
	}
	fclose(f);
	printf("The list has been saved to the file list2.txt\n");
}

_Bool checkValidID(char id[]) {
	for (int i = 0; i < strlen(id); i++)
		if (id[i] < '0' || id[i] > '9')
			return FALSE;
	return TRUE;
}

int checkIdExists(Student * stdLst, char newID[], int lenLst) {
	for (int indexIdExist = 0; indexIdExist < lenLst; indexIdExist++) {
		if (strncmp(stdLst[indexIdExist].id, newID, MAX_ID_LEN) == 0) {
			return indexIdExist;
		}
	}
	return NOT_EXIST;
}

void addID(Student * stdLst, int lenLst, int index) {
	char newID[10];
	printf("ID student: ");
	scanf("%s", newID);
	while (checkValidID(newID) == FALSE) {
		printf("ID invalid!! Re-enter: ");
		scanf("%s", newID);
	}
	while (checkIdExists(stdLst, newID, lenLst) != NOT_EXIST) {
		printf("ID already exists!! Re-enter: ");
		scanf("%s", newID);
	}
	strcpy(stdLst[index].id, newID);
}

void addName(Student * stdLst, int index) {
	flush(c);
	printf("Name student: ");
	fgets(stdLst[index].name, 50, stdin);
	stdLst[index].name[strlen(stdLst[index].name) - 1] = '\0';
}

void addScore(Student * stdLst, int index) {
	printf("Score: ");
	scanf("%f", &stdLst[index].score);
	while (stdLst[index].score < 0.0 || stdLst[index].score > 10.0) {
		printf("Score invalid!! Re-enter: ");
		scanf("%f", &stdLst[index].score);
	}
}

void addStd(Student * stdLst, int * lenLstAdd, int index) {
	addID(stdLst, (*lenLstAdd), index);
	addName(stdLst, index);
	addScore(stdLst, index);
	rankScore(stdLst, index);
	if ((*lenLstAdd) == index)
		(*lenLstAdd)++;
}

void printStd(Student * stdLst, int index) {
	printf("ID: %s", stdLst[index].id);
	printf("\tName: %s", stdLst[index].name);
	printf("\t\tMarks: %.2f", stdLst[index].score);
	printf("\tRank: %c\n", stdLst[index].rank);
}

void printLstStd(Student * stdLst, int lenLst) {
	for (int index = 0; index < lenLst; index++) 
		printStd(stdLst, index);
}

void rankScore(Student * stdLst, int index) {
	if (stdLst[index].score >= 8.5)
		stdLst[index].rank = 'A';
	else if (stdLst[index].score >= 6.5)
		stdLst[index].rank = 'B';
	else if (stdLst[index].score >= 5.0)
		stdLst[index].rank = 'C';
	else
		stdLst[index].rank = 'D';
}

void resetStd(Student * stdLst, int index) {
	stdLst[index].id[0] = '\0';
	stdLst[index].name[0] = '\0';
	stdLst[index].score = 0;
}


void updateInfoStd(Student * stdLst, int * lenLstAdd) {
	char newID[10];
	printf("ID student update: ");
	scanf("%s", newID);
	int idIndex = checkIdExists(stdLst, newID, *lenLstAdd);

	if (idIndex == NOT_EXIST ) 
		printf("ID does not exist!\n");
	else {
		resetStd(stdLst, idIndex);
		addStd(stdLst, lenLstAdd, idIndex);
	}
}


void statisScore(Student * stdLst, float * ratioLst, int lenLst) {
	float ratioA = 0.0, ratioB = 0.0, ratioC = 0.0, ratioD = 0.0;

	ratioLst[MIN_SCORE_INDEX] = stdLst[0].score;
	ratioLst[MAX_SCORE_INDEX] = stdLst[0].score;

	for (int i = 0; i < lenLst; i++) {
		if (ratioLst[MIN_SCORE_INDEX] > stdLst[i].score) 
			ratioLst[MIN_SCORE_INDEX] = stdLst[i].score;
		if (ratioLst[MAX_SCORE_INDEX] < stdLst[i].score) 
			ratioLst[MIN_SCORE_INDEX] = stdLst[i].score;

		if (stdLst[i].rank == 'A')
			ratioA = ratioA + 1.0;
		else if (stdLst[i].rank == 'B')
			ratioB = ratioB + 1.0;
		else if (stdLst[i].rank == 'C')
			ratioC = ratioC + 1.0;
		else if (stdLst[i].rank == 'D')
			ratioD = ratioD + 1.0;
	}

	ratioLst[RATIO_A_INDEX] = ratioA / (float)lenLst * 100.0;
	ratioLst[RATIO_B_INDEX] = ratioB / (float)lenLst * 100.0;
	ratioLst[RATIO_C_INDEX] = ratioC / (float)lenLst * 100.0;
	ratioLst[RATIO_D_INDEX] = ratioD / (float)lenLst * 100.0;
}

void statisStd(Student * stdLst, int lenLst) {
	float ratioLst[6];
	statisScore(stdLst, ratioLst, lenLst);
	printf("Total students: %d\n", lenLst);
	printf("Highest score: %.2f\n", ratioLst[MAX_SCORE_INDEX]);
	printf("Lowest score:  %.2f\n", ratioLst[MIN_SCORE_INDEX]);
	printf("Student level A: %.1f %%\n", ratioLst[RATIO_A_INDEX]);
	printf("Student level B: %.1f %%\n", ratioLst[RATIO_B_INDEX]);
	printf("Student level C: %.1f %%\n", ratioLst[RATIO_C_INDEX]);
	printf("Student level D: %.1f %%\n", ratioLst[RATIO_D_INDEX]);
}

void clearStd(Student * stdLst, int *lenLstAdd, int index) {
	for (int i = index; i < (*lenLstAdd) - 1; i++) {
		strcpy(stdLst[i].id, stdLst[i + 1].id);
		strcpy(stdLst[i].name, stdLst[i + 1].name);
		stdLst[i].score = stdLst[i + 1].score;
		stdLst[i].rank = stdLst[i + 1].rank;
	}
	(*lenLstAdd)--;
	printf("Student has been deleted!\n");
}

void delStd(Student * stdLst, int * lenLstAdd) {
	char newID[10];
	printf("ID student to delete: ");
	scanf("%s", newID);
	int idIndex = checkIdExists(stdLst, newID, *lenLstAdd);
	if (idIndex == NOT_EXIST ) 
		printf("ID does not exist!\n");
	else clearStd(stdLst, lenLstAdd, idIndex);
}

void findStdByID(Student * stdLst, int lenLst) {
	char findID[10];
	printf("ID student: ");
	scanf("%s", findID);
	int indexID = checkIdExists(stdLst, findID, lenLst);
	if (indexID == NOT_EXIST) 
		printf("ID does not exist!\n");
	else printStd(stdLst, indexID); 
}

int checkNameExists(Student * stdLst, char newID[], int lenLst) {
	int len = strlen(newID) - 1;
	printf("len = %d\n", len);
	for (int indexName = 0; indexName < len; indexName++)
		if (strncmp(stdLst[indexName].name, newID, len) == 0) 
			return indexName;
	return NOT_EXIST;
}

void findStdByName(Student * stdLst, int lenLst) {
	char findName[50];
	flush(c);
	printf("Name student: ");
	fgets(findName, 50, stdin);
	int indexStd = checkNameExists(stdLst, findName, lenLst);
	if (indexStd == NOT_EXIST) 
		printf("Name does not exist!\n");
	else printStd(stdLst, indexStd); 
}

void findStd(Student * stdLst, int lenLst) {
	int mode;
	printf("Find mode (1 = ID, 2 = NAME): ");
	scanf("%d", &mode);
	if (mode == FIND_ID) 
		findStdByID(stdLst, lenLst);
	else if (mode == FIND_NAME) 
		findStdByName(stdLst, lenLst);
	else printf("Mode not available!!");
}

void swapStd(Student * std1, Student * std2) {
	Student temp = *std1;
	*std1 = *std2;
	*std2 = temp;
}

void sortByScore(Student * stdLst, int lenLst) {
	for (int i = 0; i < lenLst - 1; i++)
		for (int j = i + 1; j < lenLst; j++) 
			if (stdLst[i].score < stdLst[j].score)
				swapStd(&stdLst[i], &stdLst[j]);
	printf("The list is sorted. !!\n");
}

