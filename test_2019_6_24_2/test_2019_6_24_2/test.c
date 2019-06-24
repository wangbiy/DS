#include <stdio.h>
#include <stdlib.h>
//斐波那契数的递归优化
long long Fib(long long first, long long second, long long n)
{
	if (n < 3)
		return 1;
	if (n == 3)
		return first + second;
	return Fib(second, first + second, n - 1);
}
int main()
{
	long long first = 1;
	long long second = 1;
	long long n = 10;
	long long ret = Fib(first, second, n);
	printf("%d ", ret);
	system("pause");
	return 0;
}