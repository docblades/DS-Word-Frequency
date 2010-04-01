#ifndef _FREQUENCY_H_
#define _FREQUENCY_H_

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

 public:
  Frequency();
  Frequency(const char* filename);
  virtual ~Frequency();

  void print_data();
  word_freq* to_array();
  word_freq* to_sorted_array();
  size_t size();

};

#endif /* _FREQUENCY_H_ */
