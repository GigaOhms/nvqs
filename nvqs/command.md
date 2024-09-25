gcc -E main.c -o main.i	\\ xử lý tiền xử lý trung gian
gcc -S main.i -o main.s	\\ biên dịch sang file ASM
gcc -c main.s -o main.o \\ Assembler, tạo ra file object (.o / .obj)
gcc -o main main.s		\\ biên dịch file thực thi từ object
gcc -o main main.c		\\ biên dịch file thực thi main
gcc -o -g main main.c	\\ biên dịch và cho phép chạy debug


