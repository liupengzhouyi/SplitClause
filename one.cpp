/*
//
//
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
    ifstream ifs1;
    // 临时变量：记录临时字典的长度
    int longth1 = 0;

    Node nodeList1[100000];
    string s;

    for (int k=250;k<=252;k++) {
        ifs1.open("/Users/liupeng/CLionProjects/SplitClause/papers/papers/1 (" + to_string(k) + ").txt");   			//将文件流对象与文件关联起来，如果已经关联则调用失败
        assert(ifs1.is_open());   	//若失败,则输出错误消息,并终止程序运行

        while(getline(ifs1,s))		//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
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

                string newStr = to_string((int)wString[i]);
                //string newStr = to_string((int)wString[i]) + "-" + to_string((int)wString[i+1]);
                // string newStr = to_string((int)wString[i]) + "-" + to_string((int)wString[i+1]) + "-" + to_string((int)wString[i+2]);

                // cout << newStr << endl;
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

    ofstream f1("/Users/liupeng/CLionProjects/SplitClause/test1.txt");//打开文件用于写，若文件不存在就创建它
    if(!f1) {
        return 0;   //打开文件失败则结束运行
    } else {
        for (int i=0;i<longth1;i++) {
            string str = nodeList1[i].getStr();
            stringstream stringstream1;
            stringstream1 <<str;
            int ssss;
            stringstream1 >> ssss;
            string char1 = ws2s(wstring(1,wchar_t(ssss)));
            cout << char1 << "-" << nodeList1[i].getNumber() << endl;
            // cout << ssss << "-" << sssss << "+" << nodeList[i].getStr() << "-" << nodeList[i].getNumber() << " " << char1 << char2 << " " << nodeList[i].getNumber()<< endl;
            f1<< char1 << "-" << nodeList1[i].getNumber() <<endl; //使用插入运算符写文件内容
        }
        cout << longth1 << endl;
    }
    f1.close();

    return 0;
}

*/
