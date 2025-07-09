#ifndef LiquidCrystal_H
#define LiquidCrystal_H

//#include <avr/io.h>
#include  <stdint.h>

class LiquidCrystal {
public:
    /*
    //4-bit mode without backlight control
    LiquidCrystal(uint16_t v0, uint16_t rs, uint16_t rw, uint16_t en,  uint16_t db4, uint16_t db5,
        uint16_t db6, uint16_t db7);

    //4-bit mode with backlight control
    LiquidCrystal(uint16_t v0, uint16_t rs, uint16_t rw, uint16_t en,  uint16_t db4, uint16_t db5,
        uint16_t db6, uint16_t db7, uint16_t bl1);
    */

    //8-bit mode with backlight control
    LiquidCrystal(uint16_t rs, uint16_t rw, uint16_t en, uint16_t db0,
        uint16_t db1, uint16_t db2, uint16_t db3, uint16_t db4, uint16_t db5,
        uint16_t db6, uint16_t db7, uint16_t bl1);

    /*
    //8-bit mode without backlight control
    LiquidCrystal(uint16_t v0, uint16_t rs, uint16_t rw, uint16_t en, uint16_t db0,
        uint16_t db1, uint16_t db2, uint16_t db3, uint16_t db4, uint16_t db5,
        uint16_t db6, uint16_t db7);
    */

    ~LiquidCrystal();
private:
    uint16_t rs; //register select
    uint16_t rw; //read/write
    uint16_t en; //enable
    uint16_t db0; // data0 . . . data 7
    uint16_t db1;
    uint16_t db2;
    uint16_t db3;
    uint16_t db4;
    uint16_t db5;
    uint16_t db6;
    uint16_t db7;
    uint16_t bl1; //backlight +

    void init(uint16_t rs, uint16_t rw, uint16_t en, uint16_t db0, uint16_t db1, uint16_t db2,
         uint16_t db3, uint16_t db4, uint16_t db5, uint16_t db6, uint16_t db7);
    void begin(uint16_t cols, uint16_t rows);
};

#endif
