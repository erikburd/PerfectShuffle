// PerfectShuffle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <assert.h>
#include "CardShuffler.h"
#include "Timer.h"

using namespace std;

int main()
{
    CardShuffler<int> cs, cs1;
    CardShuffler<int> cs2, cs3;
    int cycles, cycles2;

    // test for decks up to 500 cards
    // verify that the "new" shuffles generate the
    // same shuffle at each iteration as the original
    // algorithm, and also verify that it takes the
    // same number of cycles to restore each deck
    for (int j = 3; j <= 500; j++)
    {
        cout << "Deck size: " << j << "\n";
        cs.GenerateDeck(j);
        cs1.GenerateDeck(j);
        cycles = cs.RestoreDeck(ShuffleType::INV_INSHUFFLE);
        cout << "\tCycles: " << cycles << " Inverse in\n";
        for (int i = 0; i < cycles; i++)
        {
            cs.PerformShuffle(ShuffleType::INV_INSHUFFLE);
            cs1.PerformShuffle(ShuffleType::EXP_INV_INSHUFFLE);
            assert(cs.GetDeck() == cs1.GetDeck());
        }

        cs2.GenerateDeck(j);
        cs3.GenerateDeck(j);
        cycles2 = cs2.RestoreDeck(ShuffleType::INSHUFFLE);
        cout << "\tCycles: " << cycles << " In\n";
        for (int i = 0; i < cycles2; i++)
        {
            cs2.PerformShuffle(ShuffleType::INSHUFFLE);
            cs3.PerformShuffle(ShuffleType::EXP_INSHUFFLE);
            assert(cs2.GetDeck() == cs3.GetDeck());
        }

        cs.GenerateDeck(j);
        cs1.GenerateDeck(j);
        cycles = cs.RestoreDeck(ShuffleType::INV_OUTSHUFFLE);
        cout << "\tCycles: " << cycles << " Inverse out\n";
        for (int i = 0; i < cycles; i++)
        {
            cs.PerformShuffle(ShuffleType::INV_OUTSHUFFLE);
            cs1.PerformShuffle(ShuffleType::EXP_INV_OUTSHUFFLE);
            assert(cs.GetDeck() == cs1.GetDeck());
        }

        cs2.GenerateDeck(j);
        cs3.GenerateDeck(j);
        cycles2 = cs2.RestoreDeck(ShuffleType::OUTSHUFFLE);
        cout << "\tCycles: " << cycles << " Out\n";
        for (int i = 0; i < cycles2; i++)
        {
            cs2.PerformShuffle(ShuffleType::OUTSHUFFLE);
            cs3.PerformShuffle(ShuffleType::EXP_OUTSHUFFLE);
            assert(cs2.GetDeck() == cs3.GetDeck());
        }
    }
}
