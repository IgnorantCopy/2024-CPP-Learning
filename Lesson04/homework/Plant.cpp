//
// Created by Ignorant on 2024/4/20.
//

#include "Plant.h"
using namespace std;

void Plant1::beAttacked(int x)
{
    HP -= x;
    if (HP <= 0) {
        this->~Plant1();
    }
}

Plant1::Plant1(int price,int hp) : price(price), HP(hp)
{
    totalPrice += price;
}

Plant1::~Plant1() {
    totalPrice -= price;
}

Plant2::Plant2(int price) : price(price)
{
    totalPrice += price;
    totalNum++;
}
Plant2::~Plant2() {
    totalPrice -= price;
    totalNum--;
}

void changePrice(Plant1& plant1, Plant2& plant2)
{
    int temp = plant1.getPrice();
    Plant1::setTotalPrice(Plant1::getTotalPrice() - plant1.getPrice() + plant2.getPrice());
    Plant2::setTotalPrice(Plant2::getTotalPrice() - plant2.getPrice() + plant1.getPrice());
    plant1.setPrice(plant2.getPrice());
    plant2.setPrice(temp);
}

int getTotalPrice()
{
    return Plant1::getTotalPrice() + Plant2::getTotalPrice();
}

int getTotalPrice(const Plant1& plant1, const Plant1& plant2)
{
    return plant1.getPrice() + plant2.getPrice();
}

int getTotalPlant1Price()
{
    return Plant1::getTotalPrice();
}

//========
Plant2::Plant2(int price,int time1,int time2) : price(price), time1(time1), time2(time2)
{
    totalPrice += price;
    totalNum++;
}

void Plant2::func(int n)
{
    for (int i = 0; i < n; i++) {
        if (i >= time1 && i < time2) {
            setTotalNum(getTotalNum() + 1);
            this->func(n - i);
        } else if (i == time2) {
            this->~Plant2();
        }
    }
}

int getTotalPlant2Num()
{
    return Plant2::getTotalNum();
}

int Plant1::totalPrice = 0;
int Plant2::totalPrice = 0;
int Plant2::totalNum = 0;


int main() {
//    Plant1 t(20, 3);
//    Plant1 t2(30, 4);
//    cout << getTotalPrice(t, t2) << endl;
    
//    Plant1 t(20, 3);
//    Plant2 t3(40);
//    cout << getTotalPrice() << endl;
    
//    Plant1 t(20, 3);
//    Plant2 t3(40);
//    changePrice(t, t3);
//    cout << getTotalPlant1Price() << endl;
    
//    Plant2 t(4, 1, 3);
//    t.func(4);
//    cout << getTotalPlant2Num() << endl;
    
    Plant2 t(4, 1, 3);
    Plant2 t1(4, 1, 3);
    t.func(4);
    t1.func(4);
    cout << getTotalPlant2Num() << endl;
    
    return 0;
}
