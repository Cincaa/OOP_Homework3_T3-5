#include<iostream>
using namespace std;

class base{
public:
    virtual void print1(){
        cout<<"base print 1\n";
    }
    void print2(){
        cout<<"base print 2\n";
    }
};
 class derived:public base{
public:
    void print1(){
        cout<<"derived print 1\n";
    }
    void print2(){
        cout<<"derived print 2\n";
    }
 };

 int main()
 {
     base *A;
     derived B;
     A=&B;
     A->print1();
     A->print2();
     B.print1();
     B.print2();
 }
