/*course: CS215 - 014x
 *Project: Project 1
 *Purpose: A Program that converts decimal to roman numeral.
 * Finds the roman numeral for the super bowl year based on user input.
 *Author: Anthony Arnold
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string roman_numeral(int num); // forward declaration of roman_numeral function

int main()
{
    const int START = 1967;
    int usernum;
    int x = 1;
    while (x != 0) // creates while loop that only will be exited when user inputs Q or q
    {   
        start: // where goto statement will return to 
        string q = "q";
        string Q = "Q";
        cout << "***********************************************************" << endl;
        cout << "*     The Super Bowl is the annual final playoff game     *" << endl;
        cout << "*         of the NFL to determine the league champion.    *" << endl;
        cout << "* The first Super Bowl took place on January 15, 1967.    *" << endl;
        cout << "* Super Bowl I (Los Angeles Memorial Coliseum) --> 1967   *" << endl;
        cout << "* This Roman Numerals Convertor is written by Yi Pike.    *" << endl;
        cout << "* If you had a time machine, which year of Super Bowl     *" << endl;
        cout << "* would you want to attend (1967 - 5965) ?                *" << endl;
        cout << "***********************************************************" << endl;
        cout << "Please enter the year you want to attend (click Q or q to quit):" << endl; // prints this block of text and asks for userinput
        cin >> usernum;

        if (cin.fail()) // if string is detected in usernum
        {
            cin.clear(); // clears the error state of cin
            string rownum;
            cin >> rownum;

            if (rownum == q || rownum == Q) // if rownum = q or Q program ends
            {
                cout << "Back to 2023, have a great day!";
                break;

            }
            else
            {
                cout << "Please use a four-digit number to represent a year (1967-5965)!" << endl;
                cout << endl;
                cin.ignore(256, '\n'); // discards characters from cin with a max characters to ignore being 256
                goto start; // takes to start:
            }
        }
        if (usernum < 1967) // determines whether usernum is greater than 5965 or less that 1967
        {
            cout << "The time machine will bring you to the year " << usernum << ":" << endl;
            cout << "Wait!!! The year you entered is EARLIER than the first Super Bowl!" << endl;
            cout << endl;
            cin.ignore(256, '\n'); // discards characters from cin with a max characters to ignore being 256
            goto start; // takes to start:
        }
        if (usernum > 5965)
        {
            cout << "The time machine will bring you to the year " << usernum << ":" << endl;
            cout << "Wait!!! The year you entered is TOO BIG to be a roman numeral!" << endl;
            cout << endl;
            cin.ignore(256, '\n'); // discards characters from cin with a max characters to ignore being 256
            goto start; // takes to start:
        }
        else
        {
            int year = usernum;
            int convert_num = usernum - START + 1; // creates the number to be used in roman_numeral function
            cout << "The time machine will bring you to the year of " << year << ":" << endl;
            cout << "It is Super Bowl " << roman_numeral(convert_num) << endl; // calls roman_numeral function with convert_num as its parameter
            cout << "We will help you find out the result and other interesting information...next time :)" << endl;
        }
        cin.ignore(256, '\n');
    }
	return 0;
}

// This function is heavily based on the logic used in vectorpair function commented out below
string roman_numeral(int num)
{
    string total;
    /*This function works by going through a set of cases and if the case is satisfied it continues further 
    through the function until it returns the value stored in total. Total is the value from each case that is passed
    all added together in a string. After each value is added to total, a certain amount is removed from num.
    This happens until num = 0;*/
    while (num > 0) // fuction only works while num > 0.
    {
        switch (num / 1000)
        {
        case 1:
            total += "M";
            num -= 1000;
            break;
        case 2:
            total += "MM";
            num -= 2000;
            break;
        case 3:
            total += "MMM";
            num -= 3000;
            break;
        default:
            break;
        }
        switch (num / 900) 
        {
        case 1:
            total += "CM";
            num -= 900;
            break;
        default:
            break;
        }
        switch (num / 500)
        {
        case 1: 
            total += "D";
            num -= 500;
            break;
        default:
            break;
        }
        switch (num / 400)
        {
        case 1:
            total += "CD";
            num -= 400;
            break;
        default:
            break;
        }
        switch (num / 100)
        {
        case 1:
            total += "C";
            num -= 100;
            break;
        default:
            break;
        }
        switch (num / 90)
        {
        case 1:
            total += "XC";
            num -= 90;
            break;
        default:
            break;
        }
        switch (num / 50)
        {
        case 1:
            total += "L";
            num -= 50;
            break;
        default:
            break;
        }
        switch (num / 40)
        {
        case 1:
            total += "XL";
            num -= 40;
            break;
        default:
            break;
        }
        switch (num / 10)
        {
        case 1:
            total += "X";
            num -= 10;
            break;
        case 2:
            total += "XX";
            num -= 20;
            break;
        case 3:
            total += "XXX";
            num -= 30;
            break;
        default:
            break;
        }
        switch (num / 9)
        {
        case 1:
            total += "IX";
            num -= 9;
            break;
        default:
            break;
        }
        switch (num / 5)
        {
        case 1:
            total += "V";
            num -= 5;
            break;
        default:
            break;
        }
        switch (num / 4)
        {
        case 1:
            total += "IV";
            num -= 4;
            break;
        default:
            break;
        }
        switch (num / 1)
        {
        case 1:
            total += "I";
            num -= 1;
            break;
        case 2:
            total += "II";
            num -= 2;
            break;
        case 3:
            total += "III";
            num -= 3;
            break;
        default:
            break;
        }
    }
    return total; // returns all of the strings added to total.
}

// This is another solution that is quite a bit smaller for converting decimal to roman
// need to be using c++17 for program to work properly

/*string roman_numeral(int num) {
    vector < pair < int, string >> roman_val{
        { 1000, "M" },
        { 900,  "CM" },
        { 500,  "D" },
        { 400,  "CD" },
        { 100,  "C" },
        { 90,   "XC" },
        { 50,   "L" },
        { 40,   "XL" },
        { 10,   "X" },
        { 9,    "IX" },
        { 5,    "V" },
        { 4,    "IV" },
        { 1,    "I" }
    };

    string total;

    for (auto [x, y] : roman_val) {     // asigns int and string to appropriate member of the roman_val vector
        while (num >= x) {
            total += y;
            num -= x;
        }
    }
    return total;
} */