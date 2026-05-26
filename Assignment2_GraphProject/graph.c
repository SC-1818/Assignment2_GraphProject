#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void initGraph(Graph* g) {
    int i;

    g->numLocations = 0;

    for (i = 0; i < MAX_LOCATIONS; i++) {
        g->list[i] = NULL;
        strcpy(g->names[i], "");
    }
}

void addLocation(Graph* g, int index, char name[]) {
    if (index < 0 || index >= MAX_LOCATIONS) {
        printf("Invalid location index.\n");
        return;
    }

    strcpy(g->names[index], name);

    if (index >= g->numLocations) {
        g->numLocations = index + 1;
    }
}

void addRoad(Graph* g, int from, int to, int time) {
    Edge* newEdge;
    Edge* reverseEdge;

    if (from < 0 || to < 0 || from >= g->numLocations || to >= g->numLocations) {
        printf("Invalid road.\n");
        return;
    }

    if (time <= 0) {
        printf("Travel time must be positive.\n");
        return;
    }

    newEdge = malloc(sizeof(Edge));

    if (newEdge == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newEdge->to = to;
    newEdge->time = time;
    newEdge->next = g->list[from];
    g->list[from] = newEdge;

    reverseEdge = malloc(sizeof(Edge));

    if (reverseEdge == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    reverseEdge->to = from;
    reverseEdge->time = time;
    reverseEdge->next = g->list[to];
    g->list[to] = reverseEdge;
}

void printGraph(Graph* g) {
    int i;
    Edge* current;

    printf("Road Network:\n\n");

    for (i = 0; i < g->numLocations; i++) {
        printf("%s -> ", g->names[i]);

        current = g->list[i];

        while (current != NULL) {
            printf("%s (%d min)", g->names[current->to], current->time);

            if (current->next != NULL) {
                printf(", ");
            }

            current = current->next;
        }

        printf("\n");
    }
}

void freeGraph(Graph* g) {
    int i;
    Edge* current;
    Edge* temp;

    for (i = 0; i < g->numLocations; i++) {
        current = g->list[i];

        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp);
        }

        g->list[i] = NULL;
    }
}

void testGraph() {
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

    printGraph(&g);

    freeGraph(&g);
}