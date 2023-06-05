/* 
 * File:   main.cpp
 * Author: Brittany Chan
 * Created on May 1, 2023, 8:32 AM
 * Purpose: Initializing the game and assigning a char variable to every letter in the word. Allow user to input if they are ready to start and if 'y', the program will display the starting hangman design
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
    fstream file; //Word File
    string word, wrngAns;
    char choice, ltr1, ltr2, ltr3, ltr4, ltr5, ltr6, mode,
         ans1, ans2, ans3, ans4, ans5, ans6;
    unsigned int numLtrs, strike, linNum, line;
    float score;
    bool status;
    
    //Initialize or input i.e. set variable values
 
    numLtrs=(time(0)%4)+3; //Random number of letters generator
                            //+3 to count for when the number is 0

    strike = 0;
    status = true;
    
    cout << "\t-----Welcome to the Hangman Game-----" << endl;
    cout << "Would you like to play solo or multiplayer?";
    cout << endl << "- Press 1 for 1 Player, and 2 for 2 Players." << endl;
    cin >> mode;
    
    
    
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
    
     if (numLtrs == 3) { //assigns each letter in the word to a char to allow future manipulation
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
         for (int ltrs = 0; ltrs < word.length(); ltrs++) { //Checks # of letters and printing blanks for each letter
            cout << setw(5) << "__ "; 
        }
        
        do {
            for (int j = 0; strike < 6; j++) {
                if (strike == 0) {
                    cout << endl << "\nEnter a letter to take a guess: ";
                    cin >> ans1;
                    if (ans1 == ltr1 || ans1 == ltr2 || ans1 == ltr3 || ans1 == ltr4 || ans1 == ltr5 || ans1 == ltr6) {
                        status = false;
                        cout << "\t-*-That was a nice guess!-*-";
                    } else {
                        strike++;
                        status = true;
                        cout << "\n\tOops try again!";
                        cout << endl << "\t Strike: " << strike;
                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl;

                    }
                }
                cout << "\nTake another guess: ";
                cin >> ans1;
                if (ans1 == ltr1 || ans1 == ltr2 || ans1 == ltr3 || ans1 == ltr4 || ans1 == ltr5 || ans1 == ltr6) {
                    status = false;
                    cout << "\t-*-That was a nice guess!-*-";
                    //implement code that will replace one of the blanks with the letter entered 
                } else {
                    strike++; //increments strike every time the user inputs a wrong letter
                    status = true;
                    if (strike == 2) {
                    cout << "\n\tOops try again!";
                    cout << endl << "\t Strike: " << strike;

                    cout << endl << setw(20) << "* - - - *" << endl;
                    cout << setw(12) << "|"  << setw(8) << "|" << endl;
                    cout << setw(12) << "O"  << setw(8) << "|" << endl;
                    cout << setw(12) << "|"  << setw(8) << "|" << endl;
                    cout << setw(20) << "|" << endl;
                    cout << setw(20) << "|" << endl;
                    cout << setw(20) << "|" << endl;
                    cout << setw(22) << "=============" << endl;
                    } else if (strike == 3) {
                        cout << "\n\tOops try again!";
                        cout << endl << "\t Strike: " << strike;
                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(12) << "/|"  << setw(8) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl;

                    } else if (strike == 4) {
                        cout << "\n\tOops try again!";
                        cout << endl << "\t Strike: " << strike;

                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(13) << "/|\\"  << setw(7) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl;

                    } else if (strike == 5) {
                        cout << "\n\tOops try again!";
                        cout << endl << "\t Strike: " << strike;

                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(13) << "/|\\"  << setw(7) << "|" << endl;
                        cout << setw(11) << "/"  << setw(9) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl;

                    } else {
                        cout << "\n\tOops try again!";
                        cout << endl << "\t Strike: " << strike << endl;
                        cout << "      *Oh no! You died!*";

                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(13) << "/|\\"  << setw(7) << "|" << endl;
                        cout << setw(13) << "/ \\"  << setw(7) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl; 
                    }
                }
            }
               
        } while (strike != 6);
        
        

    //Exit stage right or left!
    return 0;
    } 
}
