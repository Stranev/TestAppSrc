#include "testBase.h"

using namespace std;

class yourTestClass : public testBase
{
public:
///Function must revert the sequence of words. ("word1 word2 word3" becomes "word3 word2 word1")
   void revertWords(char* arr)
   {
      int arrSize = 0; //variable for array size
      while (arr[arrSize] != '\0')
      {
         arrSize++;
      }

      char* arrWord = new char[arrSize + 1]; // To store one word. Full size in case there is only one word in the line
      string arrString;  //To add one word at a time to the beginning

      char ch = ' ';
      for (int i = 0; ch != '\0'; i++)// run through the array
      {
         ch = arr[i];
         if (ch != ' ' && ch != '\0')  //If there was a symbol then the word began
         {
            int k;
            for (k = 0; ch != ' ' && ch != '\0'; k++, i++)  // copy one word from the received array to the temporary one
            {
               arrWord[k] = arr[i];
               ch = arr[i + 1];  // read the next character for verification
            }

            arrWord[k] = '\0';  //Add zero to indicate end of line
            arrString.insert(0, arrWord); //insert a string-word at the beginning of the resulting string
            arrString.insert(0, " ");  // insert a space to separate words	
         }
      }

      //переписываю из string в полученный, в качестве аргумента, исходный char*
	  //rewrite from string to received, as an argument, the original char*
      arrString.erase(0, 1); // Delete the space in [0] position
	  int j = 0;
      for (j = 0; j < arrString.size(); j++) //Copy from string to char*
      {
         arr[j] = arrString[j];
      }
      arr[j] = '\0';

	  delete []arrWord;
   }
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //Function must revert words using revertWords method and return the longest word.
   std::string processWords(std::string& input)
   {
      int inputSize = input.length();
      if (0 != inputSize)
      {
         char* strChar = new char[inputSize + 1];//create an array to transfer to revertWords ()
         input.copy(strChar, inputSize);  // copy from string to char*
         strChar[inputSize] = '\0'; // add an end-of-line character

         revertWords(strChar);
         input = strChar;

         /////////////////////////////////////////////////////////
         inputSize = input.length();  // just in case
         char* maxLength = new char[inputSize + 1];  // stores the longest word
         char* tempLength = new char[inputSize + 1];  // for reading the current word
         int maxCurrent = 0;  // to store the length of the current maximum longest word
         int k;  // to store the length of the current word

         for (int i = 0; ('\0' != strChar[i]) && (i < inputSize); i++) // run through the array
         {
            k = 0;
            while ((' ' != strChar[i]) && ('\0' != strChar[i])) //If there was a symbol then the word began
            {
               tempLength[k] = strChar[i];
               i++; k++;
            }
            tempLength[k] = '\0';

            if (k > maxCurrent) // compare the length of the current word with the length of the maximum words
            {
               strcpy(maxLength, tempLength);
               maxCurrent = k;
            }
         }

		// delete  all arrays
		 delete []strChar;
		 delete []tempLength;

		 string longWord = maxLength;
		 delete []maxLength;

         return longWord;
      }

      return "The string is epmty";
   }
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //Function must generate random length(up to 20) array of random signed integer numbers.
   //Function must print the generated sequence in console.
   void signedIntGenerator(signed int* &arr)
   {
      int arrSize = (rand() % 20) + 1;  // +1, in case it generates 0
      arr = new signed int[arrSize];
      arr[0] = arrSize - 1;  // stores the size of the array
      for (int i = 1; i < arrSize; i++)  // fill in the array with random numbers and +-
      {
         arr[i] = rand();
         if (rand() % 2)
         {
            arr[i] *= (-1);
         }
      }

      for (int i = 1; i < arrSize; i++)
      {
         cout << "arr[" << i << "] = " << arr[i] << endl;
      }
   }
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   ///Function must use signedIntGenerator() and return minimum value.
   signed int signedMin(signed int* arr)
   {
      signedIntGenerator(arr);
      int min = 32767; //maximum for rand()

      for (int i = 1; i < arr[0] + 1; i++)
      {
         if (arr[i] < min)
         {
            min = arr[i];
         }
      }
      return min;
   }
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   ~yourTestClass()
   {}

};