# Variables
CC       = gcc
DEBUG    = -g -DDEBUG
CFLAGS   = -Wall -std=c11 $(DEBUG) -Iinclude -c
LFLAGS   = -Wall $(DEBUG) -Iinclude

# Default target

all: build req_dep_graph_88989947

build:
    mkdir -p build

clean:
    rm -rf build

######################### Generate object files #######################
# Target for graph.o
build/graph.o: ./src/graph.c ./include/graph.h ./include/parse.h
    $(CC) $(CFLAGS) ./src/graph.c -o ./build/graph.o

# Target for parse.o
build/parse.o: ./src/parse.c ./include/parse.h ./include/graph.h
    $(CC) $(CFLAGS) ./src/parse.c -o ./build/parse.o

# Target for report.o
build/report.o: ./src/report.c ./include/report.h
    $(CC) $(CFLAGS) ./src/report.c -o ./build/report.o

# Target for main.o
build/main.o: ./src/main.c ./include/graph.h ./include/parse.h ./include/report.h
    $(CC) $(CFLAGS) ./src/main.c -o ./build/main.o

######################### Generate the executable #####################
# Target for req_dep_graph_88989947
req_dep_graph_88989947: ./build/main.o ./build/graph.o ./build/parse.o ./build/report.o
    $(CC) $(LFLAGS) ./build/main.o -o ./build/req_dep_graph_88989947 ./build/graph.o ./build/parse.o ./build/report.o
