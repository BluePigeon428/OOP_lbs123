#include "controller.h"

int main()
{

    player p1;
    p1.kill();

    field f1 = field(20, 20, { 5, 1 });
    std::cout << '\n';
    field f2(f1);
    f1.str();
    std::cout << '\n';
    f2.str();
    std::cout << '\n';
    field f3(field(10, 10));
    //field f3 = std::move(field(10, 10));
    f3.str();
    std::cout << '\n';

    controller c_p1(p1, f1, f1.get_entrance_());
    c_p1.move(Right);
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';

    for (int i = 0; i < 20; i++)
    {
        c_p1.move(Right);
        c_p1.move(Top);
    }
    std::cout << "p1: " << c_p1.get_cords_().x_ << ' ' << c_p1.get_cords_().y_ << '\n';

    enemy e1;
    controller c_e1(e1, f1, { 3, 4 });
    e1.step_to_move_to_player(c_e1.get_cords_().x_, c_e1.get_cords_().y_, c_p1.get_cords_().x_, c_p1.get_cords_().y_);

    return 0;
}