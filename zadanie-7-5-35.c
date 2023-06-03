#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int printlist(int *n, int len){
    for (int i = 0; i < len; i++){
        printf("%d ", n[i]);
    }
    
}
int LongestIncreasingSubsequence(int *p, int n) {
    int tail[n];
    int prev[n];
    tail[0] = 0;
    prev[0] = -1;
    for (int i = 1; i < n; i++) {
        tail[i] = -1;
        prev[i] = -1;
    }
    printlist(tail,n);
    printf("\n");
    printlist(prev,n);
}

int main() {
    int p[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int n = sizeof(p) / sizeof(p[0]);
    int d = LongestIncreasingSubsequence(p, n);
}