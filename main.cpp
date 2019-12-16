#include<iostream>
#include<string>
#include<codecvt>
#include<fstream>
#include <map>
#include <sstream>

using namespace std;

std::string ws2s(const std::wstring& wstr)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;
    return converterX.to_bytes(wstr);
}

void swap(int &a,int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void cal(int *a,int first,int length){
    if(first == length){
        for(int i = 0; i <= length; i++){
            wstring temp = wstring(1,a[i]);
            // wcout.imbue(std::locale("chs"));
            // wcout << temp;
            cout << ws2s(wstring(1,a[i]));
        }
        cout<<endl;
    }
    else{
        for(int i = first; i <= length; i++){
            //循环遍历使得当前位置后边的每一个元素都和当前深度的第一个元素交换一次
            swap(a[first],a[i]);//使得与第一个元素交换
            cal(a,first+1,length);//深入递归，此时已确定前边的元素，处理后边子序列的全排列形式。
            swap(a[first],a[i]);//恢复交换之前的状态
        }
    }
}

/*
int main(){
    // wcout.imbue(std::locale("chs"));
    int a[100] = {};
    string str = "的乡村风格";

    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring sss = conv.from_bytes(str);
    for(int i=0;i<sss.length();i++) {
        a[i] = sss[i];
    }
    cal(a,0,sss.length()-1);
    return 0;
}
*/

