# GETRequest-Parser 
 用于解析和编辑GET请求的GUI工具 / A GUI tool to parse and edit get request in URL
 
----

![warn](https://img.shields.io/badge/Experimental-project-red.svg)
![version](https://img.shields.io/badge/version-0.1%20alpha-blue.svg)
![licence](https://img.shields.io/github/license/z4deepfz/GETRequest-Parser)

 **该项目尚在开发中，一些功能可能不够完善**
 
----

## 功能
 1. 从URL获取参数并列出
 2. 支持修改和删除参数并同步到URL文本
 3. 一键删除可能包含隐私信息的参数(开发中)
 

## 实现细节
 1. GUI使用wxWidgets和wxSmith构建
 2. 使用boost::xpressive实现静态正则表达式


## 目的
 1. 将正则表达式的使用落地
 2. 应用一些设计模式，力求模块化、低耦合
 

## 吐槽
 1. boost的静态正则很丑很晦涩，可读性约为0
 2. 还是GUI设计工具好用，但是我不认为手写代码是无用的