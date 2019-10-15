/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <io.h>
*/
/*#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <wsman.h>*//*



using namespace std;


string UTF8ToGB(const char* str)
{
    string result;
    WCHAR *strSrc;
    LPSTR szRes;

    //获得临时变量的大小
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //获得临时变量的大小
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete[]strSrc;
    delete[]szRes;

    return result;
}

// 去空格
void trim(string &s)
{
    if( !s.empty() )
    {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }

}

// 写文件
void save(string path, string str) {
    ofstream out;
    // out.open("C:\\Users\\liupeng\\IdeaProjects\\JavaTools\\src\\OpenFile\\test11.txt",  std::ios::out | ios::app);
    out.open(path, std::ios::out | ios::app);
    out << str << "\n";
    out.close();
}

// 分割
string getClause(string path, string str) {
    string newString = "";
    string string = "";
    int insen=1;
    for(int i=0;i<str.length();i++){
        if(str[i]&128){ //判断是汉字，gb2312汉字两个字节，同时输出两个字节
            //cout<<str[i]<<str[i+1];
            newString = newString + str[i] + str[i+1];
            i++;
        }else{//否则不是汉字直接输出
            newString = newString + str[i];
            // cout<<str[i]<<' ';
        }

        //“ 判断为上引号
        if(str[i-1]==-95&&str[i]==-80){
            insen=1;  //在一个句子里
        }
        //”判断为下引号
        if(str[i-1]==-95&&str[i]==-79){
            // 。判断为句号，一个句子换行
            if(str[i+1]==-95&&str[i+2]==-93){
                continue;
            }
            insen=0;  //此句子结束
            save(path, newString);
            newString = "";
            //cout<<endl;
        }

        // 。判断为句号，一个句子换行
        if(str[i-1]==-95&&str[i]==-93){
            //cout << newString << endl;
            save(path, newString);
            newString = "";
            //cout<<endl;
        }
            // ?判断为问号
        else if(str[i-1]==-93&&str[i]==-65){
            //cout << newString << endl;
            save(path, newString);
            newString = "";
            //cout<<endl;
        }
            // !判断为感叹号
        else if(str[i-1]==-93&&str[i]==-95){
            //cout << newString << endl;
            save(path, newString);
            newString = "";
            //cout<<endl;
        }
    }
    return string;
}

void paly(string ordPath, string newPath) {
    ifstream in;
    // in.open("C:\\Users\\liupeng\\IdeaProjects\\JavaTools\\src\\OpenFile\\test.txt");
    in.open(ordPath);
    string s;
    string tempStr = "";
    while (std::getline(in, s))
    {
        string str = UTF8ToGB(s.c_str()).c_str();
        //对每一行进行操作。
        trim(str);
        tempStr = tempStr + str;
        // 分割
        tempStr = getClause(newPath, tempStr);
    }
    in.close();
}




const char *to_search="C:\\Users\\liupeng\\CLionProjects\\SplitClause\\papers\\papers\\*.txt";        //欲查找的文件，支持通配符

int main()
{
    long handle;                                    //用于查找的句柄
    struct _finddata_t fileinfo;                    //文件信息的结构体
    handle=_findfirst(to_search,&fileinfo);         //第一次查找
    if(-1==handle)
        return -1;
    printf("%s\n",fileinfo.name);              //打印出找到的文件的文件名
    while(!_findnext(handle,&fileinfo))               //循环查找其他符合的文件，知道找不到其他的为止
    {
        // printf("%s\n",fileinfo.name);

        string ordPath = "C:\\Users\\liupeng\\CLionProjects\\SplitClause\\papers\\papers\\" + string(fileinfo.name);
        string newPath = "C:\\Users\\liupeng\\CLionProjects\\SplitClause\\papers\\newPapers\\" + string(fileinfo.name);
        //cout << ordPath << endl;
        //cout << newPath << endl;
        paly(ordPath,newPath);

    }
    _findclose(handle);

    system("pause");
    return 0;
}
*/
