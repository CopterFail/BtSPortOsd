# BtSPortOsd
Ground OSD based on (micro)minimosd and a HC-05 BT Module. Telemetry - Data (S.Port) will be received via BT from RC-Transmitter (Taranis with a HC-05 in battery tray).

Build Steps:

1. Get the Hardware 2 x HC-05 Module , MicroMinimOsd , 2 x 5V Regulator , inverter for s.bus , plug for Taranis uart port

2. Config one HC-05 as master, set the baudrate 57600 , pair with the other slave HC-05

3. Connect uart port plug , 5V Regulator , Slave HC-05 and place it in the Taranis battery tray

4. Config your OSD in function void vUpdateOsd() and flash the osd

5. Connect OSD, 5V Regulator and Master HC-05 (Optional: Ground battery to the osd battery input) to video receiver and monitor.

6. enjoy :)


useful links:

https://github.com/opentx/opentx/wiki/Taranis-serial-port

https://oscarliang.com/ctt/uploads/2015/12/sbus-inverter-diagram-schematics.jpg

http://www.banggood.com/10Pcs-Mini-DC-Adjustable-Power-Supply-Buck-Module-Step-Down-Module-p-999753.html

http://www.banggood.com/HC-05-Wireless-Bluetooth-Serial-Module-With-Baseplate-For-Arduino-p-959393.html

http://www.banggood.com/HC-05-Wireless-Bluetooth-RF-Transceiver-Module-For-Arduino-p-74220.html

http://www.banggood.com/MICRO-MinimOSD-Minim-OSD-Mini-OSD-W-KV-Team-MOD-For-Naze32-Flight-Controller-p-990556.html

http://www.instructables.com/id/AT-command-mode-of-HC-05-Bluetooth-module/?ALLSTEPS


Special Thanks to:

https://github.com/opentx/opentx

https://github.com/UncleRus/MultiOSD

https://github.com/markohoepken/rx5808_pro_osd

https://github.com/iNavFlight/inav


