#include "scheduler.h"

bool canPlace(int d, int s, Teacher& t, Room& r, std::vector<Group*>& gs) {
    if (t.busy[d][s] || r.busy[d][s]) return false;
    for (auto g : gs)
        if (g->busy[d][s]) return false;
    return true;
}

Schedule buildSchedule(
    std::vector<Course>& courses,
    std::unordered_map<int, Teacher>& teachers,
    std::unordered_map<int, Group>& groups,
    std::vector<Room>& rooms
) {
    Schedule sched;

    for (auto& c : courses) {
        Teacher& t = teachers[c.teacher_id];
        std::vector<Group*> gs;

        for (int id : c.group_ids)
            gs.push_back(&groups[id]);

        int placed = 0;
        for (int d = 0; d < DAYS && placed < c.hours_per_week; d++) {
            for (int s = 0; s < SLOTS && placed < c.hours_per_week; s++) {
                for (auto& r : rooms) {
                    if (r.type == c.room_type && canPlace(d, s, t, r, gs)) {
                        t.busy[d][s] = true;
                        r.busy[d][s] = true;
                        for (auto g : gs) g->busy[d][s] = true;

                        sched.lessons.push_back({
                            d, s, c.id, t.id, r.id, c.group_ids
                            });

                        sched.fitness += t.preferred_days[d] ? 10 : 5;
                        placed++;
                        break;
                    }
                }
            }
        }
    }
    return sched;
}
