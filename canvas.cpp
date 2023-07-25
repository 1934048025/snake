//
//  canvas.cpp
//  TheSnake
//
//  Created by 匡润龙 on 2023/3/5.
//  Copyright © 2023 匡润龙. All rights reserved.
//

#include <iostream>
#include <ctime>
//#include <unistd.h>
//#include <term.h>
#include <ncurses.h>
#include "canvas.hpp"

Canvas::Canvas()    //初始化画布
{
    lon=50;
    wid=20;
    cav_ch='o';
    moey_ch='$';
    score=0;
    cavas=new char*[wid];
    for(int i=0;i<wid;i++)
        cavas[i]=new char[lon];
    for(int i=0;i<wid;i++)
        for(int j=0;j<lon;j++)
            cavas[i][j]=cav_ch;
}

void Canvas::draw_snake(const Snake &sn)
{
    loct x;
    for(auto i=sn.begin();i!=sn.end();){
        x=sn.search(i);
        cavas[x.wid_i][x.lon_i]=sn.get_rear_ch();
        i=(i+1)%sn.get_length_max();
    }
    cavas[x.wid_i][x.lon_i]=sn.get_head_ch();
}

bool Canvas::set_money()
{
    srand((unsigned int)time(NULL));
    int l, w;
    do{
        l=rand()%lon;
        w=rand()%wid;
    }while(!(cavas[w][l]==cav_ch));
    cavas[w][l]=moey_ch;
    //更新金子的坐标
    money.lon_i=l;
    money.wid_i=w;
    return true;
}

bool Canvas::add_score()
{
    score++;
    return true;
}

void Canvas::update_canvas()
{
    for(int i=0;i<wid;i++)
        for(int j=0;j<lon;j++)
            cavas[i][j]=cav_ch;
    cavas[money.wid_i][money.lon_i]=moey_ch;
}

void Canvas::out_canvas()
{
    //putp( tigetstr( "clear" ) );
    //system("cls");
    //system("clear");
    clear();
    for(int i=0;i<wid;i++){
        for(int j=0;j<lon;j++)
            addch(cavas[i][j]);
        addch('\n');
    }
    printw("Score:      %d\n",score);
    refresh();
}

loct Canvas::get_money_locat()
{
    return money;
}

int Canvas::get_long()
{
    return lon;
}

int Canvas::get_wide()
{
    return wid;
}

void Canvas::game_over()
{
    addstr("GAME OVER!\n");
    refresh();
}

Canvas::~Canvas()
{
    for(int i=0;i<wid;i++)
        delete [] cavas[i];
    delete [] cavas;
}

