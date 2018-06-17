# Spotify-Fellowship-Program

Compiling Instructions on Linux Terminal
g++ -std=c++11 [numberofproblem].cpp -o [nameofprogram]
Executing Program
./[nameofprogram]


The questions in this section test your general programming knowledge. You must solve all of these questions with basic programming constructs. You may not use any large libraries or frameworks to solve these questions.

You may use the Internet to conduct research as you would at a job to solve any or these problems: if you need help to figure out the approach to a problem, feel free to find resources that help you to understand how to approach these types of programs generally, but you may NOT copy others' code. The solutions you provide here must be your own work. 

Please upload the answers to each of the questions below into your Github repo and provide us with that link. Put each answer in its own file, with the title being the number of the question, and paste the link to your repo in the textbox below.

You may use any language you'd like to complete these questions, but be sure to choose just one. 
*******************************************************
Question 1 -- sortByStrings(s,t): Sort the letters in the string s by the order they occur in the string t. You can assume t will not have repetitive characters. For s = "weather" and t = "therapyw", the output should be sortByString(s, t) = "theeraw". For s = "good" and t = "odg", the output should be sortByString(s, t) = "oodg".

Question 2 -- decodeString(s): Given an encoded string, return its corresponding decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is repeated exactly k times. Note: k is guaranteed to be a positive integer.

For s = "4[ab]", the output should be decodeString(s) = "abababab"
For s = "2[b3[a]]", the output should be decodeString(s) = "baaabaaa"

Question 3 -- changePossibilities(amount,amount): Your quirky boss collects rare, old coins. They found out you're a programmer and asked you to solve something they've been wondering for a long time.

Write a function that, given an amount of money and an array of coin denominations, computes the number of ways to make the amount of money with coins of the available denominations.

Example: for amount=4 (4¢) and denominations=[1,2,3] (1¢, 2¢ and 3¢), your program would output 4—the number of ways to make 4¢ with those denominations:

1¢, 1¢, 1¢, 1¢
1¢, 1¢, 2¢
1¢, 3¢
2¢, 2¢
