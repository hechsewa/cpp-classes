//
// Created by hushmans on 17.05.17.
//

#include "Scheduler.h"

using namespace std;

namespace academia {

    NoViableSolutionFound::NoViableSolutionFound(const string &message) : runtime_error(message) {
    }

/********SCHEDULE************/

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule schedule;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(schedule.schedule_),
                     [teacher_id](const SchedulingItem &item) { return item.TeacherId() == teacher_id; });
        return schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule room;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(room.schedule_),
                     [room_id](const SchedulingItem &compare) { return compare.RoomId() == room_id; });
        return room;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule years;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(years.schedule_),
                     [year](const SchedulingItem &compare) { return compare.Year() == year; });
        return years;
    }

    void Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
        return schedule_.push_back(item);
    }

    size_t Schedule::Size() const {
        return schedule_.size();
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> out;
        for (int i = 1; i <= n_time_slots; ++i) {
            if (!std::any_of(schedule_.begin(), schedule_.end(),
                             [i](const SchedulingItem &item) { return i == item.TimeSlot(); })) {
                out.push_back(i);
            }
        }
        return out;
    }

    const SchedulingItem & academia::Schedule::operator[](int index) const {
        return this->schedule_[index];
    }

    bool Schedule::CheckTime(const int &intg) const {
        return std::any_of(schedule_.begin(), schedule_.end(),
                           [&intg](const SchedulingItem &in) { return intg == in.TimeSlot(); });
    }

/**********************SCHEDULING ITEM***************************/

    SchedulingItem::SchedulingItem(int course_id_, int teacher_id_, int room_id_, int time_slot_, int year_) :
            course_id_(course_id_), teacher_id_(teacher_id_), room_id_(room_id_), time_slot_(time_slot_), year_(year_) {
    }

    int SchedulingItem::CourseId() const {
        return course_id_;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId() const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }

/*************** GREEDY SCHEDULER *****************/

/*academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                                 int n_time_slots) {
    Schedule greedy;

}*/
}