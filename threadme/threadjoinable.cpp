//
//  threadjoinable.cpp
//  threadme
//
//  Created by Bùi Minh Trí on 01/09/2025.
//


#include "threadhdr.h"
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

namespace threadme {

pthread_t thread1; //Create thread
pthread_t thread2; //Create thread

class m_threadhelper : public ThreadHelper{
public:
    void* printMessage(void* arg) override {
        const char* message = (const char*) arg;
        for (int i = 0; i < 5; i++) {
            std::cout << message << " (iteration " << i+1 << ")" << std::endl;
            sleep(1); // pause for 1 second
        }
        pthread_exit(nullptr); //terminate the thread
    }
};

void threadrun_joinable1(void)
{
    m_threadhelper *helper = new m_threadhelper;
    auto args = new ThreadHelper::ThreadArgs{ helper, "Hi from joinable thread1" };
    pthread_create(&thread1, nullptr, helper->threadFctCallback, args);
}

void threadrun_joinable2(void)
{
    m_threadhelper *helper = new m_threadhelper;
    auto args = new ThreadHelper::ThreadArgs{ helper, "Hi from joinable thread2" };
    pthread_create(&thread2, nullptr, helper->threadFctCallback, args);
}

void threadrun_joinable(int enb)
{
    if(enb)
    {
        threadrun_joinable1();
        threadrun_joinable2();
        
        pthread_join(thread1, nullptr);
        pthread_join(thread2, nullptr);
    }
}
} //end ns

