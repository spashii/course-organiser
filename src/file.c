#include "file.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "info.h"
#include "course.h"
#include "course_list.h"

char* get_db_path(enum db_name db) {
    char file_path = malloc(128);
    switch (db) {
        case COURSE_DB:
            strncpy(file_path, "database/course.db", 128);
            break;
        case COURSE_DB_BKP:
            strncpy(file_path, "database/course.db.bkp", 128);
            break;
        default:
            strncpy(file_path, "", 128);
    }
    return file_path;
}

FILE* open_db(enum db_name db_n, enum mode m) {
    FILE* db;
    char* file_path = get_db_path(db_n);
    switch (m) {
        case READ:
            db = fopen(file_path, "rb");
            return db;
        case WRITE:
        case APPEND:
            db = fopen(file_path, "ab");
            return db;
        case OVERWRITE:
            db = fopen(file_path, "w");
            return db;
    }
    return NULL;
}

void close_db(FILE* db) {
    if (db)
        fclose(db);
}

void copy_db(enum db_name db_dest, enum db_name db_src, enum mode write_mode) {
    FILE* src = open_db(db_src, READ);
    FILE* dest = open_db(db_dest, write_mode);
    if (src && dest) {
        int ch;
        while ((ch = fgetc(src)) != EOF) {
            fputc(ch, dest);
        }
        close_db(dest);
        close_db(src);
    }
}
