// /*******************************************************************************
//  * AUTHOR         : Jessica Hahm, Jibran Khan
//  * Lab #13        : Reccursion
//  * CLASS          : CS3A
//  * SECTION        : 32276
//  * DUE DATE       : 03/16/22
//  *******************************************************************************/
// #include <iostream>
// #include <string>
// #include <vector>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// /*******************************************************************************
//  *
//  * Recursion
//  *_________________________________________________________________
//  * <description>
//  * This program is for practice wirting recursive functions
//  *_________________________________________________________________
//  * INPUTS:
//  *  int opt: option for the user to run the program
//  *
//  * OUTPUTS:
//  *  N/A
//  *
//  *******************************************************************************/

// /*******************************************************************************
//  * int sum(int n);
//  *  This program computes the sum
//  *  - returns the sum
//  *
//  *******************************************************************************/
// int sum(int n); // IN - number to be computed

// /*******************************************************************************
//  * int findmin(const int a[], int n);
//  * This program find the minimum from the array
//  *  - returns the minimum integer
//  *
//  *******************************************************************************/
// int findmin(const int a[], // IN - array to be computed
//             int n);        // IN - size of the array

// /*******************************************************************************
//  * int findsum(const int a[], int n);
//  *  This function find the sum of the array
//  *  - returns the sum of the array
//  *
//  *******************************************************************************/
// int findsum(const int a[], // IN - array to be computed
//             int n);        // IN - size of the array

// /*******************************************************************************
//  * bool ispalindrome(const char a[], int n);
//  *  This function check if the char array is palindrom or not
//  *  - returns true if the array is palindrom and false if it's not
//  *
//  *******************************************************************************/
// bool ispalindrome(const char a[], // IN - array to be computed
//                   int n);         // IN - size of the array

// /*******************************************************************************
//  * vector<string> generate_substrings(string s);
//  *  This function generate substrings from string
//  *  - returns vector with substrings
//  *
//  *******************************************************************************/
// vector<string> generate_substrings(string s); // IN - string to be computed

// /*******************************************************************************
//  * void drawPattern(int n);
//  *  This function draws pattern
//  *  - display pattern to user
//  *
//  *******************************************************************************/
// void drawPattern(int n); // IN - number of the base star

// int main()
// {
//     int choice = 0; // IN - user inputs to play program
//     cout << "Select a function to test(1-6): \n";
//     cin >> choice;

//     int size = 0;     // IN - size of the array
//     string word = ""; // IN - word to be computed
//     vector<string> v; // IN - string vector which stores substrings

//     // run the sum function
//     if (choice == 1)
//     {
//         cout << "Enter a positive integer: \n";
//         cin >> choice;
//         cout << "\nThe sum is " << sum(choice) << endl;
//     }

//     // run findmin function
//     else if (choice == 2)
//     {
//         cout << "Finding the minimum element of an array "
//              << "containing random numbers from -1000 to 1000.\n";
//         cout << "Enter the size of the array: \n\n";
//         cin >> size;

//         int a[size]; // IN - int array to be computed
//         for (int i = 0; i < size; i++)
//             a[i] = rand() % 2001 - 1000;
//         cout << "The minimum element of the array is " << findmin(a, size) << endl;
//     }

//     // run findsum function
//     else if (choice == 3)
//     {
//         cout << "Finding the sum of the elements of an array "
//              << "containing random numbersfrom -1000 to 1000.\n";
//         cout << "Enter the size of the array: \n\n";
//         cin >> size;

//         int b[size]; // IN - int array to be computed
//         for (int i = 0; i < size; i++)
//             b[i] = rand() % 2001 - 1000;
//         cout << "The sum of the elements of the array is " << findsum(b, size) << endl;
//     }

//     // run ispalindrom function
//     else if (choice == 4)
//     {
//         cout << "Enter a phrase: \n";
//         cin >> word;
//         char c[word.length()]; // IN - char array to be computed
//         for (int i = 0; i < word.length(); i++)
//             c[i] = word[i];
//         if (ispalindrome(c, word.length()) == true)
//             cout << "The phrase is a palindrome.\n";
//         else
//             cout << "The phrase is not a palindrome\n";
//     }

//     // run generate_substring function
//     else if (choice == 5)
//     {
//         cout << "Enter a string: \n";
//         cin >> word;
//         v = generate_substrings(word);
//         cout << v.size() + 1 << " substrings\n";
//         for (int i = 0; i < v.size(); i++)
//             cout << v.at(i) << ", ";
//         cout << "\u2205" << endl;
//     }

//     // run drawpattern function
//     else
//     {
//         cout << "Enter a positive number: \n";
//         cin >> choice;
//         drawPattern(choice);
//     }
// }

// /*******************************************************************************
//  * int sum(int n)
//  *_________________________________________________________________
//  * <description>
//  * - returns sum of all numbers from 1 to n
//  *_________________________________________________________________
//  * PRECONDITIONS:
//  *  The following needs previous defined values:
//  *   int n: number for sum to be computed of
//  *
//  * POSTCONDITIONS:
//  *  returns the sum of all the numbers from 1 to n
//  *
//  *******************************************************************************/
// int sum(int n) // IN - number to be computed
// {
//     if (n < 1)
//         return n;
//     else
//         return n + sum(n - 1);
// }

// /*******************************************************************************
//  * int findmin(const int a[], int n)
//  *_________________________________________________________________
//  * <description>
//  * - returns minimum number from array
//  *_________________________________________________________________
//  * PRECONDITIONS:
//  *  The following needs previous defined values:
//  *   const int a[]: array to traverse through
//  *   int n: size of array
//  *
//  * POSTCONDITIONS:
//  *  returns the minimum integer in the array
//  *
//  *******************************************************************************/
// int findmin(const int a[], // IN - array to be computed
//             int n)         // IN - size of array
// {
//     if (n == 1)
//         return a[0];
//     return min(a[n - 1], findmin(a, n - 1));
// }

// /*******************************************************************************
//  * int findsum(const int a[], int n)
//  *_________________________________________________________________
//  * <description>
//  * - returns sum of all numbers in the array
//  *_________________________________________________________________
//  * PRECONDITIONS:
//  *  The following needs previous defined values:
//  *   const int a[]: array to traverse through
//  *   int n: size of array
//  *
//  * POSTCONDITIONS:
//  *  returns the sum of all the numbers in the array
//  *
//  *******************************************************************************/
// int findsum(const int a[], // IN - array to be computed
//             int n)         // IN - size of array
// {   
//     int sum = 0;        // CALC - store variable
//     int i = n - 1;

//     if (i < 0)
//         return sum;
//     else
//         return a[i] + findsum(a, n - 1);
// }

// /*******************************************************************************
//  * bool ispalindrome(const char a[], int n)
//  *_________________________________________________________________
//  * <description>
//  * - checks if char string is palindrome or not
//  *_________________________________________________________________
//  * PRECONDITIONS:
//  *  The following needs previous defined values:
//  *   const char a[]: char string to traverse through
//  *   int n: size of char array
//  *
//  * POSTCONDITIONS:
//  *  returns true if array is palindrome and false if it's not
//  *
//  *******************************************************************************/
// bool ispalindrome(const char a[], // IN - array to be computed
//                   int n)          // IN - size of array
// {

//     if (n <= 1)
//         return true;
//     if (a[0] != a[n - 1])
//         return false;
//     else
//         return ispalindrome(a + 1, n - 2);
// }

// /*******************************************************************************
//  * vector<string> generate_substrings(string s)
//  *_________________________________________________________________
//  * <description>
//  * - returns all the substrings of a string
//  *_________________________________________________________________
//  * PRECONDITIONS:
//  *  The following needs previous defined values:
//  *   string s: string to create substrings of
//  *
//  * POSTCONDITIONS:
//  *  returns vector of substrings of the string passed in
//  *
//  *******************************************************************************/
// vector<string> generate_substrings(string s) // IN - string to be computed
// {
//     vector<string> substring;   // CALC - vector to store substring
//     vector<string> second;      // CALC - vector to store substring
//     string temp;                // CALC - temp string to be added to vector
//     int n = s.length();
//     if (s.empty())
//         return substring;
//     else
//     {
//         for (int i = 0; i < s.length(); i++)
//         {
//             temp += s[i];
//             substring.push_back(temp);
//         }
//         temp = "";

//         second = generate_substrings(s.substr(1, s.length() - 1));
//         substring.insert(substring.end(), second.begin(), second.end());
//         return substring;
//     }
// }

// /*******************************************************************************
//  * void drawPattern(int n)
//  *_________________________________________________________________
//  * <description>
//  * - Draws a pattern based on the integer passed in
//  *_________________________________________________________________
//  * PRECONDITIONS:
//  *  The following needs previous defined values:
//  *   int n: number of the base star
//  *
//  * POSTCONDITIONS:
//  *  Displays a pattern using asterisks to the user
//  *
//  *******************************************************************************/
// void drawPattern(int n) // IN - number of the base star
// {
//     if (n < 1)
//         ;
//     else
//     {
//         for (int i = 0; i < n; i++)
//             cout << "*";
//         cout << endl;
//         drawPattern(n - 1);
//         for (int i = 0; i < n; i++)
//             cout << "*";
//         cout << endl;
//     }
// }