// C program for implementation of falling matrix effect
#include<stdio.h>
#include <unistd.h>  // for usleep()
#include <stdlib.h>  // for system() to change color

#define LINE_WIDTH 197
#define SLEEP_TIME 100000

int main() {
    //Initialize Random Number generator
    srand(5);
   
	//character set
   char ch[] = "01!| ";
   int len = sizeof(ch)-1;

    // Green Color
    system("Color 0A");
  
    // Indefinite Loop
    while (1) {
    	  //loop for line and print randomly from character set
        for (int i=0;i<LINE_WIDTH;i++)
                printf("%c",ch[rand()%len]);
        usleep(SLEEP_TIME);
    }
    return 0;
}
