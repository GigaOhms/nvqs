gcc -E main.c -o main.i	\\ xử lý tiền xử lý trung gian
gcc -S main.i -o main.s	\\ biên dịch sang file ASM
gcc -c main.s -o main.o \\ Assembler, tạo ra file object (.o / .obj)
gcc -o main main.s		\\ biên dịch file thực thi từ object
gcc -o main main.c		\\ biên dịch file thực thi main
gcc -o -g main main.c	\\ biên dịch và cho phép chạy debug
gcc -o main main.c -lm  \\ biên dịch chương trình sử dụng hàm math.h/sqrt(x);


gcc -g myProgram.c      // To be able to use gdb, we compile our source code with the -g option:
gdb a.out               // To debug the executable (a.out)
    list - lists the 10 lines of source code in the vicinity of where execution has stopped. Each call advances the current line by 10
    list m, n - where m and n are line numbers - lists lines m through n inclusive of the source code. This call advances the current line to n+1
    break n - where n is a line number - sets a breakpoint at line number n
    clear n - where n is a line number - clears any breakpoint or trace at line number n
    delete - clears all breakpoints
    run - starts the execution of your program from line 1
    print varname - where varname is a variable name - displays the value of varname
    cont - continues execution until either your program ends or encounters a breakpoint
    step - executes one line of your program
    help - displays the full set of commands available
    quit - quits