#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "frequency.h"
#include <locale>
#include <algorithm>
#include <vector>


using namespace std;

Frequency::Frequency()
{
  data = new map<string,size_t>;
}

Frequency::~Frequency()
{
  delete data;
}

Frequency::Frequency(const char *filename)
{
  populate_from_filename(filename);
}

size_t Frequency::get_count(string keyword)
{
  return 0;
}

void Frequency::populate_from_filename(const char* filename)
{
  ifstream* infile = new ifstream;
  infile->open(filename);

  populate_from_ifstream(*infile);
  infile->close();
  delete infile;
}

void Frequency::populate_from_ifstream(ifstream& infile)
{
  string a_word;
  locale loc; // to make isalpha() work
  string::iterator iter;

  delete data;
  data = new map<string,size_t>;
  map<string,size_t>::iterator m_iter;

  while (!infile.eof())
    {
      infile >> a_word;
      clean_string(a_word);

      if (a_word.empty())
	continue;

      // cout << "|" << a_word << "|"  << endl;
      m_iter = data->find(a_word);
      if (m_iter == data->end())
	(*data)[a_word] = 1;
      else
	++(m_iter->second);
    }
}

void Frequency::clean_string(string& dirty_string)
{
  locale loc; // to make isalpha() work

  for (string::iterator iter = dirty_string.begin(); iter != dirty_string.end(); iter++)
    {
      if (!isalpha(*iter, loc))
	// erase any non-alphabetic characters
  	{
  	  dirty_string.erase(iter);

	  if(dirty_string.empty())
	    break; // If it's empty, we're done

  	  iter = dirty_string.begin(); 
	  // deleting makes the iterator invalid since it changes the string size, so we start over
	  --iter; // So when we iterate at the top of the loop, it becomes the first char
  	}
    }
}

void Frequency::print_data()
{
  for(map<string,size_t>::iterator iter = data->begin(); iter != data->end(); ++iter)
    cout << iter->first << "=>" << iter->second << endl;

}

pair<string,size_t>* Frequency::to_array()
{
  pair<string,size_t>* the_array = new pair<string,size_t>[data->size()];

  size_t i = 0;
  for(
      map<string,size_t>::iterator iter = data->begin(); 
      iter != data->end(); 
      iter++, i++
      )
    {
      the_array[i] = *iter;
    }

  return the_array;
}

size_t Frequency::size()
{
  return data->size();
}

// pair<string,size_t>* Frequency::to_sorted_array()
word_freq* Frequency::to_sorted_array()
{
  // typedef pair<string,size_t> word_freq;
  word_freq* new_array = new word_freq[size()];
  word_freq* unsorted = this->to_array();

  vector<word_freq> the_vector(unsorted, unsorted+size());

  sort(the_vector.begin(), the_vector.end(), decreasing_compare);

  size_t i = 0;
  for(vector<word_freq>::iterator iter = the_vector.begin();
      iter != the_vector.end(); iter++, i++)
    {
      new_array[i] = *iter;
    }

  return new_array;
}

bool Frequency::decreasing_compare(const word_freq& lhs, const word_freq& rhs)
{
  return (lhs.second > rhs.second);
}
// +-()
