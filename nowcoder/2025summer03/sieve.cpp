vector<long long> sieve(long long n){
    vector<char> isp(n + 1, 1);
    vector<long long> p(1, 2);
    long long i, j, r = sqrt(n);
    // isp[0]=0;isp[1]=0;
    for (i = 4; i <= n; i += 2) isp[i] = 0;
    for (i = 3; i <= r; i += 2){
        if (isp[i] == 1){
            p.push_back(i);
            j = n / i;
            if (j % 2 == 0) j--;
            for (; j >= i; j -= 2) if (isp[j] == 1) isp[i * j] = 0;
        }
    }
    if (++r % 2 == 0) r++;
    for (; r <= n; r += 2) if (isp[r] == 1) p.push_back(r);
    return p;
}