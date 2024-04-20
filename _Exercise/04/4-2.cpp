//
// Created by Ignorant on 2024/4/17.
//

#include "4-2.h"

using namespace std;

TimeParser::TimeParser(string s)
{
    /* TODO */
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ':') {
            count++;
        }
    }
    if (count == 2) {
        size_t pos = s.find(':');
        strHour = s.substr(0, pos);
        s = s.substr(pos + 1);
        pos = s.find(':');
        strMin = s.substr(0, pos);
        strSec = s.substr(pos + 1);
        isError = 0;
    } else {
        isError = 1;
    }
    if (strHour.length() != 2 || strMin.length() != 2 || strSec.length() != 2) {
        isError = 1;
    } else {
        int hour = stoi(strHour);
        int min = stoi(strMin);
        int sec = stoi(strSec);
        if (hour >= 24 || min >= 60 || sec >= 60) {
            isError = 1;
        }
    }
}

int TimeParser::getHour()
{
    /* TODO */
    if (!isError) {
        return stoi(strHour);
    }
    return -1;
}

int TimeParser::getMin()
{
    /* TODO */
    if (!isError) {
        return stoi(strMin);
    }
    return -1;
}

int TimeParser::getSec()
{
    /* TODO */
    if (!isError) {
        return stoi(strSec);
    }
    return -1;
}

int main() {
    TimeParser timeParser1("10:00:40");
    cout << timeParser1.getHour() << ' ';
    cout << timeParser1.getMin() << ' ';
    cout << timeParser1.getSec() << endl;
    TimeParser timeParser2("4:6:6");
    cout << timeParser2.getHour() << ' ';
    cout << timeParser2.getMin() << ' ';
    cout << timeParser2.getSec() << endl;
    
    return 0;
}
