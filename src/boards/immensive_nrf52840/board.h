#ifndef _IMMENSIVE_NRF52840_H_
#define _IMMENSIVE_NRF52840_H_

#define _PINNUM(port, pin)    ((port)*32 + (pin))

/*------------------------------------------------------------------*/
/* IMMENSIVE
 *------------------------------------------------------------------*/

/*  Enable Firmware updates via MSC (Mass Storage Class).
    This method opens a USB disk to update the bootloader. 
    Current implementation is instable.
    By defaut USE_MSC is deactivated. */
#ifndef USE_MSC
    #define USE_MSC 0
#endif

/*------------------------------------------------------------------*/
/* LED
 *------------------------------------------------------------------*/
#define LEDS_NUMBER           0
//#define LED_PRIMARY_PIN       _PINNUM(0, 13)
//#define LED_STATE_ON          1

/*------------------------------------------------------------------*/
/* BUTTON (No buttons are connected on the board but it is required by the bootloader)
 *------------------------------------------------------------------*/
#define BUTTONS_NUMBER       2
#define BUTTON_1              _PINNUM(0, 4) // GPIO 4 - LED4 Red
#define BUTTON_2              _PINNUM(0, 5) // GPIO 5 - LED4 Green
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
