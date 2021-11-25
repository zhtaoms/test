# include <iostream>
using namespace std;

void hanoi(int n,char a,char b,char c);
void move (char x, char z);

int main()
{
    
    int n;
    cout<<"Please input n:"<<endl;
    cin>>n;
    hanoi(n,'a','b','c');
    return 0;
}
void hanoi(int n,char a,char b,char c)
{
    if(n==1)
        move(a,c);
    else{
        hanoi(n-1,a,c,b);
        move(a,c);
        hanoi(n-1,b,a,c);
    }
}

void move (char x, char z)
{
    cout<<x<<"->"<<z<<endl;
}