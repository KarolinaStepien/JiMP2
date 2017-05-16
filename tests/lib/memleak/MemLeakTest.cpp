//
// Created by mwypych on 21.02.17.
//

#include "MemLeak.h"
#include "MemLeakTest.h"
#include <gtest/gtest.h>
#include <string>
#include <sstream>

MemLeakTest::MemLeakTest() {
  MemLeak::StartRecording();
}

MemLeakTest::~MemLeakTest() {
  MemLeak::StopRecording();
  bool verification = MemLeak::Instance().Verify();
  std::string message;
  if (!verification) {
    auto issues = MemLeak::Instance().Issues();
    std::stringstream ss;
    ss << "There were discoverd " << issues.size() << " number of memory leakage: " << std::endl;
    for (const auto &str : issues) {
      ss << str << std::endl;
    }
    message = ss.str();
  }
  MemLeak::Instance().ClearState();
  EXPECT_TRUE(verification) << message;
}

void MemLeakTest::StopRecording() {
  MemLeak::Instance().StopRecording();
}
void MemLeakTest::ResumeRecording() {
  MemLeak::Instance().StartRecording();
}
