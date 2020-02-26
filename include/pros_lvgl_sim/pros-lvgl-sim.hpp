#pragma once
#include "pros_lvgl_sim_conf.h"
#if USE_PROS_LVGL_SIM == 1
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mouse.h"
#include <conio.h>

namespace ncrapi {
class SimKB
{
  public:
    SimKB();
    static void loop(void (*f1)(), void (*f2)(), void (*f3)(), void (*f4)());
    //0 leftX 1 leftY 2 rightX 3 rightY
    static int GetSimCh(int);
    static int GetSimDig(int);

  private:
};
} // namespace ncrapi
extern "C" {
LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
}

/**
 * Print the memory usage periodically
 * @param param
 */
extern void memory_monitor(lv_task_t *param);
/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
extern int tick_thread(void *data);
extern void hal_init(void);
void taskLVGL(void *pragma);
#else
#endif