#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        enum direction
        {
            North,
            South,
            West,
            East
        };
        int x = 0, y = 0;
        direction d = North;
        for (int i = 0; i < 4; i++)
        {
            for (char c : instructions)
            {
                if (c == 'G')
                {
                    switch (d)
                    {
                    case North:
                        y++;
                        break;
                    case South:
                        y--;
                        break;
                    case West:
                        x--;
                        break;
                    case East:
                        x++;
                        break;
                    }
                }
                if (c == 'L')
                {
                    switch (d)
                    {
                    case North:
                        d = West;
                        break;
                    case South:
                        d = East;
                        break;
                    case West:
                        d = South;
                        break;
                    case East:
                        d = North;
                        break;
                    }
                }
                if (c == 'R')
                {
                    switch (d)
                    {
                    case North:
                        d = East;
                        break;
                    case South:
                        d = West;
                        break;
                    case West:
                        d = North;
                        break;
                    case East:
                        d = South;
                        break;
                    }
                }
            }
        }
        if (x == 0 && y == 0)
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string ins = "GL";
    Solution su;
    cout << su.isRobotBounded(ins) << endl;
    return 0;
}
