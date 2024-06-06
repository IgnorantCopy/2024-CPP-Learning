//
// Created by Ignorant on 2024/5/30.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

/*
 * What is included in the Standard Template Library (STL)?
 *  > Volumes: vector, list, queue, stack, map, set, etc.
 *      * vector: dynamic array     - get elements at any position, add and delete elements at the end
 *      * list: doubly linked list  - insert and delete elements at any position
 *      * deque: segmented continuous spatial structure     - get elements at any position, add and delete elements
 *                                                              at the beginning and the end
 *      * stack: based on deque, list or vector     - add and delete elements at the top only
 *      * queue: based on deque, list       - add elements at the end, delete elements at the beginning
 *      * priority_queue: based on deque or vector  - add elements at the end, delete elements at the beginning,
 *                                                  and sort them to ensure the highest priority element is at the top
 *      * map<key type, value type> and multimap<key type, value type>: binary tree
 *          like dictionaries, store key-value pairs
 *          two members: first for key and second for value
 *          key in map must be unique, but in multimap, multiple keys can be the same
 *      * set<type> and multiset<type>: particular case of map and multimap, where value is not needed
 *      * basic_string<char type>
 *          string == basic_string<char>
 *          wstring == basic_string<wchar_t>
 *  > Iterator
 *      * output iterator: can only modify the elements pointed to by the iterator, but not read them
 *          get indirectly: *
 *          operator: ++
 *      * input iterator: can only read the elements pointed to by the iterator, but not modify them
 *          get indirectly: * / ->
 *          operator: ++ / == / !=
 *      * forward iterator: can read and modify the elements pointed to by the iterator
 *          get indirectly: * / ->
 *          operator: ++ / == / !=
 *      * bidirectional iterator: can read, modify, and move backwards through the elements pointed to by the iterator
 *          get indirectly: * / ->
 *          operator: ++ / -- / == / !=
 *          volumes: list, map, multimap, set, multiset
 *      * random access iterator: can read, modify, and move to any position in the sequence
 *          get indirectly: * / -> / []
 *          operator: ++ / -- / + / - / += / -= / == / != / > / < / >= / <=
 *          volumes: vector, deque, basic_string
 *      queue, stack, priority_queue do not have iterators
 *      random-access -> bidirectional -> forward -> input / output
 *  > Algorithms: searching, sorting, counting, summing, etc.
 *      operations for sequential containers:
 *      * reordering algorithm
 *      * editing algorithm
 *      * searching algorithm
 *      * arithmetical algorithm
 *      * set algorithm
 *      * heap algorithm
 *      * traversal algorithm
 */

void algorithmTest() {
    vector<int> vector;
    int n = 0;
    while (cin >> n) {
        vector.push_back(n);
    }
    cout << "Max = " << *max_element(vector.begin(), vector.end()) << endl;
    cout << "Sum = " << accumulate(vector.begin(), vector.end(), 0) << endl;
    sort(vector.begin(), vector.end());
    for_each(vector.begin(), vector.end(), [](int x) { cout << x << " "; });
    cout << endl;
}

void vectorTest() {
    vector<int> vector;     // create an empty vector
    int n = 0;
    while (cin >> n) {
        vector.push_back(n);    // add an element to the end of the vector
    }
    int sum = 0;
    int max;
    int min;
    max = min = vector[0];
    for (int i : vector) {
        sum += i;
        if (i > max) {
            max = i;
        } else if (i < min) {
            min = i;
        }
    }
    cout << "Sum = " << sum << endl;
    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;
}

void mapTest() {
    map<string, int> phoneBook;
    // add some entries to the phone book
    phoneBook["Alice"] = 123456789;
    phoneBook["Bob"] = 987654321;
    phoneBook["Charlie"] = 111111111;
    // print the phone book
    for (auto const& entry : phoneBook) {
        cout << entry.first << " : " << entry.second << endl;
    }
    string name;
    cout << "Enter a name to search for: ";
    cin >> name;
    auto iterator = phoneBook.find(name);    // find the entry with the given name
    if (iterator == phoneBook.end()) {
        cout << "Name not found." << endl;
    } else {
        cout << iterator->first << " : " << iterator->second << endl;
    }
}

void iteratorTest() {
    // Josephus Problem
    int number = 0;
    int n = 0;
    cout << "Please input the number and the number of people: ";
    cin >> number >> n;
    list<int> people;
    // initialize the list with numbers from 0 to number - 1
    for (int i = 0; i < n; i++) {
        people.push_back(i);
    }
    auto current = people.begin();
    while (1 < people.size()) {
        // start counting
        for (int i = 1; i < number; i++) {
            current++;
            if (current == people.end()) {
                current = people.begin();
            }
        }
        // remove the current element from the list
        current = people.erase(current);
        if (current == people.end()) {
            current = people.begin();
        }
    }
    cout << "The survivor is: " << *current << endl;
}

class Student {
    int id;
    char gender;
    string address;
    string major;
public:
    Student(int i, char gen, string const& addr, string const& curriculum):
            id(i), gender(gen), address(addr), major(curriculum) {}
    
    int getId() const { return this->id; }
    char getGender() const { return this->gender; }
    string getAddress() const { return this->address; }
    string getMajor() const { return this->major; }
    
    void setId(int i) { this->id = i; }
    void setGender(char gen) { this->gender = gen; }
    void setAddress(string const& addr) { this->address = addr; }
    void setMajor(string const& curriculum) { this->major = curriculum; }
    
    string toString() const {
        return "<Student: ID: " + to_string(this->id) + ", Gender: " + this->gender + ", Address: "
        + this->address + ", Major: " + this->major + " >";
    }
};

bool compareStudent(const Student &stu1, const Student &stu2) {
    return stu1.getId() < stu2.getId();
}

void displayStudents(const Student &stu) {
    cout << stu.toString() << endl;
}

void studentTest() {
    vector<Student> students;
    int id = 0;
    char gender = 'M';
    string address;
    string curriculum;
    while (cin >> id >> gender >> address >> curriculum) {
        Student newStudent(id, gender, address, curriculum);
        students.push_back(newStudent);
    }
    for_each(students.begin(), students.end(), displayStudents);
    sort(students.begin(), students.end(), compareStudent);
    for_each(students.begin(), students.end(), displayStudents);
    cout << "Number of students in Computer Science: " <<
            count_if(students.begin(), students.end(),
                     [](Student const& stu) {return stu.getMajor() == "CS";})
         << endl;
}

int main() {
//    algorithmTest();
//    vectorTest();
//    mapTest();
//    iteratorTest();
    studentTest();
    return 0;
}
