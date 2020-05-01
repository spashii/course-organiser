#include "app.h"
#include "info.h"

#include <stdio.h>
#include <time.h>

void display_header(){
    time_t now= time(NULL);
    struct tm t_now= *localtime(&now);
    int star;
    display_stars(printf("\n COURSE ORGANISER\n"));
    char str[32];
    // Fri 01 May 02:51PM
    strftime(str, 32, "%a %d %h %I:%M%p", &t_now);
    printf("\n%s\n", str);
}

void display_stars(int size){
    while(size>1 && size--){
        putchar('*');
    }
}

void display_menu(){
    printf("\nMenu\n");
    printf("1. Display All Courses\n");
    printf("2. Insert Course\n");
    printf("3. xxxx\n");
    printf("4. Exit\n");
    printf("\nYour Choice? ");
}
