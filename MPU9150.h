/************************************************

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

************************************************/
// Requires JRowberg's I2Cdev library
// https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/I2Cdev

#ifndef MPU9150_H
#define MPU9150_H

#include "I2Cdev.h"

/** Device Addresses (7 bit) **/
#define MPU9150_ADD_AD0_LOW		0x68
#define MPU9150_ADD_AD0_HIGH	0x69
#define MPU9150_ADD_DEFAULT		MPU_ADD_AD0_LOW
#define MPU9150_ADD_MAG			0x0c

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

/** Bit Masks (OR together) **/
// Self Test Trim
#define MPU9150_GYRO_TRIM		0b00011111
#define MPU9150_ACCEL_TRIM_HIGH	0b11100000
#define MPU9150_XACCEL_TRIM_LOW	0b00110000
#define MPU9150_YACCEL_TRIM_LOW	0b00001100
#define MPU9150_ZACCEL_TRIM_LOW	0b00000011

// Config
#define MPU9150_EXT_SYNC_DISABLED	0b00000000
#define MPU9150_EXT_SYNC_TEMP_OUT	0b00001000
#define MPU9150_EXT_SYNC_GYRO_XOUT	0b00010000
#define MPU9150_EXT_SYNC_GYRO_YOUT	0b00011000
#define MPU9150_EXT_SYNC_GYRO_ZOUT	0b00100000
#define MPU9150_EXT_SYNC_ACCEL_XOUT	0b00101000
#define MPU9150_EXT_SYNC_ACCEL_YOUT	0b00110000
#define MPU9150_EXT_SYNC_ACCEL_ZOUT	0b00111000
#define MPU9150_DLPF_CFG_0	0b00000000	// Accel:260Hz, Gyro:256Hz, Fs:8kHz
#define MPU9150_DLPF_CFG_1	0b00000001	// Accel:184Hz, Gyro:188Hz, Fs:1kHz
#define MPU9150_DLPF_CFG_2	0b00000010	// Accel:94Hz, Gyro:98Hz, Fs:1kHz
#define MPU9150_DLPF_CFG_3	0b00000011	// Accel:44Hz, Gyro:42Hz, Fs:1kHz
#define MPU9150_DLPF_CFG_4	0b00000100	// Accel:21Hz, Gyro:20Hz, Fs:1kHz
#define MPU9150_DLPF_CFG_5	0b00000101	// Accel:10Hz, Gyro:10Hz, Fs:1kHz
#define MPU9150_DLPF_CFG_6	0b00000110	// Accel:5Hz, Gyro:5Hz, Fs:1kHz
#define MPU9150_DLPF_CFG_7	0b00000111	// Fs: 8kHz, No filter

// Gyro Config
#define MPU9150_XG_ST	0b10000000
#define MPU9150_YG_ST	0b01000000
#define MPU9150_ZG_ST	0b00100000
#define MPU9150_FS_SEL_250	0b00000000
#define MPU9150_FS_SEL_500	0b00001000
#define MPU9150_FS_SEL_1000	0b00010000
#define MPU9150_FS_SEL_2000	0b00011000

// Accel Config
#define MPU9150_XA_ST	0b10000000
#define MPU9150_YA_ST	0b01000000
#define MPU9150_ZA_ST	0b00100000
#define MPU9150_AFS_SEL_2	0b00000000
#define MPU9150_AFS_SEL_4	0b00001000
#define MPU9150_AFS_SEL_8	0b00010000
#define MPU9150_AFS_SEL_16	0b00011000
#define MPU9150_DHPF_OFF	0b00000000
#define MPU9150_DHPF_5		0b00000001
#define MPU9150_DHPF_2_5	0b00000010
#define MPU9150_DHPF_1_25	0b00000011
#define MPU9150_DHPF_0_63	0b00000100
#define MPU9150_DHPF_HOLD	0b00000111

// Fifo Enable
#define MPU9150_FIFO_TEMP_EN	0b10000000
#define MPU9150_FIFO_XG_EN		0b01000000
#define MPU9150_FIFO_YG_EN		0b00100000
#define MPU9150_FIFO_ZG_EN		0b00010000
#define MPU9150_FIFO_ACCEL_EN	0b00001000
#define MPU9150_FIFO_SLV2_EN	0b00000100
#define MPU9150_FIFO_SLV1_EN	0b00000010
#define MPU9150_FIFO_SLV0_EN	0b00000001

// I2C Master Control
#define MPU9150_MULT_MST_EN		0b10000000
#define MPU9150_WAIT_FOR_ES		0b01000000
#define MPU9150_SLV3_FIFO_EN	0b00100000
#define MPU9150_I2C_MST_P_NSR	0b00010000
#define MPU9150_I2C_MST_CLK_348	0b00000000
#define MPU9150_I2C_MST_CLK_333	0b00000001
#define MPU9150_I2C_MST_CLK_320 0b00000010
#define MPU9150_I2C_MST_CLK_308	0b00000011
#define MPU9150_I2C_MST_CLK_296	0b00000100
#define MPU9150_I2C_MST_CLK_286	0b00000101
#define MPU9150_I2C_MST_CLK_276	0b00000110
#define MPU9150_I2C_MST_CLK_267	0b00000111
#define MPU9150_I2C_MST_CLK_258	0b00001000
#define MPU9150_I2C_MST_CLK_500	0b00001001
#define MPU9150_I2C_MST_CLK_471	0b00001010
#define MPU9150_I2C_MST_CLK_444	0b00001011
#define MPU9150_I2C_MST_CLK_421	0b00001100
#define MPU9150_I2C_MST_CLK_400	0b00001101
#define MPU9150_I2C_MST_CLK_381	0b00001110
#define MPU9150_I2C_MST_CLK_364	0b00001111

// I2C Slave Control
#define MPU9150_I2C_SLV_READ	0b10000000
#define MPU9150_I2C_SLV_WRITE	0b00000000
#define MPU9150_I2C_SLV_EN		0b10000000
#define MPU9150_I2C_SLV_BYTE_SW	0b01000000
#define MPU9150_I2C_SLV_REG_DIS	0b00100000
#define MPU9150_I2C_SLV_GRP		0b00010000
#define MPU9150_I2C_SLV4_INT_EN	0b01000000

// I2C Master Status
#define MPU9150_I2C_MASTER_PASS_THRU	0b10000000
#define MPU9150_I2C_MASTER_SLV4_DONE	0b01000000
#define MPU9150_I2C_MASTER_LOST_ARB		0b00100000
#define MPU9150_I2C_MASTER_SLV4_NACK	0b00010000
#define MPU9150_I2C_MASTER_SLV3_NACK	0b00001000
#define MPU9150_I2C_MASTER_SLV2_NACK	0b00000100
#define MPU9150_I2C_MASTER_SLV1_NACK	0b00000010
#define MPU9150_I2C_MASTER_SLV0_NACK	0b00000001

// Interrupt Pin Config
#define MPU9150_INT_PIN_LEVEL_HIGH		0b00000000
#define MPU9150_INT_PIN_LEVEL_LOW		0b10000000
#define MPU9150_INT_PIN_PUSH_PULL		0b00000000
#define MPU9150_INT_PIN_OPEN_DRAIN		0b01000000
#define MPU9150_INT_PIN_LATCH_EN		0b00100000
#define MPU9150_INT_PIN_LATCH_DIS		0b00000000
#define MPU9150_INT_PIN_RD_CLEAR_EN		0b00010000
#define MPU9150_INT_PIN_RD_CLEAR_DIS	0b00000000
#define MPU9150_INT_PIN_FSYNC_LEVEL_HIGH	0b00000000
#define MPU9150_INT_PIN_FSYNC_LEVEL_LOW		0b00001000
#define MPU9150_INT_PIN_FSYNC_INT_EN	0b00000100
#define MPU9150_INT_PIN_FSYNC_INT_DIS	0b00000000
#define MPU9150_I2C_BYPASS_EN			0b00000010
#define MPU9150_I2C_BYPASS_DIS			0b00000000
#define MPU9150_CLKOUT_EN				0b00000001
#define MPU9150_CLKOUT_DIS				0b00000000

// Interrupt Enable Config
#define MPU9150_INT_FF			0b10000000
#define MPU9150_INT_MOT			0b01000000
#define MPU9150_INT_ZMO			0b00100000
#define MPU9150_INT_FIFO_OFLOW	0b00010000
#define MPU9150_INT_I2C_MST		0b00001000
#define MPU9150_INT_DATA_RDY	0b00000001

// Motion Detection Status
#define MPU9150_MOT_XNEG	0b10000000
#define MPU9150_MOT_XPOS	0b01000000
#define MPU9150_MOT_YNEG	0b00100000
#define MPU9150_MOT_YPOS	0b00010000
#define MPU9150_MOT_ZNEG	0b00001000
#define MPU9150_MOT_ZPOS	0b00000100
#define MPU9150_MOT_ZRMOT	0b00000001

// I2C Master Delay Control
#define MPU9150_I2C_DELAY_ES_SHADOW	0b10000000
#define MPU9150_I2C_DELAY_SLV4_EN	0b00010000
#define MPU9150_I2C_DELAY_SLV3_EN	0b00001000
#define MPU9150_I2C_DELAY_SLV2_EN	0b00000100
#define MPU9150_I2C_DELAY_SLV1_EN	0b00000010
#define MPU9150_I2C_DELAY_SLV0_EN	0b00000001

// Signal Path Reset
#define MPU9150_RESET_GYRO	0b00000100
#define MPU9150_RESET_ACCEL	0b00000010
#define MPU9150_RESET_TEMP	0b00000001

// Motion Detection Control
#define MPU9150_ACCEL_ON_DLY_0	0b00000000
#define MPU9150_ACCEL_ON_DLY_1	0b00010000
#define MPU9150_ACCEL_ON_DLY_2	0b00100000
#define MPU9150_ACCEL_ON_DLY_3	0b00110000
#define MPU9150_FF_COUNT_RESET	0b00000000
#define MPU9150_FF_COUNT_1		0b00000100
#define MPU9150_FF_COUNT_2		0b00001000
#define MPU9150_FF_COUNT_3		0b00001100
#define MPU9150_MOT_COUNT_RESET	0b00000000
#define MPU9150_MOT_COUNT_1		0b00000001
#define MPU9150_MOT_COUNT_2		0b00000010
#define MPU9150_MOT_COUNT_3		0b00000011

// User control
#define MPU9150_FIFO_EN			0b01000000
#define MPU9150_I2C_MST_EN		0b00100000
#define MPU9150_I2C_IF_DIS		0b00000000
#define MPU9150_FIFO_RESET		0b00000100
#define MPU9150_I2C_MST_RESET	0b00000010
#define MPU9150_SIG_COND_RESET	0b00000001

// Power Management 1
#define MPU9150_DEVICE_RESET	0b10000000
#define MPU9150_SLEEP			0b01000000
#define MPU9150_CYCLE			0b00100000
#define MPU9150_TEMP_DIS		0b00001000
#define MPU9150_CLK_INTERNAL	0b00000000
#define MPU9150_CLK_XGYRO		0b00000001
#define MPU9150_CLK_YGYRO		0b00000010
#define MPU9150_CLK_ZGYRO		0b00000011
#define MPU9150_CLK_EXT_32K		0b00000100
#define MPU9150_CLK_EXT_19M		0b00000101
#define MPU9150_CLK_STOP		0b00000111

// Power Management 2
#define MPU9150_LP_WAKE_1_25	0b00000000
#define MPU9150_LP_WAKE_5		0b01000000
#define MPU9150_LP_WAKE_20		0b10000000
#define MPU9150_LP_WAKE_40		0b11000000
#define MPU9150_STBY_XA			0b00100000
#define MPU9150_STBY_YA			0b00010000
#define MPU9150_STBY_ZA			0b00001000
#define MPU9150_STBY_XG			0b00000100
#define MPU9150_STBY_YG			0b00000010
#define MPU9150_STBY_ZG			0b00000001

// Magnetometer
#define MPU9150_MAG_DRDY		0b00000001
#define MPU9150_MAG_HOFL		0b00001000
#define MPU9150_MAG_DERR		0b00000100
#define MPU9150_MAG_POWER_DOWN	0b00000000
#define MPU9150_MAG_MEASURE		0b00000001
#define MPU9150_MAG_SELF_TEST	0b00001000
#define MPU9150_MAG_FUSE_ROM	0b00001111
#define MPU9150_MAG_ASTC_SELF	0b01000000
#define MPU9150_MAG_I2C_DISABLE	0b00000001

class MPU9150{
	public:
		MPU9150();
		MPU9150(uint8_t address);
		
		bool testConnection();
		
		void getSelfTestTrim(uint8_t *xa, uint8_t *ya, uint8_t *za, uint8_t *xg, uint8_t *yg, uint8_t *zg);
		
		uint8_t getSampleRateDivider();
		void setSampleRateDivider(uint8_t div);
		
		uint8_t getConfig();
		void setConfig(uint8_t config);
		uint8_t getGyroConfig();
		void setGyroConfig(uint8_t config);
		uint8_t getAccelConfig();
		void setAccelConfig(uint8_t config);
		
		uint8_t getFreefallThreshold();
		void setFreefallThreshold(uint8_t thr);
		uint8_t getFreefallDuration();
		void setFreefallDuration(uint8_t dur);
		uint8_t getMotionThreshold();
		void setMotionThreshold(uint8_t thr);
		uint8_t getMotionDuration();
		void setMotionDuration(uint8_t dur);
		uint8_t getZeroMotionThreshold();
		void setZeroMotionThreshold(uint8_t thr);
		uint8_t getZeroMotionDuration();
		void setZeroMotionDuration(uint8_t dur);
		
		uint8_t getFifoEn();
		void setFifoEn(uint8_t config);
		uint8_t getI2CMasterControl();
		void setI2CMasterControl(uint8_t config);
		uint8_t getI2CSlave0Address();
		void setI2CSlave0Address(uint8_t addr);
		uint8_t getI2CSlave0Register();
		void setI2CSlave0Register(uint8_t ra);
		uint8_t getI2CSlave0Control();
		void setI2CSlave0Control(uint8_t config);
		uint8_t getI2CSlave1Address();
		void setI2CSlave1Address(uint8_t addr);
		uint8_t getI2CSlave1Register();
		void setI2CSlave1Register(uint8_t ra);
		uint8_t getI2CSlave1Control();
		void setI2CSlave1Control(uint8_t config);
		uint8_t getI2CSlave2Address();
		void setI2CSlave2Address(uint8_t addr);
		uint8_t getI2CSlave2Register();
		void setI2CSlave2Register(uint8_t ra);
		uint8_t getI2CSlave2Control();
		void setI2CSlave2Control(uint8_t config);
		uint8_t getI2CSlave3Address();
		void setI2CSlave3Address(uint8_t addr);
		uint8_t getI2CSlave3Register();
		void setI2CSlave3Register(uint8_t ra);
		uint8_t getI2CSlave3Control();
		void setI2CSlave3Control(uint8_t config);
		uint8_t getI2CSlave4Address();
		void setI2CSlave4Address(uint8_t addr);
		uint8_t getI2CSlave4Register();
		void setI2CSlave4Register(uint8_t ra);
		uint8_t getI2CSlave4DataOut();
		void setI2CSlave4DataOut(uint8_t data);
		uint8_t getI2CSlave4Control();
		void setI2CSlave4Control(uint8_t config);
		uint8_t getI2CSlave4DataIn();
		void setI2CSlave4DataIn(uint8_t data);
		uint8_t getI2CMasterStatus();
		
		uint8_t getInterruptPinConfig();
		void setInterruptPinConfig(uint8_t config);
		uint8_t getInterruptConfig();
		void setInterruptConfig(uint8_t config);
		uint8_t getInterruptStatus();
		
		int16_t getAccelX();
		int16_t getAccelY();
		int16_t getAccelZ();
		int16_t getTemp();
		int16_t getGyroX();
		int16_t getGyroY();
		int16_t getGyroZ();
		
		//TODO Slave data readout
		
		uint8_t getMotionDetectionStatus();
		
		uint8_t getI2CSlave0DataOut();
		void setI2CSlave0DataOut(uint8_t data);
		uint8_t getI2CSlave1DataOut();
		void setI2CSlave1DataOut(uint8_t data);
		uint8_t getI2CSlave2DataOut();
		void setI2CSlave2DataOut(uint8_t data);
		uint8_t getI2CSlave3DataOut();
		void setI2CSlave3DataOut(uint8_t data);
		uint8_t getI2CMasterDelayControl();
		void setI2CMasterDelayControl(uint8_t config);
		
		void setSignalPathReset(uint8_t config);
		
		uint8_t getMotionDetectionControl();
		void setMotionDetectionControl(uint8_t config);
		uint8_t getUserControl();
		void setUserControl(uint8_t config);
		uint8_t getPowerManagement1();
		void setPowerManagement1(uint8_t config);
		uint8_t getPowerManagment2();
		void setPowerManagement2(uint8_t config);
		
		uint16_t getFIFOCount();
		uint8_t getFIFO();
		void setFIFO(uint8_t data);
		
		uint8_t getDeviceID();
		
		// Magnetometer
		uint8_t getMagID();
		uint8_t getMagInfo();
		uint8_t getMagStatus1();
		uint8_t getMagStatus2();
		
		int16_t getMagX();
		int16_t getMagY();
		int16_t getMagZ();
		
		uint8_t getMagControl();
		void setMagControl(uint8_t config);
		uint8_t getMagASTC();
		void setMagASTC(uint8_t config);
		bool getMagI2CDisable();
		void setMagI2CDisable(bool disable);
		
		uint8_t getMagASAX();
		void setMagASAX(uint8_t data);
		uint8_t getMagASAY();
		void setMagASAY(uint8_t data);
		uint8_t getMagASAZ();
		void setMagASAZ(uint8_t data);
		
	private:
		uint8_t deviceAddress;
		uint8_t buffer[8];
}

#endif
