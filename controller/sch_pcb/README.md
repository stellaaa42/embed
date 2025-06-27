circuit~relay H bridge:
    DPDT relay H Bridge
    +12V -----(fuse)-------+
    
    +12V --(rly+)--(Cathode)--(D1N5819)--(Anode+)--(rly-)--SW--GND
                    +12V--(r1-nc)--m+ -->
                    GND--(r1-no)--m+   |left    --<
                    GND--(r2-nc)--m- --<          |right
                    +12V--(r2-no)--m-           -->

    +12V ---(r1-no)         (r2-nc) ------+
                     Motor
    GND ----(r1-nc)         (r2-no) ----GND
    +12V ---(Cathode)---(D)---(Anode)---GND

    sim test:
        add an inductor (~1-5mH) and series resistor as load
        HIGH/LOW
        SW
        OvelLoad: inductance
        Stuck: fuse handling
        Flyback diode clamp transient voltage
        Observe current 

        pulse:
            V(IN1) PULSE(0 5 0 1u 1u 5m 10m)
            V(IN2) DC 0
        Transient:
            .tran 0 20ms 0 10us
            .tran 0 10m 0 10u

    Netlist:
        power supply
        Dpdt Relay
        swx2
        ledx3 (Power, Extend, Retract) 
        resistors 470Ω
        flyback diodes 1N4007 -relay coil protection SW~diode~12v…fused
        Fuse 8A
        wire 14 AWG

circuit~mosfet H bridge:
    +12V
              │
              ├─────────────┬─────────────┐
              │             │             │
          [MOSFET Q1]   (Upper Left)  [MOSFET Q2]  (Upper Right)
              │             │             │
              └───── Motor/Actuator ──────┘
              │             │             │
          [MOSFET Q3]   (Lower Left)  [MOSFET Q4]  (Lower Right)
              │             │             │
             GND           GND           GND

    netlist:
        Motor drive BTS7960
        Mosfet IRLZ44N 
        Gate resistors(10Ω – 100Ω 47Ω)
        Pull-down resistors(10kΩ)
        Flyback diodes IN5408/Schottky
        Current sensing
    


Sim:
    
