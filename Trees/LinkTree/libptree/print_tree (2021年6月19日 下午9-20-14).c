#include <stdio.h>    
#include <string.h>
#include <ctype.h>      
#include <stdlib.h>   
#include <math.h>  
#include <time.h>
#include <sort.h>
#include <Trees/LinkTree.h>

int get_tree_height(BiTree T)
{
  int lh = 0,rh = 0;

  if (!T) {
    return 0; 
  }

  lh = get_tree_height(T->lchild);
  rh = get_tree_height(T->rchild);

  return (lh<rh)?(rh+1):(lh+1);
}

int breath_travel(BiTree pRoot,Queue *pQueue)
{
   int height = get_tree_height(pRoot);
   int pad_num = 2;
   char buf_branch[200]="\n";
   char leaf[10]="oooooooo";
   char vertical[10]="|||||||||";   
   char blank[30]="                             "; 
   //you can cut it down for the branch
   //when I debug, I found the size can't be too large
   //when I set it as 50, it break down.
   char line[30]="______________________________"; 


   //compare to the node's depth in the "while loop"
   int current_depth = 1;
   if(!pRoot)
   {
      return 0;
   }      
   
   enQueue(pQueue,pRoot,1);
   printf("_______________________\n");
   printf("breath begin,enter root:\n");

   while(ifEmpty(pQueue)!=0)
   {

     QNode  *qNode  = deQueue(pQueue);
     //the sub node's depth is 1 more then the parent's
     int child_depth = qNode->depth+1; 

     if(qNode->depth > current_depth)
     {
         current_depth = qNode->depth;
         printf("%s\n",buf_branch);
         sprintf(buf_branch,"\n");  //reset the buffer after print
     }
// ***************0****************  pad_between = 31 ; pad_front = 15  (depth == 1)
// *******0***************0********  pad_between = 15 ; pad_front = 7   (depth == 2)
// ***0*******0*******0*******0****  pad_between = 7  ; pad_front = 3   (depth == 3)
// *0***0***0***0***0***0***0***0**  pad_between = 3  ; pad_front = 1   (depth == 4)
// 0*0*0*0*0*0*0*0*0*0*0*0*0*0*0*0*  pad_between = 1  ; pad_front = 0;  (depth == 5)
// Tree height = 5
// pad_num = 1
// padding between node = (1+2*pad_front)*pad_num = (1+ (1<<(height-depth))-1)*pad_num
    
     int pad_front = (1<< (height - current_depth))-1;
     int pad_blank = (pad_front-1)>>1;
     int pad_under = (pad_front+1)>>1;

     if((qNode->blank == 1))
     {
       //add the parent node's padding:2
        if(pad_front == 0)    printf("%.*s%*s",pad_num,leaf,pad_num," ");

        else              
            {
             printf("%*s%.*s%*s",pad_front*pad_num," ",pad_num,leaf,(1+pad_front)*pad_num," ");
             char *new_buf=(char*)malloc(100);
	     char *old_buf = buf_branch;
            
             sprintf(new_buf,"%.*s%.*s%.*s%.*s%.*s",pad_num*pad_blank,blank,pad_num*pad_under,line,pad_num,vertical,pad_num*pad_under,line,(pad_front-pad_blank)*pad_num,blank);
	     sprintf(buf_branch,"%s%s",old_buf,new_buf);
 	    }
       if(child_depth<=height)
       {
         //enter two NULL sub-tree node.
         //every time you enter NULL TNode,there's corresponding blank QNode.
         enQueue(pQueue,NULL,child_depth);
         enQueue(pQueue,NULL,child_depth);
       }
     }
     else
     {
        if(pad_front == 0)   
            {
              printf("%*d%*s",pad_num,qNode->t_node->value,pad_num," ");
	    }
        else  
            {

               char *new_buf=(char*)malloc(100);
               char *old_buf=buf_branch;
               printf("%*s%*d%*s",pad_front*pad_num," ",pad_num,qNode->t_node->value,(1+pad_front)*pad_num," ");
               sprintf(new_buf,"%.*s%.*s%.*s%.*s%.*s",pad_num*pad_blank,blank,pad_num*pad_under,line,pad_num,vertical,pad_num*pad_under,line,(pad_front-pad_blank)*pad_num,blank);
	       sprintf(buf_branch,"%s%s",old_buf,new_buf);
            }
       if(child_depth <=height)
       {
	 enQueue(pQueue,qNode->t_node->left,child_depth);
         enQueue(pQueue,qNode->t_node->right,child_depth); 
       } 
     }

   } //while end   
     printf("\n-----------\nbreath end!\n-----------\n");

   return 1;
}