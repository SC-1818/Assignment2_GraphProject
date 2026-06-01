#include <stdio.h>
#include "tests.h"
#include "graph.h"
#include "dijkstra.h"
#include <time.h>

void addTestLocations(Graph* g) {
    addLocation(g, 0, "Accident Location");
    addLocation(g, 1, "Main Street");
    addLocation(g, 2, "City Centre");
    addLocation(g, 3, "Bridge Road");
    addLocation(g, 4, "Hospital");
    addLocation(g, 5, "Suburb Road");
}

void addNormalRoads(Graph* g) {
    addRoad(g, 0, 1, 4);
    addRoad(g, 0, 5, 8);
    addRoad(g, 1, 2, 6);
    addRoad(g, 1, 3, 7);
    addRoad(g, 2, 4, 5);
    addRoad(g, 3, 4, 6);
    addRoad(g, 5, 3, 5);
}

void addCongestedRoads(Graph* g) {
    addRoad(g, 0, 1, 4);
    addRoad(g, 0, 5, 8);
    addRoad(g, 1, 2, 15);
    addRoad(g, 1, 3, 7);
    addRoad(g, 2, 4, 5);
    addRoad(g, 3, 4, 6);
    addRoad(g, 5, 3, 5);
}

void addBlockedRoads(Graph* g) {
    addRoad(g, 0, 1, 4);
    addRoad(g, 0, 5, 8);

    /* Roads from Main Street to City Centre and Bridge Road are blocked. */

    addRoad(g, 2, 4, 5);
    addRoad(g, 3, 4, 6);
    addRoad(g, 5, 3, 5);
}

void testGraphStructure() {
    Graph g;

    printf("\nTest 1: Graph Structure Test\n");

    initGraph(&g);
    addTestLocations(&g);
    addNormalRoads(&g);

    if (g.numLocations == 6 && g.list[0] != NULL && g.list[4] != NULL) {
        printf("PASS: Graph stores locations and roads correctly.\n");
    }
    else {
        printf("FAIL: Graph structure is not correct.\n");
    }

    freeGraph(&g);
}

void testDijkstraDistance() {
    Graph g;
    int result;

    printf("\nTest 2: Dijkstra Shortest Path Test\n");

    initGraph(&g);
    addTestLocations(&g);
    addNormalRoads(&g);

    result = getShortestDistance(&g, 0, 4);

    if (result == 15) {
        printf("PASS: Dijkstra found the correct shortest travel time of 15 minutes.\n");
    }
    else {
        printf("FAIL: Expected 15 minutes but got %d minutes.\n", result);
    }

    freeGraph(&g);
}

void testEmergencyScenarios() {
    Graph g;
    int normalResult;
    int congestedResult;
    int blockedResult;

    printf("\nTest 3: Emergency Scenario Tests\n");

    initGraph(&g);
    addTestLocations(&g);
    addNormalRoads(&g);
    normalResult = getShortestDistance(&g, 0, 4);
    freeGraph(&g);

    initGraph(&g);
    addTestLocations(&g);
    addCongestedRoads(&g);
    congestedResult = getShortestDistance(&g, 0, 4);
    freeGraph(&g);

    initGraph(&g);
    addTestLocations(&g);
    addBlockedRoads(&g);
    blockedResult = getShortestDistance(&g, 0, 4);
    freeGraph(&g);

    if (normalResult == 15 && congestedResult == 17 && blockedResult == 19) {
        printf("PASS: Normal, congested, and blocked scenarios returned expected results.\n");
    }
    else {
        printf("FAIL: Scenario results were not as expected.\n");
        printf("Normal: %d, Congested: %d, Blocked: %d\n",
            normalResult, congestedResult, blockedResult);
    }
}

void runAllTests() {
    printf("\nUnit Tests\n");
    printf("----------\n");

    testGraphStructure();
    testDijkstraDistance();
    testEmergencyScenarios();
}

void runPerformanceComparison() {
    Graph g;
    clock_t startTime;
    clock_t endTime;
    double timeTaken;
    int i;
    int result;

    printf("\nPerformance Test\n");
    printf("----------------\n");

    initGraph(&g);
    addTestLocations(&g);
    addNormalRoads(&g);

    startTime = clock();

    for (i = 0; i < 10000; i++) {
        result = getShortestDistance(&g, 0, 4);
    }

    endTime = clock();

    timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Shortest distance result: %d minutes\n", result);
    printf("Dijkstra repeated 10000 times.\n");
    printf("Total time taken: %.5f seconds\n", timeTaken);

    freeGraph(&g);
}