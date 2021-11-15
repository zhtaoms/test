#include<iostream>
#include <string>
using namespace std;

#define managerid 1
#define salerid 2
#define tempid 3

//定义员工类
class Emp{
public:
    Emp(int id,string name)
    {
        m_id=id;
        m_name=name;
    }
    int getid(){return m_id;}
    string getname(){return m_name;}

    virtual float getSalary()=0;
    virtual void print()=0;


private:
    int m_id;
    string m_name;
};

class Manager:public Emp{
public:
    Manager(int id,string name,int week):Emp(id,name){
        weeksalary=week*1000;
    }
    virtual float getSalary()
    {
        return weeksalary;
    }
    virtual void print()
    {
        cout <<"ID"<<getid()<<"\t 姓名"<<getname()<<"\t 工资"<<weeksalary << endl;
    }
private:
    int weeksalary;
};


int main ()
{
    Manager a(1,"555",12);
    a.print();

    return 0;
}
