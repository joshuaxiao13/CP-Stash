# A - Frog 1

The frog can only jump 1 or 2 stones ahead from the stone that the frog is currently on. Thus, to jump to stone ```i```, 
the frog must've previously been on stone ```i-1``` or ```i-2```. Let ```dp[i]``` equal the minimum cost to jump to stone ```i```, and 
```cost(a, b)``` equal the cost to jump from stone ```a``` to stone ```b```. Then, 
```dp[i] = min(dp[i-1] + cost(i-1, i) , dp[i-2] + cost(i-2, i))```. We are told from the problem
that the cost to jump from stone ```a``` to stone ```b``` is the absolute value of the difference of their heights. Thus,

##### DP Statement

```cpp 
dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]))
```
