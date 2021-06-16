//Designed By Dark http://blog.csdn.net/xzongyuan
#ifndef PRINT_TREE_H
#define PRINT_TREE_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"queue.h"
//use breath travel
int print_tree(Tree pRoot,Queue *pQueue);
// ***************0****************  pad_between = 31 ; pad_front = 15  (depth == 1)
// *******0***************0********  pad_between = 15 ; pad_front = 7   (depth == 2)
// ***0*******0*******0*******0****  pad_between = 7  ; pad_front = 3   (depth == 3)
// *0***0***0***0***0***0***0***0**  pad_between = 3  ; pad_front = 1   (depth == 4)
// 0*0*0*0*0*0*0*0*0*0*0*0*0*0*0*0*  pad_between = 1  ; pad_front = 0;  (depth == 5)
// Tree height = 5
// pad_num = 1
// padding between node = (1+2*pad_front)*pad_num = (1+ (1<<(height-depth))-1)*pad_num
 
#endif
