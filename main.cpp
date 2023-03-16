#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

class Complex
{
private:
    float real;
    float img;

public:

// DEFAULT CONSTRUCTOR
    Complex ()
    {
        real=3.5;
        img=4.8;
        cout<< "I am default"<<endl;
    }

// OVERLOADED CONSTRUCTOR
    Complex (float x)
    {
        real=img=x;
        cout<< "I am overloaded constructor"<<endl;

    }

// OVERLOADED CONSTRUCTOR
    Complex (float x,float y)
    {
        real = x;
        img = y;
        cout<< "I am overloaded constructor"<<endl;

    }

// SETTER FUNCTIONS
    void setReal(float r)
    {
        real=r;
    }
    void setImg(float i)
    {
        img=i;
    }

// GETTER FUNCTIONS
    float getReal()
    {
        return real;
    }
    float getImg()
    {
        return img;
    }

// PRINT FUNCTION
    void print ();
};





// FUNCTIONS DECLARATION
Complex sumNum (Complex,Complex);
Complex sumNum (Complex,float);
Complex sumNum (float,Complex);
Complex sumNum (Complex,Complex,Complex);

float validFun (float&,int,string);





int main()
{
    float r1,r2,r3,i1,i2,i3;
    Complex c1,c2,c3,c4,c5,c6,c7;

    do
    {
// ENTER DATA OF 3 COMPLEX NUMBERS
        validFun (r1,1,"real");
        c1.setReal(r1);
        validFun (i1,1,"img");
        c1.setImg (i1);
        cout<<endl;
        validFun (r2,2,"real");
        c2.setReal(r2);
        validFun (i2,2,"img");
        c2.setImg (i2);
        cout<<endl;
        validFun (r3,3,"real");
        c3.setReal(r3);
        validFun (i3,3,"img");
        c3.setImg (i3);

// FUNCTIONS CALL
        cout<<endl;
        cout<< "\nSum two complex equal "<<endl;
        c4= sumNum(c1,c2);
        c4.print();
        cout<<endl;
        cout<< "\nSum complex and float equal "<<endl;
        c5= sumNum(c1,3.5);
        c5.print();
        cout<<endl;
        cout<< "\nSum float and complex equal "<<endl;
        c6= sumNum(3.5,c1);
        c6.print();
        cout<<endl;
        cout<< "\nSum three complex equal "<<endl;
        c7= sumNum(c1,c2,c3);
        c7.print();
        cout<<endl;

// CONSTRUCTORS CALL
        cout<< "\nComplex default constructor  "<<endl;
        Complex c8;
        c8.print();
        cout<<endl;
        cout<< "\nComplex constructor float "<<endl;
        Complex c9(5.6);
        c9.print();
        cout<<endl;
        cout<< "\nComplex constructor float, float "<<endl;
        Complex c10(3.2,7.5);
        c10.print();
        cout<<endl;
    }
    while(true);

    return 0;
}




// FUNCTIONS IMPLEMENTATION
Complex sumNum (Complex x,Complex y)
{
    Complex res;
    res.setReal(x.getReal() + y.getReal());
    res.setImg(x.getImg() + y.getImg());
    return res;
}
Complex sumNum (Complex x,float y)
{
    Complex res;
    res.setReal(x.getReal() + y);
    res.setImg(0);
    return res;
}
Complex sumNum (float y,Complex x)
{
    Complex res;
    res.setReal(y + x.getReal());
    res.setImg(0);
    return res;
}
Complex sumNum (Complex x,Complex y=0,Complex z=0)
{
    Complex res;
    res.setReal(x.getReal() + y.getReal()+ z.getReal());
    res.setImg(x.getImg() + y.getImg()+ z.getImg());
    return res;
}



// PRINT FUNCTION IMPLEMENTATION
void Complex::print ()
{
    if (img>0 && real>0)
    {
        if (img!=1)
            cout<<real<< "+"<<img<< "i"<<endl;
        else
            cout<<real<< "+" << "i"<<endl;
    }
    else if (img<0 && real !=0)
    {
        if (img!=-1)
            cout<<real <<img<< "i"<<endl;
        else
            cout<<real<< "-"<< "i"<<endl;
    }
    else if (real==0&&img==0)
        cout<<"0"<<endl;
    else if (real==0)
        cout<<img<<"i"<<endl;
    else if (img==0)
        cout<<real<<endl;
}




// VALIDATION FUNCTION

float validFun ( float& x,int n,string cha)
{
    cout<< "enter "<< cha <<" "<< n << " : ";
    cin>>x;
    bool validInp = false;
    while (!validInp)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input is not a number" << endl;
            cout<< "enter "<< cha <<" "<< n << " : ";
            cin>>x;
        }
        else
        {
            validInp =true;
        }
    }
    return x;
}
