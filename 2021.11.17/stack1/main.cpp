# include <iostream>
using namespace std;
#include"stack.h"

int main()
{
    char ret;
    int i=0;
    Stack a(2);
    try{
        a.push('i');
        a.push('a');
        a.push('s');
    
    }catch(Stack::Full){
        cout<<"栈满～！！！"<<endl;
    }
    
    try{
       ret =a.pop();
       cout<<ret<<endl;
       ret =a.pop();
       cout<<ret<<endl;
       ret =a.pop();
       cout<<ret<<endl;
    
    }catch(Stack::Empty){
        cout<<"无数据！！！"<<endl;
    }
    

    return 0;
}
