#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define FF first
#define SS second

struct Point {
    LD x, y;
    Point(LD a = 0, LD b = 0) {
        x = a;
        y = b;
    }
    LD dist() {
        return sqrt(x * x + y * y);
    }
    LD dist2() {
        return x * x + y * y;
    }
};

struct Vector {
    LD x, y;
    Vector(LD a = 0, LD b = 0) {
        x = a;
        y = b;
    }
    Vector(const Point & A = 0, const Point & B = 0) {
        x = B.x - A.x;
        y = B.y - A.y;
    }
    LD length() {
        return sqrt(x * x + y * y);
    }
    LD angle() { // угол вектора в полярных координатах
        return atan2(y, x);
    }
};

istream & operator >> (istream & in, Point & P) {
    in >> P.x >> P.y;
    return in;
}

ostream & operator << (ostream & out, const Point & P) {
    out << P.x << ' ' << P.y;
    return out;
}

istream & operator >> (istream & in, Vector & V) {
    in >> V.x >> V.y;
    return in;
}

ostream & operator << (ostream & out, const Vector & V) {
    out << V.x << ' ' << V.y;
    return out;
}

LD dot_product(Vector &a, Vector &b) { // scalar product
    return a.x * b.x + a.y * b.y;
}

LD cross_product(Vector &a, Vector &b) { // cross product
    return a.x * b.y - a.y * b.x;
}

LD angle(Vector a, Vector b) { // angle between the vectors
    return abs(atan2(cross_product(a, b), dot_product(a, b)));
}

int main() {

    Vector a(0, 0), b(0, 0);
    cin >> a >> b;
    cout.precision(20);
    cout << angle(a, b) << endl;

    return 0;
}
