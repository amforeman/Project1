#include <iostream>
#include <string>

int reverseAndAdd(int num);
int reverseNum(int num);
bool checkPalindrome(int sum);

int main(){
  int num;
  std::cout<<"Enter a number"<<std::endl;
  std::cin>>num;
  int iterations = 1;
  num = reverseAndAdd(num);
  bool palindrome = checkPalindrome(num);
  while (palindrome == false){
    num = reverseAndAdd(num);
    palindrome = checkPalindrome(num);
    iterations++;
  }
  std::cout<<"Resulting palindrome: "<<num<<std::endl;
  std::cout<<"Number of additions: "<<iterations<<std::endl;
}

bool checkPalindrome(int sum){
  int reverse = reverseNum(sum);
    if (sum == reverse){
      return true;
    }
    else{
      return false;
    }
}

int reverseNum(int num){
  std::string numString= std::to_string(num);
  std::string reverseNumString;
  for (int i = numString.length()-1; i >=  0; i--){
    reverseNumString = reverseNumString + numString[i];
  }
  int reverse = stoi(reverseNumString);
  return reverse;
}

int reverseAndAdd(int num){
  int reverse = reverseNum(num);
  int sum =  num + reverse;
  return sum;
}
