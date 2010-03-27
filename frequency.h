#ifndef _FREQUENCY_H_
#define _FREQUENCY_H_

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

typedef pair<string,size_t> word_freq;

class Frequency
{
 private:
  map<string,size_t> *data;
  void populate_from_filename(const char* filename);
  void populate_from_ifstream(ifstream& infile);
  void clean_string(string& dirty_string);
  bool decreasing_compare(const word_freq& lhs, const word_freq& rhs);
 public:
  Frequency();
  Frequency(const char* filename);
  virtual ~Frequency();

  size_t get_count(string keyword);
  void print_data();
  pair<string,size_t>* to_array();
  word_freq* to_sorted_array();
  size_t size();

};

#endif /* _FREQUENCY_H_ */
