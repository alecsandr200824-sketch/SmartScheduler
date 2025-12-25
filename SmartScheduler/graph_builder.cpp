#include "graph_builder.h"

bool conflict(const Course& a, const Course& b) {
    if (a.teacher_id == b.teacher_id) return true;
    for (int ga : a.group_ids)
        for (int gb : b.group_ids)
            if (ga == gb) return true;
    return false;
}

std::vector<std::vector<int>> buildConflictGraph(const std::vector<Course>& courses) {
    int n = courses.size();
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (conflict(courses[i], courses[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
    return g;
}
