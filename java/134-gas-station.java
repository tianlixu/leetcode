/*
  Source : https://leetcode.com/problems/gas-station/
  Author : Alex Xu
  Date   : August 02, 2017
  Problem:
  There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

  You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

  Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

  Note:
  The solution is guaranteed to be unique.

  Tag: Greedy

  1. If total gas is greater than total cost, there is a solution,
     a[i] = gas[i] - cost[i]
  2. The start point can be the one that
     2.1 is right after the minmum element in a[i]
     2.2 but it must be a non-negative value
    [-2, -2, -2, 3, 3]  => i=3
    [-1, 2, -1] => i=2, but a[2] = -1, which is negative, so move on i++ until a[i] is non-negative, then i=1


    [6, -3, -3, -2, 4, 1, -5, 2], can start from a[4]=4 or a[7]=2
*/

public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        for (int i=0; i<gas.length; i++)
            gas[i] -= cost[i];

        int sum = 0;
        int minIndex = 0;
        for (int i=0; i< gas.length; i++) {
            sum += gas[i];
            if (gas[i] <= gas[minIndex])
                minIndex = i;
        }

        if (sum >= 0) { // there is a solution
            int index = (minIndex + 1) % gas.length;
            while (gas[index] < 0)
                index ++;
            return index;
        }

        return -1;
    }
}
