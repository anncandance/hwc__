#include <iostream>
#include"polinominal.h"

int main() {
    int n, m;
    std::cin>>n>>m;
    polinominal p, q;
    double *d =new double[n+1];
    double*t =new double[m+1];
    for(int i=0; i<=n; ++i)d[i]=0;
    for(int i=0; i<=m; ++i)t[i]=0;
    p.init(n, d);
    q.init(m, t);
    std::cin>>p;
    std::cin>>q;
    std::cout<<p+q<<'\n'<<p-q<<'\n'<<p*q<<'\n'<<p/q<<'\n'<<p%q;
    return 0;
}

