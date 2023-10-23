#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

// Function to compare two strings based on length and lexicographical order
bool compareStrings(string &a, string &b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }
    else
    {
        return a.size() < b.size();
    }
}

// Function to find the longest and second longest compound words
void findLongestCompoundWords()
{
    vector<string> words;
    string currentWord;
    unordered_set<string> wordSet;

    // Read words from standard input and store them in a vector and a set
    while (cin >> currentWord)
    {
        words.push_back(currentWord);
        wordSet.insert(currentWord);
    }

    string longestCompoundWord, secondLongestCompoundWord;
    longestCompoundWord = secondLongestCompoundWord = "";

    // Sort the words based on length and lexicographical order
    sort(words.begin(), words.end(), compareStrings);

    int currentIndex = words.size() - 1;
    vector<bool> isCompound(1001);
    // Loop through the sorted words to find the longest and second longest compound words
    while (currentIndex >= 0)
    {
        string &currentWord = words[currentIndex--]; // Get the current word
        int wordLength = currentWord.size();
        string temp;
        fill(isCompound.begin(), isCompound.end(), false);
        // Check for compound word possibilities by iterating over word substrings
        for (int i = 0; i < wordLength; i++)
        {
            temp = "";
            for (int j = 0; j <= i; j++)
            {
                if (wordSet.count(currentWord.substr(j, i - j + 1)))
                {
                    if (j == 0 && i != wordLength - 1)
                    {
                        isCompound[i] = true;
                        break;
                    }
                    else if (j > 0 && isCompound[j - 1])
                    {
                        isCompound[i] = true;
                        break;
                    }
                }
            }
        }
        // If the current word is a compound word, update the longest and second longest
        if (isCompound[wordLength - 1])
        {
            if (longestCompoundWord.empty())
            {
                longestCompoundWord = currentWord;
            }
            else if (secondLongestCompoundWord.empty())
            {
                secondLongestCompoundWord = currentWord;
            }
            else
            {
                // Exit the loop early if both longest and second longest are found
                break;
            }
        }
    }

    // Print the results
    cout << "Longest Compound Word: " << longestCompoundWord << endl;
    cout << "Second Longest Compound Word: " << secondLongestCompoundWord;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input_02.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int testCases = 1, i = 1;
    auto start = high_resolution_clock::now();

    while (testCases--)
    {
        i++;
        findLongestCompoundWords();
        cout << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "taken Time to process input file: " << duration.count() << " milliseconds";
}
