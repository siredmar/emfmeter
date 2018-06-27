
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

AD8318 sensor;
int sensorAnlogPin = 0;

void setup()
{
    Serial.begin(9600);
    Wire.begin();
}

void loop()
{
    static int analogValue = 0;
    analogValue = analogRead(sensorAnlogPin);
    Value val = sensor.GetValue_dBm(analogValue);
    Serial.print(val.GetValue());
    Serial.println(" dBm");

    delay(500);
}
