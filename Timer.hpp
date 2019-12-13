//#pragma once
#ifndef __TIMER_CPP__
#define __TIMER_CPP__

#include <stdint.h>
#include <stdio.h>
#include <chrono>

#define TIMER_START(NS)                                  \
  std::chrono::system_clock::time_point time_start##NS = \
      std::chrono::system_clock::now()

#define TIMER_END(NS)                                  \
  std::chrono::system_clock::time_point time_end##NS = \
      std::chrono::system_clock::now()

#define TIMER_OUT(NS)                                                          \
  std::chrono::microseconds dur_micro##NS =                                    \
      std::chrono::duration_cast<std::chrono::microseconds>(time_end##NS -     \
                                                            time_start##NS);   \
  std::chrono::milliseconds dur_milli##NS =                                    \
      std::chrono::duration_cast<std::chrono::milliseconds>(dur_micro##NS);    \
  printf("[%s] Part Cost Time: %ld us | %ld ms\n", #NS, dur_micro##NS.count(), \
         dur_milli##NS.count())

#define TIMER_NOW std::chrono::system_clock::now().time_since_epoch().count()

#define TIMER_NOW_MS                                       \
  std::chrono::duration_cast<std::chrono::milliseconds>(   \
      std::chrono::system_clock::now().time_since_epoch()) \
      .count()


#define TIMER_FPS(NS)                                              \
  static std::uint64_t pre_time##NS = 0;                           \
  static std::uint64_t now_time##NS = 0;                           \
  now_time##NS = TIMER_NOW;                                        \
  double diff_hz##NS = 1000000000 / (now_time##NS - pre_time##NS); \
  printf("[%s]: %lf Hz \n", #NS, diff_hz##NS);                     \
  pre_time##NS = now_time##NS;
#endif  // __TIMER_CPP__

