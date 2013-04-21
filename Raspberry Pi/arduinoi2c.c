#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <stdio.h>
#include <unistd.h>

int deviceHandle;
int readBytes;
unsigned char buffer[7];

// Based on https://github.com/binerry/RaspberryPi/blob/master/snippets/c/i2c-arduino/i2c-arduino.c

int main (void)
{
  int i;
	printf("Hi there!\n");


	// initialize buffer
	buffer[0] = 0x00;
  
	// address of i2c Arduino device
	int deviceI2CAddress = 0x2A;  // (0x2A = 42)
  unsigned int value;
	// open device on /dev/i2c-1 (RPi model B)
	if ((deviceHandle = open("/dev/i2c-1", O_RDWR)) < 0) {
		printf("Error: Couldn't open device! %d\n", deviceHandle);
		return 1;
	}

	// connect to arduino as i2c slave
	if (ioctl(deviceHandle, I2C_SLAVE, deviceI2CAddress) < 0) {
		printf("Error: Couldn't find arduino on address!\n");
		return 1;
	}  

	// begin transmission and request acknowledgement
	//readBytes = write(deviceHandle, buffer, 1);
	//if (readBytes != 1)
	//{
	//	printf("Error: Received no ACK-Bit, couldn't established connection!");
	//}
	//else
	{
		for(i=0;i<65535;i++)
		{
		
		  readBytes = read(deviceHandle, buffer, 2);
		 
		  if(readBytes==2)
		  {
		    value = ((buffer[0]<<8)&0xFF00) + buffer[1];
		    printf("Value: %d\n",value);
		  }
		}
	}

	// close connection and return
	close(deviceHandle);
	return 0;
}

