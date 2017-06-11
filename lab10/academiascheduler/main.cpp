//
// Created by Admin on 2017-06-10.
//

#include "Scheduler.h"

using namespace academia;

int main(){
    Schedule schedule;
    schedule.InsertScheduleItem(SchedulingItem {1,2,3,4,5});
    schedule.InsertScheduleItem(SchedulingItem {1,1,3,4,5});
    schedule.InsertScheduleItem(SchedulingItem {1,2,3,4,6});
    
    return 0;
}