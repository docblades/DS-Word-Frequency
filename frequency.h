#ifndef _FREQUENCY_H_
#define _FREQUENCY_H_

#include <iostream>
#include <map>
#include <string>
#include <fstream>

class Frequency
{
private:
  map<string,size_t>* data;

public:
  Frequency();
  Frequency(ifstream file);
  Frequency(string filename);
  virtual ~Frequency();

  size_t get_count(string keyword);
};

#endif /* _FREQUENCY_H_ */
