//
// Created by zosia on 03.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>

using namespace std;
namespace pool {
    class TextPool {

        set<string> basen;

    public:
        TextPool() = default;

        TextPool(initializer_list<string> basen);

        TextPool(TextPool &&nowy);

        TextPool &operator=(TextPool &&nowy);

        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    };

}
#endif //JIMP_EXERCISES_TEXTPOOL_H
