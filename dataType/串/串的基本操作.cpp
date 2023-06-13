//
// Created by lihaoran on 6/13/23.
//

#define MAXLEN 255
typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

/**
 * 求字串
 * @param Sub
 * @param S
 * @param pos
 * @param len
 * @return
 */
bool Substring(SString &Sub, SString S, int pos, int len) {
    // pos是子串的起始位置，len是子串的长度
    // 判断子串的位置是否合法
    if (pos + len - 1 > S.length) {
        return false;
    }
    // 将字串赋值
    for (int i = pos; i < pos + len; i++) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    // 将原有 串的长度进行删减
    Sub.length = len;
    // 返回成功标志
    return true;
}

/**
 * 串的比较
 * @param S
 * @param T
 * @return
 */
int StrCompare(SString S, SString T) {
    // 从第一个字符开始比较
    // 长度小于S,T的交集的长度
    for (int i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            // 减法自动编译为 码值的差
            return S.ch[i] - T.ch[i];
        }
    }
    // 比较完毕，如果长度相等，那么就是相等的
    return S.length - T.length;
}

/**
* 是否包含子串
*/
int Index(SString S, SString T) {
    int i = 1;
    int n = S.length;
    int m = T.length;
    SString sub;
    while (i < n - m + 1) {
        Substring(sub, S, i, m);
        if (StrCompare(sub, T) != 0) ++i;
        else return i;
    }
    return 0;
}

