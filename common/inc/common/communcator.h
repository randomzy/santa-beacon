#ifndef COMMUNCATOR_H_
#define COMMUNCATOR_H_

#include <cinttypes>

using OnReceiveFn = uint32_t (*)(const char *topic, char *message, uint32_t sized);

class Communicator
{
  public:
    virtual void sendMessage(const char *topic, const char *message, uint32_t size) = 0;
    virtual void setOnMessageReceive(OnReceiveFn onReceiveFn) = 0;
    virtual void subscribe() = 0;
    virtual void unsubscribe() = 0;
};

#endif /* COMMUNCATOR_H_ */
