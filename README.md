# STM32 Templates——SPL

## Introduction

本仓库采用的是 **STM32F103C8T6** 芯片作为主控芯片，并且采用 SPL 库（标准库）进行代码的编写，包含一个基础的项目工程的模板和一个采用 OLED 显示屏搭建的调试工程模板，所提供的工程模板均通过本人成功编译链接能够正常使用，同时采用 **MDK + Vscode** 进行开发，选择 **STLink** 进行调试。

当然如果你想要查看或者学习其他与该模版相关的工程例程进行学习或者其他活动，可参考我的其他仓库[stm32f103c8t6-projects](https://github.com/rsecss/stm32f103c8t6-projects)

## Usage

直接 clone 项目到本地，根据需要选择你想要的模板然后打开 MDK 工程文件进行编译调试即可，最后根据自己的项目进行改进和使用。

## Directory structure

```txt
    |-- ARM             # 支持包(.pack)和 F1 标准库
    |-- Reference       # 参考资料
    |-- Template        # 工程模板文件夹
        |-- Template1   # 工程模板1
        |-- Template2   # 工程模板2
        |-- Template3   # OLED 工程模板
    |-- Tools           # 工具软件

```

### Template directory structure

**说明：** 我使用的基础工程模板目录结构主要有以下两种，分别是 Template1 和 Template2 选择哪一种目录结构进行构建工程看个人喜好，但是我更加推荐 Template1 这种目录结构。而 Template3 则是在第一个模板上面的进行修改，加了一些驱动函数，方便后序调试和拓展开发，同时下面的目录结构为大体框架，个人也可以根据实际情况进行调整，当然也可以参考以下两篇博客的配置方法教程：

1. [手把手带你从零开始搭建工程（标准库版）——@程亦寻](https://blog.csdn.net/debug602/article/details/141183452)
2. [用keil5新建STM32工程（超详细的图解操作）——@小治成长记](https://blog.csdn.net/qq_45390365/article/details/109016433)

#### [工程模板（Template1，推荐）](./Template/Template1.zip)

```txt
    |-- Drivers             # 驱动层
        |-- BSP             # 板级驱动层
        |-- CMSIS           # 核心层
            |-- startup     # 启动文件
        |-- STM32F10x_FWLib # 标准库驱动
        |-- SYSTEM          # 系统层
    |-- Middlewares         # 中间件层
    |-- Output              # 编译时产生的文件包括 .hex 文件
    |-- Projects            
        |-- MDK-ARM         # MDK 工程文件
    |-- User                # 用户层
    |-- keilkill.bat        # 批处理文件
```

**注意事项：**

1. 在新建工程后需要将必要的文件添入到工程目录当中，同时将工程重命名
2. 需要进入 C/C++ 设置界面，在 define 一栏输入全局宏定义 `USE_STDPERIPH_DRIVER` ，并在下面的 includepath 栏加入头文件路径 `.\Drives\CMSIS` `.\Drivers\STM32F10x_FWLib\inc` `.\User` `.\Drivers\BSP` `.\Drivers\SYSTEM` `.\Middlewares`
3. 在 Debug 设置界面，根据实际选择仿真器，这里我选择的是 `ST-Link Debugger`，同时在旁边的设置中选择 Flash Download 勾选上 `Reset and Run` 按钮，方便后续的下载和操作
4. 最后进入 Target 设置界面，选择 ARM 编译器`Use default compiler version 5`，不能选择默认的`Use default compiler version 6`，这样会导致编译不成功
5. keilkill.bat 是批处理文件，主要是为了方便分享工程时，可以清除编译产生的中间文件，这个可选，具体看个人

#### [工程模板（Template2）](./Template/Template2.zip)

```txt
    |-- CMSIS               # 核心层
        |-- startup         # 启动文件
    |-- STM32F10x_FWLib     # 标准库驱动
    |-- Hardware            # 驱动层（未添加）
    |-- System              # 系统层
    |-- User                # 用户层
    |-- XXXX                # 工程文件（.uvprojx 和 .uvoptx 文件）    
    |-- keilkill.bat        # 批处理文件
```

**说明：** 同 Template1，该模板不需要添加什么，只需要修改第二点中的 includepath  栏的头文件路径稍加修改就可以了，同时根据对应的文件夹加入相关的文件

#### [OLED 显示屏模板（Template3）](./Template/Template3.zip)

```txt
    |-- Drivers             # 驱动层
        |-- BSP             # 板级驱动层
            |-- led         # led 驱动
            |-- key         # 按键驱动
            |-- oled        # oled 显示屏驱动
        |-- CMSIS           # 核心层
            |-- startup     # 启动文件
        |-- STM32F10x_FWLib # 标准库驱动
        |-- SYSTEM          # 系统层
            |-- delay       # 延时函数
    |-- Middlewares         # 中间件层
    |-- Output              # 编译时产生的文件包括 .hex 文件
    |-- Projects            
        |-- MDK-ARM         # MDK 工程文件
    |-- User                # 用户层
    |-- keilkill.bat        # 批处理文件
```

**说明：** 该模板只需要在 Template1 基础项目工程文件中的 DRIVERS/BSP 文件夹中添加 LED、OLED、Key 相关的驱动函数就可以实现驱动简单的 OLED 显示屏进行调试和拓展开发

## Reference download

可以从我上传的[reference文件夹](./Reference/)下载相关的参考资料，当然你也可在下面提供的官方网站或者其他网站下载相关的参考资料，

1. [Arm Keil | Devices-标准库下载](https://www.keil.arm.com/devices/)
2. [资料下载——@江协科技](https://jiangxiekeji.com/download.html)

## Contributions

如果上述提供的资料和模板出现问题，欢迎大家 Issue 和 PR ！

最后，感谢广大的贡献者参与贡献！

## Acknowledgement

XXX

## Statement

该仓库提供的任何资料或者源码仅供学习参考使用。倘若是用于其他用途出现问题，概不负责！
