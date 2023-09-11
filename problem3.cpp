#include <iostream>
#include <string>
#include <vector>

int reverseAndAdd(int num);
int reverseNum(int num);
bool checkPalindrome(int sum);
void printVector(std::vector<int>);

int main(){
  int num;
  int test_cases;
  int iterations;
  std::cout<<"Enter the number of test cases (0-100) and numbers to be tested"<<std::endl;
  std::cin>>test_cases;
  std::vector<std::vector<int>> answerVec;
  for (int i = 0; i < test_cases; i++){
    std::vector<int> answer(2);
    std::cin>>num;
    num = reverseAndAdd(num);
    iterations = 1;
    bool palindrome = checkPalindrome(num);
    while (palindrome == false && iterations < 1000 && num <= 4294967295){
      num = reverseAndAdd(num);
      palindrome = checkPalindrome(num);
      iterations++;
    }
    answer[0] = iterations;
    answer[1] = num;
    answerVec.push_back(answer);
  }
  for (int i = 0; i < answerVec.size(); i++){
    printVector(answerVec[i]);
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

void printVector(std::vector<int> vec){
  for (int i = 0; i < vec.size(); i++){
    std::cout<<vec[i]<< " ";
  }
  std::cout<<std::endl;
}
