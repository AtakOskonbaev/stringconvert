#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, string> units = {{0, "nol"}, {1, "bir"}, {2, "eki"}, {3, "ych"}, {4, "tort"}, {5, "besh"}, {6, "alty"}, {7, "jeti"}, {8, "segiz"}, {9, "toguz"}};
map<int, string> tens = {{10, "on"}, {20, "juyrma"}, {30, "otuz"}, {40, "kyrk"}, {50, "eluu"}, {60, "altymysh"}, {70, "jetimish"}, {80, "seksen"}, {90, "tokson"}};
map<int, string> hundreds = {{100, "juz"}};

string convert(int number)
{
    string result = "";

    if (number == 0)
    {
        result += units[0];
        return result;
    }
    else
    {
        if (number >= 10000 && number <= 99999)
        {
            int ten = (number / 10000) * 10;
            result += tens[ten] + " ";
            int digit = (number / 1000) % 10;
            if (digit != 0)
                result += units[digit] + " min ";
            else
                result += "min ";
            number %= 1000;
        }
        if (number >= 1000 && number <= 9999)
        {
            int thousands = number / 1000;
            result += units[thousands] + " min ";
            number %= 1000;
        }
        if (number >= 100)
        {
            int hundred = number / 100;
            result += units[hundred] + " juz ";
            number %= 100;
        }
        if (number >= 10)
        {
            int ten = (number / 10) * 10;
            result += tens[ten] + " ";
            number %= 10;
        }
        if (number > 0)
        {
            result += units[number];
        }
        return result;
    }
}

int main()
{
    int number;
    cout << "Sanynyzdy kirgiziniz(0 - 99999): ";
    cin >> number;

    cout << convert(number) << endl;

    return 0;
}
