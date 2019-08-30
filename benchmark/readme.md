生成1000W个长度为32的id, 消耗时间如下所示.
```
$ time ./kid/benchmark/rand 

real    1m40.221s
user    1m39.220s
sys     0m0.888s

$ time ./kid/benchmark/uuid

real    2m2.592s
user    1m54.692s
sys     0m7.824s
```


在查看火焰图之后, 发现, 该库的瓶颈在于`std::set<std::string>::emplace(std::string)`上. 消耗了大量的时间, 将其插入set中. 

如果没有一定要保持id池的需求, 那么直接使用雪花算法生成唯一id是更好的选择.
