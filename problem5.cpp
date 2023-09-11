
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "randword.h"

static std::vector<std::string> dictionary;
std::string guessDisplay;
int guessCount = 8;
int wordLength;

bool checkLetter(char c, std::string word);
bool guessStatus(char c, std::string word);
std::vector<int> letterIndex(char c, std::string word);
void updateGuessDisplay(char c, std::vector<int> index);

void InitDictionary(std::string file){
  std::ifstream wordListFile;
  std::string word;
  wordListFile.open(file, std::ios::in);
  wordListFile>>word;
  while (!wordListFile.eof()){
    dictionary.push_back(word);
    wordListFile>>word;
  }
  wordListFile.close();
}

std::string ChooseRandomWord(){
  std::srand(time(NULL));
  int randomIndex = std::rand() % dictionary.size();
  return dictionary[randomIndex];
}

bool checkLetter(char c, std::string word){
  for (int i = 0; i < word.length(); i++){
    if (word[i] == c){
      return true;
    }
    else {
      continue;
    }
  }
  return false;
}

bool guessStatus(char c, std::string word){
  std::string status;
  bool letterCheck = checkLetter(c, word);
  if (letterCheck == true){
    std::vector<int> index = letterIndex(c, word);
    updateGuessDisplay(c, index);
    std::cout<<"That guess is correct."<< std::endl;;
    wordLength = wordLength - index.size();
    return true;
  }
  else {
    std::cout<<"There are no "<< c <<"'s in this word."<< std::endl;;
    guessCount--;
    return false;
  }
}

std::vector<int> letterIndex(char c, std::string word){
  std::vector<int> index;
  for (int i = 0; i < word.length(); i++){
    if (word[i] == c){
      index.push_back(i);
    }
  }
  return index;
}

void updateGuessDisplay(char c, std::vector<int> index){
  for(int i = 0; i < index.size(); i++){
    guessDisplay[index[i]] = c; 
  }
}

int main(){
  InitDictionary("hangmanList.txt");
  std::string word = ChooseRandomWord();
  std::cout<<"Welcome to hangman!"<<std::endl;
  std::cout<<"I have a word in mind. On each turn you will guess a letter. If the letter is correct, I will show you where it appears in the word. If your letter is incorrect, you lose a guess and a part of your body gets strung to the scaffold. The object is to guess the word before you are hung (8 guesses)."<<std::endl;
  wordLength = word.length();
  for (int i = 0; i < wordLength; i++){
    guessDisplay = guessDisplay + "_";
  }
  char guess;
  bool status;
  while (guessCount > 0 && wordLength > 0){
    std::cout<<"The word now looks like this: "<<guessDisplay<< std::endl;
    std::cout<<"You have "<<guessCount<<" guesses left."<<std::endl;
    std::cout<<"Guess a letter: "<<std::endl;
    std::cin>>guess;
    bool status = guessStatus(guess, word);
  }
  if (guessCount == 0){
    std::cout<<"You lost. The word was: "<<word<<std::endl;
    return 0;
  }
  if (wordLength == 0){
    std::cout<<"You won. You guessed the word: "<<word<<std::endl;
    return 0;
  }
  std::cout<<"Error"<<std::endl;
  return 0;
}
