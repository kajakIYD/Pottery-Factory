#ifndef I2CDevice_H
#define I2CDevice_H
#define I2C_BUFFER 0x80

#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<iostream>
#include<stdio.h>

#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include<sys/ioctl.h>
#include<stropts.h>


class I2CDevice
{
private:
    int bus, address;
    double temperatura;
    int wymuszenie;
    char dataBuffer[I2C_BUFFER];
public:
    I2CDevice(int bus = 2, int address = 0x16);
    //int readData(char sterowanie);
    int readData(char* frame);
    int raw2temp(char*);
    double getTemp(){ return temperatura; }
};

#endif // I2CDevice_H
