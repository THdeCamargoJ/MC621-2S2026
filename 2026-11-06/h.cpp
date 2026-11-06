#include <iostream>

#define llint long long int
#define LEFT "LEFT"
#define RIGHT "RIGHT"
#define TOWARDS "TOWARDS"




using namespace std;

typedef struct {
    llint x;
    llint y;
} Point;

void solveFor(Point A, Point B, Point C) {
    Point AB, CB;

    AB.x = A.x - B.x;
    AB.y = A.y - B.y;

    CB.x = C.x - B.x;
    CB.y = C.y - B.y;

    // 2D cross product
    long long cross_prod = AB.x * CB.y - AB.y * CB.x;

    if (cross_prod == 0) {
        cout << TOWARDS << endl;
    } else if (cross_prod > 0) {
        cout << RIGHT << endl;
    } else {
        cout << LEFT << endl;
    }
}

int main() {
    Point A, B, C;

    cin >> A.x;
    cin >> A.y;

    cin >> B.x;
    cin >> B.y;

    cin >> C.x;
    cin >> C.y;

    solveFor(A, B, C);

    return 0;
}