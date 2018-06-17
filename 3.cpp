/*
Name : Gurjot Singh Nijjar
Program Name: Change Possibilities
Problem 3: Your quirky boss collects rare, old coins. 
           They found out you're a programmer and asked you to solve something 
           they've been wondering for a long time.  Write a function that, given an 
           amount of money and an array of coin denominations, computes the number of ways 
           to make the amount of money with coins of the available denominations. 
Date : 6/16/18
Usage: The user inputs a number when prompted and and also inputs brackets with numbers that are seperated by commas, then the program outputs the correct response after the input is give.
g++ -std=c++11 3.cpp -o change
*/


#include <iostream>
#include <string>
#include <cstring>
#include <vector>


using namespace std;



void changePossibilities(int amount, string denominations)
{
    int a = amount; // amount given by user
    string d = denominations; // denominations string given by user
    vector<int> denom;// parse the string and store the numbers given inside the denominations string
    string buffer; // buffer to temporary hold the string value of the number
    vector<int> comb; // vector holds the possible combinations where the position [i] = the amount [a].

    for (int u = 0; u < a + 1; u++)
    {
        comb.push_back(0); // set each solutions to zero  to initialize the vector
    }
   //base case if there is a zero amount given by user
    comb[0] = 1;


    // loop through the inputted denomination string until it hits the end (square bracket)
    for (int q = 1; q < d.length(); q++ )
    {
        if(d[q] == ',' || d[q] == ']') // comma seperates the integers from each other and the end of the string
        {
            denom.push_back(stoi(buffer)); // push the int value we get from the stoi function with the buffer string
            buffer = "";
        }

        else
        {
            buffer = buffer + d[q]; // make the string concatenate the chars that are integers in the buffer
        }
    }

    // you want to have a loop that iterates through each denomination that picks coins. It goes through each denomination and doesn't overlap when gathering combinations 
    for (int i = 0; i < denom.size(); i++)
    {
        for (int j = denom[i]; j < a+1; j++) // j will be equal to a denomination and then you have to let the loop run till whatever a + 1 (to account for what is a, so it can account for the amount)
        {
            comb[j] += comb[j-(denom[i])]; // the algorithm that decides how many combinations starting with the base case and working up each denomination 
        }
    }

    
    cout << "There are " << comb[a] << " ways to make " << a << "¢ with the given denominations." << endl;
    
}

int main()
{
    int amount;
    string denominations;
    cout << "Given an amount of money and an array of coin denominations, the program computes the number of ways to make the amount of money with the given denominations" << endl;
    cout << "Enter amount in ¢: ";
    cin >> amount;
    cout << amount << "¢" << endl;
    cout << "Enter denominations (¢) inside Square Brackets such as [n1,n2,...,ni], NOTE: ¢ is not necessary, n is a number. " << endl;
    cin >> denominations;
    changePossibilities(amount,denominations);
    return 0;
}