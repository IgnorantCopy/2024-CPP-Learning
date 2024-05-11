//
// Created by Ignorant on 2024/5/11.
//

#ifndef INC_2024_CPP_LEARNING_MAP_H
#define INC_2024_CPP_LEARNING_MAP_H

#include<string>
#include<vector>
#include<list>

using namespace std;

inline unsigned hashFunc(const string &s)
{
    return (unsigned int)(s[0]);
}

class Map {
private:
    /*
     * 数据成员
     * 不做规定，由你自己实现
     */
    vector<list<pair<string, int>>> buckets = vector<list<pair<string, int>>>(200, list<pair<string, int>>());
public:
    Map(); // 构造函数，构造一个空映射表，初始化数据成员
    ~Map(); // 析构函数，释放申请的内存空间
    
    bool insert(const string& key, int value); // 插入键值到映射表中
    // 成功插入返回true；若对应键已存在旧值，插入失败，返回false
    
    bool erase(const string &key); // 删除该键的键值对
    // 成功删除返回true；若不存在对应键的键值对，删除失败，返回false
    
    bool find(const string &key); // 返回映射表中是否含有对应键的键值对
    
    int & operator[](const string &key); // 数组下标访问操作符重载
    // 可以通过下标访问的方式直接用键得到值的引用
    // 需要注意的是，如果用下标访问的方式访问了不存在的key，你需要为该key创建一个键值对
    // 此法创建的值初始为0，你需要返回该值的引用
    
    int size() const; // 返回映射表中当前记录的键值对总数
};

#endif //INC_2024_CPP_LEARNING_MAP_H
