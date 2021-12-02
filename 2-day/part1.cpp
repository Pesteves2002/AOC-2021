#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int horizontal = 0;
    int depth = 0;

    if (input.is_open())
    {
        while (getline(input, line))
        {
            int i = 0;
            char command[10] = "";
            // command
            while (line[i] != ' ')
            {
                command[i] = line[i];
                i++;
            }
            command[i] = '\0';

            int value = 0;
            char value_char[10] = "";
            int m = 0;
            while (line[i] != '\0')
            {
                value_char[m++] = line[i];
                i++;
            }
            value = atoi(value_char);

            if (strcmp(command, "forward") == 0)
            {
                horizontal += value;
            }
            if (strcmp(command, "up") == 0)
            {
                depth -= value;
            }
            if (strcmp(command, "down") == 0)
            {
                depth += value;
            }
        }
        input.close();
    }
    std::cout << horizontal * depth << std::endl;
    return 0;
}