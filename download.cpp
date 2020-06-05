//! 警告! 本代码使用了非标准函数! 如果您的gcc/msvc提示没有函数 可尝试换编译器!
//TODO 修改为标准函数

#include <bits/stdc++.h>
#include <windows.h>
#include <shlwapi.h>
#include <io.h>
#include <stdlib.h>
using namespace std;
const int STATUS_SUCESS=1,STATUS_ERROR=-1;
void wgetue() {printf("[Error] wget.exe is missing! Please check.");printf("\nstop working");getchar();return;}
void jcpue() {printf("[Error] there is no Jvav! Please check.");printf("\nstop working");getchar();return;}
/*
备用 
int CF(char *SourceFile,char *NewFile)
{
ifstream in;
ofstream out;
in.open(SourceFile,ios::binary);//打开源文件
if(in.fail())//打开源文件失败
{
   cout<<"[Error] Fail to open the source file."<<endl;
   in.close();
   out.close();
   return 0;
}
out.open(NewFile,ios::binary);//创建目标文件 
if(out.fail())//创建文件失败
{
   cout<<"[Error] Fail to create the new file."<<endl;
   out.close();
   in.close();
   return 0;
}
else//复制文件
{
   out<<in.rdbuf();
   out.close();
   in.close();
   return 1;
}
}
*/

/**
 * main: 替换原文件
 * args:
 * 	char* f1 : 需要替换的对象
 *  char* f2 : 需要替换的源文件
 */
int th(char* f1,char *f2)
{
	//#ifdef WIN32
	if(_access(f1,0)!=-1)
	{
		char* w;
		sprintf(w,"del %s && copy %s %s && del %s",f1,f2,f1,f2);
		system(w);
		return STATUS_SUCESS;
	}
	else
	{
		char *si;
		sprintf(si,"copy %s %s",f2,f1);
		system(si);
	}
	//#endif
	/*#ifdef LINUX
	char* w1;
	sprintf(w,"cp %s %s && rm -f %s",f2,f1,f2);
	if(system(w1)==STATUS_ERROR){printf("ERROR: system could not run.");return STATUS_ERROR;}
	#endif*/
	
}
int main(int argc,char **argv[])
{
	//初始化 
	system("title JCP升级器");
	if(_access("wget.exe",0)==-1){wgetue();return 0;}//
	if(_access("jcp.exe",0==-1)||_access("identifier.res",0)==-1){jcpue();return 0;}
	char c[10000];
	getcwd(c,sizeof(c));//获得目录文件 (对不起無暝)
	setenv("PATH",c,NULL);//环境变量
	//开始 
	printf("升级开始.....\n");
	printf("警告:本程序可能会误删一些文件夹。如果你的C盘的重要文件里含有Jvav或者Jcp。请立即改名\n");
	getchar();
	Sleep(3000);
	system("wget http://cdn.yuzijiangorz.xyz/Jvav-latest.7z");//获取
	system("wget http://cdn.yuzijiangorz.xyz/Jvav-latest-sourse.7z");
	system("wget http://cdn.yuzijiangorz.xyz/7z.exe");
	system("wget http://cdn.yuzijiangorz.xyz/7z.dll");
	if(_access("C:\\Jcp",0)!=-1){system("del C:\\Jcp");}//判断文件夹是否存在
	if(_access("C:\\Jvav",0)!=-1){system("del C:\\Jvav");}
	system("7z.exe x Jvav-latest-sourse.7z -oC:\\Jvav");//解压
	system("7z.exe x Jvav-latest.7z -oC:\\Jcp");
	ofstream outf("C:\\ui.bat");
	outf<<"@echo off\n";
	outf<<"echo 删除中...\n";
	char *ioud;
	sprintf(ioud,"del %s\n",c);
	outf<<ioud;
	outf<<"echo 程序运行完毕。按下回车并退出\n";
	outf<<"pause\n"
	outf<<"start C:\\Jcp\n";
	outf<<"del %0\n";
	outf.close();
	system("C:\\ui.bat");
	return 0;
}

