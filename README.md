# BohnanzaCardGame

### Explained Overall
- Deux joueurs placent les cartes en chaînes, échangent les cartes et vendent les chaînes.
- Les cartes ont 8 faces différentes correspondant à différents types de Haricots
- But du jeu et de chainer les cartes du meme type pour gagner des pieces
- Il y a un maximum de **deux** ou **trois** chaînes en tout par joueur. Chaque chaîne peut
  seulement être formée d'un **seul** type de haricot.
- Au debut du jeu chaque joueur reçoit __5 cartes__ haricots en main et les cartes restantes forment une plate-forme de tirage (une pioche (deck)).
#### Rules
- The rule is that cards in a player’s hand need to be kept sorted. Cards will be placed on a discard pile during the
  game.
- Cards in the hand are kept hidden. Cards in trading areas and chains are visible to all players. The discard
  pile is face up, but only the top card is visible.
- Le jeu se termine quand la plate-forme (deck) est vide.

#### To run the game:
** this was made to work with GNU g++13

make && ./main

#### To rebuild:

make clean && make && ./main

####UML that we made (it doesn’t reflect 100% our code - it's just a way to showcase the game overall)
<img width="1014" alt="image" src="https://github.com/AymanBennaceur/BohnanzaCardGame/assets/71724174/c3b3fa8f-020e-434b-bdb1-a24c64f30443">


###  Checklist - done / to be done

- [x] Card
- [x] Chain
- [x] Deck
- [x] DiscardPile
- [x] TradeArea
- [x] Hand
- [x] Player
- [x] Table
- [x] CardFactory
- [ ] Main
