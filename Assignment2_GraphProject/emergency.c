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

    freeGraph(&g);
}