HelloCV
```markdown
# 加密解密工具 (CryptoTool)

一个基于C++实现的简单加密解密工具，支持文本和文件的加密解密操作。

## 项目结构
```tree
cppTest/
├── includes/      # 头文件目录
│   ├── Crypto.h       # 加密解密类头文件
│   ├── FileHandler.h  # 文件处理类头文件
│   └── Menu.h         # 菜单界面类头文件
├── src/           # 源文件目录
│   ├── main.cpp       # 主程序入口
│   ├── Crypto.cpp     # 加密解密实现
│   ├── FileHandler.cpp# 文件处理实现
│   └── Menu.cpp       # 菜单界面实现
├── build/         # 构建目录（编译后生成）
├── CMakeLists.txt # CMake构建配置文件
├── README.md      # 项目说明文档
└── links.md       # 语雀笔记链接汇总

## 环境配置

### 系统要求
- Linux/Unix 系统
- GCC 编译器 (g++)
- CMake (版本 3.10 或更高)

### 依赖安装
```bash
# Ubuntu/Debian 系统
sudo apt update
sudo apt install g++ cmake
```
构建项目

使用 CMake 构建（推荐）

```bash
# 进入项目目录
cd cppTest

# 创建构建目录
mkdir build
cd build

# 生成 Makefile
cmake ..

# 编译项目
make
```

直接使用 g++ 编译

```bash
g++ -Wall -Wextra -g3 -Iincludes \
    src/main.cpp src/Menu.cpp src/Crypto.cpp src/FileHandler.cpp \
    -o My_cryptoTool
```

使用方法

运行程序

```bash
# 如果在 build 目录中编译
./My_cryptoTool

# 如果直接编译在项目根目录
./My_cryptoTool
```

CMake 构建配置

CMakeLists.txt 详解

```cmake
cmake_minimum_required(VERSION 3.10)
project(CryptoTool LANGUAGES CXX)

# 包含头文件目录
include_directories(includes)

# 添加可执行文件并链接所有源文件
add_executable(My_cryptoTool 
    src/Crypto.cpp 
    src/FileHandler.cpp 
    src/Menu.cpp 
    src/main.cpp
)
```

项目配置经验

· 使用 include_directories() 指定头文件搜索路径
· 通过 add_executable() 一次性添加所有源文件
· 支持跨平台编译，确保代码可移植性

设计思路

架构设计

1. 模块化分离：加密算法、文件操作、用户界面三个独立模块
2. 静态方法：使用静态方法避免对象状态管理复杂性
3. 菜单驱动：简单的控制台菜单界面，用户友好

类设计

· Crypto类：纯算法类，提供加密解密静态方法
· FileHandler类：文件读写操作，处理输入输出
· Menu类：用户交互界面，协调各个模块

核心实现

加密算法实现

```cpp
string Crypto::encrypt(string& text, int key) {
    string result = text;
    for(size_t i = 0; i < result.length(); i++) {
        if(isalpha(result[i])) {
            char base = islower(result[i]) ? 'a' : 'A';
            result[i] = base + ((result[i] - base) + key) % 26;
        }
    }
    return result;
}
```

文件处理实现

```cpp
string FileHandler::readFile(const string& filename) {
    ifstream file(filename);
    if(!file) {
        cout << "File open failed" << endl;
        return "";
    }
    string line, content;
    while(getline(file, line)) {
        content += line + "\n";  // 注意使用正确的换行符
    }
    file.close();
    return content;
}
```

遇到的问题与解决方案

1. 编译链接错误

问题：undefined reference to 'Menu::run()'
原因：编译命令只包含了main.cpp，缺少其他源文件
解决方案：

· 使用CMake统一管理构建过程
· 确保所有.cpp文件都被正确链接

2. 文件路径问题

问题：程序运行时找不到输入文件
原因：工作目录与文件位置不匹配
解决方案：

· 使用绝对路径或正确的相对路径
· 在代码中添加路径错误提示

3. 字符串处理错误

问题：文件读取后换行符异常
原因：错误使用了/n而不是\n
解决方案：

```cpp
// 错误
content += line + "/n";
// 正确
content += line + "\n";
```

使用方法

运行程序

```bash
./My_cryptoTool
```

功能说明

程序提供以下功能：

1. 文本加密 - 直接输入文本进行加密
2. 文本解密 - 直接输入加密文本进行解密
3. 文件加密并保存 - 加密文件内容并保存到 encrypted.txt
4. 文件解密并保存 - 解密文件内容并保存到 decrypted.txt
5. 退出 - 退出程序

加密算法

使用简单的凯撒密码（Caesar Cipher）算法：

· 仅对字母字符进行加密
· 保持大小写不变
· 支持任意整数密钥

示例使用

文件加密

1. 选择选项 3
2. 输入文件路径（如：input.txt）
3. 输入加密密钥（如：5）
4. 加密结果保存到 encrypted.txt

文件解密

1. 选择选项 4
2. 输入加密文件路径
3. 输入解密密钥（与加密密钥相同）
4. 解密结果保存到 decrypted.txt

注意事项

· 确保输入的文件路径正确
· 加密和解密使用相同的密钥
· 文件操作会在程序当前目录生成结果文件
· 程序仅处理文本文件，二进制文件可能产生意外结果

开发信息

· 编程语言: C++
· 构建工具: CMake
· 编译器: GCC
· 编码标准: C++11

```

