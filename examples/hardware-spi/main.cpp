#include <U8g2lib.h>

// GPIO chip number for character device
#define GPIO_CHIP_NUM 0
// SPI bus uses upper 4 bits and lower 4 bits, so 0x10 will be /dev/spidev1.0
#define SPI_BUS 0x02
#define OLED_SPI_PIN_RES            U8X8_PIN_NONE
#define OLED_SPI_PIN_DC             U8X8_PIN_NONE

#define OLED_SPI_PIN_CS             11

static U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R0, OLED_SPI_PIN_CS);


int main() {
    printf("-------------------------------------------\n");
    printf("Starting LCD-demo....\n");

    u8g2.initSpiHw(GPIO_CHIP_NUM, SPI_BUS, OLED_SPI_PIN_DC, OLED_SPI_PIN_RES, OLED_SPI_PIN_CS);
    u8g2.begin();

    while(1) {
        u8g2.clearDisplay();
        u8g2.sendBuffer();
        u8g2.setFont(u8g2_font_6x13_tr);
        u8g2.drawStr(1, 18, "U8g2 on HW SPI");
        u8g2.sendBuffer();
        u8g2.setFont(u8g2_font_unifont_t_symbols);
        u8g2.drawGlyph(112, 56, 0x2603);
        u8g2.sendBuffer();
        u8g2.sleepMs(1000);

        u8g2.clearDisplay();
        u8g2.sendBuffer();
        u8g2.setFont(u8g2_font_6x13_tr);
        u8g2.drawStr(1, 18, "Winter is coming....");
        u8g2.sendBuffer();
        u8g2.setFont(u8g2_font_unifont_t_symbols);
        u8g2.drawGlyph(112, 56, 0x2603);
        u8g2.sendBuffer();
        u8g2.sleepMs(1000);
    }
}