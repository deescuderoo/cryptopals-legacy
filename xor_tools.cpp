#include "tools.hpp"
#include "xor_tools.hpp"
#include <math.h>
using namespace std;

float byte_xor_decryptor::quality(string str){
  float real_frequencies[26] =
    {0.8167, 0.1492, 0.2782, 0.4253, 0.12702, 0.2228, 0.2015, 0.6094, 0.6966, 0.0153, 0.0772, 0.4025, 0.2406, 0.6749, 0.7507, 0.1929, 0.0095, 0.5987, 0.6327, 0.9056, 0.2758, 0.0978, 0.2360, 0.0150, 0.1974, 0.0074};
  
  char Dict[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char dict[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
  float counting[26];
  for (int i = 0; i < 26; i++){
    counting[i] =  std::count(str.begin(), str.end(), Dict[i]) + std::count(str.begin(), str.end(), dict[i]);
  }

  // Normalization
  for (int i = 0; i < 26; i++){
    counting[i] /= str.length();
    //cout << counting[i] << endl;
  }

  // Statistical distance (norm-1)
  float dist = 0;
  for (int i = 0; i < 26; i++){
    dist += fabs(counting[i] - real_frequencies[i]);
  }
  //cout << dist << endl;
  //cout << "Distances: " << dist << endl;
  return dist;
  
}

// string byte_to_2hex(char byte){
//   int byte0

string byte_xor_decryptor::byte_extender_hex(unsigned int byte_int, unsigned int size){
  string out = "";
  unsigned int byte0, byte1;
  string hex1, hex0;

  byte0 = byte_int % 16;
  byte1 = byte_int >> 4;

  hex1 = int_to_hex(byte1);
  hex0 = int_to_hex(byte0);
  //cout << "Inside: " << byte1 << " " << byte0 << " " << byte_int << endl;
  for (int j = 0; j < size/2; j++){
    out += hex1+hex0;
    // cout << "Test: " << hex1 + hex0 << endl;
  }
  return out;
}

vector<string> byte_xor_decryptor::decryptions(string ciphertext, unsigned int ntests){
  string plaintext, key;

  unsigned int length = ciphertext.length();
  //  
  char byte;
  float scores[256];
  for (unsigned int i = 0; i < 256; i++){
    // byte = i;
    //cout << "Int: " << i << endl;
    key = byte_extender_hex(i, length);
    //cout << "Key: " << key << " Int: " << i << endl;
    assert (key.length() == ciphertext.length());
    plaintext = xor_hexstr(ciphertext, key);
    scores[i] = quality(hexstr_to_ascii(plaintext));
  }

  unsigned int j;
  float* maxim = max_element(scores, scores + 256);
  float* minim = min_element(scores, scores + 256);

  vector<string> lst(ntests);
  for (unsigned int i = 0; i < ntests; i++){
    j = distance(scores, min_element(scores, scores + 256));
    key = byte_extender_hex(j, length);
    plaintext = xor_hexstr(ciphertext, key);
    lst[i] = hexstr_to_ascii(plaintext);
    // cout << lst[i] << endl;
    scores[j] = *(maxim);
  }
  return lst;
}
