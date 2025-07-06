# Project 5 - Reacting to input part I: Interrupts

1. Make led light on button press
2. Learn how to debug code by establish communication with the computer using the Serial library
3. Understand the difference between polling and interrupt and benefits of using interrupts over polling
4. Learn how to use interrupts in Arduino

## Light led on button press (arduino code)
 - button pin is 6, grove led pin is 4
 - read value from button pin. If button is pressed (how can you tell?) turn grove led on. If button is not pressed, turn it off
 - test that this works.

## Debug statements
- use the Serial library to add debug statements to your code. View using Serial Monitor in Arduino IDE

## Simulate additional long process
- We wish to simulate a long process that happens in the loop. In your lab, this could be a calculation, data acquisition, etc. In order to simulate this, add to your loop the following code:

```
for (int i = 0; i< 10000; i++){
    Serial.println("calculating...");
}
```
- test if lighting led still works. Why or why not?
answer here: __________

## Use interrupt to light led
- Add code to create an interrupt pin (why can't it be the button pin?). Use a variable for this.
- Short the interrupt pin with the button pin
- test. Does it work?

## Exercises
 - commit and upload your code in this project folder.

