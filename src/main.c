#include <stdio.h>
#include "parse.h"
#include "report.h"
#include "graph.h"

int main() {
    const char *file_name = "A04_Example_SRS.md";
    const char *report_file = "rdgg-report-88989947.md";

    // Step 1: Parse the SRS file
    get_requirement(file_name);

    // Step 2: Print parsed requirements
    print_parse();

    // Step 3: Generate the graph
    graph_generator();

    // Step 4: Print the graph
    print_graph();

    // Step 5: Create the report
    report_creation(report_file);

    return 0;
}
