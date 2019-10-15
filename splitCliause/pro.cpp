#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;


string UTF8ToGB(const char* str)
{
    string result;
    WCHAR *strSrc;
    LPSTR szRes;

    //�����ʱ�����Ĵ�С
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //�����ʱ�����Ĵ�С
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete[]strSrc;
    delete[]szRes;

    return result;
}

// ȥ�ո�
void trim(string &s)
{
    if( !s.empty() )
    {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }

}

// д�ļ�
void save(string path, string str) {
    ofstream out;
    out.open("C:\\Users\\liupeng\\IdeaProjects\\JavaTools\\src\\OpenFile\\test11.txt",  std::ios::out | ios::app);
    out << str << "\n";
    out.close();
}

// �ָ�
string getClause(string str) {
    string newString = "";
    string string = "";
    int insen=1;
    for(int i=0;i<str.length();i++){
        if(str[i]&128){ //�ж��Ǻ��֣�gb2312���������ֽڣ�ͬʱ��������ֽ�
            //cout<<str[i]<<str[i+1];
            newString = newString + str[i] + str[i+1];
            i++;
        }else{//�����Ǻ���ֱ�����
            newString = newString + str[i];
            // cout<<str[i]<<' ';
        }

        //�� �ж�Ϊ������
        if(str[i-1]==-95&&str[i]==-80){
            insen=1;  //��һ��������
        }
        //���ж�Ϊ������
        if(str[i-1]==-95&&str[i]==-79){
            //���ж�Ϊ��ţ�һ�����ӻ���
            if(str[i+1]==-95&&str[i+2]==-93){continue;}
            insen=0;  //�˾��ӽ���
            cout << newString << endl;
            save("", newString);
            newString = "";
            //cout<<endl;
        }

        // ���ж�Ϊ��ţ�һ�����ӻ���
        if(str[i-1]==-95&&str[i]==-93){
            cout << newString << endl;
            save("", newString);
            newString = "";
            //cout<<endl;
        }
            // ?�ж�Ϊ�ʺ�
        else if(str[i-1]==-93&&str[i]==-65){
            cout << newString << endl;
            save("", newString);
            newString = "";
            //cout<<endl;
        }
            // !�ж�Ϊ��̾��
        else if(str[i-1]==-93&&str[i]==-95){
            cout << newString << endl;
            save("", newString);
            newString = "";
            //cout<<endl;
        }
    }
    return string;
}



int main(int argc, char *argv[])
{
    ifstream in;
    in.open("C:\\Users\\liupeng\\IdeaProjects\\JavaTools\\src\\OpenFile\\test.txt");
    string s;
    string tempStr = "";
    while (std::getline(in, s))
    {
        string str = UTF8ToGB(s.c_str()).c_str();
        //��ÿһ�н��в�����
        trim(str);
        tempStr = tempStr + str;
        // �ָ�
        tempStr = getClause(tempStr);
    }
    in.close();
    system("pause");
    return 0;
}