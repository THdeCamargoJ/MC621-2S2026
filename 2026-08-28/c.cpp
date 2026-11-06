/* C - Rudolf and the Another Competition
 * https://codeforces.com/problemset/problem/1846/C
 */

#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

#define llint long long int

using namespace std;

void solveFor(vector<vector<llint>> time_per_problem_per_participant, llint duration) {
    llint rudolf_points = -1, rudolf_penalty,
          participant_points, participant_penalty,
          curr_time,
          best_count = 0;

    for(auto& tpb: time_per_problem_per_participant) {
        sort(tpb.begin(), tpb.end());

        curr_time = 0;
        participant_points = 0;
        participant_penalty = 0;
        for (llint problem_time: tpb) {
            if (curr_time + problem_time <= duration) {
                curr_time += problem_time;
                participant_penalty += curr_time;
                participant_points++;
            } else break;
        }
        
        if (rudolf_points == -1) {
            rudolf_points = participant_points;
            rudolf_penalty = participant_penalty;
        } else if (rudolf_points < participant_points
            || (rudolf_points == participant_points && rudolf_penalty > participant_penalty)
        ) {
            best_count++;
        }
    }

    cout << best_count + 1 << endl;
}

int main() {
    int n_tests;
    llint n_participants, n_problems, duration, time_to_solve;
    vector<vector<llint>> time_per_problem_per_participant;
    vector<llint> time_per_problem;

    cin >> n_tests;

    for (int _: views::iota(0,n_tests)) {
        time_per_problem_per_participant.clear();
        cin >> n_participants >> n_problems >> duration;
        
        for (llint _: views::iota(0,n_participants)) {
            time_per_problem.clear();
            for (llint _: views::iota(0,n_problems)) {
                cin >> time_to_solve;
                time_per_problem.push_back(time_to_solve);
            }
            time_per_problem_per_participant.push_back(time_per_problem);
        }

        solveFor(time_per_problem_per_participant, duration);
    }

    return 0;
}