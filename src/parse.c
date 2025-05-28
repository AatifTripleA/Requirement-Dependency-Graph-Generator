#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"
#include "graph.h"

extern Requirement requirements[];
extern int requirement_count;

void parse_srs(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "REQ-")) {
            if (strstr(line, "--")) {
                sscanf(line, "Line %*d: %s --", requirements[requirement_count].id);
            } else if (strstr(line, "->")) {
                char parent[50], child[50];
                sscanf(line, "Line %*d: %s -> %s", parent, child);

                // Find the parent requirement and add the child
                for (int i = 0; i < requirement_count; i++) {
                    if (strcmp(requirements[i].id, parent) == 0) {
                        strcpy(requirements[i].children[requirements[i].child_count++], child);
                        break;
                    }
                }
            }
        }
    }

    requirement_count++;
    fclose(file);
}

void print_parse(void) {
    printf("Parsed Requirements and Dependencies:\n");
    for (int i = 0; i < requirement_count; i++) {
        printf("Requirement: %s\n", requirements[i].id);
        printf("  Parent: %s\n", requirements[i].parent);
        printf("  Children:\n");
        for (int j = 0; j < requirements[i].child_count; j++) {
            printf("    - %s\n", requirements[i].children[j]);
        }
    }
}
