#include<bits/stdc++.h>

using namespace std;

class comp{
    int real,img;
    public:

    comp();
    comp(int a,int b);
    friend comp operator +(comp x,comp y);

    void show();
};

comp:: comp()
{
    real=0;
    img=0;
}

comp:: comp(int a,int b)
{
    real=a;
    img=b;
}

comp operator+(comp x,comp y)
{
    comp temp;
    temp.real=y.real+x.real;
    temp.img=y.img+x.img;

    return temp;
}

void comp:: show()
{
    cout << real << " " << img << "i" << endl;
}

int main()
{
    comp a(2,3),b(3,4);

    comp c;
    c=operator+(a,b);
    c.show();

}