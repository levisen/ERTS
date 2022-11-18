#include "system.h"

void driver(){
    Context *context;
    context = new Context(new PowerOnSelfTest);
    context->RequestSelfTestOk();
    std::cout << "test succeded" << std::endl;
}

int main() {
    driver();
    return 0;
}