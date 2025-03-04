/* SSR I2C Relay test for LaskaKit 8-kanálový SSR Relé modul I2C 250VAC 2A
 * 
 * LaskaKit 8-kanálový SSR Relé modul I2C 250VAC 2A: https://www.laskakit.cz/laskakit-8-kanalovy-ssr-rele-modul-i2c-250vac-2a/
 * 
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

#include <Wire.h>

// I2C slave addresses can changeable by user via dip switch on board
#define BOARD_1 0x20        // i2c slave address of BOARD #1
#define  ON 0
#define OFF 1
int FAST = 1000;            // delay value in ms
unsigned char i2c_buffer;

void setup(){
  Wire.begin();
}
void channel_mode(unsigned char addr, unsigned char channel, unsigned char value){
  channel = 8-channel;
  i2c_buffer &= ~(1<<(channel));
  i2c_buffer |= value<<channel;
  Wire.beginTransmission(addr);
  Wire.write(~i2c_buffer);
  Wire.endTransmission();
}
void loop(){
  channel_mode(BOARD_1,1,ON); delay(FAST);      // Turn ON channel 1 on board#1 and then wait delay
  channel_mode(BOARD_1,2,ON); delay(FAST);      // Turn ON channel 2 on board#1 and then wait delay
  channel_mode(BOARD_1,3,ON); delay(FAST);      // Turn ON channel 3 on board#1 and then wait delay
  channel_mode(BOARD_1,4,ON); delay(FAST);      // Turn ON channel 4 on board#1 and then wait delay
  channel_mode(BOARD_1,5,ON); delay(FAST);      // Turn ON channel 5 on board#1 and then wait delay
  channel_mode(BOARD_1,6,ON); delay(FAST);      // Turn ON channel 6 on board#1 and then wait delay
  channel_mode(BOARD_1,7,ON); delay(FAST);      // Turn ON channel 7 on board#1 and then wait delay
  channel_mode(BOARD_1,8,ON); delay(FAST);      // Turn ON channel 8 on board#1 and then wait delay
  channel_mode(BOARD_1,1,OFF); delay(FAST);     // Turn OFF channel 1 on board#1 and then wait delay
  channel_mode(BOARD_1,2,OFF); delay(FAST);     // Turn OFF channel 2 on board#1 and then wait delay
  channel_mode(BOARD_1,3,OFF); delay(FAST);     // Turn OFF channel 3 on board#1 and then wait delay
  channel_mode(BOARD_1,4,OFF); delay(FAST);     // Turn OFF channel 4 on board#1 and then wait delay
  channel_mode(BOARD_1,5,OFF); delay(FAST);     // Turn OFF channel 5 on board#1 and then wait delay
  channel_mode(BOARD_1,6,OFF); delay(FAST);     // Turn OFF channel 6 on board#1 and then wait delay
  channel_mode(BOARD_1,7,OFF); delay(FAST);     // Turn OFF channel 7 on board#1 and then wait delay
  channel_mode(BOARD_1,8,OFF); delay(FAST);     // Turn OFF channel 8 on board#1 and then wait delay
}
