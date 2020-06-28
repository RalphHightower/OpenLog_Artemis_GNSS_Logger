void menuPower()
{
  while (1)
  {
    Serial.println();
    Serial.println("Menu: Configure Power Options");

    Serial.print("1) Wake On Power Reconnect: ");
    if (settings.wakeOnPowerReconnect == true) Serial.println("Enabled");
    else Serial.println("Disabled");

#if(HARDWARE_VERSION_MAJOR >= 1)
    Serial.print("2) Turn off Qwiic bus power when sleeping: ");
    if (settings.powerDownQwiicBusBetweenReads == true) Serial.println("Yes");
    else Serial.println("No");

    Serial.print("3) Power LED During Sleep: ");
    if (settings.enablePwrLedDuringSleep == true) Serial.println("Enabled");
    else Serial.println("Disabled");
#endif

    Serial.println("x) Exit");

    byte incoming = getByteChoice(menuTimeout); //Timeout after x seconds

    if (incoming == '1')
    {
      settings.wakeOnPowerReconnect ^= 1;
    }
#if(HARDWARE_VERSION_MAJOR >= 1)
    else if (incoming == '2')
    {
      settings.powerDownQwiicBusBetweenReads ^= 1;
    }
    else if (incoming == '3')
    {
      settings.enablePwrLedDuringSleep ^= 1;
    }
#endif
    else if (incoming == 'x')
      break;
    else if (incoming == STATUS_GETBYTE_TIMEOUT)
      break;
    else
      printUnknown(incoming);
  }
}
