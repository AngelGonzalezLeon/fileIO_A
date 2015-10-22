//Name : Angel Gonzalez
//Date : 10/22/15
//Description: Following the provided prompt below

/*Write a program that will utilize a text input file (gba.txt) and compute the listed specifications. The text input file "gba.txt" is provided. Build your program in steps to code, debug and test one section at a time. 
a. For example, write code to simply read and print the results to screen as a first step.
b. The getline(  ) function is not needed for this assignment.

c. Determine the average number of characters per word. Print result to "result.txt".
    i. "average characters per word:  xx"
d. Provide a  count of the number words of each length. Please precisely follow the output format listed below: 
    i. 12 words of length 2
    ii. 11 words of length 3
    iii. 10 words of length 4
    iv. xx words of length 11 or longer
v. Print this result to "result.txt".	
e. Calculate the total number of words in the input file. Print result to "result.txt".
    i. Note: A word, for this program, is defined as a string of symbols that is followed by a blank, comma, period, or end of line.  
f. Capitalize all letters in the file. Write the results to "capitalize.txt". 
    i. When writing to file, place a blank space after each word.
g. Change the first letter of each word from original file to uppercase. Write the results to "uppercase.txt" . 
    i. When writing to file, place a blank space after each word.*/

#include <iostream>
#include <fstream> //read and write from files
#include <cstdlib> //generally good to have
#include <string> //might need this?

using namespace std;

int main()
{
    ifstream finn;
    ofstream fout;
    ofstream foutA;
    ofstream foutB;
    
    finn.open("gba.txt");
    fout.open("results.txt");
    foutA.open("capitalize.txt");
    foutB.open("uppercase.txt");
    
    string strA; //temp stores a word
    string CAPSRAGE = ""; //stores the uppercase of a character
    int i = 0;
    int strLen; // gets the length of a word
    int charactersC = 0; //gets the character count
    int wcount = 0;
    int len1 = 0, len2 = 0, len3 = 0, len4 = 0, len5 = 0, 
    len6 = 0, len7 = 0, len8 = 0, len9 = 0, len10 = 0, len11 = 0; //saves length of str 2-11+
    
    if (finn.fail())
    {
        cout << "error opening input file" << endl;
        exit(1);
    }
    if (fout.fail())
    {
        cout << "error opneing output file" << endl;
        exit(1);
    }
    
    while (!finn.eof())
    {
        finn >> strA;
        
        strLen = strA.length();
        
        switch (strLen)
        {
            case 1 : len1++;
                     break;
            case 2 : len2++;
                     break;
            case 3 : len3++;
                     break;
            case 4 : len4++;
                     break;
            case 5 : len5++;
                     break;
            case 6 : len6++;
                     break;
            case 7 : len7++;
                     break;
            case 8 : len8++;
                     break;
            case 9 : len9++;
                     break;
            case 10 : len10++;
                     break;
            default : len11++;
        }//end of switch
        
        if (strA[i] >= 'a' && strA[i] <= 'z')
        {
            {
                strA[i] = strA[i] - 32;
            }
        }
        foutA << strA[i] + strA.substr( (i+1), strA.length() ) << " ";
        
        for (int i = 0; i < strLen; i++)
        {
            if (strA[i] >= 'a' && strA[i] <= 'z')
            {
                CAPSRAGE += strA[i] - 32;
            }
            else
            {
                CAPSRAGE += strA[i];
            }
        }
        foutB << CAPSRAGE << " "; //adds a space after each word
        CAPSRAGE = ""; //resets holder
        
        charactersC += strLen;
        
        wcount++;
    }//end of while loop
    
    fout << "Average characters per word: " << (charactersC * 1.0)/wcount << endl;
    fout << "Total number of words: " << wcount << endl;
    fout << len1 << " words of length 1" << endl;
    fout << len2 << " words of length 2" << endl;
    fout << len3 << " words of length 3" << endl;
    fout << len4 << " words of length 4" << endl;
    fout << len5 << " words of length 5" << endl;
    fout << len6 << " words of length 6" << endl;
    fout << len7 << " words of length 7" << endl;
    fout << len8 << " words of length 8" << endl;
    fout << len9 << " words of length 9" << endl;
    fout << len10 << " words of length 10" << endl;
    fout << len11 << " words of length 11 or longer" << endl;
    
    
    finn.close();
    fout.close();
    foutA.close();
    foutB.close();

}
