#include <stdio.h>

int main() {
    int score;

    do {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
    
        if (score <= 1) {
            break;
        }

        printf("possible combinations of scoring plays\n");
        for (int i = 0; i <= score; i += 8) {
            for (int j = 0; j <= score; j += 7) {
                for (int k = 0; k <= score; k += 6) {
                    for (int l = 0; l <= score; l += 3) {
                        for (int m = 0; m <= score; m += 2) {
                            if (score == i + j + k + l + m) {
                                printf("%d TD + 2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", i/8, j/7, k/6, l/3, m/2);
                            }
                        }
                    }
                }
            }
        }
    } while (score > 1);

    return 0;
}