#include <stdio.h>

#define llint long long int
#define MAX_LEN 10001LL

// Fills lps[] for given patttern pat[0..M−1]
void computeLPSArray (char *P, llint M, llint *lps) {
    // length of the previous longest prefix suffix
    llint len = 0, i;
    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M - 1
    i = 1;
    while ( i < M) {
        if (P[i] == P[len]) {
        len++;
        lps[i] = len;
        i++;
        } else { // (P[ i ] != P[ l e n ] )
            if (len != 0) {
                len = lps[len - 1];
            } else { // if (len == 0)
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of P in T
void KMPSearch (char *P, char *T) {
    // create lps [] that will hold the longest prefix suffix values for pattern
    llint M = strlen(P),
          N = strlen(T),
          lps[M],
          i, j;
    
    // Preprocess the pattern (calculate lps [] array)
    computeLPSArray(P, M, lps);

    i = 0; j = 0; // index for T and P
    while (i < N) {
        if (P[j] == T [i]) {
            j ++;
            i ++;
        }
        if (j == M) {
            // printf("Found pattern at index %d " , i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && P[j] != T [i]) {
            // Do not need to match lps[0 .. lps[j - 1]] characters
            if (j != 0) j = lps [j - 1];
            else i = i + 1;
        }
    }
}




int main() {
    char string[MAX_LEN];
    llint size = 0;

    scanf("%s", string);

    while (string[size] != '\0') size++;




    return 0;
}