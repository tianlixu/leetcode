/*
 Source : https://oj.leetcode.com/problems/add-binary/
 Author : Alex Xu
 Date   : April 29, 2018
 Problem:

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */

class Solution {
    public String addBinary(String a, String b) {
        int alen = a.length();
        int blen = b.length();
        int len = Math.max(alen, blen);
        char[] buf = new char[len];

        int av = 0;
        int bv = 0;
        int cv = 0;

        for (int i=1; i<=len; i++) {
            av = i <= alen ? a.charAt(alen - i) - '0' : 0;
            bv = i <= blen ? b.charAt(blen - i) - '0' : 0;
            switch(av + bv + cv){
            case 0: buf[len-i] = '0'; cv = 0; break;
            case 1: buf[len-i] = '1'; cv = 0; break;
            case 2: buf[len-i] = '0'; cv = 1; break;
            case 3: buf[len-i] = '1'; cv = 1; break;
            }
        }

        return cv == 1 ? "1" + new String(buf) : new String(buf);
    }
}
