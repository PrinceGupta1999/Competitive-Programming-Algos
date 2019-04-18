#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
template <typename T> using indexed_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
#define mod 1000000007

#define szSieve 100000
ll sieve[szSieve + 1];
vector<ll> primes; // Array for storing primes in [2, szSieve]
map<ll, ll> c;

// Prepares a Sieve such that sieve[i] = 0 => i == prime else sieve[i] == largest prime factor of i
// TC = O(n)
void prepareSieve()
{
    for (ll x = 2; x <= szSieve; x++)
    {
        if (sieve[x]) continue; // if not prime => continue
        primes.push_back(x);
        for (ll u = 2 * x; u <= szSieve; u += x) { // Make all multiples of x non prime
            sieve[u] = x;
        }
    }
}
// Returns a map of factors such that c[x] = power of x in prime factorization of n
// TC ~= O(lg(n)) when szSieve ^ 2 >= n Requires sieve() to execute first
void factorize(ll n)
{
    for(auto x : primes)
    {
        if (x * x > n || n <= szSieve) // if (no more factors) or (n in [1, szSieve]) 
            break;
        if(sieve[x]) // if x not prime 
            continue;
        while(n % x == 0) // get no. of times n divisible by x
        {
            c[x]++;
            n /= x;
        }
    }
    if(n <= szSieve)
    {
        while(sieve[n]) // sieve[n] = greatest prime factor of n
        {
            c[sieve[n]]++; // increase power of factor
            n /= sieve[n]; // reduce n
        }
    }
    if (n > 1) // get last prime factor != 1
        c[n]++;
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

// Returns #coPrime of n < n by evaluating Euler's Totient Func.
// TC = O(lg(n))
ll numCoPrimes(ll n)
{
    factorize(n); // get all factors
    ll r = 1;
    for(auto factor : c) // Evaluate Euler's Totient Func.
        r *= power(factor.first, factor.second - 1, mod) * (factor.first - 1);
    return r;
}

// Calculates n^-1 modulo m returns 0 if not poss
// TC ~= O(lg^2(n))
ll moduloInverse(ll n, ll m, bool primeM = false)
{
    if(__gcd(m, n) != 1) // modulo inverse not possible
        return 0;
    if(primeM) // To ease calculation if we know one of numbers is prime
        return power(n, m - 2, m);
    return power(n, numCoPrimes(m) - 1, m); // Fermat's Equation
}


// Extended Euclid
// Returns x, y such that a * x + b * y = gcd(a, b)
ll extendedEuclid(ll a, ll b, ll &x, ll &y)
{
    if(a == 0)
    {
        x = 0, y = 1; // Get x and y
        return b; // Return gcd
    }
    ll x1, y1, gcd = extendedEuclid(a, b, x1, y1);
    x = y1 - (a / b) * x1; // Evaluate new x, y from previous
    y = x1;
    return gcd; // Return gcd
}

// Inverse Modulo using Extended Euclid
// if gcd(a, b) = 1 then x = a^-1 modulo b and y = b ^ -1 modulo a
ll moduloInverseEE(ll a, ll m)
{
    ll x, y, gcd = extendedEuclid(a, m, x, y);
    if(gcd != 1)
        return 0;
    else
        return (x % m + m) % m;
}


// DP Solution TC = O(n * r)
#define mn 5000
#define mr 5000
ll dp[mn + 1][mr + 1];
void preprocess(ll m)
{
    ll i, j;
    dp[0][0] = 1;
    for(i = 1; i <= mn; i++)
        dp[i][0] = i;
    for(i = 1; i <= mn; i++)
        for(j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % m; // dp[i][j] = iCj;
}

// DP calculating all factorials and their inverse modulo m (assuming prime m)
ll fact[mn + 1], ifact[mn + 1];
void preprocess2(ll m)
{
    ll i;
    fact[0] = ifact[0] = 1;
    for(i = 1; i <= mn; i++)
        fact[i] = (fact[i - 1] * i) % m, ifact[i] = (moduloInverse(i, m, true) * ifact[i - 1]) % m;
}
ll ncr(ll n, ll r, ll m)
{
    if(r > n)
        return 0;
    return (((fact[n] * ifact[r]) % m) * ifact[n - r]) % m;
}


// Lucas Theorem (when m is small) but n & r can have large values
// TC = O(m^2)(Preprocess) + O(log (n) base m)
#define mm 5000 //(use dp and preprocess from above)
// Call preprocess(mm);
ll nCr(ll n, ll r, ll m)
{
    ll res = 1, nd, rd;
    if(r > n)
        return 0;
    while(n > 0)
    {
        nd = n % m;
        rd = r % m;
        n /= m;
        r /= m;
        res = (res * dp[nd][rd]) % m;
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}
