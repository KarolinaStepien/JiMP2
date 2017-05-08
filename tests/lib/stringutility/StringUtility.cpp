//
// Created by mwypych on 24.02.17.
//

#include "StringUtility.h"

namespace utility {
bool MatchesUpToExtraNewLine(const std::string &expected, const std::string &result) {
  if (result == expected) {
    return true;
  }
  const std::string &expected_result = expected+"\n";
  return result == expected_result;
}
}