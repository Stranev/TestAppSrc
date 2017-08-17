#pragma once
#include "yourTestClass.cpp"

using namespace std;

int main() //DO NOT MODIFY THIS BLOCK
{
   yourTestClass myTest;
   signed int* arr = nullptr;

   std::cout << "Test started" << std::endl;
   std::cout << "Please input a text with several words" << std::endl;
   std::string input;
   std::getline(std::cin, input);

   std::cout << "Input text: " << input << std::endl;
   std::cout << "Longest word: " << myTest.processWords(input) << std::endl;
   std::cout << "Reverted text: " << input << std::endl;
   std::cout << "Minimal is : " << myTest.signedMin(arr) << std::endl;
   std::cout << std::endl << "Test ended";

   return 0;
}