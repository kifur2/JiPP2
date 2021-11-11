#include <iostream>
#include <cmath>

using namespace std;

class Punkt
{
public:
    double x,y;
    Punkt(double X, double Y){x=X; y=Y;}
    double odleglosc(Punkt a, Punkt b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
};

int main()
{
    double a,b;
    cout<<"Podaj a, b:"<<endl;
    cin>>a>>b;
    Punkt siema = Punkt(a,b);
    cout<<"Pole powierzchni wynosi: "<<siema.odleglosc(siema, Punkt(0,0))<<endl;
    return 0;
}
