#ifndef CLIENT_H_
#define CLIENT_H_

#include "common/communcator.h"

class Client
{
  public:
    Client(Communicator *communicator);
    void run();

  private:
    Communicator *m_communicator;
};

#endif /* CLIENT_H_ */
