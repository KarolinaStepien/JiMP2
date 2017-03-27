//
// Created by mwypych on 24.02.17.
//

#ifndef JIMP_EXERCISES_STRINGUTILITY_H
#define JIMP_EXERCISES_STRINGUTILITY_H

#include <string>
#include <sstream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <iterator>

namespace utility {

//template <typename T>
//std::string ToString(std::vector<T> v);
//
//template <typename T>
//std::string ToString(T t);

template<typename T>
std::string ToString(T t) {
  return std::to_string(t);
}

template<typename T>
std::string ToString(const std::vector<T> &v) {
  std::vector<std::string> tmp;
  std::stringstream ss;
  ss << "[";
  std::transform(begin(v), end(v), std::back_inserter(tmp), [](const auto &str) { return ToString(str); });
  std::copy(begin(tmp), end(tmp), std::ostream_iterator<std::string>(ss, ", "));
  ss << "]";
  return ss.str();
}

template<typename T>
T FromString(const std::string &value) {
  T v{};
  std::istringstream ss(value);
  ss >> v;
  return v;
}


};

#endif //JIMP_EXERCISES_STRINGUTILITY_H
