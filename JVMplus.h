#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define STATUS_VALUE int
#define STATUS_SUCCESS 1     //成功
#define STATUS_NO_INPUT 2    //没有或不合法的输入
#define STATUS_NO_IDEN 3     //标识符文件(identifier.res)丢失
#define STATUS_NO_GPP 0      //没有g++环境

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::ios;

class JvavVirtualMachine{
    //Jvav Compile Platform
private:
    std::string fileName;
public:
    JvavVirtualMachine(std::string fName) : fileName(fName){}
    STATUS_VALUE compile();
    //TODO : 带有-o参数的直接生成可执行文件
};