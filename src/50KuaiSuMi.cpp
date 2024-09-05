#include <iostream>

using namespace std;
class Solution {
public:
    double fastPow(double x, long long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0)
            return 1.0 / fastPow(x, -n);

        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        return fastPow(x, static_cast<long long>(n));
    }
};

int main(int argc, char *argv[])
{
    double x= 2.00000;
    cout<<Solution().myPow(x, 2)<<endl;
    return 0;
}
