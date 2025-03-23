#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

#define M_PI 3.14159265358979323846

using namespace std;
// /* ------------------------------------------------------ 快速傅里叶变换 ------------------------------------------------------ */
// // 使用了以下FFT的优化手段：
// // 使用迭代版本
// // 使用位逆序置换
// // 使用蝴蝶操作
// // 使用平方法以减少一次DFT操作
// template <typename T>
// vector<T> &operator*=(vector<T> &A, vector<T> const &B)
// {
//     for (int i = 0; i < A.size(); ++i)
//         A[i] *= B[i];
//     return A;
// }

// class Solution
// {
//     int N;           // the target FFI array length, which is the pow of 2
//     vector<int> rev; // bit-reverse permutation

//     void FFT(vector<complex<double>> &A, int inv)
//     {
//         for (int i = 1; i < N; ++i)
//             if (i < rev[i])
//                 swap(A[i], A[rev[i]]); // reorder

//         for (int epoch = 1; epoch <= __builtin_ctz(N); ++epoch)
//         {                             // cnt of tail zero = iter times
//             const int n = 1 << epoch; // the length of sub array to merge
//             complex<double> wn(cos(2 * M_PI / n), sin(2 * M_PI / n * inv));
//             for (int i = 0; i < N; i += n)
//             {                                   // iter over sub arrays
//                 complex<double> w(1, 0), u, v;  // initial w for each sub array
//                 for (int j = 0; j < n / 2; ++j) // iter within each sub array (half)
//                     u = A[i + j],
//                     v = A[i + j + n / 2] * w,
//                     A[i + j] = u + v,
//                     A[i + j + n / 2] = u - v,
//                     w *= wn; // spin the omega
//             }
//         }
//         if (inv == -1)
//             for (auto &e : A)
//                 e /= N; // IFFT multiplier
//     }

// public:
//     string multiply(string num1, string num2)
//     {
//         if (num1 == "0" || num2 == "0")
//             return "0";                         // in case of final ans like "000"
//         int N1 = num1.size(), N2 = num2.size(); // highest order = N1+N2-2, min string len = N1+N2-1
//         N = 1;
//         while (N < N1 + N2 - 1)
//             N <<= 1; // N >= (N1 - 1) + (N2 - 1) + 1
//         vector<complex<double>> A(N, 0);
//         rev.resize(N);
//         for (int i = 0; i < N1; ++i)
//             A[i].real(num1[N1 - 1 - i] - '0'); // input with reverse order
//         for (int i = 0; i < N2; ++i)
//             A[i].imag(num2[N2 - 1 - i] - '0'); // input with reverse order
//         for (int i = 0; i < N; ++i)
//             rev[i] = (rev[i >> 1] >> 1) + ((i & 1) ? (N >> 1) : 0); // bit-reverse

//         FFT(A, 1), A *= A, FFT(A, -1); // FFT/IFFT

//         string ans(N1 + N2 - 1, '0');
//         int diff = 0, sum;
//         for (int i = 0; i < N1 + N2 - 1; ++i) // stream direction: FFT --> , ans <--
//             sum = diff + (A[i].imag() + 1e-8) / 2, ans[N1 + N2 - 2 - i] += sum % 10, diff = sum / 10;
//         if (diff)
//             ans.insert(0, to_string(diff));
//         return ans;
//     }
// };
// /* ------------------------------------------------------ 官方题解1：做加法 ------------------------------------------------------ */
// // 小学数学，列竖式
// class Solution {
// public:
//     string addStrings(string num1, string num2) {
//         string ans = "";
//         int i = num1.length() - 1, j = num2.length() - 1, add = 0, sum = 0;
//         while (i >= 0 || j >= 0 || add != 0) {
//             add += i >= 0 ? num1[i] - '0' : 0;
//             add += j >= 0 ? num2[j] - '0' : 0;
//             ans.push_back(add % 10 + '0');
//             add /= 10;
//             i--;
//             j--;
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
//     string multiply(string num1, string num2) {
//         if (num1 == "0" || num2 == "0") {
//             return "0";
//         }
//         string ans = "0";
//         int m = num1.size(), n = num2.size();
//         for (int i = n - 1; i >= 0; i--) {
//             string curr;
//             int add = 0;
//             for (int j = n - 1; j > i; j--) {
//                 curr.push_back('0');  //这里是为了补齐位数，需要注意的是curr.push_back('0')和curr.push_back(0)的区别
//             }
//             int y = num2.at(i) - '0';
//             for (int j = m - 1; j >= 0; j--) {
//                 int x = num1.at(j) - '0';
//                 add = x * y + add;
//                 curr.push_back(add % 10 + '0');
//                 add /= 10;
//             }
//             while (add != 0) {
//                 curr.push_back(add % 10 + '0');
//                 add /= 10;
//             }
//             reverse(curr.begin(), curr.end());
//             // for(auto &c : curr){
//             //     c += '0';
//             // }
//             ans = addStrings(ans, curr);
//         }
//         return ans;
//     }
// };
/* ------------------------------------------------------ 官方题解2：做乘法 ------------------------------------------------------ */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string num1 = "123", num2 = "456";
    string num3 = "615", num4 = "738";
    cout << Solution().multiply(num1, num2) << endl;
    // cout<< Solution().addStrings(num3, num4) << endl;
    return 0;
}
