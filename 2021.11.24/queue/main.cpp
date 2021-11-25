# include <iostream>
#include"queue.h"
using namespace std;



int main()
{
    CirQueue q(10);
    int ret;
   // q.enQueue(0);  
    q.enQueue(1);  
   q.dnQueue(&ret);
   cout<<(ret)<<endl;
    q.displayQueue();
    return 0;
}
