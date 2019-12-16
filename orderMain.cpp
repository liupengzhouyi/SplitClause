/*

#include <fstream>
#include <string>
#include <codecvt>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>
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

    ofstream f1("/Users/liupeng/CLionProjects/SplitClause/text3.txt");//打开文件用于写，若文件不存在就创建它
    if(!f1) {
        return 0;//打开文件失败则结束运行
    } else {
        ifstream ifs1;
        string s;
        ifs1.open("/Users/liupeng/CLionProjects/SplitClause/test11.txt");   			//将文件流对象与文件关联起来，如果已经关联则调用失败
        assert(ifs1.is_open());   	//若失败,则输出错误消息,并终止程序运行
        while(getline(ifs1,s))//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
        {
            string str1 = s;
            // string to wstring
            wstring Wstring = s2ws(str1);
            wstring strNumber;
            wstring strWord;
            int key = 0;
            string word = "";
            string number = "";
            for (int i=0;i<Wstring.length();i++) {
                if (Wstring[i] == '-') {
                    key = 1;
                    continue;
                } else {
                    if (key == 0) {
                        word = word + ws2s(wstring(1,Wstring[i]));
                    } else {
                        number = number + ws2s(wstring(1,Wstring[i]));
                    }
                }
            }
            stringstream stringstream;
            stringstream << number;
            int number1;
            stringstream >> number1;
            double aa = number1 + 0.0;
            // cout << word << "-" << number1 << endl;
            // ---------
            ifstream ifs2;
            string s2;
            ifs2.open("/Users/liupeng/CLionProjects/SplitClause/test13.txt");   			//将文件流对象与文件关联起来，如果已经关联则调用失败
            assert(ifs2.is_open());   	//若失败,则输出错误消息,并终止程序运行
            while(getline(ifs2,s2))//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
            {
                string str2 = s2;
                // string to wstring
                wstring Wstring2 = s2ws(str2);
                wstring strNumber2;
                wstring strWord2;
                int key2 = 0;
                string word2 = "";
                string number2 = "";
                for (int i2=0;i2<Wstring2.length();i2++) {
                    if (Wstring2[i2] == '-') {
                        key2 = 1;
                        continue;
                    } else {
                        if (key2 == 0) {
                            word2 = word2 + ws2s(wstring(1,Wstring2[i2]));
                        } else {
                            number2 = number2 + ws2s(wstring(1,Wstring2[i2]));
                        }
                    }
                }
                int number_2 = 0;
                for (int l=0;l<number2.length();l++) {
                    number_2 = number_2*10 + (int)(number2[l] - '0');
                }
                double bb = number_2 + 0.0;
                cout << aa << " - " << bb << endl;
                cout << word << "-" << number << " \\ " << word2 << "-" << number2 << " 数量比：" << aa/bb << " log(" << word << "/" << word2 << ")=" << log(aa/bb) << endl;
                f1<< word << "-" << number << " \\ " << word2 << "-" << number2 << " 数量比：" << aa/bb << " log(" << word << "/" << word2 << ")=" << log(aa/bb) << endl; //使用插入运算符写文件内容
                word2 = "";

            }
            ifs2.close();
            word = "";
        }

        ifs1.close();
        //关闭文件输入流
    }
    f1.close();
    return 0;
}*/
