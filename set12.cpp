/* "The byte is the lowest level at which we can access data;
   there's no "bit" type, and we can't ask for an individual bit"*/

#include<iostream>
#include "tools.hpp"
using namespace std;

int main(){
  //cout << "Input the hex strings" << endl;
  string str1;
  string str2;
  //cin >> str1 >> str2;

  str1 = "1c0111001f010100061a024b53535009181c";
  str2 = "686974207468652062756c6c277320657965";
  string str = xor_hexstr(str1, str2);
  
  //int* result = hexstr_to_intarr(str1);
  cout << "The xor string is\n" << str << endl;
  return 0;
}
