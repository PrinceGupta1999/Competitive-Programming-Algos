// Calculates sum of digits of a number in O(lgn) time
int sumOfDigits(int n)
{
    int sod = 0;
    while(n)
    {
        sod += n % 10;
        n /= 10;
    }
    return sod;
}

// Returns the unique prime Factors of a number into an set passed by Ref.(pairFactors here) in O(lgn) time.
// Requires O(n) preprocessing for forming Sieve
void factorize(unordered_set<int>& pairFactors, int n, int sieve[], vector<int>& primeList)
{
    for(auto x : primeList)
    {
        if (x*x > n || n <= 100000)
            break;
        if(sieve[x])
            continue;
        while (n%x == 0)
        {
            pairFactors.insert(x);
            n /= x;
        }
    }
    if(n <= 100000)
    {
        while(sieve[n])
        {
            pairFactors.insert(sieve[n]);
            n /= sieve[n];
        }
    }
    if (n > 1)
        pairFactors.insert(n);
}
void prepareSieve(int sieve[], vector<int>& primeList)
{
    for (int x = 2; x <= 100001; x++) {
        if (sieve[x]) continue;
        primeList.push_back(x);
        for (int u = 2*x; u <= 100001; u += x) {
            sieve[u] = x;
        }
    }
}

//Modulo Exponentiation O(lg(y))
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

//DFS for a Tree in O(n)
void dfs(int u, int e, vector<int> adj[], int depth)
{
    bool leaf = true;
    for(auto v : adj[u])
        if(v != e)
            leaf = false, dfs(v, u, adj, depth + 1);
    if(leaf)
    {
        //leaf node computations
    }
}
