//
//  顺序表实现队列.cpp
//  dataType
//
//  Created by lihaoran on 2023/3/7.
//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5 // 定义队列中元素最大个数
typedef struct {
    int data[MaxSize]; // 用敬爱数组存放队列数据
    int front,rear; // 队头指针和队尾指针
    int size;
    int tag;
}SqQueue;

// 初始化队列
void InitQueue(SqQueue &Q){
    // 初始状态，队头对为指针指向0；
    Q.rear = Q.front = 0;
    Q.size = 0;
    Q.tag = 0;
}

// 判断一个队列是否为空
bool QueueEmpty(SqQueue Q){
    // 如果队头指针和队尾指针，指向相同证明是空的
    if (Q.front == Q.rear)
        return true;
    return false ;
}

// 入队操作
bool  EnQueue(SqQueue &Q, int x){
    // 判断队列是否已经满了
    // 这个操作极其重要!
    if (Q.front == (Q.rear+1)%MaxSize) {
        return false;
    }
    Q.data[Q.rear] = x; // 将要插入的值赋值给队列尾部
    Q.rear = (Q.rear+1)%MaxSize; // 尾指针走向下一个
    return true;
}

// 出队操作
bool EdQueue(SqQueue &Q,int &x){
    // 队列为空不能进行出队操作
    if (Q.rear == Q.front) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    return true;
}

// 获取队头元素的值
bool getQuereu(SqQueue S,int &x){
    if (S.front == S.rear) {
        return false;
    }
    x = S.data[S.front];
    return true;
}

// 计算队列元素个数公式：（rear + MaxSize + front）%MaxSize;
// 几种不同的判断空判满的操作
/*  AAAAAA
 初始化 队头队尾处于同一个位置
    1. 队尾指针的下一个是队头指针（牺牲一个存储位置）
    2. 添加size 变量用于计算队列中元素的个数，进队操作size++，出队操作size--，如果size == MaxSize队满，否则队空
    3. 添加tag标签，如果进队tag=1出队tag=0
        a. 如果rear == front 并且tag为1，则是队满
        b. 如果rear == front 并且tag=0，则是队空
 实现代码如下：
 */
// A-1.判断为空
void reatFrontIdenticalEmpty1(SqQueue &S,int &x){
    if(S.rear == S.front){
        printf("A-1为空，不能出队了\n");
        return;
    }else {
        x = S.data[S.front];
        S.front = (S.front+1)%MaxSize;
        printf("A-1取出成功：%d\n",x);
        
    }
    
}
// A-1.判断为满
void reatFrontIdenticalNotEmpty1(SqQueue &S, int x){
    if ((S.rear+1)%MaxSize == S.front){
        printf("A-1为满，不能入队了\n");
        return;
    }else {
        printf("A-1放入成功：%d\n",x);
    }

    S.data[S.rear] = x;
    S.rear = (S.rear+1)%MaxSize;
}

// A-2.判断为空
void reatFrontIdenticalEmpty2(SqQueue &S,int &x){
    if(S.size == 0){
        printf("A-2为空，不能出队了\n");
        return;
    }else {
        x = S.data[S.front];
        S.front = (S.front+1)%MaxSize;
        S.size--;

        printf("A-2取出成功：%d\n",x);
    }

}
// A-2.判断为满
void reatFrontIdenticalNotEmpty2(SqQueue &S, int x){
    if (S.size == MaxSize){
        printf("A-2为满，不能入队了\n");
        return;
    }else {
        printf("A-2放入成功：%d\n",x);
        
    }

    S.data[S.rear] = x;
    S.rear = (S.rear+1)%MaxSize;
    S.size++;
}

// A-3.判断为空
void reatFrontIdenticalEmpty3(SqQueue &S,int &x){
    if(S.rear == S.front && S.tag == 0){
        printf("A-3为空，不能出队了\n");
        return;
    }else {
        x = S.data[S.front];
        S.front = (S.front+1)%MaxSize;
        S.tag = 0;
        printf("A-3取出成功：%d\n",x);
    }
}
// A-3.判断为满
void reatFrontIdenticalNotEmpty3(SqQueue &S, int x){
    if (S.rear == S.front && S.tag == 1){
        printf("A-3为满，不能入队了\n");
        return;
    }else {
        printf("A-3放入成功：%d\n",x);
        
    }

    S.data[S.rear] = x;
    S.rear = (S.rear+1)%MaxSize;
    S.tag=1;
}

void reatFrontIdenticalTest(){
    SqQueue s;
    int x ;
    InitQueue(s);
    // A-1
    reatFrontIdenticalNotEmpty1(s,1);
    reatFrontIdenticalNotEmpty1(s,1);
    reatFrontIdenticalNotEmpty1(s,1);
    reatFrontIdenticalNotEmpty1(s,1);
    reatFrontIdenticalNotEmpty1(s,1);
    reatFrontIdenticalEmpty1(s,x);
    reatFrontIdenticalEmpty1(s,x);
    reatFrontIdenticalEmpty1(s,x);
    reatFrontIdenticalEmpty1(s,x);
    reatFrontIdenticalEmpty1(s,x);
    // A-2
    int b ;
    SqQueue a2;
    InitQueue(a2);
    reatFrontIdenticalNotEmpty2(a2,1);
    reatFrontIdenticalNotEmpty2(a2,1);
    reatFrontIdenticalNotEmpty2(a2,1);
    reatFrontIdenticalNotEmpty2(a2,1);
    reatFrontIdenticalNotEmpty2(a2,1);
    reatFrontIdenticalNotEmpty2(a2,1);
    reatFrontIdenticalEmpty2(a2,b);
    reatFrontIdenticalEmpty2(a2,b);
    reatFrontIdenticalEmpty2(a2,b);
    reatFrontIdenticalEmpty2(a2,b);
    reatFrontIdenticalEmpty2(a2,b);
    reatFrontIdenticalEmpty2(a2,b);
    // A-3
    int c;
    SqQueue a3;
    InitQueue(a3);
    reatFrontIdenticalNotEmpty3(a3,1);
    reatFrontIdenticalNotEmpty3(a3,1);
    reatFrontIdenticalNotEmpty3(a3,1);
    reatFrontIdenticalNotEmpty3(a3,1);
    reatFrontIdenticalNotEmpty3(a3,1);
    reatFrontIdenticalNotEmpty3(a3,1);

    reatFrontIdenticalEmpty3(a3,c);
    reatFrontIdenticalEmpty3(a3,c);
    reatFrontIdenticalEmpty3(a3,c);
    reatFrontIdenticalEmpty3(a3,c);
    reatFrontIdenticalEmpty3(a3,c);
    reatFrontIdenticalEmpty3(a3,c);
    
}


/* BBBBB
 初始化 队尾 ，位于队头的前一个位置（rear 指向了队尾的前一个元素）
    1. rear元素的下一个元素为front，则是空队列
    2. rear元素的下一个的下一个元素为front，则是满队列
    3. 添加size，变量用于计算队列中元素的个数，进队操作size++，出队操作size--，如果size == MaxSize队满，否则队空
    4. 添加tag标签，如果进队tag=1出队tag=0
        a. 如果reat的下一个为front并且tag==1 则是队列满
        b. 如果reat的下一个为front并且tag==0 则是队列空
 实现代码如下
 */
// B---inti

void initRearFornt(SqQueue &s){
    s.front = 0;
    s.rear = MaxSize-1;
    s.size = 0;
    s.tag = 0;
}
// B-1.判断为空
void reatFrontEmpty1(SqQueue &S,int &x){
    if((S.rear+1)%MaxSize == S.front){
        printf("B-1为空，不能出队了\n");
        return;
    }else {
        x = S.data[S.front];
        S.front = (S.front+1)%MaxSize;
        printf("B-1取出成功：%d\n",x);
        
    }
    
}
// B-1.判断为满
void reatFrontNotEmpty1(SqQueue &S, int x){
    if ((S.rear+2)%MaxSize == S.front){
        printf("B-1为满，不能入队了\n");
        return;
    }else {
        printf("B-1放入成功：%d\n",x);
    }
    S.rear = (S.rear+1)%MaxSize;
    S.data[S.rear] = x;
    
}

// B-2.判断为空
void reatFrontEmpty2(SqQueue &S,int &x){
    if(S.size == 0){
        printf("B-2为空，不能出队了\n");
        return;
    }else {
        x = S.data[S.front];
        S.front = (S.front+1)%MaxSize;
        S.size--;

        printf("B-2取出成功：%d\n",x);
    }

}
// B-2.判断为满
void reatFrontNotEmpty2(SqQueue &S, int x){
    if (S.size == MaxSize){
        printf("B-2为满，不能入队了\n");
        return;
    }else {
        printf("B-2放入成功：%d\n",x);
        
    }
    S.rear = (S.rear+1)%MaxSize;
    S.data[S.rear] = x;

    S.size++;
}

// B-3.判断为空
void reatFrontEmpty3(SqQueue &S,int &x){
    if((S.rear+1)%MaxSize == S.front && S.tag == 0){
        printf("B-3为空，不能出队了\n");
        return;
    }else {
        x = S.data[S.front];
        S.front = (S.front+1)%MaxSize;
        S.tag = 0;
        printf("B-3取出成功：%d\n",x);
    }
}
// B-3.判断为满
void reatFrontNotEmpty3(SqQueue &S, int x){
    if ((S.rear+1)%MaxSize == S.front && S.tag == 1){
        printf("B-3为满，不能入队了\n");
        return;
    }else {
        printf("B-3放入成功：%d\n",x);
        
    }
    S.rear = (S.rear+1)%MaxSize;
    S.data[S.rear] = x;
    S.tag=1;
}

void reatFrontTest(){
    SqQueue s;
    int x ;
    initRearFornt(s);
    // B-1
    reatFrontNotEmpty1(s,1);
    reatFrontNotEmpty1(s,1);
    reatFrontNotEmpty1(s,1);
    reatFrontNotEmpty1(s,1);
    reatFrontNotEmpty1(s,1);
    reatFrontEmpty1(s,x);
    reatFrontEmpty1(s,x);
    reatFrontEmpty1(s,x);
    reatFrontEmpty1(s,x);
    reatFrontEmpty1(s,x);
    // B-2
    int b ;
    SqQueue a2;
    initRearFornt(a2);
    reatFrontNotEmpty2(a2,1);
    reatFrontNotEmpty2(a2,1);
    reatFrontNotEmpty2(a2,1);
    reatFrontNotEmpty2(a2,1);
    reatFrontNotEmpty2(a2,1);
    reatFrontNotEmpty2(a2,1);
    reatFrontEmpty2(a2,b);
    reatFrontEmpty2(a2,b);
    reatFrontEmpty2(a2,b);
    reatFrontEmpty2(a2,b);
    reatFrontEmpty2(a2,b);
    reatFrontEmpty2(a2,b);
    

    // B-3
    int c;
    SqQueue a3;
    initRearFornt(a3);
    reatFrontNotEmpty3(a3,1);
    reatFrontNotEmpty3(a3,1);
    reatFrontNotEmpty3(a3,1);
    reatFrontNotEmpty3(a3,1);
    reatFrontNotEmpty3(a3,1);
    reatFrontNotEmpty3(a3,1);


    reatFrontEmpty3(a3,c);
    reatFrontEmpty3(a3,c);
    reatFrontEmpty3(a3,c);
    reatFrontEmpty3(a3,c);
    reatFrontEmpty3(a3,c);
    reatFrontEmpty3(a3,c);

    
}

int main(){
    reatFrontIdenticalTest();
    reatFrontTest();
}



