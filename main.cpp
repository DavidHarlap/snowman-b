#include <stdlib.h>


#include <iostream>
#include <string>
#include "snowman.hpp"
const int NUM_OF_DIGIT = 8;
using namespace std;


int main() {
   srand(1);
   for (size_t i = 0; i < 20; i++) {
       int code = rand() % 4 + 1;
       for (size_t i = 1; i < NUM_OF_DIGIT; i++) {
           code *= 10;
           code += rand() % 4 + 1;
       }
       cout << "code:" << code<<endl << string(ariel::snowman(code)) << endl<< endl;
   }
   cout << "left arm up: code:12442324" << endl << string(ariel::snowman(12442324));
   cout << "right arm up: code:14221212" << endl << string(ariel::snowman(14221212));

   return 0;
}  
