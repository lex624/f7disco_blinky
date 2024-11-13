// Includes
#include "gpio.hpp"

// Constructor
GPIO_Output::GPIO_Output(GPIO_TypeDef* pGPIO, uint16_t uPin) :
    m_pGPIO(pGPIO), m_uPin(uPin), m_eState(PinOff) {

    GPIO_InitTypeDef GPIO_Init = {0};

    // Configure GPIO pin for output
    GPIO_Init.Pin = uPin;
    GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pull = GPIO_NOPULL;
    GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(m_pGPIO, &GPIO_Init);
}

// Destructor
GPIO_Output::~GPIO_Output() {
    HAL_GPIO_DeInit(m_pGPIO, m_uPin); // Optionally de-initialize GPIO
}

// Methods
void GPIO_Output::on(void) {
    HAL_GPIO_WritePin(m_pGPIO, m_uPin, GPIO_PIN_SET);
    m_eState = PinOn;
}

void GPIO_Output::off(void) {
    HAL_GPIO_WritePin(m_pGPIO, m_uPin, GPIO_PIN_RESET);
    m_eState = PinOff;
}

void GPIO_Output::toggle(void) {
    HAL_GPIO_TogglePin(m_pGPIO, m_uPin);
    m_eState = (m_eState == PinOn) ? PinOff : PinOn;
}

GPIO_Output::PinState GPIO_Output::getState(void) const {
    return m_eState;
}
