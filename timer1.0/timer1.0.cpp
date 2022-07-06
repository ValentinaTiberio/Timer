/**
* Copyright (c) 2017 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* Timer (first example)
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined


#include <string>
#include <iostream>

using namespace std;

//Variables Globales (hablaremos en clase...)
int hours = 0;
int minutes = 0;
int seconds = 0;


void showTime()
{
    seconds++;
    if (seconds > 59)
    {
        seconds = 0;
        minutes++;

        if (minutes > 59)
        {
              minutes = 0;
              hours++;

              if (hours > 23)
              {
                    hours = 0;
              }
        }
    }

    string hoursText = to_string(hours);
    string minutesText = to_string(minutes);
    string secondsText = to_string(seconds);

    if(hoursText.size() == 1){hoursText = "0"+hoursText;}
    if(minutesText.size() == 1){minutesText = "0"+minutesText;}
    if(secondsText.size() == 1){secondsText = "0"+secondsText;}

    cout << hoursText << ":" << minutesText << ":" << secondsText << endl;
}

int main()
{
    //En la terminal de visual studio pueden cortar la ejecución
    //de este "while" con CTRL+C
    while(1)
    {
        showTime();

        #ifdef __unix__
            sleep(1);
            system("clear");
        #elif defined(_WIN32) || defined(WIN32)
            Sleep( 1000 );
            system("cls");
        #endif // defined
    }
    return 0;
}