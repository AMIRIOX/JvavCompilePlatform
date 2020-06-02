#include "JVMplus.h"
STATUS_VALUE JvavVirtualMachine::compile() {
    //*原理: 在新建文件前添加define后的标识符,
    //*然后使用g++编译
    //!注意,需要g++环境!
    // TODO : 目前仅支持g++ 未添加clang++, cl(msvc)等编译器
    ifstream srcFile;
    srcFile.open(fileName, ios::in);
    if (!srcFile.is_open()) {
        cout << "error: can not open source file. \n" << endl;
        return STATUS_NO_INPUT;
    } else {
        for (int i = 0; i <= 4; i++)
            fileName.pop_back();  //删除结尾的.jvav扩展名
        fileName += ".cpp";
        stringstream ss;
        ss << srcFile.rdbuf();
        std::string fileToCompile = ss.str();
        srcFile.close();

        ifstream resFile;
        resFile.open("identifier.res", ios::in);
        if (!resFile.is_open()) {
            cout << "error: Failed to open the identifier definition file. "
                    "\n"
                 << endl;
            return STATUS_NO_IDEN;
        }

        stringstream sr;
        sr << resFile.rdbuf();
        std::string identifier = sr.str();
        resFile.close();

        ofstream local;
        local.open(fileName, std::ios::out | std::ios::app);
        if (!local.is_open())
            cout << "error: can not create temp file. \n" << endl;
        local << identifier << fileToCompile;
        local.close();

        std::string _comArgs = "g++ ";
        if(isStrict){
            _comArgs+="-Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wwrite-strings -Wdangling-else -Wlogical-op ";
        }
        if(stdv!=0){
            switch (stdv)
            {
            case 17:
                _comArgs+="-std=c++17 ";
                break;
            case 11:
                _comArgs+="-std=c++11 ";
                break;
            case 14:
                _comArgs+="-std=c++14 ";
                break;
            
            default:
                break;
            }
        }
        _comArgs += fileName;
        int result = system(_comArgs.c_str());
        if (result == 0) {
            system("a.exe");
            system("del a.exe");
        } else if (result == 1) {
            _comArgs = "del " + fileName;
            system(_comArgs.c_str());
            cout << "deleting *.cpp\n";
            return STATUS_NO_GPP;
        }

        _comArgs = "del " + fileName;
        system(_comArgs.c_str());
        cout << endl;
    }
    return STATUS_SUCCESS;
}