/*
 * This file is part of INAV Project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License Version 3, as described below:
 *
 * This file is free software: you may copy, redistribute and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 */

#include <stdint.h>

#include "platform.h"

#include "drivers/bus.h"
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"
#include "drivers/pinio.h"
#include "drivers/sensor.h"

BUSDEV_REGISTER_SPI_TAG(busdev_bmi270,      DEVHW_BMI270,       BMI270_SPI_BUS,     BMI270_CS_PIN,      NONE,        0,  DEVFLAGS_NONE,  IMU_BMI270_ALIGN);
BUSDEV_REGISTER_SPI_TAG(busdev_mpu6500,     DEVHW_MPU6500,      MPU6500_SPI_BUS,    MPU6500_CS_PIN,     MPU6500_EXTI_PIN,   0,  DEVFLAGS_NONE,  IMU_MPU6500_ALIGN);

timerHardware_t timerHardware[] = {
    DEF_TIM(TIM8, CH1, PC6,   TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO | TIM_USE_FW_MOTOR, 0, 0),   // S1
    DEF_TIM(TIM8, CH2, PC7,   TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO | TIM_USE_FW_MOTOR, 0, 0),   // S2
    DEF_TIM(TIM8, CH3, PC8,   TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO, 0, 0),   // S3
    DEF_TIM(TIM8, CH4, PC9,   TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO, 0, 0),   // S4

    DEF_TIM(TIM2, CH3, PB10,  TIM_USE_MC_SERVO | TIM_USE_FW_SERVO, 0, 0),   // PWM1
    DEF_TIM(TIM2, CH4, PB11,  TIM_USE_MC_SERVO | TIM_USE_FW_SERVO, 0, 0),   // PWM2

    DEF_TIM(TIM4, CH2, PB7,  TIM_USE_PPM, 0, 0),                            // PPM, RX1
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
