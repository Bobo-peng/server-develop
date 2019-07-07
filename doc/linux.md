
## Linux ##
1.指定地方新建目录？

答：mkdir -p /home/test

2.删除非空目录？

答：rm -r test

3.复制目录？

答：cp -r /etc /tmp

4.查看文件cat/tac区别？

答：cat是头开始显示，tac是倒着显示。

5.查看文件显示屏幕怎么显示行号？

答：nl

6.head/tail？

答：head显示开始n行：head -n text.c; tail显示结尾n行：tail -n text.c;-f参数可动态打印到屏幕，如日志输出。

7.less/more？

答：nl,cat,tac都是一次性显示，文件很长前面就不会显示；

less/more会通过翻页全部显示，而less可以向前翻页：

空格----下一页

b------上一页

回车------下一行

-N选项可以显示行号。

8.查看redis进程？

答：ps -eaf | gerp redis

9.查看磁盘使用情况？

答：df

10.查看系统平均负载？

答：uptime

11.查看CPU利用率？

答：top/hyop

12.查看系统上下文切换？

答：vmstat

13.查看进程上下文切换？

答：pidstat

14.为什么不直接使用IP协议，还要加一层UDP协议？

答：

15.查看内存使用情况？

答：free

16.查看磁盘的使用情况?

答：iostat

17.对一个文件的内容进行统计？？

答：wc 命令 - c 统计字节数 - l 统计行数 - w 统计字数。

18.ps 显示出来的信息中，分别用什么符号表示的？

答：

D 不可中断 Uninterruptible（usually IO）

R 正在运行，或在队列中的进程

S 处于休眠状态

T 停止或被追踪

Z 僵尸进程

W 进入内存交换（从内核 2.6 开始无效）

X 死掉的进程


19.怎么使一个命令在后台运行？

答：& 在命令结尾。

20.怎么利用 ps 查看指定进程的信息？

答：

ps -ef (system v 输出) 

ps -aux   bsd 格式输出

ps -ef | grep pid

21.终止进程用什么命令? 带什么参数？

答：kill-9 pid

22.搜索文件用什么命令? 格式是怎么样的？

答：

find <指定目录> <指定条件> <指定动作>

whereis 加参数与文件名

locate 只加文件名

find 直接搜索磁盘，较慢。

find / -name "string*"

23.查看用过的命令列表？

答：history

24.查看网络是否连通？

答：netstat

25.替换文件中的所有字段？

答：sed -i 's/被替换字符/替换字符/g'

26.vim显示行号？

答： ：set nu

27.makefile的格式？

答：

28.cmake的格式？

答：

29.gcc 引入头文件？

答：-I

30.gcc引入so库？

答：-l

31.gcc编译动态库？

答：gcc -c -fPIC

32.gcc编译静态库？

答： gcc -c 然后打包 ar rs lib***.a 

33.统计文本单词频率？

答：

     cat abc.txt |tr -cs "[a-z][A-Z]" "\n" |tr A-Z a-z |sort|uniq -c|sort -r|awk '{print $2,$1}'
解析：

（1）tr -cs "[a-z][A-Z]" "\n"  将除了字母的字符换为换行，即文本变为每行一个单词

（2）tr A-Z a-z 大写换小写

（3）uniq -c  检查以列旁边重复出现的次数