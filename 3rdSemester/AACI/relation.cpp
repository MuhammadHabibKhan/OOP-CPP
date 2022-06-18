#include <iostream>
#include "relation.h"
#include <typeinfo>

using namespace std;

// user class method declaration

User::User(int x, int y){
    this->userID = userID;
    this->password = password;
}

bool User::verify_login(){
    string i = typeid(this->userID).name();
    string s = typeid(this->password).name();
    if ( i == "s" & s == "s"){
        cout << "login verified";
    }
    else {
        cout << "wrong datatype";
    }    
}

void User::setID(string ID){
    this->userID = ID;
}

string User::getID(){
    return userID;
}

void User::setPass(string pass){
    this->password = pass;
}

string User::getPass(){
    return password;
}

// OrderDetails class methods declaration 

OrderDetails::OrderDetails(int quan, int u_cost, string c_time, string materials){
    this->quantity = quan;
    this->unit_cost = u_cost;
    this->materials = materials;
    this->completion_time = c_time;
}

void OrderDetails::setQuantity(int quantity){
    this->quantity = quantity;
}

int OrderDetails::getQuantity(){
    return quantity;
}

int OrderDetails::getUnitCost(){
    return unit_cost;
}

void OrderDetails::setUnitCost(int unitcost){
    this->unit_cost = unitcost;
}

void OrderDetails::setCompletionTime(string t){
    this->completion_time = t;
}

string OrderDetails::getCompletionTime(){
    return completion_time;
}

int calcTotalCost(){
    cout << "Function not defined due to no time. Apologies in advance" << endl;
}

// Order Class Methods Declaration

Order::Order(int ID, string type, bool urgency, string date){
    this->orderID = ID;
    this->order_type = type;
    this->urgent = urgency;
    this->dated = date;
}

void Order::setOrderID(int id){
    this->orderID = id;
}

int Order::getOrderID(){
    return orderID;
}

void Order::setOrderType(string t){
    this->order_type = t;
}

string Order::getOrderType(){
    return order_type;
}

bool Order::getUrgency(){
    return urgent;
}

void Order::setUrgency(bool u){
    this->urgent = u;
}

void Order::setDate(string d){
    this->dated = d;
}

string Order::getDate(){
    return dated;
}

//OrderDetails order;

string Order::displayOrderDetails(OrderDetails odr){
    this->order = odr;
    cout << "COMPOSITION JUST HAPPENED FOLKS!" << endl;
}

// Customer Class

Customer::Customer(string id, string pass, string c_name, string name, int num, string c_address)
{
    this->customer_name = c_name;
    this->customer_name = name;
    this->company_number = num;
    this->company_address = c_address;
    ptr = NULL;
}

string Customer::getCustomerName()
{
    return customer_name;
}

void Customer::setCustomerName(string name)
{
    this->customer_name = name;
}

string Customer::getCompanyName()
{
    return company_name;
}

void Customer::setCompanyName(string c_name)
{
    this->company_name = c_name;
}

string Customer::getCompanyAddress()
{
    return company_address;
}

void Customer::setCompanyAddress(string c_address)
{
    this->company_address = c_address;
}

int Customer::getCompanyNumber()
{
    return company_number;
}

void Customer::setCompanyNumber(int num)
{
    this->company_number = num;
}

void Customer::placeOrder(Order o){
    this->od = o;
    cout << "COMPOSITION" << endl;
}

int Customer::check_balance(Account* a){
    this->ptr = a;
    cout << "AGGREGATION!!!" << endl;
    
}   

// Employee

Employee::Employee(string name, string des, int sal, int num)
{
    this->emp_name = name;
    this->emp_designation = des;
    this->salary = sal;
    this->emp_phone = num;
}

void Employee::setEmpName(string name)
{
    this->emp_name = name;
}

void Employee::setPhone(int num)
{
    this->emp_phone = num;
}

int Employee::getPhone()
{
    return emp_phone;
}

int Employee::getSalary()
{
    return salary;
}

int Employee::getOvertimeHours()
{
    return overtime_hours;
}

int Employee::getOvertimePayHour()
{
    return overtime_payhour;
}

int Employee::getLeaves()
{
    return leaves;
}

float Employee::getLateHours()
{
    return late_hours;
}

string Employee::getAddress()
{
    return address;
}

void Employee::setAddress(string addr)
{
    this->address = addr;
}

float Employee::calcSalary(){
    cout << "UNDER CONSTRUCTION, COMEBACK LATER" << endl;
    // salary to be calculated using formula based on 
    // late hours, leaves, overtime, salary attributes
}

void Employee::resign(){
    this->~Employee();
}

// Administration

Adminstration::Adminstration(string name, string des, int sal, int num, int acc_code, bool med, string exp)
{
    this->access_code = acc_code;
    this->expenses_covered = exp;
    this->medical = med;
    this->emp_name = name;
    this->emp_designation = des;
    this->salary = sal;
    this->emp_phone = num;
}

void Adminstration::setSalary(int sal)
{
    this->salary = sal;
}

void Adminstration::setOvertime(int hours)
{
    this->overtime_hours = hours;
}

void Adminstration::setOvertimeRate(int p)
{
    this->overtime_payhour = p;
}

void Adminstration::setLeaves(int num)
{
    this->leaves = num;
}

void Adminstration::setLateHours(int hours)
{
    this->late_hours = hours;
}

// void Adminstration::fire_employee(Employee* e){
//     e->~Employee();
//     cout << "GONE, REDUCED TO ATOMS" << endl;
// }

void Adminstration::update_balance(Account* a){
    this->acc = a;
    cout << "association" << endl;
}



