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

    void attack(int moveIndex, Pokemon &target) {
        Move &selectedMove = moves[moveIndex];
        std::cout << name << " は " << selectedMove.name << " を くりだした!" << std:: endl;

        target.hp -= selectedMove.power; // 相手のHPを減らす
        std::cout << target.name << " に " << selectedMove.power << " の ダメージ!" << std::endl;
    }

    bool isFainted() { //相手が倒れたかの判定
        return hp <= 0;
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

    Pokemon p2("ヒトカゲ", 100);

    std::cout << p2.name << " が あらわれた!" << std::endl;

    // -----ここから入力処理　-----
    p1.showMoves(); // 技の表示

    int choice;
    std::cout << p1.name << " は どうする？ ";
    std::cin >> choice; // キーボード入力を受け取る

    if (choice >= 1 && choice <= (int)p1.moves.size()) {
        p1.attack(choice - 1, p2); // 選択された技で攻撃
    } else {
        std::cout << "しかし うまく きまらなかった!" << std::endl;
    }

    // 相手の残りHPを表示
    std::cout << p2.name << " の 残りHP: " << p2.hp << std::endl;
    return 0;
}