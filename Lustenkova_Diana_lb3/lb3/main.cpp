#include "field/field_creator.h"
#include "controller.h"

int main()
{
    field_creator creator(main_level);
    field f1 = creator.get_field_();
    f1.str();
    std::cout << '\n';

    player p1;
    p1.add_lives_(1);
    controller c_p1(p1, f1, f1.get_entrance_());
    // Spikes
    std::cout << "check Spikes:" << '\n';
    c_p1.set_cords_(11, 16);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';
    std::cout << "lives_ = " << p1.get_lives_() << '\n';
    c_p1.move(Bottom);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';
    std::cout << "lives_ = " << p1.get_lives_() << '\n';
    // Healing
    std::cout << "check Healing:" << '\n';
    c_p1.move(Bottom);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';
    std::cout << "lives_ = " << p1.get_lives_() << '\n';
    // Damage
    std::cout << "check Damage:" << '\n';
    c_p1.set_cords_(18, 9);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';
    std::cout << "lives_ = " << p1.get_lives_() << '\n';
    c_p1.move(Right);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';
    std::cout << "lives_ = " << p1.get_lives_() << '\n';
    // Teleport
    std::cout << "check Teleport:" << '\n';
    c_p1.set_cords_(4, 3);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';
    c_p1.move(Top);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';
    // Rift
    std::cout << "check Rift:" << '\n';
    c_p1.set_cords_(8, 12);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';
    c_p1.move(Bottom);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';

    return 0;
}