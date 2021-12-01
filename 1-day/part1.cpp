#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int counter = 0;

    if (input.is_open())
    {
        int value = -1;
        while (getline(input, line))
        {
            if (value == -1)
            {
                value = stoi(line);
            }
            else
            {
                int bigger = stoi(line);
                if (bigger > value)
                {
                    counter++;
                }
                value = bigger;
            }
        }
        input.close();
    }
    std::cout << counter << std::endl;
}