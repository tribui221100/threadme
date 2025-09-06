//
//  threadbasic.cpp
//  threadme
//
//  Created by Bùi Minh Trí on 01/09/2025.
//

#include "threadhdr.h"
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

namespace  threadme {
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

void threadrun_basic(int enb)
{
    if(enb)
    {
        m_threadhelper *helper = new m_threadhelper;
        pthread_t thread; //Create thread
        auto* args = new ThreadHelper::ThreadArgs{ helper, "Hi from thread1" };
        pthread_create(&thread, nullptr, helper->threadFctCallback, args); // Request OS to schedule for this thread
        //POSIX system call to keep main thread alive - affect the whole thread
        //Exist until received SIGINT from Ctrl + C - applied for linux system
        //pause();
        // for windows system - join the thread
        pthread_join(thread, nullptr); // Wait for the thread to finish
    }
}
}



