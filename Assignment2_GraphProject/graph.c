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