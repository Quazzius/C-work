/*
Author: Jeff Flanegan
Class: CSC 230
Assignment: M5A2 #14.4
Date: 2019-7-23
*/

#include <stdio.h>
#include <unistd.h>

/*This program is executed from the command line and sorts single digit integers
in ascending or descending order and outputs the result. The arguments -a or -d
are added after the file name and are succeeded by the integers separated by spaces. */
int main(int argc, char *argv[])
{
    int tmp;//placeholder
    char c;//switch
    puts("");
    //valid argument options from command
    while((c = getopt(argc, argv, "a:d:")) != -1)
    {
        switch(c)
        {
            case 'a':
                //sort ascending
                for (int i = 2; i < argc; i++){
                    for (int j = i+1; j < argc; j++){
                        //swap ints
                        if (*argv[j] < *argv[i]){
                            tmp = *argv[i];
                            *argv[i] = *argv[j];
                            *argv[j] = tmp;
                        }
                    }
                }
                //print
                for (int p = 2; p < argc; p++){
                    // -48 for size of *argv[] (**argv)
                    printf("%d ", (*argv[p] - 48));
                }
              break;

            case 'd':
                //sort descending
                for (int i = 2; i < argc; i++){
                    for (int j = i+1; j < argc; j++){
                        if (*argv[i] < *argv[j]){
                            tmp = *argv[i];
                            *argv[i] = *argv[j];
                            *argv[j] = tmp;
                        }
                    }
                }
                //print
                for (int p = 2; p < argc; p++){
                    printf("%d ", (*argv[p] - 48));
                }
              break;

            default:
                puts("Invalid Argument. Valid arguments -a -d. There is no man page for this topic.");
        }//end switch
        puts("\n");
    }//end while

    return 0;
}//end main
