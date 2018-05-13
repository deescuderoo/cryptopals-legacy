#include<iostream>
#include "tools.hpp"
using namespace std;

int main() {
  string str1;
  //cout << "Please enter the hexadecimal string to be converted: " << endl;
  //getline(cin, str1);
  str1 = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  const char* str2 = str1.c_str();
  string str3 = "";
  for (int i = 0; i < str1.length(); i += 3){
    str3 += hex_to_base64_3to2(str1.substr(i,3));
  }
  cout << "Output: " << str3 <<endl;
  return 0;
}
