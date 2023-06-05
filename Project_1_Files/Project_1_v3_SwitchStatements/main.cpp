/* 
 * File:   main.cpp
 * Author: Brittany Chan
 * Created on May 1, 2023, 8:32 AM
 * Purpose:  Creating a switch statement for the status then output hangman
 *           display with matching strikes. Needs proper implementation for the 
 *           outputted blanks that represents each letter in the word. Accepts
 *           2 players but needs better implementation
 *           
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
#include <iomanip>   //Formatting Library - setw
#include <cmath>     //Math Library
#include <fstream>   //Creating input/output file
#include <string>   //String Library for getline fcn

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
    status = false;
    score = 6;
    line = 0;
    string WORD;
    
    cout << "\t-----Welcome to the Hangman Game-----" << endl;
    cout << "Would you like to play solo or multiplayer?";
    cout << endl << "- Press 1 for 1 Player, and any other key for 2 Players." << endl;
    //Only 2 Player works for now
    cin >> mode;
 
    
    if (static_cast<int>(mode) == 49) {
            file.open("ListOfWords.txt", ios::in); //Reading in random words from a word file
            linNum = (time(0)%17+1);   //Generates a random number and it will find a word in that 
                                       //line in the word file
            cout << "The line number is "<< linNum << endl;
            while (!file.eof()) {
                line++;

                getline(file, word);
                if (line == linNum) {
                    WORD = word;
                }
               
                cout << endl << WORD << endl;
            }
                 //More proper implementation needed
            
        
            cout << "Are you ready to start? (y/n)" << endl;
            cin >> choice;

            file.close();
    } else {
        cout << "Enter a word for Player 2 to guess that is ";
        cout << numLtrs << " letters long" << endl;
        cin >> word; 
        
        //Implement another input validation to make sure that user did not input a number
        if (word.length() != numLtrs) { //Validates whether user inputs the right word length
            do {
                cout << endl << "**Please enter a word " << numLtrs << " letters long**" << endl;
                cin >> word;
                
                 word.length() == numLtrs? cout << "Are you ready to start? (y/n)" << endl: cout << ""; 
                      cin >> choice;                          //If word length fits the requirement, program will continue

                
            } while (word.length() != numLtrs);
        }  else {
            cout << "Are you ready to start? (y/n)" << endl;
            cin >> choice;
        }
    }
    
    
     if (numLtrs == 3) { //assigns each letter in the word to a char to allow future manipulation
         ltr1 = word[0]; //Letter 1 to the first letter in the given word
         ltr2 = word[1]; //Letter 2 to the first letter in the given word
         ltr3 = word[2]; //And so on...
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
    
    if (choice == 'y' || choice == 'Y') { //Tests whether the user wants to continue with the game, 
                                          //Else program will exit
        cout << endl << endl; //Display how the hangman looks like before inputting answers
        cout << setw(20) << "* - - - *" << endl;
        cout << setw(12) << "|" <<setw(8) << "|" << endl;
        cout << setw(20) << "|" << endl;
        cout << setw(20) << "|" << endl;
        cout << setw(20) << "|" << endl;
        cout << setw(20) << "|" << endl;
        cout << setw(22) << "=============" << endl << endl;
        cout << setw(9) << "\t The word is:" << endl << endl;
        cout << "  ";
        for (int ltrs = 0; ltrs < word.length(); ltrs++) { //Checks # of letters and printing blanks for each letter
            cout << setw(5) << "__ "; //Blanks to represent each letter in the word
        }
        

        for (int j = 0; strike < 6; j++) { //Tests that the user still has less than 6 strikes, else 
                                           //Game will end
            if (strike == 0) {
                cout << endl << "\nEnter a letter to take a guess: "; //For the first guess
                cin >> ans1;
                //Tests whether answer is correct or not
                if (ans1 == ltr1 || ans1 == ltr2 || ans1 == ltr3 || ans1 == ltr4 || ans1 == ltr5 || ans1 == ltr6) {
                    status = false; //Sets status to false and will be passed on 
                                    //to the switch statement to determine what will be displayed

                } else {
                    strike++; //Strike is incremented every time player makes a wrong guess
                    status = true; //Sets status to false and will be passed on 
                                   //to the switch statement to determine what will be displayed
                    wrngAns = ans1;


                }
            } else {
                cout << "\nTake another guess: "; //Following guesses will be "another" guess
                cin >> ans1;
                //if next ans == prevAns
                        //cout << You have already inputted this answer
                if (ans1 == ltr1 || ans1 == ltr2 || ans1 == ltr3 || ans1 == ltr4 || ans1 == ltr5 || ans1 == ltr6) {
                    status = false;
                    //if ans1 == ltr in word
                        //if ltr != ans1: cout << __ (blank space) 
                        //else cout << ltr
                    //if user inputs the same answer as before, prompt to enter another letter
                    //if user has completed the word, program exits and the guesser wins
                } else {
                    strike++; //increments strike every time the user inputs a wrong letter
                    status = true;
                    wrngAns += ans1; //if answer is wrong, it will be appended to the wrong answer string
                }
            }

            switch(status) { //switch statement that tests whether status is true/false
                             //different prints different parts of the display depending on the # of strikes already made
                case true: {  
                    score = sqrt(score);
                    //score--;
                    //Prints out the hangman based on how many strikes user has 
                     if (strike != 6) {
                         cout << "\n\tOops try again!";
                     }
                     cout << endl << "\tStrike: " << strike;
                     cout << endl << setprecision(2) << fixed << "\tScore: " << score << endl;
                    if (strike == 1) { 
                        //Prints the head of Hangman
                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl;
                        cout << "Wrong guesses: " << wrngAns; //Prints out letter if answer is correct
                    } else if (strike == 2) {
                        //Prints the Body of Hangman
                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl;
                        cout << "Wrong guesses: " << wrngAns;
                    } else if (strike == 3) {
                        //Prints an arm of Hangman
                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(12) << "/|"  << setw(8) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl;
                        cout << "Wrong guesses: " << wrngAns;

                    } else if (strike == 4) {
                        //Prints other arm of Hangman
                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(13) << "/|\\"  << setw(7) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl;
                        cout << "Wrong guesses: " << wrngAns;

                    } else if (strike == 5) {
                        //Prints a leg of Hangman
                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(13) << "/|\\"  << setw(7) << "|" << endl;
                        cout << setw(11) << "/"  << setw(9) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl;
                        cout << "Wrong guesses: " << wrngAns;

                    } else {
                        //Prints the other leg of Hangman
                        //Player has lost the game
                        cout << endl << "      *Oh no! You died!*";
                        cout << endl << "    *The word was:'" << word << "'*";

                        cout << endl << setw(20) << "* - - - *" << endl;
                        cout << setw(12) << "|"  << setw(8) << "|" << endl;
                        cout << setw(12) << "O"  << setw(8) << "|" << endl;
                        cout << setw(13) << "/|\\"  << setw(7) << "|" << endl;
                        cout << setw(13) << "/ \\"  << setw(7) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(20) << "|" << endl;
                        cout << setw(22) << "=============" << endl; 
                        cout << "Wrong guesses: " << wrngAns;
                    }
                   break;
                }
                case false: { //Tells user their guess was right
                    score += 5;
                    cout <<"\t-*-That was a nice guess!-*-";
                  
                    cout << endl << setprecision(2) << fixed << "\tScore: " << score << endl;
                    break;
                }

            }

        }
    }

    //Display the outputs
        
    //Clean up files
    file.close();

    //Exit stage right or left!
    return 0;
    
}
