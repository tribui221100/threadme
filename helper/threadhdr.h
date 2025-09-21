//
//  threadhdr.h
//  threadme
//
//  Created by Bùi Minh Trí on 01/09/2025.
//

#ifndef threadhdr_h
#define threadhdr_h
namespace threadme{

/// @brief main thread function
/// @param int enb enable/disable
void threadrun_basic(int);
void threadrun_joinable(int);
void threadrun_mutex(int);
void threadrun_cancelation(int,int);

/// @brief child thread function 
/// @param void 
void threadrun_joinable1(void);
void threadrun_joinable2(void);

class ThreadHelper
{
public:
    virtual void* printMessage(void *arg) = 0;
    static void* threadFctCallback(void* arg) {
        ThreadArgs* args = static_cast<ThreadArgs*>(arg);
        void *result = args->obj->printMessage((void*) args->message);
        delete args;
        return result;
    }
    struct ThreadArgs {
        ThreadHelper* obj;
        const char* message;
    };
};
}
#endif /* threadhdr_h */
