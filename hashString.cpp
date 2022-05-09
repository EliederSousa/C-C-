/**
 *  hashString.cpp
 *  
 *  Copyright (c) 2022, Elieder Sousa
 *  eliedersousa<at>gmail<dot>com
 *  
 *  Distributed under the MIT license.
 *  
 *  @date     09/05/22
 *  
 *  @brief    Criando hash com chaves em string.
 *  
 *  Elieder Damasceno Sousa 		| 32093659
 *  José Eduardo Bernardino Jorge 	| 42019877
 */

#include <iostream>
#include <string>

using namespace std;

// Esta função só aceita os caracteres contidos na string "abc".
int hashString( string texto, int M ) {
  string abc = "abcdefghijklmnopqrstuvwxyz";
  string temp = "";

  for( int w = 0; w < texto.length(); w++ ) {
    temp += std::to_string(abc.find(texto[w]));
  }

  int hashInteger = stoi(temp);
  return hashInteger % M;
}

int main() {
  cout << hashString( "jose", 71);
}