#include <stdio.h>
//Different state of ATM machine
typedef enum
{
    Idle_State, 
    Card_Inserted_State,
    Pin_Eentered_State,
    Option_Selected_State,
    Amount_Entered_State,
    last_State // edge case for bound checking
} SystemState;
//Different type events
typedef enum
{
    Card_Insert_Event,
    Pin_Enter_Event,
    Option_Selection_Event,
    Amount_Enter_Event,
    Amount_Dispatch_Event,
    last_Event //edge case for bound checking
} SystemEvent;
//typedef of function pointer
typedef SystemState (*EventHandler)(void);
//structure of one stateblock with all requried information to check for state transistion
typedef struct
{
    SystemState present_state;
    SystemEvent event_requried_for_transistion;
    EventHandler Handler_requried_for_transistion;
} System_block;
//function call to dispatch the amount and return the ideal state
int read_event(){
    int a;
    printf("ENTER THE NEXT STATE: ");
    scanf("%d",&a);
    return a;
}
SystemState AmountDispatchHandler(void)
{
    return Idle_State;
}
//function call to Enter amount and return amount entered state
SystemState EnterAmountHandler(void)
{
    return Amount_Entered_State;
}
//function call to option select and return the option selected state
SystemState OptionSelectionHandler(void)
{
    return Option_Selected_State;
}
//function call to enter the pin and return pin entered state
SystemState EnterPinHandler(void)
{
    return Pin_Eentered_State;
}
//function call to processing track data and return card inserted state
SystemState InsertCardHandler(void)
{
    return Card_Inserted_State;
}
//Initialize array of structure with states and event with proper handler
System_block StateMachine [] =
{   // group of state machine blocks
    {Idle_State,Card_Insert_Event,InsertCardHandler},
    {Card_Inserted_State,Pin_Enter_Event,EnterPinHandler},
    {Pin_Eentered_State,Option_Selection_Event,OptionSelectionHandler},
    {Option_Selected_State,Amount_Enter_Event,EnterAmountHandler},
    {Amount_Entered_State,Amount_Dispatch_Event,AmountDispatchHandler}
};
//main function
int main(int argc, char *argv[])
{
    SystemState current_state = Idle_State;
    while(1)
    {       
        //Api read the event
        int triggered_Event = read_event();
        if(triggered_Event<0) // when we want to exit from while(1) loop
        break;
        //condition need to check for state transistion
        if((current_state < last_State) && (triggered_Event < last_Event)&& (StateMachine[current_state].event_requried_for_transistion ==triggered_Event) && (StateMachine[current_state].Handler_requried_for_transistion != NULL))
        {
            // function call as per the state and event and return the next state of the finite state machine
            current_state = (StateMachine[current_state].Handler_requried_for_transistion());
            printf("SUCESSFULLY CHANGED TRANSISTION TO: %d\n",current_state);
        }
        else
        {
            printf("INVALID STATE\n!! PLEASE ENTER VALID STATE !!\n");
        }
    }
    printf("EXIT\n");
    return 0;
}
 
