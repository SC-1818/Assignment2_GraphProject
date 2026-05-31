#pragma once
#ifndef EMERGENCY_H
#define EMERGENCY_H

#include "graph.h"

void addBasicLocations(Graph* g);
void runNormalScenario();
void runCongestedScenario();
void runBlockedScenario();

#endif
