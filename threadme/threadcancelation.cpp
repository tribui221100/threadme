//
//  threadbasic.cpp
//  threadme
//
//  Created by Bùi Minh Trí on 20/09/2025.
//

#include "threadhdr.h"
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

namespace  threadme {
class m_threadhelper {
public:
    static void* Routine(void* arg) {
        int l_specialValue = *reinterpret_cast<int*>(arg);

        for (int i = 0; i < 100; i++) {
            std::cout << "Thread is checking for cancellation...\n";
            pthread_testcancel(); // Check for cancellation request
            std::cout <<  " (iteration " << i << ")" << std::endl;
            sleep(1); // pause
        }
        return nullptr;
    
    }
    
};

void threadrun_cancelation(int cancelvalue, int canceltype)
{
    m_threadhelper *helper = new m_threadhelper;
    pthread_t thread; //Create thread
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, nullptr); /// Enable thread cancellation
    pthread_setcanceltype(canceltype, nullptr); /// Set cancellation type to deferred
    pthread_create(&thread, nullptr, helper->Routine, &cancelvalue); // Request OS to schedule for this thread
    
    sleep(cancelvalue); // Let the thread run for a while
    pthread_cancel(thread); 
    pthread_join(thread, nullptr); // Wait for the thread to finish
}
} //end ns