test: main
	./schedule_cp2

main: main.o CourseList.o Course.o StudentList.o Student.o Roster.o
	g++ -Wall -Wextra main.o CourseList.o Course.o StudentList.o Student.o Roster.o -o schedule_cp2

main.o: main.cpp
	g++ -Wall -Wextra -c main.cpp

Roster.o: Roster.cpp Roster.h
	g++ -Wall -Wextra -c Roster.cpp

CourseList.o: CourseList.cpp CourseList.h
	g++ -Wall -Wextra -c CourseList.cpp

Course.o: Course.cpp Course.h
	g++ -Wall -Wextra -c Course.cpp

StudentList.o: StudentList.cpp StudentList.h
	g++ -Wall -Wextra -c StudentList.cpp

Student.o: Student.cpp Student.h
	g++ -Wall -Wextra -c Student.cpp

clean:
	rm -f *.o schedule_cp2
