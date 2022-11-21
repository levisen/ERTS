#include "system.h"

/**
 * Test code
 * 
 */

void driver(){
    Context *context;
    context = new Context(new PowerOnSelfTest);
    context->RequestSelfTestOk();
    context->RequestExit();
    context->RequestInitialized();

    std::cout << "test succeded" << std::endl;
}

int main() {
    driver();
    return 0;
}