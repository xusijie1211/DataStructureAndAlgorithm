//Designed By Dark http://blog.csdn.net/xzongyuan
#include "print_tree.h"
#include "build_tree.h"
//use breath travel
int print_tree(Tree pRoot,Queue *pQueue)
{
   int height = get_tree_height(pRoot);
   int pad_num = 2;
   char buf_branch[200]="\n";
   char leaf[10]="oooooooo";
   char vertical[10]="|||||||||";   
   char blank[30]="                             "; 
   //you can cut it down for the branch
   //when I debug, I found the size can't be too large
   //when I set as 50, it break down.
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


