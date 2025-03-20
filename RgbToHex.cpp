#include <string>

using namespace std;
class RGBToHex
{
public:
    static string rgb(int r, int g, int b);
    static string toHex(int color);
};

string RGBToHex::rgb(int r, int g, int b)
{
    return toHex(r) + toHex(g) + toHex(b);
}

string RGBToHex::toHex(int color)
{
    string hex;
    if (color <= 0)
        return "00";
    if (color >= 255)
        return "FF";
    if (color < 10)
        return "0" + to_string(color);
    if (color < 255)
    {
        int fi, sec;
        sec = color / 16;
        fi = (color % (16 * sec));
        if (sec >= 10)
            hex = char(55) + sec;
        else
            hex = to_string(sec);
        if (fi >= 10)
            hex += char(55) + fi;
        else
            hex += to_string(fi);

    }
    return hex;
}