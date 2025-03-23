#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int prev_end = points[0][1], ans = 1;
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] <= prev_end){
                prev_end = min(points[i][1], prev_end);
            }else{
                ans++;
                prev_end = points[i][1];
            }
        }
        return ans;
    }
};

int main(){
    Solution su;
    vector<vector<int>>points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "result :" << su.findMinArrowShots(points) << endl;
    return 0;
}