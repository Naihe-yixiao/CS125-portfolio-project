// This program accepts grades and calculate the total numbers of populations in each grade cetegory

// Name: Hongsreng PHENG
// Section: 2

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// A function that accept an int in string and convert to an int
int stringToNum(string numInString);

int main ()
{
    // Prompt user for scores seperated by a space
    string unfilteredScores;
    cout << "Enter Exam Scores: ";
    getline (cin,unfilteredScores);

    // Declare variable to store the result
    int numberOfA = 0;
    int numberOfB = 0;
    int numberOfC = 0;
    int numberOfD = 0;
    int numberOfF = 0;
    int totalScores = 0;

    // Loop through each character until end of line or see the sentinal value
    for (int i = 0; i < unfilteredScores.length() && unfilteredScores[i] != '-'; i++)
    {
        // Capture of the string of numbers
        string numInString = "";
        while(unfilteredScores[i] != ' ' && i != unfilteredScores.length() && unfilteredScores[i] != '-')
        {
            if (unfilteredScores[i] >= '0' && unfilteredScores[i] <= '9')
            {
                numInString += unfilteredScores[i];
                i++;
            }
            else
            {
                cout << "invalid input detected" << endl;
                return 1;
            }
        }

        // Convert the string into an integer and evaulate its category
        int num = stringToNum(numInString);
        if (num >= 90 and num <= 100)
        {
            numberOfA++;
        }
        else if (num >= 80 and num <= 89)
        {
            numberOfB++;
        }
        else if (num >= 70 and num <= 79)
        {
            numberOfC++;
        }
        else if (num >= 60 and num <= 69)
        {
            numberOfD++;
        }
        else if (num >= 0 and num <= 59)
        {
            numberOfF++;
        }
        else
        {
            cout << "invalid input detected" << endl;
            return 2;
        }

        totalScores++;
    } 
    // Display all populations of each category
    cout << "Number of A's: " << numberOfA << endl;
    cout << "Number of B's: " << numberOfB << endl;
    cout << "Number of C's: " << numberOfC << endl;
    cout << "Number of D's: " << numberOfD << endl;
    cout << "Number of F's: " << numberOfF << endl;
    cout << "Total number of scores: " << totalScores << endl;
    return 0;
}

int stringToNum(string numInString)
{
    int num = 0;
    for (int i = 0; i < numInString.length(); i++)
    {
        num *= 10;
        num += (numInString[i] - '0');
    }
    return num;
}