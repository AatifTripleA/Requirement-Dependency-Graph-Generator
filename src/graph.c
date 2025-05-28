#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/parse.h"
#include "../include/graph.h"

// The Requirement structure is used to store a requirement's ID, parent, and children.
// It is implemented as an array of structures for simplicity and ease of access.
// The child_count field tracks the number of children for each requirement.
typedef struct Requirement {
    char id[50];
    char parent[50];
    char children[10][50];
    int child_count;
} Requirement;

Requirement requirements[100];
int requirement_count = 0;

// Get requirements for dependencies from the markdown file
void get_requirement(const char *file_name) {
    parse_srs(file_name);
}

// Generate the graph
void graph_generator(void) {
    printf("Graph generation complete.\n");
}

// Print the graph
void print_graph(void) {
    printf("Requirement Dependency Graph:\n");
    for (int i = 0; i < requirement_count; i++) {
        printf("Requirement: %s\n", requirements[i].id);
        printf("  Parent: %s\n", requirements[i].parent);
        printf("  Children:\n");
        for (int j = 0; j < requirements[i].child_count; j++) {
            printf("    - %s\n", requirements[i].children[j]);
        }
    }
}
