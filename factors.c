#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

/**
 * factorize - The function factorize a number
 * 11 n: number and integer
 * Return: null
 */
void factorize(ll n)
{
	for (ll i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			printf("%lld=%lld*%lld\n", n, i, n / i);
			n /= i;
		}
	}
	if (n > 1)
	{
		printf("%lld=%lld*%lld\n", n, n, 1LL);
	}
}

/**
 * main - main function
 * @argv: file location
 * @argc: number of arguments
 * Return: void
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error opening file.\n");
		return (1);
	}

	ll number;
	while (fscanf(file, "%lld", &number) == 1)
	{
		factorize(number);
	}

	fclose(file);
	return (0);
}
