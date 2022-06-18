#include <iostream>
#include <vector>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point(const Point& pto) {
        this->x = pto.x;
        this->y = pto.y;
    }
    
    friend ostream& operator << (ostream& out, Point& p) {
        out << p.x << p.y << endl;
        return out;
    }
};

class ParametricCurve : public Point{

private:
    int minT;
	int maxT;
public:
    vector<int> t;

    ParametricCurve() {
		minT = 0;
		maxT = 1;
	}

	ParametricCurve(int min, int max) {
		minT = min;
		maxT = max;
	}

    void range(int min, int max, ParametricCurve obj) {
        for (min; min < max; min++) {
            obj.t.push_back(min);
            //cout << t.at(min) << endl;
        }
    }

	void computePoints(int a, int b, ParametricCurve obj) {
        obj.range(a, b, obj);
        for (int i = 0; i < obj.t.size() - 2; i++) {
            //cout << obj.t[i] << " ";
            Point p;
            p.x = t.at(i);
            p.y = t.at(i);
            cout << p << endl;           
        }
	}
};
int main() {
    ParametricCurve temp;
    temp.computePoints(1, 10, temp);
    
    return 0;
}