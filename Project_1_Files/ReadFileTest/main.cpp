/* 
 * File:   main.cpp
 * Author: Brittany Chan
 * Created on March 17, 2019, 8:36 AM
 * Purpose:  To sort inputted names in alphabetical order 
 *           
 */

//System Libraries
#include <iostream>  //Input/Output 
#include <string>
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
    fstream in;
    string word;
    
    //Initialize or input i.e. set variable values
    in.open("TestFile.Txt", ios::in);
    
    //Map inputs -> outputs
    while(getline(in, word)) {
        cout << word << endl;
    }

    //Display the outputs

    //Exit stage right or left!
    return 0;
}

