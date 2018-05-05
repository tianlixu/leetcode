/*
  Source : https://leetcode.com/problems/triangle/
  Author : Alex Xu
  Date   : Jul 13, 2016
  Problem:
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

/*
  top-down solution. You can also use bottom-up solution which modifies the input triangle and return triangle[0][0] at the end.
 */                                      
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ret = 0;
        
        vector<int> lastmini = triangle[0];
        vector<int> currentmini;
        
        for (int i=1; i<triangle.size(); ++i) {
            vector<int>& row = triangle[i];
            
            for (int j=0; j<row.size(); ++j) {
                int mini;
                if (j == 0)
                    mini = lastmini[j] + row[j];
                else if (j == row.size()-1)
                    mini = lastmini[j-1] + row[j];
                else
                    mini = min(lastmini[j-1], lastmini[j]) + row[j];
                currentmini.push_back(mini);
            }
            
            lastmini = currentmini;
            currentmini.clear();
        }
        
        ret = *std::min_element(lastmini.begin(), lastmini.end());
        return ret;
    }
};

/*
 time exceeded for a long input
 but functionally it is correct
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return miniPath4Point(triangle, 0, 0);
    }
    
    int miniPath4Point(vector<vector<int>>& triangle, int row, int column) {
        if (row == triangle.size()-1)
            return triangle[row][column];
        
        int miniChildLeft = miniPath4Point(triangle, row+1, column);
        int miniChildRight = miniPath4Point(triangle, row+1, column+1);
        return triangle[row][column] + min(miniChildLeft, miniChildRight);
    }
};
