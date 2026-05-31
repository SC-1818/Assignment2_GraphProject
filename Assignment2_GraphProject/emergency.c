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

void runCongestedScenario() {
    Graph g;

    initGraph(&g);
    addBasicLocations(&g);

    addRoad(&g, 0, 1, 4);
    addRoad(&g, 0, 5, 8);

    /* This road is congested, so the travel time is higher than normal. */
    addRoad(&g, 1, 2, 15);

    addRoad(&g, 1, 3, 7);
    addRoad(&g, 2, 4, 5);
    addRoad(&g, 3, 4, 6);
    addRoad(&g, 5, 3, 5);

    printf("\nScenario 2: Congested Road Network\n");
    printf("The road from Main Street to City Centre has higher travel time.\n\n");

    dijkstra(&g, 0, 4);

    freeGraph(&g);
}

void runBlockedScenario() {
    Graph g;

    initGraph(&g);
    addBasicLocations(&g);

    addRoad(&g, 0, 1, 4);
    addRoad(&g, 0, 5, 8);

    /*
       The roads from Main Street to City Centre and Main Street to Bridge Road
       are not added here because they are treated as blocked roads.
    */

    addRoad(&g, 2, 4, 5);
    addRoad(&g, 3, 4, 6);
    addRoad(&g, 5, 3, 5);

    printf("\nScenario 3: Blocked Road Network\n");
    printf("Some roads from Main Street are blocked, so another route is needed.\n\n");

    dijkstra(&g, 0, 4);

    freeGraph(&g);
}

void runEmergencyComparison() {
    printf("\nEmergency Route Investigation\n");
    printf("-----------------------------\n");
    printf("Start location: Accident Location\n");
    printf("Destination: Hospital\n");

    runNormalScenario();
    runCongestedScenario();
    runBlockedScenario();
}