# include <iostream>
#include"Linkqueue.hpp"
using namespace std;



int main()
{
 LinkQueue<double> a;

    a.enQueue(5);
    a.enQueue(6);
    a.enQueue(7);
    a.enQueue(8);
    a.displayQueue();
    cout << "长度" << a.queueLength() <<endl;

    double num =0;
    a.deQueue(num);
    cout << "出队" << num <<endl;

    cout << "长度" << a.queueLength() <<endl;

    cout << "列表为空吗" << a.isEmpty()<<endl;

    a.displayQueue();

    a.clearQueue();
     cout << "清除队列" << endl;
    if(a.displayQueue())
    {
    }
    else
    {
        cout << "列表为空" << endl;
    }

    cout << "列表为空吗" << a.isEmpty()<< endl;
    cout << "长度" << a.queueLength() <<endl;



    cout << "Hello world!" << endl;
    return 0;
}
