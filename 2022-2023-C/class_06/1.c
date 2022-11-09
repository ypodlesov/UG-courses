#include <stdio.h>
#include <stdlib.h>

struct Point
{
    double x;
    double y;
};

int 
cmp(const void *a, const void *b)
{
    struct Point p1 = *(struct Point *) a;
    struct Point p2 = *(struct Point *) b;
    double r1 = p1.x * p1.x + p1.y * p1.y;
    double r2 = p2.x * p2.x + p2.y * p2.y;
    if (r1 > r2) {
        return 1;
    } else if (r1 == r2) {
        return 0;
    }
    return -1;
}

int
main() 
{
    struct Point points[5];
    for (int i = 0; i < 5; ++i) {
        scanf("%lf%lf", &points[i].x, &points[i].y);
    }
    qsort(points, 5, sizeof(*points), cmp); 
    for (int i = 0; i < 5; ++i) {
        printf("%lf %lf\n", points[i].x, points[i].y);
    }


    return 0;
}
