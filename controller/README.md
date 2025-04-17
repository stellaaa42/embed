css:
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
Transient:
    .tran 0 10m 0 10u
pulse:
    V(IN1) PULSE(0 5 0 1u 1u 5m 10m)
    V(IN2) DC 0

Netlist:
    IRLZ44N
    Gate resistors(10Ω – 100Ω 47Ω)
    Pull-down resistors(10kΩ)
    Flyback diodes
    SW
    Current sensing
    Fuse


Sim:
    IN1 HIGH, IN2 LOW
    Load: inductance
    Stuck: fuse handling
