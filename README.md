# DS4-ESP32 CONTROL CONNECTION
Codes for DS4-ESP32 Connection originated from the owner `https://github.com/un0038998/PS4Controller_ESP32.git`

# INSTRUCTIONS
For DS4 controller
- Download `Sixaxis Pair Tool` from this link `https://sixaxispairtool.en.lo4d.com/windows`.
- Open `GetBluetoothMacAddress.ino` file from the `GetBluetoothMacAddress` folder.
- Get the `MAC ADDRESS` of `ESP32` from the `GetBluetoothMacAddress.ino` file.
- Copy and paste the `MAC ADDRESS` to your `DS4` using `Sixaxis Pair Tool` and click the `Update` button.

For ESP32
- Install required Libraries in your Arduino IDE from `ArduinoLibraries` folder. 
- Open `Receive_Data.ino` file from the `Receive_Data` folder.
- Change the `MAC ADDRESS` in the `PS4.begin("your_mac_address")` using the `MAC ADDRESS` you got from `GetBluetoothMacAddres.ino` file.
- Add desired changes to the code to be remote by DS4 in the `void notify()`.
- Connect desired components.
- Compile and Upload
- After uploading, press the `EN` button on your ESP32 and press the `PS` button on your `DS4`.
- Wait for the changes and Enjoy.


