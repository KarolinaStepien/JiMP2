//
// Created by mwypych on 11.05.17.
//

#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <memory>
#include <set>
#include <vector>
#include <utility>
#include <map>
#include <ostream>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <StringUtility.h>
#include <Scheduler.h>

using ::academia::Schedule;
using ::academia::SchedulingItem;
using ::academia::Scheduler;
using ::academia::GreedyScheduler;
using ::academia::NoViableSolutionFound;

using ::std::unique_ptr;
using ::std::make_unique;
using ::std::vector;
using ::std::set;
using ::std::string;
using ::std::map;
using ::std::make_pair;
using ::std::ostream;
using ::std::accumulate;
using ::std::begin;
using ::std::end;
using ::std::pair;
using ::std::distance;
using ::std::find;

using ::testing::AssertionResult;
using ::testing::AssertionFailure;
using ::testing::AssertionSuccess;

class ScheduleTest : public ::testing::Test, MemLeakTest {
 public:
};

ostream &operator<<(ostream &out, const Schedule &schedule) {
  out << "schedule";
  return out;
}

ostream &operator<<(ostream &out, const vector<int> &v) {
  out << utility::ToString(v);
  return out;
}

vector<int> Map(const Schedule &schedule, int (*mapper)(const SchedulingItem &)) {
  std::vector<int> teachers;
  for (int i = 0; i < schedule.Size(); ++i) {
    teachers.push_back(mapper(schedule[i]));
  }
  return teachers;
}

vector<int> &Unique(vector<int> &v) {
  auto last = unique(begin(v),end(v));
  v.erase(last, end(v));
  return v;
}

vector<int> &Sorted(vector<int> &v) {
  sort(begin(v), end(v));
  return v;
}

vector<Schedule> Map(const Schedule &schedule, const vector<int> &ids, Schedule (*mapper)(const Schedule &s, int id)) {
  std::vector<Schedule> schedules;
  transform(begin(ids),
            end(ids),
            back_inserter(schedules),
            [&schedule, mapper](int id) { return mapper(schedule, id); });
  return schedules;
}

vector<int> Teachers(const Schedule &schedule) {
  auto v = Map(schedule, [](const auto &s) { return s.TeacherId(); });
  return Unique(Sorted(v));
}

vector<int> Rooms(const Schedule &schedule) {
  auto v = Map(schedule, [](const auto &s) { return s.RoomId(); });
  return Unique(Sorted(v));
}

vector<int> Years(const Schedule &schedule) {
  auto v = Map(schedule, [](const auto &s) { return s.Year(); });
  return Unique(Sorted(v));
}

vector<int> Courses(const Schedule &schedule) {
  auto v = Map(schedule, [](const auto &s) { return s.CourseId(); });
  return Sorted(v);
}

vector<Schedule> ToTeacherSchedule(const Schedule &schedule, const vector<int> &ids) {
  return Map(schedule, ids, [](const auto &s, int id) { return s.OfTeacher(id); });
}

vector<Schedule> ToRoomSchedule(const Schedule &schedule, const vector<int> &ids) {
  return Map(schedule, ids, [](const auto &s, int id) { return s.OfRoom(id); });
}

vector<Schedule> ToYearSchedule(const Schedule &schedule, const vector<int> &ids) {
  return Map(schedule, ids, [](const auto &s, int id) { return s.OfYear(id); });
}

bool IsScheduleCorrect(const Schedule &schedule) {
  auto time_slots = Map(schedule, [](const auto &s) { return s.TimeSlot(); });
  set<int> unique_slots{time_slots.begin(), time_slots.end()};
  return time_slots.size() == unique_slots.size();
}

int Id(vector<bool>::iterator &incorrect, vector<bool>::iterator end, const vector<int> &ids) {
  return ids[distance(incorrect, end)];
}

AssertionResult ValidSchedule(const string &, const Schedule &schedule) {
  auto teachers = Teachers(schedule);
  auto teachers_schedule = ToTeacherSchedule(schedule, teachers);
  vector<bool> correct_teacher_schedule;
  transform(begin(teachers_schedule),
            end(teachers_schedule),
            back_inserter(correct_teacher_schedule),
            IsScheduleCorrect);
  auto incorrect_teacher_founded = find(begin(correct_teacher_schedule), end(correct_teacher_schedule), false);
  if (incorrect_teacher_founded != end(correct_teacher_schedule)) {
    return AssertionFailure() << "Schedule violates constraint: Teacher("
                              << Id(incorrect_teacher_founded, end(correct_teacher_schedule), teachers)
                              << ") is in the same time slot in two SchedulingItems";
  }
  auto rooms = Rooms(schedule);
  auto rooms_schedule = ToRoomSchedule(schedule, rooms);
  vector<bool> correct_room_schedule;
  transform(begin(rooms_schedule), end(rooms_schedule), back_inserter(correct_room_schedule), IsScheduleCorrect);
  auto incorrect_room_founded = std::find(begin(correct_room_schedule), end(correct_room_schedule), false);
  if (incorrect_room_founded != end(correct_room_schedule)) {
    return AssertionFailure() << "Schedule violates constraint: Room("
                              << Id(incorrect_room_founded, end(correct_room_schedule), rooms)
                              << ") is in the same time slot in two SchedulingItems";
  }
  auto years = Years(schedule);
  auto years_schedule = ToYearSchedule(schedule, years);
  vector<bool> correct_year_schedule;
  transform(begin(years_schedule), end(years_schedule), back_inserter(correct_year_schedule), IsScheduleCorrect);
  auto incorrect_year_founded = std::find(begin(correct_year_schedule), end(correct_year_schedule), false);
  if (incorrect_year_founded != end(correct_year_schedule)) {
    return AssertionFailure() << "Schedule violates constraint: Year("
                              << Id(incorrect_year_founded, end(correct_year_schedule), years)
                              << ") is in the same time slot in two SchedulingItems";
  }
  return AssertionSuccess();
}

AssertionResult HasAllTeachers(const string &, const string &, const Schedule &schedule, std::vector<int> expected) {
  auto teachers = Teachers(schedule);
  if (Sorted(expected)  == teachers) {
    return AssertionSuccess();
  }
  return AssertionFailure() << "Different teachers expected: " << utility::ToString(expected) << " but was: "
                            << utility::ToString(teachers);
}

AssertionResult HasAllRooms(const string &, const string &, const Schedule &schedule, std::vector<int> expected) {
  auto rooms = Rooms(schedule);
  if (Sorted(expected)  == rooms) {
    return AssertionSuccess();
  }
  return AssertionFailure() << "Different rooms expected" << expected << " but was: "
                            << rooms;
}

AssertionResult HasAllYears(const string &, const string &, const Schedule &schedule, std::vector<int> expected) {
  auto rooms = Years(schedule);
  if (Sorted(expected) == rooms) {
    return AssertionSuccess();
  }
  return AssertionFailure() << "Different rooms years" << expected << " but was: "
                            << rooms;
}

AssertionResult HasAllCourses(const string &, const string &, const Schedule &schedule, std::vector<int> expected) {
  auto courses = Courses(schedule);
  if (Sorted(expected)  == courses) {
    return AssertionSuccess();
  }
  return AssertionFailure() << "Different courses years" << expected << " but was: "
                            << courses;
}

TEST_F(ScheduleTest, SchedulerThrowsNoViableSolutionFoundWhenItIsImpossibleToFindSolution) {
  unique_ptr<Scheduler> scheduler = make_unique<GreedyScheduler>();

  vector<int> rooms{1000};
  map<int, vector<int>> teachers{make_pair(10, vector<int> {100, 200})};
  map<int, set<int>> years{make_pair(1, set<int> {100, 200})};

  EXPECT_THROW(scheduler->PrepareNewSchedule(rooms, teachers, years, 1), NoViableSolutionFound);
}

TEST_F(ScheduleTest, SchedulerCreatesScheduleOfSingleYear) {
  unique_ptr<Scheduler> scheduler = make_unique<GreedyScheduler>();

  vector<int> rooms{1000};
  map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 20}), make_pair(200, vector<int>{30}),
                                 make_pair(300, vector<int> {40})};
  map<int, set<int>> years{make_pair(1, set<int>{10, 20}), make_pair(2, set<int>{30, 40})};

  Schedule schedule;
  EXPECT_NO_THROW(schedule = scheduler->PrepareNewSchedule(rooms, teachers, years, 10));

  EXPECT_PRED_FORMAT1(ValidSchedule, schedule);
  vector<int> expected_teachers{100, 200, 300};
  EXPECT_PRED_FORMAT2(HasAllTeachers, schedule, expected_teachers);
  vector<int> expected_rooms{1000};
  EXPECT_PRED_FORMAT2(HasAllRooms, schedule, expected_rooms);
  vector<int> expected_years{1, 2};
  EXPECT_PRED_FORMAT2(HasAllYears, schedule, expected_years);
  vector<int> expected_courses{10, 20, 30, 40};
  EXPECT_PRED_FORMAT2(HasAllCourses, schedule, expected_courses);

}

TEST_F(ScheduleTest, SchedulerCreatesFullSchedule) {
  unique_ptr<Scheduler> scheduler = make_unique<GreedyScheduler>();

  vector<int> rooms{1000,2000,3000};
  map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 20}),
                                 make_pair(200, vector<int>{11, 21, 30, 40}),
                                 make_pair(300, vector<int> {32}),
                                 make_pair(400, vector<int> {42, 50, 60, 53, 54}),
                                 make_pair(500, vector<int> {77, 79, 90}),
                                 make_pair(600, vector<int> {70, 80, 91, 92, 93})};
  map<int, set<int>> years{make_pair(1, set<int>{10, 20, 11, 21}),
                           make_pair(2, set<int>{30, 40, 32, 42}),
                           make_pair(3, set<int>{50, 60, 53, 54}),
                           make_pair(4, set<int>{70, 80, 77, 79}),
                           make_pair(5, set<int>{90, 91, 92, 93})};

  Schedule schedule;
  EXPECT_NO_THROW(schedule = scheduler->PrepareNewSchedule(rooms, teachers, years, 7));

  EXPECT_PRED_FORMAT1(ValidSchedule, schedule);
  vector<int> expected_teachers{100, 200, 300, 400, 500, 600};
  EXPECT_PRED_FORMAT2(HasAllTeachers, schedule, expected_teachers);
  vector<int> expected_rooms{1000, 2000, 3000};
  EXPECT_PRED_FORMAT2(HasAllRooms, schedule, expected_rooms);
  vector<int> expected_years{1, 2, 3, 4, 5};
  EXPECT_PRED_FORMAT2(HasAllYears, schedule, expected_years);
  vector<int> expected_courses{10, 20,11, 21, 30, 40,32,42, 50, 60, 53, 54,77, 79, 90,70, 80, 91, 92, 93};
  EXPECT_PRED_FORMAT2(HasAllCourses, schedule, expected_courses);

}

TEST_F(ScheduleTest, SchedulerCreatesScheduleOfSingleCourseWithSeveralGroupsButShortOfSlotsThrowsExcpetion) {
  unique_ptr<Scheduler> scheduler = make_unique<GreedyScheduler>();

  vector<int> rooms{1000, 2000};
  map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 10, 10}), make_pair(200, vector<int>{10, 10})};
  map<int, set<int>> years{make_pair(1, set<int>{10})};

  Schedule schedule;
  EXPECT_THROW(schedule = scheduler->PrepareNewSchedule(rooms, teachers, years, 3), NoViableSolutionFound);
}

TEST_F(ScheduleTest, SchedulerCreatesScheduleOfSingleCourseWithSeveralGroups) {
  unique_ptr<Scheduler> scheduler = make_unique<GreedyScheduler>();

  vector<int> rooms{1000};
  map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 10, 10}), make_pair(200, vector<int>{10, 10})};
  map<int, set<int>> years{make_pair(1, set<int>{10})};

  Schedule schedule;
  EXPECT_NO_THROW(schedule = scheduler->PrepareNewSchedule(rooms, teachers, years, 5));

  EXPECT_PRED_FORMAT1(ValidSchedule, schedule);
  vector<int> expected_teachers{100, 200};
  EXPECT_PRED_FORMAT2(HasAllTeachers, schedule, expected_teachers);
  vector<int> expected_rooms{1000};
  EXPECT_PRED_FORMAT2(HasAllRooms, schedule, expected_rooms);
  vector<int> expected_years{1};
  EXPECT_PRED_FORMAT2(HasAllYears, schedule, expected_years);
  vector<int> expected_courses{10, 10, 10, 10, 10};
  EXPECT_PRED_FORMAT2(HasAllCourses, schedule, expected_courses);
}

