#include <stdio.h>
// xaxox - Enter; dambul - Task
int main() {
    // 1: 
    printf("=== dambul 1 ===\n");
    int n1;
    printf("xaxox N: ");
    scanf("%d", &n1);

    for (int i = 1; i <= n1; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 2: 
    printf("=== dambul 2 ===\n");
    int n2;
    printf("xaxox N: ");
    scanf("%d", &n2);

    int sum2 = 0;
    for (int i = 1; i <= n2; i++) {
        sum2 = sum2 + i;
    }
    printf("Sum: %d\n\n", sum2);

    // 3:
    printf("=== dambul 3 ===\n");
    int n3;
    printf("xaxox N: ");
    scanf("%d", &n3);

    for (int i = 1; i <= n3; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    // 4: 
    printf("=== dambul 4 ===\n");
    int n4;
    printf("xaxox tvanshan: ");
    scanf("%d", &n4);

    for (int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", n4, i, n4 * i);
    }
    printf("\n");

    // 5: 
    printf("=== Task 5 ===\n");
    int num;
    int sum5 = 0;

    printf("Enter numbers (0 to stop):\n");
    scanf("%d", &num);

    while (num != 0) {
        sum5 = sum5 + num;
        scanf("%d", &num);
    }

    printf("Total sum: %d\n", sum5);

    return 0;
}
