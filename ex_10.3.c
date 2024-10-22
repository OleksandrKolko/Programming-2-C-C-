#include <stdio.h>
typedef struct Date {
    int day;
    int month;
    int year;
} Date;

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int is_valid_date(Date date) {

    if (date.year < 0) return 0;


    if (date.month < 1 || date.month > 12) return 0;


    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if (is_leap_year(date.year)) {
        days_in_month[2] = 29;
    }


    if (date.day < 1 || date.day > days_in_month[date.month]) return 0;

    return 1;
}

void next_day(Date* date) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if (is_leap_year(date->year)) {
        days_in_month[2] = 29;
    }


    date->day++;
    if (date->day > days_in_month[date->month]) {
        date->day = 1;
        date->month++;
        if (date->month > 12) {
            date->month = 1;
            date->year++;
        }
    }
}

const char* day_of_week(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100; //
    int j = year / 100; //
    int f = day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 - 2 * j;
    f = f % 7;

    const char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return days[f];
}

int main() {
    Date date;

    printf("Enter day: ");
    scanf("%d", &date.day);
    printf("Enter month: ");
    scanf("%d", &date.month);
    printf("Enter year: ");
    scanf("%d", &date.year);

    if (!is_valid_date(date)) {
        printf("Invalid date entered.\n");
        return 1;
    }
    next_day(&date);
    printf("Tomorrow's date: %02d/%02d/%d\n", date.day, date.month, date.year);

    const char* weekday = day_of_week(date.day, date.month, date.year);
    printf("Day of the week: %s\n", weekday);

}