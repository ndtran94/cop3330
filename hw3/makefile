# makefile for id project
# makefile for executables test1.cpp test2.cpp
# Nhi Tran
# COP Assignment #3
 
test1.x : test1.o id.o
        g++47 -otest1.x test1.o id.o
test2.x : test2.o id.o
        g++47 -otest2.x test.o id.o
id.o : id.h id.cpp
        g++47 -c -Wall -Wextra -I. id.cpp
test1.o : id.h test1.cpp
        g++ -c -Wall -Wextra -I. test1.cpp
test2.o : id.h test2.cpp
        g++ -c -Wall -Wextra -I. test2.cpp