// This is start of the header guard.  TOOLS_H can be any unique name.  By convention, we use the name of the header file.
#ifndef TOOLS_3H
#define TOOLS_3H

#include <string>
#include <vector>

// This is the content of the .h file, which is where the declarations go

class byte_xor_decryptor{
public:
  static float quality(std::string str);
  static std::string byte_extender_hex(unsigned int byte_int, unsigned int size);
  static std::vector<std::string> decryptions(std::string ciphertext, unsigned int ntests);
};

// This is the end of the header guard
#endif


 
