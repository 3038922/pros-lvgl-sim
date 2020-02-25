/**
 * \file devices/vdml_motors.cpp
 *
 * Contains functions for interacting with the V5 Motors.
 *
 * Copyright (c) 2017-2020, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "./pros-lvgl-sim.hpp"
#if USE_PROS_LVGL_SIM == 1
#include "pros/motors.hpp"

namespace pros {
using namespace pros::c;

Motor::Motor(const std::uint8_t port, const motor_gearset_e_t gearset, const bool reverse,
             const motor_encoder_units_e_t encoder_units)
    : _port(port)
{
    set_gearing(gearset);
    set_reversed(reverse);
    set_encoder_units(encoder_units);
}

Motor::Motor(const std::uint8_t port, const motor_gearset_e_t gearset, const bool reverse) : _port(port)
{
    set_gearing(gearset);
    set_reversed(reverse);
}

Motor::Motor(const std::uint8_t port, const motor_gearset_e_t gearset) : _port(port)
{
    set_gearing(gearset);
}

Motor::Motor(const std::uint8_t port, const bool reverse) : _port(port)
{
    set_reversed(reverse);
}

Motor::Motor(const std::uint8_t port) : _port(port) {}

std::int32_t Motor::operator=(std::int32_t voltage) const
{
    return 1;
}

std::int32_t Motor::move(std::int32_t voltage) const
{
    return 1;
}

std::int32_t Motor::move_absolute(const double position, const std::int32_t velocity) const
{
    return 1;
}

std::int32_t Motor::move_relative(const double position, const std::int32_t velocity) const
{
    return 1;
}

std::int32_t Motor::move_velocity(const std::int32_t velocity) const
{
    return 1;
}

std::int32_t Motor::move_voltage(const std::int32_t voltage) const
{
    return 1;
}

std::int32_t Motor::modify_profiled_velocity(const std::int32_t velocity) const
{
    return 1;
}

double Motor::get_actual_velocity(void) const
{
    return 1;
}

motor_brake_mode_e_t Motor::get_brake_mode(void) const
{
    return E_MOTOR_BRAKE_COAST;
}

std::int32_t Motor::get_current_draw(void) const
{
    return 1;
}

std::int32_t Motor::get_current_limit(void) const
{
    return 1;
}

std::int32_t Motor::is_over_current(void) const
{
    return 1;
}

std::int32_t Motor::get_direction(void) const
{
    return 1;
}

double Motor::get_efficiency(void) const
{
    return 1;
}

motor_encoder_units_e_t Motor::get_encoder_units(void) const
{
    return E_MOTOR_ENCODER_ROTATIONS;
}

std::uint32_t Motor::get_faults(void) const
{
    return 1;
}

std::uint32_t Motor::get_flags(void) const
{
    return 1;
}

motor_gearset_e_t Motor::get_gearing(void) const
{
    return E_MOTOR_GEARSET_36;
}

motor_pid_full_s_t Motor::get_pos_pid(void) const
{
    return {1, 2, 3, 4, 5, 6, 7, 8};
}

motor_pid_full_s_t Motor::get_vel_pid(void) const
{
    return {1, 2, 3, 4, 5, 6, 7, 8};
}

std::int32_t Motor::get_raw_position(std::uint32_t *const timestamp) const
{
    return 1;
}

std::int32_t Motor::is_over_temp(void) const
{
    return 1;
}

std::int32_t Motor::is_stopped(void) const
{
    return 1;
}

std::int32_t Motor::get_zero_position_flag(void) const
{
    return 1;
}

double Motor::get_position(void) const
{
    return 1;
}

double Motor::get_power(void) const
{
    return 1;
}

std::int32_t Motor::is_reversed(void) const
{
    return 1;
}

double Motor::get_temperature(void) const
{
    return 20;
}

double Motor::get_target_position(void) const
{
    return 1;
}

double Motor::get_torque(void) const
{
    return 1;
}

std::int32_t Motor::get_target_velocity(void) const
{
    return 1;
}

std::int32_t Motor::get_voltage(void) const
{
    return 1;
}

std::int32_t Motor::get_voltage_limit(void) const
{
    return 1;
}

std::uint8_t Motor::get_port(void) const
{
    return _port;
}

std::int32_t Motor::tare_position(void) const
{
    return 1;
}

std::int32_t Motor::set_brake_mode(const motor_brake_mode_e_t mode) const
{
    return 1;
}

std::int32_t Motor::set_current_limit(const std::int32_t limit) const
{
    return 1;
}

std::int32_t Motor::set_encoder_units(const motor_encoder_units_e_t units) const
{
    return 1;
}

std::int32_t Motor::set_gearing(const motor_gearset_e_t gearset) const
{
    return 1;
}

motor_pid_s_t Motor::convert_pid(double kf, double kp, double ki, double kd)
{
    return {1, 2, 3, 4};
}

motor_pid_full_s_t Motor::convert_pid_full(double kf, double kp, double ki, double kd, double filter, double limit,
                                           double threshold, double loopspeed)
{
    return {1, 2, 3, 4, 5, 6, 7, 8};
}

std::int32_t Motor::set_pos_pid(const motor_pid_s_t pid) const
{
    return 1;
}

std::int32_t Motor::set_pos_pid_full(const motor_pid_full_s_t pid) const
{
    return 1;
}

std::int32_t Motor::set_vel_pid(const motor_pid_s_t pid) const
{
    return 1;
}

std::int32_t Motor::set_vel_pid_full(const motor_pid_full_s_t pid) const
{
    return 1;
}

std::int32_t Motor::set_zero_position(const double position) const
{
    return 1;
}

std::int32_t Motor::set_reversed(const bool reverse) const
{
    return 1;
}

std::int32_t Motor::set_voltage_limit(const std::int32_t limit) const
{
    return 1;
}

namespace literals {
const pros::Motor operator"" _mtr(const unsigned long long int m)
{
    return pros::Motor(m, false);
}
const pros::Motor operator"" _rmtr(const unsigned long long int m)
{
    return pros::Motor(m, true);
}
} // namespace literals
} // namespace pros
#else
#endif