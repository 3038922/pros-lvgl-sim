
#include "./pros-lvgl-sim.hpp"
#if USE_PROS_LVGL_SIM == 1
#include "lvgl/lvgl.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include <algorithm>
#include <array>
#include <iostream>

/**
 * Print the memory usage periodically
 * @param param
 */
void memory_monitor(lv_task_t *param)
{
    (void)param; /*Unused*/

    lv_mem_monitor_t mon;
    lv_mem_monitor(&mon);
    printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n", (int)mon.total_size - mon.free_size,
           mon.used_pct,
           mon.frag_pct,
           (int)mon.free_biggest_size);
}
/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
int tick_thread(void *data)
{
    (void)data;

    while (1)
    {
        SDL_Delay(5);   /*Sleep for 5 millisecond*/
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }

    return 0;
}
void hal_init(void)
{
    /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    monitor_init();

    /*Create a display buffer*/
    static lv_disp_buf_t disp_buf1;
    static lv_color_t buf1_1[480 * 10];
    lv_disp_buf_init(&disp_buf1, buf1_1, NULL, 480 * 10);

    /*Create a display*/
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); /*Basic initialization*/
    disp_drv.buffer = &disp_buf1;
    disp_drv.flush_cb = monitor_flush; /*Used when `LV_VDB_SIZE != 0` in lv_conf.h (buffered drawing)*/
    lv_disp_drv_register(&disp_drv);

    /* Add the mouse as input device
     * Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv); /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = mouse_read; /*This function will be called periodically (by the library) to get the mouse position and state*/
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv);

    /*Set a cursor for the mouse*/
    lv_obj_t *cursor_obj = lv_img_create(lv_disp_get_scr_act(NULL), NULL); /*Create an image object for the cursor */
    lv_img_set_src(cursor_obj, &mouse_cursor_icon);                        /*Set the image source*/
    lv_indev_set_cursor(mouse_indev, cursor_obj);                          /*Connect the image  object to the driver*/

    /* Tick init.
     * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about how much time were elapsed
     * Create an SDL thread to do this*/
    SDL_CreateThread(tick_thread, "tick", NULL);

    /* Optional:
     * Create a memory monitor task which prints the memory usage in periodically.*/
    lv_task_create(memory_monitor, 3000, LV_TASK_PRIO_MID, NULL);
}
void taskLVGL(void *pragma)
{
    (void)pragma;
    while (1)
    {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        pros::delay(10);
    }
}
namespace ncrapi {

std::array<int, 16> _btn; //0 leftX ,1 leftY ,2  rightX ,3 _rightY;
lv_indev_drv_t _real_kb_drv;
lv_indev_data_t _kbDate; //键盘数据
uint32_t _lastKbVal;
bool isFirtstRun = true;
ProsLvglSim *ProsLvglSim::_prosLvglSim = nullptr; // 单例定义
ProsLvglSim *ProsLvglSim::initProsLvglSim()
{
    if (_prosLvglSim == nullptr)
        _prosLvglSim = new ProsLvglSim();
    return _prosLvglSim;
}

ProsLvglSim::ProsLvglSim()
{
    /*Initialize LittlevGL*/
    lv_init();
    /*Initialize the HAL (display, input devices, tick) for LittlevGL*/
    hal_init();
    _mainTask = new std::thread(taskLVGL, nullptr);
    lv_indev_drv_init(&_real_kb_drv);
    _real_kb_drv.type = LV_INDEV_TYPE_KEYPAD;
    _real_kb_drv.read_cb = keyboard_read;
    _lastKbVal = 0;
    _kbDate.key = 51;
}
ProsLvglSim::~ProsLvglSim()
{
    _mainTask->detach();
    delete _mainTask;
    _mainTask = nullptr;
}
void ProsLvglSim::loop(void (*f1)(), void (*f2)(), void (*f3)(), void (*f4)())
{
    if (_kbDate.state == LV_INDEV_STATE_PR || isFirtstRun) //如果按住
    {
        if (_kbDate.key != _lastKbVal) //如果这次值不等于上次值
            switch (_kbDate.key)
            {
                case 49:
                    (*f1)(); //AUTO
                    break;
                case 50:
                    (*f2)(); //OPCONTROL
                    break;
                case 51:
                    (*f3)(); //COMP
                    break;
                case 52:
                    (*f4)(); //DISABLE
                    break;
                default:
                    _btn.fill(0);
                    break;
            }
        else
            switch (_kbDate.key)
            {
                case 119: //W
                    _btn[pros::E_CONTROLLER_ANALOG_LEFT_Y]++;
                    break;
                case 115: //S
                    _btn[pros::E_CONTROLLER_ANALOG_LEFT_Y]--;
                    break;
                case 97: //A
                    _btn[pros::E_CONTROLLER_ANALOG_RIGHT_X]--;
                    break;
                case 100: //D
                    _btn[pros::E_CONTROLLER_ANALOG_RIGHT_X]++;
                case 113: //Q
                    _btn[pros::E_CONTROLLER_ANALOG_LEFT_X]--;
                    break;
                case 101: //E
                    _btn[pros::E_CONTROLLER_ANALOG_LEFT_X]++;
                    break;
                case 38: //Up Arrow
                    _btn[pros::E_CONTROLLER_ANALOG_RIGHT_Y]--;
                    break;
                case 40: //Dw Arrow
                    _btn[pros::E_CONTROLLER_ANALOG_RIGHT_Y]++;
                    break;
                //DIG
                case 114: //R
                    _btn[pros::E_CONTROLLER_DIGITAL_UP - 2] = 1;
                    break;
                case 102: //F
                    _btn[pros::E_CONTROLLER_DIGITAL_DOWN - 2] = 1;
                    break;
                case 116: //T
                    _btn[pros::E_CONTROLLER_DIGITAL_LEFT - 2] = 1;
                    break;
                case 103: //G
                    _btn[pros::E_CONTROLLER_DIGITAL_RIGHT - 2] = 1;
                case 121: //y
                    _btn[pros::E_CONTROLLER_DIGITAL_X - 2] = 1;
                    break;
                case 104: //h
                    _btn[pros::E_CONTROLLER_DIGITAL_B - 2] = 1;
                case 117: //u
                    _btn[pros::E_CONTROLLER_DIGITAL_Y - 2] = 1;
                    break;
                case 106: //j
                    _btn[pros::E_CONTROLLER_DIGITAL_A - 2] = 1;
                    break;
                case 122: //z
                    _btn[pros::E_CONTROLLER_DIGITAL_L1 - 2] = 1;
                    break;
                case 120: //x
                    _btn[pros::E_CONTROLLER_DIGITAL_L2 - 2] = 1;
                case 99: //c
                    _btn[pros::E_CONTROLLER_DIGITAL_R1 - 2] = 1;
                    break;
                case 118: //v
                    _btn[pros::E_CONTROLLER_DIGITAL_R2 - 2] = 1;
                    break;
                default:
                    _btn.fill(0);
                    break;
            }
    }
    else
        _btn.fill(0);
    isFirtstRun = false;
    _lastKbVal = _kbDate.key;
    keyboard_read(&_real_kb_drv, &_kbDate);
}
int ProsLvglSim::GetSimCh(int x)
{
    return std::clamp(_btn[x], -127, 127);
}
int ProsLvglSim::GetSimDig(int x)
{
    return _btn[x - 2];
}
} // namespace ncrapi

#else
#endif