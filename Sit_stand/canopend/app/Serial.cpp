#include "Serial.h"



Serial::Serial(bool quiet)
{
    Connected=false;
    PortCom=NULL;
    Connect(quiet);
}

Serial::~Serial()
{
    Disconnect();
}


bool Serial::Connect(bool quiet)
{
    printf("Connecting Serial.... \n");
    if(!Connected)
    {
        PortCom=fopen("/dev/ttyO4 ", "a+");
        if(PortCom){
            Connected = true;
        }else
        {
            Connected=false;
        }

    }
    if(Connected)
    {
        //Set port parameters
        struct termios options;
        tcgetattr(fileno(PortCom), &options);
        cfsetispeed(&options, B115200);
        cfsetospeed(&options, B115200);
        options.c_cflag &= ~PARENB; // no parity
        options.c_cflag &= ~CSTOPB; // 1 stop bit
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS8 | CLOCAL; // 8 bits
        tcsetattr(fileno(PortCom), TCSANOW, &options);
    }

    //Then check device
    if(Connected && !quiet)
    {
        printf("Connected...\n");
    }

    return Connected;
}

//!Close connection
void Serial::Disconnect()
{
    if(Connected)
    {
        fclose(PortCom);
    }

    Connected=false;
}


int Serial::SendChar(unsigned char c)
{
    if(Connected)
    {
        printf("%d", fprintf(PortCom, "hi \n"));
        return 0;
    }

    return -1;
}

int Serial::SendChars(const unsigned char *c, int nb_vals)
{
    if(Connected)
    {
        unsigned char mess[255];
        for(int i=0; i<fmin(nb_vals,255); i++)
            mess[i]=c[i];

        fprintf(PortCom, "%s\n", mess);
        return 0;
    }

    return -1;
}


int Serial::Read(char *value)
{
    char val[10];
    if(Connected)
    {
        if(fscanf(PortCom, "%c \n", val))
        {
            printf("Hi %s\n", val);

            return 0;

        }
        else
            return -2;
    }
    else //Not connected
    {
        //error otherwise
        return -1;
    }
}
