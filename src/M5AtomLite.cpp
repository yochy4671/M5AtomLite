// Copyright (c) M5Stack. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "M5AtomLite.h"

M5AtomLite::M5AtomLite()
{

}

M5AtomLite::~M5AtomLite()
{

}

void M5AtomLite::begin(bool SerialEnable , bool I2CEnable , bool DisplayEnable )
{
	if( _isInited ) return;

	_isInited = true;

	if( I2CEnable )
	{
		Wire.begin(25,21,10000);
	}
	if( SerialEnable )
	{
		Serial.begin(115200);
		Serial.flush();
		delay(50);
		Serial.println("M5AtomLite initializing...OK");
	}

	if( DisplayEnable )
	{
        dis.begin();
		dis.setTaskName("LEDs");
		dis.setTaskPriority(2);
		dis.start();
	}



}

void M5AtomLite::update()
{
	M5.Btn.read();
}

M5AtomLite M5;