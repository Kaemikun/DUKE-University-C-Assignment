

/*#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

*/
/*void assert_card_valid(card_t c) {
  assert(c.value>=2);
  assert(c.value<=VALUE_ACE);
  assert(c.suit>= SPADES);
  assert(c.suit<= CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r)
    {
    case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; break;
    case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; break;
    case FULL_HOUSE: return "FULL_HOUSE"; break;
    case FLUSH: return "FLUSH"; break;
    case STRAIGHT: return "STRAIGHT"; break;
    case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; break;
    case TWO_PAIR: return "TWO_PAIR"; break;
    case PAIR: return "PAIR"; break;
    case NOTHING: return "NOTHING"; break;
    }
  return "";
}

char value_letter(card_t c) {

  if(c.value>= 2 && c.value<=9)
    return(c.value+ '0');
  else
    switch(c.value)
      {
      case 10: return '0'; break;
      case VALUE_JACK: return 'J'; break;
      case VALUE_QUEEN: return 'Q'; break;
      case VALUE_KING: return 'K'; break;
      case VALUE_ACE: return 'A'; break;
      }
  return 'x';
}


char suit_letter(card_t c) {

  switch(c.suit)
    {
    case SPADES: return 's'; break;
    case DIAMONDS: return 'd'; break;
    case HEARTS: return 'h'; break;
    case CLUBS: return 'c'; break;
    case NUM_SUITS: return '0'+ 4; break;
    }
  return 'x';

}

void print_card(card_t c) {
  char a= value_letter(c);
  char b= suit_letter(c);
  printf("%c%c ", a,b);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let)
    {
    case '2': temp.value= 2; break;
    case '3': temp.value= 3; break;
    case '4': temp.value= 4; break;
    case '5': temp.value= 5; break;
    case '6': temp.value= 6; break;
    case '7': temp.value= 7; break;
    case '8': temp.value= 8; break;
    case '9': temp.value= 9; break;
    case '0': temp.value= 10; break;
    case 'J': temp.value= VALUE_JACK; break;
    case 'Q': temp.value= VALUE_QUEEN; break;
    case 'K': temp.value= VALUE_KING; break;
    case 'A': temp.value= VALUE_ACE; break;
    }
  switch(suit_let)
    {
    case 's': temp.suit= SPADES; break;
    case 'd': temp.suit= DIAMONDS; break;
    case 'h': temp.suit= HEARTS; break;
    case 'c': temp.suit= CLUBS; break;
    }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  switch(c/13)
    {
    case 0: temp.suit= SPADES; break;
    case 1: temp.suit= DIAMONDS; break;
    case 2: temp.suit= HEARTS; break;
    case 3: temp.suit= CLUBS; break;
    }
  switch(c%13){
  case 0: temp.value= 2; break;
  case 1: temp.value= 3; break;
  case 2: temp.value= 4; break;
  case 3: temp.value= 5; break;
  case 4: temp.value= 6; break;
  case 5: temp.value= 7; break;
  case 6: temp.value= 8; break;
  case 7: temp.value= 9; break;
  case 8: temp.value= 10; break;
  case 9: temp.value= VALUE_JACK; break;
  case 10: temp.value= VALUE_QUEEN; break;
  case 11: temp.value= VALUE_KING; break;
  case 12: temp.value= VALUE_ACE; break;
  }
  return temp;
}
*/
/*void assert_card_valid(card_t c) {


}

const char * ranking_to_string(hand_ranking_t r) {
  return "";
}

char value_letter(card_t c) {
  return 'x';
}


char suit_letter(card_t c) {
  return 'x';
  
}

void print_card(card_t c) {

}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  return temp;
}*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

/*
void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);
  return;
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
    case STRAIGHT_FLUSH : return "STRAIGHT_FLUSH"; break;
    case FOUR_OF_A_KIND : return "FOUR_OF_A_KIND"; break;
    case FULL_HOUSE : return "FULL_HOUSE"; break;
    case FLUSH : return "FLUSH"; break;
    case STRAIGHT : return "STRAIGHT"; break;
    case THREE_OF_A_KIND : return "THREE_OF_A_KIND"; break;
    case TWO_PAIR : return "TWO_PAIR"; break;
    case PAIR : return "PAIR"; break;
    case NOTHING: return "NOTHING"; break;
    default : return "???"; break;
  }
}

char value_letter(card_t c) {
  switch(c.value) {
  case 2 : return '2'; break;
  case 3 : return '3'; break;
  case 4 : return '4'; break;
  case 5 : return '5'; break;
  case 6 : return '6'; break;
  case 7 : return '7'; break;
  case 8 : return '8'; break;
  case 9 : return '9'; break;
  case 10 : return '0'; break;
  case VALUE_JACK : return 'J'; break;
  case VALUE_QUEEN : return 'Q'; break;
  case VALUE_KING : return 'K'; break;
  case VALUE_ACE : return 'A'; break;
  default : return '?'; break;
  }
}


char suit_letter(card_t c) {
  switch(c.suit) {
  case SPADES : return 's'; break;
  case HEARTS : return 'h'; break;
  case DIAMONDS : return 'd'; break;
  case CLUBS : return 'c'; break;
  default : return '?'; break;
  }
}

void print_card(card_t c) {
  char val = value_letter(c);
  char suit = suit_letter(c);
  printf("%c%c", val, suit);
  return;
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let) {
  case '2' : temp.value = 2; break;
  case '3' : temp.value = 3; break;
  case '4' : temp.value = 4; break;
  case '5' : temp.value = 5; break;
  case '6' : temp.value = 6; break;
  case '7' : temp.value = 7; break;
  case '8' : temp.value = 8; break;
  case '9' : temp.value = 9; break;
  case '0' : temp.value = 10; break;
  case 'J' : temp.value = VALUE_JACK; break;
  case 'Q' : temp.value = VALUE_QUEEN; break;
  case 'K' : temp.value = VALUE_KING; break;
  case 'A' : temp.value = VALUE_ACE; break;
  }
  switch(suit_let) {
  case 's' : temp.suit = SPADES; break;
  case 'h' : temp.suit = HEARTS; break;
  case 'd' : temp.suit = DIAMONDS; break;
  case 'c' : temp.suit = CLUBS; break;
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = (c / 4) + 2;
  temp.suit = c % 4;
  return temp;
}
*/#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"
//#include "deck.h"

void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value <=VALUE_ACE);
  assert(c.suit>=SPADES && c.suit<=CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  case NOTHING:
    return "NOTHING";
  default:
    return "NO_SUCH_COMBINATION";
  }
  }

char value_letter(card_t c) {
  switch(c.value){
  case 2: return '2';
  case 3: return '3';
  case 4: return '4';
  case 5: return '5';
  case 6: return '6';
  case 7: return '7';
  case 8: return '8';
  case 9: return '9';
  case 10: return '0';
  case VALUE_JACK: return 'J';
  case VALUE_QUEEN: return 'Q';
  case VALUE_KING: return 'K';
  case VALUE_ACE: return 'A';
  default : return '?';
}
}

char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return '?';
  }
}

void print_card(card_t c) {
  char cardval;
  char cardsuit;
    cardval=value_letter(c);
    cardsuit=suit_letter(c);
    printf("%c%c",cardval, cardsuit);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case '2':
    temp.value=2;
    break;
  case '3':
    temp.value=3;
    break;
  case '4':
    temp.value=4;
    break;
  case '5':
    temp.value=5;
    break;
  case '6':
    temp.value=6;
    break;
  case '7':
    temp.value=7;
    break;
  case '8':
    temp.value=8;
    break;
  case '9':
    temp.value=9;
    break;
  case '0':
    temp.value=10;
    break;
  case 'J':
    temp.value=VALUE_JACK;
    break;
  case 'Q':
    temp.value=VALUE_QUEEN;
    break;
  case 'K':
    temp.value=VALUE_KING;
    break;
  case 'A':
    temp.value=VALUE_ACE;
    break;
  }
  switch(suit_let){
  case 's':
    temp.suit=SPADES;
    break;
  case 'h':
    temp.suit=HEARTS;
    break;
  case 'd':
    temp.suit=DIAMONDS;
    break;
  case 'c':
    temp.suit=CLUBS;
    break;
 }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t ret_card;
  int suit=c/13;
  int value=c%13;
  // assign cards to numbers as such: 0-12 are values 2-14 on suit SPADES,
  // 13-25 suit HEARTS
  // 26-38 suit DIAMONDS
  // 39-51 suit CLUBS
  switch(suit){
  case 0:
    ret_card.suit=SPADES;
    break;
  case 1:
    ret_card.suit=HEARTS;
    break;
  case 2:
    ret_card.suit=DIAMONDS;
    break;
  case 3:
    ret_card.suit=CLUBS;
    break;
    
  }

  //
  if (value>=2){
    ret_card.value=value;
  }else{
    ret_card.value=value+13;
  }
  
  return ret_card;
}

/* int main(){ */
/*   printf("Welcome to Poker Calculator\n"); */
/*   card_t c; */
/*   int suitentry; */

/*   printf("insert card value:"); */
  
/*   scanf("%u", &c.value); */
/*   printf("insert card suit:"); */
  
/*   scanf("%d", &suitentry); */


  
/*   c.suit=suitentry; */
 
/*   assert_card_valid(c); */
/*   print_card(c); */
/*   return EXIT_SUCCESS; */
/* } */
