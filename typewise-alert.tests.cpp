#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
    // Test cases for inferBreach function
    EXPECT_EQ(inferBreach(20.0, 0.0, 35.0), NORMAL);  // within range
    EXPECT_EQ(inferBreach(-5.0, 0.0, 35.0), TOO_LOW); // below lower limit
    EXPECT_EQ(inferBreach(40.0, 0.0, 35.0), TOO_HIGH); // above upper limit
}

TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreach) {
    // Test cases for classifyTemperatureBreach function
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 20.0), NORMAL);  // within range
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, -5.0), TOO_LOW); // below lower limit
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 40.0), TOO_HIGH); // above upper limit

    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 30.0), NORMAL);  // within range
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, -5.0), TOO_LOW);  // below lower limit
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50.0), TOO_HIGH); // above upper limit

    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 35.0), NORMAL);  // within range
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, -5.0), TOO_LOW);  // below lower limit
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 45.0), TOO_HIGH); // above upper limit
}

