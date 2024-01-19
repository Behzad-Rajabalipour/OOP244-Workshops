#include <iostream>
#include "cstring.h" // Include the cstring header file for string manipulation functions
using namespace sdds; // Use the sdds namespace for string functions
using namespace std;

int main() {
   char str1[80] = "abcdefghijklmnopqrstuvwxyz"; // Define and initialize a string
   char str2[80]; // Define a second string
   const char* fadd; // Pointer for string search operations

   strCpy(str2, str1); // Copy str1 into str2
   cout << str2 << endl; // Display str2

   strnCpy(str2, "@@@", 2); // Copy first 2 characters of "@@@" into str2
   cout << str2 << endl; // Display str2

   strnCpy(str2, "@@@", 3); // Copy first 3 characters of "@@@" into str2
   cout << str2 << endl; // Display str2

   strnCpy(str2, "@@@", 4); // Copy first 4 characters of "@@@" into str2, includes null terminator
   cout << str2 << endl; // Display str2

   cout << strCmp("aab", "aaa") << endl; // Compare two strings and display the result

   cout << strnCmp("aab", "aaa", 2) << endl; // Compare first 2 characters of two strings and display the result

   cout << strnCmp("aab", "aaa", 3) << endl; // Compare first 3 characters of two strings and display the result

   cout << strLen("") << endl; // Display the length of an empty string

   cout << strLen(str1) << endl; // Display the length of str1

   fadd = strStr(str1, "jkl"); // Find the substring "jkl" in str1
   cout << fadd << endl; // Display the found substring or its location

   fadd = strStr(str1, "bbb"); // Try to find the substring "bbb" in str1
   if(!fadd) cout << "Not found" << endl; // If not found, display "Not found"

   strCpy(str2, "John "); // Copy "John " into str2
   strCat(str2, "Doe"); // Concatenate "Doe" to str2
   cout << str2 << endl; // Display the concatenated string

   return 0;
}
