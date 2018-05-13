#include <iostream>

#include "xor_tools.hpp"
#include "tools.hpp"
using namespace std;

int main () {
  string plaintext = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal";
  string plaintext_hex = "";
  string key = "ICE";
  string str1 = "";
  unsigned int length = plaintext.length();

  for (unsigned int i = 0; i < (plaintext.length() / key.length()) + 1; i++){
    str1 += key;
  }
  string key_hex = "";

  for (unsigned int i = 0; i < plaintext.length(); i++){
    int byte1 = plaintext[i];
    int byte2 = str1[i];

    plaintext_hex += string(1,int_to_hex(byte1 >> 4)) + string(1,int_to_hex(byte1 % 16));
    key_hex += string(1,int_to_hex(byte2 >> 4)) + string(1,int_to_hex(byte2 % 16));
  }

  string ciphertext = xor_hexstr(plaintext_hex, key_hex);
  cout << "The ciphertext is:\n" << ciphertext << endl;

  return 0;
}
