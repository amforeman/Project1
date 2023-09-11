#include <iostream>
#include <string>
#include <vector>

std::vector<char> stringToCharVector(std::string s);
void errorKeyboard(std::string s);
std::string vectorToString(std::vector<char> vec);
char characterConvert(char c);

int main(){
  std::string s;
  std::cout<<"Type something"<<std::endl;
  std::getline(std::cin,s);
  errorKeyboard(s);
}

std::vector<char> stringToCharVector(std::string s){
  std::vector<char> inputVec;
  for (int i = 0; i < s.length(); i++){
    inputVec.push_back(s[i]);
  }
  return inputVec;
}

std::string vectorToString(std::vector<char> vec){
  std::string output;
  for (int i = 0; i < vec.size(); i++){
    output = output + vec[i];
  }
  return output;
}

char characterConvert(char c){
  switch(c){
    case 'W': return 'Q';
    case 'E': return 'W';
    case 'R': return 'E';
    case 'T': return 'R';
    case 'Y': return 'T';
    case 'U': return 'Y';
    case 'I': return 'U';
    case 'O': return 'I';
    case 'P': return 'O';
    case '[':
    case '{': 
      return 'P';
    case']': return '[';
    case '}': return '{';
    case '|': return '}';
    case 'S': return 'A';
    case 'D': return 'S';
    case 'F': return 'D';
    case 'G': return 'F';
    case 'H': return 'G';
    case 'J': return 'H';
    case 'K': return 'J';
    case 'L': return 'K';
    case ';':
    case ':': 
      return 'L';
    case'"': return ':';
    case 'X': return 'Z';
    case 'C': return 'X';
    case 'V': return 'C';
    case 'B': return 'V';
    case 'N': return 'B';
    case 'M': return 'N';
    case ',':
    case '<':
      return 'M';
    case'>': return '<';
    case '.': return ',';
    case '/': return '.';
    case'?': return '>';
    case '1': return '`';
    case '2': return '1';
    case '3': return '2';
    case '4': return '3';
    case '5': return '4';
    case '6': return '5';
    case '7': return '6';
    case '8': return '7';
    case '9': return '8';
    case '0': return '9';
    case '-': return '0';
    case '=': return '-';
    case '+': return '_';
    case '!': return '~';
    case '@': return '!';
    case '#': return '@';
    case '$': return '#';
    case '%': return '$';
    case '^': return '%';
    case '&': return '^';
    case '*': return '&';
    case '(': return '*';
    case ')': return '(';
    case '_': return ')';
    case ' ': return ' ';
    default: std::cout<< "Invalid input"<< std::endl;
  }
  return ' ';
}

void errorKeyboard(std::string s){
  std::vector<char> charVec = stringToCharVector(s);
  std::vector<char> outputVec;
  for (int i = 0; i < charVec.size(); i++){
    char c = charVec[i];
    outputVec.push_back(characterConvert(c));
  }
  std::string output = vectorToString(outputVec);
  std::cout<<output<<std::endl;
}
