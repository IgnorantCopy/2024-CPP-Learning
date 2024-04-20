//
// Created by Ignorant on 2024/4/20.
//

#ifndef INC_2024_CPP_LEARNING_PLANT_H
#define INC_2024_CPP_LEARNING_PLANT_H

#include<iostream>

class Plant1
{
private:
    int price; //该植物的价格，每个实体价格可能不一样
    int HP; //该植物的生命值，每个实体生命值可能不一样
    
    static int totalPrice;
public:
    void beAttacked(int x); //植物被x点伤害攻击，生命值应下降x
    
    Plant1(int price,int hp); //要完成的构造函数，另外也可以自行添加其他构造函数
    ~Plant1(); //析构函数
    
    int getPrice() const {
        return price;
    }
    
    void setPrice(int p) {
        price = p;
    }
    
    static int getTotalPrice() {
        return totalPrice;
    }
    
    static void setTotalPrice(int p) {
        totalPrice = p;
    }
};

class Plant2
{
private:
    int price; //该植物的价格，每个实体价格可能不一样
    
    static int totalPrice;
    static int totalNum;
    //=========
    int time1=0;
    
    int time2=0;
public:
    Plant2(int price); //要完成的构造函数，另外也可以自行添加其他构造函数
    ~Plant2(); //析构函数
    
    int getPrice() const {
        return price;
    }
    
    void setPrice(int p) {
        price = p;
    }
    
    static int getTotalPrice() {
        return totalPrice;
    }
    
    static void setTotalPrice(int p) {
        totalPrice = p;
    }
    
    static int getTotalNum() {
        return totalNum;
    }
    
    static void setTotalNum(int num) {
        totalNum = num;
    }
    
    //=========
    
    Plant2(int price,int time1,int time2); //需要完成的构造函数
    
    //该植物类的功能，n表示该植物从种植开始经过的天数，n可能大于time2，具体可看示例
    void func(int n);
};

//两个 不同类 的植物交换价格
void changePrice(Plant1& plant1, Plant2& plant2);

//获得所有植物的总价格，包括所有Plant1实体和所有Plant2实体
int getTotalPrice();

//获得Plant1的两个实体的总价格
int getTotalPrice(const Plant1& plant1, const Plant1& plant2);

//获得Plant1的所有实体的总价格
int getTotalPlant1Price();

//==========

//获得Plant2的总数量
int getTotalPlant2Num();

#endif //INC_2024_CPP_LEARNING_PLANT_H
