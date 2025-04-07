#include <stdio.h>

void calculateBernoulliNumbers(int n) {
    // Arrays 
    double B[n+1];
    
    // Initialize B[0] = 1
    B[0] = 1.0;
    
    // Calculate Bernoulli numbers up to B[n]
    for (int i = 1; i <= n; i++) {
        double sum = 0.0;
        
        for (int j = 0; j < i; j++) {
            // Calculate binomial coefficient
            int binom = 1;
            for (int k = 1; k <= j; k++) {
                binom = binom * (i + 1 - k) / k;
            }
            
            sum += binom * B[j] / (i + 1 - j);
        }
        
        B[i] = -sum;
        
        // Only even-indexed Bernoulli numbers are non-zero (except B[1])
        if (i > 1 && i % 2 == 1) {
            B[i] = 0.0;
        }
        
        printf("B[%d] = %f\n", i, B[i]);
    }
}

int main() {
    int n = 10; // Calculate Bernoulli numbers up to X
    calculateBernoulliNumbers(n);
    
    return 0;
}
