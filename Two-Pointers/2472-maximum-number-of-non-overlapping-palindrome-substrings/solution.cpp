#include <string>
#include <algorithm>

class Solution {
public:
    int maxPalindromes(std::string s, int k) {
        int n = s.length();
        int count = 0;
        int i = 0;

        while (i < n) {
            // Expand around center i for odd-length palindromes (or length k)
            // Expand around center i, i+1 for even-length palindromes
            int bestEnd = -1;

            // Check possible palindrome endpoints starting at or after index i
            for (int j = i; j < n; ++j) {
                // Try odd-length palindrome centered around j
                int l = j, r = j;
                while (l >= i && r < n && s[l] == s[r]) {
                    int len = r - l + 1;
                    if (len >= k) {
                        if (bestEnd == -1 || r < bestEnd) {
                            bestEnd = r;
                        }
                        break; // Shortest valid palindrome found for this center
                    }
                    l--;
                    r++;
                }

                // Try even-length palindrome centered around j, j+1
                l = j;
                r = j + 1;
                while (l >= i && r < n && s[l] == s[r]) {
                    int len = r - l + 1;
                    if (len >= k) {
                        if (bestEnd == -1 || r < bestEnd) {
                            bestEnd = r;
                        }
                        break; // Shortest valid palindrome found for this center
                    }
                    l--;
                    r++;
                }

                // If we found a valid palindrome ending at or before current j, 
                // we can take it greedily
                if (bestEnd != -1 && j >= bestEnd) {
                    break;
                }
            }

            if (bestEnd != -1) {
                count++;
                i = bestEnd + 1; // Move past the selected palindrome
            } else {
                break;
            }
        }

        return count;
    }
};
