#include <iostream>
using namespace std;
int maxVowels(string s, int k)
{
    int vowels[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    int max_vowel = 0;
    for (int i = 0; i < k; i++)
    {
        max_vowel += vowels[s[i] - 'a'];
    }
    int window = max_vowel;
    for (int i = k; i < s.size(); i++)
    {
        window += vowels[s[i] - 'a'];
        window -= vowels[s[i - k] - 'a'];
        max_vowel = max(max_vowel, window);
    }
    return max_vowel;
}

int main()
{
    int k;
    string s;
    cin >> k;
    cin >> s;
    cout << maxVowels(s, k);
}