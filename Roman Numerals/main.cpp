//
//  main.cpp
//  Roman Numerals
//
//  Created by Christopher Katnic on 11/20/14.
//  Copyright (c) 2014 Christopher Katnic. All rights reserved.
//

#include <iostream>
#include <string>

void decimaltoroman();
void romantodecimal();

int main() {
   
while(1)
{
    char c;
    std::cout <<"\nd for decimal - > roman, r for roman - > decimal: ";
    std::cin >>c;
    
    switch (c)
    {
            case 'd':
            case 'D':
        {
            decimaltoroman();
            break;
        }
            case 'r':
            case 'R':
        {
            romantodecimal();
            break;
        }
            default:
        {
            std::cout << "\n\nYou suck, game over";
            return 0;
        }
    }
    
}
    return 0;
}

void decimaltoroman()
{
    /*
     
     I	V	X	L	C	D	M
     1	5	10	50	100	500	1000

     */
    int input;
    std::cout << "Enter your input: ";
    std::cin >> input;
    std::cout << "\nINPUTRESULTS:   ";
    while(input != 0)
    {
        if(input - 1000 >= 0)       { input -= 1000; std::cout << "M";  }
        else if(input - 900 >= 0)   { input -= 900; std::cout << "CM";  }       //C - M
        else if(input - 500 >= 0)   { input -= 500; std::cout << "D";   }
        else if(input - 400 >= 0)   { input -= 400; std::cout << "CD";  }       //C - D
        else if(input - 100 >= 0)   { input -= 100; std::cout << "C";   }
        else if(input - 90 >= 0)    { input -= 90;  std::cout << "XC";  }       //X - C
        else if(input - 50 >= 0)    { input -= 50; std::cout << "L";    }
        else if(input - 90 >= 0)    { input -= 40;  std::cout << "XL";  }       //X - L
        else if(input - 10 >= 0)    { input -= 10; std::cout << "X";    }
        else if(input - 9 >= 0)     { input -= 9; std::cout << "IX";    }       //I - X
        else if(input - 5 >= 0)     { input -= 5; std::cout << "V";     }
        else if(input - 4 >= 0)     { input -= 4; std::cout << "IV";    }       //I - V
        else                        { std::cout << "I"; input--;}
    }
}

void romantodecimal()
{
    /*
     
     I	V	X	L	C	D	M
     1	5	10	50	100	500	1000
     
     */
    std::string input; int total;
    std::cout << "Enter your input: ";
    std::cin >> input;
    std::cout << "\nINPUTRESULTS:   ";
    
    for(int i = 0; i < input.length(); i++)
    {
        switch(input[i])
        {
                case 'M':
            {
                total+=1000;
                break;
            }
            case 'D':
            {
                total+=500;
                break;
            }
            case 'C':
            {
                if(input[i+1] == 'M') {total+=900; i++; break;}
                else if(input[i+1] == 'D') {total+=400; i++; break;}
                else {total+=100;   break;}
            }
            case 'L':
            {
                total+=50;
                break;
            }
            case 'X':
            {
                if(input[i+1] == 'C') {total+=90; i++; break;}
                else if(input[i+1] == 'L') {total+=40; i++; break;}
                else {total+=10;   break;}
            }
            case 'V':
            {
                total+=5;
                break;
            }
            case 'I':
            {
                if(input[i+1] == 'X') {total+=9; i++; break;}
                else if(input[i+1] == 'V') {total+=4; i++; break;}
                else {total+=100;   break;}
            }
            default:
                break;
        }
    }
    std::cout << total;


}
















