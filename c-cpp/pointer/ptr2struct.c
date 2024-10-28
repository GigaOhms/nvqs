// Absolutely valid. Usually, you can take full advantage of this way by defining two types together:

typedef struct
{
    int a;
    int b;
} S1, *S1PTR;

// Where S1 is a struct and S1PTR is the pointer to this struct.

// You could create more pointers just by using

S1PTR ptr1, ptr2, ptr3;  

// instead of

S1 *ptr1, *ptr2, *ptr3;