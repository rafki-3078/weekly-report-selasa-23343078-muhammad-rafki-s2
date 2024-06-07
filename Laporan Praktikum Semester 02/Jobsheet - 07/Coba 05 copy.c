#include <stdio.h>

int main() {
    float num1, num2;
    char op;

    printf("Masukkan dua angka: ");
    scanf("%f %f", &num1, &num2);

    printf("Pilih operasi matematika (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case '/':
            if(num2 != 0) {
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            } else {
                printf("Error: Pembagian dengan nol tidak diperbolehkan\n");
            }
            break;
        default:
            printf("Operasi matematika tidak valid\n");
    }

    return 0;
}
