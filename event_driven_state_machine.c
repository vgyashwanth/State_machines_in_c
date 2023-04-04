#include"stdio.h"
// design a event driven state machine using array data structure
typedef enum{
  idle_state,
  card_inserted,
  pin_entered,
  option_selected,
  money_entered,
  last_state

}state;//state of the machine
typedef enum{
  insert_card_event,
  enter_the_pin_event,
  select_the_option_event,
  enter_the_money_event,
  money_dispateched_event,
  last_event
}event;// input event
typedef state (*event_handler)(void);  // typdef function
// function handlers
state idle(void){
  return card_inserted;
}   
state card(void){
  return pin_entered;
}
state pin(void){
  return option_selected;
}
state option(void){
  return money_entered;
}
state money(void){
  return idle_state;
}
// creating the state box
typedef struct{
  state present_state;
  event_handler next_state_handler;
  event requried_event;

}state_box;
// used for storing the all states events and their next_state_handlers
static state_box look_up[]={
  {idle_state,idle,insert_card_event},
  {card_inserted,card,enter_the_pin_event},
  {pin_entered,pin,select_the_option_event},
  {option_selected,option,enter_the_money_event},
  {money_entered,money,money_dispateched_event}
};
int main(){
  
  state present_state=idle_state; // loading with initial state
  event input; // for takeing the event
  while(1){ //running continously
    printf("enter the event: ");
    scanf("%d",&input);
    // checking in the state box
    if(present_state<last_state && input < last_event 
    && (look_up[present_state].requried_event==input) 
    && look_up[present_state].next_state_handler() >= 0 ){
    present_state=look_up[present_state].next_state_handler();
      printf("reached to next state\n");
    }
    else
    printf("invalid event\n");
  }



  return 0;
}
