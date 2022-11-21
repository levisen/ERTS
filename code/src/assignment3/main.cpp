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
    context->RequestSimulate();
    std::cout << "Test Succeded" << std::endl;
}

int main() {
    driver();
    return 0;
}