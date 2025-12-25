#pragma once
#ifndef GRAPH_BUILDER_H
#define GRAPH_BUILDER_H

#include "core.h"
#include <vector>

std::vector<std::vector<int>> buildConflictGraph(const std::vector<Course>& courses);

#endif
