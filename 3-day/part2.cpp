#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>

#define LENGTH 12
#define NUM_CHAR 1000

class number
{
private:
    char expression[LENGTH + 1];
    bool valid;

public:
    number()
    {
        valid = true;
    }
    number(char set_value[LENGTH])
    {
        strcpy(expression, set_value);
        expression[LENGTH] = '\0';
        valid = true;
    }
    int get_value_index(int index)
    {
        return (int)(expression[index] - '0');
    }

    void set_valid_true()
    {
        valid = true;
    }
    void set_valid_false()
    {
        valid = false;
    }
    bool get_valid()
    {
        return valid;
    }
    char *to_string()
    {
        return expression;
    }
};

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    number all_numbers[NUM_CHAR];
    int counter[LENGTH] = {0};
    int gamma = 0;
    int epsilon = 0;
    int num_inputs = 0;

    if (input.is_open())
    {
        while (getline(input, line))
        {
            char char_array[LENGTH];
            for (int i = 0; i < LENGTH; i++)
            {
                counter[i] += line[i] - '0';
            }
            strcpy(char_array, line.c_str());
            all_numbers[num_inputs] = number(char_array);
            num_inputs++;
        }
        input.close();

        for (int i = LENGTH; i > 0; i--)
        {
            int current_counter[LENGTH] = {0};
            int current_numbers = 0;
            for (int j = 0; j < NUM_CHAR; j++)
            {
                if (all_numbers[j].get_valid())
                {
                    for (int m = LENGTH - i - 1; m < LENGTH; m++)
                    {
                        current_counter[m] += all_numbers[j].get_value_index(m);
                    }
                    current_numbers++;
                }
            }

            // maiority sao 1
            if (counter[LENGTH - i] > NUM_CHAR / 2)
            {
                gamma += pow(2, i - 1);
            }
            // maiority sao 0
            else
            {
                epsilon += pow(2, i - 1);
            }
            // maioria é 1
            if (current_counter[LENGTH - i] >= current_numbers / 2)
            {
                for (int j = 0; j < NUM_CHAR; j++)
                {
                    number current = all_numbers[j];
                    if (current.get_valid() && !current.get_value_index(LENGTH - i))
                    {
                        all_numbers[j].set_valid_false();
                    }
                }
                std::cout << 1;
            }
            else
            {
                for (int j = 0; j < NUM_CHAR; j++)
                {
                    number current = all_numbers[j];
                    if (current.get_valid() && current.get_value_index(LENGTH - i))
                    {
                        all_numbers[j].set_valid_false();
                    }
                }
                std::cout << 0;
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < NUM_CHAR; i++)
    {
        if (all_numbers[i].get_valid())
        {
            int a = 3;
            std::cout << all_numbers[i].to_string() << std::endl;
        }
        all_numbers[i].set_valid_true();
    }

    for (int i = LENGTH; i > 0; i--)
    {
        int current_counter[LENGTH] = {0};
        int current_numbers = 0;
        for (int j = 0; j < NUM_CHAR; j++)
        {
            if (all_numbers[j].get_valid())
            {
                for (int m = LENGTH - i - 1; m < LENGTH; m++)
                {
                    current_counter[m] += all_numbers[j].get_value_index(m);
                }
                current_numbers++;
            }
        }

        if (current_numbers == 1)
            break;
        // se for 1 maior
        if (current_counter[LENGTH - i] > current_numbers / 2)
        {

            for (int j = 0; j < NUM_CHAR; j++)
            {
                number current = all_numbers[j];
                if (current.get_valid() && current.get_value_index(LENGTH - i))
                {
                    all_numbers[j].set_valid_false();
                }
            }
            std::cout << 0;
        }
        // se for 0 menor
        else
        {
            for (int j = 0; j < NUM_CHAR; j++)
            {
                number current = all_numbers[j];
                if (current.get_valid() && !current.get_value_index(LENGTH - i))
                {
                    all_numbers[j].set_valid_false();
                }
            }
            std::cout << 1;
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < NUM_CHAR; i++)
    {
        if (all_numbers[i].get_valid())
        {
            int a = 3;
            std::cout << all_numbers[i].to_string() << std::endl;
        }
        all_numbers[i].set_valid_true();
    }
    std::cout << gamma * epsilon << std::endl;
    return 0;
}
