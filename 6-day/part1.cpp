#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

#define TIME_SPAN 9
#define DAYS 80
#define DAYS2 256

int main()
{
    long long counter[TIME_SPAN] = {0};
    int c = 0;

    while (c != EOF)
    {
        int value;
        cin >> value;
        counter[value]++;
        c = getchar();
    }

    int days = 0;
    while (days++ < DAYS)
    {
        long long new_fishes = counter[0];

        for (int i = 0; i < TIME_SPAN - 1; i++)
        {
            counter[i] = counter[i + 1];
        }
        counter[6] += new_fishes;
        counter[8] = new_fishes;
        if (days <= 18)
        {
            for (int m = 0; m < TIME_SPAN; m++)
            {
                cout << counter[m] << ",";
            }
            cout << endl;
        }
    }

    long long sum = 0;
    for (int i = 0; i < TIME_SPAN; i++)
        sum += counter[i];

    cout << sum << endl;

    days--;
    while (days++ < DAYS2)
    {
        long long new_fishes = counter[0];

        for (int i = 0; i < TIME_SPAN - 1; i++)
        {
            counter[i] = counter[i + 1];
        }
        counter[6] += new_fishes;
        counter[8] = new_fishes;
    }

    sum = 0;
    for (int i = 0; i < TIME_SPAN; i++)
        sum += counter[i];

    cout << sum << endl;
    return 0;
}
