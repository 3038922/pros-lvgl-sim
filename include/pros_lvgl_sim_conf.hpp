#pragma once
#define USE_PROS_LVGL_SIM 1

#if USE_PROS_LVGL_SIM == 1
#define LVGL_INCLUDE_PATH "lvgl/lvgl.h"
#else
#define LVGL_INCLUDE_PATH "display/lvgl.h"
#endif
