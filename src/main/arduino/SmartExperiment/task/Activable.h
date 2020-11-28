#ifndef __ACTIVABLE_H_
#define __ACTIVABLE_H_

class Activable {

public:
     bool isActive(){
          return active;
     }

     void setActive(bool active){
          this->active = active;
     }

private:
     bool active;
     
};

#endif // __ACTIVABLE_H_

