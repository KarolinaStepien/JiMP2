//
// Created by mwypych on 11.05.17.
//

#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <Scheduler.h>

using ::academia::Schedule;
using ::academia::SchedulingItem;

class ScheduleTest : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(ScheduleTest, ScheduleInsertSchedulingItemReturnScheduleOfFirstTeacherWithSingleItem) {
  Schedule schedule;
  schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
  schedule.InsertScheduleItem(SchedulingItem {5, 6, 7, 8, 9});

  const Schedule &firstTeacherSchedule = schedule.OfTeacher(1);

  EXPECT_EQ(1, firstTeacherSchedule.Size());
  EXPECT_EQ(0, firstTeacherSchedule[0].CourseId());
  EXPECT_EQ(1, firstTeacherSchedule[0].TeacherId());
  EXPECT_EQ(2, firstTeacherSchedule[0].RoomId());
  EXPECT_EQ(3, firstTeacherSchedule[0].TimeSlot());
  EXPECT_EQ(4, firstTeacherSchedule[0].Year());
}

TEST_F(ScheduleTest, ScheduleInsertSchedulingItemReturnScheduleOfFirstTeacherWith3Items) {
  Schedule schedule;
  schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
  schedule.InsertScheduleItem(SchedulingItem {5, 33, 7, 8, 9});
  schedule.InsertScheduleItem(SchedulingItem {10, 1, 12, 13, 14});
  schedule.InsertScheduleItem(SchedulingItem {15, 1, 17, 18, 19});
  schedule.InsertScheduleItem(SchedulingItem {35, 35, 37, 38, 39});

  const Schedule &firstTeacherSchedule = schedule.OfTeacher(1);

  EXPECT_EQ(3, firstTeacherSchedule.Size());
  EXPECT_EQ(0, firstTeacherSchedule[0].CourseId());
  EXPECT_EQ(1, firstTeacherSchedule[0].TeacherId());
  EXPECT_EQ(2, firstTeacherSchedule[0].RoomId());
  EXPECT_EQ(3, firstTeacherSchedule[0].TimeSlot());
  EXPECT_EQ(4, firstTeacherSchedule[0].Year());

  EXPECT_EQ(10, firstTeacherSchedule[1].CourseId());
  EXPECT_EQ(1, firstTeacherSchedule[1].TeacherId());
  EXPECT_EQ(12, firstTeacherSchedule[1].RoomId());
  EXPECT_EQ(13, firstTeacherSchedule[1].TimeSlot());
  EXPECT_EQ(14, firstTeacherSchedule[1].Year());

  EXPECT_EQ(15, firstTeacherSchedule[2].CourseId());
  EXPECT_EQ(1, firstTeacherSchedule[2].TeacherId());
  EXPECT_EQ(17, firstTeacherSchedule[2].RoomId());
  EXPECT_EQ(18, firstTeacherSchedule[2].TimeSlot());
  EXPECT_EQ(19, firstTeacherSchedule[2].Year());
}

TEST_F(ScheduleTest, ScheduleInsertSchedulingItemReturnScheduleOfSeventhRoomWith2Items) {
  Schedule schedule;
  schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
  schedule.InsertScheduleItem(SchedulingItem {5, 33, 7, 8, 9});
  schedule.InsertScheduleItem(SchedulingItem {10, 1, 12, 13, 14});
  schedule.InsertScheduleItem(SchedulingItem {15, 4, 7, 18, 19});
  schedule.InsertScheduleItem(SchedulingItem {35, 35, 37, 38, 39});

  const Schedule &seventhRoomSchedule = schedule.OfRoom(7);

  EXPECT_EQ(2, seventhRoomSchedule.Size());
  EXPECT_EQ(5, seventhRoomSchedule[0].CourseId());
  EXPECT_EQ(33, seventhRoomSchedule[0].TeacherId());
  EXPECT_EQ(7, seventhRoomSchedule[0].RoomId());
  EXPECT_EQ(8, seventhRoomSchedule[0].TimeSlot());
  EXPECT_EQ(9, seventhRoomSchedule[0].Year());

  EXPECT_EQ(15, seventhRoomSchedule[1].CourseId());
  EXPECT_EQ(4, seventhRoomSchedule[1].TeacherId());
  EXPECT_EQ(7, seventhRoomSchedule[1].RoomId());
  EXPECT_EQ(18, seventhRoomSchedule[1].TimeSlot());
  EXPECT_EQ(19, seventhRoomSchedule[1].Year());

}

TEST_F(ScheduleTest, ScheduleInsertSchedulingItemReturnScheduleOfSecondYearWith2Items) {
  Schedule schedule;
  schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
  schedule.InsertScheduleItem(SchedulingItem {5, 33, 7, 8, 2});
  schedule.InsertScheduleItem(SchedulingItem {10, 1, 12, 13, 1});
  schedule.InsertScheduleItem(SchedulingItem {15, 4, 7, 18, 2});
  schedule.InsertScheduleItem(SchedulingItem {35, 35, 37, 38, 1});

  const Schedule &seventhRoomSchedule = schedule.OfYear(2);

  EXPECT_EQ(2, seventhRoomSchedule.Size());
  EXPECT_EQ(5, seventhRoomSchedule[0].CourseId());
  EXPECT_EQ(33, seventhRoomSchedule[0].TeacherId());
  EXPECT_EQ(7, seventhRoomSchedule[0].RoomId());
  EXPECT_EQ(8, seventhRoomSchedule[0].TimeSlot());
  EXPECT_EQ(2, seventhRoomSchedule[0].Year());

  EXPECT_EQ(15, seventhRoomSchedule[1].CourseId());
  EXPECT_EQ(4, seventhRoomSchedule[1].TeacherId());
  EXPECT_EQ(7, seventhRoomSchedule[1].RoomId());
  EXPECT_EQ(18, seventhRoomSchedule[1].TimeSlot());
  EXPECT_EQ(2, seventhRoomSchedule[1].Year());

}

TEST_F(ScheduleTest, ScheduleCheckAvailability) {
  Schedule schedule;
  schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
  schedule.InsertScheduleItem(SchedulingItem {5, 33, 7, 5, 2});
  schedule.InsertScheduleItem(SchedulingItem {10, 1, 12, 8, 1});
  schedule.InsertScheduleItem(SchedulingItem {15, 4, 7, 8, 2});
  schedule.InsertScheduleItem(SchedulingItem {35, 35, 37, 9, 1});

  std::vector<int> availability = schedule.AvailableTimeSlots(10);
  std::sort(availability.begin(), availability.end());
  const std::vector<int> expected{1, 2, 4, 6, 7, 10};
  EXPECT_EQ(expected, availability);

}

TEST_F(ScheduleTest, ScheduleCheckAvailabilityOfEmptySchedule) {
  Schedule schedule;
  std::vector<int> availability = schedule.AvailableTimeSlots(5);
  std::sort(availability.begin(), availability.end());
  const std::vector<int> expected{1, 2, 3, 4, 5};
  EXPECT_EQ(expected, availability);
}


