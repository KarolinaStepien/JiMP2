//
// Created by zosiek on 11.06.17.
//

#include "TeacherHash.h"
namespace academia{

    TeacherId::operator int() const {
        return id_;
    }
    TeacherId Teacher::Id() const {
        return id_;
    }

    int Teacher::IntId() const {
        return id_;
    }

    string Teacher::Name() const {
        return name_;
    }
    string Teacher::Department() const {
        return department_;
    }


    bool operator==(const Teacher &teacher1, const Teacher &teacher2) {
        return teacher1.Department() == teacher2.Department() && teacher1.IntId() == teacher2.IntId() && teacher1.Name() == teacher2.Name();
    }

    bool operator!=(const Teacher &teacher1, const Teacher &teacher2) {
        return teacher1.Department() != teacher2.Department() || teacher1.IntId() != teacher2.IntId() || teacher1.Name() != teacher2.Name();
    }

    size_t TeacherHash::operator()(const Teacher &teacher) const {
        size_t h1 = hash<string>{}(teacher.Name());
        size_t h2 = hash<string>{}(teacher.Department());
        return (size_t) (teacher.Id() * h1 + h2);
    }
}
