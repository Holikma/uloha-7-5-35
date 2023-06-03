#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(float p[], int T[], int l, int r, float key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (p[T[m]] >= key) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return r;
}

void printlist(int *l, int len){
    for (int i = 0; i < len; i++){
        printf("%.0f ", l[i]);
    }   
    printf("\n");
}

unsigned int* najdlhsia_rastuca_podpostupnost(float *p, int l, unsigned int *v) {
    unsigned int tail[l];
    unsigned int prev[l];
    tail[0] = 0;
    prev[0] = -1;
    for (int i = 1; i < l; i++) {
        tail[i] = -1;
        prev[i] = -1;
    }
    int len = 1;
    for (int i = 1; i < l; i++) {
        if (p[i] < p[tail[0]]) {
            tail[0] = i;
        }
        else if (p[i] > p[tail[len - 1]]) {
            prev[i] = tail[len - 1];
            tail[len++] = i;
        }
        else {
            int pos = binary_search(p, tail, -1, len - 1, p[i]);
            prev[i] = tail[pos - 1];
            tail[pos] = i;
        }
    }
    unsigned int *z = malloc(len * sizeof(unsigned int));
    printlist(z, len);
    for (unsigned int i = tail[len - 1]; i != -1; i = prev[i]) {
        z[i] = i;
        printf("pi = %.0f zi= %.0f\n", p[i], z[i]);
    }
    printlist(z, len);
    return z;
}

int main() {
    float p[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int l = sizeof(p) / sizeof(p[0]);
    unsigned int *v = najdlhsia_rastuca_podpostupnost(p, l, v);
}