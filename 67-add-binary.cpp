/*
 Source : https://oj.leetcode.com/problems/add-binary/
 Author : Alex Xu
 Date   : Jan 09, 2015
 Problem:

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */

#include <iostream>
#include <bitset>

using namespace std;

string addBin(string a, string b)
{
    std::bitset<32> aBS(a);
    std::bitset<32> bBS(b);

    int sum = aBS.to_ulong() + bBS.to_ulong();

    std::bitset<32> sumBS(sum);
    string s = sumBS.to_string();

    int pos = s.find_first_not_of('0');
    return s.substr(pos);
}

class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        
        const char* p1 = a.c_str();
        const char* p2 = b.c_str();
        int l1 = a.length();
        int l2 = b.length();

        /// make sure len(s1) > len(s2)
        if (l1 < l2) {
            std::swap(p1, p2);
            std::swap(l1, l2);
        }

        int carry = 0;
        int sum;
        int i = 0;
        while (i < l2) {
            sum = p1[l1-1-i] - '0' + p2[l2-1-i] - '0' + carry;
            s += sum % 2 + '0';
            carry = sum >= 2 ? 1 : 0;
            ++i;
        }

        while (i < l1) {
            sum = p1[l1-1-i] - '0' + carry;
            s += sum % 2 + '0';
            carry = sum >= 2 ? 1 : 0;
            ++i;
        }

        if (carry == 1)
            s += '1';

        std::reverse(s.begin(), s.end());

        return s;
    }    

    string addBinary1(string a, string b) {
        uint ia = str2uint(a);
        uint ib = str2uint(b);
        uint sum = ia + ib;

        return uint2bin(sum);
    }

    uint str2uint(string s) {
        uint n = 0;
        for (int i=0; i<s.length(); ++i) {
            n = n*2 + s[i] - '0';
        }

        return n;
    }

    string uint2bin(unsigned int n) {
        string s;;
        unsigned int mask = 0x80000000;

        while (mask) {
            if (mask & n) {
                s += '1';
            } else {
                if (!s.empty())
                    s += '0';
            }
            mask >>= 1;
        }

        return s.empty() ? "0" : s;
    }
};

int main()
{
    string a = "11";
    string b = "1";
    Solution s;
    cout << s.addBinary(a, b) <<endl;
    a =	"10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    //Expected:	"110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000
    cout << s.addBinary(a, b) <<endl;
    
    a = '0';
    b = '0';
    cout << s.addBinary(a, b) <<endl;

    return 0;
}
