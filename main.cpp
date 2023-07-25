//
//  main.cpp
//  TheSnake
//
//  Created by 匡润龙 on 2023/2/15.
//  Copyright © 2023 匡润龙. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "snake.hpp"
#include "canvas.hpp"

static Snake snake;
static Canvas cavas;

int main(int argc, const char * argv[]) {
    initscr();
    noecho();
    cavas.draw_snake(snake);
    cavas.set_money();
    timeout(0);
    int c='d';
    char diffu=9;          //难度1--10
    while(1){
        cavas.out_canvas();
        usleep(50000*(11-diffu));
        //
        //键入方向
        if((c=getch())=='d')
            snake.set_orien(c);
        if(c=='s'||c=='a'||c=='w')
            snake.set_orien(c);
        //
        //判断游戏结束
        if(snake.hit_wall(cavas.get_long(), cavas.get_wide()) || snake.hit_body()){
            cavas.game_over();
            break;
        }
        //
        //前进
        if(snake.run(cavas.get_money_locat())){     //吃金
            cavas.add_score();
            cavas.update_canvas();
            cavas.draw_snake(snake);
            cavas.set_money();  //画布完成才能判断金子不在蛇上
        }
        //
        //更新画布
        cavas.update_canvas();
        cavas.draw_snake(snake);
    }
    timeout(50000);
    getch();
    endwin();
    return 0;
}
