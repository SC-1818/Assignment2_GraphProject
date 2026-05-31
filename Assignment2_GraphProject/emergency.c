#include <stdio.h>
#include "emergency.h"
#include "dijkstra.h"

void addBasicLocations(Graph* g) {
    addLocation(g, 0, "Accident Location");
    addLocation(g, 1, "Main Street");
    addLocation(g, 2, "City Centre");
    addLocation(g, 3, "Bridge Road");
    addLocation(g, 4, "Hospital");
    addLocation(g, 5, "Suburb Road");
}

void runNormalScenario() {
    Graph g;

    initGraph(&g);
    addBasicLocations(&g);

    addRoad(&g, 0, 1, 4);
    addRoad(&g, 0, 5, 8);
    addRoad(&g, 1, 2, 6);
    addRoad(&g, 1, 3, 7);
    addRoad(&g, 2, 4, 5);
    addRoad(&g, 3, 4, 6);
    addRoad(&g, 5, 3, 5);

    printf("\nScenario 1: Normal Road Network\n");
    printf("All roads are open with normal travel time.\n\n");

    dijkstra(&g, 0, 4);

    freeGraph(&g);
}