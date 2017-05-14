//
// Created by mwypych on 21.02.17.
//

#ifndef JIMP_EXERCISES_MEMLEAKTEST_H
#define JIMP_EXERCISES_MEMLEAKTEST_H

class MemLeakTest {
 public:
  MemLeakTest();
  virtual ~MemLeakTest();
  virtual void StopRecording();
  virtual void ResumeRecording();
};
#endif //JIMP_EXERCISES_MEMLEAKTEST_H
