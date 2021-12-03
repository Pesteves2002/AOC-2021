#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>

#define LENGTH 12

int simetric(int num)
{
    if (num)
        return 0;
    return 1;
}

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int counter[LENGTH] = {0};
    int gamma = 0;
    int epsilon = 0;
    int num_inputs = 0;

    if (input.is_open())
    {
        while (getline(input, line))
        {
            for (int i = 0; i < LENGTH; i++)
            {
                counter[i] += line[i] - '0';
            }
            num_inputs++;
        }
        input.close();
        int condition = num_inputs / 2;

        for (int i = LENGTH; i > 0; i--)
        {
            // maiority sao 1
            if (counter[LENGTH - i] > condition)
            {
                gamma += pow(2, i - 1);
            }
            // minority
            else
            {
                epsilon += pow(2, i - 1);
            }
        }
    }
    std::cout << gamma * epsilon << std::endl;
    return 0;
}