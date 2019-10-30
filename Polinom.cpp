//
// Created by HP on 10/30/2019.
//

#include "Polinom.h"
;
polinom& polinom::operator=(const double &a)        ///supraincarcare operator = a
{

    delete []coef;
    n=1;
    coef = new double[2];
    coef[1]=a;
    return *this;
}

double& polinom::operator[](int i)                  /// supraincarcare operator []
{

    if (i>n)
        exit(0);
    return coef[i];
}

polinom& operator +(polinom& ob1)     /// supraincarcare operator  + pol
{
    return ob1;
}
const polinom operator-(polinom& ob1)      /// supraincarcare operator - pol
{
    for (int i=1; i<=ob1.get_n(); i++)
    {
        ob1[i]=0-ob1[i];
    }
    return ob1;

}

const polinom  operator+( polinom& ob1, polinom& ob2)     /// supraincarcare operator + pol to pol
{
    if (ob1.n == ob2.n)
    {

        polinom man(ob1.n);

        for (int i=1; i<=ob1.n; i++)
        {
            man[i]= ob1[i] + ob2[i];
        }

        return man;
    }
    else
    {

        int auxmin= 0,auxmax=0;
        if (ob1.n>ob2.n)
        {
            auxmax=ob1.n;
            auxmin=ob2.n;
        }
        else
        {
            auxmin=ob1.n;
            auxmax=ob2.n;
        }

        polinom man(auxmax);

        for (int i=1; i<=auxmin; i++)
            man[i]=ob1[i]+ob2[i];

        for ( int i=auxmin+1; i<=auxmax; i++)
        {

            if (auxmin==ob1.n)
                man[i]=ob2[i];
            else
                man[i]=ob1[i];
        }

        return man;
    }

}

const polinom operator+(polinom& ob1, double val)
{
    ob1[1]+=val;
    return ob1;
}

const polinom operator - (polinom& ob1,polinom& ob2)     /// supraincarcare operator - pol to pol
{
    int i;
    int auxmax,auxmin;
    if (ob1.get_n() == ob2.get_n())
    {
        polinom man(ob1.get_n());
        for (int i=1; i<=ob1.get_n(); i++)
        {
            man[i]= ob1[i] - ob2[i];
        }
        return man;
    }
    else
    {
        if (ob1.get_n()>ob2.get_n())
        {
            auxmax=ob1.get_n();
            auxmin=ob2.get_n();
        }
        else
        {
            auxmin=ob1.get_n();
            auxmax=ob2.get_n();
        }
        polinom man(auxmax);
        for (i=1; i<=auxmin; i++)
        {
            man[i]=ob1[i]-ob2[i];
        }
        for (i=auxmin+1; i<=auxmax; i++)
        {
            if (auxmin == ob1.get_n())
                man[i]=-ob2[i];
            else
                man[i]=ob1[i];

        }
        return man;
    }
}

const polinom operator -(polinom& ob1,double val)          /// operator - double
{
    ob1[1]= ob1[1] - val;
    polinom& man(ob1);
    return man;
}

const polinom operator-(double val, polinom& ob1)          /// supraincarcare operator - double to pol
{
    polinom& man(ob1);
    man[1]=val-ob1[1];
    return man;
}
const polinom operator*(polinom& ob1,polinom& ob2)          ///suprascriere * pol to pol
{

    while (ob1[ob1.n]==0)
        ob1.n--;
    while (ob2[ob2.n]==0)
        ob2.n--;
    int i,j;
    polinom man(ob1.n+ob2.n-1);
    for (i=1; i<=ob1.n; i++)
    {
        for (j=1; j<=ob2.n; j++)
        {
            man[i+j-1] += (ob1[i] * ob2[j]);
        }
    }

    return man;


}


const polinom operator* (polinom& ob1,double val)          ///suprascriere operator * pol to double
{
    int i;
    for (i=1; i<=ob1.get_n(); i++)
        ob1[i]=ob1[i]*val;
    polinom& man(ob1);
    return man;
}

const polinom operator* (double val, polinom& ob1)         ///supraincarcare operatorului * double to pol
{
    int i;
    for (i=1; i<=ob1.get_n(); i++)
        ob1[i]=ob1[i]*val;
    polinom& man(ob1);
    return man;
}

const polinom operator /(polinom& ob1,polinom& ob2)
{
    polinom man(ob1.n-ob2.n+1);
    int i,k=man.n;
    int l=ob2.n;
    polinom cop_ob1(ob1);
    for (i=ob1.n;i>=1 && k>0;i--)
    {
        man[k] = ob1[i] / ob2[l];
        man.afisare();
        polinom aux(k);
        aux[k]=ob1[i] / ob2[ob2.n];
        k=k-1;
        polinom man2=ob2*aux;
        ob1 = ob1 - man2; ///aici am facut o modif
        //      while (ob1[i] == 0)
        //           i--;
    }
    ob1=cop_ob1;
    return man;
}
const polinom operator /(polinom& ob1,double val)              /// supraincarcare operator / pol to val
{
    int i;
    polinom man(ob1.n);
    for (i=1;i<=ob1.n;i++)
        man[i]=ob1[i]/val;
    return man;
}

const polinom operator % (polinom& ob1,polinom& ob2)
{
    while (ob1[ob1.n]==0)
        ob1.n--;
    while (ob2[ob2.n]==0)
        ob2.n--;

    polinom man(ob1.n-ob2.n+1);
    polinom cop_ob1(ob1);
    int i,k=man.n;
    for (i=ob1.n;i>=1 && k>0;i--)
    {

//        while (ob1[i] == 0)
//            i--;

        man[k] = ob1[i] / ob2[ob2.n];

        polinom aux(k);

        aux[k]=ob1[i] / ob2[ob2.n];
        k=k-1;

        polinom man2=ob2*aux;
        ob1 = ob1 - man2; /// aici am facut o modif
//        while (ob1[i-1] == 0)
//            i--;
    }
    polinom copp_ob1(ob1);
    ob1=cop_ob1;
    return copp_ob1;
}

const polinom operator^(polinom& ob1, int val)
{
    int i;
    polinom cop_ob1(ob1);
    for (i=2;i<=val;i++)
        cop_ob1= cop_ob1*cop_ob1;
    return cop_ob1;

}


void operator +=(polinom& ob1,polinom& ob2)
{

    ob1= ob1+ob2;
}

void operator +=(polinom& ob1,double val)
{
    ob1 = ob1+val;
}
void operator +=(double &val, polinom& ob1)
{
    val = val + ob1[1];
}

void operator -=(polinom& ob1,polinom& ob2)
{
    ob1 = ob1- ob2;
}
void operator -=(polinom& ob1,double val)
{
    ob1 = ob1 - val;
}
void operator -= (double &val, polinom& ob1)
{
    val = val - ob1[1];
}
void operator *=(polinom &ob1,polinom& ob2)
{
    ob1 = ob1*ob2;
}
void operator *=(polinom&ob1, double val)
{
    ob1=ob1*val;
}
void operator *=(double &val,polinom& ob1)
{
    val = val * ob1[1];
}
void operator /=(polinom& ob1,polinom& ob2)
{
    ob1 = ob1/ob2;
}
void operator /=(polinom& ob1, double val)
{
    ob1 = ob1/val;
}
void operator /=(double &val, polinom& ob1)
{
    val = val / ob1[1];
}
int operator ==(polinom& ob1,polinom& ob2)
{
    int i;
    if (ob1.n!= ob2.n)
        return 0;
    for (i=1;i<=ob1.n;i++)
        if (ob1[i]!=ob2[i])
            return 0;
    return 1;
}
int operator ==(polinom& ob1,double val)
{
    if (ob1[1]==val && ob1.n==1)
        return 1;
    return 0;
}
int operator ==(double val,polinom& ob1)
{
    if (ob1[1]==val && ob1.n==1)
        return 1;
    return 0;
}
int operator !=(polinom& ob1,polinom& ob2)
{
    int i;
    if (ob1.n!=ob2.n)
        return 1;
    for (i=1;i<=ob1.n;i++)
    {
        if (ob1[i] != ob2[i])
            return 1;
    }
    return 0;
}
int operator !=(polinom& ob1,double val)
{
    if (ob1[1]!= val || ob1.n!=1)
        return 1;
    return 0;
}
int operator !=(double val,polinom& ob1)
{
    if (ob1[1]!= val || ob1.n!=1)
        return 1;
    return 0;
}

int operator !(polinom& ob1)
{
    if (ob1.n==0)
        return 0;
    return 1;
}

double polinom::operator() (double val)
{
    int i;
    double suma=0;
    for (i=1;i<=n;i++)
    {
        suma += coef[i]*pow(val,i-1);
    }
    return suma;
}


int grad (polinom& ob1)
{
    return ob1.n-1;
}

int operator<(polinom&ob1,polinom&ob2)
{
    if (ob1.n<ob2.n)
        return 1;
    int i;
    for (i=ob1.n;i>=1;i--)
    {
        if (ob1[i]>ob2[i])
            return 0;
    }
    return 1;
}

const polinom euclid(polinom& ob1, polinom& ob2)
{
    polinom man(1);
    polinom cop_ob1(ob1);
    polinom cop_ob2(ob2);
    if (cop_ob1<cop_ob2)
    {
        man=cop_ob1;
        cop_ob1=cop_ob2;
        cop_ob2=man;
    }
    while (!cop_ob2)
    {
        man = cop_ob1 % cop_ob2;
        cop_ob1 = cop_ob2;
        cop_ob2 = man;
    }

    return cop_ob1;
}


void polinom::afisare()
{
    int i;
    cout<<endl;
    retusare_polinom();
    for (i=1; i<=n; i++)
    {
        cout<<coef[i]<<" ";
    }
    cout<<endl;
}