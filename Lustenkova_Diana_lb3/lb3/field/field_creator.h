#include "field.h"

enum field_level { main_level, end_level, secret_level };

class field_creator
{
private:
    field field_;
protected:
public:
    field_creator(field_level level);
    field get_field_();
};
