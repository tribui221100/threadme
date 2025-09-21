//
//  threadmutex.cpp
//  threadme
//
//  Created by Bùi Minh Trí on 14/09/2025.
//


#include "threadhdr.h"
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

namespace threadme {

constexpr int THREAD_COUNT{5};
constexpr long MAX_COUNT{1000000};
long counter{0};

pthread_t m_thread[THREAD_COUNT]; //Create thread
pthread_mutex_t locker; //Create mutex locker

void* Routine(void* arg) {
    int thread_id = *reinterpret_cast<int*>(arg);
    for (int i = 0; i < MAX_COUNT; i++) {
        pthread_mutex_lock(&locker); //Lock the mutex before accessing the shared resource
        counter++; //Increment the shared resource
        pthread_mutex_unlock(&locker); //Unlock the mutex after accessing the shared resource
    }
    std::cout << "Thread " << thread_id << " finished work.\n";
    return nullptr;
}

void threadrun_mutex(int enb)
{
    if(enb)
    {
        int ids[THREAD_COUNT];
        pthread_mutex_init(&locker, nullptr); //Initialize the mutex locker
        for(int i = 0; i < THREAD_COUNT; i++) {
            ids[i] = i;
            pthread_create(&m_thread[i], nullptr, Routine, &ids[i]); // Request OS to schedule for this threa
        }
        for(int i = 0; i < THREAD_COUNT; i++) {
            pthread_join(m_thread[i], nullptr); // Wait for the thread to complete
        }
        std::cout << "Final counter value: " << counter << std::endl;
        pthread_mutex_destroy(&locker); //Destroy the mutex locker
    }
}
} //end ns

