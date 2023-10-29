#ifndef CLIENT_H_
#define CLIENT_H_

#include "common/config.h"
#include "common/pixel.h"
#include "common/topics.h"
#include <cstdio>
#include <cstring>
#include <mosquittopp.h>

class Client : public mosqpp::mosquittopp
{
  public:
    Client(const char *id, const char *host, int port) : mosqpp::mosquittopp(id)
    {
        int keepalive = 60; // seconds
        connect(host, port, keepalive);
    }

    void run()
    {
        loop_forever();
    }

    void on_connect(int rc)
    {
        printf("Connected with code %d\n", rc);
        if (rc == 0)
        {
            subscribe(NULL, BASE_TOPIC);
        }
    }

    void on_message(const mosquitto_message *message)
    {
        char buf[LED_COUNT * sizeof(RGB)];
        if (!strcmp(message->topic, BASE_TOPIC))
        {
            memset(buf, 0, sizeof(buf));
            memcpy(buf, message->payload, sizeof(buf));
            printf("\nReceived message ");
            for (int i = 0; i < LED_COUNT; i++)
            {
                printf("%d ", buf[i]);
            }
        }
    }

    void on_subscribe(int mid, int qos_count, const int *granted_qos)
    {
        printf("Subscription succeeded!\n");
    }
};

#endif /* CLIENT_H_ */
