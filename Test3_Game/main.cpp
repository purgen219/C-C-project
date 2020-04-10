#include <iostream>
#include <SFML/Graphics.hpp>
//gayBordars
#define TEST(error , cause_str) \
    error.line = __LINE__;\
    error.function = __PRETTY_FUNCTION__;\
    error.file = __FILE__;\
    error.cause = cause_str;


//////SIZE_WINDOW///////////
int size_window_x = 1000;
int size_window_y = 1000;
////////////////////////////

//////DERECTION/////////////
int down  = 2;
int left_ = 3;
int right_ = 1;
int up = 0;
///////////////////////////

//////FOR_MAP//////////////
int tree = 0;
int stone = 1;
int plate = 2;
const int MAP_Y = 12;
const int MAP_X = 14;
///////////////////////////


using namespace sf;
using namespace std;

int map_scheme[MAP_Y][MAP_X] =
        {                { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                         { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
                         { 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
                         { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1 },
                         { 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                         { 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                         { 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1 },
                         { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                         { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
                         { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                         { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
                         { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },

        };
class my_class_error{
public:
    int line;
    string function;
    string file ;
    string cause;
};

struct vec {
    int x;
    int y;
    vec ():
            x(0),
            y(0)
    {}
    vec (int x_,int y_):
            x(x_),
            y(y_)
    {}
    vec (vec & coordinates):
            x(coordinates.x),
            y(coordinates.y)
    {}
};
class Ghost{
    
};
class Hero {
public:
    Texture texture;
    vec coordinates;
    Sprite sprite;
    int width_x;
    int lenght_y;
    int speed;
    int colvo_x ;
    int colvo_y ;
    int direction;
    Hero (char * file , int speed_ , int width_x_ , int lenght_y_ , vec coordinates_ , int colvo_x_ ):
            texture(),
            coordinates(coordinates_),
            sprite(),
            width_x(width_x_),
            lenght_y(lenght_y_),
            speed(speed_),
            colvo_x(colvo_x_),
            colvo_y(0), // дописать !
            direction(-1)
    {
        try {
            my_class_error error;
            TEST(error,"Ошибка при создании героя");
            if (!texture.loadFromFile(file)) {
                throw error;
            }
            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(width_x , lenght_y * up, width_x, lenght_y));

        }
        catch (my_class_error error){
            throw error;
        }
    }
};
class Map{
public:
    Texture texture;
    Sprite sprite;
    int width_x;
    int lenght_y;
    int colvo_x ;
    Map(char * file ,int width_x_ ,int  lenght_y_ , int colvo_x_):
            texture(),
            sprite(),
            width_x(width_x_),
            lenght_y(lenght_y_),
            colvo_x(colvo_x_)
    {
        try {
            my_class_error error;
            TEST(error,"Ошибка при создании карты");
            if (!texture.loadFromFile(file)) {
                throw error;
            }
            sprite.setTexture(texture);
        }
        catch (my_class_error error){
            throw error;
        }
    }


};
class Game {
public:
    int i;
    int j;
    float time;
    Game():
            i(0),
            j(0)
    {}
    int Process(){
        Hero gay("/home/sergey/Image/sprite.png" , 3 , 32 ,32 , {50,50} , 6);
        Map map("/home/sergey/Image/map.png" , 32 , 32 , 3);
        RenderWindow window(VideoMode(size_window_x, size_window_y), "Go!");
        Clock clock ;
        while (window.isOpen())
        {
            time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time /1500;
            if (time > 1.5){
                time = 1.5;
            }
            window.clear();
            draw_map(map,window);
            Event event;
            while (window.pollEvent(event)){
                if (event.type == Event::Closed || event.key.code == Keyboard::Escape )
                    window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Left)){
                save_direction(left_,gay);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Up)){
                save_direction(up,gay);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Right)){
                save_direction(right_,gay);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Down)){
                save_direction(down,gay);
            }
            motion(gay);
            window.draw(gay.sprite);
            window.display();
        }
    }
    void save_direction (int direction , Hero & hero){
        hero.direction = direction;
        hero.speed = 3;
        i++;
        if (i == hero.colvo_x){
            i = 0;
        }
    }
    void motion( Hero & gay){

        int xc = gay.coordinates.x + gay.width_x/2; // координата центра по икс
        int yc = gay.coordinates.y + gay.lenght_y/2; // координаты центра по игрек

        int x_left_down = gay.coordinates.x; // координата левого нижнего угла по икс
        int y_left_down = gay.coordinates.y+gay.lenght_y; // координата левого нижнего угла по игрек
        int x_right_down = gay.coordinates.x+gay.width_x; // координата правого нижнего по икс
        int y_right_down = gay.coordinates.y+gay.lenght_y; // координата правого нижнего по игрек

        int x_right_up = gay.coordinates.x + gay.width_x;
        int y_right_up = gay.coordinates.y;
        int x_left_up = gay.coordinates.x;
        int y_left_up = gay.coordinates.y;

        if (gay.direction == left_){
            if (!collision_with_map(left_,gay)) {
                gay.sprite.setTextureRect(IntRect(gay.width_x * i, gay.lenght_y * left_, gay.width_x, gay.lenght_y));
                gay.coordinates.x = gay.coordinates.x - gay.speed * int(time);
            }
            else{
                if (yc/32 == y_left_up/32 ){
                    gay.coordinates.y = gay.coordinates.y -2;
                }
                if (yc/32 == y_left_down/32){
                    if (map_scheme[yc/32][(xc-gay.speed*int(time))/32] == stone) {
                        gay.coordinates.y = gay.coordinates.y + 2;
                    }
                    else if (map_scheme[yc/32][(xc-gay.speed*int(time))/32] == tree){
                        gay.sprite.setTextureRect(IntRect(gay.width_x * i, gay.lenght_y * left_, gay.width_x, gay.lenght_y));
                        gay.coordinates.x = gay.coordinates.x - gay.speed * int(time);
                    }
                }
            }

        }
        else if (gay.direction == down){
            if (!collision_with_map(down,gay)) {
                gay.sprite.setTextureRect(IntRect(gay.width_x * i, gay.lenght_y * down, gay.width_x, gay.lenght_y));
                gay.coordinates.y = gay.coordinates.y + gay.speed * int(time);
            }
            else {
                if (xc / 32 ==x_left_down / 32) {
                    gay.coordinates.x = gay.coordinates.x - 2;
                }
                if (xc/32 == x_right_down/32){
                    if (map_scheme[(yc+gay.speed*int(time))/32][(xc)/32] == stone) {
                        gay.coordinates.x = gay.coordinates.x + 2;
                    }
                    if (map_scheme[(yc+gay.speed*int(time))/32][(xc)/32] == tree) {
                        gay.sprite.setTextureRect(IntRect(gay.width_x * i, gay.lenght_y * down, gay.width_x, gay.lenght_y));
                        gay.coordinates.y = gay.coordinates.y + gay.speed * int(time);
                    }
                }
            }
        }
        else if (gay.direction == right_){
            if(!collision_with_map(right_,gay)) {
                gay.sprite.setTextureRect(IntRect(gay.width_x * i, gay.lenght_y * right_, gay.width_x, gay.lenght_y));
                gay.coordinates.x = gay.coordinates.x + gay.speed * int(time);
            }
            else{
                if (yc/32 == y_right_up/32 ){ // если центр масс выше ,тогда поднимаем его.
                    gay.coordinates.y = gay.coordinates.y - 2;
                }
                if (yc/32 == y_right_down/32){ // если центр масс ниже
                    if (map_scheme[yc / 32][(xc+gay.speed*int(time)) / 32 ] == stone) { // и если элемент дальше это камень ,тогда опускаем дальше
                        gay.coordinates.y = gay.coordinates.y + 2;
                    }
                    else if (map_scheme[yc / 32][(xc+gay.speed*int(time)) / 32] == tree) { // и если элемент дальше тропинка,то пусть идет дальше
                        gay.sprite.setTextureRect(IntRect(gay.width_x * i, gay.lenght_y * right_, gay.width_x, gay.lenght_y));
                        gay.coordinates.x = gay.coordinates.x + gay.speed * int(time);
                    }
                }
            }
        }
        else if (gay.direction == up){
            if (!collision_with_map(up,gay)) {
                gay.sprite.setTextureRect(IntRect(gay.width_x * i, gay.lenght_y * up, gay.width_x, gay.lenght_y));
                gay.coordinates.y = gay.coordinates.y - gay.speed * int(time);
            }
            else {
                if (xc/32 == x_left_up/32){
                    gay.coordinates.x = gay.coordinates.x - 2;
                }
                if (xc/32 == x_right_up/32){
                    if (map_scheme[(yc - gay.speed*int(time))/32 ][(xc)/32] == stone) {
                        gay.coordinates.x = gay.coordinates.x + 2;
                    }
                    if (map_scheme[(yc  - gay.speed*int(time))/32 ][(xc)/32] == tree) {
                        gay.sprite.setTextureRect(IntRect(gay.width_x * i, gay.lenght_y * up, gay.width_x, gay.lenght_y));
                        gay.coordinates.y = gay.coordinates.y - gay.speed * int(time);
                    }
                }

            }
        }
        gay.sprite.setPosition(gay.coordinates.x,gay.coordinates.y); // тут твой обЪект в данный моменет
        gay.speed = 0;
    }
    void draw_map(Map & map,RenderWindow & window){
        for (int j = 0; j < MAP_Y ; j++){
            for (int k = 0; k < MAP_X ; k++){
                map.sprite.setTextureRect(IntRect(map.width_x*map_scheme[j][k], 0 , map.width_x , map.lenght_y));
                map.sprite.setPosition(k*map.width_x , j*map.lenght_y);
                window.draw(map.sprite);
            }
        }
    }
    bool collision_with_map(int direction , Hero & gay){ // проверка коллизий при условии ,что они одинакого размера.
        int xc = gay.coordinates.x + gay.width_x/2; // координата центра по икс
        int yc = gay.coordinates.y + gay.lenght_y/2; // координаты центра по игрек
            if(direction == right_) { // проверка для всех точек !
                if (map_scheme[(gay.coordinates.y)/32][(gay.coordinates.x +gay.speed*int(time))/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y)/32][(gay.coordinates.x + gay.width_x + gay.speed*int(time))/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y+gay.lenght_y)/32][(gay.coordinates.x + gay.width_x + gay.speed*int(time))/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y+gay.lenght_y)/32][(gay.coordinates.x + gay.speed*int(time))/32] == stone){
                    return true;
                }
                else{
                    return false;
                }
                if (map_scheme[(yc)/32][(xc+gay.speed*int(time))/32]==stone){
                    return true;
                } else{
                    false;
                }
            }
            if (direction == left_){

                if (map_scheme[(gay.coordinates.y)/32][(gay.coordinates.x -gay.speed*int(time))/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y)/32][(gay.coordinates.x + gay.width_x - gay.speed*int(time))/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y+gay.lenght_y)/32][(gay.coordinates.x + gay.width_x - gay.speed*int(time))/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y+gay.lenght_y)/32][(gay.coordinates.x - gay.speed*int(time))/32] == stone){
                    return true;
                }
                else{
                    return false;
                }
                if (map_scheme[(yc)/32][(xc-gay.speed*int(time))/32]==stone){
                    return true;
                } else{
                    false;
                }
            }
            if (direction == up){
                if (map_scheme[(gay.coordinates.y-gay.speed*int(time))/32][(gay.coordinates.x )/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y-gay.speed*int(time))/32][(gay.coordinates.x + gay.width_x )/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y+gay.lenght_y-gay.speed*int(time))/32][(gay.coordinates.x + gay.width_x )/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y+gay.lenght_y-gay.speed*int(time))/32][(gay.coordinates.x )/32] == stone){
                    return true;
                }
                else{
                    return false;
                }
                if (map_scheme[(yc-gay.speed*int(time))/32][(xc)/32]==stone){
                    return true;
                } else{
                    false;
                }
            }
            if (direction == down){
                if (map_scheme[(gay.coordinates.y+gay.speed*int(time))/32][(gay.coordinates.x )/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y+gay.speed*int(time))/32][(gay.coordinates.x + gay.width_x )/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y+gay.lenght_y+gay.speed*int(time))/32][(gay.coordinates.x + gay.width_x )/32] == stone){
                    return true;
                }
                if (map_scheme[(gay.coordinates.y+gay.lenght_y+gay.speed*int(time))/32][(gay.coordinates.x )/32] == stone){
                    return true;
                }
                else{
                    return false;
                }
                if (map_scheme[(yc+gay.speed*int(time))/32][(xc)/32]==stone){
                    return true;
                } else{
                    false;
                }
            }
    }
    int bag(Hero & gay ){
        int xc = gay.coordinates.x + gay.width_x/2; // координата центра по икс
        int yc = gay.coordinates.y + gay.lenght_y/2; // координаты центра по игрек

        if ( xc/32 == 2 && yc/32 == 9 && gay.direction == down){
            cout << "HUY" << endl;
            gay.coordinates.x = gay.coordinates.x - 5;
        }
    }

};


int print_mistake(my_class_error error){
    cout << error.cause<<endl;
    cout <<error.function<<endl;
    cout <<error.file<<endl;
    cout<<error.line<<endl;
}
int main()
{
    try {
        Game hodilka;
        hodilka.Process();
    }
    catch (my_class_error error){
        print_mistake(error);
    }
    return 0;
}
