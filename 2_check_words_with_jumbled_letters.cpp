#include <iostream>
#include <string>
#include <algorithm>    

using namespace std;

bool partial­permutation(string s1, string s2);

int main(int argc, char **argv)
{
    //you, yuo ­> true
    /* string s1 = "yuo";
    string s2 = "you"; */

    // probably, porbalby ­> ­true
    /* string s1 = "porbalby";
    string s2 = "probably"; */
    
    //despite, desptie ­> true
    /* string s1 = "desptie";
    string s2 = "despite"; */

    //moon, nmoo ­> false
    /* string s1 = "nmoo";
    string s2 = "moon"; */

    //misspellings, mpeissngslli ­> false
    string s1 = "mpeissngslli";
    string s2 = "misspellings";

    if (partial­permutation(s1, s2) == true)
    {
        cout << "\'" << s1 << "\'" << " is a partial-permutation of " << "\'" << s2 << "\'" << endl;
    }
    else
    {
        cout << "\'" << s1 << "\'" << " is NOT a partial-permutation of " << "\'" << s2 << "\'" << endl;
    }

    return 0;
}

bool partial­permutation(string s1, string s2)
{
    const int MIN_NUMBER_LETTERS = 3;
    int max_mistakes, errors = 0;
    size_t s1_length, s2_length, i = 1;

    s1_length = s1.length();
    s2_length = s2.length();

    if ((s2_length < MIN_NUMBER_LETTERS) || (s1_length != s2_length) || (s1[0] != s2[0]))
    {
        return false;
    }

    max_mistakes = (s1_length * 2) / 3;

    while (i < s1_length && errors <= max_mistakes)
    {
        if (s1[i] != s2[i])
        {
            size_t n_chs2 = count(s2.begin(), s2.end(), s2[i]);
            size_t n_chs1 = count(s1.begin(), s1.end(), s2[i]);
            if (n_chs2 != n_chs1)
            {
                return false;
            }
            else
            {
                errors++;
            }
        }
        i++;
    }

    if (errors <= max_mistakes)
    {
        return true;
    }

    return false;
}