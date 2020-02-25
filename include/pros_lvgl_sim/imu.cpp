/**
 * \file devices/vdml_imu.cpp
 *
 * Contains functions for interacting with the VEX Inertial sensor.
 *
 * Copyright (c) 2017-2019, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "./pros-lvgl-sim.hpp"
#if USE_PROS_LVGL_SIM == 1
#include "pros/imu.hpp"

namespace pros {
std::int32_t Imu::reset() const
{
    return 1;
}

double Imu::get_rotation() const
{
    return 1.1;
}

double Imu::get_heading() const
{
    return 2.2;
}

pros::c::quaternion_s_t Imu::get_quaternion() const
{
    return {1, 2, 3, 4};
}

pros::c::euler_s_t Imu::get_euler() const
{
    return {1, 2, 3};
}

double Imu::get_pitch() const
{
    return 1;
}

double Imu::get_roll() const
{
    return 2;
}

double Imu::get_yaw() const
{
    return 3;
}

pros::c::imu_gyro_s_t Imu::get_gyro_rate() const
{
    return {1, 2, 3};
}

pros::c::imu_accel_s_t Imu::get_accel() const
{
    return {1, 2, 3};
}

pros::c::imu_status_e_t Imu::get_status() const
{
    return pros::c::E_IMU_STATUS_CALIBRATING;
}

bool Imu::is_calibrating() const
{
    return true;
}
} // namespace pros
#else
#endif