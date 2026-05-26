#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#define MAX_LOCATIONS 20
#define NAME_SIZE 50

typedef struct edge {
    int to;
    int time;
    struct edge* next;
} Edge;

typedef struct graph {
    int numLocations;
    char names[MAX_LOCATIONS][NAME_SIZE];
    Edge* list[MAX_LOCATIONS];
} Graph;

void initGraph(Graph* g);
void addLocation(Graph* g, int index, char name[]);
void addRoad(Graph* g, int from, int to, int time);
void printGraph(Graph* g);
void freeGraph(Graph* g);
void testGraph();

#endif
