
#include <iostream>
#include <array>
#include <string>


using namespace std;
const int BLN = 49;
const int RNGSTART = 0;
const int ONE = 1;
const int TWO = 2;
const int RNGEND = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int RIGHTSIZE = 8;

namespace ariel
{
    // Define arrays for presets
    array<string, 4> Hat = {"     \n _===_", " ___ \n .....", "  _  \n  /_\\ ", " ___ \n (_*_)"};
    array<string, 4> Base = {" ( : ) ", " (\" \") ", " (___) ", " (   ) "};
    array<string, 4> LREye = {".", "o", "O", "-"};
    array<string, 4> Nose = {",", ".", "_", " "};
    array<string, 4> Torso = {"( : )", "(] [)", "(> <)", "(   )"};
    array<string, 4> LArm = {"<", "\\", "/", " "};
    array<string, 4> RArm = {">", "/", "\\", " "};

    string snowman(int p)
    {
        //p = HNLRXYTB
        string ans;

        //  Assign every digit of the presets to int
        string st = to_string(p);
        int h = (int)st[RNGSTART] - BLN;
        int n = (int)st[ONE] - BLN;
        int l = (int)st[TWO] - BLN;
        int r = (int)st[RNGEND] - BLN;
        int x = (int)st[FOUR] - BLN;
        int y = (int)st[FIVE] - BLN;
        int t = (int)st[SIX] - BLN;
        int b = (int)st[SEVEN] - BLN;
        exception e;

        if ((h > RNGEND || n > RNGEND || l > RNGEND || r > RNGEND || x > RNGEND || y > RNGEND || t > RNGEND || b > RNGEND) ||
            p < RNGSTART || h < RNGSTART || n < RNGSTART || l < RNGSTART || r < RNGSTART || x < RNGSTART || y < RNGSTART || t < RNGSTART || b < RNGSTART || st.length() != RIGHTSIZE)
        {
            throw e;
            return ans;
        }

        //  Add to ans by presets
        ans += " " + Hat.at(h) + " \n";

        if ((x + ONE) % TWO != RNGSTART)
        {
            // x is 1 or 3
            if ((y + ONE) % TWO != RNGSTART)
            {
                // y is 1 or 3
                ans += " (" + LREye.at(l) + Nose.at(n) + LREye.at(r) + ") \n"; // Add third line
                ans += LArm.at(x) + Torso.at(t) + RArm.at(y) + "\n";           // Add fourth line
            }
            else
            {
                // y is 2 or 4
                ans += " (" + LREye.at(l) + Nose.at(n) + LREye.at(r) + ")" + RArm.at(y) + "\n"; // Add third line
                ans += LArm.at(x) + Torso.at(t) + " \n";                                        // Add fourth line
            }
        }
        else
        {
            // x is 2 or 4
            if ((y + ONE) % TWO != RNGSTART)
            {
                // y is 1 or 3
                ans += LArm.at(x) + "(" + LREye.at(l) + Nose.at(n) + LREye.at(r) + ") \n"; // Add third line
                ans += " " + Torso.at(t) + RArm.at(y) + "\n";                              // Add fourth line
            }
            else
            {
                // y is 2 or 4
                ans += LArm.at(x) + "(" + LREye.at(l) + Nose.at(n) + LREye.at(r) + ")" + RArm.at(y) + "\n"; // Add third line
                ans += " " + Torso.at(t) + " \n";                                                           // Add fourth line
            }
        }

        ans += Base.at(b) + "\n"; // Add base - last line
        return ans;
    }

}


