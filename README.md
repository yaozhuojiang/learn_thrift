# learn_thrift

vim match.thrift

thrift -r --gen cpp match.thrift

g++ -c main.cpp match_server/*.cpp

g++ *.o -o main -lthrift