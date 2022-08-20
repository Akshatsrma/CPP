// this file has all the algorithms i study whichwill help me to revise

#include <bits/stdc++.h>
using namespace std;
#define l long
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define lf(i, a, b) for (ll i = a; i < b; i++)
#define lb(i, a, b) for (ll i = a; i > b; i--)
#define mod 1000000007

// Euclid theorem

gcd(a, b) = gcd(a - b, b)

    // is prime
    bool isPrime(int n)
{
    if (n == 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

// print prime factors
void printPrimeFactors(int n)
{
    if (n <= 1)
        return;

    while (n % 2 == 0)
    {
        cout << 2 << " ";

        n = n / 2;
    }

    while (n % 3 == 0)
    {
        cout << 3 << " ";

        n = n / 3;
    }

    for (int i = 5; i * i <= n; i = i + 6)
    {
        while (n % i == 0)
        {
            cout << i << " ";

            n = n / i;
        }

        while (n % (i + 2) == 0)
        {
            cout << (i + 2) << " ";

            n = n / (i + 2);
        }
    }

    if (n > 3)
        cout << n << " ";

    cout << endl;
}

// print divisors 
void printDivisors(int n)
{
	int i = 1;
	for(i=1; i*i < n; i++)
	{
		if(n % i == 0)
		{
			cout<<i<<" ";
		}
	}

	for(; i >= 1; i--)
	{
		if(n % i == 0)
		{
			cout<<(n / i)<<" ";
		}
	}
}

// sieve algorithm for printing prime less than a number
void sieve(int n)
{
	if(n <= 1)
		return;

	bool isPrime[n+1];

	fill(isPrime, isPrime + n + 1, true);

	for(int i=2; i*i <= n; i++)
	{
		if(isPrime[i])
		{
			for(int j = 2*i; j <= n; j = j+i)
			{
				isPrime[j] = false;
			}
		}
	}

	for(int i = 2; i<=n; i++)
	{
		if(isPrime[i])
			cout<<i<<" ";
	}
}

// compute power of a number

int power(int x, int n){
    
    if(n==0){return 1;}
    

    int temp= power(x,n/2)
    temp =temp*temp;
    if(n%2==0)
    {
        return temp;
    }
    else{
        return temp*x;
    }

}

// iterate power (binary expression)

while(n>0)
{
    if(n%2!=0) // bit is 1
    else // bit is 0
    n=n/2;
}

///tower of hanoi 
 void ToH(int n, char A, char B, char C) 
{ 
    if (n == 1) 
    { 
        cout<<"Move 1 from " <<  A << " to " << C << endl; 
        return; 
    } 
    ToH(n-1, A, C, B); 
    cout<<"Move " << n << " from " <<  A << " to " << C << endl; 
    ToH(n-1, B, A, C); 
}

// josephus problem 
int jos(int n, int k)
{
	if(n == 1)
		return 0;
	else
		return (jos(n - 1, k) + k) % n;
}

// countSubsets with sum as sum.
int countSubsets(int arr[], int n, int sum)
{
	if(n==0)
		return sum==0? 1 : 0;

	return countSubsets(arr, n-1, sum) + countSubsets(arr, n-1, sum - arr[n-1]);
}

// largest element in an  array

int largestInArray(int arr[], int n)
{
     int largest=0

     for(int i{1};i<n;i++)
     {
         if(arr[i]>arr[largest])
         {
             largest= i;
         }

     }
     return largest;
}

// second largest in an array

int largestInArray(int arr[], int n)
{
     int largest{0},secondlargest{-1};

     for(int i{0};i<n;i++)
     {
         if(arr[i]>arr[largest])
         {
             secondlargest=largest;
             largest=i;
         }
         else if(arr[i]!=arr[largest])
         {
             if(secondlargest==-1 || arr[i]>arr[secondlargest])
             {secondlargest=i;}
         }

     }
     return largest;
}
// remove duplicates from sorted array

int remDups(int arr[], int n)
{
    int res{0};

    for(int i{1};i<n;i++)
    {
        if(arr[i]!= arr[res])
        {
            arr[++res]=arr[i];
        }
    }
    return res+1;
}

// shiftthe  zero elements at the end of the array

int shiftToEnd(int arr[], int n)
{
    int count=0;

    for(int i{0};i<n;i++)
    {
        if(arr[i]!=0)
        {
           swap(arr[i],arr[count]);
           count++;
        }
    }
    
    
}
// rotate array by d places

void reverse(int arr[], int low, int high)
{
	while(low < high)
	{
		swap(arr[high], arr[low]);

		low++;
		high--;
	}
}   

void leftRotate(int arr[], int d, int n)
{
	reverse(arr, 0, d - 1);

	reverse(arr, d, n - 1);

	reverse(arr, 0, n - 1);
}

// leader in an array(no greater element in the right of this element)
void leaders(int arr[], int n)
{
    int temp{INT_MIN};

    for(int i{n-1};i>=0;i--)
    {
        if(arr[i]>temp)
        {
            cout<<arr[i]<<" ";
            temp=arr[i];
        }
    }
}

// max difference between right element and left element(i<j)
int maxDiff(int arr[], int n)
{
	int res = arr[1] - arr[0], minVal = arr[0];

	for(int i = 1; i < n; i++)
	{
		
			res = max(res, arr[i] - minVal);
			
			minVal = min(minVal, arr[i]);
	}

	return res;
}

// Frequencies of elements in sorted array
void printFreq(int arr[], int n)
{
    int num=arr[0];
    int count{1};
    for(int i{1};i<n;i++){
       
       if(arr[i]==num)
       {
           count++;
       }
       else{
           cout<<num<<" "<<count<<endl;
           count=1;
           num=arr[i];
       }
    }
    cout<<arr[n]<<" "<<count;
}
// stock buy problem
int maxProfit(int price[], int n)
{
    int profit{};
   for(int i{1};i<n;i++)
   {
       if(arr[i]>arr[i-1])
       {
           profit+=arr[i]-arr[i-1];
       }
   }
   return profit;
}

// trapping rain water
int getWater(int arr[], int n)
{
	int res = 0;

	for(int i = 1; i < n - 1; i++)
	{
		int res = 0;

    	int lMax[n];
    	int rMax[n];

    	lMax[0] = arr[0];
    	for(int i = 1; i < n; i++)
    		lMax[i] = max(arr[i], lMax[i - 1]);


    	rMax[n - 1] = arr[n - 1];
    	for(int i = n - 2; i >= 0; i--)
    		rMax[i] = max(arr[i], rMax[i + 1]);

    	for(int i = 1; i < n - 1; i++)
    		res = res + (min(lMax[i], rMax[i]) - arr[i]);
    	
    	return res;
	}

	return res;
}

// kadens algorithm for the maximum sum of a sub array
int maxSum(int arr[], int n)
{
    int pervMaxSum[n];
    int res=arr[0];
  prevMaxSum[0]=arr[0];
    for(int i{1};i<n;i++)
    {
        prevMaxSum[i]= prevMaxSum[i-1]>0 ? prevMaxSum[i-1]+arr[i]:arr[i];
        res=max(res,prevMaxSum[i]);
    }
return res;

}
int maxSumC(int arr[], int n){
    int totalsum{arr[0]};
    int prevMS[n];
    prevMS[0]=arr[0];
    int res=arr[0];

    for(int i{1};i<n;i++){
        totalsum+=arr[i];

         prevMS[i]= prevMS[i-1]<0 ? prevMS[i-1]+arr[i]:arr[i];
         res=min(res,prevMS[i]);
    }
    return totalsum-res;
}
// moorays method for majority element
  int findMajority(int arr[], int n)
{
	int res = 0, count = 1;

    	for(int i = 1; i < n; i++)
    	{
    		if(arr[res] == arr[i])
    			count++;
    		else 
    			count --;

    		if(count == 0)
    		{
    			res = i; count = 1;
    		}
    	}

    	count = 0;

    	for(int i = 0; i < n; i++)
    		if(arr[res] == arr[i])
    			count++;

    	if(count <= n /2)
    		res = -1;

    	return res; 
}

// window sliding 

// max sum of subarray of size k
int maxSum(int arr[], int n, int k)
{
	int curr_sum = 0;

	for(int i = 0; i < k; i++)
		curr_sum += arr[i];

	int max_sum = curr_sum;

	for(int i = k; i < n; i++)
	{
		curr_sum += (arr[i] - arr[i - k]);

		max_sum = max(max_sum, curr_sum);
	}

	return max_sum;
}
// window sliding subarray with given sum, the array has only non negative elements
int subArraySum(int arr[], int n, int sum) 
{ 
	int curr_sum = arr[0], start = 0, i; 
	for (i = 1; i <= n; i++) 
	{ 
		while (curr_sum > sum && start < i-1) 
		{ 
			curr_sum = curr_sum - arr[start]; 
			start++; 
		} 
		if (curr_sum == sum) 
		{ 
			printf ("Sum found between indexes %d and %d", start, i-1); 
			return 1; 
		} 
		if (i < n) 
		curr_sum = curr_sum + arr[i]; 
	} 
	printf("No subarray found"); 
	return 0; 
} 

//prefix sum array
int prefix_sum[10000]; 
void preSum(int arr[], int n)
{
	prefix_sum[0] = arr[0];
	for(int i = 1; i < n; i++)
	{
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
	}
}

// check equilibrium in array
bool checkEquilibrium(int arr[], int n)
{
    int l_sum=0;
    int sum{};
    for(int i{};i<n;i++)
    {
      sum+=arr[i];
    }

    for(int i{};i<n;i++)
    {
        if(l_sum==sum-arr[i])
        {
            return true;
        }

        l_sum+=arr[i];

        sum=sum-arr[i];
    }
    return false;
}

// 



