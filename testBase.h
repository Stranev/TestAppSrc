#pragma once
#include <iostream>
#include <string>

using namespace std;

class testBase
{
public:
   //Function must revert the sequence of words. ("word1 word2 word3" becomes "word3 word2 word1")
   virtual void revertWords(char* arr) = 0;

   //Function must revert words using revertWords method and return the longest word.
   virtual std::string processWords(std::string& input) = 0;

   //Function must generate random length(up to 20) array of random signed integer numbers.
   //Function must print the generated sequence in console.
   virtual void signedIntGenerator(signed int* &arr) = 0;

   //Function must use signedIntGenerator() and return minimum value.
   virtual signed int signedMin(signed int* arr) = 0;

   virtual ~testBase() = 0
   {}

};