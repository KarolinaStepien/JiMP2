//
// Created by Admin on 2017-06-10.
//

#ifndef JIMP_EXERCISES_ACADEMIASCHEDULER_H
#define JIMP_EXERCISES_ACADEMIASCHEDULER_H

//#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
//#include <string>

namespace academia {

    class SchedulingItem { //pojedynczy element harmonogramu, obiekt wartości
    public:
        SchedulingItem(int course_, int teacher_, int room_, int time_, int year_);
        ~SchedulingItem(){};
        friend class Schedule;

        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;

    private:
        int course_id; //identyfikator kursu
        int teacher_id; //identyfikator nauczyciela
        int room_id; //identyfikator pomieszczenia
        int time_slot; //okno czasowe np 1 ⇒ pon 8:00-10:00
        int year; //rok studiów na którym obowiązuje przedmiot
    };

    class Schedule { //cały harmonogram
    public:
        Schedule () {};
        ~Schedule() {};
        Schedule (std::vector <SchedulingItem> item_v);

        Schedule OfTeacher(int teacher_id) const; //wylicza fragment harmonogramu związany z danym nauczycielem
        Schedule OfRoom(int room_id) const; // -||- z danym pomieszczeniem
        Schedule OfYear(int year) const; // -||- dla danego roku studiów
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;  //wylicza wektor jeszcze nie zajętych okien czasowych,
        // gdzie n_time_slots jest maksymalną wartością okna czasowego
        void InsertScheduleItem(const SchedulingItem &item); //wstawia nowy element planu
        size_t Size() const; //zwraca rozmiar planu

        SchedulingItem operator[](int iter) const;

    private:
        std::vector<SchedulingItem> items;
        std::vector<int> taken_time_slots;
    };

    class Scheduler { //interfejs czysto abstrakcyjny stanowiący kontrakt między nami a zespołem
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) =0;
        /*rooms - dostępne pomieszczenia
        teacher_courses_assignment - rozpiska nauczycieli (klucz w mapie) i prowadząnych przez nich przedmiotów (wartosć w mapie)
        courses_of_year - kursy (wartość w mapie) wymagane dla danego rocznika (klucz w mapie)
        n_time_slots - ilość slotów czasowych*/
    };

    class NoViableSolutionFound {}; //wyjątek wyrzucany, gdy nie udaje się stworzyć planu

    class GreedyScheduler : public Scheduler { //pętla która próbuje przypisywać po kolei przedmioty do sal i nauczycieli
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };

}
#endif //JIMP_EXERCISES_ACADEMIASCHEDULER_H
