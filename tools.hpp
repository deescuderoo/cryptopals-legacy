// This is start of the header guard.  TOOLS_H can be any unique name.  By convention, we use the name of the header file.
#ifndef TOOLS_H
#define TOOLS_H

#include <string>

// This is the content of the .h file, which is where the declarations go
unsigned int hex_to_int(char c);

char int_to_hex(unsigned int i);
  
char int_to_base64(unsigned int i);

std::string hex_to_base64_3to2(std::string str);

//int* hexstr_to_intarr(std::string str);

bool getBit(unsigned char byte, int position); // position in range 0-7

bool* getBits(unsigned char byte);

std::string xor_hexstr(std::string str1, std::string str2);

std::string hexstr_to_ascii(std::string str);
  
// This is the end of the header guard
#endif


