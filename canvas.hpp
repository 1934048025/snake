//
//  canvas.hpp
//  TheSnake
//
//  Created by 匡润龙 on 2023/3/5.
//  Copyright © 2023 匡润龙. All rights reserved.
//

#ifndef canvas_hpp
#define canvas_hpp

#include "snake.hpp"

class Canvas
{
private:
    int lon;  //画布长
    int wid;  //画布宽
    char **cavas;   //cavas[wid][lon];
    char cav_ch;       //画布
    char moey_ch;      //金子
    int score;         //分数
    loct money;
    
public:
    Canvas();
    void draw_snake(const Snake &sn);
    bool set_money();
    bool add_score();
    void update_canvas();
    void out_canvas();
    loct get_money_locat();
    int get_long();
    int get_wide();
    void game_over();
    ~Canvas();//不作为基类
};

#endif /* canvas_hpp */
