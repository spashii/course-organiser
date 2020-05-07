#include "util.h"

#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char *readLine(void) {
    char *line = NULL;
    int ch;
    line = malloc(sizeof(char));
    if (!line) {
        return NULL;
    }
    line[0] = '\0';
    int index;
    for (index = 0; ((ch = getchar()) != '\n') && (ch != EOF); index++) {
        line = realloc(line, sizeof(char) * (index + 2));
        if (!line) {
            return NULL;
        }
        line[index] = (char)ch;
        line[index + 1] = '\0';
    }
    return line;
}

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
    for (; *string; string++)
        *string = toupper((unsigned char)*string);
    return s;
}

void flush_stdin_buffer() {
    int ch;
    while ((ch = getchar() != '\n')) {
    }
}

long get_time() {
    time_t now = time(NULL);
    return now;
}

void print_datetime(time_t now) {
    struct tm *t = localtime(&now);
    char s[32];
    strftime(s, 32, "%a %d %h %I:%M%p", t);
    printf("%s", s);
}

void nl() {
    printf("\n");
}

void clear_screen(){
    system("cls || clear");
}