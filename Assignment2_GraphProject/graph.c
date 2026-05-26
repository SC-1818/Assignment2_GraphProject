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