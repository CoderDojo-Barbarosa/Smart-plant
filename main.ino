#include <U8g2lib.h>

#define U8X8_HAVE_HW_I2C
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int pin_umiditate = A3;

void setup() {
    u8g2.begin();
}

void loop() {
    // ================ afisarea umiditatii solului ================
    u8g2.clearBuffer();

    // <--- determinarea umiditatii solului -->
    int umiditate_sol = analogRead(pin_umiditate);
    String text_umiditate_sol = String(umiditate_sol, 2).c_str();

    // <--- afisarea pe display -->
    u8g2.setFont(u8g2_font_profont17_tf);
    u8g2.setCursor(40, 41);
    u8g2.print(text_umiditate_sol);

    u8g2.

    u8g2.clearBuffer();

}