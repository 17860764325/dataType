//
// Created by lihaoran on 2024/1/16.
//

#include "dataTypeWork/floyd佛洛依德算法求最短路径.h"

void floyd佛洛依德算法求最短路径::Floyd(int n) {
    for (int k = 0; k < n; k++) { /// 考虑以Vk作为中转点
        for (int i = 0; i < n; ++i) { /// 遍历整个矩阵i为行号，j为列号
            for (int j = 0; j < n; ++j) {
                if (A[i][j] > A[i][k] + A[k][j]) { /// 若是以Vk作为中转点的路径更短
                    A[i][j] = A[i][k] + A[k][j]; /// 更新最短路径长度
                    path[i][j] = k; /// 更新中转点
                }
            }
        }
    }
}