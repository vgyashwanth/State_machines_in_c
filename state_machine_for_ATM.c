// state machine for ATM
#include"stdio.h"

typedef enum{
    insert_card,
    enter_the_pin,
    select_option,
    enter_amount,
    dispatch_money
}event;
typedef enum{
    idle_state,
    card_inserted_state,
    pin_entered_state,
    option_selected_state,
    amount_entered_state

}state;
event read_event(){
    // mechanism for reading the event
}
event inserted_card_Handler(){
    //work...
    return card_inserted_state;
}
event pin_entered_Handler(){
    //work...
    return pin_entered_state;
}
event Option_selected_Handler(){
    //work...
    return option_selected_state;
}
event Amount_entered_Handler(){
    //work...
    return amount_entered_state;
}
event money_Dispatched_Handler(){
    //work...
    return idle_state;
}
int main(){
   state curr_state = idle_state;
    while(1){

        event event_triggered = read_event();
        switch(curr_state){
            case idle_state:
                    if(event_triggered == insert_card)
                    curr_state  = inserted_card_Handler();
                    break;
            case card_inserted_state:
                    if(event_triggered == enter_the_pin)
                    curr_state = pin_entered_Handler();
                    break;
            case pin_entered_state:
                    if(event_triggered == select_option)
                    curr_state = Option_selected_Handler();
                    break;
            case option_selected_state:
                    if(event_triggered == enter_amount)
                    curr_state = Amount_entered_Handler();
                    break;
            case amount_entered_state:
                    if(event_triggered == dispatch_money)        
                    curr_state = money_Dispatched_Handler();
                    break;

        }




    }

    return 0;
}
