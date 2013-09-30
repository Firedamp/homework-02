﻿说明
=======
命令行参数
------
		这是一个命令行程序，用于计算二维数组的最大子数组的和，
		如果你最终将该程序编译为maxsum.exe，要运行此程序首先你需要一个输入文件，
		然后运行以下命令
		maxsum.exe <file name>
		当然，你也可以加入一些参数，例如
		maxsum.exe /v <file name>
		maxsum.exe /h <file name>
		maxsum.exe /v /h <file name>
		/v表示数组垂直首尾相连，/h表示水平首位相连
		当然你还可以加上/a，但是很遗憾此程序目前还不支持/a
		任何的命令输入错误都会得到对应的错误提示
输入文件
------
		输入文件的格式如下：
		<数组的行数>，
		<数组的列数>,
		<数组元素>(以逗号隔开)
		这是一个样例：
		3,
		3,
		1,2,3,
		4,5,6,
		-1,-2,-2
		请注意，任何的输入错误都会得到对应的错误提示
