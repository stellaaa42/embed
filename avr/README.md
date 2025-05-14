## PADS settings

1mm = 40mils

Setup---Design Rules
    Trace width-> min:20 recommended:40 max:60 
    Clearance-> 17mil

Properties---Pad Stack
    Power -> Opposite Side Diameter: 90 Drill Size: 48  
    Others -> Opposite Side Diameter: 75 
    Jumper -> End Diameter: 75mil
    
Tools---Options mm -> mil

## arduino-cli

Mac
arduino-cli compile
--fqbn arduino:avr:uno
--build-path ./build

arduino-cli upload -p /dev/cu.usbmodem14101 --fqbn arduino:avr:uno ar
arduino-cli monitor -p /dev/cu.usbmodem14101

Brew install
arduino-cli version
arduino-cli config init
arduino-cli core update-index
arduino-cli core install arduino:avr

win
.\arduino-cli.exe compile --fqbn arduino:avr:uno p1 --output-dir p1\build
.\arduino-cli.exe upload -p COM7 --fqbn arduino:avr:uno --input-dir p1\build
.\arduino-cli.exe compile --fqbn arduino:avr:uno p1
.\arduino-cli.exe upload -p COM7 --fqbn arduino:avr:uno p1

--verbose

.\arduino-cli.exe board list
.\arduino-cli.exe
.\arduino-cli.exe core install arduino:avr
