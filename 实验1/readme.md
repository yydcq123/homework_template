# 分治算法实验报告

## 学号：20201060426

## 实验目的

1. 通过排序算法的程序实现执行时间测试，与理论上的结论进行对比分析，深入理解算法时间复杂度渐进性态和增长率分析
2. 理解分治算法设计的基本思想、递归程序实现的基本方法
3. 加深对分治算法设计与分析思想的理解

## 实验原理

1. 算法的计算时间取决于算法中某些操作的执行次数，增长率反映了算法的时间复杂度。通过输入数据的等价类对算法的计算时间复杂度分析测试
2. 线性同余随机数生成算法：Xi+1=(aXi+c) mod m
3. 分治算法的基本思想是将规模为n的问题分解为k个规模较小的子问题，且这些子问题相互独立，与原问题性质相同。通过求子问题的解可得到原问题的解

## 输入数据集

通过程序生成（伪）随机数，作为实验用测试数据。可使用编程语言自带的 random 函数生成，也可以采用一些有效的随机数生成算法生成，例如“线性同 余法”，基于该算法，只要参数选择合适，所产生的伪随机数就能满足均匀性和 独立性，与真正的随机数具有相近的性质。

## 实验内容

1. 以冒泡排序、合并排序和快速排序算法为例，以生成的随机数作为实验中使用的测试数据；

2. 随机数生成包含 100 个随机数的测试数据，记录这些数据三个排序算法比较操作的执行次数：

3. 使用随机数生成方法生成不同规模的测试数据（10 个，100 个，1000 个，2000 个，5000 个，10000 个，100000 个，……），分别记录 BubbleSort、MergeSort 和 QuickSort 算法执行中比较操作的执行次数，图表绘制工具生成随着输入数据增加、以上三个算法比较操作次数增加的对比曲线图（折线）。

4. 使用（3）中生成的测试数据（10 个，100 个，1000 个，2000 个，5000个，10000 个，100000 个，……），对于每种规模的测试数据，分别记录以上两个算法执行中各子问题的规模，并用表格方式记录所有情形各子问题的规模值。

5. [shiyan1.cpp](shiyan1.cpp) 为算法实现的C语言版本。


## 实验预期成果与实际结果

1. 使用随机数生成100个随机数后，三个排序算法比较操作的执行次数如下：

     第一次生成：
     请输入你想要获取的随机数的个数：100
    5053 9061 8034 4362 6098 7981 7409 8897 534 7558 9382 3449 4387 2347 1155 6811 3822 7746 7282 9312 8464 5860 3230 2476 3842 208 4641 7227 2234 830 7121 8412 1944       5747 5369 2208 7055 7386 5145 2656 2436 3917 9821 1858 4520 2278 8334 7642 37 2536 9755 480 4570 8492 5845 1413 8374 1421 5133 8197 3927 323 9598 8316 944 4783         7945 264 3244 5867 1477 9874 789 2303 5907 3531 4578 8371 5939 505 1572 7800 856 5246 6512 9461 1788 2525 3082 6578 7027 3644 3877 4438 4896 3672 93 6977 8490 8555

    冒泡排序比较次数为：9504
    归并排序比较次数为：672
    快速排序比较次数为：944

     
    第二次生成：
    请输入你想要获取的随机数的个数：100
    723 1895 3868 650 461 4949 5163 8619 2710 2458 8672 1367 6192 9998 9092 8036 2357 2934 8006 9464 3380 2442 8023 4935 2605 5748 7368 6953 459 734 2436 4332 3205         4216 3725 6399 9059 5947 4360 8314 8432 1473 5639 9534 403 800 3194 2816 2446 1291 1844 1764 9363 1815 8735 7099 3721 4350 4880 7053 1859 4614 2648 2341 8379 9790     1023 5311 9201 4494 6064 3986 4725 4363 2789 9085 69 4781 3489 3219 4551 257 5760 2759 2646 2429 6046 7910 4397 1592 122 1046 277 3717 4425 2498 9278 9586 9754 2

    冒泡排序比较次数为：9900
    归并排序比较次数为：672
    快速排序比较次数为：923

    由此可见，两次生成的测试数据中，冒泡排序的比较最多，合并排序和快速排序的比较次数较少，且比较次数比较接近，但是，快速排序对于输入数据有较强的依赖性，两次随机数的产生，比较次数的差异较大，这是由于快速排序不稳定，其选择的基准值为元素第一个，不能保证基准值左右两边的元素个数都是相同的，所以结果会有差异性。

   

2. 生成随机数10 个，100 个，1000 个，2000 个，5000个，10000 个，100000个，……）所得到的三种排序方法的比较操作执行的次数如下图所示：

<img width="410" alt="f1" src="https://github.com/yydcq123/homework_template/blob/main/pictures/fig1.png?raw=true">

<img width="413" alt="f2" src="https://github.com/yydcq123/homework_template/blob/main/pictures/fig2.png?raw=true">

<img width="423" alt="f3" src="https://github.com/yydcq123/homework_template/blob/main/pictures/fig3.png?raw=true">

<img width="420" alt="f4" src="https://github.com/yydcq123/homework_template/blob/main/pictures/fig4.png?raw=true">

 通过对上述图表进行分析可以得出结论：冒泡排序的时间复杂度为O(n^2)，而归并排序和快速排序的时间复杂度均为O(nlogn)。
