# Scheduler w/ Vector ADT

A text based application that creates and manages students, their courses, and the course roster using my own implementation of a vector ADT. The goal of this project was to:

- Familarize with separating code into modules
- Implementing a vector ADT
- Learn regular expressions

## Introduction

Vectors in C++ are essentially changable arrays. Whenever data begins to exceed the element capacity, new contiguous memory is allocated and the values are copied over. Here, I created my own vector ADT that manages the `CourseList` and `Roster`, starting with a capacity of 1 and expanding as necessary.

Based on various predetermined commands, the user can add/drop students, classes, and class rosters through the flexibilty provided by regular expressions. Any dependencies that a student has to a class, or that a class has to its students, will be taken care of accordingly and efficiently. 

No memory leaks will occur due to extensive testing with ***valgrind***.

## Makefile

Contains the following targets:

- `clean` Removes all the files Makefile can create
- `test` - creates the schedule_cp2 executable from CourseList, Course, StudentList, Student, Roster
  
## Runtime Example

## Credit

The first "hard" project in CS310. The credit for this idea goes to Professor Mike Lewis of Binghamton University. The implementation of the code was completely my own.
