#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class card {
public:
    int value;
    int suit;
    bool visible;

    card(int value, int suit, bool visible) : value(value), suit(suit), visible(visible) {}
};

class node {
public:
    node* left;
    node* right;
    card value;

    node(node* left, node* right, card value) : left(left), right(right), value(value) {}

    ~node() {
        left = nullptr;
        right = nullptr;
    }
};

void buildPyramid(std::vector<card>& deck, node*& root) {
    std::vector<node*> nodes;

    // Create nodes for the first 28 cards
    for (int i = 0; i < 28; ++i) {
        nodes.push_back(new node(nullptr, nullptr, deck[i]));
    }

    // Build pyramid structure
    int index = 0;
    for (int row = 1; row <= 7; ++row) {
        for (int col = 0; col < row; ++col) {
            if (row < 7) {
                nodes[index]->left = nodes[index + row];
                nodes[index]->right = nodes[index + row + 1];
            }
            ++index;
        }
    }

    root = nodes[0];
}

bool canPair(card& c1, card& c2) {
    return c1.visible && c2.visible && c1.value + c2.value == 13;
}

void makeCardsVisible(node* root) {
    if (!root) return;

    if (root->left == nullptr && root->right == nullptr) {
        root->value.visible = true;
    } else {
        root->value.visible = false;
    }

    makeCardsVisible(root->left);
    makeCardsVisible(root->right);
}

void removeCard(node*& target) {
    if (target) {
        target->left = nullptr;
        target->right = nullptr;
        delete target;
        target = nullptr;
    }
}

bool findAndRemovePair(node* root, int targetValue, node*& match) {
    if (!root || !root->value.visible) return false;

    if (root->value.value == targetValue) {
        match = root;
        return true;
    }

    return findAndRemovePair(root->left, targetValue, match) || findAndRemovePair(root->right, targetValue, match);
}

bool playGame(std::vector<card>& deck) {
    node* root = nullptr;
    buildPyramid(deck, root);
    makeCardsVisible(root);

    std::vector<card> drawPile(deck.begin() + 28, deck.end());

    while (true) {
        bool removedCard = false;

        // Search for a king and remove it
        node* kingNode = nullptr;
        if (findAndRemovePair(root, 13, kingNode)) {
            removeCard(kingNode);
            removedCard = true;
        }

        // Search for a pair of visible cards that sum to 13
        if (!removedCard && root) {
            node* match = nullptr;
            if (findAndRemovePair(root, 13 - root->value.value, match)) {
                removeCard(match);
                removedCard = true;
            }
        }

        // If no card was removed, draw from the pile
        if (!removedCard && !drawPile.empty()) {
            card drawnCard = drawPile.back();
            drawPile.pop_back();

            node* match = nullptr;
            if (findAndRemovePair(root, 13 - drawnCard.value, match)) {
                removeCard(match);
                removedCard = true;
            }
        }

        // If no moves left and draw pile is empty, break
        if (!removedCard && drawPile.empty()) break;

        // Update visibility
        makeCardsVisible(root);

        // Check if the pyramid is empty (win condition)
        if (!root && drawPile.empty()) {
            delete root;
            return true;
        }
    }

    if (root) {
        delete root;
    }
    return false;
}

std::vector<card> generateDeck() {
    std::vector<card> deck;

    for (int suit = 0; suit < 4; ++suit) {
        for (int value = 1; value <= 13; ++value) {
            deck.emplace_back(value, suit, false);
        }
    }

    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(std::time(0)));
    return deck;
}

int main() {
    int result = 0;

    for (int i = 0; i < 1000000; ++i) {
        std::vector<card> deck = generateDeck();
        if (playGame(deck)) {
            ++result;
        }
    }

    std::cout << result << std::endl;
    return 0;
}