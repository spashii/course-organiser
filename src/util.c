#include "util.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>
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
    char *line = malloc(size);
    int ch;
    int index=0;
    while (index + 1 < size && ((ch = getchar()) != '\n' && ch != EOF)) {
        line[index] = (char)ch;
        line[index + 1] = '\0';
        index++;
    }
    return line;
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

void nl(){
    printf("\n");
}