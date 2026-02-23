#include <iostream>
#include <string>
#include <vector>

struct Move {
    std::string name;
    int power;
};

class Pokemon {
public:
    std::string name;
    int hp;
    std::vector<Move> moves;

    Pokemon(std::string n, int h) : name(n), hp(h) {}

    void learnMove(std::string moveName, int power) {
        moves.push_back({moveName, power}); 
    }

    void greet() {
        std::cout << name << " が あらわれた！ (HP: " << hp << ")" << std::endl;
    }

    void showMoves() {
        std::cout << name << " の 技" << std::endl;
        for (int i = 0; i < (int)moves.size(); i++) {
            std::cout << i + 1 << ": " << moves[i].name << " (威力: " << moves[i].power << " )" << std::endl;
        }
    }
};

int main() {
    Pokemon p1("ピカチュウ", 100);

    // 技を覚えさせる
    p1.learnMove("10まんボルト", 90);
    p1.learnMove("でんこうせっか", 40);

    p1.greet();
    p1.showMoves(); // 技の表示
    return 0;
}