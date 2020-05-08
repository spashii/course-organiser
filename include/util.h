#ifndef _UTIL_H_
#define _UTIL_H_

#include <time.h>

// enum error_codes{
//     RET_OK,
//     RET_SUCCESS,
//     RET_NOT_OK,
//     RET_FILE_NOT_OPEN,
//     RET_FILE_READ,
//     RET_FILE_WRITE
// };

char *s_readline(int size);
char *strupr(char *str);
char *xstrupr(char *string);
void flush_stdin_buffer(void);
void nl();
void clear_screen();


time_t get_time();
void print_datetime();
char *get_datetime_format(time_t t, char *format);
int validate_date(int date, int month);
time_t input_time();



#endif