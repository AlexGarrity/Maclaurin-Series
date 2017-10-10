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
    x = 1.0 - x;
    long double total = 0;
    for (int i = 1; i < 32; i++)
    {
        long double powx = pow (x, i);
        long double delta = powx / i;
        total -= delta;
    }
    return total;
}

long double Log (long double x, long double base)
{
    //Trying to find a different series for ln, such that this actually works...
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
    long double maclaurinCos = Cos(1.9);

    cout.precision(8);

    cout << "Maclaurin's Cos of 1.9 radians is: \t" << maclaurinCos << endl;
    cout << "stdlib Cos of 1.9 radians is: \t \t" << computerCos << endl;
    cout << "Difference of Cos values: \t \t" << Absolute(maclaurinCos-computerCos) << endl;

    long double computerSin = sin(1.9);
    long double maclaurinSin = Sin(1.9);

    cout << "\nMaclaurin's Sin of 1.9 radians is: \t" << maclaurinSin << endl;
    cout << "stdlib Sin of 1.9 radians is: \t \t" << computerSin << endl;
    cout << "Difference of Sin values: \t \t" << Absolute(maclaurinSin-computerSin) << endl;

    long double computerTan = sin(1.9) / cos(1.9);
    long double maclaurinTan = Sin(1.9) / Cos(1.9);

    cout << "\nMaclaurin's Tan of 1.9 radians is: \t" << maclaurinTan << endl;
    cout << "stdlib Tan of 1.9 radians is: \t \t" << computerTan << endl;
    cout << "Difference of Tan values: \t \t" << Absolute(maclaurinTan-computerTan) << endl;

    long double maclaurinEuler = Euler(1);
    long double computerEuler = exp(1);

    cout << "\nMaclaurin's Euler ^ 1 is: \t \t \t" << maclaurinEuler << endl;
    cout << "stdlib Euler ^ 1 is: \t \t \t" << computerEuler << endl;
    cout << "Difference of Euler values is: \t \t" << Absolute(maclaurinEuler-computerEuler) << endl;

    long double maclaurinLn = Ln(0.5);
    long double computerLn = log(0.5);

    cout << "\nMaclaurin's ln(0.5) is: \t \t \t" << maclaurinLn << endl;
    cout << "stdlib ln(0.5) is: \t \t \t" << computerLn << endl;
    cout << "Difference of ln values is: \t \t" << Absolute(maclaurinLn-computerLn) << std::endl;

    //Skipping log until alternative ln series is found

    //long double maclaurinLog = log(3,10);
    //long double computerLog = log(3)/log(10);

    return 0;
}
