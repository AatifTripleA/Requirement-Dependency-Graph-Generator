#include <stdio.h>
#include "report.h"
#include "graph.h"

extern Requirement requirements[];
extern int requirement_count;

void report_creation(const char *output_file) {
    FILE *file = fopen(output_file, "w");
    if (!file) {
        printf("Error: Could not create report file %s\n", output_file);
        return;
    }

    fprintf(file, "# <center>Software Requirements Specification </center>\n");
    fprintf(file, "<center> EECS 22L - Spring 2025 </center>\n");
    fprintf(file, "<center> Project 1 - Chess Game </center>\n\n");

    for (int i = 0; i < requirement_count; i++) {
        fprintf(file, "Line %d: %s --\n", i + 1, requirements[i].id);
        for (int j = 0; j < requirements[i].child_count; j++) {
            fprintf(file, "Line %d: %s -> %s\n", i + 1, requirements[i].id, requirements[i].children[j]);
        }
    }

    fclose(file);
    printf("Report created: %s\n", output_file);
}
