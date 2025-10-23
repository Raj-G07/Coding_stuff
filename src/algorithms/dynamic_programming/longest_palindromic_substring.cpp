// Expand Around Center Approach

#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
     if(s.empty()) return "";

     int n = s.length();
     int start = 0 , maxLength = 1;

     auto expandAroundCenter = [&](int left,int right){
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return right - left - 1;
     };
     for(int i=0;i<n;i++){
        int len1 = expandAroundCenter(i,i);
        int len2 = expandAroundCenter(i,i+1);
        int len = max(len1,len2);
        if(len>maxLength){
            maxLength = len;
            start = i - (maxLength-1)/2;
        }
     }
     return s.substr(start,maxLength);
}

// Time Complexity: O(n^2) 

// Manacher's Algorithm solves the problem in linear time O(n). It uses a clever technique to calculate the longest palindrome centered at each index in the string.

string preprocess(const string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    return t;
}

string longestPalindrome_manacher(const string &s) {
    if (s.empty()) return "";
    
    string t = preprocess(s);
    int n = t.size();
    vector<int> P(n, 0);
    int C = 0, R = 0; // Center and Right boundary of current palindrome
    int maxLen = 0, centerIndex = 0;

    for (int i = 0; i < n; i++) {
        int mirror = 2 * C - i; // Mirror index of i around C

        if (i < R)
            P[i] = min(R - i, P[mirror]);

        // Expand around center i
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && t[i + P[i] + 1] == t[i - P[i] - 1])
            P[i]++;

        // Update center and right boundary
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        // Track maximum palindrome length
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Extract palindrome from original string
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

// Time & Space Complexity
// Time: O(n)
// Space: O(n)