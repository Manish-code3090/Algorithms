#include <vector>
#include <string>
#include <iostream>

int repeatedStringMatch(std::string a, std::string b) {
        int bl = b.size();
        std::vector<int>lps(bl,0) ;
        int l= 0;
        for(int i = 1; i< b.size(); i++)
        {
          
                while( l>0 && b[i] != b[l])
                {
                    l = lps[l-1];
                }

            if(b[l] == b[i])
            {
                l++;
            }
                lps[i] = l;
            
        }
        
        std::string s = a;
        int repitation = 1;
       while(s.size() < b.size())
       {
        s+= a;
        repitation++;
       }
           int j = 0;
        int i = 0;
        int maxRep = repitation+1;
        while(j<bl)
        {
            if(i == s.size())
            {
                if(repitation == maxRep) return -1;
                s+= a;
                repitation++;
            }
            if(b[j] == s[i])
            {
                j++;
                i++;
            }else if(j>0)
            {
                j = lps[j-1];
            }else
            {
                i++;
            }
        }
        return repitation;
    }

    int main() {
       int result = repeatedStringMatch("abcd", "cdabcdab");
       std::cout << "Result: " << result << std::endl; // Output: Result: 3
        return 0;
    }