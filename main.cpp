/*************************************************************************************
 * Program:
 *    Assignment 01, Genetic Genealogy
 *    Brother Dudley, CS165
 * Author:
 *    Josh Pearce
 * Summary:
 *    This program is designed to capture genetic data from the user,
 *    determine how many relatives the user would like to use in a genetic comparison,
 *    capture genetic data about the family members, and compare the user's
 *    information to their relatives' to determine how closely they match.
 *
 *    Estimated: 5.0 hrs
 *    Actual:    4.0 hrs
 *       Please describe briefly what was the most difficult part.
 **************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/*************************************************************************************
 * Get Self DNA Markers
 * Collect a 10 digit DNA sequence for the user and store it
 **************************************************************************************/
string getSelfDNAMarkers()
{
    string DNA;
    cout << "Enter your DNA sequence: ";
    cin >> DNA;
    return DNA;
}

/*************************************************************************************
 * Get Relative Names
 * Collect the names of the user's relatives and store them in an array
 **************************************************************************************/
void getRelativeNames(string names[], int const quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        cout << "Please enter the name of relative #"
             << i + 1
             << ": ";
        cin >> names[i];
    }
    return;
}

/*************************************************************************************
 * Get Relative DNA
 * Collect the DNA sequences for the given number of relatives
 **************************************************************************************/
void getRelativeDNA(string names[], string relativeDNA[], int const quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        cout << "Please enter the DNA sequence for "
             << names[i]
             << ": ";
        cin >> relativeDNA[i];
    }
}

/*************************************************************************************
 * Compare DNA
 * Compare the user's DNA to their family's DNA to see how closely they are related
 **************************************************************************************/
void compareDNA(string names[], string relativeDNA[], string myDNA, int quantity)
{
    for (int x = 0; x < quantity; x++)
    {
        int percent = 0;
        for (int i = 0; i < myDNA.length(); i++)
       {
           if (myDNA.at(i) == relativeDNA[x].at(i))
           {
               percent += 10;
           }
       }
        cout << "Percent match for "
             << names[x]
             << ": "
             << percent
             << "%" << endl;
    }
}

/*************************************************************************************
 * tell what main does
 *
 **************************************************************************************/
int main()
{
    int quantity;
    string names[50] = {};
    string relativeDNA[50] = {};
    string myDNA = getSelfDNAMarkers();
    cout << "Enter the number of potential relatives: ";
    cin >> quantity;
    cout << endl;
    getRelativeNames(names, quantity);
    cout << endl;
    getRelativeDNA(names, relativeDNA, quantity);
    cout << endl;
    compareDNA(names, relativeDNA, myDNA, quantity);
    
    return 0;
}
