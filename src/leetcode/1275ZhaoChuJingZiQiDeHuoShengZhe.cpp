#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

/* --------------------------------------------- 自己写的 ------------------------------------------------ */
// class Solution
// {
// public:
//     string tictactoe(vector<vector<int>> &moves)
//     {
//         int re[3][3] = {0};
//         int s = 1;
//         string str[3] = {"A", "B", "Draw"};
//         for (int i = 0; i < moves.size(); i++)
//         {
//             re[moves[i][0]][moves[i][1]] = s;
//             s = -s;
//         }
//         // 逐行遍历
//         int sum = 0;
//         for (int i = 0; i < sizeof(re) / sizeof(re[0]); i++)
//         {
//             for (int j = 0; j < sizeof(re) / sizeof(re[0]); j++)
//             {
//                 sum += re[i][j];
//             }
//             if (sum == 3)
//             {
//                 return "A";
//             }
//             else if (sum == -3)
//             {
//                 return "B";
//             }
//             else
//             {
//                 sum = 0;
//             }
//         }
//         // 逐列遍历
//         for (int i = 0; i < sizeof(re) / sizeof(re[0]); i++)
//         {
//             for (int j = 0; j < sizeof(re) / sizeof(re[0]); j++)
//             {
//                 sum += re[j][i];
//             }
//             if (sum == 3)
//             {
//                 return "A";
//             }
//             else if (sum == -3)
//             {
//                 return "B";
//             }
//             else
//             {
//                 sum = 0;
//             }
//         }
//         // 对角线
//         for (int i = 0; i < sizeof(re) / sizeof(re[0]); i++)
//         {
//             for (int j = 0; j < sizeof(re) / sizeof(re[0]); j++)
//             {
//                 if (i == j)
//                 {
//                     sum += re[i][j];
//                 }
//             }
//         }
//         if (sum == 3)
//         {
//             return "A";
//         }
//         else if (sum == -3)
//         {
//             return "B";
//         }
//         else
//         {
//             sum = 0;
//         }
//         // 反对角线
//         for (int i = 0; i < sizeof(re) / sizeof(re[0]); i++)
//         {
//             for (int j = 0; j < sizeof(re) / sizeof(re[0]); j++)
//             {
//                 if (abs(i - j) == 2)
//                 {
//                     sum += re[i][j];
//                 }
//             }
//         }
//         sum = sum + re[1][1];
//         if (sum == 3)
//         {
//             return "A";
//         }
//         else if (sum == -3)
//         {
//             return "B";
//         }
//         else
//         {
//             sum = 0;
//         }
//         for(int i = 0; i < sizeof(re) / sizeof(re[0]); i++){
//             for(int j = 0; j < sizeof(re) / sizeof(re[0]); j++){
//                 if(re[i][j]==0){
//                     return "Pending";
//                 }
//             }
//         }
//         return "Draw";
//     }
// };

/* --------------------------------------------- 别人写的 ------------------------------------------------ */

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int tmp[3][3]{};
        for (int i = 1; auto & v : moves) {
            tmp[v[0]][v[1]] = i;
            i = -i;
        }
        if (abs(tmp[0][0] + tmp[1][1] + tmp[2][2]) == 3 || abs(tmp[0][2] + tmp[1][1] + tmp[2][0]) == 3) 
            return tmp[1][1] > 0 ? "A" : "B";
        for (int i = 0; i < 3; ++i)
			if (abs(tmp[i][0] + tmp[i][1] + tmp[i][2]) == 3 || abs(tmp[0][i] + tmp[1][i] + tmp[2][i]) == 3) 
                return tmp[i][i] > 0 ? "A" : "B";
		return moves.size() == 9 ? "Draw" : "Pending";
    }
};
int main(int argc, char const *argv[])
{
    vector<vector<int>> moves = {{0,0},{1,1}};
    cout << Solution().tictactoe(moves) << endl;
    return 0;
}
