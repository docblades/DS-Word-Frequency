#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "frequency.h"


Frequency::Frequency()
{
  data = new map<string,size_t>;
}

Frequency::~Frequency()
{
  delete data;
}

Frequency::Frequency(ifstream file)
{
  data = new map<string,size_t>;
}

Frequency::Frequency(string filename)
{
  data = new map<string,size_t>;
}

size_t Frequency::get_count(string keyword)
{
  return 0;
}

