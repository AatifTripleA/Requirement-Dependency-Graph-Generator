#include <stdio.h>
#include "../include/parse.h"
#include "../include/report.h"
#include "../include/graph.h"

void print_file_preview(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    printf("Selected file: %s\n", file_name);
    char line[256];
    for (int i = 0; i < 3 && fgets(line, sizeof(line), file); i++) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    const char *file_name = "A04_Example_SRS.md";
    const char *report_file = "rdgg-report-88989947.md";

    // Step 1: Print file preview
    print_file_preview(file_name);

    // Step 2: Parse the SRS file
    get_requirement(file_name);

    // Step 3: Print parsed requirements
    print_parse();

    // Step 4: Generate the graph
    graph_generator();

    // Step 5: Print the graph
    print_graph();

    // Step 6: Create the report
    report_creation(report_file);

    return 0;
}
