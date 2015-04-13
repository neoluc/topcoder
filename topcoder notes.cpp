// standard algorithm implementation

int my_initial_binary_search(){
	vector<int> v;
	for(int i=1; i<=5; i++){
		v.push_back(i);
	}
	double k = 3.5;

	int l = 0;
	int r = v.size()-1;
	while(l < r){
		int m = (l+r)/2;
		cout << v[l] << ' ' << v[m] << ' ' << v[r] << ' ' << '(' << k << ')' << endl;
		if(v[m]==k){
			cout << "the result is " << m << endl;
			return m;
		}else if(v[m] > k){
			r = m;
		}else if(v[m] < k){
			l = m;
		}
	}

	cout << "target not found" << endl;
	return -1;
}

int topcoder_binary_search(){
	vector<int> v;
	for(int i=1; i<=5; i++){
		v.push_back(i);
	}
	double k = 3.5;

	int l = 0;
	int r = v.size()-1;
	while(l <= r){
		//int m = (l+r)/2; // this is incorrect if l and r too large
		int m = l + (r-l)/2;
		cout << v[l] << ' ' << v[m] << ' ' << v[r] << ' ' << '(' << k << ')' << endl;
		if(v[m]==k){
			cout << "the result is " << m << endl;
			return m;
		}else if(v[m] > k){
			r = m-1;
		}else if(v[m] < k){
			l = m+1;
		}
	}

	cout << "target not found" << endl;
	return -1;
}
// my_initial_binary_search cannot solve this case, (1,2,3,4,5) find 3.5
// topcoder_binary_search can solve this case, use your brain to illustrate
int binary_search_for_right_most_insertion_point(){
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	double k = 0;

	int l = 0;
	int r = v.size()-1;
	while(l <= r){
		int m = l + (r-l)/2;
		cout << v[l] << '(' << l << ") " << v[m] << '(' << m << ") " << v[r] << '(' << r << ") " << '[' << k << ']' << endl;
		if(v[m] <= k){
			l = m+1;
		}else if(v[m] > k){
			r = m-1;
		}
	}

	cout << "Final result " << l << endl;

	return l;
}

// this one will has bug when the below case occur
int binary_search_for_right_most_insertion_point_other_version_but_has_bug(){
	// this is the bug case
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	double k = 0;

	int l = 0;
	int r = v.size()-1;
	while(l < r-1){
		int m = l + (r-l)/2;
		if(v[m] <= k){
			l = m;
		}else if(v[m] > k){
			r = m;
		}
	}

	cout << "Final result " << r << endl;

	return r;
}


// print all permutations for non duplicate array
void backtrack_find_all_permutation_for_non_duplicate_array_until(char s[], char solution[], int used[], int n){
	if(n == 5){
		for(int i=0; i<5; i++){
			cout << solution[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i=0; i<5; i++){
		if(used[i]==0){
			used[i] = 1;
			solution[n] = s[i];
			backtrack_find_all_permutation_for_non_duplicate_array_until(s, solution, used, n+1);
			used[i] = 0;
		}
	}
}
void backtrack_find_all_permutation_for_non_duplicate_array(){
	char s[5] = {'a', 'b', 'c', 'd', 'e'};
	char solution[5];
	int used[5];
	for(int i=0; i<5; i++){
		used[i] = 0;
	}
	backtrack_find_all_permutation_for_non_duplicate_array_until(s, solution, used, 0);
}

// print all the possible path of knight tour
void backtrack_knight_tour_until(int record[8][8], int movex[], int movey[], int x, int y, int n){
	if(n == 8*8){
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				cout << record[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "---------------\n";
		return;
	}

	for(int i=0; i<8; i++){
		int nextx = x+movex[i];
		int nexty = y+movey[i];
		if(nextx>=0 && nextx<8 && nexty>=0 && nexty<8 && record[nexty][nextx]==0){
			record[nexty][nextx] = n;
			backtrack_knight_tour_until(record, movex, movey, nextx, nexty, n+1);
			record[y+movey[i]][x+movex[i]] = 0;
		}
	}
}

void backtrack_knight_tour(){
	int record[8][8];
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			record[i][j] = 0;
		}
	}
	int movex[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int movey[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	backtrack_knight_tour_until(record, movex, movey, 0, 0, 1);
}

// find all possible path to leave a maze
void backtrack_maze_until(int maze[6][6], int record[6][6], int movex[4], int movey[4], int x, int y){
	if(x==5 && y==5){
		record[y][x] = 1;
		for(int i=0; i<6; i++){
			for(int j=0; j<6; j++){
				cout << record[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "---------------\n";
		return;
	}
	if(x>=0 && x<6 && y>=0 && y<6 && maze[y][x]==1 && record[y][x]==0){
		record[y][x] = 1;
		for(int i=0; i<4; i++){
			int nextx = x + movex[i];
			int nexty = y + movey[i];
			backtrack_maze_until(maze, record, movex, movey, nextx, nexty);
		}
		record[y][x] = 0;
	}
}

void backtrack_maze(){
	int maze[6][6] = {
		{1, 0, 0, 0, 1, 0},
		{1, 1, 1, 1, 1, 1},
		{0, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 1},
		{0, 1, 0, 1, 0, 1},
		{0, 1, 1, 1, 1, 1},
	};
	int record[6][6];
	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			record[i][j] = 0;
		}
	}
	int movex[4] = {0, 1, 0, -1};
	int movey[4] = {1, 0, -1, 0};
	backtrack_maze_until(maze, record, movex, movey, 0, 0);
}

// find all possible ways to place a queen
bool backtrack_n_queen_is_safe(int board[4][4], int x, int y){
	for(int i=0; i<=y; i++){
		if(board[i][x]==1){
			return false;
		}
	}
	for(int i=y, j=x; i>=0 && j>=0 ; i--, j--){
		if(board[i][j]){
			return false;
		}
	}
	for(int i=y, j=x; i>=0 && j<4; i--, j++){
		if(board[i][j]){
			return false;
		}
	}
	return true;
}

void backtrack_n_queen_until(int board[4][4], int y){
	if(y == 4){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "------------\n";
		return ;
	}
	for(int i=0; i<4; i++){
		if(backtrack_n_queen_is_safe(board, i, y)){
			board[y][i] = 1;
			backtrack_n_queen_until(board, y+1);
			board[y][i] = 0;
		}
	}
}

void backtrack_n_queen(){
	int board[4][4];
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			board[i][j] = 0;
		}
	}
	backtrack_n_queen_until(board, 0);
}

// find all the subset of the desired sum
void backtrack_subset_sum_until(){

}

// no need to check which input bigger
int gcd_iterative(int a, int b){
	while(b!=0){
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

// no need to check which input bigger
int gcd_recursive(int a, int b){
	if(b==0){
		return a;
	}
	return gcd_recursive(b, a%b);
}

// from geeksforgeeks
// this tries to put different char on left,
// repeat the process to remaining string, so each combination will start with diff char
// also true for remaining
void backtrack_find_all_permutation_by_swap_until(vector<int>& v, int n){
	if(n == v.size()){
		for(int i=0; i<v.size(); i++){
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i=n; i<v.size(); i++){
		swap(v[n], v[i]);
		backtrack_find_all_permutation_by_swap_until(v, n+1);
		swap(v[n], v[i]);
	}
}

void backtrack_find_all_permutation_by_swap(){
	vector<int> v;
	for(int i=0; i<5; i++){
		v.push_back(i);
	}
	backtrack_find_all_permutation_by_swap_until(v, 0);
}

bool is_prime(int n){
	if(n<=1) return false;
	if(n==2) return true;
	if(n%2==0) return false;
	int m = sqrt(n*1.0);
	for(int i=3; i<=m; i+=2){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

// knuth morris pratt for match substring in a string
// my implementation of function generating longest proper prefix-suffix array
vector<int> generate_lps(string s){
	string t;
	vector<int> v;
	for(int i=0;i<s.size(); i++){
		t += s[i];
		int u = -1;
		for(int j=1; j<=t.size(); j++){
			string a = t.substr(0, t.size()-j);
			string b = t.substr(j);
			if(a==b){
				u = a.size();
				break;
			}
		}
		v.push_back(u);
	}
	return v;
}
// better version, more low level and more detailed
vector<int> generate_lps_version_2(string s){
	string t;
	vector<int> v;
	for(int i=0;i<s.size(); i++){
		t += s[i];
		int u = -1;
		for(int j=1; j<=t.size(); j++){
			bool b = true;
			for(int k=0; k<t.size()-j; k++){
				if(t[k]!=t[k+j]){
					b = false;
					break;
				}
			}
			if(b){
				u = t.size()-j;
				break;
			}
		}
		v.push_back(u);
	}
	return v;
}
void knuth_morris_pratt(){
	string a = "ABABDABACDABABCABAB";
	string b = "ABABCABAB";
	vector<int> v = generate_lps_version_2(b);
	for(int i=0; i<a.size()-b.size()+1; i++){
		int m = 0;
		for(int j=0, k=i; j<b.size() && a[k]==b[j]; k++, j++){
			if(a[k]==b[j]){
				m++;
			}
		}
		if(m==0){
			continue;
		}
		if(m==b.size()){
			cout << "found pattern at index " << i << endl;
		}
		if(v[m-1]>0){
			i += m-v[m-1]; 
		}
	}
}

// 在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，
// 并且满足*i < *ii。然后再从尾端寻找另一个元素*j，如果满足*i < *j，
// 即将第i个元素与第j个元素对调，并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。
// start from right most element, try to find a element from the right side to swap that is just slightly larger than the current element
// then after swap, make the right side assending (by reversing)
// go into those ascending elements and do those operations again until they become decending
bool inside_next_permutation(string::iterator first, string::iterator last){
	if(first == last){
		return false;
	}
	
	string::iterator i = first;
	++i;
	if(i == last){
		return false;
	}

	i = last;
	--i;

	for(;;){
		string::iterator ii = i;
		--i;
		if(*i < *ii){
			string::iterator j = last;
			while(!(*i < *--j));

			iter_swap(i, j);
			reverse(ii, last);
			return true;
		}

		if(i == first){
				reverse(first, last);
				return false;
		}
	}
}

// backtrack to generate all subsequence of a string, but seems not so efficient
// if string size is 4, then the run time will be
// 4 + 4*3 + 4*3*2 + 4*3*2*1
void backtrack_find_all_subsequence_until(string& s){
	cout << s << endl;
	if(s.size()==0){
		return;
	}
	for(int i=0; i<s.size(); i++){
		char t = s[i];
		s.erase(s.begin()+i);
		backtrack_find_all_subsequence_until(s);
		s.insert(s.begin()+i, t);
	}
}

void backtrack_find_all_subsequence(){
	string s = "abcd";
	backtrack_find_all_subsequence_until(s);
}

void temp(){
	
	int low = 1;
	int high = 100000;

	for(int i=low; i<=high; i++){
		int a = i*i;
		int b = i;
		int t = 0;
		while(b){
			t += b%10;
			b /= 10;
		}
		int x = t*t;
		int y = 0;
		while(a){
			y += a%10;
			a /= 10;
		}
		if(x == y){
			cout << i << endl;
		}
	}

}

// you can press enter
void convert_decimal_number_to_base_4_number(){
	int t = 6;
	while(1){
		int a = 0;
		int b = 1;
		int i = 0;
		while(t >> 2*i){
			int x = t >> 2*i;
			cout << x << endl;
			int y = x & 3;
			a += b*y;
			b *= 10;
			i++;
		}
		cout << a << endl;
		t++;
		getchar();
	}
}

void combination_until(vector<int>& v, vector<int>& d, int start, int n, int r){
	if(n==r){
		for(int i=0; i<d.size(); i++){
			cout << d[i] << ' ';
		}
		cout << endl;
		return;
	}
	for(int i=start; i<v.size() && v.size()-i >= r-n; i++){
		d[n] = v[i];
		combination_until(v, d, i+1, n+1, r);
	}
}
void combination(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	int r = 4;
	vector<int> d(r);
	combination_until(v, d, 0, 0, r);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






find subset of certain size
	- next_permutation + substr, but not so efficient

find all subset
	- bitmask
	- iteration
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		for(int i=0; i<v.size(); i++){
			cout << v[i] << endl;
			for(int j=i+1; j<v.size(); j++){
				cout << v[i]<<' '<<v[j] <<endl;
				for(int k=j+1; k<v.size(); k++){
					cout << v[i]<<' '<<v[j]<<' '<<v[k] << endl;
					for(int m=k+1; m<v.size(); m++){
						cout << v[i]<<' '<<v[j]<<' '<<v[k]<<' '<<v[m] << endl;
					}
				}
			}
		}
	- backtrack
		void backtrack_find_all_subset_until(vector<int>& a, vector<int>& b, int n){
			for(int i=0; i<b.size(); i++){
				cout << b[i] << ' ';
			}
			cout << endl;
			for(int i=n; i<a.size(); i++){
				b.push_back(a[i]);
				backtrack_find_all_subset_until(a, b, i+1);
				b.pop_back();
			}
		}
		void backtrack_find_all_subset(){
			vector<int> a;
			a.push_back(10);
			a.push_back(7);
			a.push_back(5);
			a.push_back(18);
			a.push_back(12);
			a.push_back(20);
			a.push_back(15);
			vector<int> b;
			backtrack_find_all_subset_until(a, b, 0);
		}
	- recursion
		void recursion_find_all_subset_until(vector<int>& a, vector<int> b, int n){
			if(n == a.size()){
				for(int i=0; i<b.size(); i++){
					cout << b[i] << ' ';
				}
				cout << endl;
				return ;
			}
			recursion_find_all_subset_until(a, b, n+1);
			b.push_back(a[n]);
			recursion_find_all_subset_until(a, b, n+1);
		}
		void recursion_find_all_subset(){
			vector<int> a;
			a.push_back(10);
			a.push_back(7);
			a.push_back(5);
			a.push_back(18);
			a.push_back(12);
			a.push_back(20);
			a.push_back(15);
			vector<int> b;
			recursion_find_all_subset_until(a, b, 0);
		}

check whether exist subset which sum equal certain number
	- iteration
	- recursion (also can use dynamic programming to improve)
		int dp_recursion_whether_subset_sum_exist_until(int memo[][1000], vector<int>& a, int n, int c, int t){
			if(c == t){
				return 1;
			}
			if(n == a.size()){
				return 0;
			}
			if(memo[n][c] != -1){
				return memo[n][c];
			}
			return memo[n][c] = dp_recursion_whether_subset_sum_exist_until(memo, a, n+1, c, t) | dp_recursion_whether_subset_sum_exist_until(memo, a, n+1, c+a[n], t);
		}
		void dp_recursion_whether_subset_sum_exist(){
			vector<int> a;
			a.push_back(10);
			a.push_back(7);
			a.push_back(5);
			a.push_back(18);
			a.push_back(12);
			a.push_back(20);
			a.push_back(15);
			int memo[20][1000];
			memset(memo, -1, sizeof(memo));
			int target = 35;
			int ans = dp_recursion_whether_subset_sum_exist_until(memo, a, 0, 0, target);
			cout << ans << endl;
		}
	- backtrack
	- bitmask


longest prefix suffix

generate numbers which only forms by certain numbers


modular formula
	- (a+b)%c = (a%c+b%c)%c
	- (a*b)%c = (a%c*b%c)%c
	eg.
		calculate the sum of 1 to 1000000 mod 17
			int sum = 0;
			for (int i = 1; i <= 1000000; i++) {
				sum = (sum + i % q) % q;
			}


find all permutation
	- next_permutation
	- backtrack version 1
		iterate diff position and put every diff remaining character to the left
	- backtrack version 2

large interval search

binary search
	- find left most position
		int binary_search_for_right_most_insertion_point(){
			vector<int> v;
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(2);
			v.push_back(2);
			v.push_back(2);
			v.push_back(3);
			v.push_back(3);
			v.push_back(3);
			double k = 0;

			int l = 0;
			int r = v.size()-1;
			while(l <= r){
				int m = l + (r-l)/2;
				if(v[m] <= k){
					l = m+1;
				}else if(v[m] > k){
					r = m-1;
				}
			}
			return l;
		}

find range interset
	- mark all range specifically
		vector<int> v(10001, 0);
		for(int i=0; i<startPoints.size(); i++){
			for(int j=startPoints[i]; j<endPoints[i]; j++){
				v[j] = 1;
			}
		}
		int ans = 0;
		for(int i=0; i<v.size(); i++){
			ans += v[i];
		}
	- mark head and tail of each range
		vector<int> v(10002);
		for(int i=0; i<startPoints.size(); i++){
			v[startPoints[i]]++;
			v[endPoints[i]]--;
		}
		int ans = 0;
		int t = 0;
		for(int i=0; i<=10000; i++){
			t += v[i];
			if(t>0){
				ans++;
			}
		}
	- sort different range and compute them
		vector< pair<int, int> > v(n);
		for(int i=0; i<n; i++){
			v[i] = make_pair(startPoints[i], endPoints[i]);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		int t = 0;
		for(int i=0; i<n; i++){
			if(v[i].first > t){
				ans += v[i].second - v[i].first;
				t = v[i].second;
			}
			if(v[i].second > t){
				ans += v[i].second - t;
				t = v[i].second;
			}
		}

extract numbers from different format
	- stringstream
	- sscanf(queries[i].c_str(), "%d,%d,%d", &a, &b, &c);
	- string.find_first_of()

check if string is palindrome
	- original string == reverse(string)
	- loop through first and last using iteration or recursion
	- from middle extend out

check how many substr of string is palindrome
	use recursive dynamic programming

How to write modulus multiplication without overflow?
	http://apps.topcoder.com/forums/?module=Thread&threadID=670443&start=0&mc=10#1970665

ceil without ceil

round without round

node number of full binary tree
	- 2^h - 1 , height is 1 when there is only one node

check lexicographical larger
	- if string is same but one shorter, then shorter smaller
		eg. DA < DAD, D < DD
	- logic
		int lexicographic_first(string a, string b){
			int ai = 0, bi = 0;
			/* find the first difference between a and b, unless we run out of characters in one of the strings */
			while (ai < a.length() && bi < b.length() && a[ai++] == b[bi++]);
			if (ai == a.length() && bi == b.length()) /* we ran out of characters in both strings */
				return 0; /* strings are equal */
			if (ai == a.length()) /* we ran out of characters in a */
				return -1; /* a came first */
			if (bi == b.length()) /* we ran out of characters in b */
				return 1; /* b came first */
			if (a[ai] < b[bi])    /* we're now looking at the first difference between a and b */
				return -1; /* a came first */
			return 1; /* b came first */
		}

common combinatorics
	property
		nCm = nC(n-m)
		nCm = (n-1)Cm + (n-1)C(m-1)
		nCn = 1
		nC0 = 1
		nC2 = n*(n-1)/2
	- how many permutation can a string get = n!
	- how many permutation if you choose k letters from string = n!/(n-k)!
	- how many permutations you can get by rearrange the words "eel" and "databases"
		= nPr/no of ways to rearrange each "kind" of letter
		for "eel"
			= 3P3/2!
		for "databases"
			= 9P9/(1!*3!*1!*1!*1!*2!*1!)
		another example, how to assign 97 coders into 5 rooms
			= 97P97/(20!*20!*20!*20!*17!)
		another example, how many ways to distribute 5 cards to 4 players from 52 cards
			= 52C5 * 47C5 * 42C5 * 37C5
	- how many permutations to form by 3 'a's and 4 'b's	
		like above = 5P5/(3!*4!)
	- how many combinations can a string get = 1
	- how many combinations if choose k letters from string = nPk/k! = n!/((n-k)!*k!)
	- there are 10 men and 10 women, how many ways to choose 12 people if
		a) no restrictions
			= 20C12
		b) 7 woman is chosen
			= 10C7*10C(12-7)
		c) at least 8 women
			= 10C8*10C4 + 10C9*10C3 + 10C10*10C2
		d) at most 3 women
			= 10C2*10C10 + 10C3*10C9
	- how many combinations to choose k letters from string which can repete
			= (n+k+1)Ck
		eg choose 3 from "ABCDEF"


common probability problems
	expected value
		= sum of all (x * p(x))
		eg
		there is a game that 50% goes to $2, 10% to $10, 10% to $1, 25% to $2, but it costed $1, how many expected to win
		E(X) = -1(0) + 0(1/2) + 1(1/8) + 2(1/4) + 10(1/8)

	conditional probability
		= p(x | given conditions) = p(x and given conditions) / p(given conditions)
		eg.
			you get one card from deck and know it is black, what is the probability it is ace of spades
				method 1
					by intuitive, it is 1/26
				method 2
					by formular
					= p(is ace of spade and is black)/p(is black) 
					= (1/52) / (26/52)

	- roll 10 coins, 7 is heads
		p(7 is h) = (number of combinations of 7 heads and 3 tails) / (number of all combinations)
		= 10C7 / 2^10
	- roll 10 unfair coins of given probability to be head (80%), 7 is heads
		* since the coins is not fair, we cannot use the method of dividing the sample space
		p(7 is h) = p(hhhhhhhttt) + p(hhhhhhthtt) + p(hhhhhhttht) + ... + p(ttbhhhhhhh) <= there are 10C7 items
		any one item is (0.8)^7*(1-0.8)^3
		so total is = 10C7 * (0.8)^7*(1-0.8)^3
	- roll 10 dice, 7 dices is 4
		= number of combinations of 7 dices 4 and others other face / number of all combinations
			number of combinations of 7 dices 4 and others other face
				= (number of ways to choose 7 '4's) * (foreach combinations, how many possible numbers combinations it will have)
				= (10C7) * (1*1*1*1*1*1*1*5*5*5)
					(1*1*1*1*1*1*1*5*5*5) is because there are 7 dice only have one choice, which is '4',
					and other dice will have numbers other than '4', so there are 5 choice for those other dices
			number of all combinations
				= 6^10
		= 10C7 * 5^3 / 6^10
	- roll 10 dice, total sum is 5
	- roll 10 dice, 2 dices is same
	- roll 6 dice, all dices not same
	- there are ABCDEFGH, what is the probability that choose 3 and the 1st is H, 2nd is G, 3rd is F
		= 1/9P3
	- poker has 52 cards, if a poker hand has 9 cards, what is the probability that a hand include 4 aces
		= no of combinations to arrange 4 aces and other 5 cards / num of all combinations of 9
		= 1*1*1*1*(52-4)C5 / 52C9





probability birthday paradox
	- in one room with 5 people, the probability that more than two people has same birthday (at least two people birthday is same)
		= p(exactly 2 people same) + p(3 same) + p(4 same) + p(5 same)
		first look at p(2 same)
			all combination of 5 people birthday is
				1,1,1,1,1 - 1,1,1,1,2 - 1,1,1,1,3 - ... - 1,1,1,1,356 - 1,1,1,2,1 - ... - 1,1,1,2,2 - 365,365,365,365,365
				so there are 365^5 combinations
			probability = (how many to choose 2 person from 5 to be the same) * (foreach combination, how many permutations can we choose from 365)
				how many to choose 2 person from 5 to be the same
					the combinations of 2 people same is
					y,y,x,x,x - y,x,y,x,x - y,x,x,y,x - y,x,x,x,y - x,y,y,x,x - x,y,x,y,x - ... - x,x,x,y,y
					it is to choose 2 people from 5 people
					this question is like having letters ABCDE, how many combinations 2 can we choose (not permutation since AB and BA is same)
					so there are 5C2 combinations for 2 person to be same, which is 5!/(3!*2!)
				foreach combination, how many permutations can we choose from 365
					eg. 1,1,2,3,4 - 1,1,2,3,5 - ...
					for 1st y, there will be 365 choice
					for 2nd y, there will be only 1 choice since it equals 1st y
					for 1st x, there will be 365-1 choice since it must differ previous numbers 
					for 2nd x, there will be 365-2 choice since it must differ previous numbers 
					for 3rd x, there will be 365-3 choice since it must differ previous numbers 
					so foreach combination, there are 365*364*363*362 = 365P4 = 365!/361!
			so p(2 same) = 5C2*365P4 / 365^5


permutation
	permutation without repetition (choose k from n , each object can choose only once and order matters)
	- eg how many permutation of string of length 3 with diff letter = 26P3 = 26*25*24 = 26!/23! = n!/(n-k)!
		if 3 letters can be same, = 26*26*26 = 26^3
	0! = 1
combination
	nCk = nPk/(no of ways to arrange k things) = nPk/k!
	eg how many combination if we want 4 letters out of A,B,C,D,E,F (6 letters)
		= no of permutation to choose 4 from these 6 letters / no of ways to arrange 4 letters
	eg there are A,B,C,D as 4 person, how many handshake can they make = how many ways to choose 2
		= the number of permutations without order

check number is prime
	public boolean isPrime (int n)
	{
	   if (n<=1) return false;
	   if (n==2) return true;
	   if (n%2==0) return false;
	   int m=Math.sqrt(n);

	   for (int i=3; i<=m; i+=2)
	      if (n%i==0)
	         return false;

	   return true;
	}

list all prime number <= n
	public boolean[] sieve(int n)
	{
	   boolean[] prime=new boolean[n+1];
	   Arrays.fill(prime,true);
	   prime[0]=false;
	   prime[1]=false;
	   int m=Math.sqrt(n);

	    for (int i=2; i<=m; i++)
	      if (prime[i])
	      	// start from i*i because the previous has been visited
	        for (int k=i*i; k<=n; k+=i)
	            prime[k]=false;

	   return prime;
	}

convert binary string to decimal integer

check whether a number is power of 5, or power of other things
	- keep devide it by that number until it become 1

check if all different combinations of substrings satisfy some requirement
	int back(int from, int to){
		if(memo[from][to] != -1){
			return memo[from][to];
		}
		if(good(s.substr(from, to-from+1))){
			return memo[from][to] = 1;
		}
		int t = numeric_limits<int>::max()/2;
		for(int i=from; i<to; i++){
			t = min(t, back(from, i) + back(i+1, to));
		}
		return memo[from][to] = t;
	}

get substring from tail of string
	s.substr(10-3, 3)

inclusion-exclusion principle 

a good combinatorics problem
	there 10 songs, how many ways to generate a playlist of 20 songs so that at least 3 songs between two same songs
		= 10*9*8*(7^17)
	there 10 songs, how many ways to generate a playlist of 20 songs so that all songs appeared at least once
		= 10^20 - 10C1*9^20 + 10C2*8^20 - ...
	there 10 songs, how many ways to generate a playlist of 20 songs combining above 2 conditions
		lets say the first condition is f(10)
		combined = f(10) - 10C1*f(9) + 10C2*f(8) - ...

	solve above problems in programming
		how many ways to generate a playlist that all songs appeared at least once
			//memorization
			int go(int t, int r, int n){
				if(n == 0){
					if(t > 0){
						return 0;
					}else{
						return 1;
					}
				}
				int u = 0;
				if(t > 0){
					u += t*go(t-1, r+1, n-1);
				}
				if(r > 0){
					u += r*go(t, r, n-1);
				}
				return u;
			}
			// dp
			int dp[P+1][N+1] = {0}; // dp[position in playlist][no of played songs]
			dp[0][0] = 1;
			for(int i=0; i<P; i++){ // foreach position of playlist
				for(int j=0; j<=N; j++){
					if(j > 0){ // if we have played some songs
						dp[i+1][j] += j*dp[i][j]; // use one of those played songs as this position of playlist
					}
					if(j+1 <= N){ // if some songs have not played
						dp[i+1][j+1] += (N-j)*dp[i][j]; // choose one to play
					}
				}
			}

edge number of complete graph

inversion
	- definition: any i<j && a[i]>a[j]
	- inversion count
		brute force
	- total inversion count != sum of inversion count of all substring
	- maximum inversion count of a string = n*(n-1)/2
	- increase of inversion
		when there is a group of n characters left,
		then picking the i-th lexicographically one as the first character increases the number of inverted pairs by i,
		regardless of the positions of the previous or next characters.
		eg. abcdef -> dabcef, inversion count: 0 -> 3
	- slowly increase inversion
		search from right most position for pair which is not inversion, then change it to be inversion
		since we start from right, so for each action, we will just increase total inversion count by one (if all charactor different)
		eg. 1243 -> 1342, inversion count: 2 -> 3
		you may wonder why will always increase one,
		why wouldnt it cause more change in inversion but just the increase the inversion of the swapped pair
		because we start from right most, so in the process, all the things between the the pair will be larger than the pair,
		like 1243, because if they are smaller, they will be swapped previously

compare string integers when the string is to big
	eg. "1122321432432523432423" and "3204302840329843"
	bool com(string a, string b){
		if(a.size() == b.size()){
			return a > b;
		}
		return a.size() > b.size();
	}

in memorization, sometimes we will push the result to the next level, sometimes we will just add it after the next level return
they are in different situation
	- eg. 366 2.2 the function look something like this
		int back(int n, int d){
			...
			int u = -1;
			for(int i=0; i<2; i++){
				int t = back(n+1, d+a[i]);
				if(t!=-1){
					u = max(u, t);
				}
			}
			return u;
		}
		you can see that in above, we cache the variable d to next level instead of something like int t = back(n+1) + a[i],
		it is because the bound condition is also on variable d, if the bound condition is not on those variable, we can just 


use dynamic programming to compute combination nCr
	use the recursive relation nCr = (n-1)C(r-1) + (n-1)Cr and nC0 = nCn = 1



some topics that the web said is important for competition
	1) Graph algorithms: Breadth first search(BFS), Depth first search(DFS), Strongly connected components(SCC), Dijkstra, Floyd-Warshall, Minimum spanning tree(MST), Topological sort.
	2) Dynamic programming: Standard dynamic programming problems such as Rod Cutting, Knapsack, Matrix chain multiplication etc.
	3) Number theory: Modular arithmetic, Fermat’s theorem, Chinese remainder theorem(CRT), Euclidian method for GCD, Logarithmic Exponentiation, Sieve of Eratosthenes, Euler’s totient function.
	3) Greedy:  Standard problems such as Activity selection.
	4) Search techniques: Binary search, Ternary search and Meet in the middle.
	5) Data structures (Basic): Stacks, Queues, Trees and Heaps.
	6) Data structures (Advanced): Trie, Segment trees, Fenwick tree or Binary indexed tree(BIT), Disjoint data structures.
	7) Strings: Knuth Morris Pratt(KMP), Z algorithm, Suffix arrays/Suffix trees. These are bit advanced algorithms.
	8) Computational geometry: Graham-Scan for convex hull, Line sweep.
	9) Game theory: Basic principles of Nim game, Grundy numbers, Sprague-Grundy theorem.



base conversion




bit manipulation
	A = 1100
	B = 1010

	A & B = 1000
	A | B = 1110
	A ^ B = 0110
	~ A = 11110101 (this means not A)

	
	A | B                   Set union
	A & B                   Set intersection
	A & ~B                  Set subtraction
	ALL_BITS ^ A            Set negation
	A |= 1 << bit           Set bit
	A &= ~(1 << bit)        Clear bit
	(A & 1 << bit) != 0     Test bit

	check two bitmask is subset
		(a|b)==b
		(a&b)==a

	find power set

	check 2 mask overlap
		(a & b) == 0
		then join 2 mask
		a | b

	pop count, which is the hamming weight
		- __builtin_popcount()
		- fastest way
			int h(int n){
				int c = 0;
				while(n > 0){
					c++;
					n &= n-1;
				}
				return c;
			}
		- other method
			int h(int n) {
				int ret = 0;
				while ( n != 0 ) {
					ret += n % 2;
					n  /= 2;
				}
				return ret;
			}
			int h(int n) {
				int ret = 0;
				while ( n != 0 ) {
					ret += (n & 1);
					n  >>= 1;
				}
				return ret;
			}
			int cbit(int arg){
				int ret=0;
				while(arg){
					if(arg & 1) ret++;
						arg >>=1;
					}
				return ret;
			}

	find all consecutive subset
		for example
		00001
		00011
		00111
		01111
		11111
		00010
		00110
		01110
		11110
		00100
		01100
		11100
		01000
		11000
		10000
		for(int i=0; i<n; i++){
			for(int j=i+1; j<=n; j++){
				int mask = (1<<j)-(1<<i);
			}
		}

dynamic programming
	find combination
		// memorization
		int com(int n, int k){
			int &re = memo[n][k];
			if(re != -1){
				return re;
			}
			if(k==0 || k==n){
				return 1;
			}
			return re = c(n-1, k-1) + c(n-1, k)%mod;
		}
		// dp
		int dp[n+1][n+1] = {0};
		dp[0][0] = 1;
		for(int i=1; i<=n; i++){
			dp[i][0] = 1;
			for(int j=1; j<=n; j++){
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
			}
		}

	knapsack
		int v[] = {60, 100, 120};
		int w[] = {10, 20, 30};
		const int b = 50;
		const int n = 3;
		int dp[n+1][b+1];
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<=b; j++){
				if(dp[i][j] != -1){
					int t = j + w[i];
					if(t <= b){
						dp[i+1][t] = max(dp[i+1][t], dp[i][j]+v[i]);
					}
					dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				}
			}
		}
		int ans = 0;
		for(int i=0; i<=b; i++){
			ans = max(ans, dp[n][i]);
		}
		return ans;

	coin change problem

	throw n number of k sided dices, find how many ways the sum is equal to t
		brute force
			int a;
			int b;
			int t; 
			// c is how many accumulate so far
			// n is the current position of dice
			int go(int c, int n){
				if(n==a && c==t){
					return 1;
				}
				if(n==a){
					return 0;
				}
				int u = 0;
				for(int i=1; i<=min(t-c, b); i++){
					u += go(c+i, n+1);
				}
				return u;
			}
			int solve(){
				// number of dice
				a = 3;
				// how many side
				b = 6;
				// our target
				t = 5;
				return go(0, 0);
			}
		memorization

		dp
			// slightly different from geeksforgeeks, similar to topcoder 626 1.1 throw dice problem
			// a=number of dice, b=number of side, t=target
			int go(int a, int b, int t){
				vector< vector<int> > dp(a+1, vector<int>(t+1));
				dp[0][0] = 1;
				for(int i=0; i<a; i++){
					for(int j=0; j<=t; j++){
						for(int k=1; k<=b && j+k<=t; k++){
							dp[i+1][j+k] += dp[i][j];
						}
					}
				}
				return dp[a][t];
			}


	throw n number of k sided dices, return a vector indicating how many ways to get diff sum
		// no of dices
		int a = 3;
		// no of sides
		int b = 6;
		// dp[a+1][a*b+1], where a+1=the nth dice, a*b+1=all possibility of sum
		vector< vector<int> > dp(a+1, vector<int>(a*b+1));
		// the sum before throw is 0, so we state that we have 1 zero
		dp[0][0] = 1;
		// foreach dice
		for(int i=0; i<a; i++){
			// foreach possible sum, we add value from 1 to b to it and accumulate those value
			for(int j=0; j<a*b+1; j++){
				// foreach side of number, we add it to the previous sum
				// if the new number exceed bound(k+j<a*b+1), we prevent it
				for(int k=1; k<=b && k+j<a*b+1; k++){
					// i+1 is the next dice, j+k is the previous sum j plus the side value j,
					// and add the old sum dp[i][j] to new sum
					dp[i+1][j+k] += dp[i][j];
				}
			}
		}
		// slightly different version
		int a = 3;
		int b = 6;
		vector< vector<int> > dp(a+1, vector<int>(a*b+1));
		dp[0][0] = 1;
		for(int i=0; i<a; i++){
			// j<=i*b ensure the loop only loop through the number that have been used
			for(int j=0; j<=i*b; j++){
				for(int k=1; k<=b; k++){
					dp[i+1][j+k] += dp[i][j];
				}
			}
		}

	recursive find expected value
		law of total expected value
		e(x) = p(x)*(x + e(x-1))
		eg. expected value of sum of n dice throw
			double go(int n){
				if(n == 0){
					return 0; // for expected value, usually return 0, but for probability, usually return 1 or 0
				}
				double u = 0;
				for(int i=1; i<=6; i++){
					u += (i + go(n-1))/6;
				}
				return u;
			}			

	find number of ways, just like calculating combinatorics

	can change perspective in dp

	divide and conquer dp

	knapsack no of ways to achieve exact weight w and exact value v
		can reference TCCC 04 Semifinals 1 1.1
			for(int i=0; i<n; i++){
				dp[v[i]][w[i]] = true;
			}
			for(int i=0; i<=2500; i++){
				for(int j=0; j<weight; j++){
					if(dp[i][j]){
						for(int k=0; k<n; k++){
							if(i+v[k] <= 2500 && j+w[k] <= weight){
								dp[i+v[k]][j+w[k]] = true;
							}
						}
					}
				}
			}

	game who win

	game win probability
	

use double to store value larger than long long

div2 250 trick
	bitmask
		get powerset
		get all consecutive subset
		check subset
	array choose 2
	find all subsequence
	loop left half and right half
	compare substring
	consecutive
	foreach element of array A, compare elements lower than that element

in memorization, you can concate all input into a string to encode it

get longest prefix suffix of two string, concept from acrush
	int get_the_length_of_longest_prefix_suffix(string& s, string& p){
		for(int i=min(s.size(), p.size()); i>0; i--){
			if(s.substr(0, i) == p.substr(p.size()-i)){
				return i;
			}
		}
		return 0;
	}
	get prefix of length n
		a.substr(0, n)
	get suffix of length n
		a.substr(a.size() - n)

for trees, dont use reference instead of pointers because once the reference is set, it cannot be changed

we can memset inf for int by
	int inf = 0x40404040;
	memset(array, 0x40, sizeof(array));
		* noted that long long cannot use 0x4040404040404040, will overflow 

if dynamic programming has a loop, we can use
	bfs if it acts like an unweighted graph
	do more than just dp[i][j + i] = min(dp[i][j + i], dp[i][j] + 1);
		eg.
			if (dp[i][j] + 1 < dp[i][j + i]) {
				dp[i][j + i] = dp[i][j] + 1;
			}
			then if the new value is not worth trying, we will not go to the same loop again
	we cannot use memorization, since it will keep looping that we cannot decide which way is better,
	but we can use memorization if we introduce the third state
		problem example can look at EmoticonsDiv1

floyd warshall shortest path algorithm
	not work with negative cycle	
	code
		g is a adjacency matrix 
		for (int k = 0; k < 8; k++) { // foreach node as intermediate node of any pair of nodes, order of intermediate nodes doesnt matter
			for (int i = 0; i < 8; i++) { // foreach i and j loop over all pair of nodes
				for (int j = 0; j < 8; j++) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]); // update the graph if it is smaller with intermediate node
				}
			}
		}
			no matter what order of intermediate nodes, it will produce the same result
				eg.
					  a  b  c  d
					a 0  5  20 10
					b 5  0  5  oo
					c 20 5  0  25
					d 10 oo 25 0
					you can draw out the graph and try to change the order of intermediate node in the loop,
					you will find although the graph in the middle process may not be the same,
					but the final process will always be the same

breadth first search is also level order traversal
	that means it traversal the nodes level by level,
	so it can be used to find the shortest path of a graph that all edges have same weight
	eg.
		bool check_graph_connected_bfs() {
			vector<bool> v(100, false); // without this array, bfs will still work, but slower
			queue<int> q;
			q.push(0);
			while (!q.empty()) {
				int a = q.front();
				q.pop();
				for (int i = 0; i < w[a]; i++) {
					if (!v[i]) {
						v[i] = true;
						q.push(i);
					}
				}
			}
			return find(v.begin(), v.end(), 0) == v.end();
		}

dijkstra algorithm
	not work with negative edge
	actually dijkstra is similar to bfs but it just use a priority queue to determine to keep exploring the current shortest path
		that is, it is not level order, but shortest path order <- important
	noted that in the version of priority queue, we can omit the visited array, since the visited node will not be put into the queue again,
		becuase the path will be larger than the original one
	example without priority queue
		long long inf = 0x1010101010101010;
		bool v[8]; // hold visited nodes, without this, dijkstra will still work, but slower
		memset(v, 0, sizeof(v));
		long long d[8]; // hold smallest distance from start node to any nodes
		memset(d, 0x10, sizeof(d));
		d[0] = 0; // initialize the start node to be 0 distance
		for (int i = 0; i < 8 - 1; i++) { // at most have (no of total nodes - 1) operations
			int n = -1; // find the index of current smallest path node
			long long m = inf;
			for (int j = 0; j < 8; j++) {
				if (d[j] < m && !v[j]) {
					m = d[j];
					n = j;
				}
			}
			if (n == -1) { // if there is no path to keep going, we end earlier
				break;
			}
			v[n] = true; // mark this as visited
			for (int j = 0; j < 8; j++) {
				d[j] = min(d[j], d[n] + g[n][j]); // update the shortest distance from this node to other nodes
			}
		}
		return d[1];
	example with set
		long long inf = 0x1010101010101010;
		long long d[8];
		memset(d, 0x10, sizeof(d));
		d[0] = 0;
		set< pair<long long, int> > s;
		s.insert(make_pair(0, 0));
		while (!s.empty()) {
			int n = s.begin()->second;
			s.erase(s.begin());
			for (int i = 0; i < 8; i++) {
				long long t = d[n] + g[n][i];
				if (t < d[i]) {
					if (d[i] != inf) { // if d[i] == inf, it means it is not presented in the queue yet
						s.erase(s.find(make_pair(d[i], i))); // erase the original one
					}
					d[i] = t; // update the shortest distance array
					s.insert(make_pair(t, i)); // add back the updated one
				}
			}
		}
		return d[1];
	example with set alternative
		this time we do not need to remove original pair in the piority queue,
		because we have added a checking condition to check whether this is the latest pair
		long long d[8];
		memset(d, 0x10, sizeof(d));
		d[0] = 0;
		set< pair<long long, int> > s;
		s.insert(make_pair(0, 0));
		while (!s.empty()) {
			int n = s.begin()->second;
			long long nd = s.begin()->first;
			s.erase(s.begin());
			if (nd <= d[n]) { // this check if this is the latest pair
				for (int i = 0; i < 8; i++) {
					long long t = d[n] + g[n][i];
					if (t < d[i]) {
						d[i] = t;
						s.insert(make_pair(t, i));
					}
				}
			}
		}
		return d[1];
	example with priority queue
		c++ has a container called priority_queue, but it only can pop the largest one,
		if we want to apply it here, we have to override the compare operator,
		and also, the priority queue implementation is just same as the one with set
		
bellman ford algorithm
	can work with negative edge
	code
		long long inf = 0x1010101010101010;
		long long d[8];
		memset(d, 0x10, sizeof(d));
		d[0] = 0;
		for (int i = 0; i < 8 - 1; i++) { // at most need n - 1 operations to reach destination
			bool bo = true;
			for (int j = 0; j < 8; j++) {
				if (d[j] != inf) {
					for (int k = 0; k < 8; k++) {
						long long t = d[j] + g[j][k];
						if (t < d[k]) {
							bo = false;
							d[k] = t;
						}
					}
				}
			}
			if (bo) {
				break;
			}
		}
		return d[1];
	can detect negative edge by adding below code after all operations
		since at the end it should be in equalibrium state, so if the graph can still be updated, then it should exist a negative cycle
		bool exist_negative_cycle = false;
		for (int k = 0; k < 8; k++) {
			if (d[j] + g[j][k] < d[k]) {
				exist_negative_cycle = true;
			}
		}

heap data structure
	can implement as priority queue
	operations
		add
			O(log n)
		pop
			O(log n)
		top
			O(1)
		empty
			O(1)

