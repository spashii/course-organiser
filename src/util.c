#include "util.h"

#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *s_readline(int size) {
    char *line = malloc(size);
    int ch;
    int index = 0;
    while (index + 1 < size && ((ch = getchar()) != '\n' && ch != EOF)) {
        line[index] = (char)ch;
        line[index + 1] = '\0';
        index++;
    }
    return line;
}

char *strupr(char *str) {
    char *p = str;
    while (*p) {
        *p = toupper(*p);
        p++;
    }
    return p;
}

char *xstrupr(char *string) {
    char *s = string;
    for (; *string; string++) *string = toupper((unsigned char)*string);
    return s;
}

void flush_stdin_buffer() {
    int ch;
    while ((ch = getchar() != '\n')) {
    }
}

time_t get_time() {
    time_t now = time(NULL);
    return now;
}

void print_datetime(time_t now) {
    struct tm *t = localtime(&now);
    char s[32];
    strftime(s, 32, "%a %d %h %I:%M%p", t);
    printf("%s", s);
}

char *get_datetime_format(time_t t, char *format) {
    struct tm *tm_t = localtime(&t);
    char *s = malloc(64);
    strftime(s, 64, format, tm_t);
    return s;
}

time_t input_time() {
    time_t t = get_time();
    struct tm *tm_t = localtime(&t);
    int date, month, year, hour, minute;
    do {
        printf("Date(dd/mm/yyyy)? ");
        scanf("%d/%d/%d", &date, &month, &year);
        flush_stdin_buffer();
        date = validate_date(date, month);
    } while (!((date >= 1 && date <= 31) && (month >= 1 && month <= 12) &&
               (year >= 1900)));
    tm_t->tm_mday = date;
    tm_t->tm_mon = month - 1;
    tm_t->tm_year = year - 1900;
    do {
        printf("Time in 24hr format(HH:MM)? ");
        scanf("%d:%d", &hour, &minute);
        flush_stdin_buffer();
    } while (!((hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59)));
    tm_t->tm_hour = hour;
    tm_t->tm_min = minute;
    return mktime(tm_t);
}

int validate_date(int date, int month) {
    // todo
    return date;
}

void nl() { printf("\n"); }

void clear_screen() { system("cls || clear"); }