#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  return (value < lowerLimit) ? TOO_LOW :
         (value > upperLimit) ? TOO_HIGH :
         NORMAL;
}


BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
    int lowerLimit = coolingLimits[coolingType].lowerLimit;
    int upperLimit = coolingLimits[coolingType].upperLimit;

    return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  void (*alertFunc)(BreachType) = (alertTarget == TO_CONTROLLER) 
                                  ? sendToController 
                                  : sendToEmail;

  alertFunc(breachType);
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  if (breachType == NORMAL) return;

  const char* recipient = "a.b@c.com";
  const char* message = (breachType == TOO_LOW) 
                        ? "Hi, the temperature is too low\n" 
                        : "Hi, the temperature is too high\n";
  
  printf("To: %s\n", recipient);
  printf("%s", message);
}
