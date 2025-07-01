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
 * 0    1   Read busy flag (DB7) and address counter (Db0 to DB6)
 * 1    0   DR write as an internal operation
 * 1    1   DR read as an internal operation
 */

/* Display data RAM (DDRAM) stores 8-bit character codes. Its capacity
 * is 80 x 8 bits, or 80 characters.
 */

/* Display is 16 character x 2 line
 * 5 x 8 dot pattern, driver can also do 5 x 10 +*/


