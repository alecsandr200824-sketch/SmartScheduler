#include "loader.h"
#include <fstream>
#include <sstream>

std::vector<std::string> split(const std::string& s, char d) {
    std::vector<std::string> r;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, d)) r.push_back(item);
    return r;
}

std::vector<Teacher> loadTeachers(const std::string& file) {
    std::ifstream in(file);
    std::vector<Teacher> v;
    std::string line;
    getline(in, line);

    while (getline(in, line)) {
        auto p = split(line, ',');
        Teacher t;
        t.id = stoi(p[0]);
        t.name = p[1];
        t.max_hours_per_day = stoi(p[2]);
        auto days = split(p[3], ';');
        for (auto& d : days) t.preferred_days[stoi(d)] = true;
        v.push_back(t);
    }
    return v;
}
