#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define base 256
#define prime 101
#define MAX_CHARS 256

// 1. Naive Method
void naiveSearch(char *text, char *pattern){
    int n = strlen(text), m = strlen(pattern);
    printf("Naive Search:\n");
    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++)
            if(text[i + j] != pattern[j])
                break;
        if(j == m)
            printf("Pattern found at index %d\n", i);
    }
}


int Hash(int hi, int x, int y){
    return (hi - x + y + prime) % prime;
}

// 2. Rabin-Karp Method
void rabinKarpSearch(char *text, char *pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    int hp = 0, ht = 0;
    printf("Rabin-Karp Search:\n");

    // Initial hash
    for(int i = 0; i < m; i++){
        hp += pattern[i];
        ht += text[i];
    }
    hp %= prime;
    ht %= prime;

    for(int i = 0; i <= n - m; i++){
        if(ht == hp){
            int match = 1;
            for(int j = 0; j < m; j++){
                if(text[i + j] != pattern[j]){
                    match = 0;
                    break;
                }
            }
            if(match) printf("Pattern found at index %d\n", i);
        }
        //next hash
        if(i<n - m) ht = Hash(ht, text[i], text[i + m]);
    }
}


// 3. Finite Automaton Method
int getNextState(char *pattern, int m, int state, int x){
    if(state < m && x == pattern[state]) return state + 1;

    for(int ns = state; ns > 0; ns--){
        if(pattern[ns - 1] == x){
            int i;
            for(i = 0; i < ns - 1; i++)
                if(pattern[i] != pattern[state - ns + 1 + i])
                    break;
            if(i == ns - 1)
                return ns;
        }
    }
    return 0;
}

void computeTF(char *pattern, int m, int TF[][MAX_CHARS]){
    for(int state = 0; state <= m; ++state)
        for(int x = 0; x < MAX_CHARS; ++x)
            TF[state][x] = getNextState(pattern, m, state, x);
}

void finiteAutomatonSearch(char *text, char *pattern){
    int m = strlen(pattern);
    int n = strlen(text);
    int TF[100][MAX_CHARS];

    printf("Finite Automaton Search:\n");

    computeTF(pattern, m, TF);

    int state = 0;
    for(int i = 0; i < n; i++){
        state = TF[state][text[i]];
        if(state == m)
            printf("Pattern found at index %d\n", i - m + 1);
    }
}


void computeLPSArray(char *pattern, int m, int lps[]) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


void KMPSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];

    computeLPSArray(pattern, m, lps);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            printf("KMP - Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}


int main() {
    char *texts[] = { "GCATCGCAGAGAGTATACAGTACG", "HACKHACKHACKHACKITHACKEREARTH", "0112011120222010112101112110" };
    char *patterns[] = { "GCAGAGAG", "HACKHACKIT", "011121"};
    int n = sizeof(texts) / sizeof(texts[0]);
    for (int i = 0; i < n; i++) {
        printf("==== Test Case %d ====\n", i + 1);
        printf("Text: %s\n", texts[i]);
        printf("Pattern: %s\n\n", patterns[i]);

        naiveSearch(texts[i], patterns[i]);
        printf("\n");

        rabinKarpSearch(texts[i], patterns[i]);
        printf("\n");

        finiteAutomatonSearch(texts[i], patterns[i]);
        printf("\n");

        KMPSearch(texts[i], patterns[i]);
        printf("\n-----------------------\n\n");
    }

    return 0;
}
