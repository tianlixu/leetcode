/*
 Source : https://oj.leetcode.com/problems/compare-version-numbers/
 Author : Alex Xu
 Date   : Feb 05, 2015

 Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1;
        int pos1;
        int v2;
        int pos2;

        v1 = getVersion(version1, pos1);
        v2 = getVersion(version2, pos2);

        if (v1 > v2)
            return 1;
        if (v1 < v2)
            return -1;

        if (pos1 == string::npos && pos2 == string::npos)
            return 0;

        if (pos1 == string::npos)
            version1 = "";
        if (pos2 == string::npos)
            version2 = "";

        return compareVersion(version1.substr(pos1+1), version2.substr(pos2+1));
    }

    int getVersion(string version, int &pos) {
        pos = version.find('.');
        return atoi(version.substr(0, pos).c_str());
    }
};


int main()
{
    Solution sol;

    string v1 = "1.0";
    string v2 = "1";
    cout << sol.compareVersion(v1, v2) << endl;

    return 0;
}
