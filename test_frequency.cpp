// **********************************
// * Final Project : Word Frequency *
// *                                *
// * CS 3424 Data Structures        *
// * SPRING 2010                    *
// * - Christian Blades             *
// * - Brent Stonehill              *
// * - Randy Wells                  *
// **********************************

#include "frequency.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
  for (size_t i=0; i < argc; i++)
    cout << "argv " << i << "=> " << argv[i] << endl;

  if(argc == 1)
    return 1;

  cout << "test_f(" << argv[1] << ")" << endl;
  Frequency *test_f = new Frequency(argv[1]);
  test_f->print_data();

  pair<string,size_t>* t_array = test_f->to_array();
  size_t t_size = test_f->size();

  // for(size_t i = 0; i < t_size; i++)
  //   {
  //     cout << i << ": " << t_array[i].first << "=>" << t_array[i].second << endl;
  //   }

  cout << "Sorted array:" << endl;
  word_freq* sorted_array = test_f->to_sorted_array();

  for(size_t i = 0; i < t_size; i++)
    cout << i << ": " << sorted_array[i].second << "=>" << sorted_array[i].first << endl;
}

