#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
clock_t start;
clock_t start1;

long long fib1(long long n);
void fib2(long long n);

int main()
{
    long long n;

    cout << "Enter the value of n: ";
    cin >> n;

    int temp = n;

    start = clock();

    while(n > 0 & (clock() - start)/CLOCKS_PER_SEC <= 60)
    {
        cout << fib1(n) << " ";
        n--;
    }

    cout << "\n\nRecursive Fibonacci: " << (clock() - start) / CLOCKS_PER_SEC << " seconds\n" << endl;

    start1 = clock();
    fib2(temp);

    return 0;
}

long long fib1(long long n)
{
    if(n <= 1)
        return n;

    else
        return fib1(n - 1) + fib1(n - 2);
}

void fib2(long long n)
{
    long long x = 1, y = 1, z = 0;
    for (long long i = 0; i < n; i++)
    {
        cout << x << " ";
        z = x + y;
        x = y;
        y = z;
   }
   cout << "\n\nIterative Fibonacci: " << (clock() - start1) / CLOCKS_PER_SEC << " seconds" << endl;
}
