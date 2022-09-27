#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define EPS 0.000000001
#define PB push_back
#define PF push_front
#define ff first
#define ss second

struct Point {
    LD x, y;
    Point(LD a = 0, LD b = 0);
    LD dist();
    LD dist2();
    LD dist_to_line(Point A, Point B);
    LD dist_to_ray(Point A, Point B);
    LD dist_to_segment(Point A, Point B);
    int point_side(LD a, LD b, LD c);
};



struct Vector {
    LD x, y;
    Vector(LD a = 0, LD b = 0);
    Vector(const Point & A = 0, const Point & B = 0);
    LD length();
    LD angle();
};
LD degrees(LD radians);
istream & operator >> (istream & in, Point & P);
ostream & operator << (ostream & out, const Point & P);
istream & operator >> (istream & in, Vector & V);
ostream & operator << (ostream & out, const Vector & V);
bool operator == (const Vector & a, const Vector & b);
Vector operator + (const Vector & a, const Vector & b);
Point operator + (const Point & a, const Vector & b);
Vector operator - (const Vector & a, const Vector & b);
Vector operator * (Vector & a, double k);
Vector operator * (double k, Vector & a);
Vector operator / (const Vector & a, double k);
Vector operator / (double k, const Vector & a);
LD dot_product(const Vector &a, const Vector &b);
LD cross_product(const Vector &a, const Vector &b);
LD triangle_area(Point A, Point B, Point C);
LD angle(const Vector &a, const Vector &b);
pair<Point, Point> points_on_line_eq(LD a, LD b, LD c);

Point::Point(LD a, LD b) {
    x = a;
    y = b;
}
LD Point::dist() {
    return sqrt(x * x + y * y);
}
LD Point::dist2() {
    return x * x + y * y;
}
LD Point::dist_to_line(Point A, Point B) { // dist from point P to straight line AB
    if (A == B) return -1;
    Vector AB(A, B);
    Vector AP(A, *this);
    return abs(cross_product(AB, AP)) / AB.length();
}
LD Point::dist_to_ray(Point A, Point B) { // dist from point P to ray AB
    if (A == B) return -1;
    Vector AB(A, B);
    Vector AP(A, *this);
    if (dot_product(AB, AP) < 0) return AP.length();
    return abs(cross_product(AB, AP)) / AB.length();
}
LD Point::dist_to_segment(Point A, Point B) { // dist from point to segment AB
    Vector AB(A, B);
    Vector AP(A, *this);
    Vector BA(B, A);
    Vector BP(B, *this);
    LD scal1 = dot_product(AB, AP);
    LD scal2 = dot_product(BA, BP);
    if (scal1 > 0 && scal2 > 0) return abs(cross_product(AB, AP)) / AB.length();
    else return min(AP.length(), BP.length());
}
int Point::point_side(LD a, LD b, LD c) {
    LD tmp = a * this->x + b * this->y + c;
    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    return -1;
}


Vector::Vector(LD a, LD b) {
    x = a;
    y = b;
}
Vector::Vector(const Point & A, const Point & B) {
    x = B.x - A.x;
    y = B.y - A.y;
}
LD Vector::length() {
    return sqrt(x * x + y * y);
}
LD Vector::angle() { // угол вектора в полярных координатах
    return atan2(y, x);
}



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
Vector operator - (const Vector & a) {
    return Vector(-a.x, -a.y);
}

LD dot_product(const Vector &a, const Vector &b) { // scalar product
    return a.x * b.x + a.y * b.y;
}

LD cross_product(const Vector &a, const Vector &b) { // cross product
    return a.x * b.y - a.y * b.x;
}

LD triangle_area(Point A, Point B, Point C) { // area of triangle ABC
    Vector AB(A, B);
    Vector AC(A, C);
    return abs(cross_product(AB, AC)) / 2;
}



LD angle(const Vector &a, const Vector &b) { // angle between the vectors
    return atan2(cross_product(a, b), dot_product(a, b));
}

pair<Point, Point> points_on_line_eq(LD a, LD b, LD c) {
    Point A(-a * c / (a*a + b*b), -b * c / (a*a + b*b));
    Point B(-b + A.x, a + A.y);
    return {A, B};
}

bool segments_cross(Point A, Point B, Point C, Point D) {
    Vector AB(A, B), CB(C, B), CA(C, A), CD(C, D), AD(A, D);
    LD cross1 = cross_product(AB, -CA);
    LD cross2 = cross_product(AB, AD);
    LD cross3 = cross_product(CD, CA);
    LD cross4 = cross_product(CD, CB);
    LD cross_f = cross1 * cross2;
    LD cross_s = cross3 * cross4;
    if (cross_f <= EPS && cross_s <= EPS)
        if (abs(cross1) > EPS || abs(cross2) > EPS ||
            abs(cross3) > EPS || abs(cross4) > EPS) return true;
    LD dst1 = A.dist_to_segment(C, D);
    LD dst2 = B.dist_to_segment(C, D);
    LD dst3 = C.dist_to_segment(A, B);
    LD dst4 = D.dist_to_segment(A, B);
    if (dst1 == 0 || dst2 == 0 || dst3 == 0 || dst4 == 0) return true;
    return false;
}

int main() {

    cout.precision(20);
    Point A, B, C, D;
    cin >> A >> B >> C >> D;
    if (segments_cross(A, B, C, D)) cout << "YES\n";
    else cout << "NO\n";


    return 0;
}
