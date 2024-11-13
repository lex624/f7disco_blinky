/*
 * GPIO.hpp
 *
 *  Created on: Nov 12, 2024
 *      Author: mistya
 */

#ifndef GPIO_HPP_
#define GPIO_HPP_

// includes
#include "setup.hpp"

// GPIO output class
class GPIO_Output {

public:
    enum PinState : uint8_t { PinOff = 0, PinOn };

private:
    GPIO_TypeDef* m_pGPIO;
    uint16_t m_uPin;
    PinState m_eState;

public:
    GPIO_Output(GPIO_TypeDef* pGPIO, uint16_t uPin);
    GPIO_Output() = delete;
    ~GPIO_Output();
    void on(void);
    void off(void);
    void toggle(void);
    PinState getState(void) const;

};

#endif /* DEVICE_DRIVERS_GPIO_HPP_ */
