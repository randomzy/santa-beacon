#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "common/config.h"
#include "common/pixel.h"
#include "common/topics.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <mosquittopp.h>

class Controller : public mosqpp::mosquittopp
{
  public:
    Controller(const char *id, const char *host, int port) : mosqpp::mosquittopp(id)
    {
        int keepalive = 60; // seconds
        connect(host, port, keepalive);
    }

    ~Controller()
    {
        std::cout << "destructor called" << std::endl;
        disconnect();
        loop_stop();
    }

    void run()
    {
        loop_start();
        for (int i = 0; i < 10; i++)
        {
            std::cout << "Sending frame" << i << std::endl;
            sendFrame();
        }
    }

    void sendFrame()
    {
        char buf[LED_COUNT * sizeof(RGB)];
        publish(nullptr, BASE_TOPIC, sizeof(buf), buf);
    }

    void on_connect(int rc)
    {
        std::cout << "Connected with status " << rc << std::endl;
        if (rc == 0)
        {
            subscribe(NULL, BASE_TOPIC);
        }
    }

    void on_subscribe(int mid, int qos_count, const int *granted_qos)
    {
        std::cout << "Subscription succeeded" << std::endl;
    }
};

#endif /* CONTROLLER_H_ */
