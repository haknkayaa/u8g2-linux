#include <U8g2lib.h>

// Set I2C bus and address
#define I2C_BUS 3
#define I2C_ADDRESS 0x3c * 2

// static U8G2_ST75256_JLX16080_1_HW_I2C u8g2(U8G2_R0);
static U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/
		U8X8_PIN_NONE);

int main() {
	printf("-------------------------------------------\n");
	printf("Starting LCD-demo\n");

	u8g2.initI2cHw(I2C_BUS);
	u8g2.setI2CAddress(I2C_ADDRESS);
	u8g2.begin();

	while(1) {
		u8g2.setFont(u8g2_font_6x13_tr);
		u8g2.drawStr(1, 18, "U8g2 on HW I2C");
		u8g2.sendBuffer();
		u8g2.setFont(u8g2_font_unifont_t_symbols);
		u8g2.drawGlyph(112, 56, 0x2603);
		u8g2.sendBuffer();
		u8g2.sleepMs(1000);

		u8g2.clearDisplay();
		u8g2.sendBuffer();

		u8g2.setFont(u8g2_font_6x13_tr);
		u8g2.drawStr(1, 18, "Winter is coming..");
		u8g2.sendBuffer();
		u8g2.setFont(u8g2_font_unifont_t_symbols);
		u8g2.drawGlyph(112, 56, 0x2603);
		u8g2.sendBuffer();
		u8g2.sleepMs(1000);

		u8g2.clearDisplay();
		u8g2.sendBuffer();
	}
}
