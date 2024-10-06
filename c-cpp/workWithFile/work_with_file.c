#include <stdio.h>

int main(){
    int ab, a, b;
    char c[100];
    FILE *f;
    f = fopen("test.txt", "r");
    // for (a = 27; a < 100; a++){
    //     fprintf(f,"%d - %d\t", 2001, 2002);
    //     fprintf(f,"%s\n", "ho cong trinh");
    // }
    fscanf(f, "%s", c);
    fclose(f);
    printf("%s", c);
    return 0;
}

int main(){
    int n = 0;
    char a[1000][1000];
    FILE *f;
    f = fopen("key.txt", "r");
	if (f == NULL)
		fclose(f);
	else {
		while (fscanf(f, "%[^\n] ", a[n]) != EOF)
            n++;
		fclose(f);
	}
    for (int i = 0; i < n; i++){
        printf("%s\n", a[i]);
        Sleep(200);
    }
     
    return 0;
}
