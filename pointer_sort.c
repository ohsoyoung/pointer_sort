#include <stdio.h>
#include <stdlib.h>

void rank_fun(int *score, int *rank);
void print_result(int *id, int *score, char *grade, int *rank);
void print_result2(int *id, int *score, char *grade, int *rank);
void grade_fun(int *rank, char *grade);

int main(void){  
  //각 포인터변수들은 10개씩 공간을 가지도록 동적할당 해줌  
  int *id = (int *)malloc(sizeof(int) * 10); //학번을 저장하기 위한 변수  
  int *score = (int *)malloc(sizeof(int) * 10); //점수를 저장하기 위한 변수  
  int *rank = (int *)malloc(sizeof(int) * 10); //등수를 저장하기 위한 변수  
  char *grade = (char *)malloc(sizeof(int) * 10); //학점을 저장하기 위한 변수  
  int temp, temp2, min, max;  int i, j; //for문을 돌리기 위한 변수

  for(i = 0; i < 10; i++)  { 
    printf("4자리 학번을 입력하세요:"); 
    scanf("%d", (id+i)); 
    
    while(!(*(id+i) >= 1000 && *(id+i) <= 9999)) //4자리수가 아니면 다시 입력 {   
      printf("다시 입력해주세요:");   
      scanf("%d", (id+i)); 
    }
    
    fflush(stdin);
    
    printf("점수를 입력하세요:"); 
    scanf("%d", (score+i)); 
    
    while(!(*(score+i) >=0 && *(score+i) <= 100)) //0~100의 수가 아니면 다시 입력  {   
      printf("다시 입력해주세요:");   
      scanf("%d", (score+i)); 
    }
  }
  
  for(i = 0; i < 9; i++) //(1)수학점수기준 오름차순으로 정렬하는 반복문  { 
    min = i;
    
    for(j = i + 1; j < 10; j++) {   
      if(*(score+j) < *(score+min))  
        min = j;//제일 작은 수학점수의 순서를 min에 저장 
    }
    
    //수학점수를 오름차순으로 정렬 
    temp = *(score+i); 
    *(score+i) = *(score+min); 
    *(score+min) = temp;
 
    //학번도 같은 순서대로 정렬 
    temp2 = *(id+i); 
    *(id+i) = *(id+min); 
    *(id+min) = temp2;  
  }
  
  rank_fun(score, rank); //등수를 계산하기 위한 함수  
  grade_fun(rank, grade); //학점을 계산하기 위한 함수  
  print_result(rank, id, grade, score); //(1)번의 최종결과를 출력하기 위한 함수
  
  for(i = 0; i < 9; i++) //(2)학번기준 오름차순으로 정렬하는 반복문  
  {
    min = i;
    
    for(j = i + 1; j < 10; j++) {   
      if(*(id+j) < *(id+min))  
        min = j;//제일 작은 학번의 순서를 min에 저장 
    }
 
    //학번을 오름차순으로 정렬 
    temp = *(id+i); 
    *(id+i) = *(id+min); 
    *(id+min) = temp;
    
    //학번에 맞게 점수도 같은 순서대로 정렬 
    temp2 = *(score+i); 
    *(score+i) = *(score+min); 
    *(score+min) = temp2;  
  }
  
  rank_fun(score, rank); //등수를 계산하기 위한 함수  
  grade_fun(rank, grade); //학점을 계산하기 위한 함수  
  print_result2(rank, id, grade, score); //(2)번의 최종결과를 출력하기 위한 함수  
  
  return 0;
}

//등수를 계산하기 위한 함수
void rank_fun(int *score, int *rank)
{  
  int i, j;  
  
  for(i = 0; i < 10; i++)  { 
    *(rank+i) = 1; 
    
    for(j = 0; j < 10; j++) {   
      if(*(score+i) < *(score+j))  
      *(rank+i) = *(rank+i) + 1; 
    }  
  }
}

//학점을 계산하기 위한 함수
void grade_fun(int *rank, char *grade) 
{  
  int i;  
  
  for(i = 0; i < 10; i++)  { 
    if(*(rank+i) == 1 || *(rank+i) == 2)   
      *(grade+i) = 'A'; 
    else if(*(rank+i) == 3 || *(rank+i) == 4)   
      *(grade+i) = 'B'; 
    else if(*(rank+i) == 5 || *(rank+i) == 6 || *(rank+i) == 7)   
      *(grade+i) = 'C'; 
    else if(*(rank+i) == 8 || *(rank+i) == 9)   
      *(grade+i) = 'D'; 
    else   
      *(grade+i) = 'F';  
  }
}

//(1)번의 최종결과를 출력하기 위한 함수 (석차, 학번, 학점, 점수 순)
void print_result(int *rank, int *id, char *grade, int *score)
{ 
  int i; 
    printf("(1) 수학점수 기준 오름차순정렬\n"); 
    printf("석차, 학번, 수학점수, 학점\n"); 
    
    for(i = 0; i < 10; i++)  
      printf("%d\t%d\t%d\t%c\n", *(rank+i), *(id+i), *(score+i), *(grade+i));
}

//(2)번의 최종결과를 출력하기 위한 함수 (학번, 점수, 학점, 석차 순)
void print_result2(int *rank, int *id, char *grade, int *score)
{ 
  int i; 
    printf("(2) 학번 기준 오름차순정렬\n"); 
    printf("학번, 수학점수, 학점, 석차\n"); 
    
    for(i = 0; i < 10; i++)   
      printf("%d\t%d\t%c\t%d\n", *(id+i), *(score+i), *(grade+i), *(rank+i));
}
