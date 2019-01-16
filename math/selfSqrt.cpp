#include<iostream>
#include<cmath>

using namespace std;

double ano_sqrt(double x) {
    if (x <= 0)
        return 0;       // if negative number throw an exception?
    int exp = 0;
    x = frexp(x, &exp); // extract binary exponent from x
    if (exp & 1) {      // we want exponent to be even
        exp--;
        x *= 2;
    }
    double y = (1+x)/2; // first approximation
    double z = 0;
    while (y != z) {    // yes, we CAN compare doubles here!
        z = y;
        y = (y + x/y) / 2;
    }
    return ldexp(y, exp/2); // multiply answer by 2^(exp/2)
}

double sqrt11(const double number, const double ACCURACY)
{
    double lower, upper, guess;

    if (number < 1)
    {
        lower = number;
        upper = 1;
    }
    else
    {
        lower = 1;
        upper = number;
    }

    while ((upper-lower) > ACCURACY)
    {
        guess = (lower + upper)/2;
        if(guess*guess > number)
        upper = guess;
        else
        lower = guess; 
    }
    return (lower + upper)/2;

}

double sqrt13( int n )
{
	// double a = (eventually the main method will plug values into a)
	double a = (double) n;
	double x = 1;
 
	// For loop to get the square root value of the entered number.
	for( int i = 0; i < n; i++)
	{
		x = 0.5 * ( x+a / x );
	}
 
	return x;
}

int main(int argc, char const *argv[])
{
    /* code */
    double y, accuracy;
    cout << "input y,accuracy: ";
    cin >> y >> accuracy;

    cout << "result: " << sqrt13(y) << endl;
    return 0;
}
