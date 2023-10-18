#ifndef MQTTCOMMUNICATOR_H_
#define MQTTCOMMUNICATOR_H_

#include "communcator.h"

class MqttCommunicator : public Communicator
{
    void sendMessage(const char *topic, const char *message, uint32_t size);
    void setOnMessageReceive(OnReceiveFn onReceiveFn);
    void subscribe();
    void unsubscribe();
};

#endif /* MQTTCOMMUNICATOR_H_ */
