#pragma once
#include "exporter.h"
#include <iostream>

void printSchedule(const Schedule& s) {
    std::cout << "\n=== ÐÀÑÏÈÑÀÍÈÅ ===\n";
    for (auto& l : s.lessons)
        std::cout << "Äåíü " << l.day
        << " Ñëîò " << l.slot
        << " Êóðñ " << l.course_id
        << " Ïðåïîä " << l.teacher_id
        << " Àóä " << l.room_id << "\n";
}
