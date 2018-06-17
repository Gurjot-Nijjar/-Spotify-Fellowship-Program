/*
Name: Gurjot Singh Nijjar
Program Name: Sort By Strings
Problem 1 : Sort the letters in the string s by the order they occur in the string t. 
           You can assume t will not have repetitive characters. 
           For s = "weather" and t = "therapyw", the output should be sortByString(s, t) = "theeraw". 
           For s = "good" and t = "odg", the output should be sortByString(s, t) = "oodg".
Date : 6/13/18
Usage : Enter in two strings, one that needs to be sorted and the other input is the string in which they need to be ordered by, the program will return an output to the user.
g++ -std=c++11 1.cpp -o sort
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void sortByStrings(string s, string t)
{
    string tosort = s; // take the initial string you need to sort
    string sort = t; // take the string that has the order you need ( our rule)
    vector<char> s_; // a vector of chars  to be used for  the S string
    vector<char> t_; // a vector of chars to be used for  the T string
    vector<char> new_string; // the output characters in the string
    string a; // the sorted out and final string



    for (int i = 0; i < tosort.length(); i++)
    {
        s_.push_back(tosort[i]); // store the characters of the inputted string into a vector of chars
    }

    for (int j = 0; j < sort.length(); j++)
    {
        t_.push_back(sort[j]);  // store the characters of the inputted string t in vector of chars
    }

    // nested for loop; outer loop needs to go through each character in T string and match it with the characters in the S string
    for (int x = 0; x < t_.size(); x++ )
    {
        for (int q = 0; q < s_.size(); q++)
        {
            if (t_[x] == s_[q]) // checks to make sure if a character in T string is found in any of the characters of the S string. If it is found you push it into the vector. The rule has to be by the order of the T string so we put the character of the T string inside it.
            {
                new_string.push_back(t_[x]);
                // also accounts for multiple occurences of a character
            }
        }
    }

    a.resize(new_string.size());
    //resize the empty string to account for the vector size of the chars

    for (int l = 0; l < new_string.size() ; l++)
    {
        a[l] = new_string[l];
    }
    //set the characters inside the string to equal to the characters inside the new string vector


    cout << "Sorted String: " <<  a << endl;


}

int main()
{
    string s;
    string t;
    cout << "Sort the letters in the string s by the order they occur in the string t. You can assume t will not have repetitive characters. " << endl;
    cout << "Enter String s: ";
    cin >> s;
    cout << "Enter String t: ";
    
    cin  >> t;
    

    sortByStrings(s, t);

    return 0;
}
