//
//  snake.cpp
//  TheSnake
//
//  Created by 匡润龙 on 2023/3/5.
//  Copyright © 2023 匡润龙. All rights reserved.
//

#include "snake.hpp"

Snake::Snake()  //初始化贪吃蛇
{
    hed_ch='@';
    rea_ch='#';
    len_max=1000;
    length0=9;
    snake=new loct[len_max];
    //snake[len_max]=loct;  (lon_i, wid_i)
    
    rear=0;
    head=length0-1;
    for(int i=rear;i<=head;i++){
        snake[i].lon_i=i;
        snake[i].wid_i=0;
    }
    orien='d';
}

int Snake::run(const loct &money)
{
    int flag=0;   //1为吃到金子
    //前进
    loct x=snake[head];
    if(orien=='d')
        x.lon_i++;
    else if(orien=='s')
        x.wid_i++;
    else if(orien=='a')
        x.lon_i--;
    else if(orien=='w')
        x.wid_i--;
    //hit_body();
    //hit_wall(x.lon_i, x.wid_i);
    head=(head+1)%len_max;
    snake[head]=x;
    //吃金子
    if(snake[head].wid_i==money.wid_i&&snake[head].lon_i==money.lon_i){
        flag=1;
    }else
        rear=(rear+1)%len_max;
    return flag;
}

bool Snake::set_orien(const char &o)
{
    if(o=='d'&&orien!='a')
        orien=o;
    if(o=='a'&&orien!='d')
        orien=o;
    if(o=='w'&&orien!='s')
        orien=o;
    if(o=='s'&&orien!='w')
        orien=o;
    return true;
}

bool Snake::hit_wall(const int &lon, const int &wid)
{
    bool flag=false;
    loct x=snake[head];
    if(orien=='d')
        x.lon_i++;
    else if(orien=='s')
        x.wid_i++;
    else if(orien=='a')
        x.lon_i--;
    else if(orien=='w')
        x.wid_i--;
    if(x.lon_i>=lon||x.lon_i<0)
        flag=true;
    if(x.wid_i>=wid||x.wid_i<0)
        flag=true;
    return flag;
}

bool Snake::hit_body()
{
    //判断当下是否咬到自己
    int i=rear;
    while (i!=head) {
        if(snake[i].wid_i==snake[head].wid_i&&snake[i].lon_i==snake[head].lon_i)
            return true;
        i=(i+1)%len_max;
    }
    return false;
}

int Snake::begin() const
{
    return rear;
}

int Snake::end() const
{
    return (head+1)%len_max;
}

loct Snake::search(const int &i) const
{
    return snake[i];
}

char Snake::get_head_ch() const
{
    return hed_ch;
}

char Snake::get_rear_ch() const
{
    return rea_ch;
}

int Snake::get_length_max() const
{
    return len_max;
}

Snake::~Snake()
{
    delete [] snake;
}



