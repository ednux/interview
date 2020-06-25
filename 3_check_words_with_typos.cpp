#include <iostream>
#include <string>

using namespace std;

bool checkWordsTypos(string s1, string s2);

int main(int argc, char **argv)
{
    string s1, s2;

    //pale, ple ­> true
    s1 = "pale";
    s2 = "ple";

    cout << (checkWordsTypos(s1, s2) ? "True" : "False") << endl;

    //pales, pale ­> true
    s1 = "pales";
    s2 = "pale";

    cout << (checkWordsTypos(s1, s2) ? "True" : "False") << endl;

    //pale, bale ­> true
    s1 = "pale";
    s2 = "bale";

    cout << (checkWordsTypos(s1, s2) ? "True" : "False") << endl;

    //pale, bake ­> false
    s1 = "pale";
    s2 = "bake";
    
    cout << (checkWordsTypos(s1, s2) ? "True" : "False") << endl;

    return 0;
}

bool checkWordsTypos(string s1, string s2)
{
    const int MAX_MISTAKES = 1;
    int errors = 0;
    size_t s1_length, s2_length, i = 0, j = 0;

    s1_length = s1.length();
    s2_length = s2.length();

    if ( (s1_length > (s2_length + 1)) || (s1_length < (s2_length - 1)) )
    {
        return false;
    }

    if (s1_length == s2_length)
    {
        while (i < s2_length && errors <= MAX_MISTAKES)
        {
            if (s1[i] != s2[i])
            {
                errors++;
            }
            i++;
        }
    }
    else
    {
        errors++;
        j = s1_length > s2_length ? s2_length : s1_length;
        while (i < j)
        {
            if (s1[i] != s2[i])
            {
                if (s1_length > s2_length)
                {
                    s2.insert(i, 1, s1[i]);
                }
                else
                {
                    s1.insert(i, 1, s2[i]);
                }

                if (s1 != s2) 
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            i++;
        }
    }

    if (errors <= MAX_MISTAKES)
    {
        return true;
    }

    return false;
}