#include <stdio.h>
#include <stdlib.h>

void PrintTwoNumbers(int (*numberSource)(void)) {
    printf("%d and %d\n", numberSource(), numberSource());
}

/* Hàm callback */
int overNineThousand(void) {
    return (rand() % 1000) + 9001;
}

/* Hàm callback. */
int meaningOfLife(void) {
    return 42;
}

int main(void) {
    PrintTwoNumbers(&rand);
// Kết quả có thể là “125185 and 8914334”.
// Hàm rand() được dùng làm tham số, điều này tương đương với
// “printf("%d and %d\n", rand(), rand());” trong hàm PrintTwoNumbers

    PrintTwoNumbers(&overNineThousand);
// Kết quả có thể là “9084 and 9441”.
// Hàm overNineThousand được dùng làm tham số, điều này tương đương với
// “printf("%d and %d\n", overNineThousand (), overNineThousand ());” trong hàm PrintTwoNumbers

    PrintTwoNumbers(&meaningOfLife);
// Kết quả là “42 and 42”.
// Hàm meaningOfLife được dùng làm tham số, điều này tương đương với
// “printf("%d and %d\n", meaningOfLife (), meaningOfLife ());” trong hàm PrintTwoNumbers

    return 0;
}
