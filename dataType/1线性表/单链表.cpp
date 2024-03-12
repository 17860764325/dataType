#include <stdio.h>
#include <stdlib.h>

// 定义一个单链表
// struct 是定义一种结构体
// typedef 命别名
// 这是一个单链表的一个节点
typedef struct LNode{
    int data; // 该节点的数据
    struct LNode *next; // 该节点的下一个节点
}LNode, *LinkList;

// 初始化一个单链表
bool InitList( LinkList &L){
    L = (LNode *)malloc(sizeof(LNode)); // 声名一个头节点
    if(L == NULL)
        return  false;;// 声明失败，内存不足
    L->next = NULL; // 头节点后边还暂时没有其他的节点，所以暂时放一个null
    return true;
}

// 单链表的判断空操作 （带头节点）
bool Empty(LinkList L){
    if(L -> next == NULL)
        return true;
    else
        return false;
}

// 按位查找
LNode * GetElem(LinkList L, int i){
    if (i < 0) {
        return NULL;
    }
        LNode * p;// 指针p指向当前扫描到的节点
        int j = 0;// 当前p指向的是第几个节点 如果带头节点那就是0 不带是1
        p = L;// p指向头节点，头节点不包含数据
        // 循环找到i-1个节点
        while(p!=NULL&&j<i-1){
            p = p -> next;
            j++;
        }
    return p;
}

// 按值查找
LNode * LocateElem(LinkList L,int e){
    LNode *p = L->next;
    while (p != NULL && p->data!=e)
        p = p->next;
    
    return p;
}

// 求一个单链表的长度（带头节点）
int ListLength(LinkList L){
    int Len = 0;
    LNode *p = L;
    while (p -> next != NULL) {
        p = p->next;
        Len++;
    }
    return Len;
}

// 求一个单链表的长度（不带头节点）
int ListLengthWithHead(LinkList L){
    int Len = 0;
    LNode *p = L;
    while (1) {
        Len++;
        if(p -> next == NULL){
            break;
        }
        p = p->next;
    }
    return Len;
}

// 实现后插操作，在某一个节点后插入一个
bool InsertNextNode(LNode *p, int e ){
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;// 内存不足
    }
    s->data = e; // 保存e数据
    s->next = p->next;
    p->next = s; // 将节点s保存到p节点后
    return true;
}

// 单链表的插入（在第i个位置插入元素e）（带头节点）
bool ListInsert(LinkList &L,int i ,int e){
    if(i < 1)
        return false ;
    // 找到 i-1个节点
    LNode *p =GetElem(L,i-1);
    // 在i-1节点后插入一个节点
    return InsertNextNode(p,e);
}

// 单链表插入操作（不带头节点）插入在其他位置的方法还是一样的，但是插入在第一个节点需要特殊的处理。
bool ListInsertWithoutHead(LinkList &L,int i ,int e){
    if(i < 1)
        return false ;
    // 判断如果对第一个元素进行操作
    if (i == 1 ) {
        LNode * f = (LNode *)malloc(sizeof(LNode));
        // 赋值新数据
        f->data = e;
        // 让f变成L的第一个节点
        f->next = L;
        // 让f变成L的第一个节点
        L = f;
        return true;
    }
    // 找到 i-1个节点
    LNode *p =GetElem(L,i-1);
    if (p==NULL) // i值不合法，i值太大
        return false;
    // 给要插入的值申请内存空间
    LNode * s = (LNode * ) malloc(sizeof(LNode));
    // 新节点的值
    s -> data = e;
    // 新节点的指向变更
    s -> next = p -> next;
    // 旧节点的指向变更
    p -> next = s;
    return true;
}

// 实现前插操作，在指定节点前插入一个数据。
bool InsertBeforeNode(LNode *p , int e){
    if(p ==NULL){
        return false;
    }
    // 声明一片空间
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 内存不够情况
    if (s == NULL) {
        return false ;
    }
    // 将新申请的s节点先放在p节点的后边
    s->next = p->next;
    p->next = s;
    // 将p的值给s
    s->data = p->data;
    // 将s的值给p
    p->data = e;
    // 完成前插
    return true;
}

// 单链表的删除操作
int ListDelete(LinkList &L, int i, int &e){
    // 判断参数是否合法？
    if (i < 0) {
        return false;
    }
    // 查找要删除的节点的前一节点
    LNode *p = GetElem(L,i);
    // i 不合法
    if (p == NULL) {
        return false ;
    }
    // i-1个节点后已经没有节点了
    if (p->next == NULL) {
        return false;
    }
    LNode *s = p->next;
    e = s->data;
    p->next = s->next;
    free(s);
    return true;
}

// 单链表删除某一个节点
bool ListDeleteBeforeNode(LNode *p,int &e){
    if (p ==NULL) {
        return false;
    }
    LNode *s = p -> next;
    e = p->data;
    p->data = s->data;
    p->next = s->next;
    free(s);
    return true;
}

// 打印单链表操作
void PrintList(LinkList L){
    LNode * p;
    int j = 0;
    p = L;
    while(true)
    {
        j++;
//        // 带头节点的话，不打印头节点
//        if (j != 1) {
//            printf("%d\n",p->data);
//        }
        printf("%d\n",p->data);
        // 如果是最后一个节点就不往下循环了
        if (p->next==NULL) {
            break;
        }
        p = p ->next;
    }
    
}

// 单链表的建立
// 头插法和尾插法
// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    int x; // 设置一个整数值
    L = (LNode * )malloc(sizeof(LNode)); // 申请一个内存空间，作为头节点
    LNode *s , *r = L; // r作为表尾指针
    scanf("%d",&x); // 输入想存储的值（第一次）
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode)); //申请一个新的节点
        s -> data = x; // 让新的节点的数据为输入的x
        r->next = s; // 让尾节点r指向s
        r = s; // 让r变成新加一个元素后的最后一个节点，让r=s
        scanf("%d",&x); // 继续输入
    }
    r->next = NULL; // 添加完毕后，将尾节点指向NULL
    return L;
}

// 头插法建立单链表 ----可用于链表的逆置
LinkList List_HeadInsert(LinkList &L){
    LNode * s;
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L -> next = NULL; // 因为要进行头插，所以做后一个元素的后边不会动，所以第一次初始化要进行清空，以防止有脏数据
    scanf("%d",&x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}

/*
 * 头插法 有头结点
 */
LinkList HeadInster(LinkList &L,int n){
    LNode *s;
    int x=1;
    L= (LinkList)malloc(sizeof(LNode));     //创建头结点
    L->next=NULL;                                //初始为空链表
    while(x!=n){
        s=(LNode*) malloc(sizeof(LNode));   //创建新结点
        s->data=x;
        s->next=L->next;
        L->next=s;
        x++;
    }
    return L;
}

/*
 * 头插法 没有头结点
 */
LinkList Headinster(LinkList &L,int n){
    LNode *s;
    int x=1;
    L= (LinkList)malloc(sizeof(LNode));
    L->data=x++;// L->data的值等于初始的x然后x的值再进行++，相当于对无节点的链表的插入第一个元素进行操作！
    L->next=NULL;
    while(x!=n){
        s=(LNode*) malloc(sizeof(LNode));
        s->data=x;
        s->next=L;
        L=s;
        x++;
    }
    return L;
}

/*
 * 尾插法、有结点
 */
LinkList TailInster(LinkList &L,int n){
    int x=1;
    L= (LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    while(x!=n){
        s=(LNode*) malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        x++;
    }
    r->next=NULL;
    return L;
}
/*
 * 尾插法、没有结点
 */
LinkList Tailinster(LinkList &L,int n){
    int x=1;
    L= (LinkList)malloc(sizeof(LNode));
    L->data=x++;
    LNode *s,*r=L;
    while(x!=n){
        s=(LNode*) malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        x++;
    }
    r->next=NULL;
    return L;
}


/*
 * 便利链表、头结点
 */
void PrintListInsert(LinkList L){
    LNode *s;
    s=L->next;
    while (s!=NULL) {
        printf("%d\t",s->data);
        s=s->next;
    }
}

/*
 * 便利链表、没有头节点
 */
void Print(LinkList L){
    LNode *s;
    s=L;
    while (s!=NULL) {
        printf("%d\t",s->data);
        s=s->next;
    }
}

// 有无头节点链表头插尾插法
int testInsert(){
    LinkList L,S,P,Q;
    printf("有头结点的头插法：");
    HeadInster(L,10);
    PrintListInsert(L);

    printf("\n无头结点的头插法：");
    Headinster(P,10);
    Print(P);
    
    printf("\n有头结点的尾插法：");
    Tailinster(S,10);
    Print(S);

    printf("\n无头结点的尾插法：");
    Tailinster(Q,10);
    Print(Q);
    return 0;
}
 
// 链表增删改查
void test(){
    LinkList L;         //声明一个指向单链表的指针
//    //初始化一个空表
//    InitList(L);
//    // 插入一个值
//    ListInsert(L, 1, 1);
//    ListInsert(L, 2, 2);
//    ListInsert(L, 3, 3);
//    ListInsert(L, 4, 4);
//    // 删除一个节点
//    int e = 1;
//    ListDelete(L, 3, e);
//    // 获取指定位置的节点
//    int i = 3;
//    printf("第%d元素是:%d\n",i,GetElem(L,i)->data);
//    int j =2;
//    printf("第%d元素是:%d\n",j,GetElem(L,j)->data);
//    int k = 2;
//    printf("值为%d元素是:%d\n",k,LocateElem(L,k)->data);
//    printf("单链表带头节点的长度是是:%d\n",ListLength(L));
//    printf("单链表不带头节点的长度是是:%d\n",ListLengthWithHead(L));
//    List_TailInsert(L);
    List_HeadInsert(L);
    PrintList(L);
}

/// 作业，给你一个单链表，你实现逆置
void homeWork(LinkList &L){
    // 有头节点
    // 插入数据,
    TailInster(L,10);
    // 进行逆转
    PrintListInsert(L);
    printf("\n");
    LNode *s,*p;
    p=L->next;
    L->next = NULL;
    while (p) {
        s = p->next;
        p -> next = L -> next;
        L->next = p;
        p = s;
    }
    PrintListInsert(L);
    printf("\n");
}

/// 另一种方法实现原地逆转，使用头插法，重新将单链表插入一遍

void function(LinkList &l){
    LNode *p,*q; /// 创建两个变量
    p = l->next;
    l->next = NULL; /// 先将链表断开
    while(p!=NULL){ /// 头插法进行插入
        q = p;
        q->next = l->next  ;
        l ->next = q;
        p=p->next;
    }
}


LinkList HomeWorkInsert(LinkList &L,int x ,int n){
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *p ,*s;
    s = L;
    while (x<n) {
        x++;
        p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        p->next = NULL;
        s->next = p;
        s=p;
    }
    return L;
}

//LinkList homeWorkComBinLinkList(LinkList &L1,LinkList L2){
//    LNode *p ,*s,*r;
//    p = L2;
//    s = L1->next;
//    r = NULL;
//    while (p) {
//        p->next = s;
//        L1 ->next = p;
//
//        p=p->next;
//    }
//    return L1;
//}

// 逆转
LinkList nizhuan(LinkList &L){
    LNode *p,*s;
    p = L->next;
    L ->next = NULL;
    while (p) {
        s = p->next;
        p->next = L->next;
        L->next = p;
        p = s ;
    }
    return L;
}


// 合并两个正序单链表，并做倒序处理
void homeWork2(){
    
    LinkList L1;// 1234
    LinkList L2;// 5678
    // 给两个正序的单链表进行插入操作赋值
    HomeWorkInsert(L1,0,4);
    HomeWorkInsert(L2,4,8);
    printf("逆转前:\n");
    printf("L1:");
    PrintListInsert(L1);
    printf("\n");
    printf("L2:{");
    PrintListInsert(L2);
    
//    // 进行合并
//    homeWorkComBinLinkList(L1,L2);
//    printf("\n");
//    PrintListInsert(L1);
    
    // 进行逆转
    printf("\n");
    printf("逆转后\n");
    nizhuan(L1);
    printf("L1:");
    PrintListInsert(L1);
    printf("\n");
    nizhuan(L2);
    printf("L2:");
    PrintListInsert(L2);
    
}


//
//int main(){
////    testInsert();
////    testCMake();
////    LinkList L;
//    homeWork2();
//}
/*
 有无头节点：
 有头：L[0(头)->1->2->3->4] L->next = 1;
 无:L[1->2->3->4] L->next = 2;

 */
