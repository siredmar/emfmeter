
/* Copyright (C) 2017 Armin Schlegel. All rights reserved.

This software may be distributed and modified under the terms of the GNU
General Public License version 2 (GPL2) as published by the Free Software
Foundation and appearing in the file GPL2.TXT included in the packaging of
this file. Please note that GPL2 Section 2[b] requires that all works based
on this software must also be made publicly available under the terms of
the GPL2 ("Copyleft").
*/

#include <Arduino.h>
#include <Wire.h>
#include "AD8318.h"

String inString = "";
unsigned int delayUs = 200;
AD8318 sensor();

void setup()
{
    Serial.begin(9600);
    Wire.begin();
}

void loop()
{
    if(Serial.available())
    {
        int inChar = Serial.read();

        if (inChar != '\n')
        {
            inString += (char)inChar;
        }
        else
        {
            inString = "";
        }

    }
    delayMicroseconds(delayUs);
}
