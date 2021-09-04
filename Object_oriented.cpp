#include<iostream>
using namespace std;

class Employee{
public:
    string name;
    string company;
    int age;

    void introduce_yourself()
    {
        cout << name << endl;
        cout << company << endl;
        cout << age << endl;
    }

    //constructor
    Employee(string n,string c,int a)
    {
        name=n;
        company=c;
        age=a;
    }


};

int main()
{
    string a,b;
    int c;
    cin >> a >> b >> c;
    Employee employee1=Employee(a,b,c);
    /*employee1.name="Shohan";
    employee1.company="ToTo";
    employee1.age=21;*/
    //cin >> employee1.name >> employee1.company >> employee1.age;

    employee1.introduce_yourself();
    
}