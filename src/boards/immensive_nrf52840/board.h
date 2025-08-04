#ifndef _IMMENSIVE_NRF52840_H_
#define _IMMENSIVE_NRF52840_H_

#define _PINNUM(port, pin)    ((port)*32 + (pin))

/*------------------------------------------------------------------*/
/* LED
 *------------------------------------------------------------------*/
#define LEDS_NUMBER           1
#define LED_PRIMARY_PIN       _PINNUM(0, 13)
#define LED_STATE_ON          1

/*------------------------------------------------------------------*/
/* BUTTON
 *------------------------------------------------------------------*/
#define BUTTONS_NUMBER        2
#define BUTTON_1              _PINNUM(0, 7)
#define BUTTON_2              _PINNUM(0, 10)
#define BUTTON_PULL           NRF_GPIO_PIN_PULLUP

//--------------------------------------------------------------------+
// BLE OTA
//--------------------------------------------------------------------+
#define BLEDIS_MANUFACTURER   "Immensive"
#define BLEDIS_MODEL          "Immensive nRF52840"

//--------------------------------------------------------------------+
// USB
//--------------------------------------------------------------------+
#define USB_DESC_VID           0x1B4F
#define USB_DESC_UF2_PID       0x0022
#define USB_DESC_CDC_ONLY_PID  0x0023

//------------- UF2 -------------//
#define UF2_PRODUCT_NAME       "Immensive nRF52840"
#define UF2_VOLUME_LABEL       "SFMM852BOOT"
#define UF2_BOARD_ID           "nRF52840-micromod-v10"

#define UF2_INDEX_URL          "https://www.sparkfun.com/products/16984"

#endif
