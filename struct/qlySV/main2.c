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
} Student;

int loadList(Student * stdLst);


#define TRUE	1
#define FALSE	0
#define NOT_EXIST (-1)
_Bool checkValidID(char id[]);
int checkIdExists(Student * stdLst, char newID[], int lenLst);
void addID(Student * stdLst, int index);
void addName(Student * stdLst, int index);
void addScore(Student * stdLst, int index);
void addStd(Student * stdLst, int * lenLstAdd, int index);
void printOut(Student * stdLst, int lenLst);

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


int main() {
	int lenLst;
	int selectFuntion;
	Student listStd[100];

	lenLst = loadList(listStd);

	printf("\n==========> MENU <===========\n");
	printf("1 - Add a student to the list\n");
	printf("2 - Update student information by ID\n");
	printf("3 - Score analysis\n");
	printf("4 - Delete student information by ID\n");
	printf("5 - Find information students\n");
	printf("6 - Sort student information by score\n");
	printf("7 - Show student list\n");
	printf("8 - Save list to list.txt\n");
	printf("0 - Exit\n");

	while (1) {
		printf("---------------------><----------------------\n");
		printf("\nSelect a function: ");
		scanf("%d", &selectFuntion);
		// printf("\n");

		switch (selectFuntion) {
		case 1:
			printf("Add a student to the list\n");
			addStd(listStd, &lenLst, lenLst);
			// Add(list, n);
			// n++;
			break;
		case 2:
			printf("Update student information by ID\n");
			updateInfoStd(listStd, &lenLst);
			// Update(list, n);
			break;
		case 3:
			printf("Score analysis!\n");
			statisStd(listStd, lenLst);
			// Rank(list, n);
			// Output(list, n);
			break;
		case 4:
			printf("Delete student information by ID\n");
			// char del[50];
			// printf("Enter ID to delete: ");
			// scanf("%s", del);
			// if (check_del(list, n, del)) {
				// Delete(list, n, del);
				// n--;
			// } else
				// printf("Student has been deleted\n");
			break;
		case 5:
			printf("Find information students\n");
			// Rank(list, n);
			// printf("  1 - Find by ID\n");
			// printf("  2 - Find by name\n");
			// printf("-- Select method: ");
			// scanf("%d", &search);
			// switch (search) {
			// case 1:
			// 	findByID(list, n);
			// 	break;
			// case 2:
			// 	findByName(list, n);
			// 	break;
			// }
			break;
		case 6:
			printf("Sort student information by score\n");
			// Sort(list, n);
			break;
		case 7:
			printf("Show student list\n");
			printOut(listStd, lenLst);
			// Rank(list, n);
			// Show(list, n);
			break;
		case 8:
			printf("Save list\n");
			// Rank(list, n);
			// writeFile(list, n);
			break;
		case 0:
			printf("Exit program !!\n");
			printf("Thank you for using !!\n");
			return 0;
		default:
			printf("This function is not available !\n");
			printf("Please select again.\n");
			break;
		}
	}
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

_Bool checkValidID(char id[]) {
	for (int i = 0; i < strlen(id); i++)
		if (id[i] < '0' || id[i] > '9')
			return FALSE;
	return TRUE;
}

int checkIdExists(Student * stdLst, char newID[], int lenLst) {
	for (int i = 0; i < lenLst; i++) {
		if (strcmp(stdLst[i].id, newID) == 0)
			return i;
	}
	return NOT_EXIST;
}

void addID(Student * stdLst, int index) {
	printf("ID student: ");
	scanf("%s", stdLst[index].id);
	while (checkValidID(stdLst[index].id) == FALSE) {
		printf("ID invalid!! Re-enter: ");
		scanf("%s", stdLst[index].id);
	}
	while (checkIdExists(stdLst, stdLst[index].id, index) != NOT_EXIST) {
		printf("ID already exists!! Re-enter: ");
		scanf("%s", stdLst[index].id);
	}
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
	addID(stdLst, index);
	addName(stdLst, index);
	addScore(stdLst, index);
	rankScore(stdLst, index);
	if ((*lenLstAdd) == index)
		(*lenLstAdd)++;
}

void printOut(Student * stdLst, int lenLst) {
	for (int i = 0; i < lenLst; i++) {
		printf("ID: %s", stdLst[i].id);
		printf("\tName: %s", stdLst[i].name);
		printf("\t\tMarks: %.2f", stdLst[i].score);
		printf("\tRank: %c\n", stdLst[i].rank);
	}
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

void updateInfoStd(Student * stdLst, int * lenLstAdd) {
	char newID[10];
	printf("ID student update: ");
	scanf("%s", newID);
	int idIndex = checkIdExists(stdLst, newID, *lenLstAdd);

	if (idIndex == NOT_EXIST ) 
		printf("ID does not exist!\n");
	else 
		addStd(stdLst, lenLstAdd, idIndex);
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
	printf("Total studens: %d\n", lenLst);
	printf("Highest score: %.2f\n", ratioLst[MAX_SCORE_INDEX]);
	printf("Lowest score:  %.2f\n", ratioLst[MIN_SCORE_INDEX]);
	printf("Student level A: %.1f %%\n", ratioLst[RATIO_A_INDEX]);
	printf("Student level B: %.1f %%\n", ratioLst[RATIO_B_INDEX]);
	printf("Student level C: %.1f %%\n", ratioLst[RATIO_C_INDEX]);
	printf("Student level D: %.1f %%\n", ratioLst[RATIO_D_INDEX]);
}


// ấm đun siêu tốc sharp
// Bộ ấm trà Minh Long
// khay Inox
// Ly Thủy tinh có quai
// Ly Thủy tinh không quai
// Bình thủy
// Bình thủy điện
// Bộ lau nhà
