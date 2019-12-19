#include "polinominal.h"
#include<cmath>
#include<algorithm>
#include<initializer_list>


void polinominal::init(int d, double*c){
    deg=d;
    cf =c;
}


void polinominal::destroy(){
    delete[] cf;
};


double polinominal::value(double x) const{
    double s=0;
    for(int i=0; i<=deg;++i){
        s += std::pow(x,i) * coef(i);
    }
    return s;
}


double & polinominal:: coef(int i) const{
    if(i > deg || i < 0) throw "index out of range";
    return cf[i];
}


polinominal::polinominal(){ deg=0; cf=nullptr;};

polinominal::polinominal(int d, double*c){deg = d; cf = c;}

polinominal::~polinominal(){delete[] cf;}

polinominal::polinominal(const polinominal &p){
    deg = p.deg;
    cf = new double[deg+1];
    for(int i=0; i< deg+1; ++i){
        cf[i]=p.cf[i];
    }
};

// перемещение
polinominal::polinominal(polinominal&& p): deg(p.deg), cf(p.cf){
    p.deg =0;
    p.cf=nullptr;

}


polinominal:: polinominal(int x){
    deg=0;
    cf=new double[1];
    cf[0]=x;
}

polinominal::polinominal(const std::initializer_list<double> &list):
    deg(list.size()-1),
    cf(new double[list.size()])
{
    std::copy(list.begin(), list.end(), cf);
};




polinominal operator+(const polinominal &p, const polinominal &q){
    polinominal s;
    int d = std::max(p.deg, q.deg);
    double*cf = new double[1+d];
    s.init(d, cf);
    for(int i = 0; i<=(std::min(p.deg, q.deg)); ++i){
        s.coef(i) = p.coef(i) + q.coef(i);
    }
    if(p.deg>q.deg){for(int i=p.deg; i>q.deg; --i) s.coef(i)=p.coef(i);}
    if(q.deg>p.deg){for(int i=q.deg; i>p.deg; --i) s.coef(i)=q.coef(i);}
    if(s.coef(s.deg)==0){while((s.coef(s.deg)==0)&&s.deg>0) --s.deg;}
    return s;
}

polinominal operator-(const polinominal &p, const polinominal &q){
    polinominal s;
    int d=std::max(p.deg, q.deg);
    double*cf = new double[1+d];
    s.init(d, cf);
    for(int i=0; i<=(std::min(p.deg, q.deg)); ++i){
        s.coef(i) = p.coef(i)-q.coef(i);
    }
    if(p.deg>q.deg){for(int i=p.deg; i>q.deg; --i) s.coef(i)=p.coef(i);}
    if(q.deg>p.deg){for(int i=q.deg; i>p.deg; --i) s.coef(i)=-q.coef(i);}
    if(s.coef(s.deg)==0){while((s.coef(s.deg)==0)&&s.deg>0) --s.deg;}
    return s;
}

polinominal operator*(const polinominal &p, const polinominal &q){
    polinominal s;
    int d = p.deg+q.deg;
    double*cf = new double[d+1];
    for(int i = 0; i <= d; ++i) cf[i]=0;
    s.init(d, cf);
    for(int i=0; i <= p.deg; ++i){
        for(int j=0; j <= q.deg; ++j)
        {
            s.coef(i+j) += p.coef(i)*q.coef(j);
        }
    }
    if(s.coef(s.deg)==0){while((s.coef(s.deg)==0)&&s.deg>0) --s.deg;}
    return s;
}

polinominal operator/(const polinominal &p, const polinominal &q){
    polinominal s;
    int d = p.deg-q.deg;
    if(d<0)
    {
        double*cf = new double[1];
        cf[0]=0;
        s.init(0,cf);
        return s;
    }
    double*cf = new double[d+1];
    for(int i=0; i<=d; ++i) cf[i]=0;
    s.init(d, cf);
    polinominal tmp, tmp2, p1 = p;  // р1 = текущее делимое
    while (p1.deg >= q.deg){
        int t = p1.deg - q.deg;     // текущая старшая степень
        // заводим два вспомогательных массива
        double* tp = new double[p1.deg + 1];
        for( int k = 0; k <= p1.deg; ++k)
            tp[k]=0;
        double* tp2 = new double[t + 1];
        for( int k=0; k <= t; ++k)
            tp2[k]=0;
        tmp2.init(t, tp2);          // текущее частное
        tmp.init(p1.deg, tp);       // q * текущее частное
        // вычисляем текущий страший коеффициент частного
        s.coef(t) = p1.coef(p1.deg) / q.coef(q.deg);    // текущий старший коеффициент частного
        tmp2.coef(t) = s.coef(t);   // текущий старший коеффициент текущего частного
        tmp = tmp2 * q;
        p1 = p1 - tmp;
//        tmp.destroy();
//        tmp2.destroy();
    }
    return s;
}

polinominal operator%(const polinominal &p, const polinominal &q){
    polinominal s = p -(p/q)*q;
    return s;
}
std::ostream & operator<<(std::ostream & st, polinominal  p){
    for (int i=0; i<=p.deg; ++i){ st<<p.coef(i)<<" ";}
    return st<<" ";
}
std::istream & operator>>(std::istream & st, polinominal & p){
    for (int i=0; i<=p.deg; ++i){ st>>p.coef(i);}
    return st;
}
// присваивание через копирование
polinominal& polinominal :: operator=(const polinominal& p){
    if(&p==this){return *this;}
    delete[] cf;
    deg=p.deg;
    cf=new double[p.deg+1];
    for(int i=0; i<=deg;++i){cf[i]=p.cf[i];}
    return *this;
}

// индексация
double& polinominal:: operator[](int i) const {
    static double c = -1;
    if((i >= 0)&&(i <= deg)) {
        return cf[i];
    }
    return c;
}

double polinominal:: operator()(double x) const{
    double s = 0;
    for(int i = 0; i <= deg; ++i){
        s += std::pow(x, i) * coef(i);
    }
    return s;
}