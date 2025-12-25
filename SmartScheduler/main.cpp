#include "loader.h"
#include "graph_builder.h"
#include "scheduler.h"
#include "exporter.h"
#include <unordered_map>

int main() {
    auto teachersVec = loadTeachers("data/teachers.csv");
    auto groupsVec = loadGroups("data/groups.csv");
    auto courses = loadCourses("data/courses.csv");
    auto rooms = loadRooms("data/rooms.csv");

    std::unordered_map<int, Teacher> teachers;
    std::unordered_map<int, Group> groups;

    for (auto& t : teachersVec) teachers[t.id] = t;
    for (auto& g : groupsVec) groups[g.id] = g;

    auto graph = buildConflictGraph(courses);

    Schedule sched = buildSchedule(courses, teachers, groups, rooms);

    printSchedule(sched);

    return 0;
}
