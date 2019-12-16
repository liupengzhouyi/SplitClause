//
// Created by 刘鹏 on 2019/12/16.
//
#include <fstream>
#include <string>
#include <codecvt>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int sum = 0;
// 最后保存的数据
string lastword[200000];

// 把一个wstring转化为string
std::string& to_string1(std::string& dest, std::wstring const & src)
{
    setlocale(LC_CTYPE, "");

    size_t const mbs_len = wcstombs(NULL, src.c_str(), 0);
    std::vector<char> tmp(mbs_len + 1);
    wcstombs(&tmp[0], src.c_str(), tmp.size());

    dest.assign(tmp.begin(), tmp.end() - 1);

    return dest;
}


// 把一个string转化为wstring
std::wstring& to_wstring1(std::wstring& dest, std::string const & src)
{
//   std::setlocale(LC_CTYPE, "");
    setlocale(LC_CTYPE, "zh_CN");

    size_t const wcs_len = mbstowcs(NULL, src.c_str(), 0);
    std::vector<wchar_t> tmp(wcs_len + 1);
    mbstowcs(&tmp[0], src.c_str(), src.size());

    dest.assign(tmp.begin(), tmp.end() - 1);

    return dest;
}


void digui(string str,int yourpinyingnumber, int nownumber, int word[][100]) {
    // cout << yourpinyingnumber << " - " << nownumber << endl;
    if (nownumber == yourpinyingnumber) {
        for (int i=1;i<word[nownumber-1][0];i++) {
            string newStr = "";
            int num = word[nownumber-1][i];
            newStr = to_string1(newStr, wstring(1,wchar_t(num)));
            string tempStr = str + newStr;
            cout << tempStr<< endl;
            lastword[sum] = tempStr;
            sum = sum + 1;
        }
    }
    else {
        for (int i=1;i<word[nownumber-1][0];i++) {
            string newStr = "";
            int num = word[nownumber-1][i];
            newStr = to_string1(newStr, wstring(1,wchar_t(num)));
            //cout << num << newStr << endl;
            string tempStr = str + newStr;
            digui(tempStr, yourpinyingnumber, nownumber + 1, word);

        }
    }

}

int main() {

    string yourpingying = "xiao xue sheng shui ping";
    string yourpingyings[1000];
    int yourpingyingnumber = 0;
    string pingying = "";
    for(int i=0;i<yourpingying.length();i++) {
        if (yourpingying[i] == ' ') {
            yourpingyings[yourpingyingnumber] = pingying;
            yourpingyingnumber = yourpingyingnumber + 1;
            pingying = "";
        } else{
            pingying = pingying + yourpingying[i];
        }
    }
    yourpingyings[yourpingyingnumber] = pingying;
    yourpingyingnumber = yourpingyingnumber + 1;
    pingying = "";
    /*for (int i=0;i<yourpingyingnumber;i++) {
        cout << yourpingyings[i] << endl;
    }*/


    // ---- 完成 拼音 分离


    string pingyings[500];
    string words[500];
    int tempwords[100][100];
    int pingyingnumber = 0;
    ifstream ifs;
    string s2;
    ifs.open("/Users/liupeng/CLionProjects/SplitClause/paly20191216/py2hzs.txt");            //将文件流对象与文件关联起来，如果已经关联则调用失败
    assert(ifs.is_open());    //若失败,则输出错误消息,并终止程序运行
    while (getline(ifs, s2))//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
    {
        //cout << s2 << endl;
        string pingying = "";
        for(int i=0;i<s2.length();i++) {
            if (s2[i] == ' ') {
                pingyings[pingyingnumber] = pingying;
                pingyingnumber = pingyingnumber + 1;
                break;
            }
            pingying = pingying + s2[i];
            for(int j=0;j<yourpingyingnumber;j++) {
                if (yourpingyings[j] == pingying) {
                    bool key = true;
                    string wordTemp = "";
                    for (int k=0;k<s2.length();k++) {
                        if (key == false) {
                            wordTemp = wordTemp + s2[k];
                        }
                        if (s2[k] == ' ') {
                            key = false;
                        }
                    }
                    words[j] = wordTemp;
                }
            }
        }
    }

    for (int i = 0; i < yourpingyingnumber; i++) {
        //string to wstring
        wstring Wstring2;
        Wstring2 = to_wstring1(Wstring2, words[i]);
        wstring strNumber2;
        wstring strWord2;
        int key2 = 0;
        string word2 = "";
        string number2 = "";
        tempwords[i][0] = 1;
        for (int i2=0;i2<Wstring2.length();i2++) {
            int num = (int)Wstring2[i2];
            word2 = to_string1(word2, wstring(1,wchar_t(num)));
            tempwords[i][i2+1] = (int) Wstring2[i2];
            tempwords[i][0] = tempwords[i][0] + 1;
            // 抽取wstring
            //cout << Wstring2[i2] << " - " << word2 << endl;
        }
    }

    /*for (int i=0;i<yourpingyingnumber;i++) {
        for (int j = 1; j < tempwords[i][0]; j++) {
            cout << tempwords[i][j] << " ";
        }
        cout << endl;
    }*/

    string str = "";
    digui(str,yourpingyingnumber,1,tempwords);
    cout << sum << endl;
    return 0;
}

