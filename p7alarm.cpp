#include <iostream>
#include <windows.h>
#include <ctime>
#include <time.h>
#include <mmsystem.h>
#include <conio.h>

using namespace std;

int main()
{
    int minute,hour;
    int minutesleft;
    int hoursleft;
    int currentminutes;
    int alarmminutes;
    int minutesremaining;
    long long i =0;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << "Year: "<< 1900 + ltm->tm_year << endl;
    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
    cout << "Day: "<<  ltm->tm_mday << endl;
    cout << "Time: "<< ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;

    cout<< "#-------------#" << endl;

    cout << "What hour will alarm sound? (24hour)" << endl;
    cin >> hour;
    cout << "What minute will alarm sound?" << endl;
    cin >> minute;

    Beep(2750,0.4*1000);
    cout<< "#-------------#" << endl;
    cout << "Alarm has been activated and will sound at:  " << hour <<":"<< minute<< endl;



    while(true)
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        currentminutes = (1 + ltm->tm_min)+ (ltm->tm_hour)*60;
        alarmminutes = hour*60+minute;

        if(alarmminutes > currentminutes)
        {
            minutesremaining = currentminutes-alarmminutes;
        }
        else
        {
            minutesremaining = 1440-currentminutes+alarmminutes;

        }

        hoursleft=minutesremaining/60;
        minutesleft=abs(minutesremaining%60);

        if(i == 10000000)
        {
            cout<< "#-------------#" << endl;
            cout << endl;
            cout<<"Till alarm." << endl;
            cout<<"Time left (Hours: "<< hoursleft << " minutes: " << minutesleft << ")" <<endl;

            cout << endl;
            i=0;
        }
        i++;

        if((1 + ltm->tm_min)==minute && (ltm->tm_hour) ==hour)
        {
            cout << "SOUND ALARM!!";
            while(true)
            {
                Beep(2750,0.4*1000);
                Beep(3750,0.4*1000);
                Beep(4750,0.4*1000);
                //PlaySound((LPCSTR) "C:\\Users\\Paco\\Desktop\\sound\\test.wav", NULL, SND_FILENAME | SND_ASYNC);

                if(kbhit())
                {
                    break;
                }
            }
            break;
        }
    }

}
