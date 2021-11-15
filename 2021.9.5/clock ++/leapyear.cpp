/*
设计一个时钟类，能够记录时、分、秒，重载它的++运算符，每执行一次++运算，加时1秒，但要使计时过程能够自动进位。
*/
#include<iostream>
using namespace std;
class Time{
    public:
        Time(int h=0,int m=0,int s=0){
            hour = h;
            minute = m;
            sec= s;
        }
        void operator++();
        void showTime(){
            cout<<"当前时间为："<<hour<<":"<<minute<<":"<<sec<<endl;
        }

    private:
        int hour,minute,sec;

};

void Time::operator++(){
    ++sec;
    if(sec==60){
        sec=0;
        ++minute;
        if(minute==60){
            minute=0;
            hour++;
            if(hour==24){
                hour=0;
            }
        }
    }
}
void delay(long i)
{
    while(i--);
}

int main(int argc, char const *argv[])
{
    Time t(23,59,00);
    while(1)
    {
    delay(100000000);
    t.operator++();
    delay(100000000);
    t.showTime();
    
    }
    return 0;
}
