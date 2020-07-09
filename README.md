# Security-System-Arduino
Here's my basic Arduino Security system that I have been working on. In order to access the system the user must enter their correct password, currently the security system can store multiple passwords for different users. For detecting motion the system uses a PIR Sensor, once triggered, the system signals an alarm using the Piezo Buzzer. The user will be prompted to enter in their password in order to deactivate the alarm for a maximum of three entries. If the user falsey enters in the password more than three times, the security system will enter Alert mode. Once accessed, the user will be taken to the security systems menu screen where they can change their password or activate the alarm.

##Setup

###Materials

Cost   | Name |                                                                           
------ | ---- |                                                                           
$12.99 | [Arduino Uno](https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU/ref=sr_1_4?dchild=1&keywords=Arduino+Uno&qid=1594317504&sr=8-4)|
$8.99  | [16x2 LCD Display](https://www.amazon.com/SunFounder-Serial-Module-Display-Arduino/dp/B019K5X53O/ref=sr_1_1_sspa?crid=1HODKVF3IYEVX&dchild=1&keywords=16x2+lcd+display+arduino&qid=1594317561&refinements=p_72%3A2661618011&rnid=2661617011&sprefix=16x2+l%2Caps%2C189&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExVTZLMERMM1FBMFNSJmVuY3J5cHRlZElkPUEwNTk5NDUyMjRFM01BWEJPRzkmZW5jcnlwdGVkQWRJZD1BMDY4NTQ2NTNIU0w1Uk1YWUJTVEMmd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl)|
$8.99  | [Real Time Clock (RTC) Module](https://www.amazon.com/Diymore-AT24C32-Arduino-Without-Battery/dp/B01IXXACD0/ref=sr_1_7_sspa?crid=2JCC12MQ4WGO&dchild=1&keywords=real+time+clock+arduino&qid=1594317754&sprefix=real+time+clock+arduino%2Caps%2C254&sr=8-7-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyQ0RWMUs3MUtFMFNWJmVuY3J5cHRlZElkPUEwMjIxNTI4MzJPOTJLWDlLWEkxRiZlbmNyeXB0ZWRBZElkPUEwODQwMjI5UDVINkpNTUZCNlFVJndpZGdldE5hbWU9c3BfbXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)|
6.28   | [Piezo Buzzer](https://www.amazon.com/Gikfun-Terminals-Passive-Electronic-Arduino/dp/B01GJLE5BS/ref=sr_1_2_sspa?dchild=1&keywords=Piezo+buzzer+arduino&qid=1594317911&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzRlJUMTBFNFZWWEM3JmVuY3J5cHRlZElkPUEwMTY0OTkxMTdFN1RYUFhINk1SRSZlbmNyeXB0ZWRBZElkPUEwMTgyMDYzUTNBNzg1OVhJT01EJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)|
6.99   | [10k Potentiometer](https://www.amazon.com/MCIGICM-Breadboard-Trim-Potentiometer-Arduino/dp/B07S69443J/ref=sr_1_9?dchild=1&keywords=potentiometer+10k&qid=1594318059&sr=8-9)|
--     | [2x 330ohm Resistors ](https://www.amazon.com/AUSTOR-Resistors-Assortment-Resistor-Experiments/dp/B07BKRS4QZ/ref=sr_1_4?dchild=1&keywords=Resistors&qid=1594318231&sr=8-4)





Total  | $36.97|



