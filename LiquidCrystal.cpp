#define F_CPU 16000000UL
#include <util/delay.h> // Requires F_CPU macro
#include "LiquidCrystal.h"

/*
//4-bit mode without backlight control
LiquidCrystal::LiquidCrystal(uint16_t rs, uint16_t rw, uint16_t en,  uint16_t db4, uint16_t db5,
                   uint16_t db6, uint16_t db7) {

}
*/

/*
//4-bit mode with backlight control
LiquidCrystal::LiquidCrystal(uint16_t rs, uint16_t rw, uint16_t en,  uint16_t db4, uint16_t db5,
                   uint16_t db6, uint16_t db7, uint16_t bl1) {

}
*/

//8-bit mode with backlight control
LiquidCrystal::LiquidCrystal(uint16_t rs, uint16_t rw, uint16_t en, uint16_t db0,
    uint16_t db1, uint16_t db2, uint16_t db3, uint16_t db4, uint16_t db5,
                   uint16_t db6, uint16_t db7, uint16_t bl1) {
    init(rs, rw, en, db0, db1, db2, db3, db4, db5, db6, db7);

}
/*
//8-bit mode without backlight control
LiquidCrystal::LiquidCrystal(uint16_t rs, uint16_t rw, uint16_t en, uint16_t db0,
                             uint16_t db1, uint16_t db2, uint16_t db3, uint16_t db4, uint16_t db5,
                             uint16_t db6, uint16_t db7) {

}
*/
void LiquidCrystal::init(uint16_t rs, uint16_t rw, uint16_t en, uint16_t db0, uint16_t db1, uint16_t db2,
        uint16_t db3, uint16_t db4, uint16_t db5, uint16_t db6, uint16_t db7) {
    this->rs = rs;
    this->rw = rw;
    this->en = en;
    this->db0 = db0;
    this->db1 = db1;
    this->db2 = db2;
    this->db3 = db3;
    this->db4 = db4;
    this->db5 = db5;
    this->db6 = db6;
    this->db7 = db7;
}

void LiquidCrystal::begin(uint16_t cols, uint16_t rows) {
    // wait for more than 40 ms after Vcc rises to 2.7 V
    _delay_ms(50);

    // Function Set
    rs 0
    rw 0
    DB 00111000

    // wait for more than 4.1 ms
    _delay_us(6);

    // Function Set

    // wait for more than 100 microSeconds
    _delay_us(110);

    // Function Set


    // Specify the number of display lines and character font.


    // Display off


    // Display Clear


    // Entry mode set





}

/*RS - Function selects registers
 * 0 - Instruction register (for write) Busy Flag address counter (for read)
 *  1 - Data Register (for write and read)
 */

/* R/W - Selects read or write
 * 0 - write
 * 1 - read
 */

/* E - Starts data read/write */

/* RS = 0 and R/W = 1,
 * RS   R/W Operation
 * 0    0   IR write as an internal operation
 * 0    1   Read busy flag (DB7) and address counter (DB0 to DB6)
 * 1    0   DR write as an internal operation
 * 1    1   DR read as an internal operation
 */

/* Display data RAM (DDRAM) stores 8-bit character codes. Its capacity
 * is 80 x 8 bits, or 80 characters.
 */

/* Display is 16 character x 2 line
 * 5 x 8 dot pattern, driver can also do 5 x 10 +*/


/* The Busy state lasts for 10ms after voltage rises to 4.5V
Check the busy flag before sending an instruction from the MPU */

/******************** Instructions */
/* Instruction  RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 * ClearDisplay 0   0   0   0   0   0   0   0   0   1
 *
 * Return Home  0   0   0   0   0   0   0   0   1   -
 *
 * Display      0   0   0   0   0   0   1   D   C   B
 * on/off
 * Control
 *
 * . . .
 * Read Busy    0   1   BF  AC  AC  AC  AC  AC  AC  AC
 * flag
 *
 * Write Data   1   0   Write Data
 * to CG or
 * DDRAM
 *
 * Read Data    1   1   Read Data
 * to CG or
 * DDRAM
 *
 * Function     0   0   0   0   1   DL  N   F   -   -
 * Set
 *
 *
 * DL = 1: 8 bits DL = 0: 4 bits
 * N = 1: 2 lines, N = 0: 1 line
 * F = 1: 5 x 10 dots, F = 0: 5 x 8 dots
 * BF = 1: Internally operating
 * BF = 0: INstructions accepatable
 * D display
 * C cursor
 * B blinking of cursor position character
*/

/*
Instructions
    page 24

Display Example
    page 43

Initializing by Instruction
    page 45

Timing Diagram
    Page 58
*/

void setPin(volatile uint8_t *port, uint8_t pin, uint8_t value)
*port |= (1 << pin); // Set the pin high
*port &= ~(1 << pin); // Set the pin low

01001101
