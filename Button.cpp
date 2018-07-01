/*
 * ===========================================================
 * Button library
 * ===========================================================
 * author: psavina
 * version: 1.0
 * date: 2018-07-01
 * -----------------------------------------------------------
 * A simple library to handle buttons.
 * There are 4 different states:
 * - Pressed:      Check if a button was pressed.
 * - Released:     Check if a button was released.
 * - Pressing:     Check if a button is currently pressed.
 * - NoKeyPressed: Check if a button is not pressed.
 * ----------------------------------------------------------
 *
 * Copyright (c) 2018 psavina
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *
 * Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */



#include "Button.h"

Button::Button(unsigned short int ButtonPin){
  _ButtonPin = ButtonPin;
  _LastButtonState = 0;
  _IsPressed = 0;
}

void Button::UpdateState(){
  int CurrentState = digitalRead(_ButtonPin);
  
  if(CurrentState != _LastButtonState){
    if(_IsPressed == 0){
      _IsPressed = 1;
      _LastButtonState = CurrentState;
      return;
    }

    if(_IsPressed == 3){
      _IsPressed = 2;
      _LastButtonState = CurrentState;
      return;
    }
  }
  else{
    if(_IsPressed == 1){
      _IsPressed = 3;
      _LastButtonState = CurrentState;
      return;
    }
    if(_IsPressed == 2){
      _IsPressed = 0;
      _LastButtonState = CurrentState;
      return;
    }  
  }

  _IsPressed = 0;
  _LastButtonState = CurrentState;
  return;
}
