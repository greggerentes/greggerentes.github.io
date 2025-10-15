#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 1000000000000000ULL // 10^15

unsigned long long s(unsigned long long n) {
    if (n <= 1) return 0;
    unsigned long long sum = 1;
    for (unsigned long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}

int main(void) {
    unsigned long long n, next;
    unsigned long long max_len;
    char mode;

    printf("Please give the number to start the aliquot sequence from: ");
    if (scanf("%llu", &n) != 1) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    printf("Provide the max aliquot length to look for (0 for unlimited): ");
    if (scanf("%llu", &max_len) != 1) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    printf("Do you want to print the full sequence ('f') or just the length ('l')? ");
    if (scanf(" %c", &mode) != 1 || (mode != 'f' && mode != 'l')) {
        fprintf(stderr, "Invalid choice\n");
        return 1;
    }

    unsigned long long count = 0;
    unsigned long long current = n;

    while (1) {
        if (mode == 'f') {
            printf("%llu\n", current);
        }

        if (current == 0) break;

        next = s(current);
        count++;

        if (next > MAX_LIMIT) {
            fprintf(stderr, "Number exceeds maximum supported integer (%llu). Stopping.\n", MAX_LIMIT);
            return 1;
        }

        if (max_len != 0 && count >= max_len) break;

        current = next;
    }

    if (mode == 'l') {
        printf("Length of aliquot sequence: %llu\n", count);
    }

    return 0;
}
