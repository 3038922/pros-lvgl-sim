#include "main.h"
#define USE_PROS_LVGL_SIM 1
#if USE_PROS_LVGL_SIM == 1
#include "../ncrapi_lvgl_sim_kernel/src/ncrLvglSimKernel.hpp"
extern "C" {
// #include "../ncrapi_lvgl_sim_kernel/freeRTOS/src/main.h"
// #include "lv_examples/lv_examples.h"
}
#endif
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button()
{
    // static bool pressed = false;
    // pressed = !pressed;
    // if (pressed)
    // {
    //     pros::lcd::set_text(2, "I was pressed!");
    // }
    // else
    // {
    //     pros::lcd::clear_line(2);
    // }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
    // pros::lcd::initialize();
    // pros::lcd::set_text(1, "Hello PROS User!");

    // pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize()
{
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol()
{
    //lv_demo_widgets();
    // pros::Controller master(pros::E_CONTROLLER_MASTER);
    // pros::Motor left_mtr(1);
    // pros::Motor right_mtr(2);
    // while (true)
    // {
    //     pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
    //                      (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
    //                      (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
    //     int left = master.get_analog(ANALOG_LEFT_Y);
    //     int right = master.get_analog(ANALOG_RIGHT_Y);
    //     left_mtr = left;
    //     right_mtr = right;
    //     pros::delay(20);
    // }
}
#if USE_PROS_LVGL_SIM == 1
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mouse.h"
#include "lvgl/lvgl.h"
#include <windows.h>

static int tick_thread(void *data)
{
    while (1)
    {
        lv_tick_inc(5);
        SDL_Delay(5); /*Sleep for 1 millisecond*/
    }
    return 0;
}

static lv_indev_t *kb_indev;
static void hal_init(void)
{
    /* Add a display
   * Use the 'monitor' driver which creates window on PC's monitor to simulate a
   * display*/
    monitor_init();

    static lv_disp_buf_t disp_buf1;
    static lv_color_t buf1_1[LV_HOR_RES_MAX * 120];
    lv_disp_buf_init(&disp_buf1, buf1_1, NULL, LV_HOR_RES_MAX * 120);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); /*Basic initialization*/
    disp_drv.buffer = &disp_buf1;
    disp_drv.flush_cb = monitor_flush;
    lv_disp_drv_register(&disp_drv);

    /* Add the mouse (or touchpad) as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv); /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = mouse_read; /*This function will be called periodically
                   (by the library) to get the mouse position and state*/
    lv_indev_drv_register(&indev_drv);

    /* If the PC keyboard driver is enabled in`lv_drv_conf.h`
   * add this as an input device. It might be used in some examples. */
#if USE_KEYBOARD
    lv_indev_drv_t kb_drv;
    lv_indev_drv_init(&kb_drv);
    kb_drv.type = LV_INDEV_TYPE_KEYPAD;
    kb_drv.read_cb = keyboard_read;
    kb_indev = lv_indev_drv_register(&kb_drv);
#endif

    /* Tick init.
   * You have to call 'lv_tick_inc()' in every milliseconds
   * Create an SDL thread to do this*/
    SDL_CreateThread(tick_thread, "tick", NULL);
}
int main(int argc, char **argv)
{
    lv_init();
    hal_init();
    while (1)
    {
        /* Periodically call the lv_task handler.
     * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        // pros::delay()
        Sleep(10); /*Just to let the system breathe */
    }
    // prvInitialiseHeap();
    // vTraceEnable(TRC_START);
    // ncrapi::NcrLvglSimKernel *prosLvglSim = ncrapi::NcrLvglSimKernel::initNcrLvglSimKernel();
    // vTaskStartScheduler();

    // while (1)
    //     ;
}
#endif