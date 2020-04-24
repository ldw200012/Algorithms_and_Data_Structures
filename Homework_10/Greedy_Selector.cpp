Greedy_Selector(){
	// Assume S = {a[1], ... a[n]}
	// with activities sorted by f[i]
	A = {a[n]}
	first_idx_of_A = n

	while true
		// find the last starting activity
		j = 0
		for i = 1 to first_idx_of_A-1 do
			if f[i] <= s[first_idx_of_A]
				then j = i

		if j = 0
			then break

		for i = j+1 to first_idx_of_A-1 do
			if s[i]	> s[j] and f[i] <= s[first_idx_of_A]
				then j = i

		// Add the element to the array
		A = A union {a[j]}
		first_idx_of_A = j

	return A
}

