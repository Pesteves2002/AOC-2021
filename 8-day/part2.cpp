#include <bits/stdc++.h>
using namespace std;
ifstream fin("date2.in");
// FILE *file = fopen("date2.in", "r");

int uniqueNrOfDigits(int x)
{
    if (x == 2)
        return 1;
    if (x == 4)
        return 4;
    if (x == 3)
        return 7;
    if (x == 7)
        return 8;
    return 0;
}

void solveZones(map<int, string> &digitCodes, map<string, int> &digitConv, const string input[10])
{
    char zone[7] = {0};
    for (int i = 0; i < 3; ++i)
    {
        if (digitCodes[7][i] != digitCodes[1][i])
        {
            zone[0] = digitCodes[7][i];
            break;
        }
    }
    string aux = digitCodes[4] + zone[0];
    sort(aux.begin(), aux.end());
    for (int i = 0; i < 10; ++i)
    {
        if (!digitConv[input[i]] && input[i].size() == 6)
        {
            char found = 0;
            bool ok = 1;
            for (int j = 0, k = 0; j < 6; ++j, ++k)
            {
                if (input[i][j] != aux[k])
                {
                    if (!found)
                    {
                        found = input[i][j];
                        --k;
                    }
                    else
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok)
            {
                zone[6] = found;
                digitCodes[9] = input[i];
                digitConv[input[i]] = 9;
                break;
            }
        }
    }
    aux = digitCodes[1] + zone[0] + zone[6];
    sort(aux.begin(), aux.end());
    for (int i = 0; i < 10; ++i)
    {
        if (!digitConv[input[i]] && input[i].size() == 5)
        {
            char found = 0;
            bool ok = 1;
            for (int j = 0, k = 0; j < 5; ++j, ++k)
            {
                if (input[i][j] != aux[k])
                {
                    if (!found)
                    {
                        found = input[i][j];
                        --k;
                    }
                    else
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok)
            {
                zone[3] = found;
                digitCodes[3] = input[i];
                digitConv[input[i]] = 3;
                break;
            }
        }
    }
    aux = digitCodes[1] + zone[3];
    sort(aux.begin(), aux.end());
    for (int i = 0; i < 4; ++i)
    {
        if (digitCodes[4][i] != aux[i])
        {
            zone[1] = digitCodes[4][i];
            break;
        }
    }
    aux = "";
    aux = aux + zone[0] + zone[1] + zone[3] + zone[6];
    sort(aux.begin(), aux.end());
    for (int i = 0; i < 10; ++i)
    {
        if (!digitConv[input[i]] && input[i].size() == 5)
        {
            char found = 0;
            bool ok = 1;
            for (int j = 0, k = 0; j < 5; ++j, ++k)
            {
                if (input[i][j] != aux[k])
                {
                    if (!found)
                    {
                        found = input[i][j];
                        --k;
                    }
                    else
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok)
            {
                zone[5] = found;
                digitConv[input[i]] = 5;
                digitCodes[5] = input[i];
                break;
            }
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        if (digitCodes[1][i] != zone[5])
        {
            zone[2] = digitCodes[1][i];
            break;
        }
    }
    for (char last = 'a'; last <= 'g'; ++last)
    {
        bool ok = 0;
        for (int i = 0; i < 7; ++i)
        {
            if (last == zone[i])
                ok = 1;
        }
        if (!ok)
        {
            zone[4] = last;
            break;
        }
    }
    aux = "";
    aux = aux + zone[0] + zone[2] + zone[3] + zone[4] + zone[6];
    sort(aux.begin(), aux.end());
    digitCodes[2] = aux;
    digitConv[aux] = 2;
    aux = "";
    aux = aux + zone[0] + zone[1] + zone[3] + zone[4] + zone[5] + zone[6];
    sort(aux.begin(), aux.end());
    digitCodes[6] = aux;
    digitConv[aux] = 6;
    aux = "";
    aux = aux + zone[0] + zone[1] + zone[2] + zone[4] + zone[5] + zone[6];
    sort(aux.begin(), aux.end());
    digitCodes[0] = aux;
    digitConv[aux] = 0;
}

int main()
{
    const int lines = 200;
    int sum = 0;
    for (int k = 0; k < lines; ++k)
    {
        map<int, string> realDigit;
        map<string, int> digitConversion;
        string dg, cd[10];
        for (int i = 0; i < 10; ++i)
        {
            fin >> cd[i];
            sort(cd[i].begin(), cd[i].end());
            int x = uniqueNrOfDigits(cd[i].size());
            if (x)
            {
                realDigit[x] = cd[i];
                digitConversion[cd[i]] = x;
            }
        }
        solveZones(realDigit, digitConversion, cd);
        fin >> dg;
        int code = 0;
        for (int i = 0; i < 4; ++i)
        {
            fin >> dg;
            sort(dg.begin(), dg.end());
            code = code * 10 + digitConversion[dg];
        }
        sum += code;
    }
    cout << sum;
}
