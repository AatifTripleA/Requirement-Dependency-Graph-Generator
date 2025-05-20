CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/parse.c src/graph.c src/report.c

req_dep_graph_88989947: $(SRC)
    $(CC) $(CFLAGS) -o req_dep_graph_88989947 $(SRC)

clean:
    rm -f req_dep_graph_88989947
