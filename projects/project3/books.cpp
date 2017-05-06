#include <iostream>
#include "books.h"

using namespace std;

class books {
  public:
    books::books(){ //constructor
    }
    
  private:
    int id;
    char title[250];
    char author[250];
    int copies;
    int checkOuts;
    int holds;
};
