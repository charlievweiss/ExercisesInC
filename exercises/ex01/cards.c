/*
Program to evaluate face values.
Adapted from Head First C by Charlie Weiss
*/

#include <stdio.h>
#include <stdlib.h>

/*
    Assigns value of 10 to J, Q, K and 11 to A. 
    Otherwise, takes card number as its value (unless larger than 10.
    which is an invalid card name)
*/
int get_card_value(char card_name[3]){
    
    int val = 0;
    switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        default:
            val = atoi(card_name);
            if ((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
                val = 0;
            }
    }
    return val;
}

/* 
Decides whether to increase or decrease card count based on card
value. Otherwise, keeps card count the same.
*/
int get_addition_value(int card_value){

    int add_val = 0;
    if ((card_value > 2) && (card_value < 7)) {
            add_val = 1;
        } else if (card_value == 10) {
            add_val = -1;
        }
    return add_val;
}

/*
Prompts for terminal input of card name and changes card count
based on the value of the input.
*/
int main(){
    char card_name[3];
    int count = 0;
    int card_value = 0;
    int add_value = 0;
    do {
        puts("Enter the card_name: ");
        scanf("%2s", card_name);
        if (card_name[0] == 'X'){
            continue;
        }

        /* Get value of card */
        card_value = get_card_value(card_name);
        if (card_value < 1){
            continue; /* card wasn't valid */
        }

        /* get add value of card */
        add_value = get_addition_value(card_value);
        count += add_value;
        
        printf("Current count: %i\n", count);
    } while (card_name[0] != 'X');
    return 0;
}