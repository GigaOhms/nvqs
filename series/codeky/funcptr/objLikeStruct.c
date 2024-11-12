
typedef enum DogType {Chihuahua, Husky} Dogtype;

typedef struct Dog {                    // struct Dog là một data structure
    DogType type;
} Dog;

void bark(Dog * dog) {                  // Code như bên trái là một kiểu lập trình C...
    if (dog->type == Chihuahua)         // truyền thống: Procedural programing.
        printf("Ang ang\n");
    else if (dog->type == Husky)        // Dữ liệu (data) được đưa vào...
        printf("Grr... Gau gau\n");     // các function (procedure) để xử lý.
    else
        printf("Meow\n");
}

Dog coho1 = {Chihuahua};
Dog coho2 = {Husky};

bark(&coho1);
bark(&coho2);

// ------------------------------------ Function pointer -------------------------------

typedef void (*BarkFn)();               // Định nghĩa một kiểu function pointer

typedef struct Dog {                   
    BarkFn bark;                        // bark là một pointer trỏ đến một function kiểu BarkFn
} Dog;

void ChihuahuaBark() {                  // Định nghĩa 2 function riêng {
    printf("Ang Ang\n");                
}                                               

void HuskyBark() {
    printf("Grr... Gau gau\n");
}                                       //                              } 

Dog coho1 = {ChihuahuaBark};            // Mua 2 em chó về
Dog coho2 = {HuskyBark};

coho1.bark();                           // Cho sủa cả ngày
coho2.bark();


// --------------------------------------------------------------------------
// hành vi (behavior) sủa (bark) giờ được gắn liền với các biến coho1,      |
// coho2 tạo từ strucrt Dog                                                 |
//                                                                          |
// kiểu code này gần với object-oriented (OO),                              |      
// chúng ta có thể cấu trúc chương trình rõ ràng hơn                        |
//                                                                          |
// Hàm bark ban đầu được chia nhỏ thành các                                  |
// hàm ChihuahuaBark và HuskyBark nhỏ hơn,                                  |
// dễ bảo trì và mở rộng hơn                                                |
// --------------------------------------------------------------------------
