/* Simple Digital clock implementation in C */
#include <stdio.h>   //for printf
#include <time.h>    //for time functions
#include <unistd.h>  // for system and sleep functions

int main()
{
    time_t t;
    struct tm* local_time;
 	  // time in seconds since Jan1, 1970
    time(&t);
 
    //fill tm strucutre for timezone 
    //and get hour, minute and seconds
    local_time = localtime(&t);
	  int hour = local_time->tm_hour;
    int minute = local_time->tm_min;
    int second = local_time->tm_sec;

    while(1) {
       // Clear output screen
       system("cls"); 
       
       // Print time in HH : MM : SS format
       printf("%02d : %02d : %02d ",hour,minute,second);
       
       // Increment second
       second++;

       // Update hour, minute and second
       if(second == 60) {
           minute += 1;
           second = 0;
       }
       if(minute == 60) {
           hour += 1;
           minute = 0;
       }
       if(hour == 24) {
           hour = minute = second =0;
       }
       // 1 second delay
       sleep(1);  
    }
    return 0;
}
