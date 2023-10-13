#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sales {
    char* month;
    float value;
};

int main() {
    float values[50], sum, avg;
    int ctr = 0, i, min, max;
    FILE* ptr;
    char str[50];
    char* months[50] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    ptr = fopen("sales.txt", "a+");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    while (fgets(str, 50, ptr) != NULL) {
        float temp = atof(str);
        values[ctr] = temp;
        ctr += 1;
    }

    fclose(ptr);
    struct sales *sl = malloc(sizeof(struct sales) * 12);

    if (sl == NULL) {
        perror("Malloc");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 12; i++) {
        sl[i].month = months[i];
        sl[i].value = values[i];
    }

    printf("Monthly sales report for 2022:\n\nMonth\t\tSales");

    for (i = 0; i < 12; i++) {
        printf("\n%-9s\t$%.2f", sl[i].month, sl[i].value);
    }

    printf("\n\nSales Summary\n");

    min = 0, max = 0;
    for (i = 0; i < 12; i++) {
        if (sl[i].value < sl[min].value) {
            min = i;
        } else if (sl[i].value > sl[max].value) {
            max = i;
        }
    }

    printf("\nMinimum sales:\t$%.2f\t(%s)", sl[min].value, sl[min].month);
    printf("\nMaximum sales:\t$%.2f\t(%s)", sl[max].value, sl[max].month);

    sum = 0;
    for (i = 0; i < 12; i++) {
        sum += sl[i].value;
    }
    avg = sum/i;

    printf("\nAverage sales:\t$%.2f\n", avg);
    printf("\nSix-Month Moving Average Report:\n\n");

    avg = 0, sum = 0, ctr = 0;
    for (i = 0; i < 7; i++, avg = 0, sum = 0, ctr = 0) {
        for (int j = i; j < (i + 6); j++) {
            sum += sl[j].value;
            ctr++;
        }
        avg = sum/ctr;
        printf("%-9s\t-  %-9s\t$%.2f\n", sl[i].month, sl[(i + 5)].month, avg);
    }

    printf("\nSales Report (Highest to Lowest):\n\nMonth\t\tSales");

    for (i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (sl[j].value < sl[i].value) {
                float tmp1 = sl[i].value;
                char* tmp2 = sl[i].month;
                sl[i].value = sl[j].value;
                sl[i].month = sl[j].month;
                sl[j].value = tmp1;
                sl[j].month = tmp2;
            }
        }
    }

    for (i = 0; i < 12; i++) {
        printf("\n%-9s\t$%.2f", sl[i].month, sl[i].value);
    }

    return 0;
}