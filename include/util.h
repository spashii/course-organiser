#ifndef _UTIL_H_
#define _UTIL_H_

enum {
    RET_OK,
    RET_SUCCESS,
    RET_NOT_OK,
    RET_FILE_NOT_OPEN,
    RET_FILE_READ,
    RET_FILE_WRITE
};

char *readLine(void);
char *s_readline(int size);
char *strupr(char *str);
void flush_stdin_buffer(void);
long get_time();
void nl();

#endif