#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define RAND_NUMS 100
#define BOARD_DIM 5

class board
{
private:
    int matrix[BOARD_DIM][BOARD_DIM];
    bool done;

public:
    board()
    {
        for (int y = 0; y < BOARD_DIM; y++)
        {
            for (int x = 0; x < BOARD_DIM; x++)
            {
                int value;
                cin >> value;
                matrix[y][x] = value;
            }
        }
        done = false;
    }

    bool get_status()
    {
        return done;
    }

    void check_number(int value)
    {
        for (int y = 0; y < BOARD_DIM; y++)
        {
            for (int x = 0; x < BOARD_DIM; x++)
            {
                if (matrix[y][x] == value)
                    matrix[y][x] = -1;
            }
        }
    }

    bool check_winner()
    {
        int sum = 0;
        for (int y = 0; y < BOARD_DIM; y++)
        {
            for (int x = 0; x < BOARD_DIM; x++)
            {
                sum += matrix[y][x];
            }
            if (sum == -5)
            {
                print();
                done = true;
                return true;
            }
            sum = 0;
        }

        for (int y = 0; y < BOARD_DIM; y++)
        {
            for (int x = 0; x < BOARD_DIM; x++)
            {
                sum += matrix[x][y];
            }
            if (sum == -5)
            {
                print();
                done = true;
                return true;
            }
            sum = 0;
        }
        return false;
    }

    void print()
    {
        for (int y = 0; y < BOARD_DIM; y++)
        {
            for (int x = 0; x < BOARD_DIM; x++)
            {
                cout << matrix[y][x] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void sum(int num)
    {
        int sum = 0;
        for (int y = 0; y < BOARD_DIM; y++)
        {
            for (int x = 0; x < BOARD_DIM; x++)
            {
                if (matrix[y][x] != -1)
                    sum += matrix[y][x];
            }
        }
        cout << sum * num << endl;
    }
};

int main()
{
    int c = 0;
    int rand_nums[RAND_NUMS];
    int random_numbers = 0;
    vector<board> all_boards;
    while (c != '\n')
    {
        cin >> rand_nums[random_numbers];
        c = getchar();
        random_numbers++;
    }
    for (int i = 0; i < random_numbers; i++)
    {
        cout << rand_nums[i] << " ";
    }
    cout << endl;
    c = 0;
    while (c != EOF)
    {
        all_boards.push_back(board());
        c = getchar();
    }
    int rand_num_index = 0;
    int curr_rand_num;
    int num_right_boards = 0;
    while (1)
    {
        curr_rand_num = rand_nums[rand_num_index++];
        if (curr_rand_num == 24)
            cout << "aqui" << endl;
        for (int i = 0; i < (int)all_boards.size(); i++)
        {

            all_boards.at(i).check_number(curr_rand_num);
            if (!all_boards.at(i).get_status() && all_boards.at(i).check_winner())
            {
                num_right_boards++;
                if (num_right_boards == (int)all_boards.size())
                {
                    cout << "olaaaaaaa" << endl;
                    cout << curr_rand_num << endl;
                    all_boards.at(i).sum(curr_rand_num);
                    return 0;
                }
            }
            all_boards.at(i).print();
        }
        cout << "--------------------------" << endl;
    }

    return 0;
}
