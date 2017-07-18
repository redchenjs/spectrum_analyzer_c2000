/*
 * main.c
 *
 *  Created on: 2017-4-16
 *      Author: redchenjs
 */
#include "inc/system/init.h"
#include "inc/system/user.h"

int main(void)
{
    system_init();          // 系统初始化，包括器件的配置，功能模块配置，外设驱动配置

    user_init();            // 应用程序初始化

    while (1) {
        user_loop();        // 应用主循环

        system_suspend();   // 系统休眠
    }
}
