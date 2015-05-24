#include "widgets.hpp"

using namespace genv;

Widgets::Widgets( ) {}                                            // Paraméter nélküli konstruktor
Widgets::Widgets( int _x, int _y, int _size_x, int _size_y )      // Négy paraméteres konstruktor
: x(_x), y(_y), size_x(_size_x), size_y(_size_y) {
    inFocus = false;
}

void Widgets::draw(){
}

void Widgets::handle( event ev ) {
}

void Widgets::set_focus( bool focus ){
    inFocus = focus;
}

bool Widgets::is_selected( int mouse_x, int mouse_y ) const {
    return mouse_x>=x && mouse_x<=x+size_x && mouse_y>=y && mouse_y<=y+size_y;
}



