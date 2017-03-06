//
// Created by mwypych on 21.02.17.
//

#ifndef JIMP_EXERCISES_MEMLEAK_H
#define JIMP_EXERCISES_MEMLEAK_H

#include <new>
#include <map>
#include <vector>
#include <string>

class MemoryEntry {
 public:
  const void *memory;
  const size_t size;
  MemoryEntry(const void *memory, const size_t size);

  std::string Message(std::string pattern) const;
  std::string ToString(const void *pVoid) const;
  std::string ToString(size_t size) const;

  MemoryEntry operator=(const MemoryEntry &entry) const {
    return MemoryEntry(entry.memory, entry.size);
  }
};

class MemLeak {
 public:
  static MemLeak &Instance();
//  static void Initialize();

  static void StartRecording();
  static void StopRecording();
  static bool IsRecording();

  void Malloc(void *memory, size_t size);
  void Free(void *memory);
  void MallocArray(void *memory, size_t size);
  void FreeArray(void *memory);

  using IssuesList = std::vector<std::string>;

  bool Verify() const;
  IssuesList Issues();
  void ClearState();

 private:
  static unsigned int recording_;
  static unsigned int internal_allocation_;
  static MemLeak instance_;
  std::map<void *, MemoryEntry> entries;

  static void StartInternalAllocation();
  static void StopInternalAllocation();
  void RemoveArrayEntry(void *pVoid);
  void InsertEntry(void *pVoid, size_t size);
  void RemoveEntry(void *pVoid);
  void InsertArrayEntry(void *pVoid, size_t size);
};

void *operator new(std::size_t n) throw(std::bad_alloc);
void operator delete(void *p) noexcept;
void *operator new[](std::size_t n) throw(std::bad_alloc);
void operator delete[](void *p) noexcept;

#endif //JIMP_EXERCISES_MEMLEAK_H
