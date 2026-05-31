#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"
#include "emergency.h"

int main() {
    printf("Emergency Route Planning in a Road Network\n");
    printf("Part 3: Emergency Route Scenarios\n\n");

    testGraph();
    testDijkstra();
    runEmergencyComparison();

    return 0;
}