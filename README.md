# Current Sensor PCB V1

A current sensor board I designed in Altium Designer. It uses an INA228 to measure DC current through a shunt resistor and an STM32F103C8T6 to read the data over I2C and display it on a 16x2 LCD.

## How It Works

Two probe wires get wired in series with whatever circuit you want to measure. The current flows through a shunt resistor (R7) on the board and the INA228 reads the voltage drop across it to figure out how much current is flowing. The STM32 pulls that data over I2C and shows it on the LCD.

## Hardware

- STM32F103C8T6 microcontroller
- INA228 current sensor (I2C address 0x40)
- AMS1117-3.3 voltage regulator
- Shunt resistor R7 (value chosen and soldered after fab depending on the current range needed)
- Reverse polarity protection diode
- 5.6k I2C pullups
- Decoupling caps on power pins

Schematic and PCB done in Altium, board fabricated at JLCPCB, parts from Mouser.

## Firmware

PlatformIO project using Arduino framework for the STM32. Reads the INA228 over I2C and displays readings on a 16x2 LCD. Was not tested on hardware because of the issues below.

## Status: Did Not Work

Board was designed, fabbed and hand soldered but I ran into a hard short on the 3.3V rail during first power on. The bench supply kept going into cc mode and the voltage wouldn't come up past 0.8V even at 1A, which meant something on the board was basically a dead short between 3V3 and GND.

I traced heat to C4 first, removed it, still shorted. Then C6 was heating up, removed that too, still shorted. Never found the exact root cause after debugging. If find the issue with the board please let me know.


## Whats In The Repo

```
curr-sens.PrjPcb                       # Altium project
curr_sens_sch.SchDoc                    # Schematic
curr_sens_sch.pdf                       # Schematic PDF
curr_sens_pcb.PcbDoc                    # PCB layout
curr_sens_pcbV1 For FAB.zip             # Gerbers for JLCPCB
Design Rule Check - curr_sens_pcb.html  # DRC report
BOM.xlsx                                # Bill of materials
Final soldered pcb.jpg                  # Board photo
Soldering setup.jpg                     # Soldering photo
CurrSens Firmware V1.0/                 # Firmware (PlatformIO)
```

## Next Steps

The schematic and PCB layout checked out fine with no real DRC issues. The design is good, it just didn't survive assembly and bring up. Planning to do a V2 with fresh parts and a better power on process.
