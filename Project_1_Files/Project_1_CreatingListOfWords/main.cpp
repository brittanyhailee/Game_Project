/* 
 * File:   main.cpp
 * Author: Brittany Chan
 * Created on May 4, 2023, 8:36 AM
 * Purpose:  Creating a word file for project 1 
 *           
 */

//System Libraries
#include <iostream>  //Input/Output 
#include <fstream>
#include <string>

using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed

//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    fstream wrdFile;
    //string word1, word2, word3, word4, word5, word6, word7, word8,
           //word1, word2, word3, word4;
    
    //Initialize or input i.e. set variable values
    wrdFile.open("ListOfWords.txt", ios::out);
    
    //Map inputs -> outputs
    wrdFile << "AUTOMATIC\n";
    wrdFile << "BURGUNDY\n";
    wrdFile << "BIRTHDAY\n";
    wrdFile << "GNARLY\n";
    wrdFile << "SABOTAGE\n";
    wrdFile << "PROGRAMMING\n";
    wrdFile << "ARACHNOPHOBIA\n";
    wrdFile << "BURGER\n";
    wrdFile << "ORCHESTRA\n";
    wrdFile << "SARCASM\n";
    wrdFile << "SOLILOQUY\n";
    wrdFile << "UNFORGIVEN\n";
    wrdFile << "FEARLESS\n";
    wrdFile << "DANGEROUSLY\n";
    wrdFile << "SAVAGE\n";
    wrdFile << "BOMBASTIC\n";
    wrdFile << "SIDEYE\n";
    wrdFile << "BAMBOOZLE\n"; 

    
    //cout << wrdFile << endl; 
    wrdFile.close();
   
    //Display the outputs

    //Exit stage right or left!
    return 0;
}

