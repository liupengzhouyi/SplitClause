//
// Created by 刘鹏 on 2019/10/21.
//

/*//
// Created by 刘鹏 on 2019/10/16.
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
    ifstream ifs1;
    // 临时变量：记录临时字典的长度
    int longth1 = 0;
    Node nodeList1[100000];
    ifstream ifs;
    int longth = 0;
    Node nodeList[100000];
    ifstream ifs2;
    // 临时变量：记录临时字典的长度
    int longth2 = 0;
    Node nodeList2[100000];
    stringstream stringstream1;
    stringstream stringstream2;
    stringstream stringstream3;
    string str1;
    string s;


    for (int k=250;k<=252;k++) {
        ifs1.open("/Users/liupeng/CLionProjects/SplitClause/papers/papers/1 (" + to_string(k) + ").txt");   			//将文件流对象与文件关联起来，如果已经关联则调用失败
        assert(ifs1.is_open());   	//若失败,则输出错误消息,并终止程序运行
        while(getline(ifs1,s))		//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
        {
            str1 = s;
            // string to wstring
            wstring wString = s2ws(str1);
            // 核心代码
            for (int i=0; i<wString.length(); i++) {
                // 获取词组
                string newStr = to_string((int)wString[i]);
                bool key = false;
                for (int i=0; i<longth1+1; i++){
                    if (nodeList1[i].getStr() == newStr) {
                        nodeList1[i].addNum();
                        key = true;
                        break;
                    }
                }
                if (!key) {
                    nodeList1[longth1].setStr(newStr);
                    nodeList1[longth1].setNumber(1);
                    longth1 ++;
                }
            }
        }
        ifs1.close();
        //关闭文件输入流
    }

    for (int i=0;i<longth1;i++) {
        string str = nodeList1[i].getStr();
        stringstream1 <<str;
        int ssss;
        stringstream1 >> ssss;
        string char1 = ws2s(wstring(1,wchar_t(ssss)));
        cout << char1 << " - " << nodeList1[i].getNumber()<< endl;
    }
    cout << longth1 << endl;

    for (int k=250;k<=252;k++) {
        ifs.open("/Users/liupeng/CLionProjects/SplitClause/papers/papers/1 (" + to_string(k) + ").txt");   			//将文件流对象与文件关联起来，如果已经关联则调用失败
        assert(ifs.is_open());   	//若失败,则输出错误消息,并终止程序运行
        while(getline(ifs,s))		//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
        {
            str1 = s;
            // string to wstring
            wstring wString = s2ws(str1);

            // 核心代码
            for (int i=0; i<wString.length()-1; i++) {
                // 获取词组
                string newStr = to_string((int)wString[i]) + "-" + to_string((int)wString[i+1]);
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
        string ss = "";
        string sss = "";
        bool key = false;
        for (int i=0; i<str.length(); i++) {
            if (!key) {
                if (str[i] == '-') {
                    key = true;
                } else {
                    ss = ss + str[i];
                }
            } else {
                sss = sss + str[i];
            }
        }


        stringstream1 <<ss;
        int ssss;
        stringstream1 >> ssss;

        stringstream2 << sss;
        int sssss;
        stringstream2 >> sssss;

        string char1 = ws2s(wstring(1,wchar_t(ssss)));
        string char2 = ws2s(wstring(1,wchar_t(sssss)));
        cout << char1 << char2 << " " << nodeList[i].getNumber()<< endl;
    }

    for (int k=250;k<=252;k++) {
        ifs2.open("/Users/liupeng/CLionProjects/SplitClause/papers/papers/1 (" + to_string(k) + ").txt");   			//将文件流对象与文件关联起来，如果已经关联则调用失败
        assert(ifs2.is_open());   	//若失败,则输出错误消息,并终止程序运行
        while(getline(ifs2,s))		//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
        {
            str1 = s;
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
                bool key1 = false;
                for (int i=0; i<longth2+1; i++){
                    if (nodeList2[i].getStr() == newStr) {
                        nodeList2[i].addNum();
                        key1 = true;
                        break;
                    }
                }
                if (!key1) {
                    nodeList2[longth2].setStr(newStr);
                    nodeList2[longth2].setNumber(1);
                    longth2 ++;
                }
            }
        }
        ifs2.close();
        //关闭文件输入流
    }



    for (int i=0;i<longth2;i++) {
        string str = nodeList2[i].getStr();
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

        stringstream1 << s1;
        int s2;
        stringstream1 >> s2;
        stringstream2 << ss1;
        int ss2;
        stringstream2 >> ss2;
        stringstream3 << sss1;
        int sss2;
        stringstream3 >> sss2;

        string char1 = ws2s(wstring(1,wchar_t(s2)));
        string char2 = ws2s(wstring(1,wchar_t(ss2)));
        string char3 = ws2s(wstring(1,wchar_t(sss2)));
        cout << char1 << char2 << char3 << " - " << nodeList2[i].getNumber()<< endl;
    }
    cout << longth2 << endl;

return 0;
}

*/