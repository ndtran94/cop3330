# makefile for soda machine project                                            # COP 3330 Assignment 1                                                         
# Nhi Tran                                                                    
#                                                                               
 
user.o: user.h machine.h user.cpp
        g++47 -c -Wall -Wextra -I. user.cpp
machine.o: machine.h machine.cpp
        g++47 -c -Wall -Wextra -I. machine.cpp
main.o: machine.h user.h main.cpp
        g++47 -c -Wall -Wextra -I. main.cpp
soda.x: main.o machine.o user.o
        g++47 -osoda.x main.o machine.o user.o

