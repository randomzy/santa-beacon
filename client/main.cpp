#include "client/client.h"
#include "common/config.h"

int main()
{
    Client client(CLIENT_ID, HOST, PORT);
    client.run();
}
