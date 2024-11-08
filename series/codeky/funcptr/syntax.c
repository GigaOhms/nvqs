// Như các bạn đã biết
// Pointer có thể trỏ đến bất kì vùng nhớ nào
// Kể cả code trong vùng code segment
// Nếu pointer trỏ đến đoạn code của một function
// --> Thì chúng ta có một function pointer

// function pointer is a pointer that points to a function...
// Vì function nằm ở code segment...
// là vùng nhớ read-only khi thực thi...
// nên funcptr là một pointer to const.

void    (*funcPtr)(int);
//        |        
// Là tên của function pointer...
// function pointer cũng chỉ là một biến pointer.

// funcPtr là một pointer trỏ đến một function...
// mà nhận input argument kiểu int...
// và trả về giá trị kiểu void.


void    *(*(*fp1)(int))[16];
// fp1 is a pointer that points to a function
// that take an int argument
// and return a pointer to an array of 10 pointers
// that point to void


float   (*(*fp2)(int, int))(int);   //
double  (*(*(*fp3)())[10])();       //
int     (*(*fp4())[10])();          //
                                    //        
                                    //    
// fp2 là con trỏ hàm trỏ tới ----- //      
// hàm có 2 đối số kiểu int,...
// có kiểu trả về là con trỏ hàm,...
// hàm đó có 1 đối số là int,...
// kiểu trả về là float.


// KẾT HỢP FUNCTION POINTER VÀ TYPEDEF

#include <stdio.h>
typedef int (*SQRT)(int);
static int square(int x) {
    return x * x ;
}
int main() {
    SQRT sqrt = square;
    printf("square of 5 is %d\n", sqrt(5));
}

// Giờ chúng ta có thể sử dụng sqrt...
// như là một alias của function square.

// với function pointer chúng ta có thể...
// dynamically call function at run-time.

// chúng ta có thể biến một data struct thành object-like struct...
// giúp code C cũng có thể sử dụng polymorphism.

// viết asynchronous programing với callback function