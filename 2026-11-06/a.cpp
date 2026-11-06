#include <iostream>
#include <ranges>
#include <vector>

#define llint long long int



using namespace std;

typedef struct {
    llint x;
    llint y;
} Block;

typedef struct {
    llint a;
    llint b;
    llint c;
} Road;


bool oppositeSides(Block A, Block B, Road R) {
    llint A_f_xy = R.a * A.x + R.b * A.y + R.c,
          B_f_xy = R.a * B.x + R.b * B.y + R.c;
    
    return (A_f_xy < 0 && B_f_xy > 0)
        || (A_f_xy > 0 && B_f_xy < 0);
}

void solveFor(Block home, Block university, vector<Road>& roads) {
    llint steps = 0;

    for (auto road: roads) {
        if (oppositeSides(home, university, road)) steps++;
    }

    cout << steps << endl;
}

int main() {
    Block home, university;
    Road road;
    vector<Road> roads;
    int n_roads;

    cin >> home.x;
    cin >> home.y;

    cin >> university.x;
    cin >> university.y;

    cin >> n_roads;

    for (int _: views::iota(0, n_roads)) {
        cin >> road.a;
        cin >> road.b;
        cin >> road.c;
        roads.push_back(road);
    }

    solveFor(home, university, roads);

    return 0;
}