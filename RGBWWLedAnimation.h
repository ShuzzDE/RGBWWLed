/**************************************************************


    @author Patrick Jahns
    @version 0.1
 **************************************************************/

#ifndef RGBWWLedAnimation_h
#define RGBWWLedAnimation_h
#include "RGBWWLedColor.h"


class RGBWWLed;

class RGBWWLedAnimation
{
    public:
        virtual bool run() {};
        virtual bool run(int st) {};
};

class HSVTransition: public RGBWWLedAnimation
{
    public:
        HSVTransition() {};
        HSVTransition(HSV colorFrom, HSV color, const int& tm, const bool& shortDirection, RGBWWLed* rgbled);
        bool        run();
        bool        run(int st);

    private:
        HSV         _basecolor;
        HSV         _currentcolor;
        HSV         _finalcolor;
        int         _currentstep;
        int         _steps;
        int         _dhue;
        int         _hueerror;
        int         _huecount;
        int         _huestep;
        int         _dsat;
        int         _saterror;
        int         _satcount;
        int         _satstep;
        int         _dval;
        int         _valerror;
        int         _valcount;
        int         _valstep;
        int         _dkelvin;
        int         _kelvinerror;
        int         _kelvincount;
        int         _kelvinstep;

        RGBWWLed*    rgbled;

        int         bresenham(int& error, int& ctr, int& dx, int& dy, int& incr, int& base, int& current);

};

#endif // RGBWWLedAnimation_h