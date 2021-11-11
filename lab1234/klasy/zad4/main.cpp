#include <iostream>

using namespace std;

class Student
{
    string imie, nazwisko;
    int numerAlbumu, liczbaPytan, poprawneOdpowiedzi;
public:
    Student(string name, string surname, int ID, int questionNum, int rightAnswers)
    {imie=name; nazwisko=surname; numerAlbumu=ID; liczbaPytan=questionNum;poprawneOdpowiedzi=rightAnswers;}
    string getImie()
    {
        return imie;
    }
    string getNazwisko()
    {
        return nazwisko;
    }
    double getID()
    {
        return numerAlbumu;
    }
    double getQuestionNum()
    {
        return liczbaPytan;
    }
    double getrightAns()
    {
        return poprawneOdpowiedzi;
    }
    void setall(string name, string surname, double a,double b,double c) {
        this->imie = name;
        this->nazwisko = surname;
        this->numerAlbumu = a;
        this->liczbaPytan = b;
        this->poprawneOdpowiedzi = c;
    }
    void percent()
    {
        cout<<(100.0*poprawneOdpowiedzi)/liczbaPytan<<"%"<<endl;
    }
};

int main()
{
    string x,y;
    double a,b,c;
    cout<<"Podaj imie, nazwisko, numer albumu, liczbe pytan, liczbe poprawnych odpowiedzi:"<<endl;
    cin>>x>>y>>a>>b>>c;
    Student siema = Student(x,y,a,b,c);
    siema.percent();
    return 0;
}