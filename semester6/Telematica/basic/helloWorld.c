#include <stdio.h> // standar the inpud ans output

void main() {

    printf("Hello World\n");

    short h = 123;
    printf("h is %hd\n", h);
    int a = 10;
    float b = 2.5;
    printf("a = %d, b = %f\n", a, b);
    double c = 3.14;
    printf("c = %f\n", c);
    char s[] = "My name is felipe";
    printf("s = %s\n", s);

    char name[] = "";
    short age = 0;
    printf("enter your name: ");
    scanf("%s" ,&name );
    printf("enter your age: ");
    scanf("%hd" ,&age );
    printf("your name is: %s \n", name);
    printf("this is your age: %hd \n", age);

    int a1 =  2;
    int a2 = 3;
    int result = a1 + a2;
    printf("result = %d\n", result);
    printf("%d \n" , !( !(a1 == a1) || (a1 > a2) ));

    if(a1 > a2) {
        printf("%d is less than %d \n", a1, a2);
    } else {
        printf("a1 is greater than a2 \n");
    }

    switch(a2) {
        case 1: printf("%d is greater than %d \n", a2, a1);
        break;
        case 2: printf("%d is less than %d \n", a2, a1);
        break;
        case 3: printf("%d is greater than %d \n", a2, a1);
        break;
        default: printf("%d is less than %d \n", a2, a1);
        break;
    }

    for (int i = 0; i <= 10; i++) {
        printf("%d \n", i);
    }

    for (int j = 0; j <= 10; j++) {
        for (int n = 0; n <= 10; n++) {
            printf("%d ", n);
        }
        printf("\n");
    }

}