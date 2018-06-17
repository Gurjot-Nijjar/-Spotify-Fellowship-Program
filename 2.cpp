/*
Name : Gurjot Singh Nijjar
Program Name: Decode Strings
Problem 2: Given an encoded string, return its corresponding decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets
is repeated exactly k times. Note: k is guaranteed to be a positive integer.
Date: 6/15/18
Usage: Enter a String  that is "encoded" (in a specific format) following the rules of the input, and you will get a "decoded" version of it.
g++ -std=c++11 2.cpp -o decode
*/

#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>

using namespace std;

string decodeString(string s)
{
    string encoded = s; // take the input 
    string buffer = ""; // buffer and temporary string variable to hold encoded strings within and k values
    string base = "";   // base case number k which is outside the square brackets of the encoded string
    string buffer2 = ""; // buffer and temporary string variable to hold encoded strings within and k values and partially done encoded string
    string decoded = ""; // our final resulting decoded string
    int length = 0; // length of k to make sure it can take any positive integer (any number of digits)
    stack<char> stack_; // our stack to hold chars of the encoded string for the algorithm 
    int base_k; // base k integer value using from the base string 
    int k; // k integer that is needed for any encoded strings within the outer encoded strings

    // The initial algorithm will loop and stop until it hits the first outside square bracket
    // Once it sees a [, the program will have the length(digits) of the encoded strings K 
    while (encoded[length] != '[')
    {
        length++;
    }
    // label the base string and get the substring number from the encoded string 
    base = encoded.substr(0,length);
    // stoi function will convert a string that has an apparent number (throws exception if there is any character and no number)
    base_k = stoi(base);
    // push the squared bracket into the stack to start the algorithm
    stack_.push(encoded[length]);
    // our case: go through the string until the stack is empty (stack already has one char inside)
    while (stack_.empty() != true)
    {
        length++;
        stack_.push(encoded[length]);
        //loop through the chars in the string and push into the stack data structure
        
        // The ] is an indicator for when the encoded string bracket stops and we can then start popping off the stack to complete the decoding process
        if (stack_.top() == ']')
        {
            stack_.pop(); // pop the ] in the stack we do not need it know 
            
            // the loop is used to get the characters inside the string and concatenate the chars in the string individually until you see the [
            while (stack_.top() != '[')
            {
                buffer = stack_.top() + buffer;
                stack_.pop();
            }
            // now we have buffers to hold the resulting encoded string inside the brackets
            buffer2 = buffer2 + buffer;
            buffer = ""; // this buffer is used for the number value before the encoded string
            
            stack_.pop(); // pop the [, as we do not need it 

            if (stack_.empty() != true)
            {
                // loop checks to make sure it only sees a number and not a bracket or an alphabet
                while(stack_.top() != '[' && (!isalpha(stack_.top())))
                {
                // concatenate the numbers (to how many digits are before the bracket) 
                buffer = stack_.top() + buffer;
                stack_.pop();
                }
                
                // set the k value to the resulting string of numbers using stoi
        
                k = stoi(buffer);
                buffer = buffer2;
                buffer2 = "";
                // concatenate the string  k times from the  given string inside the brackets
                for (int l = 0; l < k; l++)
                {
                    buffer2 += buffer; 
                }
                //get resulting decoded value after the concatenation 
                decoded = decoded + buffer2;
                buffer = "";
                buffer2 = "";
                
            }
            // if stack is empty no encoded string within the encoded string
            else
            {
            decoded = decoded + buffer2; // get original buffer and concatenate the empty decoded string
            }
        }

    }
    // set buffer to equal to the decoded from the resulting encoding string that happened inside the main encoding string 
    
    buffer2 = decoded;
    decoded = "";
    //using from whatever resulted from inside the encoded string we can now use the base k to output are fully decoded string
     for (int b = 0; b < base_k; b++)
        {
            decoded = buffer2 + decoded;
        }
    
    return decoded;
    
   

}


int main()
{
    string s;
    cout << "Given an encoded string, return its corresponding decoded string." << endl;
    cout << "The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets";
    cout << " is repeated exactly k times. Note: k is guaranteed to be a positive integer. " << endl;

    cout << "Enter String s: ";
    cin >> s;
    cout << "Here is the decoded string: " << decodeString(s) << endl;
    return 0;
}