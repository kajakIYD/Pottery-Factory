#include"i2cdevice.h"


using namespace std;

#define MAX_BUS 64

I2CDevice::I2CDevice(int new_bus, int new_address)
{
    bus = new_bus;  // 2
    address = new_address;  // 5
}

int I2CDevice::readData(char* frame)
{

    char namebuf[MAX_BUS];
    snprintf(namebuf, sizeof(namebuf), "/dev/i2c-%d", bus);
    int file;
    if((file = open(namebuf, O_RDWR)) < 0){
    cout << "failed to open\n";
        return(1);
    }
    if(ioctl(file, I2C_SLAVE, address) < 0){
        cout << "failed 1\n";
        return(2);
    }

    char buf[3];
    for(int i=0;i<3;i++){
        buf[i] = frame[i];
    }

    if(write(file, buf, 3) != 3){
    cout << "fail to write\n";
    }
    int numberBytes = I2C_BUFFER;
    int bytesRead = read(file, this->dataBuffer, numberBytes);
    if (bytesRead == -1){
        cout << "fail to read\n";
    }
    close(file);
    int tmp = 69;

    cout << "T_read: ";
    cout << (int)(dataBuffer[0]);
    cout << "\n";
    tmp = raw2temp(dataBuffer);
    return tmp;

}

int I2CDevice::raw2temp(char *buf)
{

    temperatura = (int)buf[0];
    cout << "Temp: ";
    cout << temperatura;
    cout << "\n";

    return temperatura;
}
