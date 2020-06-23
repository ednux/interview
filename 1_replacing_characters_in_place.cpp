#include <iostream>
#include <string.h>

using namespace std;

void replace(char *input, int size);

int main(int argc, char **argv)
{
    char input[30] = "User is not allowed";

    replace(input, 19);

    if (strcmp(input, "User&32is&32not&32allowed") == 0)
    {
        cout << input << endl;
    }
    else
    {
        cout << "replace failed" << endl;
    }

    return 0;
}

void replace(char *input, int size)
{
    int i, j;

    for (i=0; i <= size; i++)
    {
        if (input[i] == 32)
        {
            size+=2;
            for (j=size; j > (i + 2); j--)
            {
                input[j] = input[j-2];
            }

            input[i] = '&';
            input[++i] = '3';
            input[++i] = '2';
        }
    }
}