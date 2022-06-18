#include <iostream>
#include <vector>
using namespace std;

class Student{
    public:
    int count;
    string course;
    string* courses;
    vector <string> course_list;

    // default constructor
    Student(){};
    
    // destructor
    ~Student(){ 
        // destructor has no delete[] operator as new keyword was not used and vector was
        // not created on heap
        cout << "\nDestructor is executed" << endl; 
    }

    // parametrized constructor with initial courses input
    Student(int n){
        if ( n <= 6){
        for (int i = 0; i < n; i++){
            cout << "Enter Course Name: " << endl;
            getline (cin, course);
            courses = &course;
            course_list.push_back(*courses);
        }
        }
        else {
            cout << "Only 6 courses allowed per semester" << endl;
        }

    }
    
    // copy constructor
    Student(const Student& s){
        cout << "Copy Constructor Invoked" << endl;
        this->count = s.count;
        int len = s.course_list.size();
        // copies all present courses 
        for (int j = 0; j < len; j++){
            //vector <string> temp;
            course_list.push_back(s.course_list[j]);
        };
        
    }
   
   // addCourse method
    void addCourse(string name){
        if (course_list.size() < 6 ){
        cout << "course added" << endl;
        this->course_list.push_back(name);
        }
        else {
            cout << "full" << endl;
        }   
    }

   // setCourse method
   void setCourse(int x, string name){
       cout << "Course changed at position " << x << endl;
       course_list[x-1] = name;
   }

   // getCourse method
   string getCourse(int p){
       p = p - 1;
       if (p < 6){
           return course_list[p];
       }
       else {
           return "Only 6 courses per semester allowed\n";
       }

   }

   // << operator overloading
   friend ostream& operator << (ostream& out, const Student& s){
       for (int i = 0; i < s.course_list.size(); i++){
           out << s.course_list[i] << " | ";
       }
       out << "\n";
    }

  // = operator overloading (same functionality as copy constructor)
  void operator = (const Student &s ) { 
        cout << "Assignment Operator To Copy Invoked" << endl;
        this->count = s.count;
        int len = s.course_list.size();
        // copies all present courses 
        for (int j = 0; j < len; j++){
            vector <string> temp;
            course_list.push_back(s.course_list[j]);  
      }
}
};

int main(){
    Student Salman(3); // 3 denotes how many input subjects you want from user.
    Student Akbar (Salman);
    Salman.addCourse("DLD");
    Salman.addCourse("ASSEMBLY");
    Salman.addCourse("LINEAR");
    Salman.addCourse("OOP");
    Salman.setCourse(4, "Digital Logic Designs"); // course changed
    cout << Salman.getCourse(4) << endl; // index is plus 1 for easy human understanding
    cout << Salman.getCourse(7) << endl; 
    cout << Akbar;
    cout << Salman;
    //cout << Salman.course_list[0] << endl;
    Salman.~Student(); // destructor explicitly called but as the output shows 
    Akbar.~Student();  // compiler calls it automatically too
    Student Sharukh;
    Sharukh = Akbar; // Akbar's courses copied to Sharukh
    cout << Sharukh;

    return 0;
}