/*#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int card_ptr_comp(const void * vp1, const void * vp2) {
  return 0;
}

suit_t flush_suit(deck_t * hand) {
  return NUM_SUITS;
}

unsigned get_largest_element(unsigned * arr, size_t n) {
  return 0;
}

size_t get_match_index(unsigned * match_counts, size_t n,unsigned n_of_akind){

  return 0;
}
ssize_t  find_secondary_pair(deck_t * hand,
			     unsigned * match_counts,
			     size_t match_idx) {
  return -1;
}

int is_straight_at(deck_t * hand, size_t index, suit_t fs) {
  return 0;
}

hand_eval_t build_hand_from_match(deck_t * hand,
				  unsigned n,
				  hand_ranking_t what,
				  size_t idx) {

  hand_eval_t ans;
  return ans;
}


int compare_hands(deck_t * hand1, deck_t * hand2) {

  return 0;
}



//You will write this function in Course 4.
//For now, we leave a prototype (and provide our
//implementation in eval-c4.o) so that the
//other functions we have provided can make
//use of get_match_counts.
unsigned * get_match_counts(deck_t * hand) ;

// We provide the below functions.  You do NOT need to modify them
// In fact, you should not modify them!


//This function copies a straight starting at index "ind" from deck "from".
//This copies "count" cards (typically 5).
//into the card array "to"
//if "fs" is NUM_SUITS, then suits are ignored.
//if "fs" is any other value, a straight flush (of that suit) is copied.
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if (from->cards[ind]->value == nextv &&
	(fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
  }
}


//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)
// in "hand".  It calls the student's is_straight_at for each possible
// index to do the work of detecting the straight.
// If one is found, copy_straight is used to copy the cards into
// "ans".
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    if (x != 0){
      if (x < 0) { //ace low straight
	assert(hand->cards[i]->value == VALUE_ACE &&
	       (fs == NUM_SUITS || hand->cards[i]->suit == fs));
	ans->cards[4] = hand->cards[i];
	size_t cpind = i+1;
	while(hand->cards[cpind]->value != 5 ||
	      !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
	  cpind++;
	  assert(cpind < hand->n_cards);
	}
	copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
	copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.
//This function is longer than we generally like to make functions,
//and is thus not so great for readability :(
hand_eval_t evaluate_hand(deck_t * hand) {
  suit_t fs = flush_suit(hand);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    if(find_straight(hand, fs, &ans)) {
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  unsigned * match_counts = get_match_counts(hand);
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  if (n_of_a_kind == 4) { //4 of a kind
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
	ans.cards[copy_idx] = hand->cards[i];
	copy_idx++;
	if (copy_idx >=5){
	  break;
	}
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01
      //if other_pair_idx > 2, then, e.g. A A K Q Q
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q
      ans.cards[4] = hand->cards[4];
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}*/
#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
/*
int card_ptr_comp(const void * vp1, const void * vp2) {
  const card_t * const * cp1 = vp1;
  const card_t * const * cp2 = vp2;
  unsigned v1 = (*cp1)->value;
  unsigned v2 = (*cp2)->value;
  if (v1 < v2) {
    return 1;
  } else if (v1 > v2) {
    return -1;
  }
  if ((*cp1)->suit < (*cp2)->suit) {
    return 1;
  }
  return -1;
}

suit_t flush_suit(deck_t * hand) {
  card_t** card= hand -> cards;
  card_t card1;
  card1 = **(card +0);
  int s,h,d,c;
  s=h=d=c=0;

  for (size_t i=0 ;i< (hand ->n_cards);i++){
    card1 = **(card +i);
    switch(card1.suit){
      case SPADES : {s++;  break;}
      case HEARTS : { h++;  break;}
      case DIAMONDS :{ d++ ;  break;}
      case CLUBS :{c++ ; break;}
      case NUM_SUITS: break;
    }
  }

  if (s >= 5) return SPADES;
  if (h >= 5) return HEARTS;
  if (d >= 5) return DIAMONDS;
  if (c >= 5) return CLUBS;
  return NUM_SUITS;

}

unsigned get_largest_element(unsigned * arr, size_t n) {
  unsigned ans= arr[0];
  for (size_t i=1 ; i<n ;i++ ){
    if (arr[i] > ans) ans=arr[i];
  }
  return ans;
}

size_t get_match_index(unsigned * match_counts, size_t n,unsigned n_of_akind){
  for (int i=0; i < n; i++) {
    if (match_counts[i] == n_of_akind) {
      return i;
    }
  }
  return 0;
}

ssize_t  find_secondary_pair(deck_t * hand,
			     unsigned * match_counts,
			     size_t match_idx) {
  card_t** card = hand -> cards;
  card_t card1,card2;
  card2 = **(card + match_idx);
  card1=**(card+0);
    for (size_t i=0 ;i< (hand ->n_cards);i++){
      card1=**(card+i);
      if ((match_counts[i] > 1)&&(card1.value != card2.value)) return i;
    }

  return -1;
}

int is_n_length_straight_at(deck_t * hand, size_t index, suit_t fs, int n) {
  card_t ** cards = hand->cards;
  if (fs != NUM_SUITS && fs != cards[index]->suit) {
    return 0;
  }
  int pre = (cards[index]->value) + 1;
  for (int i=index; i < hand->n_cards; i++) {
    int val = cards[i]->value;
    if (pre - 1 == val && (fs == NUM_SUITS || fs == cards[i]->suit)) {
      pre--;
    } else if (pre - val > 1) {
      if (cards[index]->value + 1 - pre >= n) {           // pay attention !!!
        return 1;
      }
      return 0;
    }
  }
  if (cards[index]->value + 1 - pre >= n) {
    return 1;
  }
  return 0;
}

int is_ace_low_straight_at(deck_t * hand, size_t index, suit_t fs) {
  // [index, hand->n_cards) interval must contains 2? 3? 4? 5?
  int isExsit[4] = {0};
  card_t ** cards = hand->cards;
  for (int i=index; i < hand->n_cards; i++) {
    int val = cards[i]->value;
    if (((fs == NUM_SUITS || fs == cards[i]->suit)) && (2 <= val && val <= 5)) {
      isExsit[val-2] = 1;
    }
  }
  return isExsit[0] == 1 && isExsit[1] == 1 && isExsit[2] == 1 && isExsit[3] == 1;
}

int is_straight_at(deck_t * hand, size_t index, suit_t fs) {
  card_t ** cards = hand->cards;
  if (index > hand->n_cards - 5) {
    return 0;
  }
  if (is_n_length_straight_at(hand, index, fs, 5) == 1) {
    return 1;
  }
  if (cards[index]->value == 14 &&
    (fs == NUM_SUITS || fs == cards[index]->suit) &&
    is_ace_low_straight_at(hand, index+1, fs) == 1) {
    return -1;
  }
  return 0;
}

// copy n elements from hand starting from start to cards, exclude all elements at range of hand[x,y)
void copyToCards_n_cards_exclude(deck_t * hand,
          size_t src_start, size_t des_start, unsigned n, card_t ** cards,
          size_t x, size_t y) {         // [x, y) excludisive
    // printf("copyToCards_n_cards_exclude: src_start=%zu, des_start= %zu, n=%d, x=%zu, y=%zu\n", src_start, des_start, n, x, y);
  int cnt = 0;
  for (int i=src_start; i < hand->n_cards; i++) {
    if (x <= i && i < y) {
      continue;
    }
    assert(cnt < 5);
    cards[des_start+cnt] = (hand->cards)[i];
    cnt++;
    if (cnt == n) {
      break;
    }
  }
}

size_t My_find2ndPair(deck_t * hand,
			     size_t pre_match, // 3 or 2
			     size_t match_idx) {

  assert(match_idx < hand->n_cards);
  card_t ** cards = hand->cards;
  int idx = -1;
  int val = -1;
  int cnt = 0;
  for (int i=0; i < hand->n_cards; i++) {
    if (match_idx <= i && i < match_idx + pre_match) {
      continue;
    }
    if (val == cards[i]->value) {
      cnt++;
    } else {
      if (cnt == 2) {
        return idx;
      }
      val = cards[i]->value;
      cnt = 1;
      idx = i;
    }
  }
  if (cnt == 2) {
    return idx;
  }
  return -1;
}

hand_eval_t build_hand_from_match(deck_t * hand,
				  unsigned n,
				  hand_ranking_t what,
				  size_t idx) {
    // printf("build_hand_from_match: n=%d, what=%d\n", n, (int)what);
  size_t p;
  hand_eval_t ans;
  ans.ranking = what;
  if (what == NOTHING) {
    n = 5;
  }
  for (int i=0; i < n; i++) {
    (ans.cards)[i] = (hand->cards)[idx+i];
  }
  // ans.cards = cards;  // array name can't be lvalue
  switch (what)
  {
  case FOUR_OF_A_KIND:
    assert(n == 4);
    copyToCards_n_cards_exclude(hand, 0, n, 1, ans.cards, idx, idx + n);
    break;
  case FULL_HOUSE:
    assert(n == 3);
    p = My_find2ndPair(hand, n, idx);
    assert(0 <= p);
    copyToCards_n_cards_exclude(hand, p, n, 2, ans.cards, 0, hand->n_cards);
    break;
  case THREE_OF_A_KIND:
    assert(n == 3);
    copyToCards_n_cards_exclude(hand, 0, n, 2, ans.cards, idx, idx + n);
    break;
  case TWO_PAIR:
    assert(n == 2);
    p = My_find2ndPair(hand, n, idx);
    assert(p >= 0);
    copyToCards_n_cards_exclude(hand, p, n, 2, ans.cards, 0, hand->n_cards);
    for (int i=0; i < hand->n_cards; i++) {
      if ((idx <= i && i < idx + n) || (p <= i && i < p + 2)) {
        continue;
      }
      (ans.cards)[4] = (hand->cards)[i];
      break;
    }
    break;
  case PAIR:
    assert(n == 2);
    copyToCards_n_cards_exclude(hand, 0, n, 3, ans.cards, idx, idx + n);
    break;
  case STRAIGHT_FLUSH:
  case FLUSH:
  case STRAIGHT:
    assert(n == 5);
    break;
  default:
    break;
  }
  return ans;
}


int compare_hands(deck_t * hand1, deck_t * hand2) {
  qsort(hand1->cards, hand1->n_cards, sizeof(card_t*), card_ptr_comp);
  qsort(hand2->cards, hand2->n_cards, sizeof(card_t*), card_ptr_comp);
  hand_eval_t eval1 = evaluate_hand(hand1);
  hand_eval_t eval2 = evaluate_hand(hand2);
  if (eval1.ranking > eval2.ranking) {
    return -1;
  } else if (eval1.ranking < eval2.ranking) {
    return 1;
  } else {
    for (int i=0; i < 5; i++) {
      card_t* card1 = eval1.cards[i];
      card_t* card2 = eval2.cards[i];
      if (card1->value > card2->value) {
        return 1;
      } else if (card1->value < card2->value) {
        return -1;
      }
    }
  }
  return 0;
}
*/


//You will write this function in Course 4.
//For now, we leave a prototype (and provide our
//implementation in eval-c4.o) so that the
//other functions we have provided can make
//use of get_match_counts.
/*unsigned * get_match_counts(deck_t * hand) {
  size_t n = hand->n_cards;
  unsigned *ans = malloc(n*sizeof(*ans));
  size_t cnts[15];
  for (int i=0; i < 15; i++) {
    cnts[i] = 0;
  }
  for (int i=0; i < n; i++) {
    cnts[hand->cards[i]->value]++;
  }
  for (int i=0; i < n; i++) {
    ans[i] =  cnts[hand->cards[i]->value];
  }
  return ans;
}
*/
/*
unsigned * get_match_counts(deck_t * hand) ;
// We provide the below functions.  You do NOT need to modify them
// In fact, you should not modify them!


//This function copies a straight starting at index "ind" from deck "from".
//This copies "count" cards (typically 5).
//into the card array "to"
//if "fs" is NUM_SUITS, then suits are ignored.
//if "fs" is any other value, a straight flush (of that suit) is copied.
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if (from->cards[ind]->value == nextv &&
	(fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
  }
}


//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)
// in "hand".  It calls the student's is_straight_at for each possible
// index to do the work of detecting the straight.
// If one is found, copy_straight is used to copy the cards into
// "ans".
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    if (x != 0){
      if (x < 0) { //ace low straight
	assert(hand->cards[i]->value == VALUE_ACE &&
	       (fs == NUM_SUITS || hand->cards[i]->suit == fs));
	ans->cards[4] = hand->cards[i];
	size_t cpind = i+1;
	while(hand->cards[cpind]->value != 5 ||
	      !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
	  cpind++;
	  assert(cpind < hand->n_cards);
	}
	copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
	copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.
//This function is longer than we generally like to make functions,
//and is thus not so great for readability :(
hand_eval_t evaluate_hand(deck_t * hand) {
  suit_t fs = flush_suit(hand);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    if(find_straight(hand, fs, &ans)) {
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  unsigned * match_counts = get_match_counts(hand);
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  if (n_of_a_kind == 4) { //4 of a kind
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
	ans.cards[copy_idx] = hand->cards[i];
	copy_idx++;
	if (copy_idx >=5){
	  break;
	}
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01
      //if other_pair_idx > 2, then, e.g. A A K Q Q
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q
      ans.cards[4] = hand->cards[4];
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}
*/
#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int card_ptr_comp(const void * vp1, const void * vp2) {
  const card_t * const * cp1 = vp1;
  const card_t * const * cp2 = vp2;
    int result=0;
  if ((*cp1)->value > (*cp2)->value) result-=1;
  if ((*cp1)->value < (*cp2)->value) result+=1;
  if ((*cp1)->value==(*cp2)->value){
    if ((*cp1)->suit > (*cp2)->suit) result-=1;
    if ((*cp1)->suit < (*cp2)->suit) result+=1;
    if ((*cp1)->suit == (*cp2)->suit) result=0;
  }
    return result;
}

suit_t flush_suit(deck_t * hand) {
  size_t num=hand->n_cards;
  int spades=0;
  int hearts=0;
  int diamonds=0;
  int clubs=0;
  for (size_t i=0; i<num; i++){
    switch(hand->cards[i]->suit){
    case SPADES:
      spades++;
      break;
    case HEARTS:
      hearts++;
      break;
    case DIAMONDS:
      diamonds++;
      break;
    case CLUBS:
      clubs++;
      break;
    case NUM_SUITS:
      break;
    }
  }
    if (diamonds>=5) return DIAMONDS;
    if (spades>=5) return SPADES;
    if (clubs>=5) return CLUBS;
    if (hearts>=5) return HEARTS;
    return NUM_SUITS;
}


unsigned get_largest_element(unsigned * arr, size_t n) {
  unsigned current_largest=0;
  // printf("get_largest_element\n");
  for (int i=0; i<n; i++){
    if (arr[i]>current_largest) current_largest=arr[i];
  }
  return current_largest;
}

size_t get_match_index(unsigned * match_counts, size_t n,unsigned n_of_akind){
  // printf("get_match_index\n");
  for (size_t i=0; i<n; i++){
    if (match_counts[i]==n_of_akind) {
      return i;
  }
  }
  return n;
}

ssize_t  find_secondary_pair(deck_t * hand, unsigned * match_counts, size_t match_idx) {
  //  printf("find_secondary_pair\n");
  for (ssize_t i=0; i<hand->n_cards; i++){
    if (match_counts[i]>1 && hand->cards[i]->value != hand->cards[match_idx]->value) {
      return i;
    }
  }
  return -1;
}

int strt_conts(unsigned c1, unsigned c2){
  //  printf("In strt_conts with %d, %d\n",c1,c2);
  if (c1-1==c2){
    return 1;
  }else{
    return 0;
}
}

int suitSame(suit_t entry, suit_t entry2, suit_t entry3){
  // printf("In suitSame\n");
  if (entry==entry2 && entry==entry3) {
    return 1;
  }else{
    return 0;
  }
}

int is_ace_low_straight_at(deck_t *hand, size_t index, suit_t fs, int n){
  // printf("in ace low\n");
  int len=1;
  int nextValue=5;

  for (int i=0; i<n; i++){

    unsigned card_v=hand->cards[i]->value;
    suit_t card_s=hand->cards[i]->suit;

    if (fs!=NUM_SUITS) {
      if (card_v==nextValue && card_s==fs){
	nextValue--;
	len++;
	//	printf("len:%d",len);
	  }
    }else{
      if (card_v==nextValue){
	nextValue--;
	len++;
      }
      }
  }
 if (len>=5) {
   //  printf("IS ace low\n");
   return 1;
 }else{
   return 0;
 }
}

int is_n_length_straight_at(deck_t * hand, size_t index, suit_t fs, int n){
  int lastValue=hand->cards[index]->value;
  int len=1;
  if (index==0 && lastValue==14) {
    int aceLow=is_ace_low_straight_at(hand, index, fs, n);
    if (aceLow==1){
      //      printf("is ACE LOW");
      return -1;
    }
  }
  for (size_t i=index; i<n; i++){
    unsigned card_v=hand->cards[i]->value;
    suit_t card_s=hand->cards[i]->suit;
    if (fs!=NUM_SUITS){
      if ((card_s==fs) && (card_v==lastValue-1)) {
	len++;
	  lastValue--;
	  }
					      }
    if (fs==NUM_SUITS){
      if (card_v==lastValue-1){
	len++;
	  lastValue--;
      }
  }
  }

  if (len>=5) {
    return 1;
  }else{
    return 0;
  }
}

int is_straight_at(deck_t * hand, size_t index, suit_t fs) {
  if (((hand->n_cards) - index) < 5) return 0;
  // this should not be needed;
  //if (hand->n_cards<7) return 0;
  //  printf("n cards is%zu", hand->n_cards);
  if (fs!=NUM_SUITS && hand->cards[index]->suit!=fs) return 0;
  // int len=1;
  int result=0;
  // printf("In is_straightat\n");
  // for (size_t i=index; i<6; i++) {
    // if (i>5) break;
  // printf("value is: %u", hand->cards[i+1]->value);
  //  unsigned card1val=hand->cards[i]->value;
  //  unsigned card2val=hand->cards[i+1]->value;
  // // if (card1val==card2val) continue;
  // // suit_t card1s=hand->cards[i]->suit;
  //  //suit_t card2s=hand->cards[i+1]->suit;
  // if (card1val==card2val) continue;
  //  if (strt_conts(card1val, card2val)){
  //	  len++;
  // }
  // }
  result=is_n_length_straight_at(hand, index, fs, hand->n_cards);
  // printf("about to return: %d",result);
  return result;

    /* if (fs==NUM_SUITS){ */
    /* 	if (card1val==card2val) continue; */
    /* 	if (strt_conts(card1val, card2val)){ */
    /* 	  //	  printf("len is:%d\n",len); */
    /* 	len++; */
    /* 	if (len>=5) return 1; */
    /*   }else{ */
    /* 	break; */
    /*   } */
    /*   } */

    /*   if (fs!=NUM_SUITS){ */
    /* 	//	if (card1val==card2val) continue; */
    /* 	if (strt_conts(card1val,card2val)&&suitSame(card1s,card2s,fs)){ */
    /* 	  len++; */
    /* 	  printf("len is:%d\n", len); */
    /* 	  if (len>=5) return 1; */
    /* 	 }else{ */
    /* 	  break; */

    /* 	   } */
    /* 	  } */
    /* 	  } */
  /* if (len>=5){ */
  /*   return 1; */
  /* }else{ */
  /*   return 0; */
  /* } */
}


hand_eval_t build_hand_from_match(deck_t * hand,
				  unsigned n,
				  hand_ranking_t what,
				  size_t idx) {

  //  printf("in buildhandfrommatch\n");
  hand_eval_t ans;
  ans.ranking = what;

  // start at idx and copy n cards to ans.cards (AKA n of a kind)
  for (int i=0; i<n; i++){
    ans.cards[i]=hand->cards[idx+i];
  }

  // copy the rest
  int i=n;
  int x=0;

  //copies cards before the n of a kind
  for(; i<5 && x<idx; i++){
    ans.cards[i] = hand->cards[x];
    x++;
  }

  //if hand is still not completed, continue copying after n of a kind.
  if (i<5){
    x=idx+n;

    for(; i<5; i++){
      ans.cards[i] = hand->cards[x];
      x++;

    }

  }

  // PREVIOUS IMPLEMENTATION CAUSED VALGRIND ERROR
  /* hand_eval_t ans; */
  /*   ans.ranking=what; */
  /*   for (size_t i=0; i<5; i++){ */
  /*     ans.cards[i]=hand->cards[i+idx]; */
  /* 	} */
  /*   size_t from=0; */
  /*   switch(what){ */
  /*   case STRAIGHT_FLUSH: */
  /*     break; */
  /*   case FOUR_OF_A_KIND: */
  /*     for (size_t to=n; to<5; to++, from++){ */
  /* 	if (from==idx) from=idx+n; */
  /* 	ans.cards[to]=hand->cards[from]; */
  /*     } */
  /*     break; */
  /*   case FULL_HOUSE: */
  /*     break; */
  /*   case FLUSH: */
  /*     break; */
  /*   case STRAIGHT: */
  /*     break; */
  /*   case THREE_OF_A_KIND: */
  /*     for (size_t to=n; to<5; to++, from++){ */
  /* 	if (from==idx) from=idx+n; */
  /* 	ans.cards[to]=hand->cards[from]; */
  /*     } */
  /*     break; */
  /*   case TWO_PAIR: */
  /*     for (size_t to=n; to<5; to++, from++){ */
  /* 	if (from==idx) from=idx+n; */
  /* 	ans.cards[to]=hand->cards[from]; */
  /*     } */
  /*     break; */
  /*   case PAIR: */
  /*     for (size_t to=n; to<5; to++, from++){ */
  /* 	if (from==idx) from=idx+n; */
  /* 	ans.cards[to]=hand->cards[from]; */
  /*     } */
  /*     break; */
  /*   case NOTHING: */
  /*     for (size_t to=n; to<5; to++, from++){ */
  /* 	ans.cards[to]=hand->cards[from]; */
  /*     } */
  /* 	break; */

  /*   } */

  return ans;
}


int compare_hands(deck_t * hand1, deck_t * hand2) {
  // MAYBE SIZEOF SHOULD BE card_t???
  qsort(hand1->cards, hand1->n_cards, sizeof(card_t), card_ptr_comp);
  qsort(hand2->cards, hand2->n_cards, sizeof(card_t), card_ptr_comp);
  hand_eval_t handeval1 = evaluate_hand(hand1);
  hand_eval_t handeval2 = evaluate_hand(hand2);
  if (handeval1.ranking<handeval2.ranking) return 1;
  if (handeval1.ranking==handeval2.ranking) {
    for (int i=0; i<5; i++){
      if (handeval1.cards[i]->value>handeval2.cards[i]->value) return 1;
      if (handeval1.cards[i]->value==handeval2.cards[i]->value) continue;
      if (handeval1.cards[i]->value<handeval2.cards[i]->value) return -1;
  }
  }
  if (handeval1.ranking>handeval2.ranking) return -1;
  return 0;
}


//You will write this function in Course 4.
//For now, we leave a prototype (and provide our
//implementation in eval-c4.o) so that the
//other functions we have provided can make
//use of get_match_counts.
unsigned * get_match_counts(deck_t * hand) {
  unsigned * elems=malloc(sizeof(* elems)*hand->n_cards);
  size_t num = hand->n_cards;
  //  initialize elems to be safe
   for (int i=0; i< num; i++){
    elems[i]=0;
   }

  for (int i=0; i< num; i++){
    if (elems[i]<1){
      //check value in position i against all other values and get the total number of counts
      unsigned count=1;
      for (int x=0; x<num; x++){
	if (x==i) continue;
	if (hand->cards[i]->value==hand->cards[x]->value){
	  count++;
	}
      }
      // assign count to current element
      elems[i]=count;

      // assign count to same elements
      for (int x=0; x<num; x++){
	if (x==i) continue;
	if (hand->cards[i]->value==hand->cards[x]->value){
	  elems[x]=count;
	}
      }
    }
  }
  return elems;
}

// We provide the below functions.  You do NOT need to modify them
// In fact, you should not modify them!


//This function copies a straight starting at index "ind" from deck "from".
//This copies "count" cards (typically 5).
//into the card array "to"
//if "fs" is NUM_SUITS, then suits are ignored.
//if "fs" is any other value, a straight flush (of that suit) is copied.
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if (from->cards[ind]->value == nextv &&
	(fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
  }
}


//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)
// in "hand".  It calls the student's is_straight_at for each possible
// index to do the work of detecting the straight.
// If one is found, copy_straight is used to copy the cards into
// "ans".
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    if (x != 0){
      if (x < 0) { //ace low straight
	assert(hand->cards[i]->value == VALUE_ACE &&
	       (fs == NUM_SUITS || hand->cards[i]->suit == fs));
	ans->cards[4] = hand->cards[i];
	size_t cpind = i+1;
	while(hand->cards[cpind]->value != 5 ||
	      !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
	  cpind++;
	  assert(cpind < hand->n_cards);
	}
	copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
	copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.
//This function is longer than we generally like to make functions,
//and is thus not so great for readability :(
hand_eval_t evaluate_hand(deck_t * hand) {
  suit_t fs = flush_suit(hand);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    if(find_straight(hand, fs, &ans)) {
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  unsigned * match_counts = get_match_counts(hand);
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  if (n_of_a_kind == 4) { //4 of a kind
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
	ans.cards[copy_idx] = hand->cards[i];
	copy_idx++;
	if (copy_idx >=5){
	  break;
	}
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01
      //if other_pair_idx > 2, then, e.g. A A K Q Q
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q
      ans.cards[4] = hand->cards[4];
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}

