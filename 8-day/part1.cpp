#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define DIGIT_NUM 4
#define ALL_DIGITS 10

class display
{
private:
    vector<string> digits;
    vector<string> numbers;

public:
    display()
    {
        string s;
        for (int i = 0; i < ALL_DIGITS; i++)
        {
            cin >> s;
            digits.push_back(s);
        }
        getchar();
        getchar();
        for (int i = 0; i < DIGIT_NUM; i++)
        {
            cin >> s;
            numbers.push_back(s);
        }
    }

    int count_easy_digit(int num_digit)
    {
        int lenght = 0;
        int sum = 0;

        switch (num_digit)
        {
        case 1:
        {
            lenght = 2;
            break;
        }

        case 4:
        {
            lenght = 4;
            break;
        }
        case 7:
        {
            lenght = 3;
            break;
        }
        case 8:
        {
            lenght = 7;
            break;
        }

        default:
            break;
        }

        for (int i = 0; i < DIGIT_NUM; i++)
        {
            if ((int)numbers.at(i).length() == lenght)
                sum++;
        }
        return sum;
    }
};

int main()
{
    vector<display> all_displays;
    int counter[ALL_DIGITS] = {0};
    int c = 0;

    long long int sum_all_digits = 0;
    while (c != EOF)
    {
        all_displays.push_back(display());
        c = getchar();
    }

    for (display d : all_displays)
    {
        for (int i = 0; i < ALL_DIGITS; i++)
            counter[i] += d.count_easy_digit(i);
    }
    int sum = 0;
    for (int i = 0; i < ALL_DIGITS; i++)
    {
        cout << counter[i] << " ";
        sum += counter[i];
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}
