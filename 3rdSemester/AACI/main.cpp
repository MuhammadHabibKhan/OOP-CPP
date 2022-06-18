#include <iostream>
#include "relation.h"
using namespace std;

int main() {
   Customer c1("q", "haha", "Q", "y", 303030, "nowhere");
   Order o1(101, "nonsense", false, "121212");
   c1.placeOrder(o1);
   Account acc;
   c1.check_balance(&acc);
   Adminstration admin1("admin", "OOP LEARNER", 100, 111244622, 8000, true, "fuel, mobile, house, car, khansama, free ticket");
   admin1.update_balance(&acc);
return 0;
}