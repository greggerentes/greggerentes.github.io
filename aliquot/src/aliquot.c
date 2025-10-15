#include <stdio.h>
#include <stdlib.h>

unsigned long long aliquot_sum(unsigned long long n) {
    if (n == 1) return 0;

    unsigned long long sum = 1;
    for (unsigned long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            unsigned long long j = n / i;
            if (j != i) sum += j;
        }
    }
    return sum;
}

int main() {
    unsigned long long n;
    unsigned long long max_length;
    char option;

    if (scanf("%llu %llu %c", &n, &max_length, &option) != 3) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (n == 0 || (option != 'f' && option != 'l')) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    unsigned long long count = 0;
    while (n != 0 && (max_length == 0 || count < max_length)) {
        if (n > 1000000000000000ULL) {
            fprintf(stderr, "Number exceeded 10^15\n");
            return 1;
        }

        if (option == 'f') {
            printf("%llu ", n);
        }

        n = aliquot_sum(n);
        count++;
    }

    if (option == 'l') {
        printf("%llu\n", count);
    } else {
        printf("\n");
    }

    return 0;
}
