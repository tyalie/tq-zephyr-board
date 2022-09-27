/*
 * Copyright 2018-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "tq_flexspi_nor_config.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.xip_board"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
#if defined(XIP_BOOT_HEADER_ENABLE) && (XIP_BOOT_HEADER_ENABLE == 1)
#if defined(__CC_ARM) || defined(__ARMCC_VERSION) || defined(__GNUC__)
__attribute__((section(".boot_hdr.conf"), used))
#elif defined(__ICCARM__)
#pragma location = ".boot_hdr.conf"
#endif
const flexspi_nor_config_t qspiflash_config = {
.memConfig =
{
.tag = 0x42464346UL,         //!< [0x000-0x003] Tag, fixed value 0x42464346UL
.version = 0x56010400UL,           //!< [0x004-0x007] Version,[31:24] -'V', [23:16] - Major, [15:8] - Minor, [7:0] - bugfix
.reserved0 = 0x0UL,         //!< [0x008-0x00b] Reserved for future use
.readSampleClkSrc = 0x1U,   //!< [0x00c-0x00c] Read Sample Clock Source, valid value: 0/1/3
.csHoldTime = 0x3U,         //!< [0x00d-0x00d] CS hold time, default value: 3
.csSetupTime = 0x3U,        //!< [0x00e-0x00e] CS setup time, default value: 3
.columnAddressWidth = 0x0U, //!< [0x00f-0x00f] Column Address with, for HyperBus protocol, it is fixed to 3, For

/* ********************************************************************** */
/*                 Device mode configuration section                      */
.deviceModeCfgEnable = 0x0U, //!< [0x010-0x010] Device Mode Configure enable flag, 1 - Enable, 0 - Disable
.deviceModeType = 0x0U, //!< [0x011-0x011] Specify the configuration command type:Quad Enable, DPI/QPI/OPI switch,
 /*
kDeviceConfigCmdType_Generic,    //!< Generic command, for example: configure dummy cycles, drive strength, etc
kDeviceConfigCmdType_QuadEnable, //!< Quad Enable command
kDeviceConfigCmdType_Spi2Xpi,    //!< Switch from SPI to DPI/QPI/OPI mode
kDeviceConfigCmdType_Xpi2Spi,    //!< Switch from DPI/QPI/OPI to SPI mode
kDeviceConfigCmdType_Spi2NoCmd,  //!< Switch to 0-4-4/0-8-8 mode
kDeviceConfigCmdType_Reset,      //!< Reset device command
*/
.waitTimeCfgCommands = 0x0U, //!< [0x012-0x013] Wait time for all configuration commands, unit: 100us, Used for
.deviceModeSeq = {         //!< [0x014-0x017] Device mode sequence info, [7:0] - LUT sequence id, [15:8] - LUt
.seqNum = 0x0U,          //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,           //!< Sequence Index, valid number: 0-15
.reserved = 0x0U         ////! sequence number, [31:16] Reserved
},
.deviceModeArg = 0x0UL,    //!< [0x018-0x01b] Argument/Parameter for device configuration
/* ********************************************************************** */

/* ********************************************************************** */
/*                   Config command section                               */
.configCmdEnable = 0x0U,   //!< [0x01c-0x01c] Configure command Enable Flag, 1 - Enable, 0 - Disable
.configModeType[0] = 0x0U, //!< [0x01d-0x01f] Configure Mode Type, similar as deviceModeType
.configModeType[1] = 0x0U, //!< [0x01d-0x01f] Configure Mode Type, similar as deviceModeType
.configModeType[2] = 0x0U, //!< [0x01d-0x01f] Configure Mode Type, similar as deviceModeType
 /*
kDeviceConfigCmdType_Generic,    //!< Generic command, for example: configure dummy cycles, drive strength, etc
kDeviceConfigCmdType_QuadEnable, //!< Quad Enable command
kDeviceConfigCmdType_Spi2Xpi,    //!< Switch from SPI to DPI/QPI/OPI mode
kDeviceConfigCmdType_Xpi2Spi,    //!< Switch from DPI/QPI/OPI to SPI mode
kDeviceConfigCmdType_Spi2NoCmd,  //!< Switch to 0-4-4/0-8-8 mode
kDeviceConfigCmdType_Reset,      //!< Reset device command
*/
.configCmdSeqs[0] = {       //!< [0x020-0x02b] Sequence info for Device Configuration command, similar as deviceModeSeq
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.configCmdSeqs[1] = {       //!< [0x020-0x02b] Sequence info for Device Configuration command, similar as deviceModeSeq
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.configCmdSeqs[2] = {       //!< [0x020-0x02b] Sequence info for Device Configuration command, similar as deviceModeSeq
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.reserved1 = 0x0UL,   //!< [0x02c-0x02f] Reserved for future use
.configCmdArgs[0] = 0x0UL,     //!< [0x030-0x03b] Arguments/Parameters for device Configuration commands
.configCmdArgs[1] = 0x0UL,     //!< [0x030-0x03b] Arguments/Parameters for device Configuration commands
.configCmdArgs[2] = 0x0UL,     //!< [0x030-0x03b] Arguments/Parameters for device Configuration commands
.reserved2 = 0x0UL,            //!< [0x03c-0x03f] Reserved for future use
/* ********************************************************************** */

.controllerMiscOption = 0x110UL, //!< [0x040-0x043] Controller Misc Options, see Misc feature bit definitions for more
 /*
kFlexSpiMiscOffset_DiffClkEnable = 0,            //!< Bit for Differential clock enable
kFlexSpiMiscOffset_Ck2Enable = 1,                //!< Bit for CK2 enable
kFlexSpiMiscOffset_ParallelEnable = 2,           //!< Bit for Parallel mode enable
kFlexSpiMiscOffset_WordAddressableEnable = 3,    //!< Bit for Word Addressable enable
kFlexSpiMiscOffset_SafeConfigFreqEnable = 4,     //!< Bit for Safe Configuration Frequency enable
kFlexSpiMiscOffset_PadSettingOverrideEnable = 5, //!< Bit for Pad setting override enable
kFlexSpiMiscOffset_DdrModeEnable = 6,            //!< Bit for DDR clock confiuration indication.
*/
.deviceType = 0x1U,    //!< [0x044-0x044] Device Type:  See Flash Type Definition for more details
 /*
kFlexSpiDeviceType_SerialNOR = 1,       //!< Flash devices are Serial NOR
kFlexSpiDeviceType_SerialNAND = 2,      //!< Flash devices are Serial NAND
kFlexSpiDeviceType_SerialRAM = 3,       //!< Flash devices are Serial RAM/HyperFLASH
kFlexSpiDeviceType_MCP_NOR_NAND = 0x12, //!< Flash device is MCP device, A1 is Serial NOR, A2 is Serial NAND
kFlexSpiDeviceType_MCP_NOR_RAM = 0x13,  //!< Flash deivce is MCP device, A1 is Serial NOR, A2 is Serial RAMs
*/
.sflashPadType = 0x4U, //!< [0x045-0x045] Serial Flash Pad Type: 1 - Single, 2 - Dual, 4 - Quad, 8 - Octal
 /*
kSerialFlash_1Pad = 1,
kSerialFlash_2Pads = 2,
kSerialFlash_4Pads = 4,
kSerialFlash_8Pads = 8,
*/
.serialClkFreq = 0x7U, //!< [0x046-0x046] Serial Flash Frequencey, device specific definitions, See System Boot
 /*
kFlexSpiSerialClk_30MHz = 1,
kFlexSpiSerialClk_50MHz = 2,
kFlexSpiSerialClk_60MHz = 3,
kFlexSpiSerialClk_80MHz = 4,
kFlexSpiSerialClk_100MHz = 5
kFlexSpiSerialClk_120MHz = 6
kFlexSpiSerialClk_133MHz = 7
kFlexSpiSerialClk_166MHz = 8,
kFlexSpiSerialClk_200MHz = 9,
*/
.lutCustomSeqEnable = 0x0U, //!< [0x047-0x047] LUT customization Enable, it is required if the program/erase cannot
.reserved3[0] = 0x0UL,           //!< [0x048-0x04f] Reserved for future use
.reserved3[1] = 0x0UL,           //!< [0x048-0x04f] Reserved for future use
.sflashA1Size = 0x2000000UL,           //!< [0x050-0x053] Size of Flash connected to A1
.sflashA2Size = 0x0UL,           //!< [0x054-0x057] Size of Flash connected to A2
.sflashB1Size = 0x0UL,           //!< [0x058-0x05b] Size of Flash connected to B1
.sflashB2Size = 0x0UL,           //!< [0x05c-0x05f] Size of Flash connected to B2
.csPadSettingOverride = 0x0UL,   //!< [0x060-0x063] CS pad setting override value
.sclkPadSettingOverride = 0x0UL, //!< [0x064-0x067] SCK pad setting override value
.dataPadSettingOverride = 0x0UL, //!< [0x068-0x06b] data pad setting override value
.dqsPadSettingOverride = 0x0UL,  //!< [0x06c-0x06f] DQS pad setting override value
.timeoutInMs = 0x0UL,            //!< [0x070-0x073] Timeout threshold for read status command
.commandInterval = 0x0UL,        //!< [0x074-0x077] CS deselect interval between two commands
.busyOffset = 0x0U,       //!< [0x07c-0x07d] Busy offset, valid value: 0-31
.busyBitPolarity = 0x0U,  //!< [0x07e-0x07f] Busy flag polarity, 0 - busy flag is 1 when flash device is busy, 1 -
.lookupTable[0] = FLEXSPI_LUT_SEQ( CMD_SDR, FLEXSPI_1PAD, 0xec, RADDR_SDR, FLEXSPI_4PAD, 0x20), //V:0x0a2004ec Not Found
.lookupTable[1] = FLEXSPI_LUT_SEQ( MODE4_SDR, FLEXSPI_4PAD, 0x0, DUMMY_SDR, FLEXSPI_4PAD, 0x9), //V:0x32091a00
.lookupTable[2] = FLEXSPI_LUT_SEQ( READ_SDR, FLEXSPI_4PAD, 0x4, STOP, FLEXSPI_1PAD, 0x0), //V:0x00002604
.lookupTable[3] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[4] = FLEXSPI_LUT_SEQ( CMD_SDR, FLEXSPI_1PAD, 0x5, READ_SDR, FLEXSPI_1PAD, 0x4), //V:0x24040405 Read Status Register
.lookupTable[5] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[6] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[7] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[8] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000 STOP
.lookupTable[9] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[10] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[11] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[12] = FLEXSPI_LUT_SEQ( CMD_SDR, FLEXSPI_1PAD, 0x6, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000406 Write Enable
.lookupTable[13] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[14] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[15] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[16] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000 STOP
.lookupTable[17] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[18] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[19] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[20] = FLEXSPI_LUT_SEQ( CMD_SDR, FLEXSPI_1PAD, 0x21, RADDR_SDR, FLEXSPI_1PAD, 0x20), //V:0x08200421 Not Found
.lookupTable[21] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[22] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[23] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[24] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000 STOP
.lookupTable[25] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[26] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[27] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[28] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000 STOP
.lookupTable[29] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[30] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[31] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[32] = FLEXSPI_LUT_SEQ( CMD_SDR, FLEXSPI_1PAD, 0xdc, RADDR_SDR, FLEXSPI_1PAD, 0x20), //V:0x082004dc Not Found
.lookupTable[33] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[34] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[35] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[36] = FLEXSPI_LUT_SEQ( CMD_SDR, FLEXSPI_1PAD, 0x3e, RADDR_SDR, FLEXSPI_4PAD, 0x20), //V:0x0a20043e Not Found
.lookupTable[37] = FLEXSPI_LUT_SEQ( WRITE_SDR, FLEXSPI_4PAD, 0x4, STOP, FLEXSPI_1PAD, 0x0), //V:0x00002204
.lookupTable[38] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[39] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[40] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000 STOP
.lookupTable[41] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[42] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[43] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[44] = FLEXSPI_LUT_SEQ( CMD_SDR, FLEXSPI_1PAD, 0x60, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000460 Chip Erase
.lookupTable[45] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[46] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[47] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[48] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000 STOP
.lookupTable[49] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[50] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[51] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[52] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000 STOP
.lookupTable[53] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[54] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[55] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[56] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000 STOP
.lookupTable[57] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[58] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[59] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[60] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000 STOP
.lookupTable[61] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[62] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lookupTable[63] = FLEXSPI_LUT_SEQ( STOP, FLEXSPI_1PAD, 0x0, STOP, FLEXSPI_1PAD, 0x0), //V:0x00000000
.lutCustomSeq[0] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[1] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[2] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[3] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[4] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[5] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[6] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[7] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[8] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[9] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[10] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.lutCustomSeq[11] = {         //!< [0x180-0x1af] Customizable LUT Sequences
.seqNum = 0x0U,            //!< Sequence Number, valid number: 1-16
.seqId = 0x0U,             //!< Sequence Index, valid number: 0-15
.reserved = 0x0U
},
.reserved4[0] = 0x0UL,              //!< [0x1b0-0x1bf] Reserved for future use
.reserved4[1] = 0x0UL,              //!< [0x1b0-0x1bf] Reserved for future use
.reserved4[2] = 0x0UL,              //!< [0x1b0-0x1bf] Reserved for future use
.reserved4[3] = 0x0UL,              //!< [0x1b0-0x1bf] Reserved for future use
},
.pageSize = 0x100UL,              //!< Page size of Serial NOR
.sectorSize = 0x1000UL,            //!< Sector size of Serial NOR
.ipcmdSerialClkFreq = 0x1U,     //!< Clock frequency for IP command
.isUniformBlockSize = 0x0U,     //!< Sector/Block size is the same
.reserved0[0] = 0x0U,           //!< Reserved for future use
.reserved0[1] = 0x0U,           //!< Reserved for future use
.serialNorType = 0x0U,          //!< Serial NOR Flash type: 0/1/2/3
.needExitNoCmdMode = 0x0U,      //!< Need to exit NoCmd mode before other IP command
.halfClkForNonReadCmd = 0x0U,   //!< Half the Serial Clock for non-read command: true/false
.needRestoreNoCmdMode = 0x0U,   //!< Need to Restore NoCmd mode after IP commmand execution
.blockSize = 0x10000UL,             //!< Block size
.reserve2[0] = 0x0UL,          //!< Reserved for future use
.reserve2[1] = 0x0UL,          //!< Reserved for future use
.reserve2[2] = 0x0UL,          //!< Reserved for future use
.reserve2[3] = 0x0UL,          //!< Reserved for future use
.reserve2[4] = 0x0UL,          //!< Reserved for future use
.reserve2[5] = 0x0UL,          //!< Reserved for future use
.reserve2[6] = 0x0UL,          //!< Reserved for future use
.reserve2[7] = 0x0UL,          //!< Reserved for future use
.reserve2[8] = 0x0UL,          //!< Reserved for future use
.reserve2[9] = 0x0UL,          //!< Reserved for future use
.reserve2[10] = 0x0UL,          //!< Reserved for future use
};
#endif
