#include <stdio.h>
#include <stdlib.h>

/*
    Nhập phần tử vào mảng
    In ra tất cả các số & số lần xuất hiện của số đó
    VD: int arr[7] = {1,4,6,4,4,6,1}
    1 xuat hien 2 lan
    4 xuat hien 3 lan
    6 xuat hien 2 lan
*/
/*
    pptr = &arr;
    *pptr = &element;
    **pptr = element;
*/
void nhapMang(int *length, int **pptr)
{
    do
    {
        printf("Nhap so phan tu: ");
        scanf("%d", length);
    } while (*length < 1);
    *pptr = (int *)malloc(*length * sizeof(int));
    for (int i = 0; i < *length; i++)
    {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", (*pptr + i));
    }
}

void xuatMang(int length, int arr[])
{
    printf("Mang la: ");
    for (int i = 0; i < length; i++)
    {
        printf("\t%d", arr[i]);
    }
}
// Hàm chèn phần tử vào mảng mẫu
void increaseElement(int length, int arr[], int val)
{
    for (int i = length; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = val;
}

void printNumber(int length, int arr[])
{
    int *exp = (int *)malloc(length * sizeof(int));
    int change = 0;
    int ct = 0;
    // Tìm các gía trị có trong mảng & tạo ra mảng lưu giá trị đó
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (arr[i] == *(exp + j))
            {
                change = 0;
                break;
            }
            else
            {
                change = 1;
            }
        }
        if (change)
        {
            increaseElement(length, exp, arr[i]);
            change = 0;
            ct++;
        }
    }
    int length_new = (length - (length - ct));
    exp = (int *)realloc(exp, sizeof(int) * length_new);
    ct = 0;
    //Đếm số lần xuất hiện của giá trị trong mảng
    for (int i = 0; i < length_new; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (*(exp + i) == arr[j])
            {
                ct++;
            }
        }
        if (ct > 0)
            printf("\n%d xuat hien %d lan", *(exp + i), ct);
        ct = 0;
    }
    free(exp);
}

int main(int argc, char const *argv[])
{
    int *arr;
    int length;
    nhapMang(&length, &arr);
    xuatMang(length, arr);
    printNumber(length, arr);
    return 0;
}