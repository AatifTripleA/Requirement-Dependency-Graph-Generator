#ifndef GRAPH_H
#define GRAPH_H

// Get requirements for dependencies from the markdown file
void get_requirement(const char *file_name);

// Generate the graph
void graph_generator(const char *file_name);

// Print the graph
void print_graph(const char *file_name);

#endif
