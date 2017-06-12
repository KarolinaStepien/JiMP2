//
// Created by zosiek on 11.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H
#include <string>
#include <unordered_map>

using namespace std;
namespace academia{
    class TeacherId{
        int id_;
    public:
        TeacherId(int id) : id_{id}{};
        operator int() const;
    };

    class Teacher{
        TeacherId id_;
        string name_, department_;
    public:
        Teacher(TeacherId id, string name, string department): id_{id}, name_{name}, department_{department} {};
        int IntId() const;
        string Name()const;
        string Department ()const;
        TeacherId Id ()const;
    };

    bool operator == (const Teacher &teacher1, const Teacher &teacher2);
    bool operator != (const Teacher &teacher1, const Teacher &teacher2);

    class TeacherHash{
    public:
        size_t operator () (const Teacher &teacher) const;
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
