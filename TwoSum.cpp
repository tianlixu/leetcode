#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::vector<int> v;

        for (int i=0; i<numbers.size()-1; ++i) {
            for (int j=i+1; j<numbers.size(); ++j) {
                if (numbers[i] + numbers[j] == target) {
                    v.push_back(i+1);
                    v.push_back(j+1);
                }                    
            }
        }

        return v;
    }
};


int main()
{
    int a[] = {2, 7, 9, 13};
    int length = sizeof(a) / sizeof(a[0]);

    std::vector<int> v(a, a+length);
    Solution s;
    std::vector<int> result = s.twoSum(v, 20);

    cout << "index1=" << result[0] << " Index2=" << result[1] << endl;
                       
    return 0;
}
