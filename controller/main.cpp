#include "common/config.h"
#include "controller/controller.h"

int main()
{
    Controller controller(CONTROLLER_ID, HOST, PORT);
    controller.run();
}
