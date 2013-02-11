/***********************************************

Invensense MPU-9150 Library for ChipKit
https://github.com/AerodyneLabs/MPU9150

AeroDyne Labs - http://www.aerodynelabs.com
Copyright (c) 2012-2013 AeroDyne Labs

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

***********************************************/

#include "MPU9150.h"
/** Default constructor, uses default address.
 * @see MPU9150_ADD_DEFAULT
 */
MPU9150::MPU9150() {
	deviceAddress = MPU9150_ADD_DEFAULT;
}

/** Constructor, uses specified address.
 * @param address I2C address of the MPU9150
 * @see MPU9150_ADD_AD0_LOW
 * @see MPU9150_ADD_AD0_HIGH
 */
MPU9150::MPU9150(uint8_t address) {
	deviceAddress = address;
}
