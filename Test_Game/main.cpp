#include <iostream>
#include <SFML/Graphics.hpp>

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
const int MAP_Y = 9;
const int MAP_X = 8;
///////////////////////////


using namespace sf;
using namespace std;

int map_scheme[MAP_Y][MAP_X] =
        {
                { 0, 0, 0, 0, 0, 0, 0, 1 },
                { 0, 0, 0, 0, 0, 0, 0, 1 },
                { 0, 0, 0, 0, 0, 0, 0, 1 },
                { 0, 0, 0, 0, 0, 0, 0, 1 },
                { 0, 0, 0, 0, 0, 0, 0, 1 },
                { 0, 0, 0, 0, 0, 0, 0, 1 },
                { 1, 0, 0, 0, 0, 0, 0, 1 },
                { 1, 0, 0, 0, 0, 0, 0, 1 },
                { 1, 1, 1, 1, 1, 1, 1, 1 }
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
class Hero {
public:
    Texture texture;
    vec coordinates;
    Sprite sprite;
    int width_x;
    int lenght_y;
    int step;
    int colvo_x ;
    int colvo_y ;
    Hero (char * file , int step_ , int width_x_ , int lenght_y_ , vec coordinates_ , int colvo_x_ ):
        texture(),
        coordinates(coordinates_),
        sprite(),
        width_x(width_x_),
        lenght_y(lenght_y_),
        step(step_),
        colvo_x(colvo_x_),
        colvo_y(0)
    {
        try {
            my_class_error error;
            TEST(error,"Ошибка при создании героя");
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
    Game():
        i(0),
        j(0)
    {}
    int Process(){
        Hero gay("/home/sergey/Image/sprite.png" , 1 , 32 ,32 , {500,500} , 6);
        Map map("/home/sergey/Image/map.png" , 32 , 32 , 3);
        RenderWindow window(VideoMode(size_window_x, size_window_y), "Go!");
        while (window.isOpen())
        {
            window.clear();
            draw_map(map,window);
            Event event;
            while (window.pollEvent(event )){
                if (event.type == Event::Closed || event.key.code == Keyboard::Escape )
                    window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Left)){
                if (collision_with_map(left_,gay)) {
                    motion(left_, gay);
                }
                else {
                    gay.coordinates.x = gay.coordinates.x + gay.step;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)){
                if (collision_with_map(right_,gay)) {
                    motion(right_, gay);
                }
                else{
                    gay.coordinates.x = gay.coordinates.x - gay.step;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)){
                if (collision_with_map(down,gay)) {
                    motion(down, gay);
                }
                else{
                    gay.coordinates.y = gay.coordinates.y - gay.step;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)){
                if (collision_with_map(up,gay)) {
                    motion(up, gay);
                }
                else{
                    gay.coordinates.y = gay.coordinates.y + gay.step;
                }
            }
            window.draw(gay.sprite);
            window.display();
        }
    }
    void motion(int direction , Hero & hero ){
        if (direction == down){
            hero.sprite.setTextureRect(IntRect(hero.width_x*i, hero.lenght_y*down  , hero.width_x,hero.lenght_y)); // какую текстуру брать
            hero.coordinates.y = hero.coordinates.y+hero.step;

        }
        if (direction == left_){
            hero.sprite.setTextureRect(IntRect(hero.width_x*i, hero.lenght_y*left_  , hero.width_x,hero.lenght_y)); // какую текстуру брать
            hero.coordinates.x = hero.coordinates.x-hero.step;

        }
        if (direction == right_){
            hero.sprite.setTextureRect(IntRect(hero.width_x*i, hero.lenght_y*right_  , hero.width_x,hero.lenght_y)); // какую текстуру брать
            hero.coordinates.x = hero.coordinates.x+hero.step;

        }
        if (direction == up){
            hero.sprite.setTextureRect(IntRect(hero.width_x*i, hero.lenght_y*up  , hero.width_x,hero.lenght_y)); // какую текстуру брать
            hero.coordinates.y = hero.coordinates.y-hero.step;

        }
        hero.sprite.setPosition(hero.coordinates.x, hero.coordinates.y); // тут твой обЪект в данный моменет
        i++;
        if (i == hero.colvo_x){
            i = 0;
        }
    }
    void draw_map(Map & map,RenderWindow & window){
        for (int j = 0 ; j < MAP_Y ; j++){
            for (int k = 0 ; k < MAP_X ; k++){
                map.sprite.setTextureRect(IntRect(map.width_x*map_scheme[j][k], 0 , map.width_x , map.lenght_y));
                map.sprite.setPosition(k*map.width_x , j*map.lenght_y);
                window.draw(map.sprite);
            }
        }
    }
    bool collision_with_map (int derection , Hero & gay ){ // координаты на единицу кабика
        if (derection == right_){
            if (map_scheme[gay.coordinates.y/32][(gay.coordinates.x/32)+1] == stone){
                return false;
            }
            else {
                return true;
            }
        }
        if (derection == left_){
            if (map_scheme[gay.coordinates.y/32][(gay.coordinates.x/32)-1] == stone){
                return false;
            }
            else {
                return true;
            }
        }
        if (derection == up){
            if (map_scheme[gay.coordinates.y/32-1][(gay.coordinates.x/32)] == stone){
                return false;
            }
            else {
                return true;
            }
        }
        if (derection == down){
            if (map_scheme[gay.coordinates.y/32+1][(gay.coordinates.x/32)] == 1){
                return false;
            }
            else {
                return true;
            }
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
