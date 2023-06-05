/* 
 * File:   main.cpp
 * Author: Brittany Chan
 * Created on March 17, 2019, 8:36 AM
 * Purpose:  This version allows players to play more than one round,
 *           add all inputted answers and create a 2D array answer key
 *           that marks 'C' for correct and 'W' for incorrect, implement
 *           bubble and selection sort to arrange the wrngAns alphabetically 
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
char lnthChk(string, int, char &); //Checks whether the length of the word fits required length
void gmDsply(char, string , string[], int); //Hangman display
bool chckAns(string, char, string[], int, unsigned int &, vector<char>, unsigned int &, unsigned int &, bool &);
char guess(char &, string &);
void hngMan(unsigned int);
void gmStat(vector<char>, string[], int, unsigned int, unsigned int, bool);


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    
    fstream file; 
    string word, allAns;
    unsigned int numLtrs, strike, linNum, score, correct, colMax, rowMax, numPlyr;
    colMax = 100, rowMax = 1;
    char choice, ans, key[rowMax][colMax];
    bool status;
    vector<char> wrngAns;
    
    
    //Initialize or input i.e. set variable values
    numLtrs=(time(0)%4)+3;
    score = 6;
    correct = 0;
    strike = 0;
    allAns = "";
    
    
    init();
    //Map inputs -> outputs
    choice = getChc(); 
    numPlyr = choice;
    //cout << choice;
        
    
    setPlyr(choice, word, numLtrs); 
    string answer[numLtrs];


    lnthChk(word, numLtrs, choice);
    
    gmDsply(choice, word, answer, numLtrs);
    while (strike != 6 && correct != word.length()) {
        
        //hngMan(strike);
        chckAns(word, guess(ans, allAns), answer, numLtrs, correct, wrngAns, score, strike, status);
        
       
        
        if (status == true) {
            wrngAns.push_back(ans);
        } 
       
        gmStat(wrngAns, answer, numLtrs, score, strike, status);

    }
    

    cout << "\n\nYour guesses were: " << endl;
    cout << "\n\t";
    for (int j = 0; j < allAns.size(); j++) {
        key[0][j] = allAns[j];
        cout << key[0][j] << " ";
    }
    
    cout << endl;
    for (int k = 0; k < word.length(); k++) {
        for (int p = 0; p < allAns.size(); p++) {
            if (key[0][p] == word[k] || (key[0][p]-32) == word[k]) {
                key[1][p] = 'C';
                
            }  
        }
    }
    cout << "\t";
    for (int r = 0; r < allAns.length(); r++) {
        if (key[1][r] != 'C') {
        cout << "W" << " ";
        } else {
            cout << key[1][r] << " ";
        }
    }

  
    
    
    if (correct == word.length()) {
        cout << "\n\n\tCongratulations! You won! \\(＾O＾)/";
        cout << "\n\tYour score: " << score; 
   
        
    } 
    if (strike == 6) {
        cout << "\n\n\tYou Died! ˙◠˙";
        cout << "\n\tYour score: " << score; 
        hngMan(strike);
    }
    cout << setw(3) << "\n\tThe word was '" << word <<"'" << endl;
    cout << "\nWould you like to play again?" << endl;
    cin >> choice;
    if (choice == 'y') {
        main(0,0);
    } else {
        cout << "\nThank you for playing!" << endl;
        return 0;
    }
    
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

char lnthChk(string word, int length, char &choice) {
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

char guess(char &ans, string &allAns) {
    cout << endl << "\nEnter a letter to take a guess: ";
    cin >> ans;
    allAns += ans;
    return ans;
}

bool chckAns(string word, char ans, string answer[], int size, unsigned int &correct, vector<char> wrngAns, unsigned int &score, 
            unsigned int &strike, bool &status) {
    status = true;

    if ((static_cast<int>(ans) >= 65 && static_cast<int>(ans) <= 90) 
            || ((static_cast<int>(ans) >= 97 && static_cast<int>(ans) <= 122))) {
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
    } else {
        cout << "! - Please enter a valid answer - !" << endl;
  
        //chckAns(word, guess(ans), answer, size, correct, wrngAns, score, strike, status);
        
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
        }
     
    return status;
}

void gmStat(vector<char> wrngAns, string answer[], int size, unsigned int score, unsigned int strike, bool status) {
    
    cout << endl << setprecision(2) << fixed << "\n\tScore: " << score;
    cout << "\n\tStrike: " << strike;
    cout << "\n\tWrong Guesses: ";
    for (int k = 0; k < wrngAns.size(); k++) {
        if (status == true) {
            for (int i = 0; i < wrngAns.size(); i++) {
                int min = i;

                    for (int j = i+1; j < wrngAns.size(); j++) {
                        if(wrngAns[min] > wrngAns[j]) {
                            min = j;
                        //cout << wrngAns[i] << " ";
                        }
                    }
                    int temp = wrngAns[i];
                    wrngAns[i] = wrngAns[min];
                    wrngAns[min] = temp;
            }
        } else {
             for (int i = 0; i < wrngAns.size()-1; i++) {
                for (int j = 0; j < wrngAns.size()-i-1; j++) {
                    if (wrngAns[j] > wrngAns[j+1]) {
                        int temp = wrngAns[j];
                        wrngAns[j] = wrngAns[j+1];
                        wrngAns[j+1] = temp;
                    }
                }

            }
        }
        cout << wrngAns[k] << " ";
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

