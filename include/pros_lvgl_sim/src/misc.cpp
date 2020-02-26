
#include "./pros-lvgl-sim.hpp"
#if USE_PROS_LVGL_SIM == 1
#include "pros/misc.hpp"

namespace pros {
namespace competition {
/**
 * Get the current status of the competition control.
 *
 * \return The competition control status as a mask of bits with
 * COMPETITION_{ENABLED,AUTONOMOUS,CONNECTED}.
 */
std::uint8_t get_status(void)
{
    return 0;
}

std::uint8_t is_autonomous(void)
{
    return 0;
}
std::uint8_t is_connected(void)
{
    return 0;
}
std::uint8_t is_disabled(void)
{
    return 0;
}
} // namespace competition
Controller::Controller(controller_id_e_t id)
{
}
std::int32_t Controller::get_analog(controller_analog_e_t channel)
{
    return ncrapi::ProsLvglSim::GetSimCh(channel);
}
std::int32_t Controller::get_digital(controller_digital_e_t button)
{
    return ncrapi::ProsLvglSim::GetSimDig(button);
}
std::int32_t Controller::get_digital_new_press(pros::controller_digital_e_t button)
{
    return ncrapi::ProsLvglSim::GetSimDig(button);
}
std::int32_t Controller::rumble(const char *rumble_pattern)
{
    return 1;
}

} // namespace pros
#else
#endif