#include<stdio.h>
#include<string.h>

void addZero(char s[], int num){
    int n = strlen(s);
    for (int i = n - 1; i >= 0; i--)
        s[i + num] = s[i];
    for (int i = 0; i < num; i++)
        s[i] = '0';
    s[n + num] = '\0';
}

int main(){
    int n, k;
    char s1[100011];
    char s2[100011];

    scanf("%s", s1);
    scanf("%s", s2);

    int lens1 = strlen(s1);
    int lens2 = strlen(s2);

    if (lens1 > lens2){
        int khong = lens1 - lens2;
        addZero(s2, khong);
    } else {
        int khong = lens2 - lens1;
        addZero(s1, khong);
    }

    int nho = 0, kq = 0, k = 0;

    char result[1000000] = "";

    for (int i = strlen(s1) - 1; i >= 0; i--){
        kq = (s1[i] - 48) + (s2[i] - 48) + nho;
        nho = kq / 10;
        result[k] = (kq % 10) + 48;
        k++;
    }
    if (nho != 0){
        result[k] = nho + 48;
    	result[k + 1] = 0;
    } else result[k] = 0;
    for (int i = strlen(result) - 1; i >= 0; i--)
        printf("%c", result[i]);
    return 0;
}