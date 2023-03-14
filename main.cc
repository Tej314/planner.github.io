#include <stdio.h>
#include <stdlib.h>

int main() {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char months[][4] = {"Jan", "Feb", "Mar", "Apr", "May"};
    int start_day, end_day;
    int current_month = 2; // March
    int current_day = 14; // Today
    int current_year = 2023; // Current year
    int end_month = 4; // May

    printf("Planner from March 14, 2023 to May 31, 2023\n\n");

    for (int month = current_month; month <= end_month; month++) {
        printf("%s\n", months[month-1]);
        printf("Su Mo Tu We Th Fr Sa\n");

        if (month == current_month) {
            start_day = current_day % 7;
            end_day = days_in_month[month-1];
        } else {
            start_day = (start_day + days_in_month[month-2]) % 7;
            end_day = days_in_month[month-1];
        }

        for (int i = 0; i < start_day; i++) {
            printf("   ");
        }

        for (int day = 1; day <= end_day; day++) {
            printf("%2d ", day);
            if ((day + start_day) % 7 == 0) {
                printf("\n");
            }
        }

        if ((end_day + start_day) % 7 != 0) {
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}
