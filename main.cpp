//
// Created by 刘鹏 on 2019/10/16.
//
#include <fstream>
#include <string>
#include <codecvt>
#include <iostream>
#include <map>
#include <vector>

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

class MyList {
private:
    Node *myNode;
    MyList *next;

public:
    Node *getMyNode() const {
        return myNode;
    }

    void setMyNode(Node *myNode) {
        MyList::myNode = myNode;
    }

    MyList *getNext() const {
        return next;
    }

    void setNext(MyList *next) {
        MyList::next = next;
    }

};

int main(int argc, char *argv[])
{
    // "3", "4", "5", "6", "7", "8"
    string strs[10] = {"1", "2"};
    ifstream ifs;
    int longth = 0;

    Node nodeList[100000];
    string s;

    ifs.open("/Users/liupeng/CLionProjects/SplitClause/papers/papers/1 (1).txt");   			//将文件流对象与文件关联起来，如果已经关联则调用失败
    assert(ifs.is_open());   	//若失败,则输出错误消息,并终止程序运行

    while(getline(ifs,s))		//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
    {
        cout << longth << endl;
        cout<<s<<endl;
        string str1 = "这是一句临时字典长度太大，需要合并到总临时字典长度太大，需要合并到总字这是一句话，话，这是一这临时字临时字典长度太大，需要合并到总典长度太大，需要合并到总是一话，句话，这是一句话，这是一话，这是一这是一话，句话，这是一句句话，这是一句话，";
        str1 = s;

        // string to wstring
        wstring wString = s2ws(str1);

        // 临时变量：记录临时字典的长度


        // 核心代码
        for (int i=0; i<wString.length()-1; i++) {
            // 获取词组
            //wstring newStr = wstring(1,wchar_t(wString[i])) + wstring(1,wchar_t(wString[i+1]));
            string newStr = to_string((int)wString[i]) + "-" + to_string((int)wString[i+1]);
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

    for (int i=0;i<longth;i++) {
        string str = nodeList[i].getStr();
        string ss = "";
        string sss = "";
        bool key = false;
        for (int i=0;i<str.length();i++) {
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
        // cout << sss << " - " << ss << endl;
        cout << nodeList[i].getStr() << "-" << nodeList[i].getNumber() << endl;
    }

    return 0;
}

// 编码

// 统计

// 解码


