//
// Created by Ignorant on 2024/5/10.
//

#ifndef INC_2024_CPP_LEARNING_STRING_H
#define INC_2024_CPP_LEARNING_STRING_H

class String {
private:
    int len;    // 字符串长度
    char *str_p;    // 字符串数据

public:
    const char* getStr_p() { return str_p; }
    String();
    String(const char *s);
    String(const String &s);
    
    ~String();     //注意内存泄漏和野指针问题
    
    void print();  //输出字符串，最后输出换行符\n
    
    //重载操作符=，[]
    String& operator=(const String &s);
    String& operator=(const char* s);
    char & operator[](int index);
    
    //TODO:+  字符串拼接 a+b=ab
    String operator+(const String &s);
    
    //TODO:==,!=,<  返回值为bool类型，按ASCII码值比较，约定 a<aa
    bool operator==(const String &s) const;
    bool operator!=(const String &s) const;
    bool operator<(const String &s) const;
};

#endif //INC_2024_CPP_LEARNING_STRING_H
