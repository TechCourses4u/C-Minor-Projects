// C program for implementation of Fast Typing effect.
#include<stdio.h>
#include <unistd.h>  //for usleep
#include <stdlib.h>  //for system() to change color

#define SLEEP_TIME 1000

int main() {
    //Initialize Random Number generator
    srand(5);
   
	//character set
   char ch[] = "01!| ";
   int len = sizeof(ch)-1;

    // Green Color
    system("Color 0A");
  
    // Indefinite Loop, print randomly from character set and add delay of 1 ms between characters
    while (1) {
        printf("%c",ch[rand()%len]);
        usleep(SLEEP_TIME);
    }
    return 0;
}
