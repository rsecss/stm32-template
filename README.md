# STM32 Templates

## 介绍

本仓库采用的是 STM32F103C8T6 芯片作为主控芯片，并且采用标准库进行代码的编写，包含一个基础的项目工程的模板和一个采用 OLED 显示屏搭建的调试工程模板，同时采用 MDK + Vscode进行开发调试，当然也可以只选择 MDK 进行开发和调试，看各人喜好啦。

## 目录结构（标准库）

**说明：** 我使用的基础工程模板目录结构主要有以下两种，分别是 Template1 和 Template2 选择哪一种目录结构进行构建工程看个人喜好，但是我更加推荐 Template1 这种目录结构，而第三个模板则是在第一个模板上面的进行修改，同时下面的目录结构为大体框架，个人也可以根据实际情况进行调整，当然也可以参考以下两篇博客的配置方法教程

1. [手把手带你从零开始搭建工程（标准库版）——@程亦寻](https://blog.csdn.net/debug602/article/details/141183452)
2. [用keil5新建STM32工程（超详细的图解操作）——@小治成长记](https://blog.csdn.net/qq_45390365/article/details/109016433)

### [基础工程（Template）](./Template)

```markdown
    |-- CMSIS           # 存放内核函数及启动文件
        |-- STARTUP     # 存放启动文件
    |-- FWLIB           # 存放库函数
    |-- DRIVERS         # 存放驱动函数
    |-- SYSTEM          # 存放系统函数
    |-- USER            # 存放用户函数
    |-- XXXX            # 工程文件（.uvprojx 文件）
    |-- keilkill.bat    # 批处理清除编译产生的中间文件（可选）
```

**注意事项：**

1. 在新建工程后需要将添加的文件加入到工程目录当中
2. 需要进入 C/C++ 设置界面，在 define 一栏输入全局宏定义 `USE_STDPERIPH_DRIVER` ，并在下面的 includepath 栏加入头文件路径 `.\CMSIS` `.\FWLIB\inc` `.\USER` `.\DRIVERS` `.\SYSTEM`
3. 在 Debug 设置界面，根据实际选择仿真器，这里我选择的是 ST-Link Debugger，同时在旁边的设置中选择 Flash Download 勾选上 Reset and Run 按钮，方便后面的下载和操作
4. 最后进入 Target 设置界面，选择 ARM 编译器`Use default compiler version 5`，不能选择默认的`Use default compiler version 6`，这样会导致编译不成功
5. keilkill.bat 是批处理文件，主要是为了方便分享工程时，可以清除编译产生的中间文件，这个可选，具体看个人

### 基础工程（Template2）

```markdown
    |-- Start           # 存放内核函数和启动文件
    |-- Library         # 存放库函数
    |-- Hardware        # 存放 驱动函数
    |-- System          # 存放系统函数
    |-- User            # 存放用户函数
    |-- XXXX            # 项目文件（.uvprojx 文件）    
    |-- keilkill.bat    # 批处理清除编译产生的中间文件（可选）
```

**注意事项：**同 Template，只需要修改第二点中的 includepath  栏的头文件路径稍加修改就可以了，同时根据对应的文件夹假如相关的文件

### OLED 显示屏

```markdown
    |-- CMSIS           # 存放内核函数及启动文件
        |-- STARTUP     # 存放启动文件
    |-- FWLIB           # 存放库函数
    |-- DRIVERS         # 存放驱动函数
        |-- LED.h       # LED 驱动函数
        |-- LED.c
        |-- Key.h       # Key 驱动函数
        |-- Key.c
        |-- OLED.h      # OLED 驱动函数
        |-- OLED.c
        |-- OLED_Font.h
    |-- SYSTEM          # 存放系统函数，包含延时函数
        |-- Delay.h
        |-- Delay.c
    |-- USER            # 存放用户函数
    |-- XXXX            # 项目文件（.uvprojx 文件）
    |-- keilkill.bat    # 批处理清除编译产生的中间文件（可选）
```

**注意事项：** 只需要在 Template 基础项目工程文件中的 DRIVERS 文件夹中添加
LED、OLED、Key 相关的驱动函数就能实现驱动简单的 OLDE 显示屏

## 资料参考下载

1. [Arm Keil | Devices-标准库](https://www.keil.arm.com/devices/)
1. [资料下载——@江协科技](https://jiangxiekeji.com/download.html)
