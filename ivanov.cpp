#include"ivanov.h"
#include<iostream>

using namespace ivanov;

int ivanov::rate;   //ставка налога
std::string ivanov::names[N];
int ivanov::passport_data[N];
int ivanov::No[N];
int ivanov::square[N];
int ivanov::price[N];

void ivanov::tax(){
    for(int i=0; i<N; ++i){
        std::cout<<names[i]<<": site number: "<<No[i]<<" price: "<<price[i]<<"tax: "<<rate *(square[i])*(price[i])<<std::endl;
    }
}



