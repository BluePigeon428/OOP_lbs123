#include "controller.h"

int main()
{

    player p1;
    p1.kill();

    field f1 = field(100, 100);
    field f2 = f1.copy();

    controller c_p1(p1, f1, { 1, 1 });
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