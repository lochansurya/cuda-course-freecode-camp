#include <stdio.h>
#include <math.h>

void softmax(float *x, int n) {
    float max = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        x[i] = exp(x[i] - max);
        sum += x[i];
    }
    for (int i = 0; i < n; i++) {
        x[i] /= sum;
    }
}

int main() {
    float x[] = {1.0, 2.0, 3.0};
    softmax(x, 3);
    for (int i = 0; i < 3; i++) {
        printf("%f\n", x[i]);
    }
    return 0;
}