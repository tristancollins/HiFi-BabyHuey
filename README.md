# HiFi-BabyHuey
An "Engineer's" Baby Huey EL34 PCB

## BoM
Included as excel file
Toroidy power transformer
Primary Windings output transformers

## Chassis
Schaeffer / FPE files included

## Board size
Width:	329.9460 mm 
Height:	146.5580 mm 
Area:	48356.2259 sq. mm

## Power-up procedure
### Safety first
**Make sure all grounds are connected back to the IEC earth connection, and then that IEC earth pin is connected to the earth pin on your plug.**

### Step 1

- Adjust the bias pots (RV303 & RV304, RV403 & RV404) counter-clockwise to limit the bias point on the EL34s.
- Adjust driver current set (RV301 & RV401) to 680r by measuring across the footprint of R302/R402
- DON'T INSTALL VALVES
- Connect a multimeter to a B+ point (R334) and set to 500Vdc setting.
- If you have a second multimeter, connect it to a V_Bias point (R332) and set it to 200Vdc.
- Switch the amplifier on and closely monitor the reading(s) - B+ should be ~430Vdc, V_Bias should be ~125V.
- If so, switch off, unplug and watch the reading(s). B+ should decrease slowly to zero over a few minutes. V_Bias should decrease faster.
- **If neither of these things happen, you have a problem... Stop, unplug everything and get help.**

### Step 2

- Install the valves.
- It's best to have two or three multimeters for this bit. And even better if you have leads with little hooks on the end.
- Hook a multimeter to R334 for B+ and to R332 for the bias voltage.
- Plug the power cable in and switch on and let things settle for 30 secs or so.
- Watch the multimeters - you should read ~375V and ~-125V
- If so, power off.

### Step 3

- Move the multimeters to the bias test points (TP303 & TP304) for the power valves of channel one.
- Switch on, let things warm up and then adjust the trim pots to read 0.4V on each multimeter (change the range if needed).
- Once thats done, **KEEPING ONE HAND IN YOUR POCKET**, move the probes to the other channel (TP403 & TP404) and do the same.
- It will take a few goes going back and forth to get both sides to match.

### Step 4

- **KEEPING ONE HAND IN YOUR POCKET** move the probes of one multimeter to the driver stage, one on TP301 and one on TP302.
- You want to adjust the balance to read zero volts (or as close as you can get - it tends to move around).
- Do this for the other channel.

### Step 5

- Go back and repeat Step 3.

### Step 6

Now take a bunch of readings to make sure everything works and sounds as it should. Use the schematic to work out where these points are on the PCB. Compare with the readings I've made. There will be variations due to component tolerances and line voltage variation. +/-10% should be fine.

#### OVERALL

Voltages:

- Measure V_Bias
- Measure V_Driver
- Measure BPlusin
- Measure V_elevation
- Optional using scope: Measure ripple on B+ (100x probes!)
- Optional using scope: Measure ripple on V_Bias

Hum:

- Balance heaters using scope

#### CHANNEL 1

Voltages:

- Measure V_neg
- Measure V_pos
- Measure B+out

Currents:

- A Measure drop across R334 - divide 10x1000
- B Measure drop across R333 - divide by 270*1000
- C Measure drop across R332 - divide by 270*1000
- D Measure drop across R321 - divide by 390*1000
- E Measure drop across R322 - divide by 390*1000
- F Measure drop across R308 - divide by 220
- G Measure drop across R309 - divide by 220
- H Measure drop across R305 - divide by 47
- Make F+G = 1.5mA by adjusting RV301
- D & E should = 1.7mA
- H should = V_neg/47k

#### CHANNEL 2

Repeat CHANNEL 1
