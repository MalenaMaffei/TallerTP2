#ifndef TP2_THREAD_H
#define TP2_THREAD_H

#include <thread>
#include <iostream>
//class Thread {
//public:
//    Thread ();
//
//    void start();
//
//    void join();
//
//    virtual void run() = 0;
//    virtual ~Thread();
//
////    Thread(const Thread&);
////    Thread& operator=(const Thread&);
////
//    Thread(Thread&& other);
////
////    Thread& operator=(Thread&& other);
//private:
//    std::thread thread;
//};
class Thread {
private:
    std::thread thread;

public:
    Thread() {}

    void start() {
//        std::cout << "entro a start" << std::endl;
        thread = std::thread(&Thread::run, this);
    }

    void join() {
        thread.join();
    }

    virtual void run() = 0;
//    virtual ~Thread() {}

    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;

    Thread(Thread&& other) {
        this->thread = std::move(other.thread);
    }

    Thread& operator=(Thread&& other) {
        this->thread = std::move(other.thread);
        return *this;
    }
};


#endif //TP2_THREAD_H
