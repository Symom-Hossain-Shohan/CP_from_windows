#include<bits/stdc++.h>

using namespace std;

class integer{
    int a,b;
    public:
    integer()
    {
        a=0,b=0;
    }
    void show();
};

void integer:: show()
{
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    integer ax;
    ax.show() ;
}