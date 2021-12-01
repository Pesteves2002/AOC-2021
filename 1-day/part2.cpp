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
        int values[3] = {-1, -1, -1};
        int prev_sum = 0;

        while (getline(input, line))
        {
            if (!prev_sum)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (values[i] == -1)
                    {
                        values[i] = stoi(line);
                        getline(input, line);
                    }
                }

                for (int i = 0; i < 3; i++)
                {
                    prev_sum += values[i];
                }
            }

            int new_value = stoi(line);
            for (int i = 0; i < 2; i++)
            {
                values[i] = values[i + 1];
            }
            values[2] = new_value;

            int sum = 0;
            for (int i = 0; i < 3; i++)
            {
                sum += values[i];
            }

            if (sum > prev_sum)
            {
                counter++;
            }
            prev_sum = sum;
        }

        input.close();
    }
    std::cout << counter << std::endl;
}
