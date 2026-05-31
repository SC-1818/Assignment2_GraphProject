#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"
#include "emergency.h"
#include "tests.h"

int main() {
    printf("Emergency Route Planning in a Road Network\n");
    printf("Final Program Output\n\n");

    testGraph();
    testDijkstra();
    runEmergencyComparison();
    runAllTests();

    return 0;
}