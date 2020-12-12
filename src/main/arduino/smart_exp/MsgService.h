#ifndef __MSGSERVICE_H_
#define __MSGSERVICE_H_

#include "Arduino.h"

class Msg {
  String content;

public:
  Msg(String content) {
    this->content = content;
  }
  
  String getContent(){
    return content;
  }
};

class MsgServiceClass {
    
public: 
  
  Msg* currentMsg;
  bool msgAvailable;

  void init();  

  bool isMsgAvailable();
  Msg* receiveMsg();

  void sendMsg(String msg);
};

extern MsgServiceClass MsgService;

#endif // __MSGSERVICE_H_