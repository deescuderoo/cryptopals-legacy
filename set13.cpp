#include <iostream>
#include "xor_tools.hpp"
using namespace std;

// We assume the plaintext has only words (perhaps a few punctuation marks)


int main(){
  unsigned int ntests = 10;
  //cout << "Input the ciphertext (xored with just one byte)" << endl;
  vector<string> plaintext(ntests);
  string ciphertext;
  //cin >> ciphertext;
  ciphertext = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

  plaintext = byte_xor_decryptor::decryptions(ciphertext, ntests);
  for (unsigned int i = 0; i < ntests; i++){
    cout << "Possible plaintext number " << i+1 << ": " << plaintext.at(i) << endl;
  }
  return 0;
  
}
