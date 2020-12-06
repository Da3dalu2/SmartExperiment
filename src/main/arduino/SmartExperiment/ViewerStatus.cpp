#include "ViewerStatus.h"

ViewerStatus::ViewerStatus() {
    this->previousState = EnumState::Ending;
}

void ViewerStatus::init() {
    MsgService.init();
}

void ViewerStatus::displayStatusOnViewer(EnumState currentState) {

    if (currentState != previousState ) {
        switch(currentState) {
        case EnumState::Ready:
            MsgService.sendMsg("{ready}");
            break;
        case EnumState::Running:
            MsgService.sendMsg("{running}");
            break;
        case EnumState::Error:
            MsgService.sendMsg("{error}");
            break;
        case EnumState::Ending:
            MsgService.sendMsg("{ending}");
            break;
        case EnumState::Suspended:
            MsgService.sendMsg("{suspended}");
            break;
        }
    }

    if ( currentState == EnumState::Ending && MsgService.isMsgAvailable() ) {
        String msg = MsgService.receiveMsg()->getContent();
        if ( msg == "{exitConfirmed}") {
            bool endConfirmationReceived = true;
            bool exitConfirmed = true;
            taskDirector->notifyEndConfirmationReceived(
                endConfirmationReceived, exitConfirmed);
        } else if (msg == "{exitNotConfirmed}") {
            bool endConfirmationReceived = true;
            bool exitConfirmed = false;
            taskDirector->notifyEndConfirmationReceived(
                endConfirmationReceived, exitConfirmed);
        }
    }

    previousState = currentState;   
}