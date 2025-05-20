# Variables
CC       = gcc
DEBUG    = -g -DDEBUG
CFLAGS   = -Wall -std=c11 $(DEBUG) -c
LFLAGS   = -Wall $(DEBUG)

CFLAGSNDEBUG  = -Wall -std=c11 -c
LFLAGSNDEBUG   = -Wall

# Default target

all: req_dep_graph_88989947

clean:
	rm -f *.o
	rm -f req_dep_graph_88989947

######################### Generate object files #######################
# Target for graph.o
graph.o:	graph.c graph.h
	$(CC) $(CFLAGS) graph.c -o graph.o
# Target for parse.o
parse.o: parse.c parse.h
	$(CC) $(CFLAGS) parse.c -o parse.o
# Target for report.o
report.o: report.c report.h graph.c graph.h 
	$(CC) $(CFLAGS) report.c -o report.o

######################### Generate the executable #####################
# Target for req_dep_graph_88989947
req_dep_graph_88989947: graph.o parse.o report.o
	$(CC) $(LFLAGS) graph.o parse.o report.o -o req_dep_graph_88989947 -lm
