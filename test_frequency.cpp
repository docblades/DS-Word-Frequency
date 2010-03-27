#include "frequency.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
  for (size_t i=0; i < argc; i++)
    cout << "argv " << i << "=> " << argv[i] << endl;

  if(argc == 0)
    return 1;

  cout << "test_f(" << argv[1] << ")" << endl;
  Frequency *test_f = new Frequency(argv[1]);
  test_f->print_data();

}

