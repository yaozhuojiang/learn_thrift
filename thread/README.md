# learn_thread

## thread

创建即开始执行

eg: thread.cpp

### mutex

互斥量，对共享资源进行保护

eg：mutex.cpp

### 死锁

可能拿锁跑路，可能竞争锁

解决方法：使用 lock_gurad/unique_lock，std::lock()

eg：deadlock1.cpp deadlock2.cpp

### atomic

原子操作

eg：atomic.cpp

### condition_variable

eg：condition_variable.cpp

### promise future

eg：promise_future.cpp

### async

eg：async.cpp
