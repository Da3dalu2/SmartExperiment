#include "ViewerStatus.h"

ViewerStatus::ViewerStatus() {
    this->msg = "";
    this->endConfirmationReceived = false;
}

void ViewerStatus::init() {
    MsgService.init();
}

void ViewerStatus::displayStatusOnViewer(EnumState currentState) {
    switch(currentState) {
        case EnumState::Ready:
            msg = "{ready}";
            MsgService.sendMsg(msg);
            break;
        case EnumState::Running:
            msg = "{running}";
            MsgService.sendMsg(msg);
            break;
        case EnumState::Error:
            msg = "{error}";
            MsgService.sendMsg(msg);
            break;
        case EnumState::Ending:
            msg = "{ending}";
            MsgService.sendMsg(msg);
            if ( MsgService.isMsgAvailable() ) {
                String msg = MsgService.receiveMsg()->getContent();
                if ( msg == "{confirmation}") {
                    taskDirector->notifyEndConfirmationReceived(
                        endConfirmationReceived);
                    endConfirmationReceived = false;
                }
            }
            break;
        case EnumState::Suspended:
            msg = "{suspended}";
            MsgService.sendMsg(msg);
            break;
    }
}