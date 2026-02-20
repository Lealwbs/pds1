#include <stdio.h>
#include <stdbool.h>

const int DAY_TARGET = 17, MONTH_TARGET = 9, YEAR_TARGET = 2020;
const int MONTHS[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

bool is_bissexto(int year){
    return (year%4 == 0 && (year%100 != 0 || year%400 == 0));
}

int count_days(int day, int month, int year){
    int result = 0;
    result += day;
    result += MONTHS[month-1] + (is_bissexto(year) && month > 2 ? 1 : 0);
    for(int i=1; i<year; i++) 
        result += 365 + is_bissexto(i);
    return result;
}

int main(void){    
    int day, month, year;
    while(scanf("%d %d %d", &day, &month, &year)){
        if(day < 1 || month < 1 || year < 1) break;
        int days_count = count_days(DAY_TARGET, MONTH_TARGET, YEAR_TARGET) - count_days(day, month, year);
        printf("%d\n", days_count + 1);
    }
    return 0;
}