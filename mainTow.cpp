/*
#include <fstream>
#include <string>
#include <codecvt>
#include <iostream>
#include <map>

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

// 全局变量
map<int, int> mapAll;

int main(int argc, char *argv[])
{
    string str = "这是一句临时字典长度太大，需要合并到总临时字典长度太大，需要合并到总字这是一句话，话，这是一这临时字临时字典长度太大，需要合并到总典长度太大，需要合并到总是一话，句话，这是一句话，这是一话，这是一这是一话，句话，这是一句句话，这是一句话，";

    // string to wstring
    wstring wString = s2ws(str);

    // 临时变量
    map<int, int> tempMap;

    // 临时变量：记录临时字典的长度
    int longth = 0;

    // 核心代码
    for (int i=0;i<wString.length();i++) {
        //判断是否存在
        map<int, int>::iterator l_it;;
        l_it = tempMap.find(wString[i]);
        if (l_it == tempMap.end()) {
            // 加入字典
            tempMap.insert(pair<int, int>(wString[i], 1));
            // 长度加一
            longth = longth + 1;
        }
        else {
            int number = l_it->second;
            tempMap.erase(wString[i]);
            tempMap.insert(pair<int, int>(wString[i], 1 + number));
        }
        if (longth >= 100000) {
            cout << "临时字典长度太大，需要合并到总字典中" << endl;
        }
    }

    for(auto&it:tempMap){
        cout << ws2s(wstring(1,wchar_t(((int)(it.first))))) << " - " << it.first << " : " << it.second << endl;
    }

    return 0;
}*/
