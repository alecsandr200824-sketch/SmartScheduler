#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "core.h"
#include <unordered_map>
Schedule buildSchedule(
    std::vector<Course>& courses,
    std::unordered_map<int, Teacher>& teachers,
    std::unordered_map<int, Group>& groups,
    std::vector<Room>& rooms
);

#endif
