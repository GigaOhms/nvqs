#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void flush(int c) {
	while ((c = getchar()) != '\n' && c != EOF) {}
}
int c;

struct Student {
	char name[50];
	float score;
	char id[50];
	char rank;
};

int Check(char id[]) {
	int i;
	for (i = 0; i < strlen(id); i++)
		if (id[i] < '0' || id[i] > '9')
			return 1;
	return 0;
}

void Add(struct Student list[], int n) {
	printf("Nhap ID sinh vien: ");
	scanf("%s", list[n].id);
	while (Check(list[n].id)) {
		printf("ID khong hop le!\n");
		printf("Nhap lai ID sinh vien: ");
		scanf("%s", list[n].id);
	}
	flush(c);
	printf("Nhap ten sinh vien: ");
	fgets(list[n].name, 100, stdin);
	list[n].name[strlen(list[n].name) - 1] = '\0';
	printf("Nhap diem: ");
	scanf("%f", &list[n].score);
	while (list[n].score < 0 || list[n].score > 10) {
		printf("khong hop le!\n");
		printf("Nhap lai diem: ");
		scanf("%f", &list[n].score);
	}
}

void Update(struct Student list[], int n) {
	int i, chk = 1;
	char cn[50];
	printf("Nhap ID can cap nhat: ");
	scanf("%s", cn);

	for (i = 0; i < n; i++) {
		if (strcmp(list[i].id, cn) == 0) {
			flush(c);
			printf("Cap nhat ten: ");
			fgets(list[i].name, 100, stdin);
			list[i].name[strlen(list[i].name) - 1] = '\0';
			printf("Cap nhat diem: ");
			scanf("%f", &list[i].score);
			chk = 0;
			break;
		}
	}
	if (chk)
		printf("Khong tim thay ID tuong ung de cap nhat!\n");
}

// xep loai sinh vien (A, B, C, D)
void Rank(struct Student list[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		float score = list[i].score;
		if (score >= 8.5)
			list[i].rank = 'A';
		else if (score >= 6.5)
			list[i].rank = 'B';
		else if (score >= 5.0)
			list[i].rank = 'C';
		else
			list[i].rank = 'D';
	}
}

void Output(struct Student list[], int n) {
	// Tim diem cao nhat va diem thap nhat
	int i;
	float min = 10, max = 0;
	for (i = 0; i < n; i++) {
		if (max < list[i].score)
			max = list[i].score;
		if (min > list[i].score)
			min = list[i].score;
	}
	// Tinh ti le % sinh vien dat diem A, B, C, D
	int A = 0, B = 0, C = 0, D = 0;
	for (i = 0; i < n; i++) {
		if (list[i].rank == 'A')
			A++;
		else if (list[i].rank == 'B')
			B++;
		else if (list[i].rank == 'C')
			C++;
		else
			D++;
	}
	float Ap, Bp, Cp, Dp;
	Ap = ((float)A / (float)n) * 100;
	Bp = ((float)B / (float)n) * 100;
	Cp = ((float)C / (float)n) * 100;
	Dp = ((float)D / (float)n) * 100;

	// In ra ket qua
	printf("\t-- So luong sinh vien: %d\n", n);
	printf("\t\tDiem so cao nhat: %.2f\n", max);
	printf("\t\tDiem so thap nhat: %.2f\n", min);
	printf("\t\tTi le xep loai:\n");
	printf("\t\t\tA: %.2f %%\n", Ap);
	printf("\t\t\tB: %.2f %%\n", Bp);
	printf("\t\t\tC: %.2f %%\n", Cp);
	printf("\t\t\tD: %.2f %%\n", Dp);
}

int check_del(struct Student list[], int n, char del[]) {
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(list[i].id, del) == 0)
			return 1;
	return 0;
}
// xoa thong tin sinh vien theo ID
void Delete(struct Student list[], int *n) {
	char del[50];
	printf("Nhap ID can xoa: ");
	scanf("%s", del);
	int i, j;
	for (i = 0; i < *n; i++) {
		if (strcmp(list[i].id, del) == 0) {
			for (j = i; j < *n - 1; j++)
				list[j] = list[j + 1];
			*n--;
			break;
		}
	}
	printf("Sinh vien da duoc xoa!\n");
}

void findByID(struct Student list[], int n) {
	int i;
	char fid[50];
	printf("Nhap ID sinh vien can tim: ");
	scanf("%s", fid);
	for (i = 0; i < n; i++) {
		if (strcmp(fid, list[i].id) == 0) {
			printf("ID: %s", list[i].id);
			printf("\t\tName: %s", list[i].name);
			printf("\t\tMarks: %.2f", list[i].score);
			printf("\tRank: %c\n", list[i].rank);
			fid[0] = '-';
		}
	}
	if (fid[0] != '-')
		printf("Khong co sinh vien phu hop!\n");
}

void findByName(struct Student list[], int n) {
	int i;
	char fid[100];
	printf("Nhap ten sinh vien can tim: ");
	fflush(stdin);
	fgets(fid, 100, stdin);
	for (i = 0; i < n; i++) {
		if (strcmp(list[i].name, fid) == 0) {
			printf("ID: %s", list[i].id);
			printf("\t\tName: %s", list[i].name);
			printf("\t\tMarks: %.2f", list[i].score);
			printf("\tRank: %c\n", list[i].rank);
			fid[0] = '-';
		}
	}
	if (fid[0] != '-')
		printf("Khong co sinh vien phu hop!\n");
}

void Sort(struct Student list[], int n) {
	int i, j;
	struct Student temp;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (list[i].score < list[j].score) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
	printf("Danh sach da duoc sap xep!\n");
}

void Show(struct Student list[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("ID: %s", list[i].id);
		printf("\tName: %s", list[i].name);
		printf("\t\tMarks: %.2f", list[i].score);
		printf("\tRank: %c\n", list[i].rank);
	}
}

void writeFile(struct Student list[], int n) {
	FILE *f;
	int i;
	f = fopen("danhsach.txt", "w");
	for (i = 0; i < n; i++) {
		fprintf(f, "ID: %s", list[i].id);
		fprintf(f, "\t\tName: %s", list[i].name);
		fprintf(f, "\t\tMarks: %.1f", list[i].score);
		fprintf(f, "\tRank: %c\n", list[i].rank);
	}
	fclose(f);
	printf("Danh sach da duoc ghi vao file danhsach.txt\n");
}

int main() {
	int n = 0, search;
	int cae;
	struct Student list[10000];

	FILE *f;
	int i;
	f = fopen("danhsach.txt", "r");
	if (f == NULL)
		fclose(f);
	else {
		while (fscanf(
				   f,
				   "ID: %s\t\tName: %100[^\t]\t\tMarks: %f\tRank: %c\n",
				   list[n].id,
				   list[n].name,
				   &list[n].score,
				   &list[n].rank) != EOF)
			n++;
		fclose(f);
	}

	printf("\n==========> MENU <===========\n");
	printf("1 - them 1 sinh vien\n");
	printf("2 - cap nhat thong tin boi ID\n");
	printf("3 - In ra thong tin so luong sinh vien va thong ke\n");
	printf("4 - Xoa ID va thong tin sinh vien\n");
	printf("5 - Tim kiem sinh vien\n");
	printf("6 - Sap xep sinh vien tu cao den thap\n");
	printf("7 - Hien thi danh sach sinh vien\n");
	printf("8 - Ghi danh sach vao file danhsach.txt\n");
	printf("0 - Thoat\n");

	while (1) {
		printf("---------------------><----------------------\n");
		printf("\nChon mot hanh dong: ");
		scanf("%d", &cae);
		printf("\n");

		switch (cae) {
		case 1:
			printf("Ban da chon hanh dong 1!\n");
			Add(list, n);
			n++;
			break;
		case 2:
			printf("Ban da chon hanh dong 2!\n");
			Update(list, n);
			break;
		case 3:
			printf("Ban da chon hanh dong 3!\n");
			Rank(list, n);
			Output(list, n);
			break;
		case 4:
			printf("Ban da chon hanh dong 4!\n");
			Delete(list, &n);
			break;
		case 5:
			printf("Ban da chon hanh dong 5!\n");
			Rank(list, n);
			printf("  1 - Tim theo ID\n");
			printf("  2 - Tim theo ten\n");
			printf("-- Chon phuong phap tim kiem: ");
			scanf("%d", &search);
			switch (search) {
				case 1:
					findByID(list, n);
					break;
				case 2:
					findByName(list, n);
					break;
				}
			break;
		case 6:
			printf("Ban da chon hanh dong 6!\n");
			Sort(list, n);
			break;
		case 7:
			printf("Ban da chon hanh dong 7!\n");
			Rank(list, n);
			Show(list, n);
			break;
		case 8:
			printf("Ban da chon hanh dong 8!\n");
			Rank(list, n);
			writeFile(list, n);
			break;
		case 0:
			printf("Ban da chon thoat chuong trinh!\n");
			printf("Cam on ban da su dung chuong trinh!\n");
			return 0;
		default:
			printf("Khong co chuc nang nay!\n");
			printf("Hay chon chuc nang trong hop menu.\n");
			break;
		}
	}
}
