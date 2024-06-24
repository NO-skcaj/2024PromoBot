#pragma once

#include <units/length.h>

namespace drive
{
    // THESE VALUES ARE NOT TESTED
    constexpr double DRIVE_P     = 0.7;
    constexpr double DRIVE_I     = 0;
    constexpr double DRIVE_D     = 0.03;
    constexpr int DRIVE_AMPERAGE = 30;

    constexpr int LEFT_CAN       = 1;
    constexpr int RIGHT_CAN      = 1;

    constexpr float WIDTH        = 20;

    // For every rotation of the motor, how far do you go
    // Normally its just the circumference
    constexpr units::inch_t INCH_PER_ROTATION{10}; 
}