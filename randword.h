/*
 *File: randword.h
 *---------------------------
 *The interface exports functions for choosing a word from a data file at random
 */

#ifndef _randword_h
#define _randword_h

#include <string>

/*
 *Function: InitDictionary
 *Usage: InitDictionary("data.txt")
 */
void InitDictionary(std::string file);


/*
 *Function: ChooseRandomWord
 *Usage: string word = ChooseRandomWord()
 */
std::string ChooseRandomWord();

#endif
