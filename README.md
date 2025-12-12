# Spacey
A fully open-source space mouse! The current space mouse costs around $350 USD, so being able to build it for ~$75 USD is a HUGE reduction is cost for the same features (minus the screen). It has 10 hotkeyabled buttons, LEDs, a magnetometor for the space mouse part of it, and an amazingly designed CAD!

There are 2 main parts to this space mouse, the CAD + PCB for the keyboard, and the few parts for the space mouse part of it. Some photos of the CAD can be seen below, and can be viewed [here](https://cad.onshape.com/documents/f05fe75dfc18f89f5fcec945/w/6a3c1056693be4c34d9f2601/e/94b3cceea32ed90fe954c1a2). The PCB controls all the hotkeys, and the Xiao + magnetometor controls the actual space mouse ascpect. The space mouse part was partially taken from a tutorial though this was fully expanded to support hotkeys to act like the real and production-wise space mouse. Since the tutorial only convered those few main parts, all of the PCB + CAD shown below was all designed by myself.

## Photos

<img width="826" height="633" alt="Screenshot 2025-12-12 at 1 01 20 PM" src="https://github.com/user-attachments/assets/ffcf5020-002b-46f0-a8ed-bddb9ca7e07a" />

<img width="1200" height="222" alt="image" src="https://github.com/user-attachments/assets/32eff032-1e1c-4419-9f0c-61a2e30d8a16" />

<img width="606" height="534" alt="Screenshot 2025-12-12 at 12 20 18 AM" src="https://github.com/user-attachments/assets/43ae6ea1-84bb-4bdb-b117-db0437597c2c" />

<img width="890" height="680" alt="Screenshot 2025-12-12 at 12 20 33 AM" src="https://github.com/user-attachments/assets/59ec0e1c-3baf-481e-90be-73bfa46b3161" />

## BOM

## Full Total: $77.47 USD

## Parts for the Keyboard Part of it
| Item                 | Description              | Quantity | Unit Price ($) | Total Price ($) | URL                                                                                                             | Running Total ($ with Tax) |
|----------------------|-------------------------|----------|----------------|----------------|-----------------------------------------------------------------------------------------------------------------|---------------------------|
| PCB                  | My PCB                  | x5       | $23.08         | $3.08          | [Link](https://jlcpcb.com)                                                                                      | $3.08                     |
| Case                 | 3D Printed              | 1        | Free           | Free           | N/A                                                                                                             | $0                        |
| XIAO-nRF52840        | MCU                     | 1        | $11.63         | $19.62         | [Link](https://ca.robotshop.com/fr/products/seeedstudioxiaonrf52840-fr?srsltid=AfmBOopHbke249HRHFvztYqPt2fS6K0UxMoKPbETLySdByMfJnvjifeVefc) | $19.62                     |
| Buttons + LEDs + Screw Terminal       | LCSC Parts for the PCB      | 15        | $20          | $20          | [Link](https://lcsc.com)                  | $20                       |
## Total with shipping + tax (USD): $42.7

## Parts for the space mouse part of it
| Item                 | Description              | Quantity | Unit Price ($) | Total Price ($) | URL                                                                                                             | Running Total ($ with Tax) |
|----------------------|-------------------------|----------|----------------|----------------|-----------------------------------------------------------------------------------------------------------------|---------------------------|
| Adafruit QT Py RP2040     | MCU                     | 1        | $9.95          | $9.95          | [Link](https://www.adafruit.com/product/4900) | N/A       |
| STEMMA QT / Qwiic JST SH 4-pin Cable - 50mm Long   | JST Cable | 1     | $0.95          | $0.95          | [Link](https://www.adafruit.com/product/4210)                                            | N/A                     |
| Adafruit TLV493D      | The main chip for the mouse- the magnetometer                    | 1        | $5.95           | $5.95           | [Link](https://www.adafruit.com/product/4366)                                                  | N/A                      |
| Magnets      | For the magnetometer                    | 1        | Free           | Free           | N/A                                                 | N/A                      |
## Total with shipping + tax (USD): $34.77
