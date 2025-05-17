#ifndef GRAPH_H
#define GRAPH_H

// Initializes the requirement dependency graph
void graph_init(void);

// Adds a dependency between two requirements
void graph_add_dependency(const char *from, const char *to);

// Frees resources used by the graph
void graph_free(void);

#endif
