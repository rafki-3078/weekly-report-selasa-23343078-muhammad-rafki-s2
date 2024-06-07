#include <stdio.h>

struct Distance {
    int feet;
    float inch;
} dist1, dist2, sum;

int main() {

    printf("1st distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist1.feet);

    printf("Enter inch: ");
    scanf("%f", &dist1.inch);

    printf("2nd distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist2.feet);

    printf("Enter inch: ");
    scanf("%f", &dist2.inch); // Corrected the typo in scanf

    sum.feet = dist1.feet + dist2.feet;
    sum.inch = dist1.inch + dist2.inch;

    while (sum.inch >= 12) {
        ++sum.feet;
        sum.inch = sum.inch - 12;
    }

    printf("sum of distances = %d\'-%.1f\"\n", sum.feet, sum.inch); // Added a missing closing double quote and added a newline

    return 0; // Added a missing semicolon
}
