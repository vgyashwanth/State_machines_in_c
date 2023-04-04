#include <stdio.h> 
void delay_handler(int x);// used for generating the delay 
typedef enum{ // assigning values to the states 
green_state, 
yellow_state, 
red_state 
}state; 
 
state read_initial_state(void); 
 
int main() 
{ 
state current_state = read_initial_state(); // loading the initial state 
 
while(1){ 
 
switch(current_state){ // monitoring the state 
 
case green_state: 
{ 
delay_handler(360); // waiting for 360 sec 
current_state=yellow_state; // updating the state 
break; 
 
} 
 
case yellow_state: 
{ 
delay_handler(10); // waiting for 10 sec 
current_state=red_state; 
break; 
 
} 
 
case red_state: 
{ 
delay_handler(120); // waiting for 120 sec 
current_state=green_state; 
break; 
} 
 
} 
 
 
} 
 
return 0; 
} 
void delay_handler(int x){ 
//delay generating using timers 
} 
 
state read_initial_state(void){ 
state initial_state; 
// logic for finding initial state 
return initial_state; 
 
}
