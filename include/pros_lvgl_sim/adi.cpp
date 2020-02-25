/**
 * \file devices/vdml_adi.cpp
 *
 * Contains functions for interacting with the V5 ADI.
 *
 * Copyright (c) 2017-2020, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "./pros-lvgl-sim.hpp"
#if USE_PROS_LVGL_SIM == 1
#include "pros/adi.hpp"

namespace pros {
using namespace pros::c;

ADIPort::ADIPort(std::uint8_t port, adi_port_config_e_t type) : _port(port)
{
}

ADIPort::ADIPort(void)
{
    // for use by derived classes like ADIEncoder
}

std::int32_t ADIPort::set_config(adi_port_config_e_t type) const
{
    return true;
}

std::int32_t ADIPort::get_config(void) const
{
    return _port;
}

std::int32_t ADIPort::set_value(std::int32_t value) const
{
    return 1;
}

std::int32_t ADIPort::get_value(void) const
{
    return 1;
}

ADIAnalogIn::ADIAnalogIn(std::uint8_t port) : ADIPort(port, E_ADI_ANALOG_IN) {}

ADIAnalogOut::ADIAnalogOut(std::uint8_t port) : ADIPort(port, E_ADI_ANALOG_OUT) {}

std::int32_t ADIAnalogIn::calibrate(void) const
{
    return 1;
}

std::int32_t ADIAnalogIn::get_value_calibrated(void) const
{
    return 1;
}

std::int32_t ADIAnalogIn::get_value_calibrated_HR(void) const
{
    return 1;
}

ADIDigitalOut::ADIDigitalOut(std::uint8_t port, bool init_state) : ADIPort(port, E_ADI_DIGITAL_OUT)
{
    set_value(init_state);
}

ADIDigitalIn::ADIDigitalIn(std::uint8_t port) : ADIPort(port, E_ADI_DIGITAL_IN) {}

std::int32_t ADIDigitalIn::get_new_press(void) const
{
    return 1;
}

ADIMotor::ADIMotor(std::uint8_t port) : ADIPort(port, E_ADI_LEGACY_PWM)
{
    stop();
}

std::int32_t ADIMotor::stop(void) const
{
    return 1;
}

ADIEncoder::ADIEncoder(std::uint8_t port_top, std::uint8_t port_bottom, bool reversed)
{
    _port = port_top;
}

std::int32_t ADIEncoder::reset(void) const
{
    return 1;
}

std::int32_t ADIEncoder::get_value(void) const
{
    return 1;
}

ADIUltrasonic::ADIUltrasonic(std::uint8_t port_ping, std::uint8_t port_echo)
{
    _port = port_ping;
}

ADIGyro::ADIGyro(std::uint8_t port, double multiplier)
{
    _port = 1;
}

double ADIGyro::get_value(void) const
{
    return 1;
}

std::int32_t ADIGyro::reset(void) const
{
    return 1;
}
} // namespace pros
#else
#endif