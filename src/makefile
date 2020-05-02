C = gcc
CFLAGS = -Wall -g

test: test.o info.o course.o course_list.o course_index.o file.o util.o
	$(C) $(CFLAGS) -o test test.o info.o course.o course_list.o course_index.o file.o util.o

test.o: app/info.h course/course.h course_list/course_list.h course_index/course_index.h database/file.h util/util.h
	$(C) $(CFLAGS) -c test.c 

info.o: app/info.h
	$(C) $(CFLAGS) -c app/info.c

course.o: course/course.h util/util.h database/file.h
	$(C) $(CFLAGS) -c course/course.c

course_list.o: course/course.h course_list/course_list.h database/file.h
	$(C) $(CFLAGS) -c course_list/course_list.c

course_index.o: course/course.h course_list/course_list.h course_index/course_index.h
	$(C) $(CFLAGS) -c course_index/course_index.c

file.o: app/info.h course/course.h course_list/course_list.h database/file.h
	$(C) $(CFLAGS) -c database/file.c

util.o: util/util.h
	$(C) $(CFLAGS) -c util/util.c 

clean:
	-rm *.o test