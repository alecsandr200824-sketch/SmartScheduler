#pragma once
#ifndef LOADER_H
#define LOADER_H

#include "core.h"

std::vector<Teacher> loadTeachers(const std::string& file);
std::vector<Group> loadGroups(const std::string& file);
std::vector<Course> loadCourses(const std::string& file);
std::vector<Room> loadRooms(const std::string& file);

#endif
