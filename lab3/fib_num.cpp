#include<iostream>
#include<omp.h>
#include<iomanip>
using namespace std;

#define NUM_THREADS 2
#define ll long long int
#define f(i,g,n) for(int i=g;i<=n;i++)

ll fib_serial(ll n)
{
	if(n <= 1)
		return n;
	return fib_serial(n-1)+fib_serial(n-2);
}

ll fib_task(ll n)
{
	ll a,b;
	if(n <= 1)
		return n;
	#pragma omp task
		a = fib_task(n-1);
	#pragma omp task
		b = fib_task(n-2);
	return a+b;
}

ll fib_taskwait(ll n)
{
	ll a,b;
	if(n <= 1)
		return n;
	#pragma omp task shared(a)
		a = fib_taskwait(n-1);
	#pragma omp task shared(b)
		b = fib_taskwait(n-2);
	#pragma omp taskwait
		return a+b;
}

int main()
{
	omp_set_num_threads(NUM_THREADS);
	ll n,res,res1;
	cout<<"Enter a number: ";
	cin>>n;
	double time = omp_get_wtime();
	res1 = fib_serial(n);
	time = omp_get_wtime()-time;
	cout<<"\nSerial Program\n";
	cout<<"N-th fibonacci number: "<<res1<<"\n";
	cout<<"Time taken: "<<setprecision(30)<<time<<"\n";
	f(i,0,75) cout<<"-"; cout<<"\n";

	time = omp_get_wtime();
	res = fib_task(n);
	time = omp_get_wtime()-time;
	cout<<"Parallel program with task\n";
	cout<<"N-th fibonacci number: "<<res<<"\n";
	cout<<"Time taken: "<<setprecision(30)<<time<<"\n";
	(res == res1) ? cout<<"Correct\n" : cout<<"Not correct\n";
	f(i,0,75) cout<<"-"; cout<<"\n";

	time = omp_get_wtime();
	res = fib_taskwait(n);
	time = omp_get_wtime()-time;
	cout<<"Parallel program with taskwait and data scoping\n";
	cout<<"N-th fibonacci number: "<<res<<"\n";
	cout<<"Time taken: "<<setprecision(30)<<time<<"\n";
	(res == res1) ? cout<<"Correct\n" : cout<<"Not correct\n";
	f(i,0,75) cout<<"-"; cout<<"\n";

	return 0;
}