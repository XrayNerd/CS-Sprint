CC = g++
OBJS = src/*
# --std=c++14 -> Use C++14 instead of anything else
# -Wall				-> Warn All
# -Iheaders		-> Includes header directory
CFLAGS = --std=c++14 -Wall -Iheaders
LFLAGS = -lSDL2 -lSDL2_image
OBJ_NAME = main

all : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(OBJ_NAME)
