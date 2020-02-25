# pros-lvgl-sim
At present, `./ncrapi/I18N` only has Chinese. Welcome to help me translate.
- Download: `git clone --recursive https://github.com/3038922/pros-lvgl-sim.git`
- or: `git clone https://github.com/3038922/pros-lvgl-sim.git` `git submodule update --init --recursive` 
- how to build:
[Development Environment Tutorial](https://3038922.github.io/new_century_robotics/)

# Cmake tools tutorial
![avatar](./pic/1.jpg)
![avatar](./pic/2.jpg)
![avatar](./pic/3.jpg)
![avatar](./pic/4.jpg)
![avatar](./pic/5.jpg)
- Considering the future, I have updated lvgl to 6.1.
- The API of pros itself has a little conflict with the simulator support, so don't directly cover the project into the project of pros at present.
- After all the tests are completed, I will delete the ncrapi related code and only keep the independent pros-lvgl-sim. 

## Operation guide
1. click `1` autonomous()
2. click `2` opcontrol()
3. click `3` competition_initialize()
4. click `4` disabled()
5. click `w` `s`  `E_CONTROLLER_ANALOG_LEFT_Y`.It will be displayed in PWM
6. click `a` `d`  `E_CONTROLLER_ANALOG_RIGHT_X`.It will be displayed in PWM
7. click `q` `e`  `E_CONTROLLER_ANALOG_LEFT_X`.It will be displayed in PWM
8. click `⬆ Up Arrow` `⬇ Dw Arrow`  `E_CONTROLLER_ANALOG_RIGHT_Y`.
9. click `z` `E_CONTROLLER_DIGITAL_L1`.
10. click `x` `E_CONTROLLER_DIGITAL_L2`.
11. click `c` `E_CONTROLLER_DIGITAL_R1`.
12. click `v` `E_CONTROLLER_DIGITAL_R2`.
13. click `r` `E_CONTROLLER_DIGITAL_UP`.
14. click `f` `E_CONTROLLER_DIGITAL_DOWN`.
15. click `t` `E_CONTROLLER_DIGITAL_LEFT`.
16. click `g` `E_CONTROLLER_DIGITAL_RIGHT`.
17. click `y` `E_CONTROLLER_DIGITAL_X`.
18. click `h` `E_CONTROLLER_DIGITAL_B`.
19. click `u` `E_CONTROLLER_DIGITAL_Y`.
20. click `j` `E_CONTROLLER_DIGITAL_A`.
## Project Preview
![avatar](./pic/6.jpg)