#include"sidorov.h"
#include<iostream>
using namespace sidorov;
int sidorov::rate;   //ставка налога
std::string sidorov::names[N];
int sidorov::passport_data[N];
std::string sidorov::address[N];
double sidorov::part[N];
int sidorov::price[N];

void sidorov::tax(){
    for(int i=0; i<N; ++i){
        std::cout<<names[i]<<": address: "<<address[i]<<" price: "<<price[i]<<"tax: "<<rate *(part[i])*(price[i])<<std::endl;
    }
}

