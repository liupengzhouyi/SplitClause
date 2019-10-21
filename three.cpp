//
// Created by 刘鹏 on 2019/10/21.
//

#include <fstream>
#include <string>
#include <codecvt>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

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

class Node {

private:

    string str;

    int number;

public:

    const string &getStr() const {
        return str;
    }

    void setStr(string &str) {
        Node::str = str;
    }

    int getNumber() const {
        return number;
    }

    void setNumber(int number) {
        Node::number = number;
    }

    void addNum() {
        Node::number = this->getNumber() + 1;
    }

};

int main(int argc, char *argv[])
{
    // "3", "4", "5", "6", "7", "8"
    ifstream ifs;
    // 临时变量：记录临时字典的长度
    int longth = 0;

    Node nodeList[100000];
    string s;

    for (int k=250;k<=252;k++) {
        ifs.open("/Users/liupeng/CLionProjects/SplitClause/papers/papers/1 (" + to_string(k) + ").txt");   			//将文件流对象与文件关联起来，如果已经关联则调用失败
        assert(ifs.is_open());   	//若失败,则输出错误消息,并终止程序运行

        while(getline(ifs,s))		//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
        {
            //cout << longth << endl;
            // cout<<s<<endl;
            //string str1 = "这是一句临时字典长度太大，需要合并到总临时字典长度太大，需要合并到总字这是一句话，话，这是一这临时字临时字典长度太大，需要合并到总典长度太大，需要合并到总是一话，句话，这是一句话，这是一话，这是一这是一话，句话，这是一句句话，这是一句话，";
            string str1 = s;
            // string to wstring
            wstring wString = s2ws(str1);


            // 核心代码
            for (int i=0; i<wString.length()-1; i++) {
                // 获取词组
                //wstring newStr = wstring(1,wchar_t(wString[i])) + wstring(1,wchar_t(wString[i+1]));

                //string newStr = to_string((int)wString[i]);
                //string newStr = to_string((int)wString[i]) + "-" + to_string((int)wString[i+1]);
                string newStr = to_string((int)wString[i]) + "-" + to_string((int)wString[i+1]) + "-" + to_string((int)wString[i+2]);

                // cout << newStr << endl;
                bool key = false;
                for (int i=0; i<longth+1; i++){
                    if (nodeList[i].getStr() == newStr) {
                        nodeList[i].addNum();
                        key = true;
                        break;
                    }
                }
                if (!key) {
                    nodeList[longth].setStr(newStr);
                    nodeList[longth].setNumber(1);
                    longth ++;
                }
            }
        }
        ifs.close();
        //关闭文件输入流
    }



    for (int i=0;i<longth;i++) {
        string str = nodeList[i].getStr();
        string s1, ss1, sss1;
        int key = 0;
        for (int i=0; i<str.length(); i++) {
            if (str[i] != '-') {
                if (key == 0) {
                    s1 = s1 + str[i];
                } else if(key == 1) {
                    ss1 = ss1 + str[i];
                } else if(key == 2) {
                    sss1 = sss1 + str[i];
                }
            } else {
                key ++;
            }
        }
        stringstream stringstream1;
        stringstream1 << s1;
        int s2;
        stringstream1 >> s2;

        stringstream stringstream2;
        stringstream2 << ss1;

        int ss2;
        stringstream2 >> ss2;

        stringstream stringstream3;
        stringstream3 << sss1;
        int sss2;
        stringstream3 >> sss2;

        string char1 = ws2s(wstring(1,wchar_t(s2)));
        string char2 = ws2s(wstring(1,wchar_t(ss2)));
        string char3 = ws2s(wstring(1,wchar_t(sss2)));
        cout << char1 << char2 << char3 << " - " << nodeList[i].getNumber()<< endl;
        // cout << ssss << "-" << sssss << "+" << nodeList[i].getStr() << "-" << nodeList[i].getNumber() << " " << char1 << char2 << " " << nodeList[i].getNumber()<< endl;
    }
    cout << longth << endl;

    return 0;
}
