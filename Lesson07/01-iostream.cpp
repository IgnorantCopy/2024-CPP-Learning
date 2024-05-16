//
// Created by Ignorant on 2024/5/16.
//

#include <iostream>
#include <iomanip>
#include <istream>
#include <limits>
using namespace std;

/*
 * summary of ioStream
 *  1. implementation
 *      > output: ostream, cout, <<, etc.
 *      > input: istream, cin, >>, etc.
 *  2. classification
 *      ① console-oriented io:
 *          > 从标准输入设备（如：键盘）获得数据
 *          > 向标准输出设备（如：显示器）输出数据
 *      ② file-oriented io:
 *          > 从外存（磁盘）获得数据
 *          > 把结果保存到外存（磁盘）中
 *      ③ string-oriented io:
 *          > 从程序中的字符串变量中获得数据
 *          > 把结果保存到字符串变量中
 *  3. diagram
 *      > ios
 *          > istream
 *              |________________________________
 *              > ifstream                      |
 *              > istrstream                    |-----------------> iostream
 *          > ostream                           |                       > fstream
 *              |_______________________________|                       > strstream
 *              > ofstream
 *              > ostrstream
 */

class Complex {
    double real;
    double image;
public:
    explicit Complex(double r = 0, double i = 0) : real(r), image(i) {}
    
    double getReal() const { return real; }
    double getImage() const { return image; }
    void setReal(double r) { real = r; }
    void setImage(double i) { image = i; }
    
    friend ostream& operator<<(ostream& out, const Complex& c);
};

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real << " + " << c.image << "i";
    return out;
}

int main() {
    /*
     * 4. usage
     *     ① include <iostream> for console-oriented io
     *      special circumstances:
     *          cout a pointer
     */
//    char *p = new char[]{'a'};
//    cout << p << endl;
//    cout << (void*) p << endl;
//    delete[] p;
    int num = 123456;
    // manipulator: in <iomanip>
    cout << dec << num << endl; // 十进制输出
    cout << hex << num << endl; // 十六进制输出
    cout << oct << num << endl; // 八进制输出
    double pi = 3.14159265358979323846;
    cout << fixed << setprecision(2) << pi << endl; // 固定小数点输出，精度为2位
    cout << scientific << pi << endl; // 科学计数法输出
    char str[10] = {0};
    cin >> setw(10) >> str; // 限定输入宽度为10
    char str2[10] = {0};
    cin.ignore(2, '\n');    // 忽略缓存区中的前2个字符，或者直到遇到'\n'
    cin.getline(str2, 10, '\n'); // 读取一行，并以'\n'作为结束符
    if (cin.fail()) {   // 如果本行还有未读入的字符
        cin.clear();    // 则清除错误状态
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略剩余的输入
    }
    cout << str << endl;
    cout << str2 << endl;
    
    Complex c1(11, 1);
    Complex c2(22, 2);
    cout << c1 << endl << c2 << endl;
    /*
     *     ③ include <strstream> for string-oriented io
     */
    return 0;
}
