// chúng ta biết là function input parameter có thể là một pointer
void func(int *ptr);

// nếu input pointer đó là một function pointer?
void func(MyFunc funPtr); // Callback function


// với callback function: một function sẽ...
// gọi một function khác mà chúng ta đưa vào.
typedef void (*StoreFn)(char *str);
void download(StoreFn fn) {
    printf("Pretend downloading...\n");
}

// callback function rất linh hoạt vì chúng ta...
// không hard-code function nào được gọi

// invoke callback function after downloaded fn("awesome!!!);
void store(char *str) {
    printf("Store: %s\n", str);
}

int main() {
    download(store);
    return 0;
}
