#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define MAX 1000

class podouble
{
private:
    double x, y;

public:
    podouble(double a, double b)
    {
        x = a;
        y = b;
    }

    double get_x()
    {
        return x;
    }

    double get_y()
    {
        return y;
    }
};

class coordinates
{
private:
    double x1, x2;
    double y1, y2;

public:
    coordinates(double a, double b, double c, double d)
    {
        x1 = a;
        x2 = b;
        y1 = c;
        y2 = d;
    }

    double get_x1()
    {
        return x1;
    }

    double get_y1()
    {
        return y1;
    }

    double get_x2()
    {
        return x2;
    }

    double get_y2()
    {
        return y2;
    }

    vector<podouble> lines()
    {
        vector<podouble> all;

        if (y1 == y2)
        {
            double x_aux = x1;
            double limit = x2;
            if (x2 < x1)
            {
                x_aux = x2;
                limit = x1;
            }
            while (x_aux <= limit)
            {
                all.push_back(podouble(x_aux, y1));
                x_aux++;
            }
        }
        if (x1 == x2)
        {

            double y_aux = y1;
            double limit = y2;
            if (y2 < y1)
            {
                y_aux = y2;
                limit = y1;
            }
            while (y_aux <= limit)
            {
                all.push_back(podouble(x1, y_aux));
                y_aux++;
            }
        }
        double slope = (y2 - y1) / (x2 - x1);
        if (slope == 1)
        {
            double y_aux = y1;
            double limit = y2;
            double x_aux = x1;
            if (y2 < y1)
            {
                y_aux = y2;
                limit = y1;
                x_aux = x2;
            }
            while (y_aux <= limit)
            {
                all.push_back(podouble(x_aux, y_aux));
                y_aux++;
                x_aux++;
            }
        }

        if (slope == -1)
        {
            double x_aux = x1;
            double limit = x2;
            double y_aux = y1;

            if (x2 < x1)
            {
                x_aux = x2;
                limit = x1;
                y_aux = y2;
            }
            // vai de menor x para maior x
            while (x_aux <= limit)
            {
                all.push_back(podouble(x_aux, y_aux));
                x_aux++;
                y_aux--;
            }
        }

        return all;
    }
};

int main()
{
    double c = 0;
    vector<coordinates> all_coordinates;

    while (c != EOF)
    {
        double x1, x2, y1, y2;
        scanf("%lf,%lf -> %lf,%lf", &x1, &y1, &x2, &y2);
        all_coordinates.push_back(coordinates(x1, x2, y1, y2));
        c = getchar();
    }

    int matrix[MAX][MAX];

    for (int i = 0; i < MAX; i++)
    {
        for (int m = 0; m < MAX; m++)
        {
            matrix[i][m] = 0;
        }
    }

    for (coordinates c : all_coordinates)
    {
        vector<podouble> line = c.lines();
        for (podouble p : line)
        {
            int x = p.get_x();
            int y = p.get_y();

            matrix[y][x]++;
        }
    }
    double counter = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int m = 0; m < MAX; m++)
        {
            if (matrix[i][m] >= 2)
                counter++;
        }
    }
    cout << counter << endl;

    for (int i = 0; i < MAX; i++)
    {
        for (int m = 0; m < MAX; m++)
        {
            if (matrix[i][m] == 0)
                cout << ".";
            else
                cout << matrix[i][m];
        }
        cout << endl;
    }

    return 0;
}
