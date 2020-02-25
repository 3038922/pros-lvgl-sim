
#include "./pros-lvgl-sim.hpp"
#if USE_PROS_LVGL_SIM == 1
#include "lvgl/lvgl.h"
#include "pros/rtos.hpp"
#include <ctime>
#include <thread> // std::thread, std::this_thread::sleep_for

namespace pros {

namespace c {
uint32_t millis(void)
{
    return lv_tick_get();
}
void delay(const uint32_t milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
} // namespace c
Task::Task(task_fn_t function, void *parameters, std::uint32_t prio, std::uint16_t stack_depth, const char *name)
{
    task = new std::thread(function, parameters);
}
void Task::remove()
{
    ((std::thread *)(task))->detach();
    delete ((std::thread *)(task));
    task = nullptr;
}
void Task::delay_until(std::uint32_t *const prev_time, const std::uint32_t delta)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(delta));
}
std::uint32_t Task::get_state()
{
    if (task == nullptr)
        return 0;
    else
        return 4;
}
} // namespace pros
#else
#endif