#include<stdio.h>
int solvesudoko(int,int) ;
void printsudoko(void) ;
int same(int,int,int) ;
int sameRow(int,int,int) ;
int sameColumn(int,int,int)  ;

int sudoko[9][9] = {0,0,0, 0,0,3, 2,9,0,
			 0,8,6, 5,0,0, 0,0,0,
			 0,2,0, 0,0,1, 0,0,0,
			 0,0,3, 7,0,5, 1,0,0,
			 9,0,0, 0,0,0, 0,0,8,
			 0,0,2, 9,0,8, 3,0,0,
			 0,0,0, 4,0,0, 0,8,0,
			 0,4,7, 1,0,0, 0,0,0};

int main( ){

 int x=0 ;
 int y=0 ;

 solvesudoko(x,y) ;
 printsudoko( ) ;

}

int solvesudoko(int x,int y){
  int num=1 ;
  int tx=0 ;
  int ty=0 ;
 if(sudoko[x][y]!=0){

    if(x==8 && y==8){
        return 1 ;
    }

  if(x<8){
    x++ ;
  }
  else{
    x=0 ;
    y++ ;
  }

  if(solvesudoko(x,y)){
    return 1 ;
  }
  else{
    return 0 ;
  }
 }

 if(sudoko[x][y]==0)
 {
     while(num<10){
        if(!same(x,y,num)&& !sameRow(x,y,num)&& !sameColumn(x,y,num)){
            sudoko[x][y]=num ;

        if(x==8 && y==8){
            return 1 ;
        }

        if(x<8){
            tx=x+1 ;
        }
        else{
          tx=0 ;
          ty=y+1 ;

        }

        if(solvesudoko(x,y)){
            return 1 ;
        }


      }
     num++ ;

 }
 sudoko[x][y]=0 ;
 return 0 ;
}



}

int sameColumn(int x,int y,int num){


for(int i=0;i<9;i++)
{

      if(sudoko[x][i]==num){
        return 1 ;
      }
}
return 0 ;

}



int sameRow(int x,int y,int num){


for(int i=0;i<9;i++)
{

      if(sudoko[i][y]==num){
        return 1 ;
      }
}
return 0 ;

}

int same(int x,int y,int num){
int a,b ;
if(x<3){
 a=0 ;
}
else if(x<6){
 a=3 ;
}
else{
 a=6 ;
}

if(y<3){
 b=0 ;
}
else if(y<6){
 b=3 ;
}
else{
 b=6 ;
}


for(int i=a;i<a+3;i++)
{
   for(int j=b;j<b+3;j++){
    if(sudoko[i][j]==num){

        return 1 ;

      }
    }
}

return 0 ;


}





void printsudoko(){

 for(int i=0;i<9;i++){

    for(int j=0;j<9;j++){


       printf("%d ",sudoko[i][j]) ;


    }
    printf("\n") ;
 }




}













