#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "frequency.h"
#include <locale>
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
  data = new map<string,size_t>;
  populate_from_filename(filename);
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

  delete data;
  data = new map<string,size_t>;
  map<string,size_t>::iterator m_iter;

  // while (!infile.eof())
  while (infile >> a_word)
    {
      // infile >> a_word;
      clean_string(a_word);

      if (a_word.empty())
	continue;

      m_iter = data->find(a_word);
      if (m_iter == data->end())
	(*data)[a_word] = 1;
      else
	++(m_iter->second);
    }
}

void Frequency::clean_string(string& dirty_string)
{
  locale loc;
  string temp;
  for(string::iterator letter = dirty_string.begin(); letter != dirty_string.end(); letter++)
    {
      if (isalpha(*letter, loc))
	temp.push_back(*letter);
    }
  dirty_string = temp;
}

void Frequency::print_data()
{
  for(map<string,size_t>::iterator iter = data->begin(); 
      iter != data->end(); ++iter)
    cout << iter->first << "=>" << iter->second << endl;

}

word_freq* Frequency::to_array()
{
  pair<string,size_t>* the_array = new pair<string,size_t>[data->size()];

  // iterates through the map and puts each object in an array
  size_t i = 0;
  for(map<string,size_t>::iterator iter = data->begin(); 
      iter != data->end(); iter++, i++)
    the_array[i] = *iter;

  return the_array;
}

size_t Frequency::size()
{
  return data->size();
}

word_freq* Frequency::to_sorted_array()
{
  word_freq* new_array = new word_freq[size()];
  vector<word_freq> sort_vector;

// Compare the frequency of each word against what's already in the 
// sort_vector. When it's less than whatever position we're to in 
// the vector, insert this one at that position.
  sort_vector.push_back(*data->begin());
  for (map<string,size_t>::iterator iter = ++data->begin(); iter != data->end(); iter++)
    {
      for(vector<word_freq>::iterator v_iter = sort_vector.begin();
	  v_iter != sort_vector.end(); v_iter++)
	{
	  if (v_iter->second <= iter->second)
	    {
	      sort_vector.insert(v_iter, *iter);
	      break;
	    }
	}
    }

  // Turn this vector into an array and return it
  size_t i = 0;
  for(vector<word_freq>::iterator iter = sort_vector.begin();
      iter != sort_vector.end(); iter++, i++)
    {
      new_array[i] = *iter;
    }

  return new_array;
}


// +-()
