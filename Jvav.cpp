
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
    Jvav Programmer Ver.2.1 
    By Amiriox
    Compilation time 2020-06-02 20:00
    ----------------------------------
    Jvav Programmer Ver.2.2 Snapshot
    By Amiriox
    Compilation time 2020-06-03 09:30
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
        cout << "| Jvav Program                Ver.2.2 Pre1  |\n";
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
            // TODO : ����ˮƽ,�˴��޷�����̫����ļ�?(300������)
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
        } 
        //else if (command == "language") {
        //     cout << "Please enter the setting language(English/��������):";
        //     // string language;
        //     cin >> language;
        //     if (language == "English") {
        //         goto main;
        //     } else if (language == "��������") {
        //         system("cls");
        //         goto ch;
        //     } else {
        //         cout << "Unknown language.\n";
        //         goto main;
        //     }
        // } 
        else if (command == "exit" || command == "EXIT") {
            return 0;
        } else {
            cout << "Unknown command\n";
            goto main;
        }

    //     /*cn_main*/
    // ch:
    //     language = "��������";
    //     cout << "--------------------------------------------\n";
    //     cout << "| Jvav������             �汾��2.1 Ԥ����0     |\n";
    //     cout << "| ���ߣ��ź�����?           ��д�ߣ�30266      |\n";
    //     cout << "| Jvav����ƽ̨��Jvav������������: Amiriox     |\n";
    //     cout << "| JCP/Jvins������ģʽ���Ѿ�����ʹ��!            |\n";
    //     cout << "| ͨ������'����'����ð���?                      |\n";
    //     cout << "| ����֧���������͸��£�                        |\n";
    //     cout << "| ����֧�ֱ���JvavԴ�ļ�!                      |\n";
    //     cout << "--------------------------------------------\n";
    // cn_main:
    //     cout << "Jvav>";
    //     cin >> cn_command;
    //     if (cn_command == "����") {
    //         cout << "----Jvav����---��(1/1)ҳ----\n";
    //         cout << "  ���� [ҳ��]:��ȡ����\n  �˳�:�˳�Jvav\n  "
    //                 "���� [�ļ���]:����Դ�ļ�\n  ���� [Դ�ļ���] "
    //                 "[��ִ���ļ���]: ���ɿ�ִ���ļ�\n"
    //                 "���?:����ַ�\n  "
    //                 "����:�����ַ��Ա����\n  ����:���߼��汾����\n  "
    //                 "cn_lang:����Jvav������\n  ����:��ȡ����Jvav����Ϣ\n";
    //         cout << "----Jvav����---��(1/1)ҳ----\n";
    //         goto cn_main;
    //     } else if (cn_command == "����") {
    //         // TODO : ����ˮƽ,�˴��޷�����̫����ļ�?(300������)
    //         string fileName;
    //         cin >> fileName;
    //         JvavVirtualMachine jvav_compiler(fileName);
    //         jvav_compiler.setStrictMode(tmpstrict);
    //         jvav_compiler.setStandardVersion(tmpversion);
    //         STATUS_VALUE compile_result = jvav_compiler.compile();
    //         if (compile_result == STATUS_SUCCESS) {
    //             cout << "\n����ɹ�?.\n";
    //         } else if (compile_result == STATUS_NO_GPP) {
    //             cout << "\n����ʧ��,�������﷨�����û��g++����.\n";
    //         } else if (compile_result == STATUS_NO_IDEN) {
    //             cout << "\n��ʶ���ļ���ʧ,����\"identifier.res\"\n";
    //         } else if (compile_result == STATUS_NO_INPUT) {
    //             cout << "\nĿ¼��û��ָ����Դ�ļ�\n";
    //         } else {
    //             cout << "\nδ֪����.\n";
    //         }
    //         goto cn_main;
    //     } else if (cn_command == "����") {
    //         HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    //         SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    //         cout << "��ʾ: ";
    //         hd = GetStdHandle(STD_OUTPUT_HANDLE);
    //         // SetConsoleColor( FOREGROUND_RED, BACKGROUND_BLUE |
    //         // FOREGROUND_GREEN );
    //         SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN);
    //         cout << "����: ";
    //         hd = GetStdHandle(STD_OUTPUT_HANDLE);
    //         SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_INTENSITY);
    //         cout << "�����ڸ�������\n";
    //         SetConsoleTextAttribute(
    //             hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    //         cout << "��������Ҫ���ĵ�����ѡ��,\n ����\"�˳�\"�Ա��˳�: \n";
    //         string tmp;
    //         cin >> tmp;
    //         while (tmp != "�˳�") {
    //             processChangeSettings(tmp);
    //             cin >> tmp;
    //         }
    //         goto cn_main;
    //     } else if (cn_command == "����") {
    //         string fileName;
    //         cin >> fileName;
    //         string _oname;
    //         cin >> _oname;
    //         JvavVirtualMachine jvav_compiler(fileName);
    //         jvav_compiler.setStrictMode(tmpstrict);
    //         jvav_compiler.setStandardVersion(tmpversion);
    //         jvav_compiler.setMakePackageOptions(_oname);
    //         STATUS_VALUE compile_result = jvav_compiler.compile();
    //         if (compile_result == STATUS_SUCCESS) {
    //             cout << "\nCompile successfully.\n";
    //         } else if (compile_result == STATUS_NO_GPP) {
    //             cout << "\nCompiler error or there is no g++ compiler "
    //                     "environment!\n";
    //         } else if (compile_result == STATUS_NO_IDEN) {
    //             cout << "\nThe identifier file is missing, please check if the "
    //                     "identity.res file is in good condition.\n";
    //         } else if (compile_result == STATUS_NO_INPUT) {
    //             cout << "\nThere are no such files in the directory.\n";
    //         } else {
    //             cout << "\nUnknown Error.\n";
    //         }
    //         goto cn_main;
    //     } else if (cn_command == "�˳�") {
    //         cout << "��ȷ��Ҫ�˳�Jvav��(��/��)";
    //         string cn_back;
    //         cin >> cn_back;
    //         if (cn_back == "��") {
    //             return 0;
    //         } else {
    //             goto cn_main;
    //         }
    //     } else if (cn_command == "���?") {
    //         cout << "Jvav>���?>";
    //         cin >> cn_type;
    //         cout << cn_type << endl;
    //         goto cn_main;
    //     } else if (cn_command == "����") {
    //         cout << "Jvav>����>";
    //         cin >> cn_input_char;
    //         goto cn_main;
    //     } else if (cn_command == "����") {
    //         cout << "Jvav�����?,��Jvav����ƽ̨���汾Ϊ2."
    //                 "2Ԥ����1��\n��ֻ��һ����������������Ȼ�����������ʵ������?"
    //                 "����"
    //                 "����������������\n�ð汾֧������jdk�����С�����Ҫg++"
    //                 "������\n�ó����д���?3"
    //                 "0266��Amiriox��\n";
    //         goto cn_main;
    //     } else if (cn_command == "����") {
    //         cout << "Jvav>����>�Բ���,��������������ڿ�����?.\n";
    //         goto cn_main;
    //     } else if (cn_command == "cn_lang") {
    //         cout << "��������Ҫ�л�������(��������/English):";
    //         string cn_lang;
    //         cin >> cn_lang;
    //         if (cn_lang == "��������") {
    //             goto cn_main;
    //         } else if (cn_lang == "English") {
    //             system("cls");
    //             language = "English";
    //             goto en_main;
    //         } else {
    //             cout << "δ֪�����ԡ�\n";
    //             goto cn_main;
    //         }
    //     } else {
    //         cout << "δ֪�����\n";
    //         goto cn_main;
    //     }
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
        //         } else if (language == "��������") {
        //             cout <<
        //             "Jvav>����>�����޷�����֤��������ȡ�汾�б���\n"; goto
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
        //         } else if (language == "��������") {
        //             cout << "�и��°汾�ɹ���������ǰ��https://"
        //                     "30266-official.github.io/updates/Jvav.zip���أ�\n";
        //             goto cn_main;
        //         }
        //     } else if (ret == 6) {
        //         if (language == "English") {
        //             cout << "Congratulations! You've upgraded to the latest "
        //                     "version!\n";
        //             goto main;
        //         } else {
        //             cout << "��ϲ�㣡�������������°汾��\n";
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
        //         } else if (language == "��������") {
        //             cout << "Jvav>����>"
        //                     "���������޷���ȡ�汾�б�����Ϊ���İ汾������δ���İ�"
        //                     "����"
        //                     "�����ǲ��ṩ֧�֡�\n";
        //             goto cn_main;
        //         }
        //     }

    } else {
        string cmd=argv[1];
        if (cmd == "-c") {
            // TODO : ����ˮƽ,�˴��޷�����̫����ļ�?(300������)
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