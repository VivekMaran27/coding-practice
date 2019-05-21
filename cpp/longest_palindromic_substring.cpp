#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    string longestPalindrome(string s) {
        
        int length = s.length();
        int start = 0;
        int end = 0;
        std::vector<int> start_end_idx_for_char;

        // std::cout<<"longestPalindrome++"<<endl;
        /* Loop through each character in string */
        for(int i = 0; i< length; ++i)
        {
            /* Assume this character is middle of an odd palindromic substring */
            start_end_idx_for_char= longestPalindromeForIndex(s, i, i);
            /* If length of the substring found is greater than current, update */
            if((end -start) < (start_end_idx_for_char[1] - start_end_idx_for_char[0]))
            {
                start = start_end_idx_for_char[0];
                end = start_end_idx_for_char[1] ;
            }
            
            /* Assume this character is middle of an even palindromic substring */
            start_end_idx_for_char  = longestPalindromeForIndex(s,i, i+1);
            /* If length of the substring found is greater than current, update */
            if((end -start) <  (start_end_idx_for_char[1] - start_end_idx_for_char[0]))
            {
                start = start_end_idx_for_char[0];
                end = start_end_idx_for_char[1] ;
            }
        }
        // std::cout<<"longestPalindrome--"<<endl;
        return s.substr(start, (end-start+1));
    }
    
    std::vector<int> longestPalindromeForIndex(string s, int left, int right) 
    {
        int length = s.length();
        std::vector<int> result;
        int start = left;
        int end = right;
     
        // std::cout<<"longestPalindromeForIndex++"<<endl;
        if((length == 0) || (right >= length) || (left < 0))
        {
            result.push_back(0);
            result.push_back(0);
        }

        /* Keep checking left and right until a mismatch or out of bounds */
        while((start >= 0) && (end < length) && (s[start] == s[end]))
        {
            --start;
            ++end;
        }
        result.push_back(start+1);
        result.push_back(end-1);
        // std::cout<<"Middle Char "<<s[left] <<" "<<start+1<<" "<<end-1<<endl;
        // std::cout<<"longestPalindromeForIndex--"<<endl;
        return result;
    }
};

int main() {
  std::cout << "Hello World!\n";
  Solution solution;
  std::string test = "babad";
  cout<<"longestPalindrome of "<<test<<" is: "<<
  solution.longestPalindrome(test);
}
