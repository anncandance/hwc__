#include "polinominal.h"
#include<cmath>
#include<algorithm>


void polinominal::init(int d, double*c){
    deg=d;
    cf =c;
}
void polinominal::destroy(){
    delete[] cf;
};
double polinominal::value(double x){
    double s=0;
    for(int i=0; i<=deg;++i){
        s+=std::pow(x,i)*coef(i);
    }
    return s;
}
double & polinominal::coef(int i){
    if(i>deg||i<0) throw "index out of range";
    return cf[i];
}

polinominal operator+(polinominal p, polinominal q){
    polinominal s;
    int d=std::max(p.deg, q.deg);
    double*cf = new double[1+d];
    s.init(d, cf);
    for(int i=0; i<=(std::min(p.deg, q.deg)); ++i){
    s.coef(i) = p.coef(i)+q.coef(i);
    }
    if(p.deg>q.deg){for(int i=p.deg; i>q.deg; --i) s.coef(i)=p.coef(i);}
    if(q.deg>p.deg){for(int i=q.deg; i>p.deg; --i) s.coef(i)=q.coef(i);}
    if(s.coef(s.deg)==0){while((s.coef(s.deg)==0)&&s.deg>0) --s.deg;}
    return s;
}

polinominal operator-(polinominal p, polinominal q){
    polinominal s;
    int d=std::max(p.deg, q.deg);
    double*cf = new double[1+d];
    s.init(d, cf);
    for(int i=0; i<=(std::min(p.deg, q.deg)); ++i){
        s.coef(i) = p.coef(i)-q.coef(i);
    }
    if(p.deg>q.deg){for(int i=p.deg; i>q.deg; --i) s.coef(i)=p.coef(i);}
    if(q.deg>p.deg){for(int i=q.deg; i>p.deg; --i) s.coef(i)=q.coef(i);}
    if(s.coef(s.deg)==0){while((s.coef(s.deg)==0)&&s.deg>0) --s.deg;}
    return s;
}

polinominal operator*(polinominal p, polinominal q){
    polinominal s;
    int d=p.deg+q.deg;
    double*cf = new double[d+1];
    for(int i=0; i<=d; ++i) cf[i]=0;
    s.init(d, cf);
    for(int i=0; i<=p.deg; ++i){
        for(int j=0; j<=q.deg; ++j) {
            s.coef(i+j)+=p.coef(i)*q.coef(j);
        }
    }
    if(s.coef(s.deg)==0){while((s.coef(s.deg)==0)&&s.deg>0) --s.deg;}
    return s;
}

polinominal operator/(polinominal p, polinominal q){
    polinominal s;
    int d = p.deg-q.deg;
    if(d<0)  {s.init(0,nullptr);
    return s;}
    double*cf = new double[d+1];
    for(int i=0; i<=d; ++i) cf[i]=0;
    s.init(d, cf);
    polinominal tmp, tmp2;
    while (p.deg>=q.deg){
        double* tp = new double[p.deg+1];
        for( int k=0; k<=p.deg; ++k) tp[k]=0;
        tmp.init(p.deg, tp);
        double* tp2 = new double[p.deg-q.deg+1];
        for( int k=0; k<=p.deg-q.deg; ++k) tp2[k]=0;
        tmp2.init(p.deg-q.deg, tp2);
        s.coef(p.deg-q.deg) = p.coef(p.deg)/q.coef(q.deg);
        tmp2.coef(p.deg-q.deg) = s.coef(p.deg-q.deg);
        tmp = tmp2*q;
        p =p-tmp;
        tmp.destroy();
        tmp2.destroy();
    }
    return s;
}

polinominal operator%(polinominal p, polinominal q){
    polinominal s = p -(p/q)*q;
    return s;
}
std::ostream & operator<<(std::ostream & st, polinominal  p){
    for (int i=0; i<=p.deg; ++i){ st<<p.coef(i)<<" ";}
    return st<<" ";
}
std::istream & operator>>(std::istream & st,polinominal & p){
    for (int i=0; i<=p.deg; ++i){ st>>p.coef(i);}
    return st;
}


