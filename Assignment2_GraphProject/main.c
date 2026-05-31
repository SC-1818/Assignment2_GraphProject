#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"

int main() {
    printf("Emergency Route Planning in a Road Network\n");
    printf("Part 2: Dijkstra Shortest Path Test\n\n");

    testGraph();
    testDijkstra();

    return 0;
}