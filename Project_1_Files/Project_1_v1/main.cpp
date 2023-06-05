/* 
 * File:   main.cpp
 * Author: Brittany Chan
 * Created on May 1, 2023, 8:32 AM
 * Purpose: Purpose: Initializing the game and assigning a char variable to 
 *          every letter in the word. Allow user to input if they are ready to 
 *          start and if 'y', the program will display the starting hangman 
 *          design. This version also only allows 1 player
 *           
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
#include <iomanip>   //Formatting Library - setw
#include <cmath>     //Math Library
#include <fstream>   //Creating input/output file

using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed

//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
  
    //srand(numLtrs);
    
    //Declare Variables
    fstream wrdFile; //Word File
    string word;
    char choice, ltr1, ltr2, ltr3, ltr4, ltr5, ltr6,
         ans1, ans2, ans3, ans4, ans5, ans6;
    unsigned int numLtrs, strike;
    
    //Initialize or input i.e. set variable values
    wrdFile.open("ListOfWords.txt", ios::in); //Reading in random words from a word file
    numLtrs=(time(0)%3)+3; //Random number of letters generator
                            //+3 to count for when the number is 0
    strike = 0;
    
    cout << "\t-----Welcome to the Hangman Game-----" << endl;
    cout << "Enter a word for Player 2 to guess that is ";
    cout << numLtrs << " letters long" << endl;
    cin >> word; 
    
    if (word.length() != numLtrs) { //Validates whether user inputs the right word length
        do {
            cout << endl << "**Please enter a word " << numLtrs << " letters long**" << endl;
            cin >> word;
            
            if (word.length() == numLtrs) {
                cout << "Are you ready to start? (y/n)" << endl;
                cin >> choice;
            }
        } while (word.length() != numLtrs);
    }  else {
        cout << "Are you ready to start? (y/n)" << endl;
        cin >> choice;
         }
    
     if (numLtrs == 3) {
         ltr1 = word[0];
         ltr2 = word[1];
         ltr3 = word[2];
     } else if (numLtrs == 4) {
         ltr1 = word[0];
         ltr2 = word[1];
         ltr3 = word[2];
         ltr4 = word[3];
     } else if (numLtrs == 5) {
         ltr1 = word[0];
         ltr2 = word[1];
         ltr3 = word[2];
         ltr4 = word[3];
         ltr5 = word[4];
     } else {
         ltr1 = word[0];
         ltr2 = word[1];
         ltr3 = word[2];
         ltr4 = word[3];
         ltr5 = word[4];
         ltr6 = word[5];
     }
     
         
//    } else if (numLtrs == 4) {
//        cin >> ltr1 >> ltr2 >> ltr3 >> ltr4;
//    } else if (numLtrs == 5) {
//        cin >> ltr1 >> ltr2 >> ltr3 >> ltr4 >> ltr5;
//    } else {
//        cin >> ltr1 >> ltr2 >> ltr3 >> ltr4 >> ltr5 >> ltr6;
//    }
         

    //Map inputs -> outputs
    
    if (choice == 'y' || choice == 'Y') {
        cout << endl << endl;
        cout << setw(20) << "* - - - *" << endl;
        cout << setw(12) << "|" <<setw(8) << "|" << endl;
        cout << setw(20) << "|" << endl;
        cout << setw(20) << "|" << endl;
        cout << setw(20) << "|" << endl;
        cout << setw(20) << "|" << endl;
        cout << setw(22) << "=============" << endl << endl;
        cout << setw(9) << "\t The word is:" << endl << endl;

        for (int ltrs = 0; ltrs < word.length(); ltrs++) { //Checks # of letters and printing blanks for each letter
            cout << setw(5) << "__ "; 
        }
        
        
       

    //Display the outputs

    //Exit stage right or left!
    return 0;
    } 
}

