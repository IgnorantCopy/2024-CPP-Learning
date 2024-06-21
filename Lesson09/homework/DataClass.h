//
// Created by Ignorant on 2024/6/13.
//

#ifndef INC_2024_CPP_LEARNING_DATACLASS_H
#define INC_2024_CPP_LEARNING_DATACLASS_H

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class DataClass {
private:
    std::vector<std::string> data_;

public:
    DataClass(const std::vector<std::string> &data) : data_(data) {}
    
    std::string HashKey() const {
        // Your code here
        std::string result;
        for (auto const& s : data_) {
            result += s;
            result += " ";
        }
        return result;
    }
    
    bool operator==(const DataClass &dc) const {
        // Your code here
        return HashKey() == dc.HashKey();
    }
};

// 不需要修改
struct DataClassHash {
    size_t operator()(const DataClass &dc) const {
        
        std::string str = dc.HashKey();
        
        return std::hash<std::string>()(str);
    }
};

#endif //INC_2024_CPP_LEARNING_DATACLASS_H
