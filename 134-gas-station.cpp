/*
  Source : https://leetcode.com/problems/gas-station/
  Author : Alex Xu
  Date   : Jul 19, 2016
  Problem:
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

  Tag: Greedy
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;      // Start at the 0th station
        int current = 0;
        int tank = 0;       // Start with no gas

        // We will try starting at each station
        while (start < gas.size()) {
            tank += gas[current];   // Take the gas from the gas station
            tank -= cost[current];  // Travel to the next gas station

            // Check if we ran out of gas
            if (tank < 0) {
                if (current < start) // current is now behind start. If we're back to a station we already tried, we give up
                    break;

                tank = 0; // Reset the gas tank
                start = ++current; // Start at the next gas station instead
            } else {
                current = (current + 1) % gas.size(); // We're now at the next gas station
                if (current == start)  // If we're back to where we started, we completed the circuit
                    return start;
            }
        }
        
        return -1;
    }
};
