#include "field_creator.h"

#include <fstream>

field_creator::field_creator(field_level level) : field_()
{
    std::string level_id;
    if (level == main_level)
    {
        level_id = "main";
    }
    if (level == end_level)
    {
        level_id = "end";
    }
    if (level == secret_level)
    {
        level_id = "secret";
        field_ = field(5, 7, { 2, 1 });
    }
    std::string file_name = "../field/levels/" + level_id + "_level.txt";
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        std::cerr << "field_creator(field_level level): !file.is_open()" << '\n';
        return;
    }
    int current_id;
    for (int y = 0; y < field_.get_height_(); y++)
    {
        for (int x = 0; x < field_.get_width_(); x++)
        {
            file >> current_id;
            // -3, -2, -1 is Floor with event
            if (current_id == -3)
                field_.set_event_of_cell(x, y, new Rift);
            if (current_id == -2)
                field_.set_event_of_cell(x, y, new Damage);
            if (current_id == -1)
                field_.set_event_of_cell(x, y, new Healing);
            // 0 is just Floor
            if (current_id == 1)
                field_.set_type_of_cell(x, y, Spikes);
            if (current_id == 2)
                field_.set_type_of_cell(x, y, Barrier);
            if (current_id == 3)
                field_.set_type_of_cell(x, y, Teleport);
            if (current_id == 4)
                field_.set_type_of_cell(x, y, Exit_door);
        }
    }
    if (level == main_level)
    {
        field_.set_tp_cords_of_cell(4, 4, { 20, 20 });
        field_.set_tp_cords_of_cell(20, 20, { 4, 4 });
    }
    if (level == end_level)
    {
        field_.set_tp_cords_of_cell(6, 6, { 6, 18 });
        field_.set_tp_cords_of_cell(6, 18, { 6, 6 });
    }
}

field field_creator::get_field_()
{
    return field_;
}
