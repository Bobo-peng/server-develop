能一句话说清楚的，绝不用第二句。
## 网络 ##
1.UDP和TCP的区别？

答：

（1）TCP是面向连接的，UDP不需要建立连接；

（2）TCP是面向字节流的，UDP是面向报文的；

（3）TCP是可靠传输，UDP是不可靠传输；


2.UDP协议3次发送，几次接收？

答：3次

3.UDP可以使用connect吗？

答：可以

4.TIME_WAIT状态出现在哪一端？

答：主动断开方

5.出现大量的TIME_WAIT如何解决？

答：

（1）通过调整内核参数

    net.ipv4.tcp_syncookies = 1 表示开启SYN Cookies。当出现SYN等待队列溢出时，启用cookies来处理，可防范少量SYN攻击，默认为0，表示关闭；
    
    net.ipv4.tcp_tw_reuse = 1 表示开启重用。允许将TIME-WAIT sockets重新用于新的TCP连接，默认为0，表示关闭；
    
    net.ipv4.tcp_tw_recycle = 1 表示开启TCP连接中TIME-WAIT sockets的快速回收，默认为0，表示关闭。
    
    net.ipv4.tcp_fin_timeout 修改系統默认的 TIMEOUT 时间

（2）SO_LINGER选项

6.怎么发送RST包？

答：SO_LINGER

    struct linger {
    int l_onoff //0=off, nonzero=on(开关)
    int l_linger //linger time(延迟时间)
    } 

l_onoff 为非0，l-linger为0,立即发生RST包，不用等2MSL。

7.描述TCP/IP的层次结构？

答：从下往上：数据链路层-网络层-传输层-应用层

8.TCP三次握手的细节？

答：

（1）客户端发起连接请求：SYN=1,seq=x

（2）服务端收到请求后，向客户端发送确认+seq:SYN =1,ACK=1，ack=x+1,seq=y

（3）客户端确认：ACK，ack=y+1,seq = x+1

9.TCP四次挥手的细节？

答：

（1）主动方发起结束连接，发送FIN包：FIN=1,seq=u

（2）被动方回复：ACK=1, ack=u+1

（3）被动方发送FIN包：FIN=1,seq=w,ack=u+1

（4）主动方回复确认：ACK=1,ack=w+1


10.TCP为什么不能两次握手？

答：因为双方都要维护自己的序列号，都需要得到对方的确认。

11.CLOSE_WAIT状态在什么时候出现？

答：主动方

12.为什么TIME_WAIT要等2MSL？

答：MSL报文最大生存时间，一来一回正好2MSL

13.TCP和UDP适合什么场景？

答：TCP适合弱网环境提高可靠传输，UDP适合大流量，允许丢失，如直播

14.为什么不直接使用IP协议，还要加一层UDP协议？

答：端口需要确认数据流向哪个进程（应用程序）

15.UDP使用connect的意义是什么？

答：

UDP中使用connect可以提高效率

    普通的UDP发送两个报文内核做了如下:#1:建立连结#2:发送报文#3:断开连结#4:建立连结#5:发送报文#6:断开连结
    采用connect方式的UDP发送两个报文内核如下处理:#1:建立连结#2:发送报文#3:发送报文另外一点,  每次发送报文内核都由可能要做路由查询.

UDP多次调用connect有两种用途:1,指定一个新的ip&port连结. 2,断开和之前的ip&port的连结。

16.怎么设计可靠的UDP?

答：kcp，quic

17.UDP分片原理？

答：对应用层数据分片，以满足MTU的要求；给分片编号，接收端重组，解决乱序问题。

18.linux常见的网络模型？

答：

（1）同步阻塞

（2）同步非阻塞

（3）异步阻塞

（4）异步非阻塞

19.select和epoll的区别？

答：

(1)select 通过轮询，epoll通过事件驱动

(2)select 返回的所有的fd,epoll返回的所有就绪的fd

(3)select 存储fd的数据结构是数组，默认上限1024，epoll是红黑树，没有上限

20.epoll的水平模式和边缘模式的区别？

答：水平模式一直触发，边缘模式只触发一次

21.select可以检测网络异常吗？

答：

22.recv的返回值，>0,=0,<0的区别？

答：

（1）阻塞情况下；>0 接收的字节数；=0 对方断开连接； <0 发生错误

（2）非阻塞情况下：<0 的情况还有看erron的值，如果erron=EAGIN 不是错误

23.socket的SO_LINGER选项是什么作用？

答：设置关闭时等待的选项

24.socket的SO_KEEPALIVE作用？

答：保持连接

25.如何优雅关闭一个连接？

答：SO_LINGER 非零 优雅

26.close和shutdown的区别？

答：  close函数会关闭套接字ID，如果有其他的进程共享着这个套接字，那么它仍然是打开的。 而shutdown会切断进程共享的套接字的所有连接。

    《UNIX网络编程：卷1》的第136页

27.如何解决TCP粘包问题？

答：应用层解决

28.如何设计保活心跳？

答：心跳包 = 1个携带少量信息 & 大小在10字节内的信息包

29.如何设计业务心跳？

答：不断增加心跳间隔时间进行心跳应答测试，直到心跳失败5次后

30.如和检测对端已关闭？

答：


    一是使用read返回值，如果返回0，并且errno=EAGAIN，则说明连接被对方关闭
    使用心跳包，长时间没有接到心跳包时，说明连接断开
    使用getsockopt判断连接状态，若是TCP_ESTABLISHED，则说明连接未断开，否则说明连接断开；


31.http协议格式是什么？

答：起始行-http头-数据

32.http头格式是什么？

答：

（1）请求头：第一行：请求方法 URL 协议版本（中间用空格隔开）
       
接下来“回车换行符”是字段，以key-value的形式

（2）响应头：协议版本 响应码 响应码描述

接下来“回车换行符”是字段，以key-value的形式

33.head/get/post方法的区别？

答：

（1）get是向服务器请求资源

（2）post是向服务器提交资源
34.ping命令的原理？

答：ICMP

35.http1.0/1.1/2.0的区别？

答：

(1)http1.0:短链接

(2)http1.1:可长连接（connection:keep-alive）

(3)http2.0：服务器可主动推送给客户端，I/O复用技术

36.http和https的区别？

答：https基于TSL协议，加密数据

37.https连接过程是什么？

答：

（1）客户端发起连接

（2）服务器发送证书给客户端

（3）客户端验证证书

（4）验证成功后，产生密钥，通过证书公钥加密，发送给服务端

（5）服务端拿到密钥，随后数据通过该密钥加密，发送数据

38.socket的错误码EINTR代表什么？

答：中断

39.如何清理无效的死连接？

答；

40.ARP协议的作用？

答：通过IP找到MAC

41.http的常用响应码？

答：

(1)200 OK

(2)301 永久重定向

(3)302 临时重定向

(4)404 客户端请求的资源不存在

(5)5xx 服务器故障

42.输入URL按下回车发生了什么？

答：

（1）向DNS发起请求，回去IP和端口

（2）和服务端建立连接，获取资源

（3）服务端返回资源

（4）客户端（浏览器）显示资源

43.网关的作用？

答：

44.TCP中都有什么定时器？

答：

    1. 重传定时器，使用于当希望收到另一端的确认。
    2. 坚持定时器，使窗口大小信息保持不断流动，即使另一端关闭了其接收窗口
    3. 保活定时器，检测到一个空闲连接的另一端何时崩溃或重启
    4. 2MSL定时器，测量一个连接处于TIME_WAIT状态的时间

45.TCP中6个控制位代表什么？

答：

（1）紧急指针

（2）ACK 确认

（3）PSH 尽快推给应用

（4）RST 重置

（5）SYN 同步连接

（6）FIN 中止连接

46.session和cookie的区别？

答：

（1）cookie 客户端

（2）session 服务端

47.常用的网络工具？

答：ping tracert telent netstat
