//
//    FILE: INA239_demo_energy_charge.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo core functions
//     URL: https://github.com/RobTillaart/INA239
//
//  need more tests.

#include "INA239.h"


INA239 INA(0x40);


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.println();
  Serial.print("INA239_LIB_VERSION: ");
  Serial.println(INA239_LIB_VERSION);
  Serial.println();

  Wire.begin();
  if (!INA.begin() )
  {
    Serial.println("Could not connect. Fix and Reboot");
    while(1);
  }

  INA.setMaxCurrentShunt(10, 0.015);
  INA.setAccumulation(1);  //  clear registers?
}


void loop()
{
  Serial.println("\nVBUS\tVSHUNT\tCURRENT\tPOWER\tTEMP\tJOULE\tCOULOMB");
  for (int i = 0; i < 20; i++)
  {
    Serial.print(INA.getBusVoltage(), 3);
    Serial.print("\t");
    Serial.print(INA.getShuntMilliVolt(), 3);
    Serial.print("\t");
    Serial.print(INA.getMilliAmpere(), 3);
    Serial.print("\t");
    Serial.print(INA.getMilliWatt(), 3);
    Serial.print("\t");
    Serial.print(INA.getEnergy(), 8);  //  how many decimals valid
    Serial.print("\t");
    Serial.print(INA.getCharge(), 8);
    Serial.print("\t");
    Serial.print(INA.getTemperature(), 3);
    Serial.println();
    delay(1000);
  }
}


//  -- END OF FILE --