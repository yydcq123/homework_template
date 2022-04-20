# XXXX实验报告

## 学号：XXX

>注:为保护同学隐私，请不要填写姓名

## 实验目的：

1. 给定一个由数字组成的列表，列表中数字都大于1，寻找此列表中的最大值
1. ...

## 实验原理

对列表元素做一次遍历，使用一个全局变量Max来记录到当前的最大值，此变量初始化为一个负数，如果当前元素大于Max，那么令Max等于当前元素，然后进行查看下一个元素.


## 实验输入数据集

文本数据集：5,1,2,3,7,14,6  
文件数据集：[数据集](./data/list.txt)

## 实验内容

1. [max.py](./max.py) 算法实现的python版本
1. [max.c](max.c) 算法实现的C语言版本
1. [max.java](max.java) 算法实现的java版本

## 实验预期结果与实际结果
+ 实验预期结果：14

实验过程及实验结果（Java版）

```bash
gitpod /workspace/homewrok_template (main) $ javac Max.java
Picked up JAVA_TOOL_OPTIONS:  -Xmx3435m
gitpod /workspace/homewrok_template (main) $ java Max
Picked up JAVA_TOOL_OPTIONS:  -Xmx3435m
14

```

实验过程及实验结果（C版）

```bash
gitpod /workspace/homewrok_template (main) $ gcc -o max.exe max.c
gitpod /workspace/homewrok_template (main) $ ./max.exe 
14

```

实验过程及实验结果（Python版）

```bash
gitpod /workspace/homewrok_template (main) $ python max.py 
14

```