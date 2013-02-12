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

bool MPU9150::testConnection() {
	return getDeviceID() == 0x68;
}

void MPU9150::getSelfTestTrim(
		uint8_t *xa, uint8_t *ya, uint8_t *za,
		uint8_t *xg, uint8_t *yg, uint8_t *zg) {
	I2Cdev::readBytes(deviceAddress, MPU9150_REG_SELF_TEST_X, 4, buffer);
	&xg = buffer[0] && MPU9150_GYRO_TRIM;
	&yg = buffer[1] && MPU9150_GYRO_TRIM;
	&zg = buffer[2] && MPU9150_GYRO_TRIM;
	&xa = ((buffer[0] && MPU9150_ACCEL_TRIM_HIGH) >> 3) ||
			((buffer[3] && MPU9150_XACCEL_TRIM_LOW) >> 4);
	&ya = ((buffer[1] && MPU9150_ACCEL_TRIM_HIGH) >> 3) ||
			((buffer[3] && MPU9150_YACCEL_TRIM_LOW) >> 2);
	&za = ((buffer[2] && MPU9150_ACCEL_TRIM_HIGH) >> 3) ||
			(buffer[3] && MPU9150_ZACCEL_TRIM_LOW);
}

uint8_t MPU9150::getSampleRateDivider() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_SMPRT_DIV, buffer);
	return buffer[0];
}

void MPU9150::setSampleRateDivider(uint8_t div) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_SMPRT_DIV, div);
}

uint8_t MPU9150::getConfig() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_CONFIG, buffer);
	return buffer[0];
}

void MPU9150::setConfig(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_CONFIG, config);
}

uint8_t MPU9150::getGyroConfig() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_GYRO_CONFIG, buffer);
	return buffer[0];
}

void MPU9150::setGyroConfig(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_GYRO_CONFIG, config);
}

uint8_t MPU9150::getAccelConfig() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_ACCEL_CONFIG, buffer);
	return buffer[0];
}

void MPU9150::setAccelConfig(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_ACCEL_CONFIG, config);
}

uint8_t MPU9150::getFreefallThreshold() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_FF_THR, buffer);
	return buffer[0];
}

void MPU9150::setFreefallThreshold(uint8_t thr) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_FF_THR, thr);
}

uint8_t MPU9150::getFreefallDuration(){
	I2Cdev::readByte(deviceAddress, MPU9150_REG_FF_DUR, buffer);
	return buffer[0];
}

void MPU9150::setFreefallDuration(uint8_t dur) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_FF_DUR, dur);
}

uint8_t MPU9150::getMotionThreshold() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_MOT_THR, buffer);
	return buffer[0];
}

void MPU9150::setMotionThreshold(uint8_t thr) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_MOT_THR, thr);
}

uint8_t MPU9150::getMotionDuration() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_MOT_DUR, buffer);
	return buffer[0];
}

void MPU9150::setMotionDuration(uint8_t dur) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_MOT_DUR, dur);
}

uint8_t MPU9150::getZeroMotionThreshold() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_ZMOT_THR, buffer);
	return buffer[0];
}

void MPU9150::setZeroMotionThreshold(uint8_t thr) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_ZMOT_THR, thr);
}

uint8_t MPU9150::getZeroMotionDuration() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_ZMOT_DUR, buffer);
	return buffer[0];
}

void MPU9150::setZeroMotionDuration(uint8_t dur) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_ZMOT_DUR, dur);
}

uint8_t MPU9150::getFifoEn() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_FIFO_EN, buffer);
	return buffer[0];
}

void MPU9150::setFifoEn(uint8_t config) {
	I2Cdev::writeByte(deviceAddresss, MPU9150_REG_FIFO_EN, config);
}

uint8_t MPU9150::getI2CMasterControl() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_MST_CTRL, buffer);
	return buffer[0];
}

void MPU9150::setI2CMasterControl(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_MST_CTRL, config);
}

uint8_t MPU9150::getI2CSlave0Address() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV0_ADDR, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave0Address(uint8_t addr) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV0_ADDR, addr);
}

uint8_t MPU9150::getI2CSlave0Register() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV0_REG, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave0Register(uint8_t ra) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV0_REG, ra);
}

uint8_t MPU9150::getI2CSlave0Control() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV0_CTRL, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave0Control(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV0_CTRL, config);
}

uint8_t MPU9150::getI2CSlave1Address() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV1_ADDR, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave1Address(uint8_t addr) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV1_ADDR, addr);
}

uint8_t MPU9150::getI2CSlave1Register() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV1_REG, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave1Register(uint8_t ra) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV1_REG, ra);
}

uint8_t MPU9150::getI2CSlave1Control() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV1_CTRL, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave1Control(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV1_CTRL, config);
}

uint8_t MPU9150::getI2CSlave2Address() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV2_ADDR, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave2Address(uint8_t addr) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV2_ADDR, addr);
}

uint8_t MPU9150::getI2CSlave2Register() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV2_REG, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave2Register(uint8_t ra) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV2_REG, ra);
}

uint8_t MPU9150::getI2CSlave2Control() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV2_CTRL, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave2Control(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV2_CTRL, config);
}

uint8_t MPU9150::getI2CSlave3Address() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV3_ADDR, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave3Address(uint8_t addr) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV3_ADDR, addr);
}

uint8_t MPU9150::getI2CSlave3Register() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV3_REG, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave3Register(uint8_t ra) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV3_REG, ra);
}

uint8_t MPU9150::getI2CSlave3Control() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV3_CTRL, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave3Control(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV3_CTRL, config);
}

uint8_t MPU9150::getI2CSlave4Address() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV4_ADDR, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave4Address(uint8_t addr) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV4_ADDR, addr);
}

uint8_t MPU9150::getI2CSlave4Register() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV4_REG, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave4Register(uint8_t ra) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV4_REG, ra);
}

uint8_t MPU9150::getI2CSlave4DataOut() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV4_DO, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave4DataOut(uint8_t data) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV4_DO, data);
}

uint8_t MPU9150::getI2CSlave4Control() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV4_CTRL, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave4Control(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_I2C_SLV4_CTRL, config);
}

uint8_t MPU9150::getI2CSlave4DataIn() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_SLV4_DI, buffer);
	return buffer[0];
}

void MPU9150::setI2CSlave4DataIn(uint8_t data) {
	I2Cdev::writeBuffer(deviceAddress, MPU9150_REG_I2C_SLV4_DI, data);
}

uint8_t MPU9150::getI2CMasterStatus() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_I2C_MST_STATUS, buffer);
	return buffer[0];
}

uint8_t MPU9150::getInterruptPinConfig() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_INT_PIN_CFG, buffer);
	return buffer[0];
}

void MPU9150::setIntrruptPinConfig(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_INT_PIN_CFG, config);
}

uint8_t MPU9150::getInterruptConfig() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_INT_ENABLE, buffer);
	return buffer[0];
}

void MPU9150::setIntrruptConfig(uint8_t config) {
	I2Cdev::writeByte(deviceAddress, MPU9150_REG_INT_ENABLE, config);
}

uint8_t MPU9150::getIntrruptStatus() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_INT_STATUS, buffer);
	return buffer[0];
}

uint8_t MPU9150::getDeviceID() {
	I2Cdev::readByte(deviceAddress, MPU9150_REG_WHO_AM_I, buffer);
	return buffer[0];
}
