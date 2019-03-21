#include<iostream>
#include<vector>
using namespace std;
int _bseach(vector<int> number, int value);
void square_brute_force(double a);
void square_bsearch(double a);
int main()
{

	vector<int> number = { 1,2,3,4,5,6,7,8,9,10 };
	_bseach(number, 3);
	square_brute_force(41.235554545423);
//	square_bsearch(41.235554545423);


	system("pause");
	return 0;
}
int _bseach(vector<int> number, int value)
{
	int size = number.size();
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (value == number[mid])
		{
			cout << "Value " << value << " is located at index of " << mid << endl;
			return 0;
		}
		else if (value > number[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return 1;
}
void square_brute_force(double a)
{
	double epicilon = 0.01;
	int numGuesses = 0;
	double ans = 0.0;
	while (abs(pow(ans, 2) - a) > epicilon)
	{
		ans += 0.00001;
		numGuesses += 1;
	}
	if (abs(pow(ans, 2) - a) > epicilon)
	{

		cout << "failed.." << numGuesses << endl;
	}
	else
	{
		cout << ans << " close to square root of " << a << " with " << numGuesses << " number of guesses " << endl;
	}

}
void square_bsearch(double a)
{
	double epicilon = 0.01;
	double low = 0.0;
	double high = a;
	int guesses = 0;
	double guess = (high + low) / 2.0;
	while (abs((pow(guess, 2)) - a) >= epicilon)
	{
		if (pow(guess, 2) < a)
		{
			low = guess;
		}
		else
		{
			high = guess;
		}
		guess = (high + low) / 2.0;
		guesses += 1;

	}
	cout << guess << "is close enough to square root of" << a << "Guesses:" << guesses << endl;
}
