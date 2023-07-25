//
//  snake.hpp
//  TheSnake
//
//  Created by 匡润龙 on 2023/3/5.
//  Copyright © 2023 匡润龙. All rights reserved.
//

#ifndef snake_hpp
#define snake_hpp


struct loct
{
    int lon_i;
    int wid_i;
};
//坐标

class Snake
{
private:
    char hed_ch;             //头
    char rea_ch;             //身体
    int length0;              //初试长度
    int len_max;           //贪吃蛇最长长度=画布 长*宽 (lon * wid)
    loct *snake;           //snake[len_max]=loct;  (lon_i, wid_i)   蛇坐标
    int head, rear;        //  rear-> ####@ <-head
    //满足先进先出，吃金币；  可以遍历，判断撞身体。
    char orien;              //蛇头方向，即移动方向 d右  s下  a左  w上
    
public:
    Snake();
    int run(const loct &money);
    bool hit_wall(const int &lon, const int &wid);
    bool hit_body();
    bool set_orien(const char &o);
    int begin() const;
    int end() const;
    loct search(const int &i) const;
    char get_head_ch() const;
    char get_rear_ch() const;
    int get_length_max() const;
    ~Snake();//不作为基类
};

#endif /* snake_hpp */
