#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int c = 0;
    vector<int> all_crabs;
    int value;
    int min = 99999999;
    int max = -1;
    while (c != EOF)
    {
        cin >> value;
        all_crabs.push_back(value);

        if (value > max)
            max = value;
        if (value < min)
            min = value;

        c = getchar();
    }
    int num_crabs = all_crabs.size();
    long long sum = 0;
    long long minimum_fuel = 999999;
    for (int x = min; x <= max; x++)
    {
        for (int index = 0; index < num_crabs; index++)
            sum += abs(all_crabs.at(index) - x);
        if (sum < minimum_fuel)
            minimum_fuel = sum;
        sum = 0;
    }
    cout << minimum_fuel << endl;

    sum = 0;
    minimum_fuel = 9999999999;
    int offset;
    for (int x = min; x <= max; x++)
    {
        for (int index = 0; index < num_crabs; index++)
        {
            offset = abs(all_crabs.at(index) - x);
            sum += (offset) * (offset + 1) / 2;
        }
        if (sum < minimum_fuel)
            minimum_fuel = sum;
        sum = 0;
    }
    cout << minimum_fuel << endl;

    return 0;
}
