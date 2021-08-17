# Turn on and off a LED with a switch

The code is simple: 
- If the input pin (in this case PIND register's 7th bit) is clear, the switch is pressed. Then the output pin PB0 is set high.
- If the input pin is set, the switch isn't pressed. Then the output pin is set low. 
