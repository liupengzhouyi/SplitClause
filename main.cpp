#include <fstream>
#include <string>
#include <codecvt>
#include <iostream>

using namespace std;

std::wstring s2ws(const std::string& str)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.from_bytes(str);
}

std::string ws2s(const std::wstring& wstr)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}

int main(int argc, char *argv[])
{
    std::wstring wstr = L"不回家拿来不";

    for (int i=0;i<wstr.length();i++) {
        cout << wstr[i] << endl;
    }

    int number = 22238;
    string s = ws2s(wstring(1,wchar_t(number)));
    //string s = ws2s(wstring(1,wstr[2]));
    cout << s << endl;

    return 0;
}


