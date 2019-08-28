/*
Author: Jeff Flanegan
Class: CSC 230
Assignment: M4A2 #11.13
Date: 2019-7-12
*/
#include <stdio.h>
/*
This program takes in a 7 digit number as individual ints
and writes every combination of letters associated with the
key pad numbers to a file. 2 = a,b,c. 3 = d,e,f etc...
*/
int main()
{
    const char arr[] = "ABCDEFGHIJKLMNOPRSTUVWXY";//alphabet array
    char foo[] = "foobarr";//character collection
    int a,b,c,d,e,f,g = 0;//numbers
    FILE *pFile;//create pointer to FILE structure
    //prompt user for numbers
    puts("Enter 7 numbers (2 - 9) eg: 5 5 5 9 7 5 2");
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    //open text file using pointer to FILE structure
    //if file can't be opened or created, send error message
    if((pFile = fopen("2187.txt","w")) == NULL){
        puts("error opening file");
    }
    //run through every possible combinatin and
    //write each combination to a file on its own line
    else{
        for(int i = 0; i < 3; i++){
            //subtract 2 from input number since numbers start at 2
            //multiply by 3 since each key has 3 letters to run through
            //add the current loop counter to get the next letter
             foo[0] = arr[(a - 2) * 3 + i];
            for(int j = 0; j < 3; j++){
                foo[1] = arr[(b - 2) * 3 + j];
                for(int k = 0; k < 3; k++){
                    foo[2] = arr[(c - 2) * 3 + k];
                    for(int l = 0; l < 3; l++){
                        foo[3] = arr[(d - 2) * 3 + l];
                        for(int m = 0; m < 3; m++){
                            foo[4] = arr[(e - 2) * 3 + m];
                            for(int n = 0; n < 3; n++){
                                foo[5] = arr[(f - 2) * 3 + n];
                                for(int o = 0; o < 3; o++){
                                    foo[6] = arr[(g - 2) * 3 + o];
                                    fprintf(pFile,"%c%c%c%c%c%c%c\n",foo[0],foo[1],
                                        foo[2],foo[3],foo[4],foo[5],foo[6]);
                                }//end7
                            }//end6
                        }//end5
                    }//end4
                }//end3
            }//end2
        }//end1
    }//end else
    fclose(pFile);
    return 0;
}//end main
