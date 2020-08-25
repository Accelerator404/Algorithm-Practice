#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
 * PAT Advanced: 1045. Favorite Color Stripe
 */

int main() {
    int N, M, L;
    set<int> fav_color_s;
    vector<int> fav_color, stripe_seq, stripe_order_seq;

    // 读入数据
    cin >> N;
    cin >> M;
    fav_color.resize(N + 1);  // 调整为能存储所有颜色
    for (int i = 1; i <= M; i++) {
        int tmp;
        cin >> tmp;
        fav_color_s.insert(tmp);
        fav_color[tmp] = i;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int tmp;
        cin >> tmp;
        if (fav_color_s.find(tmp) == fav_color_s.end())
            continue;
        stripe_seq.push_back(tmp);
    }

    // 将输入的颜色序列转换为fav_color中存储的颜色顺序序列
    stripe_order_seq.resize(stripe_seq.size());
    for (int i = 0; i < stripe_seq.size(); i++) {
        stripe_order_seq[i] = fav_color[stripe_seq[i]];
    }

    // 使用动态规划
    vector<int> max_len(stripe_seq.size(), 1);   // 从每一颗珠子开始统计左侧最大长度，初始长度均为1
    for (int i = 0; i < stripe_seq.size(); i++) {
        for (int j = 0; j < i; ++j) {
            // 如果左侧某位置j上珠子与位置i的珠子满足fav_color顺序，(i结尾的珠子序列的最大长度)应大于等于(j位置上该长度+1)
            if (stripe_order_seq[i] >= stripe_order_seq[j]) {
                max_len[i] = max(max_len[i], max_len[j] + 1);
            }
        }
    }
    // 此时max_len存储了以每个位置结尾时，满足题设条件的序列的最大长度
    cout << *max_element(max_len.begin(), max_len.end()) << endl;
    return 0;
}