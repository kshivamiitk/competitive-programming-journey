```here we are upto understand what is the case of KMP```
## KMP 
KMP (Knuth–Morris–Pratt) is a linear-time algorithm for string matching: given a pattern P (length m) and a text T (length n), it finds all occurrences of P in T in O(n + m) time.

The core idea: when a mismatch happens after some matched prefix of P, we reuse information about the pattern structure so we don't restart matching from scratch. That reuse information is stored in the prefix-function (also called pi or LPS — longest proper prefix that is also suffix).

### Prefix function
For a string s of length n, pi[i] = length of the longest proper prefix of s[0..i] which is also a suffix of s[0..i].
(“Proper” means not the whole substring itself.)

#### working algorithm here
```pi[0] = 0
for i = 1 .. n-1:
    j = pi[i-1]
    while j > 0 and s[i] != s[j]:
        j = pi[j-1]
    if s[i] == s[j]:
        j += 1
    pi[i] = j
```
Example s = "ababaca" (step-by-step):

i=0: pi[0]=0

i=1 (s[1]=b): j=0, b!=a -> pi[1]=0

i=2 (s[2]=a): j=0, a==a -> j=1 -> pi[2]=1

i=3 (s[3]=b): j=1, b==b -> j=2 -> pi[3]=2

i=4 (s[4]=a): j=2, a==a -> j=3 -> pi[4]=3

i=5 (s[5]=c): j=3, c!=b -> j=pi[2]=1; c!=b -> j=pi[0]=0; c!=a -> pi[5]=0

i=6 (s[6]=a): j=0, a==a -> j=1 -> pi[6]=1
