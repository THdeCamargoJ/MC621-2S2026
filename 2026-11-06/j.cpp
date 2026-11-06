#include <iostream>

#define RIGHT "RIGHT"
#define ALMOST "ALMOST"
#define NEITHER "NEITHER"

typedef struct {
    int x;
    int y;
} Block;

using namespace std;

bool rightTriangle(Block A, Block B, Block C) {
    long long int ABx, ABy,  ACx, ACy,  BCx, BCy,
                  ABsquared, ACsquared, BCsquared;

    ABx = A.x - B.x;
    ACx = A.x - C.x;
    BCx = B.x - C.x;
    
    ABy = A.y - B.y;
    ACy = A.y - C.y;
    BCy = B.y - C.y;

    ABsquared = ABx * ABx + ABy * ABy;
    ACsquared = ACx * ACx + ACy * ACy;
    BCsquared = BCx * BCx + BCy * BCy;

    if (ABsquared && ACsquared && BCsquared) {
        return (ABsquared + ACsquared == BCsquared)
            || (ABsquared + BCsquared == ACsquared)
            || (ACsquared + BCsquared == ABsquared);
    }
    return false;
}

int main() {
    Block A, B, C, P;

    cin >> A.x;
    cin >> A.y;
    cin >> B.x;
    cin >> B.y;
    cin >> C.x;
    cin >> C.y;

    if (rightTriangle(A, B, C)) {
        cout << RIGHT << endl;
        return 0;
    }

    // replace A
    P = A;
    
    P.x += 1;
    if (rightTriangle(P, B, C)) {
        cout << ALMOST << endl;
        return 0;
    }
    
    P.x -= 2;
    if (rightTriangle(P, B, C)) {
        cout << ALMOST << endl;
        return 0;
    }
    P.x += 1;
    
    P.y += 1;
    if (rightTriangle(P, B, C)) {
        cout << ALMOST << endl;
        return 0;
    }

    P.y -= 2;
    if (rightTriangle(P, B, C)) {
        cout << ALMOST << endl;
        return 0;
    }

    // replace B
    P = B;
    
    P.x += 1;
    if (rightTriangle(A, P, C)) {
        cout << ALMOST << endl;
        return 0;
    }
    
    P.x -= 2;
    if (rightTriangle(A, P, C)) {
        cout << ALMOST << endl;
        return 0;
    }
    P.x += 1;
    
    P.y += 1;
    if (rightTriangle(A, P, C)) {
        cout << ALMOST << endl;
        return 0;
    }

    P.y -= 2;
    if (rightTriangle(A, P, C)) {
        cout << ALMOST << endl;
        return 0;
    }

    // replace C
    P = C;
    
    P.x += 1;
    if (rightTriangle(A, B, P)) {
        cout << ALMOST << endl;
        return 0;
    }
    
    P.x -= 2;
    if (rightTriangle(A, B, P)) {
        cout << ALMOST << endl;
        return 0;
    }

    P.x += 1;
    
    P.y += 1;
    if (rightTriangle(A, B, P)) {
        cout << ALMOST << endl;
        return 0;
    }

    P.y -= 2;
    if (rightTriangle(A, B, P)) {
        cout << ALMOST << endl;
        return 0;
    }

    cout << NEITHER << endl;

    return 0;
}