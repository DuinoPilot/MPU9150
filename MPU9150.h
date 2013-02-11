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

#ifndef MPU9150_H
#define MPU9150_H

/** Device Addresses (7 bit) **/
#define MPU9150_ADD_AD0_LOW		0x68
#define MPU9150_ADD_AD0_HIGH	0x69
#define MPU9150_ADD_DEFAULT		MPU_ADD_AD0_LOW

/** Register Addresses for Accel & Gyro **/
#define MPU9150_REG_SELF_TEST_X		0x0d
#define MPU9150_REG_SELF_TEST_Y		0x0e
#define MPU9150_REG_SELF_TEST_Z		0x0f
#define MPU9150_REG_SELF_TEST_A		0x10

#define MPU9150_REG_SMPRT_DIV		0x19
#define MPU9150_REG_CONFIG			0x1a
#define MPU9150_REG_GYRO_CONFIG		0x1b
#define MPU9150_REG_ACCEL_CONFIG	0x1c

#define MPU9150_REG_FF_THR			0x1d
#define MPU9150_REG_FF_DUR			0x1e
#define MPU9150_REG_MOT_THR			0x1f
#define MPU9150_REG_MOT_DUR			0x20
#define MPU9150_REG_ZRMOT_THR		0x21
#define MPU9150_REG_ZRMOT_DUR		0x22

#define MPU9150_REG_FIFO_EN			0x23
#define MPU9150_REG_I2C_MST_CTRL	0x24
#define MPU9150_REG_I2C_SLV0_ADDR	0x25
#define MPU9150_REG_I2C_SLV0_REG	0x26
#define MPU9150_REG_I2C_SLV0_CTRL	0x27
#define MPU9150_REG_I2C_SLV1_ADDR	0x28
#define MPU9150_REG_I2C_SLV1_REG	0x29
#define MPU9150_REG_I2C_SLV1_CTRL	0x2a
#define MPU9150_REG_I2C_SLV2_ADDR	0x2b
#define MPU9150_REG_I2C_SLV2_REG	0x2c
#define MPU9150_REG_I2C_SLV2_CTRL	0x2d
#define MPU9150_REG_I2C_SLV3_ADDR	0x2e
#define MPU9150_REG_I2C_SLV3_REG	0x2f
#define MPU9150_REG_I2C_SLV3_CTRL	0x30
#define MPU9150_REG_I2C_SLV4_ADDR	0x31
#define MPU9150_REG_I2C_SLV4_REG	0x32
#define MPU9150_REG_I2C_SLV4_DO		0x33
#define MPU9150_REG_I2C_SLV4_CTRL	0x34
#define MPU9150_REG_I2C_SLV4_DI		0x35
#define MPU9150_REG_I2C_MST_STATUS	0x36

#define MPU9150_REG_INT_PIN_CFG		0x37
#define MPU9150_REG_INT_ENABLE		0x38
#define MPU9150_REG_INT_STATUS		0x3a

#define MPU9150_REG_ACCEL_XOUT_H	0x3b
#define MPU9150_REG_ACCEL_XOUT_L	0x3c
#define MPU9150_REG_ACCEL_YOUT_H	0x3d
#define MPU9150_REG_ACCEL_YOUT_L	0x3e
#define MPU9150_REG_ACCEL_ZOUT_H	0x3f
#define MPU9150_REG_ACCEL_ZOUT_L	0x40
#define MPU9150_REG_TEMP_OUT_H		0x41
#define MPU9150_REG_TEMP_OUT_L		0x42
#define MPU9150_REG_GYRO_XOUT_H		0x43
#define MPU9150_REG_GYRO_XOUT_L		0x44
#define MPU9150_REG_GYRO_YOUT_H		0x45
#define MPU9150_REG_GYRO_YOUT_L		0x46
#define MPU9150_REG_GYRO_ZOUT_H		0x47
#define MPU9150_REG_GYRO_ZOUT_L		0x48

#define MPU9150_REG_EXT_SENS_DATA_00	0x49
#define MPU9150_REG_EXT_SENS_DATA_01	0x4a
#define MPU9150_REG_EXT_SENS_DATA_02	0x4b
#define MPU9150_REG_EXT_SENS_DATA_03	0x4c
#define MPU9150_REG_EXT_SENS_DATA_04	0x4d
#define MPU9150_REG_EXT_SENS_DATA_05	0x4e
#define MPU9150_REG_EXT_SENS_DATA_06	0x4f
#define MPU9150_REG_EXT_SENS_DATA_07	0x50
#define MPU9150_REG_EXT_SENS_DATA_08	0x51
#define MPU9150_REG_EXT_SENS_DATA_09	0x52
#define MPU9150_REG_EXT_SENS_DATA_10	0x53
#define MPU9150_REG_EXT_SENS_DATA_11	0x54
#define MPU9150_REG_EXT_SENS_DATA_12	0x55
#define MPU9150_REG_EXT_SENS_DATA_13	0x56
#define MPU9150_REG_EXT_SENS_DATA_14	0x57
#define MPU9150_REG_EXT_SENS_DATA_15	0x58
#define MPU9150_REG_EXT_SENS_DATA_16	0x59
#define MPU9150_REG_EXT_SENS_DATA_17	0x5a
#define MPU9150_REG_EXT_SENS_DATA_18	0x5b
#define MPU9150_REG_EXT_SENS_DATA_19	0x5c
#define MPU9150_REG_EXT_SENS_DATA_20	0x5d
#define MPU9150_REG_EXT_SENS_DATA_21	0x5e
#define MPU9150_REG_EXT_SENS_DATA_22	0x5f
#define MPU9150_REG_EXT_SENS_DATA_23	0x60

#define MPU9150_REG_MOT_DETECT_STATUS	0x61

#define MPU9150_REG_I2C_SLV0_DO			0x63
#define MPU9150_REG_I2C_SLV1_DO			0x64
#define MPU9150_REG_I2C_SLV2_DO			0x65
#define MPU9150_REG_I2C_SLV3_DO			0x66

#define MPU9150_REG_I2C_MST_DELAY_CTRL	0x67

#define MPU9150_REG_SIGNAL_PATH_RESET	0x68

#define MPU9150_REG_MOT_DETECT_CTRL		0x69

#define MPU9150_REG_USER_CTRL			0x6a
#define MPU9150_REG_PWR_MGMT_1			0x6b
#define MPU9150_REG_PWR_MGMT_2			0x6c

#define MPU9150_REG_FIFO_COUNT_H		0x72
#define MPU9150_REG_FIFO_COUNT_L		0x73
#define MPU9150_REG_FIFO_R_W			0x74

#define MPU9150_REG_WHO_AM_I			0x75

/** Register Addreses for Mag **/
#define MPU9150_REG_WIA		0x00
#define MPU9150_REG_INFO	0x01
#define MPU9150_REG_ST1		0x02

#define MPU9150_REG_HXL		0x03
#define MPU9150_REG_HXH		0x04
#define MPU9150_REG_HYL		0x05
#define MPU9150_REG_HYH		0x06
#define MPU9150_REG_HZL		0x07
#define MPU9150_REG_HZH		0x08

#define MPU9150_REG_ST2		0x09
#define MPU9150_REG_CNTL	0x0a
#define MPU9150_REG_RSV		0x0b
#define MPU9150_REG_ASTC	0x0c

#define MPU9150_REG_TS1		0x0d
#define MPU9150_REG_TS2		0x0e
#define MPU9150_REG_I2CDIS	0x0f

#define MPU9150_REG_ASAX	0x10
#define MPU9150_REG_ASAY	0x11
#define MPU9150_REG_ASAZ	0x12

class MPU9150{
	public:
		MPU9150();
		MPU9150(uint8_t address);
		
	private:
		uint8_t deviceAddress;
}

#endif
