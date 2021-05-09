A = Given array
n = size of A
k = maximum value in array A


//Get two integer values a and b of out target range
int a, b;


// Make array C as an empty list with size k
//(where range of elements in array A is [1, k])
for i from 1 to k{
	C[i] = 0;
}
for j from 1 to n{
	//increase C[A[j]] by 1
	C[A[j]] += 1;
}
for i from 2 to k{
	//Accumulate element numbers as index grows
	C[i] = C[i] + C[i-1];
}


//check whether two integers are making right range
if b > k{
	b = k;
}
if a < 1{
	return C[b];
}

return C[b] - C[a-1]


