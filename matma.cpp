#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int main()
{
	ofstream file;
	file.open("random.txt");
	unsigned long long int q = 30000000091, p = 40000000003, s = 8172888777, x = 0;
	int  b;
	unsigned long long int n = q * p;
	for (int i = 0; i < 10000; i++)
	{
		if (i == 0) {

			x = (s * s) % n;
		}
		else
		{

			x = (x * x) % n;
		}
		b = x%2;
		cout << b;
		file << b;
	}
	file.close();
	return 0;
}


