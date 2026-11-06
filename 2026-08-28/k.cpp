#include <iostream>

#define MODULO 1000000007LL
#define llint long long int

using namespace std;

void printAnswer(llint answer) {
    cout << (answer % MODULO + MODULO) % MODULO << endl;
}

llint modPow(llint x, llint y) {
    // base cases
    if (y == 0) return 1;
    if (x == 0) return 0;

    // y is even
    long v;
    if (y % 2 == 0) {
        v = modPow(x, y/2);
        v = (v * v) % MODULO;
    }

    // y is odd
    else {
        v = x % MODULO;
        v = (v * modPow(x, y-1)) % MODULO;
    }

    return (llint) ((v + MODULO) % MODULO);
}

void solveFor(llint N) {
    llint valid_seqs_set,
          inval_seqs_set,
          total_seqs_set;
    
    total_seqs_set = modPow(10, N);
    inval_seqs_set = 2 * modPow(9, N) - modPow(8, N);
    valid_seqs_set = total_seqs_set - inval_seqs_set;
    printAnswer(valid_seqs_set);
}

int main() {
    llint N;

    cin >> N;

    solveFor(N);
}