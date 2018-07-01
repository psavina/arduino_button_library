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

#ifndef __BUTTON_LIB_H_
#define __BUTTON_LIB_H_

class Button {
private:
  unsigned short int       _ButtonPin;
  unsigned short int       _ButtonState;
  unsigned short int       _LastButtonState;
  unsigned short int       _IsPressed;
  void                     UpdateState();

public:
  Button(unsigned short int ButtonPin);
  bool      Pressed(){return   _IsPressed == 1;}
  bool      Released(){return  _IsPressed == 2;}
  bool      Pressing(){return  _IsPressed == 3;}
  bool      NoPressed(){return _IsPressed == 0;}
};


#endif
