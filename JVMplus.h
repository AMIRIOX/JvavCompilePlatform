#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#define STATUS_VALUE int
#define STATUS_SUCCESS 1   //�ɹ�
#define STATUS_NO_INPUT 2  //û�л򲻺Ϸ�������
#define STATUS_NO_IDEN 3   //��ʶ���ļ�(identifier.res)��ʧ
#define STATUS_NO_GPP 0    //û��g++����

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::stringstream;

class JvavVirtualMachine {
    // Jvav Compile Platform
   private:
    std::string fileName;
    bool isStrict;
    int stdv;
    int compileMode;
    std::string oname;

   public:
    JvavVirtualMachine(std::string fName, bool iss = true, int stdversion=0, int comMode=0)
        : fileName(fName), isStrict(iss), stdv(stdversion), compileMode(comMode) {}
    STATUS_VALUE compile();
    void setStrictMode(bool a){
        isStrict=a;
    }
    void setStandardVersion(int ver){
        stdv=ver;
    }
    void setMakePackageOptions(std::string name){
        setCompileMode(1);
        setExecuteFileName(name);
    }
    void setCompileMode(int mode){
        compileMode=mode;
    }
    void setExecuteFileName(std::string on){
        oname = on;
    }
    // TODO : ����-o������ֱ�����ɿ�ִ���ļ�
};