#ifndef __VIEWER_STATUS_H_
#define __VIEWER_STATUS_H_

#include "MsgService.h"
#include "State.h"

class ViewerStatus {

public:
    ViewerStatus();
    void init();
    void displayStatusOnViewer(EnumState currentState);
};

#endif // __VIEWER_STATUS_H_