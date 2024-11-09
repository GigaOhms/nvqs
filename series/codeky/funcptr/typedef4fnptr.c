/*
Chúng ta có thể sử dụng typedef để đơn giản hóa việc sử dụng 
con trỏ hàm (function pointer). Hãy tưởng tượng 
chúng ta có một số hàm, tất cả đều có cùng một chữ ký (signature), 
sử dụng đối số (argument) của chúng để in (print) 
ra một thứ gì đó theo những cách khác nhau:
*/

#include <stdio.h>

void print_to_n(int n) {
    for (int i = 1; i <= n; ++i)
        printf("%d\n", i);
}

void print_n(int n) {
    printf("%d\n", n);
}

// Ở đây chúng ta có thể sử dụng typedef để tạo 
// một kiểu con trỏ hàm được đặt tên là printer:

typedef void (*printer_t)(int); 

/*
Dòng này tạo ra một kiểu (type), có tên là 
print_t cho một con trỏ đến một hàm nhận một 
đối số int và không trả về gì, khớp với chữ ký của các 
hàm mà chúng ta có ở trên. Để sử dụng nó, 
chúng ta tạo một biến thuộc kiểu vừa tạo và gán 
cho nó một con trỏ cho một trong những hàm được đề cập:
*/

printer_t p = &print_to_n;
void (*p)(int) = &print_to_n; // This would be required without the type

// Sau đó, gọi hàm được trỏ đến bằng biến con trỏ hàm:

p(5);           // Prints 1 2 3 4 5 on separate lines
(*p)(5);        // So does this

/*
Do đó typedef cho phép một cú pháp đơn 
giản hơn khi xử lý các con trỏ hàm. 
Điều này dễ thấy hơn khi con trỏ hàm được 
sử dụng trong các tình huống phức tạp hơn,
chẳng hạn như đối số cho các hàm.

Nếu bạn đang sử dụng một hàm nhận một 
con trỏ hàm làm tham số (parameter), 
mà không có kiểu con trỏ hàm được define 
trước thì định nghĩa hàm sẽ là:
*/

void foo (void (*printer)(int), int y){
    //code
    printer(y);
    //code
}

// Tuy nhiên với typedef sẽ thành:

void foo (printer_t printer, int y){
    //code
    printer(y);
    //code
}

/*
Tương tự, các hàm có thể trả về con trỏ hàm 
và một lần nữa, việc sử dụng typedef có thể 
làm cho cú pháp đơn giản hơn khi làm như vậy.

Một ví dụ cổ điển là hàm signal trong <signal.h>. 
Khai báo của nó (theo tiêu chuẩn C) là:
*/

void (*signal(int sig, void (*func)(int)))(int);

/*
Đó là một hàm nhận hai đối số — một int và 
một con trỏ đến một hàm nhận int làm đối số và 
không trả về gì — và trả về một con trỏ đến hàm 
giống như đối số thứ hai của nó.

Nếu chúng ta define một kiểu SigCatcher làm bí danh 
cho con trỏ tới kiểu hàm:
*/

typedef void (*SigCatcher)(int);

// Chúng ta có thể khai báo signal() sử dụng:

SigCatcher signal(int sig, SigCatcher func);

/*
Nhìn chung, cách này dễ hiểu hơn (mặc dù tiêu chuẩn C 
không yêu cầu define một kiểu để thực hiện công việc). 
Hàm signal nhận hai đối số, một int và một SigCatcher, 
và trả về một SigCatcher — trong đó SigCatcher là 
một con trỏ đến một hàm nhận đối số int và không trả về gì.

Mặc dù việc sử dụng typedef đặt tên cho các kiểu con trỏ 
đến hàm giúp dễ đọc hơn. Nhưng nó cũng có thể gây bối rối 
cho người khác khi bảo trì code của bạn sau này, vì vậy hãy 
sử dụng cẩn thận và cung cấp tài liệu đầy đủ. Xem thêm Con trỏ hàm.
*/

