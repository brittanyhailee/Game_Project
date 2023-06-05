/* 
 * File:   main.cpp
 * Author: Brittany Chan
 * Created on March 17, 2019, 8:36 AM
 * Purpose:  This version replaces blanks with letters when the input is correct
 *           
 */

//System Libraries
#include <iostream> //I/O Library
#include <cstdlib>  //Random Function Library
#include <ctime>    //Time Library
#include <iomanip>  //Formatting Library - setw
#include <cmath>    //Math Library
#include <fstream>  //Creating input/output file
#include <string>   //String Library for getline fcn
#include <vector>   //Vector library

using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed

//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void init();
int getChc();
string setPlyr(char, string &, unsigned int &); //Sets mode to preferred number of players
int lnthChk(string, int, char &); //Checks whether the length of the word fits required length
void gmDsply(char, string , string[], int); //Hangman display
int chckAns(string, char, string[], int, unsigned int &, vector<char>, unsigned int &, unsigned int &, bool &);
char guess(char &);
void hngMan(unsigned int);
void gmStat(vector<char>, string[], int, unsigned int, unsigned int, bool);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream file;
    string word;
    unsigned int numLtrs, strike, linNum, score, correct;
    char choice, ans;
    bool status;
    vector<char> wrngAns;
    
    
    //Initialize or input i.e. set variable values
    numLtrs=(time(0)%4)+3;
    score = 6;
    correct = 0;
    strike = 0;
    
    
    init();
    //Map inputs -> outputs
    choice = getChc(); 
    //cout << choice;
    
    setPlyr(choice, word, numLtrs);
    string answer[numLtrs];


    lnthChk(word, numLtrs, choice);
    
    gmDsply(choice, word, answer, numLtrs);
    while (strike != 6 && correct != word.length()) {
        
        //hngMan(strike);
        chckAns(word, guess(ans), answer, numLtrs, correct, wrngAns, score, strike, status);
       
        
        if (status == true) {
            wrngAns.push_back(ans);
        } 
       
        gmStat(wrngAns, answer, numLtrs, score, strike, status);

    }
    if (correct == word.length()) {
        cout << "\n\tCongratulations! You won! \\(＾O＾)/";
        
    } 
    if (strike == 6) {
        cout << "\n\tYou Died! ˙◠˙";
        
    }
    cout << setw(3) << "\n\tThe word was '" << word <<"'" << endl;
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}

void init() {
    cout << "\t-----Welcome to the Hangman Game-----" << endl;
    cout << "Would you like to play solo or multiplayer?";
    cout << endl << "- Press 1 for 1 Player, and any other key for 2 Players." << endl;
    //Only 2 Player works for now
    
}

int getChc() {
    char mode;
    cin >> mode;
    return mode;
}

string setPlyr(char choice, string &word, unsigned int &numLtrs) {
    int linNum, line;
    fstream file;
    string temp; 
    line = 1;
    if (static_cast<int>(choice) == 49) {
            file.open("ListOfWords.txt", ios::in); //Reading in random words from a word file
            linNum = (time(0)%18+1);   //Generates a random number and it will find a word in that 
                                       //line in the word file

            //cout << "The line number is "<< linNum << endl;
              while (!file.eof()) {
               
                getline(file, temp);
                if (line == linNum) {
                    word = temp;
                    numLtrs = word.length();
                }
                line++;
            }
            cout << "Randomly Generating a word..." << endl;

            
    } else {
        cout << "Enter a word for Player 2 to guess that is ";
        cout << numLtrs << " letters long" << endl;
        cin >> word; 
    //}
    }
    //cout << "The word is " << word;
    return word;
}

int lnthChk(string word, int length, char &choice) {
    if (static_cast<int>(choice) != 49) {
        while (word.length() != length) { //Validates whether user inputs the right word length
            //do {
            cout << endl << "**Please enter a word " << length << " letters long**" << endl;
            cin >> word;
           
        }
        cout << "Are you ready to start? (y/n)" << endl; 
        cin >> choice; 
    } else {
    cout << "Are you ready to start? (y/n)" << endl; 
    cin >> choice; 
    }
    return choice;
}


void gmDsply(char choice, string word, string answer[], int size) {
    unsigned int strike = 0;
    if (choice == 'y' || choice == 'Y') { //Tests whether the user wants to continue with the game, 
                                  //Else program will exit
        hngMan(strike);
        cout << setw(3) << "\tThe word is: \n";
        for (int ltrs = 0; ltrs < word.length(); ltrs++) { //Checks # of letters and printing blanks for each letter
            answer[ltrs] = '_';
            
            size == 3? cout << "   " << setw(4) << answer[ltrs]:
                         cout << " " << setw(5) << answer[ltrs]; //Blanks to represent each letter in the word
        }
    } else {
        cout << "Exiting game..." << endl;
        exit(0);
    }
}

char guess(char &ans) {
    cout << endl << "\nEnter a letter to take a guess: ";
    cin >> ans;
    return ans;
}

int chckAns(string word, char ans, string answer[], int size, unsigned int &correct, vector<char> wrngAns, unsigned int &score, 
            unsigned int &strike, bool &status) {
    status = true;
    
    for (int i = 0; i < word.length(); i++) {
        if (ans == word[i] || ans == (word[i]+32)) {
            status = false;
            correct++;
            answer[i] = word[i];

            //cout << "Correct letter: "<< answer[i] << endl;
                //cout << " " << word[i];
        }
//            else {
//                //status = true;
//                cout << " __ ";
//            }
        }
    
    if (status == false) {
        score+=5;
        cout << "\n\t-*-That was a nice guess!-*-";
        status = false;
    } else {
        cout << "\n\tOops try again!";
        score = sqrt(score);
        strike++;
        status = true;
        //status = true;
        }
    //status = true;
     
    
    //status = true;
    
//    if (status == false) {
//        strike += 0;
//        score += 5;
//        cout << endl <<"\t-*-That was a nice guess!-*-" << endl;
//    } else {
//        strike++;
//        score = sqrt(score);
//        cout << "\n\tOops try again!";
//        cout << endl << setprecision(2) << fixed << "\tScore: " << score << endl;
//        hngMan(strike);
//        wrngAns.push_back(ans);
//
//    }
    return status;
}

void gmStat(vector<char> wrngAns, string answer[], int size, unsigned int score, unsigned int strike, bool status) {
    
    cout << endl << setprecision(2) << fixed << "\n\tScore: " << score;
    cout << "\n\tStrike: " << strike;
    cout << "\n\tWrong Guesses: ";
    for (int i = 0; i < wrngAns.size(); i++) {
        cout << wrngAns[i] << " ";
    }
    hngMan(strike);
    cout << "\tThe word is: " << endl;
   
    for (int i = 0; i < size; i++) {
        //cout << answer[i] << " ";
         size == 3? cout << "   " << setw(4) << answer[i]:
                         cout << " " << setw(5) << answer[i];
        
    }          
}
    

void hngMan(unsigned int strike) {
    switch (strike) {
        case 0: {
            cout << endl << endl; //Display how the hangman looks like before inputting answers
            cout << setw(20) << "* - - - *" << endl;
            cout << setw(12) << "|" <<setw(8) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(22) << "=============" << endl << endl;
            //cout << setw(9) << "\t The word is:" << endl << endl;
            //cout << "  ";
            break;
        }
        case 1: {
            cout << endl << setw(20) << "* - - - *" << endl;
            cout << setw(12) << "|"  << setw(8) << "|" << endl;
            cout << setw(12) << "O"  << setw(8) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(22) << "=============" << endl;
            //cout << setw(9) << "\t The word is:" << endl << endl;
            //cout << "  ";
            break;
        }
        case 2: {
            cout << endl << setw(20) << "* - - - *" << endl;
            cout << setw(12) << "|"  << setw(8) << "|" << endl;
            cout << setw(12) << "O"  << setw(8) << "|" << endl;
            cout << setw(12) << "|"  << setw(8) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(22) << "=============" << endl;
            break;
        }
        case 3: {
            cout << endl << setw(20) << "* - - - *" << endl;
            cout << setw(12) << "|"  << setw(8) << "|" << endl;
            cout << setw(12) << "O"  << setw(8) << "|" << endl;
            cout << setw(12) << "/|"  << setw(8) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(22) << "=============" << endl;
            break;
        }
        case 4: {
            cout << endl << setw(20) << "* - - - *" << endl;
            cout << setw(12) << "|"  << setw(8) << "|" << endl;
            cout << setw(12) << "O"  << setw(8) << "|" << endl;
            cout << setw(13) << "/|\\"  << setw(7) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(22) << "=============" << endl;
            break;
        }
        case 5: {
            cout << endl << setw(20) << "* - - - *" << endl;
            cout << setw(12) << "|"  << setw(8) << "|" << endl;
            cout << setw(12) << "O"  << setw(8) << "|" << endl;
            cout << setw(13) << "/|\\"  << setw(7) << "|" << endl;
            cout << setw(11) << "/"  << setw(9) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(22) << "=============" << endl;
            break;
        }
        case 6: {
            cout << endl << setw(20) << "* - - - *" << endl;
            cout << setw(12) << "|"  << setw(8) << "|" << endl;
            cout << setw(12) << "O"  << setw(8) << "|" << endl;
            cout << setw(13) << "/|\\"  << setw(7) << "|" << endl;
            cout << setw(13) << "/ \\"  << setw(7) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(20) << "|" << endl;
            cout << setw(22) << "=============" << endl; 
            break;
        }
    }
}

