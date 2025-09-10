#include<iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter Either 0 or 1";
    cin >> num;

    if (num == 1)
    {
        cout << "Number is 1";
    }
    else if (num == 0)
    {
        cout << "Number is 0";
    }
    else
    {
        cout << "Invalid NUmber";
    }
}