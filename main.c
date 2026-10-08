#include <stdio.h>

// 1:
void task1() {
    int a, b, temp;
    printf("Task 1: Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    temp = a;
    a = b;
    b = temp;
    
    printf("%d %d\n", a, b);
}

// 2:
void task2() {
    int num;
    printf("Task 2: Enter an integer: ");
    scanf("%d", &num);
    
    if (num % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }
}
// 3:
void task3() {
    int num;
    printf("Task 3: Enter an integer: ");
    scanf("%d", &num);
    
    if (num % 3 == 0 && num % 5 == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

// 4:
void task4() {
    int num;
    printf("Task 4: Enter a positive integer: ");
    scanf("%d", &num);
    
    int last_digit = num % 10;
    printf("%d\n", last_digit);
}
// 5:
void task5() {
    int num;
    printf("Task 5: Enter a three-digit positive integer: ");
    scanf("%d", &num);
    
    int d1 = num / 100;       // Первая цифра
    int d2 = (num / 10) % 10; // Вторая цифра
    int d3 = num % 10;        // Третья цифра
    
    int sum = d1 + d2 + d3;
    printf("%d\n", sum);
}

int main() {
    int choice;
    printf("Select task (1-5): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        default: printf("Invalid task number.\n");
    }
    
    return 0;
}

