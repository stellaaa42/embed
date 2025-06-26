# arduino as in system programming

## Sketch -> Upload using programmer
    chip -> Attiny85
    port -> Arduino Uno
    clock -> internal 8 MHz
    processor -> Attiny85
    programmer -> 'Arduino as ISP'


# arduino-cli

## Mac
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

## win
    .\arduino-cli.exe compile --fqbn arduino:avr:uno p1 --output-dir p1\build
    .\arduino-cli.exe upload -p COM7 --fqbn arduino:avr:uno --input-dir p1\build
    .\arduino-cli.exe compile --fqbn arduino:avr:uno p1
    .\arduino-cli.exe upload -p COM7 --fqbn arduino:avr:uno p1
    
    --verbose
    
    .\arduino-cli.exe board list
    .\arduino-cli.exe
    .\arduino-cli.exe core install arduino:avr
