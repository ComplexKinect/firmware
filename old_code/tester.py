from serial import Serial, SerialException
import time

cxn = Serial("/dev/ttyACM0", baudrate=9600)
time.sleep(2)

while True:
    for i in range(1,4):
        print(i)
        cxn.write([i])
        time.sleep(2)
