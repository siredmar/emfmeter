#pragma once
#include <LiquidCrystal.h>

class Display
{
  public:
    Display(int LcdRs, int LcdEnable, int LcdD4, int LcdD5, int LcdD6, int LcdD7, int row, int col)
    {
        lcd = new LiquidCrystal(LcdRs, LcdEnable, LcdD4, LcdD5, LcdD6, LcdD7);
        lcd->begin(row, col);
        lcd->display();
    }

    ~Display()
    {
        lcd->clear();
        lcd->home();
        lcd->noDisplay();
    }

    void Print(String val, int x, int y)
    {
        lcd->setCursor(x, y);
        lcd->print(val);
    }

    void Print(int val, int x, int y)
    {
        lcd->setCursor(x, y);
        lcd->print(val);
    }

    void Print(long val, int x, int y)
    {
        lcd->setCursor(x, y);
        lcd->print(val);
    }

    void Print(char val, int x, int y)
    {
        lcd->setCursor(x, y);
        lcd->print(val);
    }

  private:
    LiquidCrystal *lcd;
};