#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int N = 110000 * 35;

int ch[N][2], sum[N], tot = 1;

#define walk for(int i = 31, t, rt = 1 ; (t = (val >> i) & 1), ~i ; i --)

void ins(int val, int c = 1) {
    walk {
        if(ch[rt][t] == 0) ch[rt][t] = ++ tot;
        sum[rt = ch[rt][t]] += c;
    }
}

int kth(int val, int ret = 0) {
    walk {
        if(val > sum[ch[rt][0]]) {
            val -= sum[ch[rt][0]];
            ret |= 1 << i;
            rt = ch[rt][1];
        } else {
            rt = ch[rt][0];
        }
    }
    return ret;
}

int rk(int val, int ret = 0) {
    walk {
        ret += t * sum[ch[rt][0]];
        rt = ch[rt][t];
    }
    return ret;
}

int pre(int val) {
    return kth(rk(val));
}

int sub(int val) {
    return kth(rk(val + 1) + 1);
}

int n, opt, x;

int main() {
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i ++) {
        scanf("%d%d", &opt, &x);
        x += int(1e7);
        if(opt == 1) ins(x);
        if(opt == 2) ins(x, -1);
        if(opt == 3) printf("%d\n", rk(x) + 1);
        if(opt == 4) printf("%d\n", kth(x - (int)1e7) - (int)1e7);
        if(opt == 5) printf("%d\n", pre(x) - (int)1e7);
        if(opt == 6) printf("%d\n", sub(x) - (int)1e7);
    }
}