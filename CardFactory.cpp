#include "CardFactory.h"



// Deck CardFatory::getDeckFromSave(istream& is) {
//     Deck df;
//     is.seekg(0, is.end);
//     int l = is.tellg()/2;
//     is.seekg(0, is.beg);
//     char c;
//     for (int i = 0; i<l; i++) {
//         is.seekg(2, is.cur);
//         is.readsome(c, 1);
//         if (c == "B") {
//             df.push_back(new Blue());
//         } else if (c == "C") {
//             df.push_back(new Chili());
//         } else if (c == "S") {
//             df.push_back(new Stink());
//         } else if (c == "G") {
//             df.push_back(new Green());
//         } else if (c == "s") {
//             df.push_back(new soy());
//         } else if (c == "b") {
//             df.push_back(new black());
//         } else if (c == "R") {
//             df.push_back(new Red());
//         } else if (c == "g") {
//             df.push_back(new Green());
//         } else {
//             cout << "error reading save file, starting new game";
//         }
//     }
//     return df;
// }

// Hand CardFatory::getHandFromSave(istream& is) {
//     Hand h;
//     is.seekg(0, is.end);
//     int l = is.tellg()/2;
//     is.seekg(0, is.beg);
//     char c;
//     for (int i = 0; i<l; i++) {
//         is.seekg(2, is.cur);
//         is.readsome(c, 1);
//         if (c == "B") {
//             h+=(new Blue());
//         } else if (c == "C") {
//             h+=(new Chili());
//         } else if (c == "S") {
//             h+=(new Stink());
//         } else if (c == "G") {
//             h+=(new Green());
//         } else if (c == "s") {
//             h+=(new soy());
//         } else if (c == "b") {
//             h+=(new black());
//         } else if (c == "R") {
//             h+=(new Red());
//         } else if (c == "g") {
//             h+=(new Green());
//         } else {
//             cout << "error reading save file, starting new game";
//         }
//     }
//     return h;
// }

// DiscardPile CardFatory::getDiscardFromSave(istream& is) {
//     DiscardPile dp;
//     if(is) {
//         is.seekg(0, is.end);
//         int l = is.tellg()/2;
//         is.seekg(0, is.beg);
//         char c;
//         for (int i = 0; i<l; i++) {
//             is.seekg(2, is.cur);
//             is.readsome(c, 1);
//             if (c == "B") {
//                 dp.push_back(new Blue());
//             } else if (c == "C") {
//                 dp.push_back(new Chili());
//             } else if (c == "S") {
//                 dp.push_back(new Stink());
//             } else if (c == "G") {
//                 dp.push_back(new Green());
//             } else if (c == "s") {
//                 dp.push_back(new soy());
//             } else if (c == "b") {
//                 dp.push_back(new black());
//             } else if (c == "R") {
//                 dp.push_back(new Red());
//             } else if (c == "g") {
//                 dp.push_back(new Green());
//             } else {
//                 cout << "error reading save file, starting new game";
                
//             }
//         }
//     }
//     return dp;
// }


