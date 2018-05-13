#include <iostream>
#include <fstream>

#include "xor_tools.hpp"
#include "tools.hpp"
using namespace std;

// We assume the plaintext has only words (perhaps a few punctuation marks)

int main () {
  unsigned int ntests = 10;
  string line;
  unsigned int ntexts = 0;


  vector<string> plaintext(ntests);

  vector<string> ptexts(0);


  
  ifstream data ("data/4.txt");
  if (data.is_open())
    {
      while ( getline (data,line) )
	{
	  plaintext = byte_xor_decryptor::decryptions(line, ntests);
	  ptexts.insert(ptexts.end(), plaintext.begin(), plaintext.end());
	  //cout << "\nline " << ntexts << " " << ptexts.size() << " " << plaintext.size() << ": " << line;
	  ntexts++;
	}
      unsigned int length = ntests * ntexts;
      float scores[length];
      for (unsigned int i = 0; i < length; i++){
	//cout << ntexts << " " << length << " " << i << " " << byte_xor_decryptor::quality(hexstr_to_ascii(ptexts[i])) << endl;
	scores[i] = byte_xor_decryptor::quality(ptexts[i]);
      }

      

      unsigned int j;
      
      float* maxim = max_element(scores, scores + length);
      float* minim = min_element(scores, scores + length);
      
      unsigned int ntest_all = 10;
      vector<string> lst(ntest_all);
      
      for (unsigned int i = 0; i < ntest_all; i++){
	j = distance(scores, min_element(scores, scores + ntexts*ntests));
	assert (scores[j] == *min_element(scores, scores + ntexts*ntests));
	assert (scores[j] == *(scores + j));
	lst[i] = ptexts[j];
	assert (scores[j] == byte_xor_decryptor::quality(ptexts[j]));
	cout << "Possible plaintext number " << i+1 << ": " << lst[i] << ". Score: " << scores[i] << endl;
	// cout << lst[i] << endl;
	scores[j] = *(maxim);
      }
      data.close();

    }

  else cout << "Unable to open file"; 

  return 0;
}
