//
// Created by lihaoran on 6/13/23.
//
// 定长的数据存储
#define MAXLEN 255 // 串的最大长度
typedef struct {
    char ch[MAXLEN]; // 每个分量存储一个字符
    int length; // 串的实际长度
} SString;

// 朴素匹配算法
int index(SString s, SString t) {
    int i, j = 1;
    while (i <= s.length && j <= t.length) {
        if (s.ch[i] == t.ch[i]) {
            i++, j++; // 匹配成功继续比较后续字符
        } else {
            i = i - j + 2;
            j = 1;// 指针后退重新开始匹配
        }
    }
    if (j > t.length) return i - t.length;
    else return 0;
}