//
// Created by Ignorant on 2024/5/9.
//

#include <iostream>
using namespace std;

/*
 * 聚合关系：
 *  > 在聚合关系中，被包含的对象与包含它的对象独立创建和消亡，被包含的对象可以脱离包含它的对象独立存在
 *  > 实现上，聚合类的成员对象一般是采用对象指针表示，用于指向被包含的成员对象，而被包含的成员对象是在外部创建，然后加入到聚合
 *          类对象中来的。
 */

class Employee {
    string name;
    int salary;
public:
    Employee() = default;
    Employee(const string& name, int salary): name(name), salary(salary) {}
    
    string getName() const {
        return name;
    }
    
    void setName(const string& name) {
        this->name = name;
    }
    
    int getSalary() const {
        return salary;
    }
    
    void setSalary(int salary) {
        this->salary = salary;
    }
};

const int MAX_NUM_OF_EMPLOYEES = 1000;

class Company {
    string name;
    Employee* employees[MAX_NUM_OF_EMPLOYEES];
    int numOfEmployees;
public:
    Company() = default;
    Company(const string& name): name(name){
        numOfEmployees = 0;
    }
    
    ~Company() {
        numOfEmployees = 0;
    }
    
    int addEmployee(Employee* employee) {
        if (numOfEmployees < MAX_NUM_OF_EMPLOYEES) {
            employees[numOfEmployees++] = employee;
            return 0;
        }
        return -1;
    }
    
    int removeEmployee(int index) {
        if (index < numOfEmployees) {
            for (int i = index; i < numOfEmployees - 1; i++) {
                employees[i] = employees[i + 1];
            }
            numOfEmployees--;
            return 0;
        }
        return -1;
    }
    
    string getName() const {
        return name;
    }
    
    void setName(const string& name) {
        this->name = name;
    }
    
    int getNumOfEmployees() const {
        return numOfEmployees;
    }
    
    Employee* getEmployee(int index) const {
        if (index < numOfEmployees) {
            return employees[index];
        }
        return nullptr;
    }
    
    int setEmployee(int index, Employee* employee) {
        if (index < numOfEmployees) {
            employees[index] = employee;
            return 0;
        }
        return -1;
    }
};

int main() {
    Company company1("ABC Corp.");
    Employee employee1("John", 50000);
    Employee employee2("Mary", 60000);
    Employee employee3("Tom", 70000);
    
    company1.addEmployee(&employee1);
    company1.addEmployee(&employee2);
    company1.addEmployee(&employee3);
    
    cout << "Company name: " << company1.getName() << endl;
    cout << "Number of employees: " << company1.getNumOfEmployees() << endl;
    
    Employee* employee = company1.getEmployee(1);
    if (employee) {
        cout << "Employee name: " << employee->getName() << endl;
        cout << "Employee salary: " << employee->getSalary() << endl;
    }
    
    company1.removeEmployee(1);
    cout << "Number of employees: " << company1.getNumOfEmployees() << endl;
    
    employee = company1.getEmployee(1);
    if (employee) {
        cout << "Employee name: " << employee->getName() << endl;
        cout << "Employee salary: " << employee->getSalary() << endl;
    }
    
    employee = new Employee("Jane", 80000);
    company1.addEmployee(employee);
    cout << "Number of employees: " << company1.getNumOfEmployees() << endl;
    
    employee = company1.getEmployee(3);
    if (employee) {
        cout << "Employee name: " << employee->getName() << endl;
        cout << "Employee salary: " << employee->getSalary() << endl;
    }
    
    delete employee;
    return 0;
}
