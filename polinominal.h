#ifndef HWC_POLINOMINAL_H
#define HWC_POLINOMINAL_H
#include<iostream>


class polinominal {
    int deg;
    double* cf;

public:
    void init(int d, double*c);
    void destroy();
    double & coef(int i);
    double value(double x);


    friend polinominal operator+(polinominal p, polinominal q);
    friend polinominal operator-(polinominal p, polinominal q);
    friend polinominal operator*(polinominal p, polinominal q);
    friend polinominal operator/(polinominal p, polinominal q);
    friend polinominal operator%(polinominal p, polinominal q);

    friend std::ostream & operator<<(std::ostream & st, polinominal p);
    friend std::istream & operator>>(std::istream & st,polinominal & p);

};


#endif //HWC_POLINOMINAL_H
