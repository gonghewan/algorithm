int KMP(string ori, string pattern) {
    int sizeofp = pattern.size(), sizeofo = ori.size();
    vector<int> next(sizeofp, 0);
    next[0] = -1;
    int j = -1;
    for (int i = 0; i < sizeofp - 1; i++) {
        if (j == -1 || pattern[i] == pattern[j]) {
            next[++i] = ++j;
        }
        else {
            j = next[j];
        }
    }
    int count_i = 0, count_j = 0;
    while (count_j < sizeofp && count_i < sizeofo) {
        if (count_j == -1 || ori[count_i] == pattern[count_j]) {
            ++count_j;
            ++count_i;
        }
        else {
            count_j = next[count_j];
        }
    }
    if (count_j == sizeofp) return count_i - count_j;
    else return -1;
}
