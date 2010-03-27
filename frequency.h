#ifndef _FREQUENCY_H_
#define _FREQUENCY_H_

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

class Frequency
{
 private:
  map<string,size_t> *data;
  void populate_from_filename(const char* filename);
  void populate_from_ifstream(ifstream& infile);
  void clean_string(string& dirty_string);
 public:
  Frequency();
  Frequency(const char* filename);
  virtual ~Frequency();

  size_t get_count(string keyword);
  void print_data();

};

#endif /* _FREQUENCY_H_ */
