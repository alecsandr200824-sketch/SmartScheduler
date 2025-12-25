#pragma once
#ifndef CORE_H
#define CORE_H

#include <string>
#include <vector>
#include <unordered_map>

const int DAYS = 5;
const int SLOTS = 8;

struct Teacher {
    int id;
    std::string name;
    int max_hours_per_day;
    bool preferred_days[DAYS]{};
    bool busy[DAYS][SLOTS]{};
};

struct Group {
    int id;
    std::string name;
    int size;
    int max_hours_per_day;
    bool busy[DAYS][SLOTS]{};
};

struct Room {
    int id;
    std::string name;
    int capacity;
    std::string type;
    bool busy[DAYS][SLOTS]{};
};

struct Course {
    int id;
    std::string name;
    std::string type;
    int hours_per_week;
    int teacher_id;
    std::vector<int> group_ids;
    std::string room_type;
};

struct Lesson {
    int day;
    int slot;
    int course_id;
    int teacher_id;
    int room_id;
    std::vector<int> group_ids;
};

struct Schedule {
    std::vector<Lesson> lessons;
    int fitness = 0;
    int violations = 0;
};

#endif

