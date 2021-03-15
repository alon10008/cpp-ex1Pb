#include <iostream>
#include <string>
#include "snowman.hpp"
#include <array>
#include <stdexcept>

using namespace std;
using namespace ariel;

string hat(int num);
string nose(int num);
string eye(int num);
string torso(int num);
string rharm(int num);
string lharm(int num);
string base(int num);

const int dec_base = 10;         // snowman format - HNLRXYTB
const int lowest = 11111111;    // lowest case
const int heighest = 44444444; // heighest case
const int h = 0;    // hat
const int n = 1;    // nose
const int l = 2;    // left eye
const int r = 3;    // right eye
const int x = 4;    // left harm
const int y = 5;    // right harm
const int t = 6;    // torso
const int b = 7;    // base


string ariel::snowman(int num) {

    const int arr_len = 8;
    if(num < lowest || num > heighest)
    {
        throw out_of_range("WRONG INPUT!\n");
    }
    array<string,arr_len> snow;
    string snowman;
    int digit = 0;
    for(int i=arr_len-1 ; i>=0 ; i--)
    {
        digit = num%dec_base;
        num /= dec_base;
        switch(i)
        {
            case h: snow[h] = hat(digit);break;
            case n: snow[n] = nose(digit);break;
            case l: snow[l] = eye(digit);break;
            case r: snow[r] = eye(digit);break;
            case x: snow[x] = lharm(digit);break;
            case y: snow[y] = rharm(digit);break;
            case t: snow[t] = torso(digit);break;
            case b: snow[b] = base(digit);break;
        }
    }
    if(snow[x] == "\\" && snow[y] == "/")
    {
        snowman = "\n" + snow[h]; 
        snowman += "\n" + snow[x] + "(" + snow[l] + snow[n] + snow[r] + ")" + snow[y];
        snowman += "\n (" + snow[t] + ")\n";
        snowman += " (" + snow[b] + ")";
    }
    else if(snow[x] == "\\")
    {
        snowman += "\n" + snow[h];
        snowman += "\n" + snow[x] + "(" + snow[l] + snow[n] + snow[r] + ")";
        snowman += "\n (" + snow[t] + ")" + snow[y] + "\n";
        snowman += " (" + snow[b] + ")";
    }
    else if(snow[y] == "/")
    {
        snowman += "\n" + snow[h];
        snowman += "\n (" + snow[l] + snow[n] + snow[r] + ")" + snow[y];
        snowman += "\n" + snow[x] + "(" + snow[t] + ")\n";
        snowman += " (" + snow[b] + ")";
    }
    else
    {
        snowman += "\n" + snow[h];
        snowman += "\n (" + snow[l] + snow[n] + snow[r] + ")";
        snowman += "\n" + snow[x] + "(" + snow[t] + ")" + snow[y] + "\n";
        snowman += " (" + snow[b] + ")";
    }
    return snowman;

}

string hat(int num) {

    switch(num)
    {
        case 1: return " _===_";break;
        case 2: return "  ___\n .....";break;
        case 3: return "   _\n  /_\\";break;
        case 4: return "  ___\n (_*_)";break;
        default: throw out_of_range("WRONG INPUT!\n");
    }

}

string nose(int num) {
    
    switch(num)
    {
        case 1: return ",";break;
        case 2: return ".";break;
        case 3: return "_";break;
        case 4: return " ";break;
        default: throw out_of_range("WRONG INPUT!\n");
    }

}

string eye(int num) {

    switch(num)
    {
        case 1: return ".";break;
        case 2: return "o";break;
        case 3: return "O";break;
        case 4: return "-";break;
        default: throw out_of_range("WRONG INPUT!\n");
    }

}

string lharm(int num) {

    switch(num)
    {
        case 1: return "<";break;
        case 2: return "\\";break;
        case 3: return "/";break;
        case 4: return " ";break;
        default: throw out_of_range("WRONG INPUT!\n");
    }

}

string rharm(int num) {

    switch(num)
    {
        case 1: return ">";break;
        case 2: return "/";break;
        case 3: return "\\";break;
        case 4: return "";break;
        default: throw out_of_range("WRONG INPUT!\n");
    }

}

string torso(int num) {

    switch(num)
    {
        case 1: return " : ";break;
        case 2: return "] [";break;
        case 3: return "> <";break;
        case 4: return "   ";break;
        default: throw out_of_range("WRONG INPUT!\n");
    }

}

string base(int num) {

    switch(num)
    {
        case 1: return " : ";break;
        case 2: return "\" \"";break;
        case 3: return "___";break;
        case 4: return "   ";break;
        default: throw out_of_range("WRONG INPUT!\n");
    }

}
