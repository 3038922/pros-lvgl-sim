/**
 * \file devices/vdml_vision.cpp
 *
 * Contains functions for interacting with the V5 Vision Sensor.
 *
 * Copyright (c) 2017-2020, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "./pros-lvgl-sim.hpp"
#if USE_PROS_LVGL_SIM == 1
#include "pros/vision.hpp"

namespace pros {
using namespace pros::c;

Vision::Vision(std::uint8_t port, vision_zero_e_t zero_point) : _port(port)
{
}

std::int32_t Vision::clear_led(void) const
{
    return 1;
}

vision_signature_s_t Vision::signature_from_utility(const std::int32_t id, const std::int32_t u_min,
                                                    const std::int32_t u_max, const std::int32_t u_mean,
                                                    const std::int32_t v_min, const std::int32_t v_max,
                                                    const std::int32_t v_mean, const float range,
                                                    const std::int32_t type)
{
    return {1, {22, 23, 24}, 3, 4, 5, 6, 7, 8, 9, 10, 11};
}

vision_color_code_t Vision::create_color_code(const std::uint32_t sig_id1, const std::uint32_t sig_id2,
                                              const std::uint32_t sig_id3, const std::uint32_t sig_id4,
                                              const std::uint32_t sig_id5) const
{
    return 1;
}

vision_object_s_t Vision::get_by_size(const std::uint32_t size_id) const
{
    return {1, E_VISION_OBJECT_NORMAL, 3, 4, 5, 6, 7, 8, 9};
}

vision_object_s_t Vision::get_by_sig(const std::uint32_t size_id, const std::uint32_t sig_id) const
{
    return {1, E_VISION_OBJECT_NORMAL, 3, 4, 5, 6, 7, 8, 9};
}

vision_object_s_t Vision::get_by_code(const std::uint32_t size_id, const vision_color_code_t color_code) const
{
    return {1, E_VISION_OBJECT_NORMAL, 3, 4, 5, 6, 7, 8, 9};
}

int32_t Vision::get_exposure(void) const
{
    return 1;
}

int32_t Vision::get_object_count(void) const
{
    return 1;
}

std::int32_t Vision::get_white_balance(void) const
{
    return 1;
}

std::uint8_t Vision::get_port(void) const
{
    return _port;
}

int32_t Vision::read_by_size(const std::uint32_t size_id, const std::uint32_t object_count,
                             vision_object_s_t *const object_arr) const
{
    return 1;
}

int32_t Vision::read_by_sig(const std::uint32_t size_id, const std::uint32_t sig_id, const std::uint32_t object_count,
                            vision_object_s_t *const object_arr) const
{
    return 1;
}

int32_t Vision::read_by_code(const std::uint32_t size_id, const vision_color_code_t color_code,
                             const std::uint32_t object_count, vision_object_s_t *const object_arr) const
{
    return 1;
}

vision_signature_s_t Vision::get_signature(const std::uint8_t signature_id) const
{
    return {1, {22, 23, 24}, 3, 4, 5, 6, 7, 8, 9, 10, 11};
}

std::int32_t Vision::print_signature(const vision_signature_s_t sig)
{
    return 1;
}

std::int32_t Vision::set_signature(const std::uint8_t signature_id, vision_signature_s_t *const signature_ptr) const
{
    return 1;
}

std::int32_t Vision::set_auto_white_balance(const std::uint8_t enable) const
{
    return 1;
}

std::int32_t Vision::set_exposure(const std::uint8_t exposure) const
{
    return 1;
}

std::int32_t Vision::set_led(const std::int32_t rgb) const
{
    return 1;
}

std::int32_t Vision::set_white_balance(const std::int32_t rgb) const
{
    return 1;
}

std::int32_t Vision::set_zero_point(vision_zero_e_t zero_point) const
{
    return 1;
}

std::int32_t Vision::set_wifi_mode(const std::uint8_t enable) const
{
    return 1;
}
} // namespace pros
#else
#endif