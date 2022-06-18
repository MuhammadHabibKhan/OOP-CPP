#ifndef RELATION_H
#define RELATION_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class User {
    // user class acts as an abstract class
    string userID;
    string password;
    public:
    User(){};
    User(int x, int y);
    bool verify_login();
    void setID(string ID);
    string getID();
    void setPass(string pass);
    string getPass();
    ~User(){};
};

class Account; //forward declaration, cagglass Customer aggregates on Class Account

class OrderDetails{
    string product_name;
    string materials;
    int quantity;
    int unit_cost;
    string completion_time;
    public:
    OrderDetails(){};
    OrderDetails(int quan, int u_cost, string c_time, string materials);

    int getQuantity();
    void setQuantity(int quantity);
    void setUnitCost(int unitcost); 
    int getUnitCost();
    string getCompletionTime();
    void setCompletionTime(string t);

    int calcTotalCost();

    ~OrderDetails(){};
};

class Order{
    int orderID;
    string order_type;
    bool urgent;
    string dated;
    public:
    Order(){};
    Order(int ID, string type, bool urgency, string date);

    int getOrderID();
    void setOrderID(int id);
    string getOrderType();
    void setOrderType(string t);
    bool getUrgency();
    void setUrgency(bool u);
    string getDate();
    void setDate(string d);
    OrderDetails order;
    string displayOrderDetails(OrderDetails odr);

    ~Order(){};
};

// inheritance between User & Customer
class Customer : public User{
    string customer_name;
    string company_name;
    int company_number;
    string company_address;
    public:
    Customer(){};
    Customer(string id, string pass, string c_name, string name, int num, string c_address);

    string getCustomerName();
    void setCustomerName(string name);
    string getCompanyName();
    void setCompanyName(string c_name);
    string getCompanyAddress();
    void setCompanyAddress(string c_address);
    int getCompanyNumber();
    void setCompanyNumber(int num);

    Order od;
    void placeOrder(Order o);
    Account* ptr;
    int check_balance(Account* a); 
    map <int, int> show_history; // orderID and amount paid, entered by administration 

    ~Customer(){};
};

class Account{
    map<int, int> transaction_history;
    int balance;
    public:
    Account() {balance = 0;}
    ~Account(){};  
};

class Employee : public User{
    protected:
    string emp_name;
    int emp_phone;
    string emp_designation;
    int salary;
    int overtime_hours;
    int overtime_payhour;
    int leaves;
    float late_hours;
    string address;
    public:
    Employee(){};
    Employee(string name, string des, int sal, int num);

    string getEmpname();
    void setEmpName(string name);
    void setPhone(int num);
    int getPhone();
    int getSalary();
    int getOvertimeHours();
    int getOvertimePayHour();
    int getLeaves();
    float getLateHours();
    string getAddress();
    void setAddress(string addr);

    float calcSalary();
    void resign();

    ~Employee(){};
};

class Adminstration : public Employee{
    int access_code;
    string expenses_covered;
    bool medical;
    public:
    Adminstration(){};
    Adminstration(string name, string des, int sal, int num, int acc_code, bool med, string exp);
    
    // Admminstation class has association with all the following classes
    Customer* c;
    Account* acc;
    Employee* emp;

    void delete_customer(Customer* c);
    void update_balance(Account* a);  // association , admin manages accounts 
    void update_history(Customer* c, Account* a);
    void change_completion_time(Customer* c, OrderDetails* od);
    void fire_employee(Employee* e);

    void setSalary(int sal);
    void setOvertime(int hours);
    void setOvertimeRate(int p);
    void setLeaves(int num);
    void setLateHours(int hours);

    ~Adminstration(){};
};

#endif