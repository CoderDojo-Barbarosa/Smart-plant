#include <U8g2lib.h>
#include <AHT20.h>
#define U8X8_HAVE_HW_I2C

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
AHT20 aht20;

const char sun_symbol[2] = {69, 0};
const char drop_symbol[2] = {72, 0};


void setup() {
    u8g2.begin();
    aht20.begin();
}

void loop() {
    // ================ afisarea umiditatii din aer ================
    u8g2.clearBuffer();


    // <---- determinarea umiditatii ---->
    float umiditate = aht20.getHumity(); // format float
    String text_umiditate = String(umiditate, 2).c_string() // transformarea din float in string

    // <--- afisarea pe display --> 
    u8g2.setCursor(0,48);
    u8g2.print(drop_symbol);

    u8g2.setFont(u8g2_font_profont17_tf);
    u8g2.setCursor(40, 41);
    u8g2.print(text_umiditate);

    u8g2.setCursor(105,41);
    u8g2.print("%");

    u8g2.sendBuffer();
    delay(2500);



    // ================ afisarea temperaturii din aer ================
    u8g2.clearBuffer();

    // <---- determinarea umiditatii ---->
    float temperatura = aht20.getTemperature(); // format float
    String text_temperatura = String(temperatura, 2).c_str(); // transformarea din float in string

    // <--- afisarea pe display --> 
    u8g2.setCursor(0,48);
    u8g2.print(sun_symbol);

    u8g2.setFont(u8g2_font_profont17_tf);
    u8g2.setCursor(40, 41);
    u8g2.print(text_temperatura);

    u8g2.setCursor(100,41);
    u8g2.print(str_degree);
    u8g2.setFont(u8g2_font_open_iconic_weather_4x_t);


    u8g2.sendBuffer();
    delay(2500);

}