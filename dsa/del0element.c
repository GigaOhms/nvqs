// --------------- Xoa phan tu 0 ----------------
#include <stdio.h>

#define M 100

int main(){
    int n, a[M];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int j = 0;
    for (int i = 0; i < n; i++){
        while (a[j] == 0){
            j++;
            n--;
        }
        a[i] = a[j];
        j++;
    }
    show(a, n);
    return 0;
}