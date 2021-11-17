#include"stack.h"

int main()
{
    char ret;
    int i=0;
    Stack a(10);
    a.push('i');
    a.push('a');

    ret=a.getTop();
    cout<<ret<<endl;
    a.pop();
    ret=a.getTop();
    cout<<ret<<endl;
    a.setNull();
    ret=a.getTop();
    cout<<ret<<endl;

    return 0;
}
