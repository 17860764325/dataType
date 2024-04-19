//
// Created by lihaoran on 2024-04-18.
//

#include "../../headSpace/dataTypeWork/满二叉树知前序得后序.h"

void 满二叉树知前序得后序::PreToPost(char *pre, char *post, int l1, int h1, int l2, int h2) {
    int half;
    if (h1>=l1){
        post[h2] = pre[l1];
        half = (h1-l1)/2;
        PreToPost(pre,post,l1+1,l1+half,l2,l2=half-1);
        PreToPost(pre,post,l1+half+1,h1,l2+half,h2-1);
    }
}

int main(){
    char pre[] = {'A','B','D','E','C','F','G'},post[7];
    满二叉树知前序得后序 a;
    a.PreToPost(pre,post,0,6,0,6);
    for (int i = 0; i < 7; ++i) {
        std::cout<< post[i];
    }
}
