//
// Created by Admin on 2017-06-10.
//

#include "Scheduler.h"

academia::SchedulingItem::SchedulingItem(int course_, int teacher_, int room_, int time_, int year_){
    course_id = course_;
    teacher_id = teacher_;
    room_id = room_;
    time_slot = time_;
    year = year_;
}

int academia::SchedulingItem::CourseId() const {
    return course_id;
}

int academia::SchedulingItem::TeacherId() const {
    return teacher_id;
}

int academia::SchedulingItem::RoomId() const {
    return room_id;
}

int academia::SchedulingItem::TimeSlot() const{
    return time_slot;
}

int academia::SchedulingItem::Year() const {
    return year;
}

academia::Schedule::Schedule(std::vector<academia::SchedulingItem> item_v) {
    for(auto &&item : item_v){
        InsertScheduleItem(item);
    }
}

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule st;

    for(int i=0; i<items.size(), i++){
        if(teacher_id == items[i].teacher_id){
            st.items.emplace_back(items[i]);
        }
    }
    return st;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule sr;

    for(int i=0; i<items.size(), i++){
        if(room_id == items[i].room_id){
            sr.items.emplace_back(items[i]);
        }
    }
    return sr;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule sy;

    for(int i=0; i<items.size(), i++){
        if(year == items[i].year){
            sy.items.emplace_back(items[i]);
        }
    }
    return sy;
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector<int> n_slots;
    std::vector<int> free_slots;
    for(int i=0; i<n_time_slots; i++){
        n_slots.emplace_back(i+1);
    }
    std::set_difference(n_slots.begin(), n_slots.end(),
                        taken_time_slots.begin(), taken_time_slots.end(),
                        std::inserter(free_slots, free_slots.begin()));
    return free_slots;
}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    SchedulingItem element = item;
    taken_time_slots.emplace_back(element.time_slot);
    items.emplace_back(element);
}

size_t academia::Schedule::Size() const {
    return items.size();
}

academia::SchedulingItem academia::Schedule::operator[](int iter) const {
    return items[iter];
}

academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                                 int n_time_slots) {
    return academia::Schedule();
}
