//Jeff Flanegan
//programming discussion 3
#include <stdio.h>
#include <stdlib.h>

/*
This program simulates the epic race of the Tortoise and the Hare.
Each movement is generated randomly by percentage for each contestant.
Tortoise: 50% move forward 3, 20% move back 6, 30% move forward 1.
Hare: 20% no movement, 20% move forward 9, 10% move back 12,
      30% move forward 1, 20% move back 2.
The race track is printed with the positions of the tortoise and hare
printed T and H respectively. If they land on the same space "OUCH!!"
is printed representing the tortoise biting the hare. Whichever animal
reaches 70 first is the winner. Prepare for suspense!
*/
int main()
{
    //hare value and movement, tortoise value and movement
    int h = 0, mH = 0, t = 0, mT = 0;
    puts("BANG !!!!!\nAND THEY'RE OFF !!!!!");
    //loops until one hits 70 (finish)
    while(mH < 70 && mT < 70){
        srand(time(NULL)); //seed random
        //random action
        h = 1+(rand()%10);
        t = 1+(rand()%10);

        //tortoises actions
        if(t <= 5){mT += 3;}//move forward 3
        else if(t >= 8){mT += 1;}//move forward 1
        else{mT -= 6;}//move backward 6
        if(mT < 0){mT = 0;}//can't go below 0

        //hare actions
        if(h <= 2){mH += 9;}
        else if(h == 3){mH -= 12;}
        else if(h > 3 && h < 7){mH += 1;}
        else if(h > 6 && h < 9){mH -= 2;}
        //nothing for 9/10
        if(mH < 0){mH = 0;}

        //racetrack is 70 spaces
        for(int i = 0; i < 70; i++){
            if(mH == mT && mT == i){//land on same space
                printf("OUCH!!");
                //subtract text from track minus 1
                i += 5;
            }
            else if(i == mH){printf("H");}
            else if(i == mT){printf("T");}
            else{printf("_");}
        }
        //separates the tracks,if you reduce the window
        //vertically it makes the experience better.
        puts("\n\n\n\n\n\n\n");
        sleep(1);//hesitate next loop
    }//end loop
    //output results
    if (mT >= 70 && mH < 70){puts("TORTOISE WINS! YAY!");}
    else if(mT > 70 && mH > 70){puts("TIE!");}
    else{puts("Hare wins...Lame");}

    return 0;
}
