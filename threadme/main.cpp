//
//  main.cpp
//  threadme
//
//  Created by Bùi Minh Trí on 01/09/2025.
//

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "threadhdr.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //1. Run basic thread
    threadme::threadrun_basic(0);
    
    //2. Run joinable threads
    threadme::threadrun_joinable(0);

    //3. Run mutex threads
    threadme::threadrun_mutex(0);

    //4. Run thread cancelation - duration 5s / DEFFERED 
    threadme::threadrun_cancelation(5,2);
    
    return 0;
} 
