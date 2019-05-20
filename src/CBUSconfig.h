
/*

  Copyright (C) Duncan Greenwood 2017 (duncan_greenwood@hotmail.com)

  This work is licensed under the:
      Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
   To view a copy of this license, visit:
      http://creativecommons.org/licenses/by-nc-sa/4.0/
   or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.

   License summary:
    You are free to:
      Share, copy and redistribute the material in any medium or format
      Adapt, remix, transform, and build upon the material

    The licensor cannot revoke these freedoms as long as you follow the license terms.

    Attribution : You must give appropriate credit, provide a link to the license,
                  and indicate if changes were made. You may do so in any reasonable manner,
                  but not in any way that suggests the licensor endorses you or your use.

    NonCommercial : You may not use the material for commercial purposes. **(see note below)

    ShareAlike : If you remix, transform, or build upon the material, you must distribute
                 your contributions under the same license as the original.

    No additional restrictions : You may not apply legal terms or technological measures that
                                 legally restrict others from doing anything the license permits.

   ** For commercial use, please contact the original copyright holder(s) to agree licensing terms

    This software is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE

*/

#if !defined __CBUSCONFIG_H__
#define __CBUSCONFIG_H__

#include <Arduino.h>                // for definition of byte datatype

#include <CBUSLED.h>
#include <CBUSSwitch.h>

// external EEPROM -- learned event table
// in-memory hash table
static const byte EE_HASH_BYTES = 4;
static const byte HASH_LENGTH = 128;

static const byte EEPROM_I2C_ADDR = 0x50;

enum {
  EEPROM_INTERNAL = 0,
  EEPROM_EXTERNAL = 1
};

// a class to encapsulate CBUS module configuration, events, NVs, EEPROM, etc

class CBUSConfig {

  public:
    void begin(void);
    byte findExistingEvent(unsigned int nn, unsigned int en);
    byte findEventSpace(void);
    void getEvArray(byte idx);
    void makeEvHashTable(void);
    void updateEvHashEntry(byte idx);
    void readEvent(byte idx, byte tarr[]);
    void clearEvHashTable(void);
    void printEvHashTable(bool raw);
    byte getEvTableEntry(byte tindex);
    byte numEvents(void);
    byte makeHash(byte tarr[]);
    byte readNV(byte idx);
    void writeNV(byte idx, byte val);
    void loadNVs(void);
    byte readEEPROM(unsigned int eeaddress);
    byte readBytesEEPROM(unsigned int eeaddress, byte nbytes, byte dest[]);
    void writeEEPROM(unsigned int eeaddress, byte data);
    void writeBytesEEPROM(unsigned int eeaddress, byte src[], byte numbytes);
    void writeeventEEPROM(byte index, byte data[]);
    void cleareventEEPROM(byte index);
    void resetEEPROM(void);
    void resetModule(CBUSLED green, CBUSLED yellow, CBUSSwitch sw);
    unsigned int freeSRAM(void);
    void reboot(void);
    void setCANID(byte canid);
    void setFLiM(bool f);
    void setNodeNum(unsigned int nn);
    bool setEEPROMtype(byte type);

    byte eeprom_type;
    byte EE_EVENTS_START;
    byte EE_MAX_EVENTS;
    byte EE_NUM_EVS;
    byte EE_BYTES_PER_EVENT;
    unsigned int EE_NVS_START;
    byte EE_NUM_NVS;

    byte CANID;
    bool FLiM;
    unsigned int nodeNum;

};

#endif