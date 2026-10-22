#include <stdlib.h>

double estimar_pi(int n) {
    int dentro = 0;
    for (int i = 0; i < n; i++) {
        double x = rand() / (double) RAND_MAX;
        double y = rand() / (double) RAND_MAX;
        if (x * x + y * y <= 1.0)
            dentro++;
    }
    return 4.0 * dentro / n;
}