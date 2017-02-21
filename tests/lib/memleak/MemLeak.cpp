//
// Created by mwypych on 21.02.17.
//
#include "MemLeak.h"
#include <iostream>
#include <algorithm>
#include <regex>

void *operator new(std::size_t n) {
  void *memory = malloc(n);
  MemLeak::Instance().Malloc(memory, n);
  return memory;
}

void operator delete(void *p) throw() {
  MemLeak::Instance().Free(p);
  free(p);
}

void *operator new[](std::size_t n) {
  void *memory = malloc(n);
  MemLeak::Instance().MallocArray(memory, n);
  return memory;
}

void operator delete[](void *p) throw() {
  MemLeak::Instance().FreeArray(p);
  free(p);
}

MemLeak &MemLeak::Instance() {
  return instance_;
}

MemLeak MemLeak::instance_{};
unsigned int MemLeak::recording_ = 0;
unsigned int MemLeak::internal_allocation_ = 0;

void MemLeak::StartRecording() {
  recording_++;
}

void MemLeak::StopRecording() {
  recording_--;
}

bool MemLeak::IsRecording() {
  return recording_ > 0 && internal_allocation_ <= 1;
}

void MemLeak::Malloc(void *memory, size_t size) {
  if (!IsRecording()) {
    return;
  }
  StartInternalAllocation();
  InsertEntry(memory, size);
  StopInternalAllocation();
}

void MemLeak::Free(void *memory) {
  if (!IsRecording()) {
    return;
  }
  StartInternalAllocation();
  RemoveEntry(memory);
  StopInternalAllocation();
}

void MemLeak::MallocArray(void *memory, size_t size) {
  if (!IsRecording()) {
    return;
  }
  StartInternalAllocation();
  InsertArrayEntry(memory, size);
  StopInternalAllocation();
}

void MemLeak::FreeArray(void *memory) {
  if (!IsRecording()) {
    return;
  }
  StartInternalAllocation();
  RemoveArrayEntry(memory);
  StopInternalAllocation();
}

void MemLeak::StartInternalAllocation() {
  internal_allocation_++;
}

void MemLeak::StopInternalAllocation() {
  internal_allocation_--;
}

void MemLeak::RemoveArrayEntry(void *pVoid) {
  auto entry = entries.find(pVoid);
  if (entry == entries.end()) {

  } else {
    entries.erase(entry);
  }
}

void MemLeak::InsertEntry(void *pVoid, size_t size) {
  auto entry = entries.find(pVoid);
  if (entry == entries.end()) {
    entries.emplace_hint(entry, std::pair<void *, MemoryEntry>(pVoid, {pVoid, size}));
  } else {

  }
}

void MemLeak::RemoveEntry(void *pVoid) {
  auto entry = entries.find(pVoid);
  if (entry == entries.end()) {

  } else {
    entries.erase(entry);
  }
}

void MemLeak::InsertArrayEntry(void *pVoid, size_t size) {
  auto entry = entries.find(pVoid);
  if (entry == entries.end()) {
    entries.emplace_hint(entry, std::pair<void *, MemoryEntry>(pVoid, {pVoid, size}));
  } else {

  }
}

void MemLeak::ClearState() {
  entries.clear();
}

bool MemLeak::Verify() const {
  return entries.size() == 0;
}

MemLeak::IssuesList MemLeak::Issues() {
  IssuesList result;
  std::transform(
      begin(entries),
      end(entries),
      std::back_inserter(result),
      [](const auto &pair) {
        return pair.second.Message("memory allocated at {PTR} of size {SIZE} was not properly freed");
      });
  return result;
}

MemoryEntry::MemoryEntry(const void *memory, const size_t size)
    : memory(memory), size(size) {}

std::string MemoryEntry::Message(std::string pattern) const {
  std::string tmp = std::regex_replace(pattern, std::regex {R"(\{PTR\})"}, ToString(memory));
  std::string result = std::regex_replace(tmp, std::regex {R"(\{SIZE\})"}, ToString(size));
  return result;
}

std::string MemoryEntry::ToString(const void *address) const {
  std::stringstream ss;
  ss << address;
  return ss.str();
}

std::string MemoryEntry::ToString(size_t size) const {
  return std::to_string(size);
}

