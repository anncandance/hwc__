
class Mass
{
    double m;

public:
    Mass(double mm): m(mm){}
    double get()
    {
        return m;
    }
    friend Mass operator "" _kg(long double mm); // килограмм
    friend Mass operator "" _c(long double mm);  // центнер
    friend Mass operator "" _oz(long double mm); // унция
    friend Mass operator "" _f(long double mm); // фунт
    friend Mass operator "" _t(long double mm); // тонна

    friend Mass operator+(Mass a, Mass b)
    {
        return Mass(a.m + b.m);
    }
    friend Mass operator+(Mass a, double mm)
    {
        return Mass(a.m + mm);
    }
    friend Mass operator-(Mass a, double mm)
    {
        return Mass(a.m - mm);
    }
    friend Mass operator*(Mass a, double mm)
    {
        return Mass(a.m * mm);
    }
    friend Mass operator/(Mass a, double mm)
    {
        return Mass(a.m / mm);
    }

};

Mass operator "" _kg(long double mm) // килограмм
{
    return Mass((double)mm);
}
Mass operator "" _c(long double mm)
{
return Mass((double)mm * 100);
}
Mass operator "" _oz(long double mm) // унция
{
    return Mass((double)(mm * 0.0283495));
}
Mass operator "" _f(long double mm) // фунт
{
    return Mass((double)(mm * 0.453592));
}
Mass operator "" _t(long double mm) // тонна
{
    return Mass((double)(mm * 1000));
}