/**
 *  Author: Moamen Nasser Saad
 *  Date : 06/23/2025
 */
#include<iostream>
#include<map>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;


/**
 * @brief Get the Most Freq Char Using Vector object
 * 
 * @param s 
 * @return pair<char, int> 
 */
pair<char, int> GetMostFreqCharUsingVector(const string &s)
{
    // array of only low characters
    vector<int> freq(26, 0);
    // count frequency of each character
    for(char c : s)
    {
        freq[c - 'a']++;
    }

    int maxFreq = 0;
    // assume tha the first character is the maximum
    char maxChar = 'a';

    for(int i = 0 ; i < 26 ; i++)
    {
        if(freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            maxChar = 'a' + i;
        }
    }
    return {maxChar, maxFreq};
}

/**
 * @brief Get the Most Freq Char object and its occurrences
 *
 * @param s string
 * @return pair<char, int>
 */
pair<char, int> GetMostFreqChar(string s)
{
    int n = s.length();
    // vector<int>v;

    map<char, int>mpp;
    pair<char, int> pa;
    for (int i = 0; i < n; i++)
    {
      mpp[s[i]]++;
    }

    // Create a multimap where values are keys and keys are values
    multimap<int, char> sortedByValueMap;
    for (const auto& pair : mpp) 
    {
        sortedByValueMap.insert(make_pair(pair.second, pair.first));
    }

    for(auto &element : sortedByValueMap)
    {
       cout << element.second << " " <<element.first << "\n";
    }
    auto last = sortedByValueMap.rbegin();
    return {last->second, last->first};
}


int main()
{

    string s = "babaccccccccfqqqqqqqqqqqqqqqqqqqqqqqqqqqqdegergdfgbfbfcxvbsdfergtrhtgnqqqqqqqqqqfcbdxvdsgccccccbabcb";
    string s1 = "sajnmdcjfreklmdcsklnffgkljgsfdhgkilwerthpewifovkndsklgnvsafkjqfhyrsaknfvcwuikqgfthuikajhsnklfaaasnfkjfhdiaoaaasklnckcsaaaavckjefsaasmanklmdcnsakljsaaaaaksndkjsahwuiqpnsacaaa";
    auto[ch, count] =  GetMostFreqChar(s);
    
    cout << "Result of the function is: " << ch << " " << count << "\n";
    
    return 0;
}