#define _XOPEN_SOURCE 700

#include "util.h"

#include <malloc.h>
#include <stdio.h>
#include <time.h>

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
    char *line = malloc(sizeof(size));
    int ch;
    int index;
    for (index = 0; ((ch = getchar()) != '\n' && ch != EOF) && (index + 1 < size); index++) {
        *(line + index) = ch;
    }
    *(line + index + 1) = '\0';
    fflush(stdin);
    return line;
}

long get_time(){
    time_t now = time(NULL);
    struct tm *temp;
    temp = localtime(&now);
    return now;
}