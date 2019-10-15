/*
#include <stdio.h>
#include <io.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <windows.h>
#include <wsman.h>


const char *to_search="C:\\Users\\liupeng\\CLionProjects\\SplitClause\\papers\\papers\\*.txt";        //欲查找的文件，支持通配符

int main()
{
    long handle;                                                //用于查找的句柄
    struct _finddata_t fileinfo;                          //文件信息的结构体
    handle=_findfirst(to_search,&fileinfo);         //第一次查找
    if(-1==handle)
        return -1;
    printf("%s\n",fileinfo.name);                         //打印出找到的文件的文件名
    while(!_findnext(handle,&fileinfo))               //循环查找其他符合的文件，知道找不到其他的为止
    {
        printf("%s\n",fileinfo.name);
        string new = "C:\\Users\\liupeng\\CLionProjects\\SplitClause\\papers\\papers\\" + fileinfo.name;




    }
    _findclose(handle);

    system("pause");
    return 0;
}
*/
