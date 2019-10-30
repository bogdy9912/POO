//
// Created by HP on 10/30/2019.
//

#ifndef UNTITLED_P  OLINOM_H
#define UNTITLED_POLINOM_H
#include <iostream>
#include <cmath>
using namespace std;

class polinom
{

    double *coef;
    int n;
public:

    void set_n(int val)    /// Seteaza N
    {
        n=val;
    }


    void set_coef()                 ///Set coef  ADICA CITESTE COEFICIENTII UNUI POL
    {
        int i;
        for (i=1; i<=n; i++)
            cin>>coef[i];
    }
    void set_coef_to_0()
    {
        int i;
        for (i=1;i<=n;i++)
            coef[i]=0;
    }


    int get_n ()             /// GET N
    {
        return n;
    }


    double get_coef(int poz)        /// get coeficient specific
    {
        return *(coef+poz);
    }
    void retusare_polinom()
    {

        while (coef[n]==0)
        {
            n--;
        }
    }

    polinom(int m)                  ///constructor de initializare
    {
        n=m;
        coef = new double[n+1];

        for (int i=1; i<=n; i++)
            coef[i]=0;
    }

    polinom(const polinom&ob)       /// constructor de copiere
    {
        coef=new double[ob.n+1];
        n=ob.n;
        for (int i=1; i<=ob.n; i++)
        {
            coef[i]=ob.coef[i];
        }


    }
    ~polinom()          /// destructor
    {
        delete []coef;
        n=0;
    }



    polinom& operator = (const polinom& ob)     ///supraincarcare operator = pol
    {
        if (n==ob.n)
        {
            for (int i=1; i<=n; i++)
                coef[i]=ob.coef[i];
        }
        else
        {
            delete[] coef;
            coef=new double[ob.n +1];
            for (int i=1; i<=ob.n; i++)
            {
                coef[i]=ob.coef[i];
            }
            n=ob.n;
        }
        return *this;
    }

/// functii friend sau scrise in afara clasei

    polinom& operator=(const double &a);
    double& operator[](int );
    void afisare();
    friend polinom& operator+(polinom&);
    friend const polinom  operator+(polinom&,polinom&);
    friend const polinom operator+(polinom&,double);
    friend const polinom operator+(double,polinom&);
    friend const polinom operator-(polinom&);
    friend const polinom operator-(polinom&,polinom&);
    friend const polinom operator-(polinom&,double);
    friend const polinom operator-(double,polinom&);
    friend const polinom operator*(polinom&,polinom&);
    friend const polinom operator*(polinom&,double);
    friend const polinom operator*(double,polinom&);
    friend const polinom operator/(polinom&, polinom&);
    friend const polinom operator/(polinom&, double);
    friend const polinom operator/(double,polinom&);
    friend const polinom operator%(polinom&, polinom&);
    //  friend polinom& operator%(polinom,double);
    friend const polinom operator^(polinom&,int);
    friend void operator+=(polinom&,polinom&);
    friend void operator+=(polinom&,double);
    friend void operator+=(double&,polinom&);    /// ce inseamna asta?
    friend void operator-=(polinom&,polinom&);
    friend void operator-=(polinom&,double);
    friend void operator-=(double&,polinom&); ///same
    friend void operator*=(polinom&,polinom&);
    friend void operator*=(polinom&,double);
    friend void operator*=(double&,polinom&); /// same
    friend void operator/=(polinom&,polinom&);
    friend void operator/=(polinom&,double);
    friend void operator/=(double&,polinom&);  /// same
    friend int operator==(polinom&,polinom&);
    friend int operator==(polinom&,double);
    friend int operator==(double,polinom&);
    friend int operator!=(polinom&,polinom&);
    friend int operator!=(polinom&,double);
    friend int operator!=(double,polinom&);
    friend int operator !(polinom&);
    double operator() (double);
    friend int grad (polinom&);
    friend const polinom euclid(polinom&,polinom&);
    friend int operator <(polinom& ,polinom &);


};


#endif //UNTITLED_POLINOM_H
