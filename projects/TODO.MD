# TODO List for this Project

* [ ] Implement binary_search algorithm
* [ ] Implement calculate_score algorithm
 * This needs to check if the card has an adjacent value to a card already in the hand
 * I think we need to recalculate the score ever single time we get a new card.
 * I can't think of a clever algorithm that doesn't require a recalculating.


## calculate_score algorithm

Let's consider the cases

Simple Case:
	There are no adjacent cards in the players' hand.
	Then we simply add the value of the card to the players' score.

Case 1: The card added extends the end an existing 'chain'

 Current Hand: [1] ... [n-1] 
 Card to Draw: [n]
 Card after action [1]... [n-1] [n]

In this case, then we don't add to the score.
We just need to verify that this card is simply just an extension of the chain.

Case 2: The card added extends the front of the existing 'chain'

 Current Hand: [n+1] [n+2] ... [n+k]
 Card to Draw: [n]
 Card after action [n] [n+1] [n+2] ... [n+k]

In this case, we need to subtract 1 to the score.
We also need to verify that this is the start of the longer chain.

Case 3: The card added connects two existing chains

 Current Hand: [1] ... [n-1], [n+1] ... [n+k]
 Card to Draw: [n]
 Card after action [1] ... [n+k] 

In this case, we would subtract the upper chain's starting number to the score. 

### An aside about this algorithm

I'm thinking that we can use a data structure for this kind of idea. 
But I'm trying to think which one is the best case here...
