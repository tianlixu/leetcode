/*
  Source : https://leetcode.com/problems/guess-number-higher-or-lower-ii/
  Author : Alex Xu
  Date   : Jul 27, 2016
  Problem:
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:
    n = 10, I pick 8.

    First round:  You guess 5, I tell you that it's higher. You pay $5.
    Second round: You guess 7, I tell you that it's higher. You pay $7.
    Third round:  You guess 9, I tell you that it's lower. You pay $9.

    Game over. 8 is the number I picked.
    You end up paying $5 + $7 + $9 = $21.

Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

  Tag: DP
*/


/*
  Given any [i,j], we make a guess x:
  [i, ..., j] = [i, ..., x, ..., j]
  Your strategy is the best, but your luck is the worst.
  Vx = x + max(dp(i, x-1), dp(x+1, j))

  dp(i,j) = min(Vi, V(i+1), ... Vx ... V(j-1), Vj)

  A second thought, Vj is not needed at all:
  if dp(i,j) = Vj 
  then Vj is the smallest of (Vi, V(i+1), ... Vx ... V(j-1), Vj)
       Also Vj = j + dp(i, j-1) = j + V(j-1)
       which means
       Vj > V(j-1) 
       That is to say Vj is not the smallest
  Conclusion:
    dp(i,j) != Vj
        

  Example: 
      n=5


     0   1   2   3   4   5           len = 2->3->4->5
   +---+---+---+---+---+---+
 0 | 0 | 0 | 0 | 0 | 0 | 0 |
   +---+---+---+---+---+---+ 
 1 | 0 | 0 | 1 | 2 | 3 | 4 |     i=1        i = 1->2->...->(n-len+1)
   +---+---+---+---+---+---+       v
 2 | 0 | 0 | 0 | 1 | 2 | 3 |       2          j = len+i-1
   +---+---+---+---+---+---+       v
 3 | 0 | 0 | 0 | 0 | 1 | 2 |       3
   +---+---+---+---+---+---+       v
 4 | 0 | 0 | 0 | 0 | 0 | 1 |       4
   +---+---+---+---+---+---+  
 5 | 0 | 0 | 0 | 0 | 0 | 0 |
   +---+---+---+---+---+---+  


  Only need to fill the cell marked from 1 to 4
 
  len=2, fill the value for cell marked with 1
  len=3, fill the value for cell marked with 2
  len=4, fill the value for cell marked with 3
  len=5, fill the value for cell marked with 4

*/


class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > v(n+1, vector<int>(n+1, 0));

        for (int len=2; len<=n; len++) { // len [2,3,....n]
            for (int i=1; i<=(n-len+1); i++) { // row [1,2,...,n-len+1]
                int j = len+i-1; // col 
                v[i][j] = INT_MAX;
                for (int k=i; k<j; k++) {
                    v[i][j] = min(v[i][j], k + max(v[i][k-1], v[k+1][j]));
                }
            }
        }

        return v[1][n];
    }
};
