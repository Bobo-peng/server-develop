
## nginx ##
1.nginx框架是什么？

答：多进程。一个master进程（管理），多个work（工作）进程。

2.nginx负载均衡算法怎么实现的？

答：（1）round-robin的意思是循环轮询；（2）least-connected 每次都找连接数最少的服务器来转发请求；（3）ip-hash根据请求的客户端IP地址来决定当前请求应该交给谁；（4）weighted权重算法，会根据每个服务的权重来分发请求，权重大的请求相对会多分发一点，权重小的会少分发一点.

3.什么是惊群？如何解决惊群？

答：多个子进程在同一时刻监听同一个端口引起的，nginx解决方法：同一个时刻只能有唯一一个worker子进程监听web端口，此时新连接事件只能唤醒唯一正在监听端口的worker子进程。

采用锁，互斥量实现！！

4.为什么Nginx性能这么高？

答：异步非阻塞事件处理机制：运用了epoll模型，提供了一个队列，排队解决。

5.为什么不使用多线程？

答：

6.请解释一下什么是Nginx？

答：是一个web服务器和反向代理服务器，用于HTTP、HTTPS、SMTP、POP3和IMAP协议。

7.请解释Nginx如何处理HTTP请求？

答：Nginx使用反应器模式。主事件循环等待操作系统发出准备事件的信号，这样数据就可以从套接字读取，在该实例中读取到缓冲区并进行处理。单个线程可以提供数万个并发连接。


8.使用“反向代理服务器”的优点是什么？

答：反向代理服务器可以隐藏源服务器的存在和特征。它充当互联网云和web服务器之间的中间层。这对于安全方面来说是很好的，特别是当您使用web托管服务时。

9.动态资源、静态资源分离的原因？

答：提高用户访问静态代码的速度，降低对后台应用访问
这里我们将静态资源放到nginx中，动态资源转发到tomcat服务器中。

10.请列举Nginx的一些特性？

答：跨平台，非阻塞、高并发连接，用户请求是异步的，负载均衡器廉价。

11.在Nginx中，如何使用未定义的服务器名称来阻止处理请求?？

答：

