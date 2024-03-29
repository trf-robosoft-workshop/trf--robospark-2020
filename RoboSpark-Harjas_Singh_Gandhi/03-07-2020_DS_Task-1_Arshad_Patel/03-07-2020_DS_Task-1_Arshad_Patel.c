#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    char name[20];
    int rollno;
}Student;

typedef struct {
  Student student[10];
  int rear, front;
}Queue;

// function prototypes
void initQueue(Queue *);
void enqueue(Queue *, Student * );
Student dequeue(Queue *);

void initQueue(Queue *qp){
  qp -> front = SIZE - 1;
  qp-> rear = SIZE - 1;
}

void enqueue(Queue *qp, Student *stu){
  if ((qp->rear + 1) % SIZE == qp->front){
    printf("Queue Overflow\n");
    return;
  }
  if ((stu->rollno)%2!=0){
      printf("Told You Only Even Roll No. Allowed\n");
      return;
  }
  qp->rear = (qp->rear + 1) % SIZE;
  qp->student[qp->rear] = *stu;

}

Student dequeue(Queue *qp){
  if (qp->rear == qp->front){ 
    Student a = {"noName",-9999};
    return a;
  }
  qp->front = (qp->front + 1) % SIZE;
  Student a = qp->student[qp->front];
  return a;
}

void menu(){
  printf("----------Operations----------\n");
  printf("-----------------------------------------\n");
  printf("1. Enqueue a student (only even rollno allowed)\n");
  printf("2. Dequeue student\n");
  printf("3. Quit\n");
  printf("-----------------------------------------\n\n");
}

int main() {
  Queue q;
  initQueue(&q);
  int quit = 0;
  Student temp1,temp2;
  menu();
  while(!quit){
    int choice;
    printf("Input your option: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
              printf("First Name\n");
              scanf("%s", &temp1.name);
              printf("Roll No\n");
              scanf("%d",&temp1.rollno);
              enqueue(&q,&temp1);
              break;
      case 2:
              temp2 = dequeue(&q);
              if (temp2.rollno == -9999)
                printf("Queue underflow\n");
              else
                printf("Deleted Student Details Are:\n\tName:%s\n\tRoll No.:%d\n",temp2.name,temp2.rollno);  
              break;
      case 3:
               quit = 1;
               break;
      default: printf("Invalid choice, valid options are 1 2 and 3\n");
    }

  }
  
  return 0;
}
