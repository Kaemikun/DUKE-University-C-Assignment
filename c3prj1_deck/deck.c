/*#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){

}

int deck_contains(deck_t * d, card_t c) {
  return 0;
}

void shuffle(deck_t * d){

}

void assert_full_deck(deck_t * d) {

}
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
/*
int isEqualCard(card_t c1, card_t c2) {
  if (c1.suit == c2.suit && c1.value == c2.value) {
    return 1;
  }
  return 0;
}

void print_hand(deck_t * hand){
  for (int i=0; i < hand->n_cards; i++) {
    print_card(*((hand->cards)[i]));
    printf("%c", ' ');
  }
}

int deck_contains(deck_t * d, card_t c) {
  for (int i=0; i < d->n_cards; i++) {
    if ((isEqualCard(c, *((d->cards)[i]))) == 1) {
      return 1;
    }

  }
  return 0;
}

void shuffle(deck_t * d){
  int remain = d->n_cards;
  int limit = d->n_cards - 1;
  for (int i=0; i < limit; i++) {
    // should not need to use the srand() function
    int idx = rand() % remain + i;
    // swap idx's deck_t and i's deck_t
    card_t * tmp = (d->cards)[i];
    (d->cards)[i] = (d->cards)[idx];
    (d->cards)[idx] = tmp;
    remain--;
  }
}

void assert_full_deck(deck_t * d) {
  for (int i=0; i < d->n_cards; i++) {
    assert_card_valid(*((d->cards)[i]));
    for (int j=0; j < d->n_cards; j++) {
      if (i == j) {
        continue;
      }
      assert(!(isEqualCard(*((d->cards)[i]), *((d->cards)[j]))));
    }
  }
}
*/
/*void add_card_to(deck_t * deck, card_t c) {
  card_t *card = malloc(sizeof(*card));
  card->value = c.value;
  card->suit = c.suit;
  deck->cards = realloc(deck->cards, (deck->n_cards + 1)*sizeof(*(deck->cards)));
  deck->cards[deck->n_cards] = card;
  deck->n_cards++;
}

card_t * add_empty_card(deck_t * deck) {
  card_t c = {.value=0,.suit=0};
  add_card_to(deck, c);
  return deck->cards[deck->n_cards-1];
}
*/
/*deck_t * make_deck_exclude(deck_t * excluded_cards) {
  deck_t *ans = malloc(sizeof(*ans));
  ans->cards = NULL;
  ans->n_cards = 0;
  for (int i=0; i < 52; i++) {
    card_t c = card_from_num(i);
    if (deck_contains(excluded_cards, c)) {
      continue;
    }
    add_card_to(ans, c);
  }
  return ans;
}
*/
/*deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t *exclu = malloc(sizeof(*exclu));
  exclu->cards = NULL;
  exclu->n_cards = 0;
  for (int i=0; i < n_hands; i++) {
    card_t **cards = hands[i]->cards;
    size_t len = hands[i]->n_cards;
    for (int j=0; j < len; j++) {
      add_card_to(exclu, *cards[j]);
    }
  }
  deck_t *ans = make_deck_exclude(exclu);
  free(exclu);  // Observe
  return ans;
}
*/
/*void free_deck(deck_t * deck) {
  if (deck == NULL) {  // avoid subsequent NULL pointer exception
    return ;
  }
  for (int i=0, l=deck->n_cards; i < l; i++) {
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void add_card_to(deck_t * deck, card_t c){
  // create a card and assign c value+suit to it
   card_t * card = malloc(sizeof(* card));
  card->value = c.value;
  card->suit = c.suit;

  // increase size of deck
  deck->n_cards++;
  size_t num=deck->n_cards;
  deck->cards = realloc(deck->cards, num*sizeof(deck->cards));
  deck->cards[num-1]=card;
}

card_t * add_empty_card(deck_t * deck){
  card_t * card = malloc(sizeof(* card));
  card->value = 0;
  card->suit = 0;

  deck->n_cards++;
  size_t num=deck->n_cards;
  deck->cards = realloc(deck->cards, num*sizeof(deck->cards));
  deck->cards[num-1]=card;
  return card;
}

deck_t * make_deck_exclude(deck_t * excluded_cards){
  deck_t * deck=malloc(sizeof(* deck));
  deck->cards=NULL;
  deck->n_cards=0;
  for(unsigned i=0; i<52; i++){
    card_t card = card_from_num(i);


    //Don't add to deck if it is one of the excluded
    if (deck_contains(excluded_cards,card)==0){
      add_card_to(deck, card);
    }
  }


  return deck;

}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){

  deck_t *deck = malloc(sizeof(*deck));
  deck->n_cards = 0;
  deck->cards = NULL;

  deck_t *hand;
  card_t *card;

  // get each hand sent to the function
  for (size_t i = 0; i < n_hands; i++) {
    hand = hands[i];


    for (size_t j = 0; j < hand->n_cards; j++) {
      card = hand->cards[j];
      if (card->value!=0){

      if (!deck_contains(deck, * card)) {
  	  add_card_to(deck,* card);
  	}
      }
    }
  }
  deck_t * deck_ans;
  deck_ans = make_deck_exclude(deck);
  free_deck(deck);
  return deck_ans;


}

void free_deck(deck_t * deck){
  for (int i=0; i<deck->n_cards; i++){
    free(deck->cards[i]);
  }

  free(deck->cards);
  free(deck);

}


int deck_contains(deck_t * d, card_t c){

  for (size_t i=0; i<(d->n_cards); i++) {
    if (((d->cards[i]->value) == c.value) && ((d->cards[i]->suit)==c.suit)) {
      //  printf("contained in deck");
      return 1;
    }
  }
  return 0;
}

void print_hand(deck_t * hand){
  for (size_t i=0; i<(hand->n_cards); i++) {
    print_card(*(hand->cards[i]));
    printf(" ");
  }

  // for (size_t i=0; i< n_cards; i++){
  //print_card(*(hand).card_t[i]);
  //printf(" ");
  //}
}

void shuffle(deck_t * d){
  size_t max_rand=d->n_cards;
  card_t swap_card;
  size_t num;
  size_t num2;
  for (size_t i=0; i<max_rand; i++){
    num=rand()%max_rand;
    num2=rand()%max_rand;
    //   while (num>max_rand){
    //num/=2;
    //}
    // printf("num =%zu ", num);
    swap_card.value=d->cards[num]->value;
    swap_card.suit=d->cards[num]->suit;
    d->cards[num]->value=d->cards[num2]->value;
    d->cards[num]->suit=d->cards[num2]->suit;
    d->cards[num2]->value=swap_card.value;
    d->cards[num2]->suit=swap_card.suit;
  }


}

void assert_full_deck(deck_t * d) {
  // printf("running assert_full_deck");
  assert(d->n_cards == 52);
  for (size_t i=0; i < d->n_cards; i++){
    assert_card_valid(*(d->cards[i]));
    assert(deck_contains(d, card_from_num(i))==1);
  }

}
