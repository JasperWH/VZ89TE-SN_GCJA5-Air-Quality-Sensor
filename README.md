# Background

## C02[1]:
The outdoor air in most locations contains down to about 380 parts per million carbon dioxide. Higher outdoor CO2 concentrations can be found near vehicle traffic areas, industry and sources of combustion. Elevated indoors levels are primarily from peoples breath indoors. Without adequate ventilation to dilute and remove the CO2 being continuously generated by the occupants, CO2 can accumulate. This can have a detrimental effect on work as symptoms such as tiredness, lack of focus take effect.

## Particulate Matter [2]:
This is a mixture of solid and liquid particles that are suspended in the air. These are categorized into coarse, fine and ultrafine. PM2.5 are fine particles that have a diameter less than 2.5 micrometers (more than 100 times thinner than a human hair) and remain suspended in the air for longer durations. The health risk with PM2.5 is that they can travel deep into the respiratory tract, reaching the lungs and entering the blood stream.

## CO2 Air Quality Levels [3]:
- 250-400ppm	Normal background concentration in outdoor ambient air
- 400-1,000ppm	Concentrations typical of occupied indoor spaces with good air exchange
- 1,000-2,000ppm	Complaints of drowsiness and poor air.
- 2,000-5,000 ppm	Headaches, sleepiness and stagnant, stale, stuffy air. Poor concentration, loss of attention, increased heart rate and slight nausea may also be present.
- 5,000	Workplace exposure limit (as 8-hour TWA) in most jurisdictions.
- 40,000+ ppm	Exposure may lead to serious oxygen deprivation resulting in permanent brain damage, coma, even death.
note CO2 measurements are only a broad guide to ventilation rather than demonstrating 'safe levels'

## Particle Air Quality Levels [2]:
- 0-12 μg/m3 Long term safe level
- 35+ μg/m3 Short term acceptable level however during a 24-hour period air is considered unhealthy and can cause issues for people with existing breathing issues such as asthma
- 50+ μg/m3 Prolonged exposure to levels above can lead to serious health issues and premature mortality

## Placement [4]:
Locate the monitor at head height and keep them away from:
- windows
- doors
- air supply openings
Position the monitors over 50cm away from people as their exhaled breath contains CO2. If your monitor is too close it may give a misleadingly high reading.

# Implementation:
## Hardware:
- MICS-VZ-89TE VOC Sensor IAQ Module
- SN-GCJA5 Sensor Particle Matter (with connector cable)
- STM32F407G-DISC1 Discovery Board
- 2x 4k7 resistors
- 10x LEDS
- 10x 100 ohm resistors
- USB PCB board
- 5v USB power supply
- Case
- Jumper wires
- Pin Headers

### Setup:
![Circuit Design](https://github.com/JasperWH/VZ89TE-SN_GCJA5-Air-Quality-Sensor/blob/main/Pictures/Air_quality_Sensor_Circuit_Diagram.PNG)
THe user recomends:
>In this case, the 5V and 3V pins deliver a 5 V or 3 V power supply and power consumption must be lower than 100 mA.
This project draws more that 200mA just thruogh the LEDs so for any long term use it is recommened xto use a transistor can act as a digital switch and run everythnig straight from a 5v and 3.3v power supply

## Software:
- STMCubeIDE

### Setup:
![STM32Cube setup](https://github.com/JasperWH/VZ89TE-SN_GCJA5-Air-Quality-Sensor/blob/main/Pictures/Air_quality_Sensor_STM32_setup.PNG)

### Code:
This programme has been written in C, no external libraries need to be downaload to run this application

## References:
- [1] https://www.energy.wsu.edu/documents/co2inbuildings.pdf
- [2] https://www.indoorairhygiene.org/pm2-5-explained/
- [3] https://www.kane.co.uk/knowledge-centre/what-are-safe-levels-of-co-and-co2-in-rooms
- [4] https://www.hse.gov.uk/ventilation/using-co2-monitors.htm#:~:text=The%20amount%20of%20CO2%20in,take%20action%20to%20improve%20it.

