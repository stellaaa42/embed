circuit~relay:
    +12V -----(fuse 15A)---(diode)----+
                        |
                    +------[DPDT1]-----+---- Motor (Actuator) + terminal
                    |               |
    [S1]==(ON-NEUTRAL-ON)==          [NO]
                    |               |
                    +------[DPDT2]-----+---- Motor (Actuator) - terminal
                        |
                        GND

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

circuit~mosfet/H bridge:
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
    
