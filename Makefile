# Variables
CC       = gcc
DEBUG    = -g -DDEBUG
CFLAGS   = -Wall -std=c11 $(DEBUG) -Iinclude -c
LFLAGS   = -Wall $(DEBUG) -Iinclude

CFLAGSNDEBUG  = -Wall -std=c11 -c
LFLAGSNDEBUG   = -Wall

# Default target

all: build req_dep_graph_88989947

build:
	mkdir -p build

clean:
        rm -rf build

######################### Generate object files #######################
# Target for graph.o
build/graph.o:  ./src/graph.c ./include/graph.h
        $(CC) $(CFLAGS) ./src/graph.c -o ./build/graph.o
# Target for parse.o
build/parse.o: ./src/parse.c ./include/parse.h
        $(CC) $(CFLAGS) ./src/parse.c -o ./build/parse.o
# Target for report.o
build/report.o: ./src/report.c ./include/report.h ./src/graph.c ./include/graph.h
        $(CC) $(CFLAGS) ./src/report.c -o ./build/report.o

######################### Generate the executable #####################
# Target for req_dep_graph_88989947
req_dep_graph_88989947: ./src/main.c ./build/graph.o ./build/parse.o ./build/report.o
        $(CC) $(LFLAGS) ./src/main.c -o ./build/req_dep_graph_88989947 ./build/graph.o ./build/parse.o ./build/report.o
