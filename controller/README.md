circuit~relay H bridge:
    DPDT relay actuator wiring
        +12V
           |
           |
     +-----+-----+
     |           |
   [Relay1]   [Relay2]
     |           |
    NC          NO
     |           |
     |---MOTOR---|
     |           |
    NO          NC
     |           |
    GND         GND
1. When **Relay 1** is energized, it switches Motor input 1 from NC (+12V) to NO (GND).
2. When **Relay 2** is energized, it switches Motor input 2 from NC (GND) to NO (+12V).

    +12V -----(fuse 15A)-------+
          |              |
          |           .---+---.
    cathode           | Relay1|
    (diode)           '---+---'
    anode                 |COM
       |             +--+--+
       |             |     |NO----> Motor A side
     GND             NC     |
                     |      |
                     GND    |
                            |
                        .--+--.
                        |Relay2|
                        '--+--'
                        |COM
                        +--+--+
                        |     |NO----> Motor B side
                        NC     |
                        |      |
                        GND    |
                            ...



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
        Mosfet IRLZ44N 
        Motor drive bts7960
        Gate resistors(10Ω – 100Ω 47Ω)
        Pull-down resistors(10kΩ)
        Flyback diodes IN5408/Schottky
        Current sensing
    


Sim:
    
