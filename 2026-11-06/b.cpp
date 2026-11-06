#include <iostream>
#include <ranges>
#include <vector>

#define llint long long int
#define MAX_LINES 100000



using namespace std;

void solveFor(vector<llint>& p, vector<llint>& q) {
    llint p_evens = 0, q_evens = 0, p_odds = 0, q_odds = 0;

    for (auto p_i: p) {
        if (p_i % 2 == 0) p_evens++;
        else p_odds++;
    }
    
    for (auto q_i: q) {
        if (q_i % 2 == 0) q_evens++;
        else q_odds++;
    }

    cout << p_evens * q_evens + p_odds * q_odds << endl;
}

int main() {
    int n_tests;
    vector<llint> p, q;
    llint linear_coef, n_lines, m_lines;

    cin >> n_tests;

    for (int t: views::iota(0, n_tests)) {
        cin >> n_lines;
        for (int i: views::iota(0, n_lines)) {
            cin >> linear_coef;
            p.push_back(linear_coef);
        }
        
        cin >> m_lines;
        for (int i: views::iota(0, m_lines)) {
            cin >> linear_coef;
            q.push_back(linear_coef);
        }

        solveFor(p, q);
        p.clear();
        q.clear();
    }

    return 0;
}