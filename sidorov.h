
#ifndef HWC_SIDOROV_H
#define HWC_SIDOROV_H
#include<iostream>
namespace sidorov {
    const int N = 3;     // размер базы
    extern int rate;   //ставка налога
    extern std::string names[N];
    extern int passport_data[N];
    extern std::string address[N];
    extern double part[N];
    extern int price[N];
    void tax();


}
#endif //HWC_SIDOROV_H
