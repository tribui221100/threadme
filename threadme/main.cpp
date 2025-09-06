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
    threadme::threadrun_basic(1);
    
    
    //2. Run joinable threads

    return 0;
}
