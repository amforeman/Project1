#include <iostream>
#include <string>

int reverseAndAdd(int num);
int reverseNum(int num);
bool checkPalindrome(int sum);

int main(){
  int num;
  int test_cases;
  int iterations;
  std::cout<<"Enter the number of test cases (0-100) and numbers to be tested"<<std::endl;
  std::cin>>test_cases;
  for (int i = 0; i < test_cases; i++){
    std::cin>>num;
    num = reverseAndAdd(num);
    iterations = 1;
    bool palindrome = checkPalindrome(num);
    while (palindrome == false && iterations < 1000){
      num = reverseAndAdd(num);
      palindrome = checkPalindrome(num);
      iterations++;
    }
    std::cout<<iterations<<" "<<num<<std::endl;
  }
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
