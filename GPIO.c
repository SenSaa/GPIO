#include <stdio.h>
#include <unistd.h>

int main(void) {

  printf("\n Starting... \n");

  char GPIO_Value_HIGH[] = "1";
  char GPIO_Value_LOW[] = "0";
  char Joystick_GPIO_Reading[] = "0";

  FILE *LED_GPIO_value = NULL;

	// Export LED GPIO Pin
	char LED_GPIO_Pin_A[] = "66";
	FILE *Export_File = NULL;
	Export_File = fopen ("/sys/class/gpio/export", "w"); // Open FileSystem -  passing File Path & File access mode. * File access mode = "w" - if you want to write.
	fwrite (LED_GPIO_Pin_A, 1, sizeof(LED_GPIO_Pin_A), Export_File); // Write to File - passing Pin Number & SysFile Path
	fclose (Export_File); // Close File

	// Export Joystick GPIO Pin
	char Joystick_GPIO_Pin[] = "69";
	FILE *Export_File2 = NULL;
	Export_File2 = fopen ("/sys/class/gpio/export", "w"); // Open FileSystem -  passing File Path & File access mode.
	fwrite (Joystick_GPIO_Pin, 1, sizeof(Joystick_GPIO_Pin), Export_File2); // Write to File - passing Pin Number & SysFile Path
	fclose (Export_File2); // Close File

	// Sets the Direction of the LED Pin.
	char IO_O_Dir[] = "out";
	FILE *IO_Dir_LED_A = NULL;
	IO_Dir_LED_A = fopen ("/sys/class/gpio/gpio66/direction", "w"); // Open SystemFile -  passing File Path & File access mode.
	fwrite (IO_O_Dir, 1, sizeof(IO_O_Dir), IO_Dir_LED_A); // Write to File - passing IO Direction & SysFile path
	fclose (IO_Dir_LED_A); // Close File

	// Sets the Direction of the Joystick Pin.
	char IO_I_Dir[] = "in";
	FILE *IO_Dir_Joystick = NULL;
	IO_Dir_Joystick = fopen ("/sys/class/gpio/gpio69/direction", "w"); // Open SystemFile -  passing File Path & File access mode.
	fwrite (IO_I_Dir, 1, sizeof(IO_I_Dir), IO_Dir_Joystick); // Write to File - passing IO Direction & SysFile path
	fclose (IO_Dir_Joystick); // Close File

	FILE *Joystick_GPIO_value = NULL;
	while (1) {
		Joystick_GPIO_value = fopen ("/sys/class/gpio/gpio69/value", "r"); // Open Fs -  passing File Path & File access mode. *** File access mode = "r" - if you want to read!
		fread (Joystick_GPIO_Reading, 1, 1, Joystick_GPIO_value); // Write to File - passing Pin Value & SystemFile Path
		int value = atoi(Joystick_GPIO_Reading);
		fclose (Joystick_GPIO_value); // Close File
		if (value == 0) {
			LED_GPIO_value = fopen ("/sys/class/gpio/gpio66/value", "w"); // Open Fs -  passing File Path & File access mode.
			fwrite (GPIO_Value_HIGH, 1, sizeof(GPIO_Value_HIGH), LED_GPIO_value); // Write to File - passing Pin Value & System File Path
			fclose (LED_GPIO_value); // Close File
			printf("Value = %d\n", value);
		}
		else if (value == 1) {
			LED_GPIO_value = fopen ("/sys/class/gpio/gpio66/value", "w"); // Open Fs -  passing File Path & File access mode.
			fwrite (GPIO_Value_LOW, 1, sizeof(GPIO_Value_LOW), LED_GPIO_value); // Write to File - passing Pin Value & SystemFile Path
			fclose (LED_GPIO_value); // Close File
			printf("Value = %d\n", value);
		}
		usleep(200000);
	}

  return(0);
}

