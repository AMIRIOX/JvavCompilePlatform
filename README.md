# Jvav Compile Platform 源代码

这只是一个梗, 并且当事人并不介意大家玩这个梗

如果您并不关心源代码,只想使用Jvav编译程序, 

请前往Jvav安装程序:[https://gitee.com/Doxfer/jvav_auxiliary/tree/master/]( https://gitee.com/Doxfer/jvav_auxiliary/tree/master/ )

## 源代码编译和运行

```shell
$ g++ Jvav.cpp JVMplus.cpp
```

## 可执行文件使用方法

点击编译后的可执行文件即可,或将本目录加入环境变量,在cmd中输入`jcp`
JCP在中文模式下是旧版本(没有严格模式),
而Jvins在中文模式下不可用.
我们将在Ver2.1中更新此问题

## 设置
### 设置Jvav标准版本
```shell
Jvav>settings
-std
11
quit
```
### 开启/关闭严格模式
严格模式默认开启,会报变量未使用等错误
所有warning将在严格模式下变为error.
关闭严格模式如下.如需开启则将false改为true
```shell
Jvav>settings
-strict=false
quit
```

### 编译: compile命令
不会生成可执行文件,但会有正常的程序运行(输入 输出等)
```shell
$ Jvav> compile demo-cn.jvav
```

### 打包: jvins命令
将会生成{executeFileName}.exe可执行文件
```shell
$ Jvav> jvins demo-cn.jvav {executeFileName}
```


目录下的`demo-cn.jvav`是一个关于Jvav语法的演示文档

```Jvav
JvavBegin

iNt mAiN(){  //iNt 为 整型变量
    cHaR ch = 'r';  //cHaR 为 字面量(字符)
    iNt n;         
    input n;         //使用input 变量/字符串/字符/重载了">>"运算符的类对象 进行程序输入
    output n magic 10;   //output 变量/字符串/字符/重载了"<<"运算符的类对象 进行程序输出,
    //并使用magic代替*(包括指针/解引用运算符和乘法的*都可以使用magic运算符)
    goBack ZERO;    //使用goBack 代替 return
    //并使用0-10的任意数字的英文单词大写代表0-10,如 ZERO ONE TWO等

    //除此之外,您可以使用if/else的大写字母IF/ELSE来进行条件控制
    //像使用while那样使用Loop,像使用for那样使用ConLoop
}

JvavEnd
```
这是一个简单的JCP with jvins的demo
乱码问题正在修复
```shell
---------------------------------------------
| Jvav Program                Ver.2 Pre0    |
| By Dr.ZhangHaoYang      Programmer 30266  |
| The author of the JCP & Jvins: Amiriox    |
| Enter'help'to get help!
          |
| Online push updates are now supported!    |
| Compile vav source ile are now supported! |
--------------------------------------------
Jvav>compile demo-cn.jvav
demo-cn.cpp: In function \'int main()\':
demo-cn.cpp:55:10: error: unused variable \'ch\' [-Werror=unused-variable]
     cHaR ch = \'r\';  //cHaR 涓?瀛?1;31mm^~
cc1plus.exe: all warnings being treated as errors
deleting *.cpp

Compiler error or there is no g++ 
compiler environment!
Jvav>settings
tips: Warning: You are changing your settings
Please enter the Settings you want to change,
enter quit to quit:
-std
Input 11 or 14 or 17 for jvav standard version: 11
The standard has been set to 11   
-strict=false
Strict Mode already been closed.  
quit
Jvav>compile demo-cn.jvav
450
4500
3请按任意键继续. . .


Compile successfully.
Jvav>jvins demo-cn.jvav testins   

Your execute file has been generated.

Compile successfully.
Jvav>exit

D:\CppProjects\DevelopingProjects\Public.MyJCP\JvavCompilePlatform>testins.exe
4502
45020
3请按任意键继续. . .
D:\CppProjects\DevelopingProjects\Public.MyJCP\JvavCompilePlatform>
```
