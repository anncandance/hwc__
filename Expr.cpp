#include <iostream>
#include <cstdlib>
#include<cmath>

using namespace std;


struct Expr
{
    virtual ~Expr() {}
    virtual void print() = 0;
    virtual double eval (double) = 0;
    virtual Expr* der() = 0;
    virtual Expr* copy() = 0;
};


struct Const : Expr
{
    double a;
    Const (double aa) : a(aa) {}
    void print()
    {
        cout << a;
    }
    double eval(double)
    {
        return a;
    }

    Expr* der()
    {
        return new Const(0);
    }
    Expr* copy()
    {
        return new Const(a);
    }
};


struct Var : Expr
{
    void print()
    {
        cout << "x";
    }
    double eval(double x)
    {
        return x;
    }
    Expr* der()
    {
        return new Const(1);
    }
    Expr* copy()
    {
        return new Var;
    }
};


struct Sum : Expr
{
    Expr* l, * r;
    Sum(Expr* ll, Expr* rr) : l(ll), r(rr) {}
    void print()
    {
        cout << "(";
        l->print();
        cout << "+";
        r->print();
        cout << ")";
    }
    double eval(double x)
    {
        return l->eval(x) + r->eval(x);
    }
    Expr* der()
    {
        return new Sum(l->der(), r->der());
    }
    Expr* copy()

    {
        return new Sum(l->copy(), r->copy());
    }
};

struct Multiplication : Expr
{
    Expr *l, *r;
    Multiplication(Expr *ll, Expr *rr) : l(ll), r(rr) {};
    void print()
    {
        cout << "("; l -> print(); cout << " * "; r -> print(); cout << ")" << endl;
    }
    double eval(double x)
    {
        return l -> eval(x) * r -> eval(x);
    }
    Expr* der()
    {
        return new Sum( new Multiplication(l->der(), r), new Multiplication(l, r -> der()) );
    }
    Expr* copy()
    {
        return new Multiplication(l -> copy(), r -> copy());
    }

};

struct Cos :Expr
{

    void print()
    {
        cout<<" Cos x ";
    }
    double eval(double xx)
    {
        return cos(xx);
    }
    Expr* copy()
    {
        return new Cos;
    }
    Expr* der();

};

struct Sin : Expr
{

    void print()

    {
        cout<<" Sin x ";
    }
    double eval(double xx)
    {
        return sin(xx);
    }
    Expr* der()
    {
        return new Cos;
    }
    Expr* copy()
    {
        return new Sin;
    }
};

Expr* Cos::der()
{
    return new Multiplication(new Const(-1),  new Sin);
}
