var t;
t = readline();
for (t; t > 0; t--){
    var n;
    var ans = 0;
    n = readline();
    while (n > 0){
        var x = n % 10;
        ans = ans + x;
        n = n - x;
        n = n / 10;
    }
    print(ans);
}