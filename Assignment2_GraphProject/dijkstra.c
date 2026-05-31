#include <stdio.h>
#include "dijkstra.h"

int findSmallestDistance(int distance[], int visited[], int numLocations) {
    int i;
    int smallest;
    int smallestIndex;

    smallest = INF;
    smallestIndex = -1;

    for (i = 0; i < numLocations; i++) {
        if (visited[i] == 0 && distance[i] < smallest) {
            smallest = distance[i];
            smallestIndex = i;
        }
    }

    return smallestIndex;
}

void printRoute(Graph* g, int parent[], int location) {
    if (location == -1) {
        return;
    }

    if (parent[location] != -1) {
        printRoute(g, parent, parent[location]);
        printf(" -> ");
    }

    printf("%s", g->names[location]);
}

void dijkstra(Graph* g, int start, int end) {
    int distance[MAX_LOCATIONS];
    int visited[MAX_LOCATIONS];
    int parent[MAX_LOCATIONS];
    int i;
    int count;
    int currentIndex;
    int newDistance;
    Edge* currentEdge;

    for (i = 0; i < g->numLocations; i++) {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[start] = 0;

    for (count = 0; count < g->numLocations - 1; count++) {
        currentIndex = findSmallestDistance(distance, visited, g->numLocations);

        if (currentIndex == -1) {
            break;
        }

        visited[currentIndex] = 1;
        currentEdge = g->list[currentIndex];

        while (currentEdge != NULL) {
            newDistance = distance[currentIndex] + currentEdge->time;

            if (visited[currentEdge->to] == 0 && newDistance < distance[currentEdge->to]) {
                distance[currentEdge->to] = newDistance;
                parent[currentEdge->to] = currentIndex;
            }

            currentEdge = currentEdge->next;
        }
    }

    printf("Shortest travel time from %s to %s: ", g->names[start], g->names[end]);

    if (distance[end] == INF) {
        printf("No route found.\n");
    }
    else {
        printf("%d minutes\n", distance[end]);

        printf("Route: ");
        printRoute(g, parent, end);
        printf("\n");
    }
}

void testDijkstra() {
    Graph g;

    initGraph(&g);

    addLocation(&g, 0, "Accident Location");
    addLocation(&g, 1, "Main Street");
    addLocation(&g, 2, "City Centre");
    addLocation(&g, 3, "Bridge Road");
    addLocation(&g, 4, "Hospital");
    addLocation(&g, 5, "Suburb Road");

    addRoad(&g, 0, 1, 4);
    addRoad(&g, 0, 5, 8);
    addRoad(&g, 1, 2, 6);
    addRoad(&g, 1, 3, 7);
    addRoad(&g, 2, 4, 5);
    addRoad(&g, 3, 4, 6);
    addRoad(&g, 5, 3, 5);

    printf("\nDijkstra Test:\n\n");
    dijkstra(&g, 0, 4);

    freeGraph(&g);
}

int getShortestDistance(Graph* g, int start, int end) {
    int distance[MAX_LOCATIONS];
    int visited[MAX_LOCATIONS];
    int i;
    int count;
    int currentIndex;
    int newDistance;
    Edge* currentEdge;

    for (i = 0; i < g->numLocations; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[start] = 0;

    for (count = 0; count < g->numLocations - 1; count++) {
        currentIndex = findSmallestDistance(distance, visited, g->numLocations);

        if (currentIndex == -1) {
            break;
        }

        visited[currentIndex] = 1;
        currentEdge = g->list[currentIndex];

        while (currentEdge != NULL) {
            newDistance = distance[currentIndex] + currentEdge->time;

            if (visited[currentEdge->to] == 0 && newDistance < distance[currentEdge->to]) {
                distance[currentEdge->to] = newDistance;
            }

            currentEdge = currentEdge->next;
        }
    }

    return distance[end];
}