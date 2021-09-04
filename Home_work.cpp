#include <bits/stdc++.h>

using namespace std;


class cgpa{
    double cg=3.0;
    double total_cg=cg;
    int cnt=1;
    double avg;
    public:

    void add_cg(double x)
    {
        total_cg+=x;
        cnt+=1;
    }
    void clac_avg()
    {
        avg=total_cg/cnt;
    }

    void show_avg()
    {
        cout << avg << endl;
    }
};

int main()
{
    cgpa neww;
    neww.add_cg(3.8);
    neww.add_cg(3.9);
    neww.clac_avg();

    neww.show_avg();

}