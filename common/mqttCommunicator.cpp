#include "common/mqttCommunicator.h"

#include <mosquittopp.h>

void MqttCommunicator::sendMessage(const char *topic, const char *message, uint32_t size)
{
}

void MqttCommunicator::setOnMessageReceive(OnReceiveFn onReceiveFn)
{
}

void MqttCommunicator::subscribe()
{
}

void MqttCommunicator::unsubscribe()
{
}
