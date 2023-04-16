#include <bits/stdc++.h>

using namespace std;

//from my understanding, this is a function that returns true if something is a prime number
bool isPrime1(int n)
{

	if (n != 2 && n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
		//this is worth testing because I did not test it, but it takes less lines of code and uses 'and' and 'or' functions
		//it will return true if n is 2
		return false;
	return true;
}

bool isPrime2(int n)
{
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

vector<int> getDivisors(int n)
{
	vector<int> ret;
	for (int i = 1; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			ret.push_back(i);
			if (i != (n/i))
				ret.push_back(n / i);
		}
	}
	return ret;
}

vector<bool> init(long long n)
{
	vector<bool> isPrime(n + 10, true);
	isPrime[0] = isPrime[1] = false;
	for (long long i = 2; i * i <= n; i++)
		if (isPrime[i])
			for (long long j = i * i; j < n; j += i)
				isPrime[j] = false;

	return isPrime;
}

vector<pair<int, int>> PF(int n)
{
	vector<pair<int, int>> ans;
	for (int i = 2; i * i <= n; i++)
	{
		int cnt = 0;
		while (n % i == 0)
		{
			cnt++;
			n /= i;
		}
		if (cnt)
			ans.push_back({i, cnt});
	}
	if (n > 1)
		ans.push_back({n, 1});
	return ans;
}

int main()
{
	vector<bool> isPrime = init(1e6 + 10);
	return 0;
}
