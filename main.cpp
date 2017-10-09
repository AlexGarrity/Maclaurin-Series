#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

unsigned long long factorial(int number)
{
    unsigned long long value = number;
    for (int i = number - 1; i > 1; i --)
    {
        value *= i;
    }
    return value;
}

long double Absolute (long double x)
{
    if (x < 0)
    {
        return x * -1;
    }
    return x;
}

long double Ln (long double x)
{
    if (x == 1) return 0;
    long double total = x - 1;
    for (int i = 1; i <= 32; i++)
    {
        long double powx = pow(x,i);
        long double delta = powx / i;
        if (i % 2) total -= delta;
        else total += delta;
    }
    return total;
}

long double Log (long double x, long double base)
{
    return Ln(x)/Ln(base);
}

long double Euler (int x)
{
    long double total = 1;
    for (int i = 1; i <= 12; i++)
    {
        long double powx = pow (x, i);
        unsigned long long factorialI = factorial(i);
        long double delta = powx / factorialI;
        total += delta;
    }
    return total;
}

long double Sin (double value)
{
    long double total = value;
    for (int i = 3; i <= 33; i += 2)
    {
        long double powx = pow(value, i);
        unsigned long long factorialI = factorial(i);
        long double delta = powx / factorialI;

        if ((i-1) % 4 == 0) total += delta;
        else total -= delta;
    }
    return total;
}

long double Cos (double value)
{
    long double total = 1;
    for (int i = 2; i <= 32; i += 2)
    {
        long double powx = pow(value,i);
        unsigned long long factorialI = factorial(i);
        long double delta = powx / factorialI;

        if (i % 4 == 0) total += delta;
        else total -= delta;
    }
    return total;
}

int main ()
{
    cout << "Started... " << endl;

    long double computerCos = cos(1.9);
    long double taylorCos = Cos(1.9);

    cout.precision(8);

    cout << "Taylor's Cos of 1.9 radians is: \t" << taylorCos << endl;
    cout << "stdlib Cos of 1.9 radians is: \t \t" << computerCos << endl;
    cout << "Difference of Cos values: \t \t" << Absolute(taylorCos-computerCos) << endl;

    long double computerSin = sin(1.9);
    long double taylorSin = Sin(1.9);

    cout << "\nTaylor's Sin of 1.9 radians is: \t" << taylorSin << endl;
    cout << "stdlib Sin of 1.9 radians is: \t \t" << computerSin << endl;
    cout << "Difference of Sin values: \t \t" << Absolute(taylorSin-computerSin) << endl;

    long double computerTan = sin(1.9) / cos(1.9);
    long double taylorTan = Sin(1.9) / Cos(1.9);

    cout << "\nTaylor's Tan of 1.9 radians is: \t" << taylorTan << endl;
    cout << "stdlib Tan of 1.9 radians is: \t \t" << computerTan << endl;
    cout << "Difference of Tan values: \t \t" << Absolute(taylorTan-computerTan) << endl;

    long double taylorEuler = Euler(1);
    long double computerEuler = exp(1);

    cout << "\nTaylor's Euler ^ 1 is: \t \t \t" << taylorEuler << endl;
    cout << "stdlib Euler ^ 1 is: \t \t \t" << computerEuler << endl;
    cout << "Difference of Euler values is: \t \t" << Absolute(taylorEuler-computerEuler) << endl;

    long double taylorLn = Ln(0.5);
    long double computerLn = log(0.5);

    cout << "\nTaylor's ln(0.5) is: \t \t \t" << taylorLn << endl;
    cout << "stdlib ln(0.5) is: \t \t \t" << computerLn << endl;
    cout << "Difference of ln values is: \t \t" << Absolute(taylorLn-computerLn) << std::endl;

    //Skipping log until alternative ln series is found

    //long double taylorLog = log(3,10);
    //long double computerLog = log(3)/log(10);

    return 0;
}
