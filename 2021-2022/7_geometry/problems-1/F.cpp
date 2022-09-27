#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define EPS 0.000000001
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

LD degrees(LD radians) {
    return radians / M_PI * 180;
}

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

bool operator == (const Vector & a, const Vector & b) {
    return a.x == b.x && a.y == b.y;
}
Vector operator + (const Vector & a, const Vector & b) {
    return Vector(a.x + b.x, a.y + b.y);
}
Point operator + (const Point & a, const Vector & b) {
    return Point(a.x + b.x, a.y + b.y);
}
Vector operator - (const Vector & a, const Vector & b) {
    return Vector(a.x - b.x, a.y - b.y);
}
Vector operator * (Vector & a, double k) {
    return Vector(a.x * k, a.y * k);
}
Vector operator * (double k, Vector & a) {
    return Vector(a.x * k, a.y * k);
}
Vector operator / (const Vector & a, double k) {
    return Vector(a.x / k, a.y / k);
}
Vector operator / (double k, const Vector & a) {
    return Vector(a.x / k, a.y / k);
}

LD dot_product(Vector &a, Vector &b) { // scalar product
    return a.x * b.x + a.y * b.y;
}

LD cross_product(Vector &a, Vector &b) { // cross product
    return a.x * b.y - a.y * b.x;
}

LD triangle_area(Point A, Point B, Point C) { // area of triangle ABC
    Vector AB(A, B);
    Vector AC(A, C);
    return abs(cross_product(AB, AC)) / 2;
}

LD dist_to_line(Point P, Point A, Point B) { // dist from point P to straight line AB
    if (A == B) return -1;
    Vector AB(A, B);
    Vector AP(A, P);
    return abs(cross_product(AB, AP)) / AB.length();
}

LD dist_to_ray(Point P, Point A, Point B) { // dist from point P to ray AB
    if (A == B) return -1;
    Vector AB(A, B);
    Vector AP(A, P);
    if (dot_product(AB, AP) < 0) return AP.length();
    return abs(cross_product(AB, AP)) / AB.length();
}

LD dist_to_segment(Point P, Point A, Point B) { // dist from point P to segment AB
    Vector AB(A, B);
    Vector AP(A, P);
    Vector BA(B, A);
    Vector BP(B, P);
    LD scal1 = dot_product(AB, AP);
    LD scal2 = dot_product(BA, BP);
    if (scal1 > 0 && scal2 > 0) return abs(cross_product(AB, AP)) / AB.length();
    else return min(AP.length(), BP.length());
}

LD angle(Vector a, Vector b) { // angle between the vectors
    return atan2(cross_product(a, b), dot_product(a, b));
}



int main() {

    Point p, a, b;
    cin >> p >> a >> b;
    if (abs(dist_to_segment(p, a, b)) > EPS) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
