#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    bool v4flag = true;
    bool v6flag = true;
    int start = 0;
    int end = 0;
    int pointNum = 0;
    int MNum = 0;

public:
    bool isValidIPv4(string s, int start, int end)
    {
        if (start >= end)
        {
            return false;
        }
        if (s[start] == '0' && start != end - 1)
        {
            return false;
        }
        int num = 0;
        for (int i = start; i < end; i++)
        {
            if (s[i] > '9' || s[i] < '0')
            {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255)
            {
                return false;
            }
        }
        return true;
    }
    bool isValidIPv6(string s, int start, int end)
    {
        if ((end - start) < 1 || (end - start) > 4)
        {
            return false;
        }
        for (int i = start; i < end; i++)
        {
            if ((s[i] > '9' || s[i] < '0') && (s[i] > 'f' || s[i] < 'a') &&
                (s[i] > 'F' || s[i] < 'A'))
            {
                return false;
            }
        }
        return true;
    }
    string validIPAddress(string queryIP)
    {
        for (int i = 0; i < queryIP.size(); i++)
        {
            if (queryIP[i] != '.')
            {
                end++;
            }
            else
            {
                pointNum++;
                if (!isValidIPv4(queryIP, start, end))
                {
                    v4flag = false;
                    break;
                }
                end = i + 1;
                start = i + 1;
            }
        }
        if (!isValidIPv4(queryIP, start, end) || pointNum != 3)
        {
            v4flag = false;
        }
        start = 0;
        end = 0;
        for (int i = 0; i < queryIP.size(); i++)
        {
            if (queryIP[i] != ':')
            {
                end++;
            }
            else
            {
                MNum++;
                if (!isValidIPv6(queryIP, start, end))
                {
                    v6flag = false;
                    break;
                }

                end = i + 1;
                start = i + 1;
            }
        }
        if (!isValidIPv6(queryIP, start, end) || MNum != 7)
        {
            v6flag = false;
        }

        if (v4flag && !v6flag)
        {
            return "IPv4";
        }
        else if (v6flag && !v4flag)
        {
            return "IPv6";
        }
        else
        {
            return "Neither";
        }
    }
};

int main(int argc, char const *argv[])
{
    string queryIP = "192.0.0.1";
    // cout << Solution().isValidIPv6(queryIP, 29, 33) << endl;
    cout << Solution().validIPAddress(queryIP) << endl;
    return 0;
}
