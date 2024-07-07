#pragma once

#include <wpi/sendable/Sendable.h>
#include <wpi/sendable/SendableBuilder.h>

#include <frc/smartdashboard/SmartDashboard.h>

#include <frc/drive/DifferentialDrive.h>

#include <frc/kinematics/DifferentialDriveKinematics.h>

#include <frc/estimator/DifferentialDrivePoseEstimator.h>

#include <frc/geometry/Rotation2d.h>

#include <units/angle.h>
#include <units/length.h>

#include "utils/hardware.hpp"
#include "Constants.hpp"

using namespace hardware;

class Differential
{
    public:
        Differential(hardware::gyro::navx* Gyro);

        void Drive(double y, double x);
        
        void Periodic();

        // ***     GYRO     *** //
        gyro::navx* Gyro;
    private:
        // *** DRIVE MOTORS *** //

        motors::CANSparkMax     d_leftMotor;
        motors::CANSparkMax     d_rightMotor;

        frc::DifferentialDrive driveController{
            [&](double output) { d_leftMotor.Set(output); },
            [&](double output) { d_rightMotor.Set(-output); }// right motor needs to be inverted
        };

        frc::DifferentialDriveKinematics kinematics{units::inch_t{drive::WIDTH}};

        frc::DifferentialDrivePoseEstimator	PoseEstimator{	
            kinematics,
            frc::Rotation2d{units::degree_t{0}},
            units::meter_t{0},
            units::meter_t{0},
            frc::Pose2d{}
        };
};