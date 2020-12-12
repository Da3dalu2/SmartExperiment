#ifndef __VIEWER_STATUS_H_
#define __VIEWER_STATUS_H_

#include "MsgService.h"
#include "State.h"
#include "Communicator.h"
#include "TaskDirector.h"
#include "EnumState.h"

class ViewerStatus: public Communicator {

public:
    ViewerStatus();
    void init();
    void displayStatusOnViewer(EnumState currentState);

private:
    TaskDirector* taskDirector;
    EnumState previousState;
};

#endif // __VIEWER_STATUS_H_