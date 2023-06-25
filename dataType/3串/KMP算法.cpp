//
// Created by lihaoran on 6/14/23.
//
/**
 *
 * KMP算法实现
 * */
#define MAXLEN 255
typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

// KMP算法实现
// 求模式串t的next函数值并存入数组next
void get_next(SString t, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < t.length) {
        if (j == 0 || t.ch[i] == t.ch[j]) {
            ++i, ++j;
            next[i] = j;
        } else j = next[j];
    }
}

// nextval函数---优化kmp算法
// 求模式串t的next函数修正值并存入数组nextval
void get_nextval(SString t, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < t.length) {
        if (j == 0 || t.ch[i] == t.ch[j]) {
            ++i, ++j;
            if (t.ch[i] != t.ch[j]) nextval[i] = j;
            else nextval[i] = nextval[j];
        } else j = nextval[j];
    }
}



// 利用模式串t的next函数求t在主串s中第pos个字符之后的位置的KMP算法
// 其中，t非空，1<=pos<=StrLength(s)
int index_KMP(SString s, SString t, int pos) {
    int i = pos, j = 1;
    int next[255];
    get_next(t, next);
    while (i <= s.length && j <= t.length) {
        if (j == 0 || s.ch[i] == t.ch[j]) {
            ++i, ++j;
        } else j = next[j];
    }
    if (j > t.length) return i - t.length;
    else return 0;
}
