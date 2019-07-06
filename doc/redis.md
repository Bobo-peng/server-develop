
## redis ##
1.redis单线程为什么还快？

答：

（1）纯内存操作

（2）非阻塞I/O

2.redis和memcache的区别？

答：

（1）redis可以做持久化，而memcahe不能；

（2）redis支持的数据类型多，memcached所有的值均是简单的字符串；

（3）Redis直接自己构建了VM 机制 ，因为一般的系统调用系统函数的话，会浪费一定的时间去移动和请求；

（4）value值redis最大可以达到1GB，而memcache只有1MB。


3.redis支持哪些数据类型？

答：String、List、Set、Sorted Set、hashes

4.Redis的全称是什么？

答：Remote Dictionary Server。。

5.Redis有哪几种数据淘汰策略？

答：

volatile-lru：从已设置过期时间的数据集（server.db[i].expires）中挑选最近最少使用的数据淘汰

volatile-ttl：从已设置过期时间的数据集（server.db[i].expires）中挑选将要过期的数据淘汰

volatile-random：从已设置过期时间的数据集（server.db[i].expires）中任意选择数据淘汰

allkeys-lru：从数据集（server.db[i].dict）中挑选最近最少使用的数据淘汰

allkeys-random：从数据集（server.db[i].dict）中任意选择数据淘汰

no-enviction（驱逐）：禁止驱逐数据

6.为什么redis需要把所有数据放到内存中？

答：磁盘I/O速度为严重影响redis的性能。

7.redis支持主从的模式？

答：Master会将数据同步到slave，而slave不会将数据同步到master。Slave启动时会连接master来同步数据。

8.读写分离模型？

答：为了避免Master DB的单点故障，集群一般都会采用两台Master DB做双机热备，所以整个集群的读和写的可用性都非常高。

9.redis持久化方案？

答：RDB内存快照和AOF日志文件。

10.MySQL里有2000w数据，redis中只存20w的数据，如何保证redis中的数据都是热点数据？

答：施行数据淘汰策略。

11.Redis 常见的性能问题都有哪些？如何解决？

答：

1).Master写内存快照，save命令调度rdbSave函数，会阻塞主线程的工作，当快照比较大时对性能影响是非常大的，会间断性暂停服务，所以Master最好不要写内存快照。

2).Master AOF持久化，如果不重写AOF文件，这个持久化方式对性能的影响是最小的，但是AOF文件会不断增大，AOF文件过大会影响Master重启的恢复速度。Master最好不要做任何持久化工作，包括内存快照和AOF日志文件，特别是不要启用内存快照做持久化,如果数据比较关键，某个Slave开启AOF备份数据，策略为每秒同步一次。

3).Master调用BGREWRITEAOF重写AOF文件，AOF在重写的时候会占大量的CPU和内存资源，导致服务load过高，出现短暂服务暂停现象。

4). Redis主从复制的性能问题，为了主从复制的速度和连接的稳定性，Slave和Master最好在同一个局域网内

12.redis 最适合的场景？

答：

会话缓存（Session Cache）

全页缓存（FPC）

队列

排行榜/计数器

发布/订阅

13.什么是RESP？有什么特点？

答：

RESP 是redis客户端和服务端之前使用的一种通讯协议；

RESP 的特点：实现简单、快速解析、可读性好

14.Redis 有哪些架构模式？

答：

单机版：特点：简单；问题：1、内存容量有限 2、处理能力有限 3、无法高可用。

主从复制：特点：
1、master/slave 角色
2、master/slave 数据相同
3、降低 master 读压力在转交从库
问题：
无法保证高可用
没有解决 master 写的压力

哨兵：特点：
1、保证高可用
2、监控各个节点
3、自动故障迁移
缺点：主从模式，切换需要时间丢数据
没有解决 master 写的压力

集群：（proxy 型）、（直连型）



15.使用过Redis分布式锁么，它是怎么实现的？

答：先拿setnx来争抢锁，抢到之后，再用expire给锁加一个过期时间防止锁忘记了释放。

16.使用过Redis做异步队列么，你是怎么用的？有什么缺点？

答：

17.什么是缓存穿透？如何避免？

答：一般的缓存系统，都是按照key去缓存查询，如果不存在对应的value，就应该去后端系统查找（比如DB）。

（1）：对查询结果为空的情况也进行缓存，缓存时间设置短一点，或者该key对应的数据insert了之后清理缓存。

（2）：对一定不存在的key进行过滤。可以把所有的可能存在的key放到一个大的Bitmap中，查询时通过该bitmap过滤。

18.什么是缓存雪崩？何如避免？

答：

当缓存服务器重启或者大量缓存集中在某一个时间段失效，这样在失效的时候，会给后端系统带来很大压力。导致系统崩溃。
如何避免？
（1）：在缓存失效后，通过加锁或者队列来控制读数据库写缓存的线程数量。比如对某个key只允许一个线程查询数据和写缓存，其他线程等待。
（2）：做二级缓存，A1为原始缓存，A2为拷贝缓存，A1失效时，可以访问A2，A1缓存失效时间设置为短期，A2设置为长期
（2）：不同的key，设置不同的过期时间，让缓存失效的时间点尽量均匀。
19参考：
[http://w.itcodemonkey.com/article/21.html?v=1](http://w.itcodemonkey.com/article/21.html?v=1 "redis面试题")
