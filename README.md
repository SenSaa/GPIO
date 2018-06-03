# GPIO
Application to trigger GPIO 66 output pin (interfaced with LED) based on GPIO 69 pin input (interfaced with button).

User-space GPIO programming via sysfs to export information through Beaglebone Black's device tree.
Cross-Compiled and remotely deployed using Eclipse and GCC-Linaro Toolchain on Windows.

GPIO conversion formula (to map physical pin numbers to the kernel pin number):
```
 GPIO[nx32+m].
```
 So, P8-07 which is GPIO2_2:
```
 GPIO2_2 ->  GPIO (2x32) + 2 = GPIO 64 + 2 = GPIO 66!
```
P8-09 which is GPIO2_5:
```
 GPIO2_5 ->  GPIO (2x32) + 5 = GPIO 64 + 5 = GPIO 69!
```

There are four steps to the process of using a GPIO pin.
1) Export the pin.
2) Set the direction, e.g. “out” or "in".
3) Set pin to high or low.
4) When pin state is set, unexport pin.
