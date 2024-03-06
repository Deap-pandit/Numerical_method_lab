#include<bits/stdc++.h>
using namespace std;

class Secont{

    private :

    const double tollerence = 0.0001;

    double function(double x)
    {
        return (x*x * (exp(-(x/2)))-1);

    }
    double secent(double a,double b)
    {
        return ((a*function(b) - b*function(a))  /  (function(b) - function(a)) );

    }

    public :
    void solve()
    {
        double a,b;
        srand(time(0));
        while(true)
        {

            a =rand()%10 -9;
            b = rand()%10 ;
            if(function(a) *function(b) < 0.0)
            {
                break;
            }

        }

        double new_root = secent(a,b);
        double root;
        while(true)
        {
            cout<<"a =  "<< a <<"  "<<"b = "<<b<<" "<< "new_root = "<< new_root<<endl;

            if(function(new_root) == 0.0)
            {
                root = new_root;
                break;

            }
            if(new_root - secent(new_root,a)< tollerence)

            {
                    root  = new_root;
                    break;

            }
            b= a;
            a = new_root;
            new_root = secent(a,b);




        }

        root = secent(root,a);
        cout<<"the root is "<<root<<endl;


    }

};

int main()
{
    Secont sc = Secont();
    sc.solve();

}