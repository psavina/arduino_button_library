#include "Button.h"

Button::Button(unsigned short int ButtonPin){
  _ButtonPin = ButtonPin;
  _ButtonState = 0;
  _LastButtonState = 0;
  _KeyPressed = 0;
  _KeyReleased = 0;
  _KeyPressing = 0;
  _NoKeyPressed = 0;
}

void Button::UpdateState(){
  int CurrentState = digitalRead(_ButtonPin);
  if(CurrentState != _LastButtonState){
    if(_KeyPressed == 0 && _KeyPressing == 0){
      _KeyPressed = 1;
    }

    if(_KeyPressing == 1){
      _KeyReleased = 1;
      _KeyPressing = 0;
    }
  }
  else{
    if(_KeyPressed == 1){
      _KeyPressed = 0;
      _KeyPressing = 1;
    }
    if(_KeyReleased == 1){
      _KeyReleased = 0;
      _KeyPressing = 0;  
    }  
  }
  if(_KeyReleased == 0 && _KeyPressing == 0 && _KeyPressed == 0)
    _NoKeyPressed = 1;
  else
    _NoKeyPressed = 0;
  _LastButtonState = CurrentState;
}
