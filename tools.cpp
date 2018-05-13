#include "tools.hpp"
using namespace std;

// 3 hex = 2 Base64
//

unsigned int hex_to_int(char c){
  if (c == '0'){
    return 0;
  }
  if (c == '1'){
    return 1;
  }
  if (c == '2'){
    return 2;
  }
  if (c == '3'){
    return 3;
  }
  if (c == '4'){
    return 4;
  }
  if (c == '5'){
    return 5;
  }
  if (c == '6'){
    return 6;
  }
  if (c == '7'){
    return 7;
  }
  if (c == '8'){
    return 8;
  }
  if (c == '9'){
    return 9;
  }
  if (c == 'a'){
    return 10;
  }
  if (c == 'b'){
    return 11;
  }
  if (c == 'c'){
    return 12;
  }
  if (c == 'd'){
    return 13;
  }
  if (c == 'e'){
    return 14;
  }
  if (c == 'f'){
    return 15;
  }
  return 0;
}

char int_to_hex(unsigned int i){
  if (i == 0){
    return '0';
  }
  if (i == 1){
    return '1';
  }
  if (i == 2){
    return '2';
  }
  if (i == 3){
    return '3';
  }
  if (i == 4){
    return '4';
  }
  if (i == 5){
    return '5';
  }
  if (i == 6){
    return '6';
  }
  if (i == 7){
    return '7';
  }
  if (i == 8){
    return '8';
  }
  if (i == 9){
    return '9';
  }
  if (i == 10){
    return 'a';
  }
  if (i == 11){
    return 'b';
  }
  if (i == 12){
    return 'c';
  }
  if (i == 13){
    return 'd';
  }
  if (i == 14){
    return 'e';
  }
  if (i == 15){
    return 'f';
  }
  return '0';
}
		    
// int* hexstr_to_intarr(string str){
//   char c;
//   static int list[];//str.length()];
//   for (int i = 0; i < str.length(); i++){
//     c = str[i];
//     list[i] = hex_to_int(c);
//   }
//   return list;
// }

char int_to_base64(unsigned int i){
  if (i == 0){
    return 'A';
  }
  if (i == 1){
    return 'B';
  }
  if (i == 2){
    return 'C';
  }
  if (i == 3){
    return 'D';
  }
  if (i == 4){
    return 'E';
  }
  if (i == 5){
    return 'F';
  }
  if (i == 6){
    return 'G';
  }
  if (i == 7){
    return 'H';
  }
  if (i == 8){
    return 'I';
  }
  if (i == 9){
    return 'J';
  }
  if (i == 10){
    return 'K';
  }
  if (i == 11){
    return 'L';
  }
  if (i == 12){
    return 'M';
  }
  if (i == 13){
    return 'N';
  }
  if (i == 14){
    return 'O';
  }
  if (i == 15){
    return 'P';
  }
  if (i == 16){
    return 'Q';
  }
  if (i == 17){
    return 'R';
  }
  if (i == 18){
    return 'S';
  }
  if (i == 19){
    return 'T';
  }
  if (i == 20){
    return 'U';
  }
  if (i == 21){
    return 'V';
  }
  if (i == 22){
    return 'W';
  }
  if (i == 23){
    return 'X';
  }
  if (i == 24){
    return 'Y';
  }
  if (i == 25){
    return 'Z';
  }
  if (i == 26){
    return 'a';
  }
  if (i == 27){
    return 'b';
  }
  if (i == 28){
    return 'c';
  }
  if (i == 29){
    return 'd';
  }
  if (i == 30){
    return 'e';
  }
  if (i == 31){
    return 'f';
  }
  if (i == 32){
    return 'g';
  }
  if (i == 33){
    return 'h';
  }
  if (i == 34){
    return 'i';
  }
  if (i == 35){
    return 'j';
  }
  if (i == 36){
    return 'k';
  }
  if (i == 37){
    return 'l';
  }
  if (i == 38){
    return 'm';
  }
  if (i == 39){
    return 'n';
  }
  if (i == 40){
    return 'o';
  }
  if (i == 41){
    return 'p';
  }
  if (i == 42){
    return 'q';
  }
  if (i == 43){
    return 'r';
  }
  if (i == 44){
    return 's';
  }
  if (i == 45){
    return 't';
  }
  if (i == 46){
    return 'u';
  }
  if (i == 47){
    return 'v';
  }
  if (i == 48){
    return 'w';
  }
  if (i == 49){
    return 'x';
  }
  if (i == 50){
    return 'y';
  }
  if (i == 51){
    return 'z';
  }
  if (i == 52){
    return '0';
  }
  if (i == 53){
    return '1';
  }
  if (i == 54){
    return '2';
  }
  if (i == 55){
    return '3';
  }
  if (i == 56){
    return '4';
  }
  if (i == 57){
    return '5';
  }
  if (i == 58){
    return '6';
  }
  if (i == 59){
    return '7';
  }
  if (i == 60){
    return '8';
  }
  if (i == 61){
    return '9';
  }
  if (i == 62){
    return '+';
  }
  if (i == 63){
    return '/';
  }
  return '0';
}

string hex_to_base64_3to2(string str){
  char c0, c1, c2;
  c0 = str[0]; c1 = str[1]; c2 = str[2]; //Reverse order
  //	cout << "Test1: " << c0 << c1 << c2 << endl;
  int i0, i1, i2;
  i0 = hex_to_int(c0);
  i1 = hex_to_int(c1);
  i2 = hex_to_int(c2);
  //	cout << "Test2: " << i0 << i1 << i2 << endl;

  int d0, d1; // This can be improved by shifting
  /*using the left and right shift operators will
    result in significantly faster code than calculating
    and then multiplying by a power of two*/
  d0 = i2 + 16*(i1 % 4);
  d1 = (i1 / 4) + 4*i0;
  //	cout << "Test3: " << d0 << d1 << endl;

  char e0, e1;
  e0 = int_to_base64(d0);
  e1 = int_to_base64(d1);
  //	cout << "Test4: " << e0 << e1 << endl;

  char arr[3] = {e1, e0, '\0'};
  string str2(arr);
  //	cout << "Test5: " << str2 << endl;
  return str2;
}

bool getBit(unsigned char byte, int position) // position in range 0-7, not really used in this code
{
  return (byte >> position) & 0x1;
}

/**
   Gives a list with the bits of the character
*/
bool* getBits(unsigned char byte){
  static bool tmp[4] = {getBit(byte, 0), getBit(byte, 1), getBit(byte, 2), getBit(byte, 3)};
  return tmp;
}

std::string xor_hexstr(std::string str1, std::string str2){
  char c;
  unsigned int list1[str1.length()];
  for (int i = 0; i < str1.length(); i++){
    c = str1[i];
    list1[i] = hex_to_int(c);
  }
  unsigned int list2[str2.length()];
  for (int i = 0; i < str2.length(); i++){
    c = str2[i];
    list2[i] = hex_to_int(c);
  }

  // Now we perform the xor
  char list[str1.length()+1];
  for (int i = 0; i < str1.length(); i++){
    c = int_to_hex(list1[i] ^ list2[i]);
    list[i] = c;
  }
  list[str1.length()] = '\0';

  string str(list);
  return str;
}

string hexstr_to_ascii(string str){
  string out = "";
  for (int i = 0; i < str.length(); i+=2){
    //cout << "Hex: " << str[i] << " " << str[i+1] << endl;
    unsigned int tmp1 = hex_to_int(str[i]);
    unsigned int tmp2 = hex_to_int(str[i+1]);
    //cout << "Ints: " << tmp1 << tmp2 << endl;
    char tmp3 = tmp2 + (tmp1 << 4);
    out += tmp3;
  }
  return out;
}
