#ifndef SERIAL_H
#define SERIAL_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <termios.h>
//#include <FL/Fl.H>
//#include <FL/fl_ask.H>


class Serial
{
    public:
        Serial(bool quiet=false);
        ~Serial();

        bool Connect(bool quiet=false);
        void Disconnect();

        int SendChar(unsigned char c);
        int SendChars(const unsigned char *c, int nb_vals);

        int Read(char *value);

        bool GetConnected() { return Connected; }
        void SetConnected(bool val) { Connected = val; }

    private:
        FILE* PortCom;
        bool Connected;
};

#endif // SERIAL_H
