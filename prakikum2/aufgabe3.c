#include <stdio.h>

#define NUM_ROWS 8

int main() {
    double conversionRate;
    printf("Enter conversion rate (1.00 BTC -> CHF): ");
    scanf("%lf", &conversionRate);
    int iterateStep = 200;
    for (int i = 0; i < NUM_ROWS; i++) {
        printf("%4i CHF \t <--> \t %10.5f BTC\n",
               iterateStep * (i + 1),
               (float) iterateStep * (i + 1) / conversionRate); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    return 0;
}