## 计算机图形学课后作业
 ![](https://img.shields.io/badge/release-v1.0-yellowgreen.svg) ![](https://img.shields.io/badge/platform-windows-brightgreen.svg) ![](https://img.shields.io/badge/build-cmake-blue.svg)

### 使用方法

请用 CMake 工具打开该工程，具体方法是：

1. 下载 CMake：[地址](http://www.cmake.org/cmake/resources/software.html)。我选择的是 Win32 安装程序。

2. 在 CMake 的源码路径处填入文件夹的路径，如作业一是 `xxx/HW01-sphere`。
3. 在 CMake 的编译输出路径处填入build的路径，如作业一是 `xxx/HW01-sphere/build`。
4. configure 两次再 generate（注意选择适合自己的 IDE 版本）。
5. 打开 build 中编译好的文件即可。（如，选择 Visual Studio 则打开 *.sln）。
6. 右键工程（如作业一是 `HW01-sphere`），点击 "设为启动项目"，然后运行。
7. note: 编译目录不要有特殊字符。配置有问题参考：[地址](https://learnopengl-cn.github.io/01%20Getting%20started/02%20Creating%20a%20window/#glfw_1)。

### 实验作业

* 作业一：绘制球体 - `HW01-sphere` 。
* 作业二：立方体旋转 - `HW02-rotating-cube` 。
* 作业三：创建摄像机类 - `HW03-camera` 。
