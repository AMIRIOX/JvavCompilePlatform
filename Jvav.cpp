
/*
    Jvav Programmer Ver.02w05c Snapshot
    By 30266
    Compilation time 2020-04-16 21:00
    ----------------------------------
    Jvav Programmer Ver.03w00c Snapshot
    By Amiriox
    Compilation time 2020-05-15 15:24
    ----------------------------------
    Jvav Programmer Ver.2 Release
    By Amiriox
    Compilation time 2020-06-02 12:56
    ----------------------------------
    Jvav Programmer Ver.2.1 Snapshot
    By Amiriox
    Compilation time 2020-06-02 20:00
*/
#include <windows.h>

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "JVMplus.h"
using namespace std;

map<string, int> settingCommandMap;
void init_() {
    // settings map init;
    settingCommandMap["-strict=false"] = 1;
    settingCommandMap["-strict=true"] = 2;
    settingCommandMap["-std"] = 3;
}
bool tmpstrict = true;
int tmpversion = 0;
void processChangeSettings(string set_c) {
    switch (settingCommandMap[set_c]) {
        case 1: {
            tmpstrict = false;
            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "Strict Mode already been closed." << endl;
            SetConsoleTextAttribute(
                hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
        case 2: {
            tmpstrict = true;
            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "Strict Mode already been opened.";
            SetConsoleTextAttribute(
                hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
        case 3: {
            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            cout << "Input 11 or 14 or 17 for jvav standard version: ";
            bool outputWarning = bool(tmpversion);
            cin >> tmpversion;
            SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "The standard has been set to " << tmpversion << endl;
            if (outputWarning) {
                SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN);
                cout << "Warning: Before you set it up, the standard version "
                        "is not the default"
                     << endl;
            }
            SetConsoleTextAttribute(
                hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
        default: {
            cout << "Unknown Setting Options.\n" << endl;
            break;
        }
    }
};
int main(int argc, char** argv) {
    init_();
    if (argc == 1) {
        cout << "Initializing program...\n";
        string language;
        string cn_command, cn_type, cn_input_char;
        string command, type, inputcharacter;
        language = "English";
        cout << "Configuring the online update service...\n";
        system("del upgrade.txt");
        system("cls");
    /*en_main*/
    en_main:
        cout << "---------------------------------------------\n";
        cout << "| Jvav Program                Ver.2.1 Pre0  |\n";
        cout << "| By Dr.ZhangHaoYang      Programmer 30266  |\n";
        cout << "| The author of the JCP & Jvins: Amiriox    |\n";
        cout << "| Enter'help'to get help!                   |\n";
        cout << "| Online push updates are now supported!    |\n";
        cout << "| Compile vav source ile are now supported! |\n";
        cout << "--------------------------------------------\n";
    main:
        cout << "Jvav>";
        cin >> command;
        if (command == "help") {
            cout << "----Jvav help------Page(1/1)---\n";
            cout << "  help [page]:Get help\n  compile [filename]:compile "
                    "source code\n"
                    "leave:Exit Jvav\n  output:Output \n"
                    "jvins [source code filename] [execute filename]: make a "
                    "package for your source code\n"
                    "characters\n  input:Input characters\n  upgrade:Online "
                    "detection of version updates\n  language:setting the "
                    "program "
                    "language\n  info:Jvav information\n";
            cout << "----Jvav help------Page(1/1)---\n";
            goto main;
        } else if (command == "compile" || command == "cl") {
            // TODO : 限于水平,此处无法编译太大的文件(300行以上)
            string fileName;
            cin >> fileName;
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(tmpstrict);
            jvav_compiler.setStandardVersion(tmpversion);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\nCompile successfully.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\nCompiler error or there is no g++ compiler "
                        "environment!\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\nThe identifier file is missing, please check if the "
                        "identity.res file is in good condition.\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\nThere are no such files in the directory.\n";
            } else {
                cout << "\nUnknown Error.\n";
            }
            goto main;
        } else if (command == "settings" || command == "set") {
            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "tips: ";
            hd = GetStdHandle(STD_OUTPUT_HANDLE);
            // SetConsoleColor( FOREGROUND_RED, BACKGROUND_BLUE |
            // FOREGROUND_GREEN );
            SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "Warning: ";
            hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "You are changing your settings\n";
            SetConsoleTextAttribute(
                hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << "Please enter the Settings you want to change,\nenter quit "
                    "to quit: \n";
            string tmp;
            cin >> tmp;
            while (tmp != "quit") {
                processChangeSettings(tmp);
                cin >> tmp;
            }
            goto main;
        } else if (command == "jvins" || command == "jvi") {
            string fileName;
            cin >> fileName;
            string _oname;
            cin >> _oname;
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(tmpstrict);
            jvav_compiler.setStandardVersion(tmpversion);
            jvav_compiler.setMakePackageOptions(_oname);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\nCompile successfully.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\nCompiler error or there is no g++ compiler "
                        "environment!\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\nThe identifier file is missing, please check if the "
                        "identity.res file is in good condition.\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\nThere are no such files in the directory.\n";
            } else {
                cout << "\nUnknown Error.\n";
            }
            goto main;
        } else if (command == "leave") {
            cout << "Are you sure to leave jvav?(y/n)";
            string L;
            cin >> L;
            if (L == "y") {
                return 0;
            } else {
                goto main;
            }
        } else if (command == "output") {
            cout << "Jvav>output>";
            cin >> type;
            cout << type << endl;
            goto main;
        } else if (command == "info") {
            cout
                << "Jvav Programm Ver.1.2 Pre1\nIt's just a joke, but we still "
                   "make it, and the joke was first brought by Zhang "
                   "Haoyang.\nThis version supports running away from "
                   "jdk.\nThe "
                   "person writing the program is 30266 and Amiriox.\n";
            goto main;
        } else if (command == "input") {
            cout << "Jvav>input>";
            cin >> inputcharacter;
            goto main;
        } else if (command == "upgrade") {
            cout << "Jvav>upgrade>Sorry, we are developing this feature.\n";
            goto main;
        } else if (command == "language") {
            cout << "Please enter the setting language(English/简体中文):";
            // string language;
            cin >> language;
            if (language == "English") {
                goto main;
            } else if (language == "简体中文") {
                system("cls");
                goto ch;
            } else {
                cout << "Unknown language.\n";
                goto main;
            }
        } else if (command == "exit" || command == "EXIT") {
            return 0;
        } else {
            cout << "Unknown command\n";
            goto main;
        }

        /*cn_main*/
    ch:
        language = "简体中文";
        cout << "--------------------------------------------\n";
        cout << "| Jvav编译器             版本：2.1 预览版0     |\n";
        cout << "| 作者：张浩洋大师           编写者：30266      |\n";
        cout << "| Jvav编译平台和Jvav打包程序的作者: Amiriox     |\n";
        cout << "| JCP/Jvins在中文模式下已经可以使用!            |\n";
        cout << "| 通过输入'帮助'来获得帮助                      |\n";
        cout << "| 现已支持在线推送更新！                        |\n";
        cout << "| 现已支持编译Jvav源文件!                      |\n";
        cout << "--------------------------------------------\n";
    cn_main:
        cout << "Jvav>";
        cin >> cn_command;
        if (cn_command == "帮助") {
            cout << "----Jvav帮助---第(1/1)页----\n";
            cout << "  帮助 [页码]:获取帮助\n  退出:退出Jvav\n  "
                    "编译 [文件名]:编译源文件\n  生成 [源文件名] "
                    "[可执行文件名]: 生成可执行文件\n"
                    "输出:输出字符\n  "
                    "输入:输入字符以便调用\n  更新:在线检测版本更新\n  "
                    "cn_lang:设置Jvav的语言\n  关于:获取关于Jvav的信息\n";
            cout << "----Jvav帮助---第(1/1)页----\n";
            goto cn_main;
        } else if (cn_command == "编译") {
            // TODO : 限于水平,此处无法编译太大的文件(300行以上)
            string fileName;
            cin >> fileName;
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(tmpstrict);
            jvav_compiler.setStandardVersion(tmpversion);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\n编译成功.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\n编译失败,可能有语法错误或没有g++环境.\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\n标识符文件丢失,请检查\"identifier.res\"\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\n目录中没有指定的源文件\n";
            } else {
                cout << "\n未知错误.\n";
            }
            goto cn_main;
        } else if (cn_command == "设置") {
            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "提示: ";
            hd = GetStdHandle(STD_OUTPUT_HANDLE);
            // SetConsoleColor( FOREGROUND_RED, BACKGROUND_BLUE |
            // FOREGROUND_GREEN );
            SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "警告: ";
            hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "您正在更改设置\n";
            SetConsoleTextAttribute(
                hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << "请输入您要更改的设置选项,\n 输入\"退出\"以便退出: \n";
            string tmp;
            cin >> tmp;
            while (tmp != "退出") {
                processChangeSettings(tmp);
                cin >> tmp;
            }
            goto cn_main;
        } else if (cn_command == "生成") {
            string fileName;
            cin >> fileName;
            string _oname;
            cin >> _oname;
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(tmpstrict);
            jvav_compiler.setStandardVersion(tmpversion);
            jvav_compiler.setMakePackageOptions(_oname);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\nCompile successfully.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\nCompiler error or there is no g++ compiler "
                        "environment!\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\nThe identifier file is missing, please check if the "
                        "identity.res file is in good condition.\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\nThere are no such files in the directory.\n";
            } else {
                cout << "\nUnknown Error.\n";
            }
            goto cn_main;
        } else if (cn_command == "退出") {
            cout << "你确定要退出Jvav吗？(是/否)";
            string cn_back;
            cin >> cn_back;
            if (cn_back == "是") {
                return 0;
            } else {
                goto cn_main;
            }
        } else if (cn_command == "输出") {
            cout << "Jvav>输出>";
            cin >> cn_type;
            cout << cn_type << endl;
            goto cn_main;
        } else if (cn_command == "输入") {
            cout << "Jvav>输入>";
            cin >> cn_input_char;
            goto cn_main;
        } else if (cn_command == "关于") {
            cout << "Jvav编程器,和Jvav编译平台，版本为2."
                    "2预览版1。\n这只是一个梗，但是我们依然把它变成了现实。最早"
                    "是张"
                    "浩洋提出的这个梗。\n该版本支持脱离jdk的运行。但需要g++"
                    "环境。\n该程序编写者为3"
                    "0266和Amiriox。\n";
            goto cn_main;
        } else if (cn_command == "更新") {
            cout << "Jvav>更新>对不起,这个功能我们正在开发中.\n";
            goto cn_main;
        } else if (cn_command == "cn_lang") {
            cout << "请输入您要切换的语言(简体中文/English):";
            string cn_lang;
            cin >> cn_lang;
            if (cn_lang == "简体中文") {
                goto cn_main;
            } else if (cn_lang == "English") {
                system("cls");
                language = "English";
                goto en_main;
            } else {
                cout << "未知的语言。\n";
                goto cn_main;
            }
        } else {
            cout << "未知的命令！\n";
            goto cn_main;
        }
        /*
        ! upgrade
        ! can not run!
        */
        // upgrade:
        //     system("java -jar upgrade.jar > upgrade.txt");
        //     ifstream readFile("upgrade.txt");
        //     int ret;
        //     readFile >> ret;
        //     readFile.close();
        //     if (ret == -1) {
        //         if (language == "English") {
        //             cout << "Jvav>upgrade>Error! The update failed! Because
        //             the "
        //                     "version "
        //                     "list cannot be obtained on the authentication "
        //                     "server!\n";
        //             goto main;
        //         } else if (language == "简体中文") {
        //             cout <<
        //             "Jvav>更新>错误！无法从认证服务器获取版本列表！\n"; goto
        //             cn_main;
        //         }
        //     } else if (ret > 6) {
        //         if (language == "English") {
        //             cout << "Jvav>upgrade>Updated versionavailable for
        //             upgrades, "
        //                     "please "
        //                     "go to "
        //                     "https://30266-official.github.io/updates/Jvav.zip
        //                     " "download!\n";
        //             goto main;
        //         } else if (language == "简体中文") {
        //             cout << "有更新版本可供升级，请前往https://"
        //                     "30266-official.github.io/updates/Jvav.zip下载！\n";
        //             goto cn_main;
        //         }
        //     } else if (ret == 6) {
        //         if (language == "English") {
        //             cout << "Congratulations! You've upgraded to the latest "
        //                     "version!\n";
        //             goto main;
        //         } else {
        //             cout << "恭喜你！你已升级至最新版本！\n";
        //             goto cn_main;
        //         }
        //     } else {
        //         if (language == "English") {
        //             cout
        //                 << "Jvav>upgrade>Error!We can't get a version list
        //                 because "
        //                    "your version is coming from a future version, so
        //                    we " "don't " "support it.\n";
        //             goto main;
        //             cout << ret;
        //         } else if (language == "简体中文") {
        //             cout << "Jvav>更新>"
        //                     "错误！我们无法获取版本列表，因为您的版本是来自未来的版"
        //                     "本，"
        //                     "故我们不提供支持。\n";
        //             goto cn_main;
        //         }
        //     }

    } else {
        string cmd=argv[1];
        if (cmd == "-c") {
            // TODO : 限于水平,此处无法编译太大的文件(300行以上)
            string fileName=argv[2];
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(false);
            jvav_compiler.setStandardVersion(11);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\nCompile successfully.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\nCompiler error or there is no g++ compiler "
                        "environment!\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\nThe identifier file is missing, please check if the "
                        "identity.res file is in good condition.\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\nThere are no such files in the directory.\n";
            } else {
                cout << "\nUnknown Error.\n";
            }
        } else if (cmd == "-o") {
            string fileName=argv[2];
            string _oname=argv[3];
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(false);
            jvav_compiler.setStandardVersion(11);
            jvav_compiler.setMakePackageOptions(_oname);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\nCompile successfully.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\nCompiler error or there is no g++ compiler "
                        "environment!\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\nThe identifier file is missing, please check if "
                        "the "
                        "identity.res file is in good condition.\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\nThere are no such files in the directory.\n";
            } else {
                cout << "\nUnknown Error.\n";
            }
        }
    }
}