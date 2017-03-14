#ifndef UTILS_HPP__
#define UTILS_HPP__

#include <stdlib.h>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "ttmath/ttmath.h"
typedef ttmath::Big<4,10> MyBig;

namespace Utils {

  unsigned int get_value(const std::map<std::string, unsigned int> &h,
                         const std::string &k) {
    std::map<std::string, unsigned int>::const_iterator it = h.find(k);
    if (it != h.end()) return it->second;
    return static_cast<unsigned int>(0);
  }

  double get_value(const std::map<std::string, double> &h,
                   const std::string &k) {
    std::map<std::string, double>::const_iterator it = h.find(k);
    if (it != h.end()) return it->second;
    return static_cast<double>(0);
  }

  MyBig get_value(const std::map<std::string, MyBig> &h,
                  const std::string &k) {
    std::map<std::string, MyBig>::const_iterator it = h.find(k);
    if (it != h.end()) return it->second;
    return static_cast<MyBig>(0);
  }

  void string_tokenize(const std::string &str,
                       std::vector<std::string> &tokens,
                       const std::string &delimiters = " ") {
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    std::string::size_type pos = str.find_first_of(delimiters, lastPos);
    while (std::string::npos != pos || std::string::npos != lastPos) {
      tokens.push_back(str.substr(lastPos, pos - lastPos));
      lastPos = str.find_first_not_of(delimiters, pos);
      pos = str.find_first_of(delimiters, lastPos);
    }
  }

  std::string get_index(const std::string &a, const std::string &b) {
    return a + "-" + b;
  }

  // return a inform rand number in [a..b].
  static double random(double a, double b) {
    return (b - a) * drand48() + a;
  }

  // return a uniform random integer value in [0..n-1]
  static unsigned long random(unsigned long n) {
    if (n == 0) return 0;
    unsigned short state48[3];
    unsigned long guard = (unsigned long) (nrand48(state48) * n);
    return (guard > n) ? n : guard;
  }

}

#endif
