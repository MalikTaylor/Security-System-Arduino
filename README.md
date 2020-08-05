# Security-System-Arduino
 
<p align="center">
  <img width="450" height="300" src="https://github.com/MalikTaylor/Security-System-Arduino/blob/master/Images/Secuirty%20System%207-26-2020.JPG">
</p>

### About
This project is a basic security system powered by the Arduino Uno. To access the system the user must enter their correct password. Once accessed, the user can activate the system's alarm, change their password, or configure the system's settings. In order to detect motion the system uses a PIR sensor, if the system is armed and the PIR sensor is triggered, the system signals an alarm using a Piezo Buzzer. The user will then be prompted to enter their password to deactivate the alarm. If the user falsely enters in the password more than three times, the security system will enter a lock-down state.

## Setup

### Materials

Cost   | Name |                                                                           
------ | ---- |                                                                           
$12.99 | [Arduino Uno](https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU/ref=sr_1_4?dchild=1&keywords=Arduino+Uno&qid=1594317504&sr=8-4)|
$8.99  | [16x2 LCD Display](https://www.amazon.com/SunFounder-Serial-Module-Display-Arduino/dp/B019K5X53O/ref=sr_1_1_sspa?crid=1HODKVF3IYEVX&dchild=1&keywords=16x2+lcd+display+arduino&qid=1594317561&refinements=p_72%3A2661618011&rnid=2661617011&sprefix=16x2+l%2Caps%2C189&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExVTZLMERMM1FBMFNSJmVuY3J5cHRlZElkPUEwNTk5NDUyMjRFM01BWEJPRzkmZW5jcnlwdGVkQWRJZD1BMDY4NTQ2NTNIU0w1Uk1YWUJTVEMmd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl)|
$5.99  | [I2C Adapter](https://www.amazon.com/gp/product/B00VC2NEU8/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)|
$8.99  | [Real Time Clock (RTC) Module](https://www.amazon.com/Diymore-AT24C32-Arduino-Without-Battery/dp/B01IXXACD0/ref=sr_1_7_sspa?crid=2JCC12MQ4WGO&dchild=1&keywords=real+time+clock+arduino&qid=1594317754&sprefix=real+time+clock+arduino%2Caps%2C254&sr=8-7-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyQ0RWMUs3MUtFMFNWJmVuY3J5cHRlZElkPUEwMjIxNTI4MzJPOTJLWDlLWEkxRiZlbmNyeXB0ZWRBZElkPUEwODQwMjI5UDVINkpNTUZCNlFVJndpZGdldE5hbWU9c3BfbXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)|
$6.28   | [Piezo Buzzer](https://www.amazon.com/Gikfun-Terminals-Passive-Electronic-Arduino/dp/B01GJLE5BS/ref=sr_1_2_sspa?dchild=1&keywords=Piezo+buzzer+arduino&qid=1594317911&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzRlJUMTBFNFZWWEM3JmVuY3J5cHRlZElkPUEwMTY0OTkxMTdFN1RYUFhINk1SRSZlbmNyeXB0ZWRBZElkPUEwMTgyMDYzUTNBNzg1OVhJT01EJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)|
$8.99   | [Button Keypad](https://www.amazon.com/gp/product/B07B4DR5SH/ref=ppx_yo_dt_b_asin_title_o02_s02?ie=UTF8&psc=1)|
---    | [2x 330ohm Resistors ](https://www.amazon.com/AUSTOR-Resistors-Assortment-Resistor-Experiments/dp/B07BKRS4QZ/ref=sr_1_4?dchild=1&keywords=Resistors&qid=1594318231&sr=8-4)|
---    | [2x LED ](https://www.amazon.com/eBoot-Pieces-Emitting-Diodes-Assorted/dp/B06XPV4CSH/ref=sr_1_4?crid=3HCMV47TVPSM5&dchild=1&keywords=led+diodes&qid=1596075010&sprefix=led+dio%2Caps%2C178&sr=8-4)
Total  | $52.23|

### Schematic

<p align="center">
 <img width="600" height="500" src="https://github.com/MalikTaylor/Security-System-Arduino/blob/master/Schematic/Schematic.png">
</p>

<br>
<a href="https://personal-website-c1fb5.web.app/">Website</a>
 - <a href="https://www.instagram.com/__maliktaylor/">Instagram</a>
 - <a href="https://www.youtube.com/channel/UCZMicsoHBOJebbyCS7dWkTg?">YouTube</a>
 <br>
 <br>

