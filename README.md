# BtSPortOsd
Ground OSD based on (micro)minimosd and a HC-05 BT Module. Telemetry - Data (S.Port) will be received via BT from RC-Transmitter (Taranis with a HC-05 in battery tray).

Build Steps:

1. Get the Hardware 2 x HC-05 Module , MicroMinimOsd , 2 x 5V Regulator , inverter for s.bus , plug for Taranis uart port

2. Config one HC-05 as master, set the baudrate 57600 , connect with the other HC-05

3. Connect uart port plug , 5V Regulator , Master HC-05 and place it in the Taranis battery tray

4. Config your OSD in function void vUpdateOsd() and flash the osd

5. Connect OSD, 5V Regulator and Slave HC-05 (Optional: Ground battery to the osd battery input) to video receiver and monitor.

6. enjoy :)
