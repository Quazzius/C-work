/*
Author: Jeff Flanegan
Class: CSC 230
Assignment: M4A1 #10.12
Date: 2019-7-10
*/

#include <stdio.h>
#include <unistd.h>
/*
This program takes in 4 characters, packs them into an unsigned int
and prints the results in bits. The character bits are first printed individually
before being packed together one-by-one. After each character is packed
into the integer the updated bit assignment is printed.
*/

//prototypes
void printChars(char);
void packCharacters(char, unsigned int *);

int main()
{
    //prompt user for character input
    char w,x,y,z;
    puts("Enter 4 characters");
    scanf("%c%c%c%c",&w,&x,&y,&z);
    puts("");
    //print character bytes
    printChars(w);
    printChars(x);
    printChars(y);
    printChars(z);
    puts("");

    unsigned int bits = 0; //int for packing
    packCharacters(w, &bits);
    packCharacters(x, &bits);
    packCharacters(y, &bits);
    packCharacters(z, &bits);
    return 0;
}//end main

//prints character bytes
void printChars(char x){

    unsigned int mask = 1 << 7; //mask for bits
        //output character, then bits
        printf("%c = ", x);
        for (int j = 0; j < 8; j++){
            putchar(x & mask ? '1' : '0');
            x <<= 1; // shift value left 1
        }
    puts("");
}//end printchars

//pack the chars!
void packCharacters(char var, unsigned int *pBits){

    unsigned int uMask = 1 << 31; //mask 32 bits
    //shift bits left 8 spaces
    *pBits <<= 8;
    //append called character to first 8 bits
    *pBits |= var;
    //use placeholder for printing without changing original value
    int holder = *pBits;
    //print bits
    for (int j = 1; j <= 32; j++){
        putchar(holder & uMask ? '1' : '0');
        holder <<= 1;
        if (j % 8 == 0){putchar(' ');}//8 bit spacing
    }
    sleep(1);
    puts("");
}//end packCharacters
