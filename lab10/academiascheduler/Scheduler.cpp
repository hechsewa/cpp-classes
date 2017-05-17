//
// Created by hushmans on 17.05.17.
//

#include "Scheduler.h"

using namespace std;

academia::NoViableSolutionFound::NoViableSolutionFound(const string &__arg) : runtime_error(__arg) {
}

/********SCHEDULE************/

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule schedule;
    std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(schedule.schedule_),
                 [teacher_id](const SchedulingItem &compare){return compare.TeacherId()==teacher_id;});
    return schedule;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule room;
    std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(room.schedule_), [room_id](const SchedulingItem &compare){return compare.RoomId()==room_id;});
    return room;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule years;
    std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(years.schedule_), [year](const SchedulingItem &compare){return compare.Year()==year;});
    return years;
}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    return schedule_.push_back(item);
}

size_t academia::Schedule::Size() const {
    return schedule_.size();
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int time_slots) const {
    std::vector<int> out;
    for (int i=1; i<time_slots+1; ++i){
        if(!std::any_of(schedule_.begin(), schedule_.end(), [&i](const SchedulingItem &itg){return i==itg.TimeSlot();})){
            out.push_back(i);
        }
    }
    return out;
}

const academia::SchedulingItem &academia::Schedule::operator[](const int &intg) const {
    return this->schedule_[intg];
}

bool academia::Schedule::CheckTime(const int &intg) const {
    return std::any_of(schedule_.begin(), schedule_.end(), [&intg](const SchedulingItem &in){return intg==in.TimeSlot();});
}

/**********************SCHEDULING ITEM***************************/

academia::SchedulingItem::SchedulingItem(int course_id_, int teacher_id_, int room_id_, int time_slot_, int year_):
        course_id_(course_id_), teacher_id_(teacher_id_), room_id_(room_id_), time_slot_(time_slot_), year_(year_) {
}

int academia::SchedulingItem::CourseId() const {
    return course_id_;
}

int academia::SchedulingItem::TeacherId() const {
    return teacher_id_;
}

int academia::SchedulingItem::RoomId() const {
    return room_id_;
}

int academia::SchedulingItem::TimeSlot() const {
    return time_slot_;
}

int academia::SchedulingItem::Year() const {
    return year_;
}
