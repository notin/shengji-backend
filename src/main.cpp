
#include "SocketServer.h"
#include "Deck.h"

#include <iostream>
#include <set>
#include <openssl/sha.h>

void deckTesting();
int serverTesting();       

int main() {
	serverTesting();
	// deckTesting();

	return 0;
}


int serverTesting() {
	SocketServer s;
	s.runServerAsAppServer();
	return 0;
}


void deckTesting() {
	int deck_count = 2;
	int card_omit = 0;
	Deck deck(deck_count, card_omit);

	deck.shuffleDeck();
	deck.setStrongSuitAndValue("Spades", "10");
	//Card* card = deck.drawCard();
	//std::cout << deck.printRankOrder() << std::endl;

	set<Card> cardset;

	int draw_deck_size = deck.getDrawDeckSize();
	for (int i = 0; i < draw_deck_size; i++) {
		Card* drawnCard = deck.drawCard();
		std::cout << to_string(i) << ": " << (*drawnCard).toString() << "\n";
		cardset.insert(*drawnCard);
	}
	std::cout << "\n" << std::endl;

	//Card* get_card = deck.getCard("Spades", "2", 0);
	//std::cout << get_card->toString() << std::endl;

	//for (Card card : cardset) {
	//	std::cout << card.toString() << "\n";
	//}
	//std::cout << to_string(cardset.size()) << std::endl;

	deck.printRankOrder();
}