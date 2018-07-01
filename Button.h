#ifndef __BUTTON_LIB_H_
#define __BUTTON_LIB_H_

class Button {
private:
  unsigned short int       _ButtonPin;
  unsigned short int       _ButtonState;
  unsigned short int       _LastButtonState;
  unsigned short int       _KeyPressed;
  unsigned short int       _KeyReleased;
  unsigned short int       _KeyPressing;
  unsigned short int       _NoKeyPressed;

public:
  Button(unsigned short int ButtonPin);
  void      UpdateState();
  bool      Pressed(){return _KeyPressed == 1;}
  bool      Released(){return _KeyReleased == 1;}
  bool      Pressing(){return _KeyPressing == 1;}
  bool      NoPressed(){return _NoKeyPressed == 1;}
};


#endif
