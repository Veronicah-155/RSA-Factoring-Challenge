#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll pollard_rho(ll n) {
    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll c = rand() % (n - 1) + 1;
    ll d = 1;

    while (d == 1) {
        x = (x * x + c) % n;
        y = (y * y + c) % n;
        y = (y * y + c) % n;
        d = gcd(abs(x - y), n);
        if (d == n) {
            return pollard_rho(n);
        }
    }

    return d;
}

void factorize(ll n) {
    if (n <= 1) {
        printf("No prime factors found for %lld\n", n);
      return;
    }

    ll factor = pollard_rho(n);

    if (factor == n) {
        printf("No prime factors found for %lld\n", n);
        return;
    }

    printf("%lld=%lld*%lld\n", n, factor, n / factor);
}

/**
 * main - rsa_factor code interpreter
 * @argc: number of arguments
 * @argv: rsa file location
 * Return: 0 on success
 */

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: factors <file>\n");
        return (1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return (1);
    }

    ll number;
    if (fscanf(file, "%lld", &number) != 1) {
        printf("Invalid input.\n");
        fclose(file);
        return (1);
    }

    factorize(number);

    fclose(file);
    return (0);
}
