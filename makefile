#Program Name: Final Project
#Author: Brendan Corazzin
#Date: 6/4/2017
#Description: This is the makefile for the Final Project.


CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#LDFLAGS = -lboost_date_time

OBJS = main.o getChar.o getYorN.o menu.o Game.o Player.o Pack.o Space.o Sbeach.o Forest.o validateInput.o River.o Wbeach.o Temple.o Nbeach.o

SRCS = main.cpp getChar.cpp getYorN.cpp menu.cpp Game.hpp Player.cpp Pack.cpp Space.cpp Sbeach.cpp Forest.cpp validateInput.cpp River.cpp Wbeach.cpp Temple.cpp Nbeach.cpp

HEADERS = getChar.hpp getYorN.hpp menu.hpp Game.hpp Player.hpp Pack.hpp Space.hpp Sbeach.hpp Forest.hpp validateInput.hpp River.hpp Wbeach.hpp Temple.hpp Nbeach.hpp

final: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o final
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean: 
	rm *.o final
