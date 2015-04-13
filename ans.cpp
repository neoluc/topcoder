
// 628 2.1
int BishopMove::howManyMoves(int r1, int c1, int r2, int c2) {
	if(r1==r2 && c1==c2){
		return 0;
	}
	for(int i=r1-1, j=c1+1; i>=0 && j<8; i--, j++){
		if(i==r2 && j==c2){
			return 1;
		}
		for(int m=i+1, n=j+1; m<8 && n<8; m++, n++){
			if(m==r2 && n==c2){
				return 2;
			}
		}
		for(int m=i+1, n=j+1; m>=0 && n>=0; m--, n--){
			if(m==r2 && n==c2){
				return 2;
			}
		}
	}
	for(int i=r1+1, j=c1-1; i<8 && j>=0; i++, j--){
		cout << i << ' ' << j << '\n';
		if(i==r2 && j==c2){
			return 1;
		}
		for(int m=i+1, n=j+1; m<8 && n<8; m++, n++){
			if(m==r2 && n==c2){
				return 2;
			}
		}
		for(int m=i+1, n=j+1; m>=0 && n>=0; m--, n--){
			if(m==r2 && n==c2){
				return 2;
			}
		}
	}
	for(int i=r1+1, j=c1+1; i<8 && j<8; i++, j++){
		if(i==r2 && j==c2){
			return 1;
		}
		for(int m=i+1, n=j-1; m<8 && n>=0; m++, n--){
			if(m==r2 && n==c2){
				return 2;
			}
		}
		for(int m=i-1, n=j+1; m>=0 && n<8; m--, n++){
			if(m==r2 && n==c2){
				return 2;
			}
		}
	}
	for(int i=r1-1, j=c1-1; i>=0 && j>=0; i--, j--){
		if(i==r2 && j==c2){
			return 1;
		}
		for(int m=i+1, n=j-1; m<8 && n>=0; m++, n--){
			if(m==r2 && n==c2){
				return 2;
			}
		}
		for(int m=i-1, n=j+1; m>=0 && n<8; m--, n++){
			if(m==r2 && n==c2){
				return 2;
			}
		}
	}
	return -1;
}
// better
int BishopMove::howManyMoves(int r1, int c1, int r2, int c2) {
	if(r1==r2 && c1==c2){
		return 0;
	}
	if((r1+c1)%2!=(r2+c2)%2){
		return -1;
	}
	if(r1+c1==r2+c2 || r1-r2==c1-c2){
		return 1;
	}
	return 2;
}

// 631 div2.1
int TaroGrid::getNumber(vector <string> grid) {
	
	vector<int> ans(grid[0].size(), 1);
	vector<int> temp(grid[0].size(), 1);
	
	for(int i=1; i<grid.size(); i++){
		for(int j=0; j<grid[i].size(); j++){
			
			if(grid[i][j] == grid[i-1][j]){
				temp[j]++;
			}else{
				ans[j] = max(ans[j], temp[j]);
				temp[j] = 1;
			}
			
		}
	}
	
	for(int i=0; i<temp.size(); i++){
		ans[i] = max(ans[i], temp[i]);
	}
	
	return *max_element(ans.begin(), ans.end());
}
// better
int TaroGrid::getNumber(vector <string> grid) {
	vector<int> c(grid[0].size(), 0);
	int m = -1;
	for(int i=0; i<grid.size(); i++){
		for(int j=0; j<grid[i].size(); j++){
			if(i==0){
				c[j]++;
			}else{
				if(grid[i][j] == grid[i-1][j]){
					c[j]++;
				}else{
					c[j] = 1;
				}	
			}
			m = max(m, c[j]);
		}
	}
	return m;
}
// other
int TaroGrid::getNumber(vector <string> grid) {
	vector<int> b(grid[0].size(), 0);
	vector<int> w(grid[0].size(), 0);
	int m = -1;
	for(int i=0; i<grid.size(); i++){
		for(int j=0; j<grid[i].size(); j++){
			if(grid[i][j]=='B'){
				b[j]++;
				w[j] = 0;
			}else{
				w[j]++;
				b[j] = 0;
			}
			m = max(m, b[j]);
			m = max(m, w[j]);
		}
	}
	return m;
}

// 635 div2.1
string IdentifyingWood::check(string s, string t) {
	int sp = 0;
	int tp = 0;
	
	int c=0;
	while(tp<t.size() && sp<s.size()){
		if(t[tp] == s[sp]){
			sp++;
			tp++;
			c++;
		}else{
			sp++;
		}
	}
	
	return (c==t.size())? "Yep, it's wood.": "Nope.";
}
string IdentifyingWood::check(string s, string t) {
	int i, j;
	for(i=0, j=0; i<s.size() && j<t.size(); i++){
		if(s[i] == t[j]){
			j++;
		}
	}
	if(j == t.size()){
		return "Yep, it's wood.";
	}
	return "Nope.";
}

// 634 div2.1
int MountainRanges::countPeaks(vector <int> heights) {
	int c=0;
	if(heights.size() == 1){
		return 1;
	}
	
	for(int i=0; i<heights.size(); i++){
		if((i==0 && heights[i]>heights[i+1]) || (i==heights.size()-1 && heights[i]>heights[i-1])){
			c++;
		}else{
			if(heights[i] > heights[i+1] && heights[i] > heights[i-1]){
				c++;
			}
		}
		
	}
	
	return c;
}
int MountainRanges::countPeaks(vector <int> heights) {
	
	int c = 0;
	
	heights.insert(heights.begin(), -1);
	heights.push_back(-1);
	
	for(int i=1; i<heights.size()-1; i++){
		if(heights[i] > heights[i+1] && heights[i] > heights[i-1]){
			c++;
		}
	}
	
	return c;
}

// 629 2.1
int RectangleCoveringEasy::solve(int holeH, int holeW, int boardH, int boardW) {
	if(holeW > holeH){
		int temp = holeW;
		holeW = holeH;
		holeH = temp;
	}
	if(boardW > boardH){
		int temp = boardW;
		boardW = boardH;
		boardH = temp;
	}
	
	if(boardW>=holeW && boardH>=holeH && (boardW>holeW || boardH>holeH)){
		return 1;
	}
	
	return -1;
}

// 626 2.1
int SumOfPower::findSum(vector <int> array) {
	int l=0, r=array.size()-1;
	int s = r;
	int ans = 0;
	while(l<=r){
		if(r >= array.size()){
			l=0;
			r=--s;
			continue;
		}
		for(int i=l; i<=r; i++){
			ans += array[i];
		}
		
		l++;
		r++;
	}
	return ans;
}
int SumOfPower::findSum(vector <int> array) {
	int i=0, j=array.size()-1;
	int ans = 0;
	while(i<=j){
		int t = j;
		for(;j<array.size(); i++, j++){
			for(int k=i; k<=j; k++){
				ans += array[k];
			}
		}
		i = 0;
		j = --t;
	}
	return ans;
}
// better
int SumOfPower::findSum(vector <int> array) {
	int ans = 0;
	for(int i=0; i<array.size(); i++){
		for(int j=i; j<array.size(); j++){
			for(int k=i; k<=j; k++){
				ans += array[k];
			}
		}
	}
	return ans;
}
// even better
int SumOfPower::findSum(vector <int> array) {
	int ans = 0;
	for(int i=0; i<array.size(); i++){
		int t = 0;
		for(int j=i; j<array.size(); j++){
			t += array[j];
			ans += t;
		}
	}
	return ans;
}

// 623 2.1
// failed in test case
// {{-31, -33, 3, -10, -17, -27, -13, 4, -5, -34, -25, -30, -14, -32, -35, -11, -12, -28, -10, -8, -4, -28, -29, -26, 0, -28, -8, -11, -35, -9, -10, -28, 5, -7, -27, -30, -36, -24, 1, -5, -29, -14, -22, -13, -19, -25, -7}, {372, 147, 10, 444, 176, 238, 102, 69, 81, 366, 242, 298, 264, 371, 158, 41, 440, 290, 98, 108, 454, 375, 235, 249, 417, 375, 399, 44, 158, 52, 98, 354, 6, 119, 283, 197, 216, 381, 29, 81, 297, 437, 272, 127, 319, 339, 408}}
string CatchTheBeatEasy::ableToCatchAll(vector <int> x, vector <int> y) {
	
	set<int> a;
	bool found = false;
	int ti;
	int cx = 0;
	int cy = 0;
	
	for(int j=0; j<x.size(); j++){
		int ts = 999999;
		for(int i=0; i<x.size(); i++){
			if(a.find(i) == a.end()){
				int s = y[i] - abs(cx - x[i]);
				if(s >= 0 && s < ts){
					ts = s;
					ti = i;
					found = true;
				}			
			}
		}
		
		if(found){
			int d = abs(cx - x[ti]);
			for(int i=0; i<y.size(); i++){
				y[i] -= d;
			}
			cx = x[ti];
			cy = y[ti];
			a.insert(ti);
			found = false;
		}else{
			return "Not able to catch";
		}
	}
	
	return "Able to catch";
}
// correct
struct coor{
	int x;
	int y;
};
bool compare(const coor &i, const coor &j){
	return i.y<j.y;
}
string CatchTheBeatEasy::ableToCatchAll(vector <int> x, vector <int> y) {
	vector<coor> coors;
	for(int i=0; i<x.size(); i++){
		coor temp;
		temp.x = x[i];
		temp.y = y[i];
		coors.push_back(temp);
	}
	
	sort(coors.begin(), coors.end(), compare);
	
	int tx = 0, ty = 0;
	for(int i=0; i<coors.size(); i++){
		if(abs(tx - coors[i].x) > coors[i].y - ty){
			return "Not able to catch";
		}
		tx = coors[i].x;
		ty = coors[i].y;
	}
	
	return "Able to catch";
}
//better
string CatchTheBeatEasy::ableToCatchAll(vector <int> x, vector <int> y) {
	vector< pair<int, int> > v(x.size());
	for(int i=0; i<x.size(); i++){
		v[i] = make_pair(y[i], x[i]);
	}
	sort(v.begin(), v.end());
	int cx = 0;
	int cy = 0;
	for(int i=0; i<v.size(); i++){
		if(abs(v[i].second-cx) > v[i].first-cy){
			return "Not able to catch";
		}
		cx = v[i].second;
		cy = v[i].first;
	}
	return "Able to catch";
}

// 622 2.1
int FibonacciDiv2::find(int N) {
	int a = 0;
	int b = 1;
	while(b<=N){
		int c = a+b;
		a = b;
		b = c;
	}
	return min(b-N, N-a);
}

// 620 2.1
vector <int> CandidatesSelectionEasy::sort(vector <string> score, int x) {
	vector< pair<int, int> > v;
	for(int i=0; i<score.size(); i++){
		v.push_back(make_pair(score[i][x], i));
	}
	::sort(v.begin(), v.end());
	
	vector<int> vi(v.size());
	for(int i=0; i<v.size(); i++){
		vi[i] = v[i].second;
	}
	return vi;
}

// 619 2.1
int GoodCompanyDivTwo::countGood(vector <int> superior, vector <int> workType) {
	int n = superior.size();
	vector< set<int> > v(n);
	vector<int> vn(n, 0);
	for(int i=n-1; i>=0; i--){
		v[i].insert(workType[i]);
		vn[i]++;
		if(superior[i] >= 0){
			v[superior[i]].insert(workType[i]);
			vn[superior[i]]++;
		}	
	}
	int c = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i].size() == vn[i]){
			c++;
		}
	}
	
	return c;
}

// 240 2.1 this is wrong answer of first try
string Pronunciation::canPronounce(vector <string> words) {

	vector<int> m((int)'z');

	for(int k=0; k<(int)'z'; k++){
		if(k==(int)'a'||k==(int)'A'||k==(int)'e'||k==(int)'E'||k==(int)'i'||k==(int)'I'||k==(int)'o'||k==(int)'O'||k==(int)'u'||k==(int)'U'){
			m[k] = 1;
		}else{
			m[k] = 0;
		}
	}
	
	for(int i=0; i<words.size(); i++){
		char tc;
		int cc = 0, cvs = 0, cvd = 0;
		for(int j=0; j<words[i].size(); j++){
			char c = words[i][j];
			if(j==0){
				if(m[(int)c] == 0){
					cc++;
				}else{
					cvs++;
					cvd++;
				}
			}else{
				if(m[(int)c]==0 && m[(int)tc]==0){
					cc++;
					cvs=1;
					cvd=1;
					if(cc>=3){
						return words[i];
					}
				}else if(m[(int)c]==1 && m[(int)tc]==1){
					if(c!=32 || c+32!=tc || c-32!=tc){
						cvd++;
						cvs=1;
						cc=1;
					}else{
						cvs++;
						cvd=1;
						cc=1;
						if(cvd>=2){
							return words[i];
						}
					}
				}else{
					cc = cvd = cvs = 1;
				}
			}
			tc = c;
		}
	}
	
	return "";
}
// correct
string Pronunciation::canPronounce(vector <string> words) {
	string v = "aeiouAEIOU";
	for(int i=0; i<words.size(); i++){
		int cc = 0, cvs = 0, cvd = 0;
		for(int j=0; j<words[i].size(); j++){
			if(v.find(words[i][j])==string::npos){
				cc++;
				cvs = cvd = 0;
			}else{
				if(j==0){
					cvs++;
					cvd++;
				}else{
					if(words[i][j]==words[i][j-1] || (int)words[i][j]+32 ==(int)words[i][j-1] || (int)words[i][j]-32==(int)words[i][j-1]){
						cvs++;
					}else{
						cvd++;
					}
				}
				cc = 0;
			}
			cout << words[i][j] << " cc " << cc << " cvs " << cvs << " cvd " << cvd << endl;
			if(cc >= 3 || cvd >= 2){
				return words[i];
			}
		}
	}
	return "";
}
// correct and better
bool isv(char c){
	return c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U';
}
string Pronunciation::canPronounce(vector <string> words) {
	for(int i=0; i<words.size(); i++){
		int c=0, v=0;
		for(int j=0; j<words[i].size(); j++){
			if(isv(words[i][j])){
				if(j==0 || (j>0  && tolower(words[i][j])!=tolower(words[i][j-1]))){
					v++;
				}
				c=0;
			}else{
				c++;
				v=0;
			}
			if(c>=3 || v>=2){
				return words[i];
			}
		}
	}
	return "";
}
// another
string Pronunciation::canPronounce(vector <string> words) {
	for(int i=0; i<words.size(); i++){
		int c = 0;
		int v = 0;
		for(int j=0; j<words[i].size(); j++){
			if(!isv(words[i][j])){
				c++;
				v = 0;
			}else{
				v++;
				c = 0;
			}
			if(v > 1 && tolower(words[i][j])!=tolower(words[i][j-1])){
				return words[i];
			}
			if(c > 2){
				return words[i];
			}
		}
	}
	return "";
}
// another
string Pronunciation::canPronounce(vector <string> words) {
	for(int i=0; i<words.size(); i++){
		int c = 1;
		for(int j=1; j<words[i].size(); j++){
			if(!isv(words[i][j]) && !isv(words[i][j-1])){
				c++;
				if(c>=3){
					return words[i];
				}
			}else if(isv(words[i][j]) && isv(words[i][j-1]) && tolower(words[i][j]) != tolower(words[i][j-1])){
				c++;
				return words[i];
			}else{
				c = 1;
			}
		}
	}
	return "";
}

// 606 2.1
string EllysSubstringSorter::getMin(string S, int L) {
	string ans = S;
	for(int i=0; i<=S.size()-L; i++){
		string t = S;
		sort(t.begin()+i, t.begin()+i+L);
		ans = min(ans, t);
	}
	return ans;
}

// 611 2.1
string InterestingNumber::isInteresting(string x) {
	vector<int> c(x.size(), 0);
	for(int i=0; i<x.size(); i++){
		if(c[x[i]-'0']==0 && x[i+x[i]-'0'+1] != x[i]){
			return "Not interesting";
		}
		c[x[i]-'0']++;
		if(c[x[i]-'0']>2){
			return "Not interesting";
		}
	}
	return "Interesting";
}

// 583 2.1
string SwappingDigits::minNumber(string num) {
	
	string ans = num;
	
	for(int i=0; i<num.size(); i++){
		for(int j=0; j<num.size(); j++){
			string t = num;
			char ct = t[i];
			t[i] = t[j];
			t[j] = ct;
			if(t < ans && t[0]!='0'){
				ans = t;
			}
		}
	}
	return ans;
}
// better
string SwappingDigits::minNumber(string num) {
	string ans = num;
	for(int i=0; i<num.size(); i++){
		for(int j=i+1; j<num.size(); j++){
			swap(num[i], num[j]);
			if(num[0]!='0' && num<ans){
				ans = num;
			}
			swap(num[i], num[j]);
		}
	}
	return ans;
}

// 221 2.1
vector <string> EqualSubstrings::getSubstrings(string str) {
	string ansx = "";
	string ansy = "";
	for(int i=0; i<=str.size(); i++){
		string x = str.substr(0, i);
		string y = str.substr(i, str.size()-i);
		int a = 0;
		int b = 0;
		for(int j=0; j<x.size(); j++){
			if(x[j]=='a'){
				a++;
			}
		}
		for(int k=0; k<y.size(); k++){
			if(y[k]=='b'){
				b++;
			}
		}
		if(a==b && x.size()>=ansx.size()){
			ansx = x;
			ansy = y;
		}
	}
	vector<string> v(2);
	v[0] = ansx;
	v[1] = ansy;
	return v;
}

// 332 2.1
bool isw(char c){
	return (c>='a'&&c<='z') || (c>='A'&&c<='Z');
}
double TextStatistics::averageLength(string text) {
	vector<int> c;
	for(int i=0; i<text.size(); i++){
		if(!isw(text[i])){
			c.push_back(i);
		}
	}
	
	c.insert(c.begin(), -1);
	c.push_back(text.size());
	
	double tc = 0;
	int tn = 0;
	
	for(int i=0; i<c.size()-1; i++){
		int l = c[i+1] - c[i] - 1;
		if(l>0){
			tc += l;
			tn++;
		}
	}
	
	return tn==0? 0: tc/tn;
}
double TextStatistics::averageLength(string text) {
	int a = 0;
	int b = 0;
	for(int i=0; i<text.size(); i++){
		if(isalpha(text[i])){
			a++;
		}
		if((i==0 && isalpha(text[i])) || (isalpha(text[i]) && !isalpha(text[i-1]))){
			b++;
		}
	}
	return b==0? 0: (double)a/b;
}
// even better
double TextStatistics::averageLength(string text) {
	int a = 0;
	int b = 0;
	for(int i=0; i<text.size(); i++){
		if(isalpha(text[i])){
			a++;
		}
		if((i==0 || !isalpha(text[i-1])) && isalpha(text[i])){
			b++;
		}
	}
	return b==0? 0: a*1.0/b;
}


// 559 2.1
int BlockTower::getTallest(vector <int> blockHeights) {
	int ans = -1;
	for(int i=0; i<=blockHeights.size(); i++){
		int t = 0;
		for(int j=0; j<i; j++){
			if(blockHeights[j]%2==0){
				t += blockHeights[j];
			}
		}
		for(int k=i; k<blockHeights.size(); k++){
			if(blockHeights[k]%2==1){
				t += blockHeights[k];
			}
		}
		ans = max(ans, t);
	}
	return ans;
}
// seems better
int BlockTower::getTallest(vector <int> blockHeights) {
	int ans = -1;
	for(int i=0; i<=blockHeights.size(); i++){
		int t = 0;
		for(int j=0; j<blockHeights.size(); j++){
			if((j<i && blockHeights[j]%2==0) || (j>=i && blockHeights[j]%2==1)){
				t += blockHeights[j];
			}
			ans = max(ans, t);
		}
	}
	return ans;
}


// 198 2.1
// brute force
int Reppity::longestRep(string input) {
	int ans = 0;
	int n = input.size();
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			for(int k=j+1; k<n; k++){
				for(int m=k; m<n; m++){
					string a = input.substr(i, j-i+1);
					string b = input.substr(k, m-k+1);
					if(a == b){
						ans = max(ans, (int)a.size());
					}
				}
			}
		}
	}
	return ans;
}
// better
int Reppity::longestRep(string input) {
	int ans = 0;
	for(int i=0; i<input.size(); i++){
		for(int j=i+1; j<input.size(); j++){
			if(input[j] == input[i]){
				int t = 0;
				int a = i;
				int b = j;
				while(input[a]==input[b] && a<j && b<input.size()){
					t++;
					a++;
					b++;
				}
				ans = max(ans, t);
			}
		}
	}
	return ans;
}
int Reppity::longestRep(string input) {
	int ans = -1;
	int n = input.size();
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int t = 0;
			for(int a=i, b=j; a<j && b<n && input[a]==input[b]; a++, b++){
				t++;
			}
			ans = max(ans, t);
		}
	}
	return ans;
}

// 251 2.1
int Elections::visit(vector <string> likelihoods) {
	vector<double> v(likelihoods.size());
	for(int i=0; i<likelihoods.size(); i++){
		int t = 0;
		for(int j=0; j<likelihoods[i].size(); j++){
			if(likelihoods[i][j]=='1'){
				t++;
			}
		}
		v[i] = likelihoods[i].size()==0? 0: (double)t/likelihoods[i].size();
	}
	return min_element(v.begin(), v.end()) - v.begin();
}
// better
int Elections::visit(vector <string> likelihoods) {
	int ans = -1;
	double b = numeric_limits<double>::max();
	for(int i=0; i<likelihoods.size(); i++){
		int x = 0;
		for(int j=0; j<likelihoods[i].size(); j++){
			if(likelihoods[i][j]=='1'){
				x++;
			}
		}
		double t = x*1.0/likelihoods[i].size();
		if(t < b){
			ans = i;
			b = t;
		}
	}
	return ans;
}

// 291 2.1
// a prime number >1 and only divided by 1 or itself
bool isp(int n){
	if(n<2) return false;
	if(n==2) return true;
	if(n%2==0) return false;
	int m = sqrt(n);
	for(int i=3; i<=m; i+=2){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
int FarFromPrimes::count(int A, int B) {
	int ans = 0;
	for(int i=A; i<=B; i++){
		int t = true;
		for(int j=i-10; j<=i+10; j++){
			if(isp(j)){
				t = false;
				break;
			}
		}
		if(t){
			ans++;
		}
	}
	return ans;
}

// 492 2.1
int TimeTravellingCellar::determineProfit(vector <int> profit, vector <int> decay) {
	int ans = -1;
	for(int i=0; i<profit.size(); i++){
		for(int j=0; j<decay.size(); j++){
			if(i!=j){
				ans = max(profit[i]-decay[j], ans);
			}
		}
	}
	return ans;
}

// 439 2.1
// wrong answer, aimed for rectengle, not square...
int SquareOfDigits::getMax(vector <string> data) {
	int ans = 1;
	for(int i=0; i<data.size(); i++){
		for(int j=0; j<data[i].size(); j++){
			vector<int> x;
			for(int k=j+1; k<data[i].size(); k++){
				if(data[i][k]==data[i][j]){
					x.push_back(k);
				}
			}
			vector<int> y;
			for(int m=i+1; m<data.size(); m++){
				if(data[m][j]==data[i][j]){
					y.push_back(m);
				}
			}
			for(int n=0; n<x.size(); n++){
				for(int o=0; o<y.size(); o++){
					if(data[y[o]][x[n]]==data[i][j]){
						ans = max(ans, (x[n]-j+1)*(y[o]-i+1));
					}
				}
			}
		}
	}
	return ans;
}
// correct
int SquareOfDigits::getMax(vector <string> data) {
	int ans = 1;
	for(int i=0; i<data.size(); i++){
		for(int j=0; j<data[i].size(); j++){
			vector<int> x;
			for(int k=j+1; k<data[i].size(); k++){
				if(data[i][k]==data[i][j]){
					x.push_back(k);
				}
			}
			vector<int> y;
			for(int m=i+1; m<data.size(); m++){
				if(data[m][j]==data[i][j]){
					y.push_back(m);
				}
			}
			for(int n=0; n<x.size(); n++){
				for(int o=0; o<y.size(); o++){
					if(data[y[o]][x[n]]==data[i][j] && x[n]-j+1==y[o]-i+1){
						ans = max(ans, (x[n]-j+1)*(y[o]-i+1));
					}
				}
			}
		}
	}
	return ans;
}
// better
int SquareOfDigits::getMax(vector <string> data) {
	int ans = 1;
	for(int i=0; i<data.size(); i++){
		for(int j=0; j<data[i].size(); j++){
			for(int k=j+1; k<data[i].size(); k++){
				if(data[i][k]==data[i][j] && i+k-j<data.size() && data[i+k-j][j]==data[i][j] && data[i+k-j][k]==data[i][j]){
					ans = max(ans, (k-j+1)*(k-j+1));
				}
			}
		}
	}
	return ans;
}

// 334 2.1
int SupermarketDiscount::minAmount(vector <int> goods) {
	int ans = numeric_limits<int>::max();
	for(int i=0; i<goods.size(); i++){
		int t = goods[i]>=50?goods[i]-10:goods[i];
		for(int j=0; j<goods.size(); j++){
			if(i!=j){
				t+=goods[j]>=50?goods[j]-10:goods[j];
			}
		}
		ans = min(ans, t);
	}
	
	for(int i=0; i<goods.size(); i++){
		for(int j=i+1; j<goods.size(); j++){
			int t = goods[i]+goods[j];
			t = t>=50? t-10: t;
			for(int k=0; k<goods.size(); k++){
				if(k!=i && k!=j){
					t+=goods[k]>=50?goods[k]-10:goods[k];
				}
			}
			ans = min(ans, t);
		}
	}
	
	int t = goods[0]+goods[1]+goods[2];
	t = t>=50? t-10: t;
	ans = min(ans, t);
	
	return ans;
}
// better using binary to find all subset
int SupermarketDiscount::minAmount(vector <int> goods) {
	int ans = numeric_limits<int>::max();
	for(int i=0; i<1<<goods.size(); i++){
		int d = 0;
		int n = 0;
		for(int j=0; j<goods.size(); j++){
			if(i&(1<<j)){
				d += goods[j];
			}else{
				n += goods[j]>=50? goods[j]-10: goods[j];
			}
		}
		d = d>=50? d-10: d;
		ans = min(ans, d + n);
	}
	return ans;
}

// 610 2.1
int DivideByZero::CountNumbers(vector <int> numbers) {
	vector<int> v(101, 0);
	for(int i=0; i<numbers.size(); i++){
		v[numbers[i]]++;
	}
	
	for(int i=0; i<numbers.size(); i++){
		for(int j=0; j<numbers.size(); j++){
			if(numbers[i] > numbers[j]){
				int t = numbers[i]/numbers[j];
				if(v[t]==0){
					numbers.push_back(t);
					v[t]++;
					i=0;
					j=-1;
				}
			}
		}
	}
	return numbers.size();
}
// seems better
int DivideByZero::CountNumbers(vector <int> numbers) {
	int n = 0;
	while(numbers.size() > n){
		n = numbers.size();
		for(int i=0; i<numbers.size(); i++){
			for(int j=i+1; j<numbers.size(); j++){
				if(numbers[i]!=numbers[j]){
					int a = max(numbers[i], numbers[j]);
					int b = min(numbers[i], numbers[j]);
					int c = a/b;
					if(find(numbers.begin(), numbers.end(), c)==numbers.end()){
						numbers.push_back(c);
					}
				}
			}
		}
	}
	return (int)numbers.size();
}

// 575 2.1
int TheSwapsDivTwo::find(vector <int> sequence) {
	set< vector<int> > s;
	for(int i=0; i<sequence.size(); i++){
		for(int j=0; j<sequence.size(); j++){
			if(i!=j){
				vector<int> v = sequence;
				int t = v[i];
				v[i] = v[j];
				v[j] = t;
				s.insert(v);
			}
		}
	}
	return s.size();
}
//better
int TheSwapsDivTwo::find(vector <int> sequence) {
	set< vector<int> > s;
	for(int i=0; i<sequence.size(); i++){
		for(int j=i+1; j<sequence.size(); j++){
			swap(sequence[i], sequence[j]);
			s.insert(sequence);
			swap(sequence[i], sequence[j]);
		}
	}
	return s.size();
}

// 207 2.1
int TransportCounting::countBuses(int speed, vector <int> positions, vector <int> velocities, int time) {
	int a = speed*time;
	int ans = 0;
	for(int i=0; i<positions.size(); i++){
		int t = positions[i]+velocities[i]*time;
		if(a>=t || positions[i]==0){
			ans++;
		}
	}
	return ans;
}

// 473 2.1
vector <int> OnTheFarmDivTwo::animals(int heads, int legs) {
	if(heads==0 && legs==0){
		return vector<int>(2, 0);
	}
	double chickens = (double)(4*heads-legs)/2;
	double cows = heads - chickens;
	double d1;
	double d2;
	if(cows<0 || chickens<0 || modf(cows, &d1)!=0.0 || modf(chickens, &d2)!=0.0){
		return vector<int>();
	}
	
	vector<int> ans(2);
	ans[0] = chickens;
	ans[1] = cows;
	return ans;
}

// 590 2.1
string FoxAndGomoku::win(vector <string> board) {
	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[i].size(); j++){
			if(board[i][j]=='o'){
				if(j+4<board[i].size() && board[i][j+1]=='o' && board[i][j+2]=='o' && board[i][j+3]=='o' && board[i][j+4]=='o'){
					return "found";
				}else if(j+4<board[i].size() && i+4<board.size() && board[i+1][j+1]=='o' && board[i+2][j+2]=='o' && board[i+3][j+3]=='o' && board[i+4][j+4]=='o'){
					return "found";
				}else if(i+4<board.size() && board[i+1][j]=='o' && board[i+2][j]=='o' && board[i+3][j]=='o' && board[i+4][j]=='o'){
					return "found";
				}else if(j-4<board[i].size() && i+4<board.size() && board[i+1][j-1]=='o' && board[i+2][j-2]=='o' && board[i+3][j-3]=='o' && board[i+4][j-4]=='o'){
					return "found";
				}
			}
		}
	}
	return "not found";
}
string FoxAndGomoku::win(vector <string> board) {
	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[i].size(); j++){
			if(j+4<board[i].size() && board[i][j]=='o' && board[i][j+1]=='o' && board[i][j+2]=='o' && board[i][j+3]=='o' && board[i][j+4]=='o'){
				return "found";
			}
			if(i+4<board.size() && board[i][j]=='o' && board[i+1][j]=='o' && board[i+2][j]=='o' && board[i+3][j]=='o' && board[i+4][j]=='o'){
				return "found";
			}
			if(j+4<board[i].size() && i+4<board.size() && board[i][j]=='o' && board[i+1][j+1]=='o' && board[i+2][j+2]=='o' && board[i+3][j+3]=='o' && board[i+4][j+4]=='o'){
				return "found";
			}
			if(j-4>=0 && i+4<board.size() && board[i][j]=='o' && board[i+1][j-1]=='o' && board[i+2][j-2]=='o' && board[i+3][j-3]=='o' && board[i+4][j-4]=='o'){
				return "found";
			}
		}
	}
	return "not found";
}

// 452 2.1
// there is a better version without brute force
int EggCartons::minCartons(int n) {
	int ans = 100;
	for(int i=0; i<=n/8; i++){
		for(int j=0; j<=n/6; j++){
			if(6*j+8*i==n){
				ans = min(ans, i+j);
			}
		}
	}
	return ans==100? -1: ans;
}

// 595 2.1
int LittleElephantAndBallsAgain::getNumber(string S) {
	int c = 1;
	int n = 1;
	for(int i=1; i<S.size(); i++){
		if(S[i] == S[i-1]){
			c++;
		}else{
			c = 1;
		}
		n = max(n, c);
	}
	return S.size() - n;
}
// alternative worse answer
int LittleElephantAndBallsAgain::getNumber(string S) {
	int ans = 0;
	for(int i=0; i<S.size(); i++){
		for(int j=i; j<S.size(); j++){
			set<int> s;
			for(int k=i; k<=j; k++){
				s.insert(S[k]);
			}
			if(s.size()==1){
				ans = max(ans, j-i+1);
			}
		}
	}
	return S.size() - ans;
}

// 314 2.1
int MooingCows::dissatisfaction(vector <string> farmland) {
	int ans = numeric_limits<int>::max();
	vector< pair<int, int> > v;
	for(int i=0; i<farmland.size(); i++){
		for(int j=0; j<farmland[i].size(); j++){
			if(farmland[i][j]=='C'){
				v.push_back(make_pair(j, i));
			}
		}
	}
	
	for(int i=0; i<v.size(); i++){
		int t = 0;
		for(int j=0; j<v.size(); j++){
			if(i!=j){
				t += (v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second - v[j].second)*(v[i].second - v[j].second);
			}
		}
		ans = min(ans, t);
	}
	return ans;
}

// 466 2.1
// find powerset
string LotteryTicket::buy(int price, int b1, int b2, int b3, int b4) {
	vector<int> v(4);
	v[0] = b1;
	v[1] = b2;
	v[2] = b3;
	v[3] = b4;
	for(int i=0; i<v.size(); i++){
		if(v[i]==price){
			return "POSSIBLE";
		}
		for(int j=i+1; j<v.size(); j++){
			if(v[i]+v[j]==price){
				return "POSSIBLE";
			}
			for(int k=j+1; k<v.size(); k++){
				if(v[i]+v[j]+v[k]==price){
					return "POSSIBLE";
				}
				for(int m=k+1; m<v.size(); m++){
					if(v[i]+v[j]+v[k]+v[m]==price){
						return "POSSIBLE";
					}
				}
			}
		}
	}
	return "IMPOSSIBLE";
}
// other answer using binary approach
string LotteryTicket::buy(int price, int b1, int b2, int b3, int b4) {
	vector<int> v(4);
	v[0] = b1;
	v[1] = b2;
	v[2] = b3;
	v[3] = b4;
	for(int i=0; i<1<<v.size(); i++){
		int t = 0;
		for(int j=0; j<v.size(); j++){
			if(i & (1<<j)){
				t += v[j];
			}
		}
		if(price==t){
			return "POSSIBLE";
		}
	}
	return "IMPOSSIBLE";
}
// use backtrack to check subset sum
int back(vector<int>& v, int c, int t, int n){
	if(c == t){
		return 1;
	}
	for(int i=n; i<v.size(); i++){
		if(back(v, c+v[i], t, i+1)){
			return 1;
		}
	}
	return 0;
}
string LotteryTicket::buy(int price, int b1, int b2, int b3, int b4) {
	vector<int> v(4);
	v[0] = b1;
	v[1] = b2;
	v[2] = b3;
	v[3] = b4;
	int ans = back(v, 0, price, 0);
	return ans==0? "IMPOSSIBLE": "POSSIBLE";
}

// 509 2.1
bool isp(string s){
	for(int i=0, j=s.size()-1; i<j; i++, j--){
		if(s[i]!=s[j]){
			return false;
		}
	}
	return true;
}
int PalindromizationDiv2::getMinimumCost(int X) {
	int ans = X;
	for(int i=1; i<X*2; i++){
		ostringstream o;
		o << i;
		if(isp(o.str())){
			ans = min(ans, abs(X-i));
		}
	}
	return ans;
}

// 162 2.1
int LCMRange::lcm(int first, int last) {
	int i=last;
	int ans;
	while(1){
		bool b = true;
		for(int j=first; j<=last; j++){
			if(i%j!=0){
				b = false;
				break;
			}
		}
		if(b){
			ans = i;
			break;
		}
		i++;
	}
	return ans;
}
// better
int gcd(int a, int b){
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}
int LCMRange::lcm(int first, int last) {
	int ans = first;
	for(int i=first; i<=last; i++){
		ans = ans*i / gcd(ans, i);
	}
	return ans;
}
int LCMRange::lcm(int first, int last) {
	int ans = first;
	for(int i=first+1; i<=last; i++){
		ans = ans*i/gcd(ans, i);
	}
	return ans;
}

// 601 2.1
int WinterAndMandarins::getNumber(vector <int> bags, int K) {
	sort(bags.begin(), bags.end());
	int ans = numeric_limits<int>::max();
	for(int i=0, j=K-1; j<bags.size(); i++, j++){
		ans = min(ans, bags[j]-bags[i]);
	}
	return ans;
}
int WinterAndMandarins::getNumber(vector <int> bags, int K) {
	sort(bags.begin(), bags.end());
	int ans = numeric_limits<int>::max();
	for(int i=0; i+K-1<bags.size(); i++){
		ans = min(ans, bags[i+K-1]-bags[i]);
	}
	return ans;
}
int WinterAndMandarins::getNumber(vector <int> bags, int K) {
	sort(bags.begin(), bags.end());
	int ans = numeric_limits<int>::max();
	for(int i=0; i<bags.size()-K+1; i++){
		ans = min(ans, bags[i+K-1]-bags[i]);
	}
	return ans;
}

// 341 2.1
int ChangingString::distance(string A, string B, int K) {
	vector<int> v(A.size());
	for(int i=0; i<A.size(); i++){
		v[i] = abs(A[i]-B[i]);
	}
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for(int i=0; i<v.size(); i++){
		if(i<K){
			if(v[i]==0){
				ans++;
			}
		}else{
			ans += v[i];
		}
	}
	return ans;
}

// 639 2.1
string ElectronicPetEasy::isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
	vector<int> a(t1);
	vector<int> b(t2);
	for(int i=0; i<t1; i++){
		a[i] = st1+p1*i;
	}
	for(int i=0; i<t2; i++){
		b[i] = st2+p2*i;
	}
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			if(a[i]==b[j]){
				return "Difficult";
			}
		}
	}
	return "Easy";
}
// better
string ElectronicPetEasy::isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
	set<int> s;
	for(int i=0; i<t1; i++){
		s.insert(st1+p1*i);
	}
	for(int i=0; i<t2; i++){
		s.insert(st2+p2*i);
	}
	return s.size()==t1+t2? "Easy": "Difficult";
}

// 285 2.1
// there is other approach that use sort
int BasketsWithApples::removeExcess(vector <int> apples) {
	int ans = -1;
	for(int i=0; i<apples.size(); i++){
		int t = 0;
		for(int j=0; j<apples.size(); j++){
			if(apples[j]>=apples[i]){
				t += apples[i];
			}
		}
		ans = max(ans, t);
	}
	return ans;
}

// 259 2.1
int CompetitionStatistics::consecutiveGrowth(vector <int> ratingChanges) {
	int ans = 0;
	int p = 0;
	for(int i=0; i<ratingChanges.size(); i++){
		if(ratingChanges[i]>0){
			p++;
		}else{
			p = 0;
		}
		ans = max(ans, p);
	}
	return ans;
}

// 177 2.1
// do not fully understand
int Stairs::designs(int maxHeight, int minWidth, int totalHeight, int totalWidth) {
	vector<int> w;
	for(int i=minWidth; i<=totalWidth; i++){
		if(totalWidth%i==0){
			w.push_back(totalWidth/i);
		}
	}
	vector<int> h;
	for(int i=1; i<=maxHeight; i++){
		if(totalHeight%i==0){
			h.push_back(totalHeight/i);
		}
	}
	int ans = 0;
	for(int i=0; i<w.size(); i++){
		for(int j=0; j<h.size(); j++){
			if(w[i]+1 == h[j]){
				ans++;
			}
		}
	}
	return ans;
}

// 558 2.1
// other solution will use two array to store the testing point and loop through to test, refer to editorial
int SurroundingGameEasy::score(vector <string> cost, vector <string> benefit, vector <string> stone) {
	int ans = 0;
	for(int i=0; i<stone.size(); i++){
		for(int j=0; j<stone[i].size(); j++){
			if(stone[i][j]=='o'){
				ans -= cost[i][j]-'0';	
			}
			if(stone[i][j]=='o' || ( (i==0 || stone[i-1][j]=='o') && (j==stone[i].size()-1 || stone[i][j+1]=='o') && (i==stone.size()-1 || stone[i+1][j]=='o') && (j==0 || stone[i][j-1]=='o') )){
				ans += benefit[i][j]-'0';
			}
		}
	}
	return ans;
}

// 556 2.1
int ChocolateBar::maxLength(string letters) {
	int ans = 0;
	for(int i=0; i<letters.size(); i++){
		set<int> s;
		for(int j=i; j<letters.size(); j++){
			if(s.find(letters[j])==s.end()){
				s.insert(letters[j]);
				ans = max(ans, (int)s.size());
			}else{
				break;
			}
		}
	}
	return ans;
}
// maybe better
int ChocolateBar::maxLength(string letters) {
	int ans = 0;
	for(int i=0; i<letters.size(); i++){
		for(int j=i; j<letters.size(); j++){
			set<int> s;
			for(int k=i; k<=j; k++){
				s.insert(letters[k]);
			}
			if(s.size()==j-i+1){
				ans = max(ans, j-i+1);
			}
		}
	}
	return ans;
}
// better
int ChocolateBar::maxLength(string letters) {
	int ans = 0;
	for(int i=0; i<letters.size(); i++){
		set<int> s;
		for(int j=i; j<letters.size(); j++){
			if(!s.insert(letters[j]).second){
				break;
			}
			ans = max(ans, (int)s.size());
		}
	}
	return ans;
}
// optimized by myself
int ChocolateBar::maxLength(string letters) {
	int ans = 0;
	map<int, int> m;
	for(int i=0; i<26; i++){
		m[97+i] = -1;
	}
	int t = 0;
	for(int i=0; i<letters.size(); i++){
		if(m[letters[i]]==-1){
			t++;
			m[letters[i]] = i;
		}else{
			t = 0;
			i = m[letters[i]];
			for(int i=0; i<26; i++){
				m[97+i] = -1;
			}
		}
		ans = max(ans, t);
	}
	return ans;
}
// better
int ChocolateBar::maxLength(string letters) {
	int f['z'+1];
	memset(f, 0, sizeof(f));
	int ans = 1;
	for(int i=0; i<letters.size(); i++){
		int t = 0;
		for(int j=i; j<letters.size(); j++){
			if(f[letters[j]]==1){
				break;
			}
			f[letters[j]] = 1;
			t++;
		}
		ans = max(ans, t);
		memset(f, 0, sizeof(f));		
	}
	return ans;
}
// maybe better
int ChocolateBar::maxLength(string letters) {
	vector<int> v('z'+1);
	int ans = 1;
	for(int i=0; i<letters.size(); i++){
		int t = 0;
		for(int j=i; j<letters.size(); j++){
			if(v[letters[j]]==1){
				break;
			}
			v[letters[j]] = 1;
			t++;
		}
		ans = max(ans, t);
		fill(v.begin(), v.end(), 0);
	}
	return ans;
}

// 441 2.1
int DifferentStrings::minimize(string A, string B) {
	int ans = B.size();
	for(int i=0; i<B.size()-A.size()+1; i++){
		int t = 0;
		for(int j=0; j<A.size(); j++){
			if(B[i+j]!=A[j]){
				t++;
			}
		}
		ans = min(ans, t);
	}
	return ans;
}

// 373 2.1
int TheEquation::leastSum(int X, int Y, int P) {
	int ans = numeric_limits<int>::max();
	for(int i=1; i<=P; i++){
		for(int j=1; j<=P; j++){
			if((i*X+j*Y)%P==0){
				ans = min(ans, i+j);
			}
		}
	}
	return ans;
}

// 263 2.1
double Party::averageNames(int n, vector <int> personA, vector <int> personB) {
	vector< set<int> > v(n);
	for(int i=0; i<personA.size(); i++){
		v[personA[i]].insert(personB[i]);
		for(set<int>::iterator it=v[personB[i]].begin(); it!=v[personB[i]].end(); it++){
			if(*it!=personA[i]){
				v[personA[i]].insert(*it);
			}
		}
		v[personB[i]].insert(personA[i]);
		for(set<int>::iterator it=v[personA[i]].begin(); it!=v[personA[i]].end(); it++){
			if(*it!=personB[i]){
				v[personB[i]].insert(*it);
			}
		}
	}
	double ans = 0;
	for(int i=0; i<n; i++){
		ans += v[i].size();
	}
	return ans/n;
}

// 201 2.1
int Multiples::number(int min, int max, int factor) {
	int ans = 0;
	for(int i=min; i<=max; i++){
		if(i%factor==0){
			ans++;
		}
	}
	return ans;
}

// 287 2.2
// this is wrong answer, 1 test case not passed
int gcd(int a, int b){
	if(a==0) return b;
	if(b==0) return a;
	return gcd(b%a, a);
}
int gcd(int a, int b){
	if(b>a){
		gcd(b, a);
	}
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}
string TwoEquations::solve(string first, string second) {
	vector<string> v;
	for(int i=0, j=0; i<3; i++){
		string t;
		while(first[j]!='*' && j<first.size()){
			if(first[j]!='(' && first[j]!=')'){
				t += first[j];
			}
			j++;
		}
		v.push_back(t);
		j += 5;
	}
	for(int i=0, j=0; i<3; i++){	
		string t;
		while(second[j]!='*' && j<second.size()){
			if(second[j]!='(' && second[j]!=')'){
				t += second[j];
			}
			j++;
		}
		v.push_back(t);
		j += 5;
	}
	
	vector<int> vi(6);
	for(int i=0; i<v.size(); i++){
		istringstream(v[i]) >> vi[i];
	}
	
	int x1 = vi[1]*vi[5]-vi[4]*vi[2];
	int x2 = vi[3]*vi[1]-vi[0]*vi[4];
	int y1 = vi[0]*vi[5]-vi[2]*vi[3];
	int y2 = vi[0]*vi[4]-vi[3]*vi[1];
	
	if(x1==0 && x2==0){
		return "MULTIPLE SOLUTIONS";
	}else if(x1!=0 && x2==0){
		return "NO SOLUTIONS";
	}
	
	int xx = gcd(abs(x1), abs(x2));
	int yy = gcd(abs(y1), abs(y2));
	
	x1 = x1/xx;
	x2 = x2/xx;
	y1 = y1/yy;
	y2 = y2/yy;
	
	if(x1<0 && x2<0){
		x1 = abs(x1);
		x2 = abs(x2);
	}
	if(y1<0 && y2<0){
		y1 = abs(y1);
		y2 = abs(y2);
	}
	
	ostringstream o;
	o << "X=";
	if(x1<0){
		o << '(' << x1 << ")/";
	}else{
		o << x1 << '/';
	}
	if(x2<0){
		o << '(' << x2 << ") ";
	}else{
		o << x2 << ' ';
	}
	o << "Y=";
	if(y1<0){
		o << '(' << y1 << ")/";
	}else{
		o << y1 << '/';
	}
	if(y2<0){
		o << '(' << y2 << ")";
	}else{
		o << y2;
	}
	return o.str();
}
string TwoEquations::solve(string first, string second) {
	int a, b, c, d, e, f;
	vector<string> v(6);
	istringstream isf(first);
	istringstream iss(second);
	string t;
	isf >> v[0] >> t >> v[1] >> t >> v[2];
	iss >> v[3] >> t >> v[4] >> t >> v[5];
	for(int i=0; i<v.size(); i++){
		v[i] = v[i][0]=='('? v[i].substr(1, 2): v[i].substr(0, 1);
	}
	
	istringstream(v[0]) >> a;
	istringstream(v[1]) >> b;
	istringstream(v[2]) >> c;
	istringstream(v[3]) >> d;
	istringstream(v[4]) >> e;
	istringstream(v[5]) >> f;
	
	if(a==0 && b==0 && c!=0){
		return "NO SOLUTIONS";
	}
	if(d==0 && e==0 && f!=0){
		return "NO SOLUTIONS";
	}
	
	int x1 = b*f-e*c;
	int x2 = d*b-a*e;
	int y1 = a*f-c*d;
	int y2 = a*e-d*b;
	
	if(x1==0 && x2==0){
		return "MULTIPLE SOLUTIONS";
	}
	if(x1!=0 && x2==0){
		return "NO SOLUTIONS";
	}
	
	int xx = gcd(abs(x1), abs(x2));
	int yy = gcd(abs(y1), abs(y2));
	
	x1 /= xx;
	x2 /= xx;
	y1 /= yy;
	y2 /= yy;
	
	if(x1<0 && x2<0){
		x1 = abs(x1);
		x2 = abs(x2);
	}
	if(y1<0 && y2<0){
		y1 = abs(y1);
		y2 = abs(y2);
	}
	if(x1>0 && x2<0){
		x1 = -x1;
		x2 = -x2;
	}
	if(y1>0 && y2<0){
		y1 = -y1;
		y2 = -y2;
	}
	
	ostringstream o;
	o << "X=";
	if(x1<0){
		o << '(' << x1 << ")/";
	}else{
		o << x1 << '/';
	}
	if(x2<0){
		o << '(' << x2 << ") ";
	}else{
		o << x2 << ' ';
	}
	o << "Y=";
	if(y1<0){
		o << '(' << y1 << ")/";
	}else{
		o << y1 << '/';
	}
	if(y2<0){
		o << '(' << y2 << ")";
	}else{
		o << y2;
	}
	return o.str();
}

// 358 2.2
// this answer fail in some test case
int BrokenButtons::minPresses(int page, vector <int> broken) {
	if(page==100){
		return 0;
	}
	
	int a = page;
	int b = page;
	while(isb(a, broken) && a>-1){
		a--;
	}
	while(isb(b, broken) && b<500001){
		b++;
	}
	
	if(a==-1 && b==500000){
		return abs(page - 100);
	}
	
	int c = page - a;
	int d = b - page;
	
	int sa;
	
	if(c < d){
		ostringstream o;
		o<<a;
		sa = c + o.str().size();
	}else{
		ostringstream o;
		o<<b;
		sa = d + o.str().size();
	}
	
	return sa>=abs(page-100)? abs(page-100): sa;
}
// correct, tle in local but pass in topcoder server
int BrokenButtons::minPresses(int page, vector <int> broken) {
	vector<int> v(10, 0);
	for(int i=0; i<broken.size(); i++){
		v[broken[i]] = 1;
	}
	int ans = abs(page-100);
	for(int i=0; i<=999999; i++){
		ostringstream o;
		o << i;
		string t = o.str();
		bool b = true;
		for(int j=0; j<t.size(); j++){
			if(v[t[j]-'0']==1){
				b = false;
				break;
			}
		}
		if(b){
			ans = min(ans, (int)(abs(page-i)+t.size()));
		}
	}
	return ans;
}
// used while to check digit, but while method cannot check 0
int BrokenButtons::minPresses(int page, vector <int> broken) {
	vector<int> v(10,0);
	for(int i=0; i<broken.size(); i++){
		v[broken[i]] = 1;
	}
	int ans = abs(page-100);
	for(int i=0; i<1000000; i++){
		int t = i;
		bool pass = true;
		int d = 0;
		if(i==0){
			d = 1;
			pass = v[0]? false: true;
		}else{
			while(t){
				d++;
				if(v[t%10]){
					pass = false;
					break;
				}
				t/=10;
			}
		}
		if(pass){
			ans = min(ans, d+abs(page-i));
		}
	}
	return ans;
}
int BrokenButtons::minPresses(int page, vector <int> broken) {
	vector<int> v(10);
	for(int i=0; i<broken.size(); i++){
		v[broken[i]] = 1;
	}
	int ans = numeric_limits<int>::max();
	for(int i=0; i<1000000; i++){
		bool b = true;
		int t = i;
		int d = 0;
		while(t){
			if(v[t%10]){
				b = false;
				break;
			}
			d++;
			t /= 10;
		}
		if(i==0){
			if(v[i]){
				b = false;
			}else{
				d = 1;
			}
		}
		if(b){
			ans = min(ans, d+abs(page-i));
		}
	}
	ans = min(ans, abs(page-100));
	return ans;
}

//250 2.2
// failed in 1 test case
int LanguageRecognition::whichLanguage(vector <string> languages, string text) {
	vector< vector<int> > l(languages.size(), vector<int>(26, 0));
	for(int i=0; i<languages.size(); i++){
		for(int j=0; j<languages[i].size(); j++){
			if(isalpha(languages[i][j])){
				l[i][tolower(languages[i][j])-'a']++;
			}
		}
	}
	
	vector<int> t(26, 0);
	for(int i=0; i<text.size(); i++){
		if(isalpha(text[i])){
			t[tolower(text[i])-'a']++;
		}
	}
	
	vector< pair<double, int> > v;
	for(int i=0; i<l.size(); i++){
		double a = 0;
		for(int j=0; j<l[i].size(); j++){
			double d = ((double)l[i][j]/languages[i].size() - (double)t[j]/text.size());
			a += d*d;
		}
		v.push_back(make_pair(a, i));
	}
	
	sort(v.begin(), v.end());
	
	return v[0].second;
}
// better, still fail because of floating points
int LanguageRecognition::whichLanguage(vector <string> languages, string text) {
	double eps = 1e-9;
	vector< vector<int> > v(languages.size(), vector<int>('z'+1));
	vector<int> c(languages.size());
	for(int i=0; i<languages.size(); i++){
		for(int j=0; j<languages[i].size(); j++){
			if(isalpha(languages[i][j])){
				v[i][tolower(languages[i][j])]++;
				c[i]++;
			}
		}
	}
	vector<int> a('z'+1);
	int b = 0;
	for(int i=0; i<text.size(); i++){
		if(isalpha(text[i])){
			a[tolower(text[i])]++;
			b++;
		}
	}
	int ans = -1;
	double t = numeric_limits<double>::max();
	for(int i=0; i<v.size(); i++){
		double u = 0;
		for(int j='a'; j<='z'; j++){
			u += (v[i][j]*1.0/c[i]-a[j]*1.0/b)*(v[i][j]*1.0/c[i]-a[j]*1.0/b);
		}
		if(u < t || (u-t<=eps && i<ans)){
			t = u;
			ans = i;
		}
	}
	return ans;
}
// solved, avoided floating point
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}
int LanguageRecognition::whichLanguage(vector <string> languages, string text) {
	vector<int> v('z'+1);
	int vv = 0;
	for(int i=0; i<text.size(); i++){
		if(isalpha(text[i])){
			v[tolower(text[i])]++;
			vv++;
		}
	}
	int ans = -1;
	long long a = 50*50*30;
	int aa = 1;
	for(int i=0; i<languages.size(); i++){
		vector<int> u('z'+1);
		int uu = 0;
		for(int j=0; j<languages[i].size(); j++){
			if(isalpha(languages[i][j])){
				u[tolower(languages[i][j])]++;
				uu++;
			}
		}
		long long t = 0;
		for(int j='a'; j<='z'; j++){
			long long x = vv*u[j]-uu*v[j];
			t += x*x;
		}
		int tt = vv*vv*uu*uu;
		int g = gcd(t, tt);
		t /= g, tt /= g;
		if(t*aa < a*tt){
			a = t;
			aa = tt;
			ans = i;
		}
	}
	return ans;
}

// 467 2.2
// wrong in question?
double LateProfessor::getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) {
	vector<int> v(10000002);
	int i = 0;
	while(1){
		int a = waitTime*(i+1) + walkTime*i + 1;
		int b = waitTime*(i+1) + walkTime*(i+1) - lateTime;
		if(b<a){
			return 0;
		}
		v[a]++;
		if(b>worstArrival) break;
		v[b+1]--;
		i++; 
	}
	v[bestArrival]++;
	v[worstArrival+1]--;
	int t = 0;
	int a = 0;
	int b = 0;
	for(int i=0; i<=10000001; i++){
		t += v[i];
		if(i >= bestArrival && i<=worstArrival){
			a++;
			if(t == 2){
				b++;
			}
		}
	}
	return b*1.0/a;
}
// still wrong
double LateProfessor::getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) {
	int i = 0;
	int ans = 0;
	while(1){
		int a = waitTime*(i+1) + walkTime*i;
		int b = waitTime*(i+1) + walkTime*(i+1) - lateTime;
		if(a>worstArrival) break;
		if(a<=worstArrival && b>=bestArrival){
			ans += min(b, worstArrival) - max(a, bestArrival);
		}
		i++; 
	}
	return worstArrival-bestArrival==0? 0: ans*1.0/(worstArrival-bestArrival);
}


// 441 2.2
long long PaperAndPaintEasy::computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2) {
	long long t = 0;
	int m = min(xfold, abs(width-xfold));
	if(m >= x2){
		t += (long long)(x2-x1)*(y2-y1)*2*(cnt+1);
	}else if(m < x2 && m > x1){
		t += (long long)(x2-m)*(y2-y1)*(cnt+1) + (long long)(m-x1)*(y2-y1)*2*(cnt+1);
	}else{
		t += (long long)(x2-x1)*(y2-y1)*(cnt+1);
	}
	return (long long)width*height - t;
}

// 493 2.1
int AmoebaDivTwo::count(vector <string> table, int K) {
	int ans = 0;
	for(int i=0; i<table.size(); i++){
		for(int j=0; j<table[i].size(); j++){
			if(K==1){
				if(table[i][j]=='A'){
					ans++;
				}
			}else{
				if(j+K-1<table[i].size()){
					bool b = true;
					for(int k=j; k<j+K; k++){
						if(table[i][k]!='A'){
							b = false;
							break;
						}
					}
					if(b){
						ans++;
					}
				}
				if(i+K-1<table.size()){
					bool b = true;
					for(int k=i; k<i+K; k++){
						if(table[k][j]!='A'){
							b = false;
							break;
						}
					}
					if(b){
						ans++;
					}
				}
			}
		}
	}
	return ans;
}

// 555 2.1
int XorBoardDivTwo::theMax(vector <string> board){
	int d = 0;
	int t = 0;
	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[i].size(); j++){
			t += board[i][j]-'0';
			int a = 0;
			int b = 0;
			for(int k=0; k<board.size(); k++){
				a += board[k][j]-'0';
				if(k==i){
					b += board[k][j]-'0';
				}else{
					b += 1+'0'-board[k][j];
				}
			}
			for(int m=0; m<board[i].size(); m++){
				a += board[i][m]-'0';
				if(m==j){
					b += board[i][m]-'0';
				}else{
					b += 1+'0'-board[i][m];
				}
			}
			d = max(d, b-a);
		}
	}
	return t+d;
}
// more brute force but less time to think
int XorBoardDivTwo::theMax(vector <string> board){
	int ans = 0;
	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[i].size(); j++){
			
			for(int k=0; k<board.size(); k++){
				board[k][j] = board[k][j]=='1'? '0': '1';
			}
			for(int m=0; m<board[i].size(); m++){
				board[i][m] = board[i][m]=='1'? '0': '1';
			}
			
			int t = 0;
			for(int k=0; k<board.size(); k++){
				for(int m=0; m<board[k].size(); m++){
					t += board[k][m]-'0';
				}
			}
			ans = max(ans, t);

			for(int k=0; k<board.size(); k++){
				board[k][j] = board[k][j]=='1'? '0': '1';
			}
			for(int m=0; m<board[i].size(); m++){
				board[i][m] = board[i][m]=='1'? '0': '1';
			}
		}
	}
	return ans;
}

// 179 2.2
// incorrect method
int Packhorses::horses(int p, int x, int y){
    int h = 0;
	while(p>0){
		p--;
		h++;
		// this part failed, has to cleverly choose fill x or y
		if(y>0){
			y--;
			continue;
		}
		if(x>0){
			x--;
		}
		if(x>0){
			x--;
		}
		// this part failed
	}
	while(x>0){
		h++;
		x--;
		if(x>0){
			x--;
		}
		if(x>0){
			x--;
		}
	}
	while(y>0){
		h++;
		y--;
		if(y>0){
			y--;
		}
	}
    return h;
}
// better, brute force
int Packhorses::horses(int p, int x, int y){
    int ans = numeric_limits<int>::max();
    for(int i=0; i<=p; i++){
    	int a = max(x - i*2, 0);
    	int b = max(y - (p-i), 0);
    	ans = min(ans, p + (a+2)/3 + (b+1)/2);
    }
    return ans;
}

// 410 2.2
// wrong
// miss something from the question
void dfs(vector<string>& w, vector< vector<int> >& v, vector<int>& vv, vector<int>& r, int n, int k){
	r[k] = 1;
	v[n][k] = 1;
	for(int i=0; i<w[k].size(); i++){
		if(w[k][i]=='1' && v[n][i]==0){
			vv[n]++;
			dfs(w, v, vv, r, n, i);
		}
	}
}
int AddElectricalWires::maxNewWires(vector <string> wires, vector <int> gridConnections) {
	vector< vector<int> > v(gridConnections.size(), vector<int>(wires.size()));
	vector<int> vv(gridConnections.size());
	vector<int> r(wires.size());
	for(int i=0; i<gridConnections.size(); i++){
		dfs(wires, v, vv, r, i, gridConnections[i]);
	}
	int a = wires.size() - accumulate(r.begin(), r.end(), 0);
	int ans = 0;
	for(int i=0; i<gridConnections.size(); i++){
		int b = accumulate(v[i].begin(), v[i].end(), 0);
		int c = a+b;
		ans = max(ans, c*(c-1)/2-vv[i]);
	}
	return ans;
}
// better, but still wrong
// miss something from the question
void dfs(vector<string>& w, vector<int>& v, int& c, int n){
	v[n] = 1;
	for(int i=0; i<w[n].size(); i++){
		if(w[n][i]=='1' && v[i]==0){
			c++;
			dfs(w, v, c, i);
		}
	}
}
int AddElectricalWires::maxNewWires(vector <string> wires, vector <int> gridConnections) {
	vector<int> g(wires.size());
	for(int i=0; i<gridConnections.size(); i++){
		g[gridConnections[i]] = 1;
	}
	int e = 0;
	for(int i=0; i<wires.size(); i++){
		int t;
		stringstream(wires[i]) >> t;
		if(t==0 && g[i]==0){
			e++;
		}
	}
	int ans = 0;
	for(int i=0; i<gridConnections.size(); i++){
		vector<int> v(wires.size());
		int c = 0;
		dfs(wires, v, c, gridConnections[i]);
		int a = accumulate(v.begin(), v.end(), 0);
		ans = max(ans, (a+e)*(a+e-1)/2-c);
	}
	return ans;
}
// correct
void dfs(vector<string>& w, vector<int>& v, int n){
	v[n] = 1;
	for(int i=0; i<w[n].size(); i++){
		if(v[i]==0 && w[n][i]=='1'){
			dfs(w, v, i);
		}
	}
}
int AddElectricalWires::maxNewWires(vector <string> wires, vector <int> gridConnections) {
	int a = 0;
	for(int i=0; i<wires.size(); i++){
		for(int j=0; j<wires[i].size(); j++){
			if(wires[i][j]=='1'){
				a++;
			}
		}
	}
	a /= 2;
	int b = wires.size();
	int m = 0;
	int ans = 0;
	for(int i=0; i<gridConnections.size(); i++){
		vector<int> v(wires.size());
		dfs(wires, v, gridConnections[i]);
		int c = accumulate(v.begin(), v.end(), 0);
		ans += c*(c-1)/2;
		b -= c;
		m = max(m, c);
	}
	ans += b*(b-1)/2 + m*b;
	return ans - a;
}

// 454 2.1
int MinimalDifference::findNumber(int A, int B, int C) {
	ostringstream o;
	o << C;
	string c = o.str();
	int d = 0;
	for(int i=0; i<c.size(); i++){
		d += c[i]-'0';
	}
	
	int ans = numeric_limits<int>::max();
	int aa = -1;
	
	for(int i=A; i<=B; i++){
		ostringstream oo;
		oo << i;
		string t = oo.str();
		int e = 0;
		for(int j=0; j<t.size(); j++){
			e += t[j]-'0';
		}
		if(abs(e-d) < ans || (abs(e-d)==ans && i < aa)){
			ans = abs(e-d);
			aa = i;
		}
	}
	
	return aa;
}
// alternative
int MinimalDifference::findNumber(int A, int B, int C) {
	int d = 0;
	while(C){
		d += C%10;
		C/=10;
	}
	
	int ans = numeric_limits<int>::max();
	int aa = -1;
	
	for(int i=A; i<=B; i++){
		int t = i;
		int e = 0;
		while(t){
			e += t%10;
			t /= 10;
		}	
		if(abs(e-d) < ans || (abs(e-d)==ans && i < aa)){
			ans = abs(e-d);
			aa = i;
		}
	}
	return aa;
}

// 391 2.1
int SnowyWinter::snowyHighwayLength(vector <int> startPoints, vector <int> endPoints) {
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
	return ans;
}
// faster
int SnowyWinter::snowyHighwayLength(vector <int> startPoints, vector <int> endPoints) {
	int n = startPoints.size();
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
	return ans;
}
// even faster but more space
int SnowyWinter::snowyHighwayLength(vector <int> startPoints, vector <int> endPoints) {
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
	return ans;
}

// 338 2.2
// brute force method will exceed time limit
// this use binary search to find the right most insertion point between 0 and 2000000000
int ImprovingStatistics::howManyGames(int played, int won) {
	int a = (long long)won*100/played;
	if(a >= 99){
		return -1;
	}
	int l = 0;
	int r = 2000000000;
	while(l<=r){
		int m = l + (r-l)/2;
		int b = (long long)(won+m)*100/(played+m);
		if(b == a){
			l = m+1;
		}else{
			r = m-1;
		}
	}
	return l;
}
// correct in local, wrong in topcoder server
int ImprovingStatistics::howManyGames(int played, int won) {
	int a = won*1.0/played*100;
	if(a>=99){
		return -1;
	}
	int l = 0;
	int r = 2000000000;
	while(l<=r){
		int m = l+(r-l)/2;
		int b = (won+m)*1.0/(played+m)*100;
		cout << a <<' '<<b<<' '<<l<<' '<<r<<endl; 
		if(b==a){
			l = m+1;
		}else{
			r = m-1;
		}
	}
	return l;
}
// use larger interval in loop to make it faster, after exceed then go back to find
int ImprovingStatistics::howManyGames(int played, int won) {
	int a = won*100LL/played;
	if(a>=99) return -1;
	int i = 1000;
	while(1){
		int b = (won+i)*100LL/(played+i);
		if(b > a){
			break;
		}
		i += 1000;
	}
	for(int j=i-1000; j<=i; j++){
		int b = (won+j)*100LL/(played+j);
		if(b>a){
			return j;
		}
	}
	return 0;
}


// 464 2.2
// brute force method, correct logic but time limmit exceed
string ColorfulStrings::getKth(int n, int k) {
	long long a = pow((double)10,(double)n);
	long long b = a/10;
	vector<string> v; 
	for(long long i=b; i<a; i++){
		ostringstream o;
		o<< i;
		string t = o.str();
		set<int> s;
		int ss = 0;
		for(int j=0; j<t.size(); j++){
			for(int k=j; k<t.size(); k++){
				int u = 1;
				for(int m=j; m<=k; m++){
					u *= t[m]-'0';
				}
				ss++;
				s.insert(u);
			}
		}
		if(s.size()==ss){
			v.push_back(t);
		}
	}
	if(v.size() < k){
		return "";
	}
	sort(v.begin(), v.end());
	return v[k-1];
}
// correct, use backtrack to find all permutation
void backtrack(vector<int>& r, vector<int>& u, vector<string>& v, int d, int n, int st){
	if(d==n){
		set<int> s;
		int a = 0;
		for(int i=0; i<r.size(); i++){
			int t = 1;
			for(int j=i; j<r.size(); j++){
				t *= r[j];
				s.insert(t);
				a++;
			}
		}
		if(s.size() != a){
			return;
		}
		string t = "";
		for(int i=0; i<r.size(); i++){
			t += '0'+r[i];
		}
		v.push_back(t);
		return;
	}
	for(int i=st; i<=9; i++){
		if(u[i]==0){
			u[i] = 1;
			r[d] = i;
			backtrack(r, u, v, d+1, n, st);
			u[i] = 0;
		}
	}
}
string ColorfulStrings::getKth(int n, int k) {
	if(n>=9){
		return 	"";
	}
	int st = n<2? 0: 2;
	vector<int> r(n);
	vector<int> u(10,0);
	vector<string> v;
	backtrack(r, u, v, 0, n, st);
	if(k > v.size()){
		return "";
	}
	return v[k-1];
}
// seems better
string ColorfulStrings::getKth(int n, int k) {
	if(n>=9){
		return "";
	}
	string s;
	for(int i=(n<2)?0:2; i<10; i++){
		s += '0'+i;
	}
	int a = 0;
	do{
		set<int> si;
		for(int i=0; i<n; i++){
			int t = 1;
			for(int j=i; j<n; j++){
				t *= s[j]-'0';
				if(!si.insert(t).second){
					goto ng;
				}
			}
		}
		if(k-1 == a){
			return s.substr(0, n);
		}
		a++;
	ng:
		reverse(s.begin()+n, s.end());
	}while(next_permutation(s.begin(), s.end()));
	return "";
}

//390 2.1
int FingerCounting::maxNumber(int weakFinger, int maxCount) {
	int a = 0;
	int c = 0;
	while(1){
		for(int i=1; i<=4; i++){
			if(i==weakFinger){
				c++;
				if(c>maxCount){
					return a;
				}
			}
			a++;
		}
		for(int i=5; i>=2; i--){
			if(i==weakFinger){
				c++;
				if(c>maxCount){
					return a;
				}
			}
			a++;
		}
	}
}
// better
int FingerCounting::maxNumber(int weakFinger, int maxCount) {
	int c = 0;
	int i = 0;
	int ff[] = {1,2,3,4,5,4,3,2};
	while(1){
		int f = ff[i%8];
		if(f==weakFinger){
			c++;
			if(c>maxCount){
				return i;
			}
		}
		i++;
	}
}

// 562 2.1
string CucumberMarket::check(vector <int> price, int budget, int k) {
	for(int i=0; i<1<<price.size(); i++){
		int a = 0;
		int b = 0;
		for(int j=0; j<price.size(); j++){
			if(i&(1<<j)){
				a += price[j];
				b++;
			}
		}
		if(b==k && a>budget){
			return "NO";
		}
	}
	return "YES";
}
// better
string CucumberMarket::check(vector <int> price, int budget, int k) {
	sort(price.rbegin(), price.rend());
	int t = 0;
	for(int i=0; i<k; i++){
		t += price[i];
	}
	return t>budget? "NO": "YES";
}

// 188 2.2
int Percents::minSamples(string percent) {
	double eps = 1e-9;
	double a = 0;
	a += (percent[0]-'0')*10;
	a += percent[1]-'0';
	a += 0.1*(percent[3]-'0');
	a += 0.01*(percent[4]-'0');
	a /= 100;
	for(int i=1; i<=10000; i++){
		double b = floor(i*a);
		double c = ceil(i*a);
		double d = b/i;
		double e = c/i;
		d = round(d*10000)/10000;
		e = round(e*10000)/10000;
		if(abs(a-d)<=eps || abs(a-e)<=eps){
			return i;
		}
	}
	return -1;
}
// better
int Percents::minSamples(string percent) {
	int p = (percent[0]-'0')*1000 + (percent[1]-'0')*100 + (percent[3]-'0')*10 + (percent[4]-'0');	
	for(int i=1; i<=10000; i++){
		int a = (i*p+9999)/10000;
		int b = i*p/10000;
		int c = round(a*10000.0/i);
		int d = round(b*10000.0/i);
		if(c==p || d==p){
			return i;
		}
	}
	return -1;
}

// 581 2.1
int BlackAndWhiteSolitaire::minimumTurns(string cardFront) {
	char f[2] = {'B', 'W'};
	int a = 0;
	int b = 0;
	for(int i=0; i<cardFront.size(); i++){
		if(f[i%2]!=cardFront[i]){
			a++;
		}
		if(f[(i+1)%2]!=cardFront[i]){
			b++;
		}
	}
	return min(a, b);
}

// Pilot Round 2 Member Pilot 2 div2.1
vector<string> Xosceles::draw(int xCount){
	int a=1, ar=1, ac=1;
	int b=2, br=1, bc=2;
	while(a<xCount){
		ac = ac+2;
		a += ac;
		ar++;
	}
	while(b<xCount){
		bc = bc+2;
		b += bc;
		br++;
	}
	if(xCount!=a && xCount!=b){
		return "";
	}
	int r, c;
	if(xCount==a){
		r = ar;
		c = ac;
	}else{
		r = br;
		c = bc;
	}
	vector<string> v(r);
	for(int i=v.size()-1, ll=0, rr=c-1; i>=0; i--, ll++, rr--){
		string t = "";
		for(int j=0; j<c; j++){
			if(j<ll || j>rr){
				t += '.';
			}else{
				t += 'X';
			}
		}
		v[i] = t;
	}
	return v;
}
vector <string> Xosceles::draw(int xCount) {
	int r = (int)sqrt(xCount);
	int a = r*r;
	int b = r*r+r;
	if(xCount!=a && xCount!=b){
		return vector<string>();
	}
	int c;
	if(xCount==a){
		c = r*2-1;
	}else{
		c = r*2;
	}
	vector<string> v(r);
	for(int i=r-1, k=0; i>=0; i--, k++){
		string t = "";
		for(int j=0; j<c; j++){
			if(j<k || j>c-k-1){
				t += '.';
			}else{
				t += 'X';
			}
		}
		v[i] = t;
	}
	return v;
}

// 582 2.1
string SemiPerfectSquare::check(int N) {
	int n = sqrt(N);
	for(int b=2; b<=n; b++){
		for(int a=1; a<b; a++){
			if(a*b*b==N){
				return "Yes";
			}
		}
	}
	return "No";
}
// editorial
string SemiPerfectSquare::check(int N){
	for(int b=1; b*b<=N; b++){
		if(N%(b*b)==0){
			int a = N/(b*b);
			if(a<b){
				return "YES";
			}
		}
	}
	return "NO";
}

// 296 2.1
int EratosthenSieve2::nthElement(int n){
	vector<int> v(1000);
	for(int i=0; i<v.size(); i++){
		v[i] = i+1;
	}
	for(int i=2; i<11; i++){
		for(int j=v.size()-1; j>=0; j--){
			if((j+1)%i==0){
				v.erase(v.begin()+j);
			}
		}
	}
	return v[n-1];
}
// more efficient
int EratosthenSieve2::nthElement(int n){
	vector<int> v(1001, 1);
	v[0] = 0;
	for(int i=2; i<11; i++){
		int p = 0;
		for(int j=0; j<v.size(); j++){
			if(v[j]==0){
				continue;
			}
			if((p+1)%i==0){
				v[j] = 0;
			}
			p++;
		}
	}
	int c = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i]==1){
			c++;
			if(c==n){
				return i;
			}
		}
	}
}
// using list, but this solution maybe not the best
int EratosthenSieve2::nthElement(int n) {
	list<int> l;
	for(int i=1; i<=1000; i++){
		l.push_back(i);
	}
	for(int i=2; i<11; i++){
		for(int j=l.size()-1; j>=0; j--){
			if((j+1)%i==0){
				list<int>::iterator it(l.begin());
				advance(it, j);
				l.erase(it);
			}
		}
	}
	list<int>::iterator it = l.begin();
	advance(it, n-1);
	return *it;
}

// 554 2.1
int TheBrickTowerEasyDivTwo::find(int redCount, int redHeight, int blueCount, int blueHeight) {
	set<int> s;
	int c[] = {redCount, blueCount};
	int h[] = {redHeight, blueHeight};
	int a[] = {0,0};
	int b[] = {0,0};
	int m = 0;
	int n = 0;
	for(int i=0; a[i%2]<c[i%2]; i++){
		m += h[i%2];
		a[i%2]++;
		s.insert(m);
	}
	for(int i=1; b[i%2]<c[i%2]; i++){
		n += h[i%2];
		b[i%2]++;
		s.insert(n);
	}
	return (int)s.size();
}
// more brute force, but faster to code
int TheBrickTowerEasyDivTwo::find(int redCount, int redHeight, int blueCount, int blueHeight) {
	set<int> s;
	for(int i=0; i<=redCount; i++){
		for(int j=0; j<=blueCount; j++){
			if((i>0||j>0) && abs(i-j)<=1){
				s.insert(i*redHeight+j*blueHeight);
			}
		}
	}
	return (int)s.size();
}
// even better
int TheBrickTowerEasyDivTwo::find(int redCount, int redHeight, int blueCount, int blueHeight) {
	set<int> s;
	for(int i=0; i<=redCount; i++){
		for(int j=0; j<=blueCount; j++){
			if(i|j && abs(i-j)<=1){
				s.insert(i*redHeight+j*blueHeight);
			}
		}
	}
	return s.size();
}

// 272 2.1
int HammingDistance::minDistance(vector <string> numbers) {
	int ans = numeric_limits<int>::max();
	for(int i=0; i<numbers.size(); i++){
		for(int j=i+1; j<numbers.size(); j++){
			int t = 0;
			for(int k=0; k<numbers[i].size(); k++){
				if(numbers[i][k]!=numbers[j][k]){
					t++;
				}
			}
			ans = min(ans, t);
		}
	}
	return ans;
}

// 593 2.1
int RaiseThisBarn::calc(string str) {
	int ans = 0;
	for(int i=1; i<=str.size()-1; i++){
		int a = 0;
		int b = 0;
		for(int j=0; j<str.size(); j++){
			if(j<i){
				if(str[j]=='c'){
					a++;
				}
			}else{
				if(str[j]=='c'){
					b++;
				}
			}
		}
		if(a==b){
			ans++;
		}
	}
	return ans;
}
// better
int RaiseThisBarn::calc(string str) {
	int ans = 0;
	for(int i=1; i<str.size(); i++){
		string a = str.substr(0, i);
		string b = str.substr(i, str.size()-i);
		int c = count(a.begin(), a.end(), 'c');
		int d = count(b.begin(), b.end(), 'c');
		if(c==d){
			ans++;
		}
	}
	return ans;
}
// even better
int RaiseThisBarn::calc(string str) {
	int ans = 0;
	for(int i=1; i<str.size(); i++){
		string a = str.substr(0, i);
		string b = str.substr(i);
		if(count(a.begin(), a.end(), 'c') == count(b.begin(), b.end(), 'c')){
			ans++;
		}
	}
	return ans;
}

// 319 2.1
int SkewSymmetric::minChanges(vector <string> M) {
	vector< vector<int> > v(M.size());
	for(int i=0; i<M.size(); i++){
		vector<int> vv(M.size());
		stringstream ss(M[i]);
		string t;
		int p = 0;
		while(ss >> t){
			istringstream(t) >> vv[p];
			p++;
		}
		v[i] = vv;
	}
	int ans = 0;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			if(i==j){
				if(v[i][j]!=0){
					ans++;
				}
			}else{
				if(v[i][j] != -v[j][i]){
					v[i][j] = -v[j][i];
					ans++;
				}
			}
		}
	}
	return ans;
}
// better
int SkewSymmetric::minChanges(vector <string> M) {
	vector< vector<int> > v(M.size(), vector<int>(M.size()));
	for(int i=0; i<M.size(); i++){
		stringstream ss(M[i]);
		for(int j=0; j<M.size(); j++){
			ss >> v[i][j];
		}
	}
	int ans = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i][i]!=0){
			ans++;
		}
	}
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v[i].size(); j++){
			if(v[i][j]!=-v[j][i]){
				ans++;
			}
		}
	}
	return ans;
}

// 278 2.1
string RectangleGroups::maximalIndexed(vector <string> rectangles) {
	map<char, int> m;
	for(int i=0; i<rectangles.size(); i++){
		char c;
		int l;
		int w;
		stringstream ss(rectangles[i]);
		ss >> c >> l >> w;
		m[c] += l*w;
	}
	int an = -1;
	char aa;
	for(map<char, int>::iterator it=m.begin(); it!=m.end(); it++){
		if(it->second > an){
			an = it->second;
			aa = it->first;
		}
	}
	ostringstream o;
	o << an;
	string ans = "";
	ans += aa;
	ans += ' ';
	ans += o.str();
	return ans;
}
// better
string RectangleGroups::maximalIndexed(vector <string> rectangles) {
	map<string, int> m;
	for(int i=0; i<rectangles.size(); i++){
		stringstream ss(rectangles[i]);
		string c;
		int l, w;
		ss >> c >> l >> w;
		m[c] += l*w;
	}
	int ai = -1;
	string ag;
	for(map<string, int>::iterator i=m.begin(); i!=m.end(); i++){
		if(i->second > ai){
			ai = i->second;
			ag = i->first;
		}
	}
	stringstream ss;
	ss << ag << ' ' << ai;
	return ss.str();
}

// 512 2.1
int MarbleDecoration::maxLength(int R, int G, int B) {
	vector<int> v(3);
	v[0] = R;
	v[1] = G;
	v[2] = B;
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for(int i=0; i<=v[0]; i++){
		for(int j=0; j<=v[1]; j++){
			if(abs(i-j)<=1){
				ans = max(ans, i+j);
			}
		}
	}
	return ans;
}
// better
int MarbleDecoration::maxLength(int R, int G, int B) {
	int a[] = {R, G, B};
	sort(a, a+3);
	int ans = 0;
	for(int i=0; i<=a[2]; i++){
		for(int j=0; j<=a[1]; j++){
			if(abs(i-j)<=1){
				ans = max(ans, i+j);
			}
		}
	}
	return ans;
}
// better
int MarbleDecoration::maxLength(int R, int G, int B) {
	int a[] = {R, G, B};
	sort(a, a+3);
	if(a[2]==a[1]){
		return a[2]+a[1];
	}
	return a[1]*2+1;
}

// 274 2.1
vector <int> SimpleDuplicateRemover::process(vector <int> sequence) {
	vector<int> v(1001, -1);
	for(int i=0; i<sequence.size(); i++){
		v[sequence[i]] = i;
	}
	sort(v.begin(), v.end());
	vector<int> a;
	for(int i=0; i<v.size(); i++){
		if(v[i]!=-1){
			a.push_back(sequence[v[i]]);
		}
	}
	return a;
}
// more generic but slower
vector <int> SimpleDuplicateRemover::process(vector <int> sequence) {
	vector< pair<int, int> > v(sequence.size());
	for(int i=0; i<sequence.size(); i++){
		v[i] = make_pair(sequence[i], i);
	}
	sort(v.rbegin(), v.rend());
	set<int> s;
	for(int i=0; i<v.size(); i++){
		if(i==0 || v[i].first!=v[i-1].first){
			s.insert(v[i].second);
		}
	}
	vector<int> ans;
	for(int i=0; i<sequence.size(); i++){
		if(s.find(i)!=s.end()){
			ans.push_back(sequence[i]);
		}
	}
	return ans;
}
// better, easier to implement but slower
vector <int> SimpleDuplicateRemover::process(vector <int> sequence) {
	vector<int> ans;
	for(int i=0; i<sequence.size(); i++){
		if(find(sequence.begin()+i+1, sequence.end(), sequence[i])==sequence.end()){
			ans.push_back(sequence[i]);
		}
	}
	return ans;
}

// 395 2.1
int SquareDigitNumbers::getNumber(int n) {
	if(n==0){
		return 0;
	}
	vector<int> v(10, 0);
	v[0] = v[1] = v[4] = v[9] = 1;
	int i=1;
	for(int j=1;; j++){
		int t = j;
		bool b = true;
		while(t){
			if(v[t%10]==0){
				b = false;
				break;
			}
			t /= 10;
		}
		if(b){
			if(i==n){
				return j;
			}
			i++;
		}
	}
}
// note that below will not give correct answer, something wrong with pow
int SquareDigitNumbers::getNumber(int n) {
	int ans = 0;
	int v[] = {0, 1, 4, 9};
	int i = 0;
	while(n){
		cout << v[n%4] << endl;
		ans += v[n%4]*pow(10, i*1.0);
		n /= 4;
		i++;
	}
	return ans;
}
// better, use the concept of "base 4 number"
int SquareDigitNumbers::getNumber(int n) {
	int f[] = {0, 1, 4, 9};
	int ans = 0;
	int i = 1;
	while(n){
		ans += f[n%4]*i;
		i *= 10;
		n /= 4;
	}
	return ans;
}

// 552 2.1
int FoxAndFlowerShopDivTwo::theMaxFlowers(vector <string> flowers, int r, int c) {
	int a=0, b=0, m=0, n=0;
	for(int i=0; i<flowers.size(); i++){
		for(int j=0; j<flowers[i].size(); j++){
			if(flowers[i][j]=='F'){
				if(i<r){
					a++;
				}
				if(i>r){
					b++;
				}
				if(j<c){
					m++;
				}
				if(j>c){
					n++;
				}
			}
		}
	}
	int t[] = {a, b, m, n};
	return *max_element(t, t+4);
}

// 474 2.1
bool isp(string t){
	for(int i=0, j=t.size()-1; i<j; i++, j--){
		if(t[i]!=t[j]){
			return false;
		}
	}
	return true;
}
int PalindromesCount::count(string A, string B) {
	int ans = 0;
	for(int i=0; i<=A.size(); i++){
		string a = A.substr(0, i);
		string b = A.substr(i, A.size()-i);
		if(isp(a+B+b)){
			ans++;
		}
	}
	return ans;
}
// slower but faster to code
int PalindromesCount::count(string A, string B) {
	int ans = 0;
	for(int i=0; i<=A.size(); i++){
		string a = A.substr(0, i);
		string b = A.substr(i, A.size()-i);
		string t = a+B+b;
		reverse(t.begin(), t.end());
		if(t==a+B+b){
			ans++;
		}
	}
	return ans;
}

// 357 2.1
string MnemonicMemory::getPhrase(string number, vector <string> dictionary) {
	sort(dictionary.begin(), dictionary.end());
	string ans = "";
	for(int i=0; i<number.size(); i++){
		int t = number[i]-'0';
		for(int j=0; j<dictionary.size(); j++){
			if(dictionary[j].size() == t){
				if(i!=0){
					ans += " ";
				}
				ans += dictionary[j];
				dictionary.erase(dictionary.begin()+j);
				break;
			}
		}
	}
	return ans;
}
// better
string MnemonicMemory::getPhrase(string number, vector <string> dictionary) {
	sort(dictionary.begin(), dictionary.end());
	vector<int> v(dictionary.size(), 0);
	string ans = "";
	for(int i=0; i<number.size(); i++){
		int t = number[i]-'0';
		for(int j=0; j<dictionary.size(); j++){
			if(dictionary[j].size() == t && v[j]==0){
				if(i!=0){
					ans += " ";
				}
				ans += dictionary[j];
				v[j] = 1;
				break;
			}
		}
	}
	return ans;
}

// 540 2.1
int RandomColoringDiv2::getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
	int ans = 0;
	for(int i=0; i<maxR; i++){
		for(int j=0; j<maxG; j++){
			for(int k=0; k<maxB; k++){
				int a = abs(startR-i);
				int b = abs(startG-j);
				int c = abs(startB-k);
				if((a<=d2 && b<=d2 && c<=d2) && (a>=d1||b>=d1||c>=d1)){
					ans++;
				}
			}
		}
	}
	return ans;
}

// 365 2.1
int TournamentsAmbiguityNumber::scrutinizeTable(vector <string> table) {
	int ans = 0;
	for(int i=0; i<table.size(); i++){
		for(int j=0; j<table.size(); j++){
			for(int k=0; k<table.size(); k++){
				if(table[i][j]=='1'&&table[j][k]=='1'&&table[k][i]=='1'){
					ans++;
				}
			}
		}
	}
	return ans;
}

// 640 2.1
int ChristmasTreeDecorationDiv2::solve(vector <int> col, vector <int> x, vector <int> y) {
	int ans = 0;
	for(int i=0; i<x.size(); i++){
		if(col[x[i]-1]!=col[y[i]-1]){
			ans++;
		}
	}
	return ans;
}

// 580 2.1
// classic problem to check overlap
int ShoutterDiv2::count(vector <int> s, vector <int> t) {
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		for(int j=i+1; j<s.size(); j++){
			if(!(t[i]<s[j] || t[j]<s[i])){
				ans++;
			}
		}
	}
	return ans;
}
// or
int ShoutterDiv2::count(vector <int> s, vector <int> t) {
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		for(int j=i+1; j<s.size(); j++){
			if(s[i]<=t[j] && s[j]<=t[i]){
				ans++;
			}
		}
	}
	return ans;
}

// 506 2.1
int SlimeXSlimeRancher2::train(vector <int> attributes) {
	int a = *max_element(attributes.begin(), attributes.end());
	int ans = 0;
	for(int i=0; i<attributes.size(); i++){
		ans += a-attributes[i];
	}
	return ans;
}

// 280 2.1
// the next answer is better
int UniqueDigits::count(int n) {
	int ans = 0;
	for(int i=1; i<n; i++){
		stringstream ss;
		ss << i;
		string t = ss.str();
		set<int> s;
		bool b = true;
		for(int j=0; j<t.size(); j++){
			if(!s.insert(t[j]-'0').second){
				b = false;
				break;
			}
		}
		if(b){
			ans++;
		}
	}
	return ans;
}
// better
int UniqueDigits::count(int n) {
	int ans = 0;
	for(int i=1; i<n; i++){
		bool b = true;
		int t = i;
		vector<int> v(10,0);
		while(t){
			if(v[t%10]!=0){
				b = false;
				break;
			}
			v[t%10]++;
			t /= 10;
		}
		if(b){
			ans++;
		}
	}
	return ans;
}

// 529 2.1
int PairingPawns::savedPawnCount(vector <int> start) {
	for(int i=start.size()-2; i>=0; i--){
		start[i] += start[i+1]/2;
	}
	return start[0];
}

// 217 2.1
double FuelConsumption::maximalDistance(vector <int> velocities, vector <int> consumptions, int fuel) {
	double ans = 0;
	for(int i=0; i<velocities.size(); i++){
		ans = max(ans, (double)velocities[i]/consumptions[i]*fuel);
	}
	return ans;
}
double FuelConsumption::maximalDistance(vector <int> velocities, vector <int> consumptions, int fuel) {
	double ans = 0;
	for(int i=0; i<velocities.size(); i++){
		ans = max(ans, velocities[i]*1.0/consumptions[i]*fuel);
	}
	return ans;
}

// 642 2.1
int ForgetfulAddition::minNumber(string expression) {
	int ans = numeric_limits<int>::max();
	for(int i=1; i<expression.size(); i++){
		string a = expression.substr(0, i);
		string b = expression.substr(i);
		int c;
		int d;
		stringstream(a) >> c;
		stringstream(b) >> d;
		ans = min(ans, c+d);
	}
	return ans;
}

// 230 2.1
// this gcd function do not need to check which input bigger
int gcd(int a, int b){
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}
vector <int> InequalityChecker::getDifferences(int n) {
	int s = 0;
	int S = 0;
	for(int i=1; i<=n-1; i++){
		s += i*i*i;
	}
	for(int i=1; i<=n; i++){
		S += i*i*i;
	}
	int a = 2*(S+s) - n*n*n*n;
	int b = 4;
	int c = gcd(a, b);
	vector<int> v(2);
	v[0] = a/c;
	v[1] = b/c;
	return v;
}
// better
vector <int> InequalityChecker::getDifferences(int n) {
	int s = 0;
	int S = 0;
	for(int i=1; i<=n-1; i++){
		s += i*i*i;
	}
	S = s + n*n*n;
	int a = 2*(S+s) - n*n*n*n;
	int b = 4;
	int c = gcd(a, b);
	vector<int> v(2);
	v[0] = a/c;
	v[1] = b/c;
	return v;
}
// even better
vector <int> InequalityChecker::getDifferences(int n) {
	int m = n-1;
	int s = m*m*m*m/4 + n*n*n/2 + n*n/4;
	int S = n*n*n*n/4 + n*n*n/2 + n*n/4;
	int a = 2*(S+s) - n*n*n*n;
	int b = 4;
	int c = gcd(a, b);
	vector<int> v(2);
	v[0] = a/c;
	v[1] = b/c;
	return v;
}

// 584 2.1
int TopFox::possibleHandles(string familyName, string givenName) {
	set<string> s;
	for(int i=1; i<=familyName.size(); i++){
		for(int j=1; j<=givenName.size(); j++){
			s.insert(familyName.substr(0, i) + givenName.substr(0, j));
		}
	}
	return s.size();
}

// 578 2.1
// brute force
vector <int> DeerInZooDivTwo::getminmax(int N, int K) {
	vector<int> v(2);
	v[0] = numeric_limits<int>::max();
	v[1] = -1;
	for(int i=0; i<=N; i++){
		for(int j=i; j<=N; j++){
			int a = i;
			int b = j-i;
			int c = N-j;
			if(N*2 - (b+c*2) == K){
				v[0] = min(x, c);
				v[1] = max(y, c);
			}
		}
	}
	return v;
}
// better
vector <int> DeerInZooDivTwo::getminmax(int N, int K) {
	vector<int> v(2);
	v[0] = max(0, N - K);
	v[1] = N - (K+1)/2;
	return v;
}

// 614 2.1
string MicroStrings::makeMicroString(int A, int D) {
	string ans = "";
	for(int i=0; A-i*D>=0; i++){
		stringstream ss;
		ss << A-i*D;
		ans += ss.str();
	}
	return ans;
}

// 530 2.1
// permutation
int GogoXBallsAndBinsEasy::solve(vector <int> T){
	vector<int> v = T;
	int ans = 0;
	do{
		int t = 0;
		for(int i=0; i<v.size(); i++){
			t += abs(v[i]-T[i]);
		}
		ans = max(ans, t/2);
	}while(next_permutation(v.begin(), v.end()));
	return ans;
}
// better
int GogoXBallsAndBinsEasy::solve(vector <int> T){
	vector<int> v = T;
	reverse(v.begin(), v.end());
	int t = 0;
	for(int i=0; i<v.size(); i++){
		t += abs(T[i]-v[i]);
	}
	return t/2;
}

// 592 2.1
int LittleElephantAndBooks::getNumber(vector <int> pages, int number){
	sort(pages.begin(), pages.end());
	int ans = 0;
	for(int i=0; i<number-1; i++){
		ans += pages[i];
	}
	ans += pages[number];
	return ans;
}

// 557 2.1
int GreatFairyWar::minHP(vector <int> dps, vector <int> hp) {
	int ans = 0;
	for(int i=0; i<hp.size(); i++){
		for(int j=i; j<hp.size(); j++){
			ans += hp[i]*dps[j];
		}
	}
	return ans;
}

// 605 2.1
int AlienAndPassword::getNumber(string S) {
	set<string> s;
	for(int i=0; i<S.size(); i++){
		string t = "";
		for(int j=0; j<S.size(); j++){
			if(i!=j){
				t += S[j];
			}
		}
		s.insert(t);
	}
	return s.size();
}
// better
int AlienAndPassword::getNumber(string S) {
	set<string> s;
	for(int i=0; i<S.size(); i++){
		string a = S.substr(0, i);
		string b = S.substr(i+1);
		s.insert(a+b);
	}
	return s.size();
}

// 238 2.1
int ArrayHash::getHash(vector <string> input) {
	int ans = 0;
	for(int i=0; i<input.size(); i++){
		for(int j=0; j<input[i].size(); j++){
			ans += j + input[i][j] - 'A' + i;
		}
	}
	return ans;
}

// 571 2.1
int FoxAndGame::countStars(vector <string> result) {
	int ans = 0;
	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			if(result[i][j]=='o'){
				ans++;
			}
		}
	}
	return ans;
}

// 618 2.1
int WritingWords::write(string word) {
	int ans = 0;
	for(int i=0; i<word.size(); i++){
		ans += word[i]-'A'+1;
	}
	return ans;
}

// 271 2.1
int CheckFunction::newFunction(string code) {
	int f[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int ans = 0;
	for(int i=0; i<code.size(); i++){
		ans += f[code[i]-'0'];
	}
	return ans;
}

// 504 2.1
int ComparerInator::makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {
	int f[] = {0, 0, 0, 0};
	int ff[] = {1, 1, 7, 7};
	for(int i=0; i<A.size(); i++){
		if(A[i] == wanted[i]){
			f[0]++;
		}
		if(B[i] == wanted[i]){
			f[1]++;
		}
		if((A[i]<B[i]?A[i]:B[i]) == wanted[i]){
			f[2]++;
		}
		if((A[i]<B[i]?B[i]:A[i]) == wanted[i]){
			f[3]++;
		}
	}
	bool b = false;
	int ans = 10;
	for(int i=0; i<4; i++){
		if(f[i] == A.size()){		
			ans = min(ans, ff[i]);
			b = true;
		}
	}
	if(!b){
		return -1;
	}
	return ans;
}
// seems better
int ComparerInator::makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {
	bool a=true, b=true, c=true, d=true;
	for(int i=0; i<A.size(); i++){
		if(A[i]!=wanted[i]){
			a = false;
		}
		if(B[i]!=wanted[i]){
			b = false;
		}
		if(min(A[i], B[i])!=wanted[i]){
			c = false;
		}
		if(max(A[i], B[i])!=wanted[i]){
			d = false;
		}
	}
	if(a||b){
		return 1;
	}
	if(c||d){
		return 7;
	}
	return -1;
}

// 240 2.2
// backtrack will not pass the time constraint
void backtrack(vector< vector< pair<int, int> > >& v, int& r, int t, int n, int l){
	if(n == v.size()){
		r = min(r, t);
		return;
	}
	for(int i=0; i<v[n].size(); i++){
		if(n==0){
			backtrack(v, r, v[n][i].second, n+1, i);
		}else{
			int x = v[n][i].first<v[n-1][l].second? (v[n][i].first+24*60-v[n-1][l].second): (v[n][i].first-v[n-1][l].second);
			int y = v[n][i].second<=v[n][i].first? (v[n][i].second+24*60-v[n][i].first): (v[n][i].second-v[n][i].first);
			backtrack(v, r, t+x+y, n+1, i);
		}
	}
}
string TravellingByTrain::earliestArrival(vector <string> timeTable) {
	vector< vector< pair<int, int> > > v(timeTable.size()+1);
	vector< pair<int, int> > vt(1, make_pair(0, 9*60));
	v[0] = vt;
	for(int i=0; i<timeTable.size(); i++){
		stringstream ss(timeTable[i]);
		string t;
		vector< pair<int, int> > vv;
		while(ss >> t){
			int a = ((t[0]-'0')*10+t[1]-'0' )*60 + (t[3]-'0')*10+t[4]-'0';
			int b = ((t[6]-'0')*10+t[7]-'0' )*60 + (t[9]-'0')*10+t[10]-'0';
			vv.push_back(make_pair(a, b));
		}
		v[i+1] = vv;
	}	
	int r = numeric_limits<int>::max();
	backtrack(v, r, 0, 0, 0);
	int a = r/24/60 + 1;
	int b = (r%(24*60))/60;
	int c = (r%(24*60))%60;
	stringstream ss;
	ss << setfill('0')<<setw(2) << b << ':'<<setfill('0')<<setw(2) << c << ", day " << a;
	return ss.str();
}
// compare each timeTable[i][j] and choose the earliest time
string TravellingByTrain::earliestArrival(vector <string> timeTable) {
	string a = "09:00";
	int b = 1;
	for(int i=0; i<timeTable.size(); i++){
		stringstream ss(timeTable[i]);
		string t;
		int j = 0;
		string aa;
		int bb;
		while(ss >> t){
			string x = t.substr(0, 5);
			string y = t.substr(6, 5);
			int z = 0;
			if(x < a){
				z++;
			}
			if(y <= x){
				z++;
			}
			if(j==0 || z<bb || (z==bb && y<aa)){
				aa = y;
				bb = z;
			}
			j++;
		}
		a = aa;
		b += bb;
	}
	stringstream ss;
	ss << a << ", day " << b;
	return ss.str();
}
string TravellingByTrain::earliestArrival(vector <string> timeTable) {
	string a = "09:00";
	int b = 1;
	for(int i=0; i<timeTable.size(); i++){
		stringstream ss(timeTable[i]);
		string t;
		string c;
		int d;
		int j = 0;
		while(ss >> t){
			string e = t.substr(0, 5);
			string f = t.substr(6, 5);
			int g = b;
			if(e < a){
				g++;
			}
			if(f <= e){
				g++;
			}
			if(j==0 || g<d || (g==d&&f<c)){
				c = f;
				d = g;
			}
			j++;
		}
		a = c;
		b = d;
	}
	stringstream ss;
	ss << a << ", day " << b;
	return ss.str();
}

// 613 2.2
int TaroFriends::getNumber(vector <int> coordinates, int X) {
	int n = coordinates.size();
	sort(coordinates.begin(), coordinates.end());
	int ans = numeric_limits<int>::max();
	for(int i=0; i<=n; i++){
		vector<int> t = coordinates;
		for(int j=0; j<n; j++){
			if(j<i){
				t[j] += X;
			}else{
				t[j] -= X;
			}
		}
		int a = *max_element(t.begin(), t.end()) - *min_element(t.begin(), t.end());
		ans = min(ans, a);
	}
	return ans;
}
// faster
int TaroFriends::getNumber(vector <int> coordinates, int X) {
	sort(coordinates.begin(), coordinates.end());
	int ans = numeric_limits<int>::max();
	for(int i=0; i<=coordinates.size(); i++){
		int a = numeric_limits<int>::max();
		int b = numeric_limits<int>::min();
		for(int j=0; j<coordinates.size(); j++){
			int t;
			if(j<i){
				t = coordinates[j] + X; 
			}else{
				t = coordinates[j] - X;
			}
			a = min(a, t);
			b = max(b, t);
		}
		ans = min(ans, b-a);
	}
	return ans;
}

// 438 2.2
double FeudaliasBattle::getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed) {
	vector< pair< double, pair<int, int> > > v;
	for(int i=0; i<siloX.size(); i++){
		for(int j=0; j<baseX.size(); j++){
			double x = siloX[i]-baseX[j];
			double y = siloY[i]-baseY[j];
			double a = sqrt(x*x+y*y)/missileSpeed + takeOffTime/60.0;
			double b = a + takeOffTime/60.0 + rechargeTime;
			v.push_back(make_pair(a, make_pair(i, j)));
			v.push_back(make_pair(b, make_pair(i+10, j)));
		}
	}
	double ans = numeric_limits<double>::max();
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if(v[i].second.first!=v[j].second.first && v[i].second.second!=v[j].second.second){
				ans = min(ans, max(v[i].first, v[j].first));
			}
		}
	}
	return ans;
}
// better
double FeudaliasBattle::getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed) {
	vector< pair< double, pair<int, int> > > v;
	for(int i=0; i<baseX.size(); i++){
		for(int j=0; j<siloX.size(); j++){
			for(int k=0; k<2; k++){
				double x = siloX[j]-baseX[i];
				double y = siloY[j]-baseY[i];
				double a = sqrt(x*x+y*y)/missileSpeed + takeOffTime/60.0*(k+1) + k*rechargeTime;
				v.push_back(make_pair(a, make_pair(i, j*2+k)));
			}
		}
	}
	double ans = numeric_limits<double>::max();
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if(v[i].second.first!=v[j].second.first && v[i].second.second!=v[j].second.second){
				ans = min(ans, max(v[i].first, v[j].first));
			}
		}
	}
	return ans;
}
double FeudaliasBattle::getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed) {
	vector< pair< double, pair<int, int> > > v;
	for(int i=0; i<baseX.size(); i++){
		for(int j=0; j<siloX.size(); j++){
			double a = sqrt(((long long)siloX[j]-baseX[i])*(siloX[j]-baseX[i])+((long long)siloY[j]-baseY[i])*(siloY[j]-baseY[i]));
			double b = a/missileSpeed + takeOffTime/60.0;
			double c = b + takeOffTime/60.0 + rechargeTime;
			v.push_back(make_pair(b, make_pair(j*2, i)));
			v.push_back(make_pair(c, make_pair(j*2+1, i)));
		}
	}
	double ans = numeric_limits<double>::max();
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if(v[i].second.first!=v[j].second.first && v[i].second.second!=v[j].second.second){
				ans = min(ans, max(v[i].first, v[j].first));
			}
		}
	}
	return ans;
}

// 402 2.2
// wrong answer
vector <int> ConsecutiveNumbers::missingNumber(vector <int> numbers) {
	int n = numbers.size();
	vector<int> v;
	sort(numbers.begin(), numbers.end());
	if(numbers[n-1]-numbers[0]+1 == n){
		if(numbers[0]-1>0){
			v.push_back(numbers[0]-1);
		}
		v.push_back(numbers[n-1]+1);
	}else if(numbers[n-1]-numbers[0]+1-n <= 1){
		for(int i=0, j=numbers[0]; i<n; j++){
			if(numbers[i]!=j){
				v.push_back(j);
			}else{
				i++;
			}
		}
	}
	return v;
}
// correct
vector <int> ConsecutiveNumbers::missingNumber(vector <int> numbers) {
	int n = numbers.size();
	sort(numbers.begin(), numbers.end());
	vector<int> v;
	int a = 0;
	for(int i=1; i<numbers.size(); i++){
		int t = numbers[i]-numbers[i-1];
		if(t == 2){
			if(a == 1){
				return vector<int>();
			}
			v.push_back(numbers[i]-1);
			a++;
		}else if(t != 1){
			return vector<int>();
		}
	}
	if(a == 0){
		if(numbers[0]-1 > 0){
			v.push_back(numbers[0]-1);
		}
		v.push_back(numbers[n-1]+1);
	}
	return v;
}
// seems better
vector <int> ConsecutiveNumbers::missingNumber(vector <int> numbers) {
	sort(numbers.begin(), numbers.end());
	vector<int> v;
	for(int i=1; i<numbers.size(); i++){
		int a = numbers[i] - numbers[i-1];
		if(a == 2 && v.empty()){
			v.push_back(numbers[i]-1);
		}else if(a != 1){
			return vector<int>();
		}
	}
	if(!v.empty()){
		return v;
	}
	if(numbers[0]!=1){
		v.push_back(numbers[0]-1);
	}
	v.push_back(numbers[numbers.size()-1]+1);
	return v;
}

// 259 2.2
bool isp(int n){
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
int PrimePolynom::reveal(int A, int B, int C) {
	int i = 0;
	while(isp(A*i*i+B*i+C)){
		i++;
	}
	return i;
}

// 433 2.2
// correct logic but time limit exceed
void backtrack(vector<string>& s, int k, int n, int& ans){
	if(n==s.size()){
		string t;
		for(int i=0; i<s.size(); i++){
			t += s[i];
		}
		int c = 0;
		for(int i=0; i<t.size(); i++){
			if(t.substr(i)+t.substr(0,i)==t){
				c++;
			}
		}
		if(c==k){
			ans++;
		}
		return;
	}
	for(int i=n; i<s.size(); i++){
		swap(s[n], s[i]);
		backtrack(s, k, n+1, ans);
		swap(s[n], s[i]);
	}
}
int MagicWords::count(vector <string> S, int K) {
	int ans = 0;
	backtrack(S, K, 0, ans);
	return ans;
}
// better, improved the time, but still time out
void backtrack(vector<string>& s, int k, int n, map<string, bool>& m, int& ans){
	if(n==s.size()){
		string t;
		for(int i=0; i<s.size(); i++){
			t += s[i];
		}
		if(m.find(t)!=m.end()){
			if(m[t]){
				ans++;
			}
			return;
		}
		int c = 0;
		for(int i=0; i<t.size(); i++){
			if(t.substr(i)+t.substr(0,i)==t){
				c++;
			}
		}
		if(c==k){
			ans++;
			m[t] = true;
		}else{
			m[t] = false;
		}
		return;
	}
	for(int i=n; i<s.size(); i++){
		swap(s[n], s[i]);
		backtrack(s, k, n+1, m, ans);
		swap(s[n], s[i]);
	}
}
int MagicWords::count(vector <string> S, int K) {
	int ans = 0;
	map<string, bool> m;
	backtrack(S, K, 0, m, ans);
	return ans;
}
// seems better, using native function, but still time limit exceed
int MagicWords::count(vector <string> S, int K) {
	int ans = 0;
	map<string, bool> m;
	vector<int> v(S.size());
	for(int i=0; i<S.size(); i++){
		v[i] = i;
	}
	do{
		string t;
		for(int i=0; i<S.size(); i++){
			t += S[v[i]];
		}
		if(m.find(t)!=m.end()){
			if(m[t]){
				ans++;
			}
			continue;
		}
		int c = 0;
		for(int i=0; i<t.size(); i++){
			if(t.substr(i)+t.substr(0,i)==t){
				c++;
			}
		}
		if(c==K){
			ans++;
			m[t] = true;
		}else{
			m[t] = false;
		}
	}while(next_permutation(v.begin(), v.end()));
	return ans;
}
// solved, by not using stl substr() function, seems it eat a lot of time
int MagicWords::count(vector <string> S, int K) {
	int ans = 0;
	map<string, bool> m;
	vector<int> v(S.size());
	for(int i=0; i<S.size(); i++){
		v[i] = i;
	}
	do{
		string t;
		for(int i=0; i<S.size(); i++){
			t += S[v[i]];
		}
		if(m.find(t)!=m.end()){
			if(m[t]){
				ans++;
			}
			continue;
		}
		int c = 0;
		for(int i=0; i<t.size(); i++){
			bool b = true;
			for(int j=0; j<t.size(); j++){
				if(t[j] != t[(i+j)%t.size()]){
					b = false;
					break;
				}
			}
			if(b){
				c++;
			}
		}
		if(c==K){
			ans++;
			m[t] = true;
		}else{
			m[t] = false;
		}
	}while(next_permutation(v.begin(), v.end()));
	return ans;
}

// 270 2.2
// brute force, correct logic but tle
// editorial said can optimize it to pass
// by "stop as soon as the tip exceeds 10% of the sum you pay"
int TippingWaiters::possiblePayments(int bill, int cash) {
	int a = bill;
	int b = cash;
	while((a-bill)*1.0/a*100<5 || a%5!=0) a++;
	while((b-bill)*1.0/b*100>10 || b%5!=0) b--;
	if(a>b) return 0;
	return (b-a)/5+1;
}
// use binary search
int TippingWaiters::possiblePayments(int bill, int cash) {
	int l = bill;
	int r = cash;
	while(l<=r){
		int m = l + (r-l)/2;
		double a = (m-bill)*1.0/m*100;
		if(a<5){
			l = m+1;
		}else{
			r = m-1;
		}
	}
	int ll = bill;
	int rr = cash;
	while(ll<=rr){
		int m = ll+(rr-ll)/2;
		double a = (m-bill)*1.0/m*100;
		if(a>10){
			rr = m-1;
		}else{
			ll = m+1;
		}
	}
	if(l>rr){
		return 0;
	}
	int a = l;
	int b = rr;
	while(a%5!=0){
		a++;
	}
	while(b%5!=0){
		b--;
	}
	if(a>b){
		return 0;
	}
	return (b-a)/5+1;
}
// better binary search
int TippingWaiters::possiblePayments(int bill, int cash) {
	int l = bill;
	int r = cash;
	while(l<=r){
		int m = l+(r-l)/2;
		if((m-bill)*20LL<m){
			l = m+1;
		}else{
			r = m-1;
		}
	}
	int ll = bill;
	int rr = cash;
	while(ll<=rr){
		int m = ll+(rr-ll)/2;
		if((m-bill)*10LL>m){
			rr = m-1;
		}else{
			ll = m+1;
		}
	}
	int a = l;
	int b = rr;
	while(a%5!=0) a++;
	while(b%5!=0) b--;
	if(b<a){
		return 0;
	}
	return (b-a)/5+1;
}
// seems better
int TippingWaiters::possiblePayments(int bill, int cash) {
	long long a = (long long)ceil(20/19.0*bill);
	long long b = (long long)(10/9.0*bill);
	b = min(b, (long long)cash);
	while(a%5!=0){
		a++;
	}
	while(b%5!=0){
		b--;
	}
	if(a>b){
		return 0;
	}
	return (b-a)/5+1;
}
// better
int TippingWaiters::possiblePayments(int bill, int cash) {
	int a = bill + (bill+18)/19;
	int b = bill + bill/9;
	b = min(b, cash);
	while(a%5!=0) a++;
	while(b%5!=0) b--;
	if(a>b) return 0;
	return (b-a)/5+1;
}

// 533 2.2
// backtrack version
void backtrack(vector<int>& w, int m, int& ans){
	if(w.size()==2){
		ans = max(ans, m);
		return;
	}
	for(int i=0; i+2<w.size(); i++){
		vector<int> v(w.size()-1);
		for(int j=0; j<w.size(); j++){
			if(j<i+1){
				v[j] = w[j];
			}else if(j>i+1){
				v[j-1] = w[j];
			}
		}
		backtrack(v, m+w[i]*w[i+2], ans);
	}
}
int CasketOfStarEasy::maxEnergy(vector <int> weight) {
	int ans = -1;
	backtrack(weight, 0, ans);
	return ans;
}
// dfs version
int dfs(vector<int>& w){
	int ans = 0;
	for(int i=0; i+2<w.size(); i++){
		vector<int> v(w.size()-1);
		for(int j=0; j<w.size(); j++){
			if(j<i+1){
				v[j] = w[j];
			}else if(j>i+1){
				v[j-1] = w[j];
			}
		}
		ans = max(ans, dfs(v)+w[i]*w[i+2]);
	}
	return ans;
}
int CasketOfStarEasy::maxEnergy(vector <int> weight) {
	return dfs(weight);
}

// 539 2.2
// pure backtrack all combination
// clearly will tle
void backtrack(vector<int>& l, vector<int>& u, long long t, int n, set<int>& s){
	if(n==l.size()){
		if(t>9000){
			s.insert(t);
		}
		return;
	}
	for(int i=l[n]; i<=u[n]; i++){
		backtrack(l, u, t+i, n+1, s);
	}
}
int Over9000Rocks::countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
	int n = lowerBound.size();
	set<int> s;
	for(int i=0; i<2<<n; i++){
		vector<int> l(n, 0);
		vector<int> u(n, 0);
		for(int j=0; j<n; j++){
			if(i&(1<<j)){
				l.push_back(lowerBound[j]);
				u.push_back(upperBound[j]);
			}
		}
		backtrack(l, u, 0, 0, s);
	}
	return s.size();
}
// solved
// calculate ans by finding range
int Over9000Rocks::countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
	int n = lowerBound.size();
	vector< pair<int, int> > v;
	for(int i=1; i<1<<n; i++){
		int a = 0, b = 0;
		for(int j=0; j<n; j++){
			if(i&(1<<j)){
				a += lowerBound[j];
				b += upperBound[j];
			}
		}
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int t = 9000;
	for(int i=0; i<v.size(); i++){
		if(v[i].first > t){
			ans += v[i].second-v[i].first+1;
			t = v[i].second;
		}
		if(v[i].second > t){
			ans += v[i].second-t;
			t = v[i].second;
		}
	}
	return ans;
}

// 276 2.2
void backtrack(vector< pair<int, int> >& v, int n, int g, int q, int m, int& ans){
	if(q>=g){
		ans = min(ans, m);
		return;
	}
	if(n==v.size()){
		return;
	}
	int b = v[n].first;
	while(b<g){
		b+=v[n].first;
	}
	for(int i=v[n].first; i<=b; i+=v[n].first){
		backtrack(v, n+1, g, q+i, m+i/v[n].first*v[n].second, ans);
	}
}
int VolumeDiscount::bestDeal(vector <string> priceList, int quantity) {
	int ans = numeric_limits<int>::max();
	for(int i=1; i<1<<priceList.size(); i++){
		vector< pair<int, int> > v;
		for(int j=0; j<priceList.size(); j++){
			if(i&(1<<j)){
				stringstream ss(priceList[j]);
				int a, b;
				ss >> a >> b;
				v.push_back(make_pair(a, b));
			}
		}
		backtrack(v, 0, quantity, 0, 0, ans);
	}
	return ans;
}

// 597 2.2
// tle
void backtrack(string& a, string& b, int n, int& ans, int& aa, int t){
	if(a==b){
		aa = 1;
		ans = min(ans, t);
		return;
	}
	if(n==a.size()){
		return;
	}
	for(int i=n; i<a.size(); i++){
		if(a[i]==b[b.size()-1-i]){
			string s;
			s += a[i];
			for(int j=0; j<a.size(); j++){
				if(j!=i){
					s += a[j];
				}
			}
			backtrack(s, b, n+1, ans, aa, t+1);
		}
	}
}
int LittleElephantAndString::getNumber(string A, string B) {
	int ans = numeric_limits<int>::max();
	int aa = 0;
	backtrack(A, B, 0, ans, aa, 0);
	if(aa==0){
		return -1;
	}
	return ans;
}
// find the largest suffix of B that is a subsequence of A, then size minus that value
int LittleElephantAndString::getNumber(string A, string B) {
	if(multiset<char>(A.begin(), A.end()) != multiset<char>(B.begin(), B.end())){
		return -1;
	}
	int t = 0;
	for(int i=A.size()-1, j=B.size()-1; i>=0 && j>=0; i--){
		if(A[i]==B[j]){
			t++;
			j--;
		}
	}
	return A.size()-t;
}

// 591 2.2
// tle
int ConvertibleStrings::leastRemovals(string A, string B) {
	map< pair<int, int>, int > m;
	for(int i=0; i<A.size(); i++){
		pair<int, int> p(A[i], B[i]);
		if(m.find(p)!=m.end()){
			m[p]++;
		}else{
			m[p] = 1;
		}
	}
	int ans = numeric_limits<int>::max();
	for(int i=1; i<1<<m.size(); i++){
		set<int> a;
		set<int> b;
		int t = 0;
		bool bb = true;
		int j = 0;
		for(map< pair<int, int>, int >::iterator it=m.begin(); it!=m.end(); it++, j++){
			if(i&(1<<j)){
				if(!a.insert(it->first.first).second || !b.insert(it->first.second).second){
					bb = false;
					break;
				}
				t += it->second;
			}
		}
		if(bb){
			ans = min(ans, (int)A.size()-t);
		}
	}
	return ans;
}
// little better, still tle
int ConvertibleStrings::leastRemovals(string A, string B) {
	map< pair<int, int>, int > m;
	for(int i=0; i<A.size(); i++){
		pair<int, int> p(A[i], B[i]);
		if(m.find(p)!=m.end()){
			m[p]++;
		}else{
			m[p] = 1;
		}
	}
	int ans = numeric_limits<int>::max();
	for(int i=1; i<1<<m.size(); i++){
		vector<int> a(200);
		vector<int> b(200);
		int t = 0;
		bool bb = true;
		int j = 0;
		for(map< pair<int, int>, int >::iterator it=m.begin(); it!=m.end(); it++, j++){
			if(i&(1<<j)){
				if(a[it->first.first]==1 || b[it->first.second]==1){
					bb = false;
					break;
				}
				a[it->first.first] = 1;
				b[it->first.second] = 1;
				t += it->second;
			}
		}
		if(bb){
			ans = min(ans, (int)A.size()-t);
		}
	}
	return ans;
}
// it generate all the diff version of string A, then compare with B 
int ConvertibleStrings::leastRemovals(string A, string B) {
	string f = "ABCDEFGHI";
	int ans = numeric_limits<int>::max();
	do{
		int t = 0;
		for(int i=0; i<A.size(); i++){
			if(f[A[i]-'A'] != B[i]){
				t++;
			}
		}
		ans = min(ans, t);
	}while(next_permutation(f.begin(), f.end()));
	return ans;
}

// 270 2.1
int BuyingCheap::thirdBestPrice(vector <int> prices) {
	sort(prices.begin(), prices.end());
	int t = 1;
	for(int i=1; i<prices.size(); i++){
		if(prices[i]!=prices[i-1]){
			t++;
		}
		if(t == 3){
			return prices[i];
		}
	}
	return -1;
}
int BuyingCheap::thirdBestPrice(vector <int> prices) {
	set<int> s(prices.begin(), prices.end());
	if(s.size() < 3) return -1;
	set<int>::iterator i = s.begin();
	advance(i, 2);
	return *i;
}
int BuyingCheap::thirdBestPrice(vector <int> prices) {
	set<int> s(prices.begin(), prices.end());
	vector<int> v(s.begin(), s.end());
	if(v.size()<3) return -1;
	return v[2];
}

// 539 2.1
int PlatypusPaternity::maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups) {
	int ans = 0;
	for(int i=0; i<femaleCompatibility.size(); i++){
		for(int j=0; j<maleCompatibility.size(); j++){
			for(int k=0; k<siblingGroups.size(); k++){
				int t = 0;
				bool b = true;
				for(int m=0; m<siblingGroups[k].size(); m++){
					if(siblingGroups[k][m]=='Y'&&maleCompatibility[j][m]=='Y'&&femaleCompatibility[i][m]=='Y'){
						t++;
					}else if(siblingGroups[k][m]=='Y'&&(maleCompatibility[j][m]=='N'||femaleCompatibility[i][m]=='N')){
						b = false;
						break;
					}
				}
				if(t>0 && b)
					ans = max(ans, 2+t);
			}
		}
	}
	return ans;
}

// 305 2.2
int UnfairDivision::albertsShare(vector <int> assets) {
	int ans = 0;
	for(int i=1; i<assets.size(); i++){
		int a = -1;
		int b = -1;
		// cannot change to j=i+1, since point of view is different
		for(int j=1; j<assets.size(); j++){
			if(i!=j){
				int m = min(i, j);
				int n = max(i, j);
				vector<int> v(3);
				for(int k=0; k<assets.size(); k++){
					if(k<m){
						v[0] += assets[k];
					}else if(m<=k && k<n){
						v[1] += assets[k];
					}else{
						v[2] += assets[k];
					}
				}
				sort(v.begin(), v.end());
				if(v[1]>a || (v[1]==a&&v[0]<b)){
					a = v[1];
					b = v[0];
				}
			}
		}
		ans = max(ans, b);
	}
	return ans;
}

// 196 2.2
// this is brute force, but we can also use binary search
int ClapLight::threshold(vector <int> background) {
	for(int i=0; i<=1001; i++){
		bool b = true;
		for(int j=0; j<background.size()-3; j++){
			if(background[j]<i && background[j+1]>=i && background[j+2]>=i && background[j+3]<i){
				b = false;
				break;
			}
		}
		if(!b){
			continue;
		}
		int t = 0;
		for(int j=0; j<background.size(); j++){
			if(background[j]<i) t++;
		}
		if(t*2>background.size()){
			return i;
		}
	}
	return -1;
}

// 484 2.2
int sum(long long a){
	int t = 0;
	while(a > 0){
		t += a%10;
		a /= 10;
	}
	return t;
}
int RabbitNumber::theCount(int low, int high) {
	int f[] = {0, 1, 2, 3};
	int ans = 0;
	int i=1;
	while(1){
		int t = i;
		long long a = 0;
		int b = 1;
		while(t){
			a += f[t%4]*b;
			b *= 10;
			t /= 4;
		}
		if(a>high){
			break;
		}
		if(a>=low && a<=high && sum(a*a) == sum(a)*sum(a)){
			ans++; 
		}
		i++;
	}
	return ans;
}
// t >> 2*j means, for each digit j, t/(4^j) to see how much the jth digit have in base 4,
// then &3 means, since 3 is 11 in binary, if 0..100 &3, it will be 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, ....
// which is periodic, then we will know what will be the number in base 4 if we &3,
// then so for every digit j, since we know how much is the jth digit, if we
// just &3 the jth digit, we will know how to represent each digit in terms of 0, 1, 2, 3
// so then we can get the number in base 4, the same method applies to other base
int RabbitNumber::theCount(int low, int high) {
	int ans = 0;
	int i = 1;
	while(1){
		int t = i;
		long long a = 0;
		int b = 1;
		int j = 0;
		while(t >> (2*j)){
			int x = ((t >> (2*j)) & 3);
			a += x*b;
			b *= 10;
			j++;
		}
		if(a > high){
			break;
		}
		if(a>=low && a<=high && sum(a*a) == sum(a)*sum(a)){
			ans++;
		}
		i++;
	}
	return ans;
}
// recursion
int sum(long long a){
	int t = 0;
	while(a > 0){
		t += a%10;
		a /= 10;
	}
	return t;
}
void count(long long t, int l, int h, int& ans){
	if(t>h){
		return;
	}
	if(t>=l && t<=h){
		if(sum(t*t)==sum(t)*sum(t)){
			ans++;
		}
	}
	count(t*10, l, h, ans);
	count(t*10+1, l, h, ans);
	count(t*10+2, l, h, ans);
	count(t*10+3, l, h, ans);
}
int RabbitNumber::theCount(int low, int high) {
	int ans = 0;
	count(1, low, high, ans);
	count(2, low, high, ans);
	count(3, low, high, ans);
	return ans;
}

// 516 2.2
int NetworkXOneTimePad::crack(vector <string> plaintexts, vector <string> ciphertexts) {
	set< vector<int> > s;
	for(int i=0; i<plaintexts.size(); i++){
		for(int j=0; j<ciphertexts.size(); j++){
			vector<int> v;
			for(int k=0; k<ciphertexts[j].size(); k++){
				v.push_back((plaintexts[i][k]-'0')^(ciphertexts[j][k]));
			}
			s.insert(v);
		}
	}
	int ans = 0;
	for(set< vector<int> >::iterator i=s.begin(); i!=s.end(); i++){
		vector<int> v(plaintexts.size());
		for(int j=0; j<ciphertexts.size(); j++){
			string t;
			for(int k=0; k<ciphertexts[j].size(); k++){
				t += (ciphertexts[j][k]-'0')^(*i)[k];
			}
			for(int k=0; k<plaintexts.size(); k++){
				if(plaintexts[k]==t && v[k]==0){
					v[k]=1;
				}
			}
		}
		if(accumulate(v.begin(), v.end(), 0)==ciphertexts.size()){
			ans++;
		}
	}
	return ans;
}

// 251 2.2
bool isv(char c){
	c = tolower(c);
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
string SMS::compress(string originalMessage) {
	vector<int> v(originalMessage.size());
	for(int i=0; i<originalMessage.size(); i++){
		if(isv(originalMessage[i])){
			int a = 0;
			int j = i-1;
			while(j>=0 && isalpha(originalMessage[j])){
				if(!isv(originalMessage[j])){
					a++;
				}
				j--;
			}
			int b = 0;
			j = i+1;
			while(j<originalMessage.size() && isalpha(originalMessage[j])){
				if(!isv(originalMessage[j])){
					b++;
				}
				j++;
			}
			if(a&&b){
				v[i] = 1;
			}
		}
	}
	for(int i=originalMessage.size()-1; i>=0; i--){
		if(v[i]==1){
			originalMessage.erase(originalMessage.begin()+i);
		}
	}
	return originalMessage;
}

// 285 2.2
int SentenceSplitting::split(string sentence, int K) {
	vector<string> v;
	stringstream ss(sentence);
	string t;
	while(ss >> t){
		v.push_back(t);
	}
	for(int i=1; i<=sentence.size(); i++){
		int a = -1;
		int c = 0;
		bool b = true;
		for(int j=0; j<v.size(); j++){
			if(a + v[j].size() + 1 > i){
				c++;
				a = v[j].size();
				if(c>K || a>i){
					b = false;
					break;
				}
			}else{
				a += v[j].size() + 1;
			}
		}
		if(b){
			return i;
		}
	}
	return -1;
}

// 553 2.2
long long pp(stack<long long>& s){
	if(s.empty()) return 0;
	long long t = s.top();
	s.pop();
	return t;
}
int Suminator::findMissing(vector <int> program, int wantedResult) {
	stack<long long> a;
	stack<long long> b;
	for(int i=0; i<program.size(); i++){
		if(program[i]==0){
			a.push(pp(a)+pp(a));
			b.push(pp(b)+pp(b));
		}else if(program[i]==-1){
			a.push(pp(a)+pp(a));
			b.push(program[i]);
		}else{
			a.push(program[i]);
			b.push(program[i]);
		}
	}
	long long x = pp(a);
	long long y = pp(b);
	if(x == wantedResult){
		return 0;
	}
	long long t = (long long)wantedResult - y;
	if(t < 0){
		return -1;
	}
	stack<long long> c;
	for(int i=0; i<program.size(); i++){
		if(program[i]==0 || (program[i]==-1 && -1+t==0)){
			c.push(pp(c)+pp(c));
		}else if(program[i]==-1){
			c.push(-1+t);
		}else{
			c.push(program[i]);
		}
	}
	long long z = pp(c);
	if(z == wantedResult){
		return -1+t;
	}
	return -1;
}
// better
long long pp(stack<long long>& s){
	if(s.empty()) return 0;
	long long t = s.top();
	s.pop();
	return t;
}
long long cal(vector<int>& v, int x){
	stack<long long> s;
	for(int i=0; i<v.size(); i++){
		int t = v[i]==-1? x: v[i];
		if(t == 0){
			s.push(pp(s)+pp(s));
		}else{
			s.push(t);
		}
	}
	return pp(s);
}
int Suminator::findMissing(vector <int> program, int wantedResult) {
	long long x = cal(program, 0);
	long long y = cal(program, -1);
	if(x == wantedResult){
		return 0;
	}
	if(wantedResult < y){
		return -1;
	}
	long long z = cal(program, -1+wantedResult-y);
	if(z == wantedResult){
		return -1+wantedResult-y;
	}
	return -1;
}

// 568 2.2
// the first approach which is correct logic would be, have a vector< pair< sum of other two color ball, pair<index, which color> > >
// sort this vector, then find the first red.size() elements that has no duplication in index, and at least has 1 in each color,
// but i do not how to code this solution, so the below one is brute force to force each to appear once, then find its best score among them
int BallsSeparating::minOperations(vector <int> red, vector <int> green, vector <int> blue) {
	int n = red.size();
	if(n<3){
		return -1;
	}
	int ans = numeric_limits<int>::max();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(i!=j && j!=k && k!=i){
					int t = 0;
					for(int m=0; m<n; m++){
						int r = green[m]+blue[m];
						int g = red[m]+blue[m];
						int b = red[m]+green[m];
						if(m==i){
							t += r;
						}else if(m==j){
							t += g;
						}else if(m==k){
							t += b;
						}else{
							t += min(r, min(g, b));
						}
					}
					ans = min(ans, t);
				}
			}
		}
	}
	return ans;
}

// 609 2.2
// brute force
int PackingBallsDiv2::minPacks(int R, int G, int B) {
	int v[] = {R, G, B};
	sort(v, v+3);
	int ans = numeric_limits<int>::max();
	// try diff no of variety packages
	for(int i=0; i<=v[2]; i++){
		int t = 0;
		// add the number of remaining color ball normal set
		for(int j=0; j<3; j++){
			int a = max(0, v[j]-i);
			t += (a+2)/3;
		}
		ans = min(ans, t+i);
	}
	return ans;
}
// greedy
int PackingBallsDiv2::minPacks(int R, int G, int B) {
	int v[] = {R, G, B};
	sort(v, v+3);
	int ans = v[0];
	v[1] -= v[0];
	v[2] -= v[0];
	ans += v[1]/3 + v[2]/3;
	v[1] %= 3;
	v[2] %= 3;
	int t = v[1]+v[2];
	if(t==1 || t==2){
		ans += 1;
	}else if(t>2){
		ans += 2;
	}
	return ans;
}

// 403 2.2
// one other solution would be generate a vector with all the number of 4 and 7 before hand
int TheLuckyNumbers::count(int a, int b) {
	int f[] = {0, 4, 7};
	int ans = 0;
	int i = 0;
	while(1){
		int t = i;
		long long y = 1;
		long long x = 0;
		bool bo = true;
		while(t){
			if(f[t%3]==0){
				bo = false;
				break;
			}
			x += f[t%3]*y;
			y *= 10;
			t /= 3;
		}
		if(!bo || i==0){
			i++;
			continue;
		}
		if(x > b){
			break;
		}
		if(x>=a && x<=b){
			ans++;
		}
		i++;
	}
	return ans;
}
// recursion
// we should be careful if the desired number has zero
int re(long long t, int a, int b){
	if(t > b) return 0;
	return re(t*10+4, a, b) + re(t*10+7, a, b) + (t>=a&&t<=b);
}
int TheLuckyNumbers::count(int a, int b) {
	return re(0, a, b);
}
// use binary
int TheLuckyNumbers::count(int a, int b) {
	int ans = 0;
	for(int i=0; i<=9; i++){
		// find power set for i
		for(int j=0; j<1<<i; j++){
			long long x = 0;
			// check each digit and generate respective number
			for(int k=1, m=0; m<i; k<<=1, m++){
				x *= 10;
				if((k&j)==0) x += 4;
				else x += 7;
			}
			if(x>=a && x<=b){
				ans++;
			}
		}
	}
	return ans;
}

// 557 2.2
void dfs(vector<int>& v, vector<string>& l, int n){
	for(int i=0; i<l[n].size(); i++){
		if(v[i]==0 && l[n][i]=='Y'){
			v[i] = 1;
			dfs(v, l, i);
		}
	}
}
int IncubatorEasy::maxMagicalGirls(vector <string> love) {
	int ans = -1;
	for(int i=0; i<1<<love.size(); i++){
		vector<int> m(love.size());
		vector<int> v(love.size());
		for(int j=0; j<love.size(); j++){
			if(i&(1<<j)){
				m[j] = 1;
				dfs(v, love, j);
			}
		}
		int t = 0;
		for(int j=0; j<v.size(); j++){
			if(m[j]==1 && v[j]==0){
				t++;
			}
		}
		ans = max(ans, t);
	}
	return ans;
}

// 583 2.2
string IDNumberVerification::verify(string id, vector <string> regionCodes) {
	if(id.size()!=18){
		return "Invalid";
	}
	for(int i=0; i<17; i++){
		if(!isdigit(id[i])){
			return "Invalid";
		}
	}
	string r = id.substr(0, 6);
	bool b = false;
	for(int i=0; i<regionCodes.size(); i++){
		if(r == regionCodes[i]){
			b = true;
			break;
		}
	}
	if(!b){
		return "Invalid";
	}
	string yy = id.substr(6, 4);
	string mm = id.substr(10, 2);
	string dd = id.substr(12, 2);
	int y, m, d;
	stringstream(yy)>>y, stringstream(mm)>>m, stringstream(dd)>>d;
	bool lp = false;
	if((y%4==0 && y%100!=0) || y%400==0){
		lp = true;
	}
	if(!lp && m==2 && d>=29){
		return "Invalid";
	}
	if(lp && m==2 && d>29){
		return "Invalid";
	}
	if(d==31 &&m!=1&&m!=3&&m!=5&&m!=7&&m!=8&&m!=10&&m!=12){
		return "Invalid";
	}
	if(m>12||m<1||d<1||d>31){
		return "Invalid";
	}
	if(yy+mm+dd<"19000101" || yy+mm+dd>"20111231"){
		return "Invalid";
	}
	long long c = id[17]=='X'? 10: id[17]-'0';
	for(int i=0; i<=16; i++){
		c += (id[i]-'0')<<(17-i);
	}
	if(c%11!=1){
		return "Invalid";
	}
	if(id[16]=='0'&&id[15]=='0'&&id[14]=='0'){
		return "Invalid";
	}
	if((id[16]-'0')%2==0){
		return "Female";
	}
	return "Male";
}

// 606 2.2
int EllysNumberGuessing::getNumber(vector <int> guesses, vector <int> answers) {
	int n = guesses.size();
	long long c;
	bool boo = true;
	long long a = guesses[0]+answers[0];
	long long b = guesses[0]-answers[0];
	for(int i=1; i<n; i++){
		long long aa = guesses[i]+answers[i];
		long long bb = guesses[i]-answers[i];
		if(aa!=a && aa!=b && bb!=a && bb!=b){
			return -2;
		}
		if((aa==a&&bb!=b)||(aa==b&&bb!=a)){
			c = aa;
			boo = false;
		}
		if((bb==a&&aa!=b)||(bb==b&&aa!=a)){
			c = bb;
			boo = false;
		}
		a = aa;
		b = bb;
	}
	if(boo){
		if((a<1||a>1000000000)&&(b<1||b>1000000000)){
			return -2;
		}else if((a<1||a>1000000000) && b>=1 && b<=1000000000){
			return b;
		}else if((b<1||b>1000000000) && a>=1 && a<=1000000000){
			return a;
		}else{
			return -1;
		}
	}
	if(c<1 || c>1000000000){
		return -2;
	}
	return c;
}
// better
int EllysNumberGuessing::getNumber(vector <int> guesses, vector <int> answers) {
	long long ans;
	bool boo = true;
	for(int i=1; i<guesses.size(); i++){
		if(guesses[i]!=guesses[i-1] || answers[i]!=answers[i-1]){
			long long a = guesses[i-1]-answers[i-1];
			long long b = guesses[i-1]+answers[i-1];
			long long c = guesses[i]-answers[i];
			long long d = guesses[i]+answers[i];
			if(a!=c&&b!=d&&a!=d&&b!=c){
				return -2;
			}
			if(c==a||c==b){
				ans = c;
			}
			if(d==a||d==b){
				ans = d;
			}
			boo = false;
		}
	}
	if(boo){
		long long a = guesses[0]-answers[0];
		long long b = guesses[0]+answers[0];
		bool c = a<1||a>1000000000;
		bool d = b<1||b>1000000000;
		if(c && d){
			return -2;
		}
		if(!c && d){
			return a;
		}
		if(c && !d){
			return b;
		}
		return -1;
	}
	if(ans<1 || ans>1000000000){
		return -2;
	}
	return ans;
}
int EllysNumberGuessing::getNumber(vector <int> guesses, vector <int> answers) {
	int a[] = {guesses[0]-answers[0], guesses[0]+answers[0]};
	int ans = -2;
	for(int i=0; i<2; i++){
		bool b = a[i]>=1 && a[i]<=1000000000;
		for(int j=0; j<guesses.size(); j++){
			b = b && answers[j]==abs(guesses[j]-a[i]);
		}
		if(b){
			if(ans != -2){
				ans = -1;
			}else{
				ans = a[i];
			}
		}
	}
	return ans;
}

// 480 2.2
vector <string> InternetSecurity::determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold) {
	set<string> s(dangerous.begin(), dangerous.end());
	vector<int> v(address.size());
	while(1){
		bool bo = true;
		for(int i=0; i<address.size(); i++){
			if(v[i]==0){
				vector<string> w;
				stringstream ss(keyword[i]);
				string t;
				int a = 0;
				while(ss>>t){
					if(s.find(t)!=s.end()){
						a++;
					}
					w.push_back(t);
				}
				if(a>=threshold){
					v[i] = 1;
					for(int j=0; j<w.size(); j++){
						s.insert(w[j]);
					}
					bo = false;
				}
			}
		}
		if(bo){
			break;
		}
	}
	vector<string> ans;
	for(int i=0; i<address.size(); i++){
		if(v[i]){
			ans.push_back(address[i]);
		}
	}
	return ans;
}

// 390 2.2
int ConcatenateNumber::getSmallest(int number, int k) {
	long long d = 1;
	while(d<=number){
		d *= 10;
	}
	vector<int> f(k);
	long long a = number%k;
	int i = 1;
	while(1){
		if(a==0){
			return i;
		}
		if(f[a]){
			return -1;
		}
		f[a] = 1;
		a = ((a%k)*(d%k)+number%k)%k;
		i++;
	}
}
int ConcatenateNumber::getSmallest(int number, int k) {
	long long d = 1;
	while(d<=number){
		d *= 10;
	}
	long long a = number%k;
	for(int i=1; i<=k; i++){
		if(a==0){
			return i;
		}
		a = (a*d+number)%k;
	}
	return -1;
}

// 184 2.2
double BagOfHolding::oddsReachable(vector <int> sizes, int item) {
	vector<int> v(sizes.size());
	for(int i=0; i<v.size(); i++){
		v[i] = i;
	}
	int x = 0;
	int y = 0;
	do{
		bool bo = true;	
		for(int i=0; i<v.size(); i++){
			if(v[i] == item){
				for(int j=i+1; j<v.size(); j++){
					if(sizes[v[j]]>=sizes[v[i]]){
						bo = false;
						break;
					}
				}
				break;
			}
		}
		if(bo){
			x++;
		}
		y++;
	}while(next_permutation(v.begin(), v.end()));
	return x*1.0/y;
}

// 543 2.2
// 用XOR[i,j]表示区间[i,j]中所有整数的异或结果。根据异或的交换律以及以下两个性质：

// 相等的两个整数的异或为0
// 任意一个整数与0异或后不变
// 有：XOR[L,R]=XOR[0,L-1] xor XOR[0,R]。因为区间[0,L-1]属于区间[0,R]的子区间，相同的两个整数取异或后都变成0就只剩[L,R]区间了。因此可以将问题简化为对任意一个正整数N，求XOR[0,N]。

// 解决该问题的关键在于发现以下性质。

// 性质：如果正整数N满足N+1是4的倍数，那么XOR[0,N]等于0.

// 证明：如果N+1是4的倍数，那么区间[0,N]的整数个数是4的倍数。将该区间中的整数两两组成一对，每一对形如(2k,2k+1)，即每一个偶数都其相邻较大的那个奇数组成一对。对每对整数内部取异或，显然由于每一对整数的二进制形式只有最后一位不同，所以每一对异或之后的结果均为1。由于区间[0,N]的整数个数是4的倍数，那么这种整数对总共有偶数对，所以剩下偶数个1取异或，结果显然是0。

// 根据以上性质，对于任意一个正整数N，计算XOR[0,N]时，区间[0,N]中的前4k个数都可以忽略，其中k=(N+1)/4，只需要考虑最后不超过3个数即可(以下实现实际上是考虑不超过4个数)。

// two points about xor:
// 1. a xor a = 0
// 2. a xor 0 = a
// 3. xor(a to b) == xor(0 to a-1) ^ xor(0 to b)
long long f(long long a){
	if(a%4 == 0) return a;
	if(a%4 == 1) return 1;
	if(a%4 == 2) return a+1;
	return 0;
}
long long EllysXors::getXor(long long L, long long R) {
	return f(L-1)^f(R);
}

// 492 2.2
// fail in test case
int TimeTravellingGardener::determineUsage(vector <int> distance, vector <int> height) {
	int d = accumulate(distance.begin(), distance.end(), 0);
	vector<int> v;
	for(int i=0; i<=distance.size(); i++){
		int t = 0;
		for(int j=0; j<i; j++){
			t += distance[j];
		}
		v.push_back(t);
	}
	int ans = numeric_limits<int>::max();
	for(int i=0; i<=1000; i++){
		for(int j=0; j<=1000; j++){
			int a = j-i;
			int t = 0;
			for(int k=0; k<height.size(); k++){
				if((long long)(height[k]-i)*d==(long long)a*v[k]){
					t++;
				}
			}
			ans = min(ans, (int)height.size()-t);
		}
	}
	return ans;
}

// 246 2.2
string Conglutination::split(string conglutination, int expectation) {
	for(int i=1; i<conglutination.size(); i++){
		string a = conglutination.substr(0, i);
		string b = conglutination.substr(i);
		long long c, d;
		stringstream(a) >> c;
		stringstream(b) >> d;
		if(c+d == expectation){
			return a + "+" + b;
		}
	}
	return "";
}

// 414 2.2
// wrong in test case
int Embassy::visaApplication(vector <int> forms, int dayLength, int openTime) {
	int ans = numeric_limits<int>::max();
	for(int i=0; i<dayLength-openTime; i++){
		int a = i+openTime;
		int t = 0;
		for(int j=0; j<forms.size(); j++){
			t += forms[j];
			if(t%dayLength < i){
				t += i-t%dayLength;
			}
			if(t%dayLength > a){
				t += dayLength-t%dayLength+i;
			}
		}
		t -= max(0, i-forms[0]);
		ans = min(ans, t);
	}
	return ans;
}
// correct
int Embassy::visaApplication(vector <int> forms, int dayLength, int openTime) {
	int ans = numeric_limits<int>::max();
	for(int i=0; i<dayLength; i++){
		int t = i;
		for(int j=0; j<forms.size(); j++){
			t += forms[j];
			if(t%dayLength > openTime){
				t += dayLength - t%dayLength;
			}
		}
		ans = min(ans, t-i);
	}
	return ans;
}

// 565 2.2
void back(vector<int>& d, vector<int>& p, long long s, int t, int n, int& ans){
	if(n==d.size()){
		ans = min(ans, t);
		return;
	}
	if(d[n]<=s){
		back(d, p, s, t, n+1, ans);
	}	
	back(d, p, s+d[n], t+p[n], n+1, ans);
}
int MonstersValley2::minimumPrice(vector <int> dread, vector <int> price) {
	int ans = numeric_limits<int>::max();
	back(dread, price, 0, 0, 0, ans);
	return ans;
}

//361 2.2
int WhiteHats::whiteNumber(vector <int> count) {
	vector<int> v(count.size()+1);
	for(int i=0; i<count.size(); i++){
		v[count[i]]++;
	}
	if(v[0]==count.size()){
		return 0;
	}
	for(int i=1; i<=count.size(); i++){
		if(v[i-1]==i && v[i]==count.size()-i){
			return i;
		}
	}
	return -1;
}

// 383 2.2
// only profitable can be consider
// wrong
int Planks::makeSimilar(vector <int> lengths, int costPerCut, int woodValue) {
	int a = accumulate(lengths.begin(), lengths.end(), 0);
	sort(lengths.begin(), lengths.end());
	int ans = 0;
	for(int i=1; i<=a; i++){
		int b = 0;
		for(int j=0; j<lengths.size(); j++){
			int c = b + ((long long)i*woodValue*(lengths[j]/i))-((lengths[j]-1)/i)*costPerCut;
			if(c < b) break;
			b = c;
		}
		ans = max(ans, b);
	}
	return ans;
}
// correct
int Planks::makeSimilar(vector <int> lengths, int costPerCut, int woodValue) {
	int a = *max_element(lengths.begin(), lengths.end());
	int ans = 0;
	for(int i=1; i<=a; i++){
		int b = 0;
		for(int j=0; j<lengths.size(); j++){
			int c = lengths[j]/i*woodValue*i;
			int d = (lengths[j]-1)/i*costPerCut;
			if(c>=d){
				b += c-d;
			}
		}
		ans = max(ans, b);
	}
	return ans;
}

// 386 2.2
// candidate key is the super key that you cannot find other super key to be its subset
// - a is subset of b: (a|b)==b , (a&b)==a
// - i^(1<<j) means toggle the ith bits of number i, can use it to check subset
// - in generating power set, you can also use (i>>j)&1 for the reverse instead of i&(1<<j)
vector <int> CandidateKeys::getKeys(vector <string> table) {
	vector<int> v(1<<table[0].size(), 1);
	int a = -1;
	int b = numeric_limits<int>::max();
	for(int i=1; i<1<<table[0].size(); i++){
		if(v[i]==0){
			continue;
		}
		set<string> s;
		bool bo = true;
		for(int j=0; j<table.size(); j++){
			string t;
			for(int k=0; k<table[j].size(); k++){
				if(i&(1<<k)){
					t += table[j][k];
				}
			}
			if(!s.insert(t).second){
				bo = false;
				break;
			}
		}
		if(bo){
			int n = s.begin()->size();
			a = max(a, n);
			b = min(b, n);
			for(int j=i+1; j<1<<table[0].size(); j++){
				// if i is subset of j
				if((i&j) == i){
					v[j] = 0;
				}
			}
		}
	}
	if(a < b){
		return vector<int>();
	}
	vector<int> ans(2);
	ans[0] = b;
	ans[1] = a;
	return ans;
}
// alternative
vector <int> CandidateKeys::getKeys(vector <string> table) {
	set<int> s;
	vector<int> v(2);
	v[0] = (1<<table[0].size())+1;
	v[1] = -1;
	for(int i=1; i<1<<table[0].size(); i++){
		bool bo = true;
		for(set<int>::iterator j=s.begin(); j!=s.end(); j++){
			if((*j&i) == *j){
				bo = false;
				break;
			}
		}
		if(!bo){
			continue;
		}
		bool boo = true;
		set<string> se;
		for(int j=0; j<table.size(); j++){
			string t;
			for(int k=0; k<table[j].size(); k++){
				if(1&(i>>k)){
					t += table[j][k];
				}
			}
			if(!se.insert(t).second){
				boo = false;
				break;
			}
		}
		if(boo){
			s.insert(i);
			v[0] = min(v[0], (int)se.begin()->size());
			v[1] = max(v[1], (int)se.begin()->size());
		}
	}
	if(v[1] == -1){
		return vector<int>();
	}
	return v;
}
// somehow 1 test case wrong, copy from egor
vector <int> CandidateKeys::getKeys(vector <string> table) {
	vector<int> v(1<<table[0].size());
	int a = (1<<table[0].size())+1;
	int b = -1;
	for(int i=1; i<1<<table[0].size(); i++){
		bool bo = true;
		for(int j=0; j<table.size(); j++){
			if(1&(i>>j) && v[i^(1<<j)]){
				bo = false;
				v[i] = 1;
				break;
			}
		}
		if(!bo){
			continue;
		}
		bool boo = true;
		set<string> s;
		for(int j=0; j<table.size(); j++){
			string t;
			for(int k=0; k<table[j].size(); k++){
				if(1&(i>>k)){
					t += table[j][k];
				}
			}
			if(!s.insert(t).second){
				boo = false;
				break;
			}
		}
		if(boo){
			v[i] = 1;
			a = min(a, (int)s.begin()->size());
			b = max(b, (int)s.begin()->size());
		}
	}
	if(b == -1){
		return vector<int>();
	}
	vector<int> ans(2);
	ans[0] = a;
	ans[1] = b;
	return ans;
}

// 580 2.2
int EelAndRabbit::getmax(vector <int> l, vector <int> t) {
	int n = l.size();
	vector<int> a(n*2);
	vector< pair<int, int> > v(n);
	for(int i=0; i<n; i++){
		v[i] = make_pair(t[i], t[i]+l[i]);
		a[i*2] = t[i];
		a[i*2+1] = t[i]+l[i];
	}
	int ans = 0;
	for(int i=0; i<a.size(); i++){
		for(int j=i+1; j<a.size(); j++){
			vector<int> r(n);
			int t = 0;
			for(int k=0; k<v.size(); k++){
				if(v[k].first<=a[i] && v[k].second>=a[i] && r[k]==0){
					t++;
					r[k] = 1;
				}
				if(v[k].first<=a[j] && v[k].second>=a[j] && r[k]==0){
					t++;
					r[k] = 1;
				}
			}
			ans = max(ans, t);
		}
	}
	return ans;
}

// 284 2.2
int Measures::beatsPerM(vector <int> loudness) {
	for(int i=2; i<=10; i++){
		for(int j=0; j<i; j++){
			int t = 0;
			int m = 0;
			for(int k=j; k<loudness.size(); k+=i){
				bool pass = true;
				int c = 1;
				for(int l=k+1; l<k+i && l<loudness.size(); l++){
					c++;
					pass = pass && (loudness[l]<=loudness[k]);
				}
				if(c == i){
					t++;
					if(pass){
						m++;
					}
				}	
			}
			if(t>0 && m*5>=4*t){
				return i;
			}
		}
	}
	return -1;
}

// 512 2.2
// wrong direction
int trans(char c){
	if(isalpha(c)){
		if(isupper(c)){
			return c-'A'+10;
		}else{
			return c-'a'+36;
		}
	}
	return c-'0';
}
int MysteriousRestaurant::maxDays(vector <string> prices, int budget) {
	int n = prices.size();
	int m = prices[0].size();
	vector< vector<int> > v(7, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			v[i%7][j] += trans(prices[i][j]);
		}
	}
	vector<int> p(7);
	for(int i=0; i<7; i++){
		p[i] = min_element(v[i].begin(), v[i].end()) - v[i].begin();
	}
	int d = 0;
	for(int i=0; i<n; i++){
		budget -= trans(prices[i][p[i%7]]);
		if(budget < 0){
			break;
		}
		d++;
	}
	return d;
}
// correct
int trans(char c){
	if(isalpha(c)){
		if(isupper(c)){
			return c-'A'+10;
		}else{
			return c-'a'+36;
		}
	}
	return c-'0';
}
int MysteriousRestaurant::maxDays(vector <string> prices, int budget) {
	int n = prices.size();
	int m = prices[0].size();
	int ans = 0;
	for(int u=1; u<=n; u++){
		vector< vector<int> > v(7, vector<int>(m));
		for(int i=0; i<u; i++){
			for(int j=0; j<m; j++){
				v[i%7][j] += trans(prices[i][j]);
			}
		}
		vector<int> p(7);
		for(int i=0; i<7; i++){
			p[i] = min_element(v[i].begin(), v[i].end()) - v[i].begin();
		}
		int d = 0;
		int t = budget;
		for(int i=0; i<u; i++){
			t -= trans(prices[i][p[i%7]]);
			if(t< 0){
				break;
			}
			d++;
		}
		ans = max(ans, d);
	}
	return ans;
}
// seems better
// other approach can be binary search (not this one)
int trans(char c){
	if(isalpha(c)){
		if(isupper(c)){
			return c-'A'+10;
		}else{
			return c-'a'+36;
		}
	}
	return c-'0';
}
int MysteriousRestaurant::maxDays(vector <string> prices, int budget) {
	int n = prices.size();
	int m = prices[0].size();
	for(int d=n; d>=1; d--){
		int b = 0;
		for(int i=0; i<7; i++){
			int t = numeric_limits<int>::max();
			for(int j=0; j<m; j++){
				int c = 0;
				for(int k=i; k<d; k+=7){
					c += trans(prices[k][j]);
				}
				t = min(t, c);
			}
			b += t;
		}
		if(b <= budget){
			return d;
		}
	}
	return 0;
}

// 631 2.2
// editorial suggests that all cat try to be in left most position
// my version just check if their number exceed their range
string CatsOnTheLineDiv2::getAnswer(vector <int> position, vector <int> count, int time) {
	int n = position.size();
	for(int i=0; i<n; i++){
		if(count[i] > time*2+1){
			return "Impossible";
		}
	}
	vector< pair< pair<int, int>, int > > v(n);
	for(int i=0; i<n; i++){
		v[i] = make_pair(make_pair(position[i]-time, position[i]+time), count[i]);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		int r = v[i].first.second;
		int t = v[i].second;
		for(int j=i+1; j<v.size(); j++){
			if(v[j].first.first <= v[i].first.second){
				r = max(r, v[j].first.second);
				t += v[j].second;
			}
		}
		if(r-v[i].first.first+1 < t){
			return "Impossible";
		}
	}
	return "Possible";
}

// 165 2.2
// problem find maximum point
int ParallelSpeedup::numProcessors(int k, int overhead) {
	long long a = numeric_limits<long long>::max();
	int b = -1;
	for(int i=1; i<=k; i++){
		long long t = (k+i-1)/i + (long long)overhead*i*(i-1)/2;
		if(t < a){
			a = t;
			b = i;
		}
	}
	return b;
}
// seems better
int ParallelSpeedup::numProcessors(int k, int overhead) {
	int i = 1;
	long long a = numeric_limits<long long>::max();
	int b = -1;
	while(1){
		long long t = (k+i-1)/i + (long long)overhead*i*(i-1)/2;
		if(t > k){
			break;
		}
		if(t < a){
			a = t;
			b = i;
		}
		i++;
	}
	return b;
}

// 588 2.2
// just backtrack, tle
void back(vector<int>& d, vector<int>& t, int tu, vector<int>& r, long long a, int n, int m, int& ans){
	if(a > tu){
		ans = max(ans, m-1);
		return ;
	}
	if(m==d.size()){
		ans = max(ans, m);
		return ;
	}
	for(int i=0; i<d.size(); i++){
		if(r[i]==0){
			r[i] = 1;
			back(d, t, tu, r, a+d[i]+abs(t[n]-t[i]), i, m+1, ans);
			r[i] = 0;
		}
	}
}
int GUMIAndSongsDiv2::maxSongs(vector <int> duration, vector <int> tone, int T) {
	int ans = 0;
	vector<int> r(duration.size());
	for(int i=0; i<duration.size(); i++){
		r[i] = 1;
		back(duration, tone, T, r, duration[i], i, 1, ans);
		r[i] = 0;
	}
	return ans;
}
// power set, tle
int GUMIAndSongsDiv2::maxSongs(vector <int> duration, vector <int> tone, int T) {
	int n = duration.size();
	int ans = 0;
	for(int i=1; i<1<<n; i++){
		vector< pair<int, int> > v;
		for(int j=0; j<n; j++){
			if((i>>j)&1){
				v.push_back(make_pair(tone[j], duration[j]));
			}
		}
		sort(v.begin(), v.end());
		long long t = 0;
		for(int j=0; j<v.size(); j++){
			t += v[j].second;
			if(j!=0){
				t += abs(v[j].first - v[j-1].first);
			}
		}
		if(t <= T){
			ans = max(ans, (int)v.size());
		}
	}
	return ans;
}
// correct, power set improved
// noticed that we don't need to sort the vector to find the tone difference
// the range of min and max is equal to those difference
int GUMIAndSongsDiv2::maxSongs(vector <int> duration, vector <int> tone, int T) {
	int n = duration.size();
	int ans = 0;
	for(int i=1; i<1<<n; i++){
		int t = 0;
		int a = numeric_limits<int>::max();
		int b = -1;
		int c = 0;
		for(int j=0; j<n; j++){
			if((i>>j)&1){
				a = min(a, tone[j]);
				b = max(b, tone[j]);
				t += duration[j];
				c++;
			}
		}
		if((long long)t+b-a <= T){
			ans = max(ans, c);
		}
	}
	return ans;
}

// 201 2.2
vector <int> ElevatorLimit::getRange(vector <int> enter, vector <int> exit, int physicalLimit) {
	int n = enter.size();
	vector<int> v(2);
	v[0] = physicalLimit+1;
	v[1] = -1;
	for(int i=0; i<=physicalLimit; i++){
		int t = i;
		bool bo = true;
		for(int j=0; j<n; j++){
			t -= exit[j];
			if(t<0){
				bo = false;
				break;
			}
			t += enter[j];
			if(t>physicalLimit){
				bo = false;
				break;
			}
		}
		if(bo){
			v[0] = min(v[0], i);
			v[1] = max(v[1], i);
		}	
	}
	if(v[1] == -1){
		return vector<int>();
	}
	return v;
}

// 610 2.2
// almost correct, but wrong
int TheMatrix::MaxArea(vector <string> board) {
	int r = board.size();
	int c = board[0].size();
	int ans = 0;
	for(int i=0; i<c; i++){
		for(int j=i; j<c; j++){
			vector<int> v(r);
			for(int k=0; k<r; k++){
				bool bo = true;
				for(int m=i+1; m<c; m++){
					bo = bo && (board[k][m]!=board[k][m-1]);
				}
				if(bo){
					v[k] = board[k][i]-'0';
				}else{
					v[k] = -1;
				}
			}
			int t = 0;
			int u = 0;
			for(int k=0; k<v.size(); k++){
				if(v[k]==-1){
					t = 0;
				}else if(t>0 && (v[k-1]!=v[k])){
					t++;
				}else{
					t = 1;
				}
				u = max(u, t);
			}
			ans = max(ans, u*(j-i+1));
		}
	}
	return ans;
}

// 473 2.2
string SequenceOfCommands::whatHappens(vector <string> commands) {
	int x = 0, y = 0, d = 0;
	for(int i=0; i<commands.size(); i++){
		for(int j=0; j<commands[i].size(); j++){
			if(commands[i][j] == 'L'){
				d = (d+3)%4;
			}else if(commands[i][j] == 'R'){
				d = (d+1)%4;
			}else{
				if(d==0){
					y++;
				}else if(d==1){
					x++;
				}else if(d==2){
					y--;
				}else if(d==3){
					x--;
				}
			}
		}
	}
	if(x == 0 && y == 0){
		return "bounded";
	}
	if(d == 0){
		return "unbounded";
	}
	return "bounded";
}
// little shorter
string SequenceOfCommands::whatHappens(vector <string> commands) {
	int x = 0, y = 0, d = 0;
	for(int i=0; i<commands.size(); i++){
		for(int j=0; j<commands[i].size(); j++){
			if(commands[i][j] == 'L'){
				d = (d+3)%4;
			}else if(commands[i][j] == 'R'){
				d = (d+1)%4;
			}else{
				if(d==0){
					y++;
				}else if(d==1){
					x++;
				}else if(d==2){
					y--;
				}else if(d==3){
					x--;
				}
			}
		}
	}
	if((x!=0 || y!=0) && d == 0){
		return "unbounded";
	}
	return "bounded";
}
// alternative
string SequenceOfCommands::whatHappens(vector <string> commands) {
	int dy[] = {1, 0, -1, 0};
	int dx[] = {0, 1, 0, -1};
	int x = 0, y = 0, d = 0;
	for(int i=0; i<commands.size(); i++){
		for(int j=0; j<commands[i].size(); j++){
			if(commands[i][j] == 'L'){
				d = (d+3)%4;
			}else if(commands[i][j] == 'R'){
				d = (d+1)%4;
			}else{
				x += dx[d];
				y += dy[d];
			}
		}
	}
	if((x!=0 || y!=0) && d == 0){
		return "unbounded";
	}
	return "bounded";
}

// 206 2.2
string OmahaLow::low(string sharedCards, string playersCards) {
	set<char> s, p;
	for(int i=0; i<sharedCards.size(); i++){
		if(sharedCards[i]<='8'){
			s.insert(sharedCards[i]);
		}
	}
	for(int j=0; j<playersCards.size(); j++){
		if(playersCards[j]<='8'){
			p.insert(playersCards[j]);
		}
	}
	if(s.size()<3 || p.size()<2){
		return "";
	}
	string vp(p.begin(), p.end()), vs(s.begin(), s.end());
	vector< string > u;
	for(int i=0; i<vs.size(); i++){
		for(int j=i+1; j<vs.size(); j++){
			for(int k=j+1; k<vs.size(); k++){
				for(int m=0; m<vp.size(); m++){
					for(int n=m+1; n<vp.size(); n++){
						set<char> si;
						si.insert(vs[i]);
						si.insert(vs[j]);
						si.insert(vs[k]);
						si.insert(vp[m]);
						si.insert(vp[n]);
						if(si.size()!=5) continue;
						u.push_back(string(si.rbegin(), si.rend()));
					}
				}
			}
		}
	}
	if(u.empty()) return "";
	string r = u[0];
	for(int i=1; i<u.size(); i++){
		for(int j=0, k=1; k<5; k++, j++){
			if(r[j]!=u[i][j] || r[k]!=u[i][k]){
				if(u[i][j]<r[j] || u[i][k]<r[k]){
					r = u[i];
				}
			}
		}
	}
	return r;
}
// code faster
// use next_permutation and substr to choose combination from string (5/8)
// but will generate many duplicates, so although handy, but slower
string OmahaLow::low(string sharedCards, string playersCards) {
	sort(sharedCards.begin(), sharedCards.end());
	sort(playersCards.begin(), playersCards.end());
	string ans;
	do{
		do{
			string t = sharedCards.substr(0, 3) + playersCards.substr(0, 2);
			set<char> s(t.begin(), t.end());
			if(s.size() != 5) continue;
			string u(s.rbegin(), s.rend());
			if(u[0] > '8') continue;
			if(ans=="" || u<ans) ans = u;
		}while(next_permutation(playersCards.begin(), playersCards.end()));
	}while(next_permutation(sharedCards.begin(), sharedCards.end()));
	return ans;
}

// 603 2.2
int SplitIntoPairs::makepairs(vector <int> A, int X) {
	vector<int> a, b;
	for(int i=0; i<A.size(); i++){
		if(A[i]>=0){
			a.push_back(A[i]);
		}else{
			b.push_back(A[i]);
		}
	}
	if(a.size()%2==0){
		return a.size()/2+b.size()/2;
	}
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			if((long long)a[i]*b[j]>=X){
				return a.size()/2+b.size()/2+1;
			}
		}
	}
	return a.size()/2+b.size()/2;
}
// better
int SplitIntoPairs::makepairs(vector <int> A, int X) {
	vector<int> a, b;
	for(int i=0; i<A.size(); i++){
		if(A[i]>=0){
			a.push_back(A[i]);
		}else{
			b.push_back(A[i]);
		}
	}
	if(a.size()%2==0){
		return a.size()/2+b.size()/2;
	}
	int c = *min_element(a.begin(), a.end());
	int d = *max_element(b.begin(), b.end());
	if((long long)c*d >= X){
		return a.size()/2+b.size()/2+1;
	}
	return a.size()/2+b.size()/2;
}
// better
int SplitIntoPairs::makepairs(vector <int> A, int X) {
	vector<int> a, b;
	for(int i=0; i<A.size(); i++){
		if(A[i]>=0){
			a.push_back(A[i]);
		}else{
			b.push_back(A[i]);
		}
	}
	if(a.size()%2==0){
		return A.size()/2;
	}
	int c = *min_element(a.begin(), a.end());
	int d = *max_element(b.begin(), b.end());
	if((long long)c*d >= X){
		return A.size()/2;
	}
	return A.size()/2-1;
}

// 378 2.2
int TrueStatements::numberTrue(vector <int> statements) {
	vector<int> r(51);
	bool bo = false;
	for(int i=0; i<statements.size(); i++){
		if(statements[i] == 0) bo = true;
		r[statements[i]]++;
	}
	int ans = 0;
	for(int i=0; i<r.size(); i++){
		if(r[i]==i){
			ans = i;
		}
	}
	if(ans==0 && bo){
		return -1;
	}
	return ans;
}
// better
int TrueStatements::numberTrue(vector <int> statements) {
	for(int i=statements.size(); i>=0; i--){
		if(count(statements.begin(), statements.end(), i) == i){
			return i;
		}
	}
	return -1;
}

// 590 2.2
void dfs(vector<string>& b, vector< pair<int, int> >& v, vector< vector<int> >& r, int x, int y, int dx[], int dy[]){
	r[x][y] = 1;
	v[v.size()-1].first++;
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0 && nx<b.size() && ny>=0 && ny<b.size()){
			if(r[nx][ny]==0 && b[nx][ny]=='o'){
				dfs(b, v, r, nx, ny, dx, dy);
			}
			if(b[nx][ny]=='.'){
				v[v.size()-1].second++;
			}
		}
	}
}
int FoxAndGo::maxKill(vector <string> board) {
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	int n = board.size();
	int ans = -1;
	for(int k=0; k<n; k++){
		for(int m=0; m<n; m++){
			if(board[k][m]=='.'){
				vector<string> b = board;
				b[k][m] = 'x';
				vector< vector<int> > r(n, vector<int>(n));
				vector< pair<int, int> > v;
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(b[i][j]=='o' && r[i][j]==0){
							v.push_back(make_pair(0 ,0));
							dfs(b, v, r, i, j, dx, dy);
						}
					}
				}
				int t = 0;
				for(int i=0; i<v.size(); i++){
					if(v[i].second==0){
						t += v[i].first;
					}
				}
				ans = max(ans, t);
			}
		}
	}
	return ans;
}

// 207 2.2
bool com(const pair<long long, string>& a, const pair<long long, string>& b){
	if(a.first > b.first){
		return true;
	}
	if(a.first == b.first && a.second < b.second){
		return true;
	}
	return false;
}
vector <string> RegularSeason::finalStandings(vector <string> teams, int rounds) {
	int n = teams.size();
	vector< pair<long long, string> > v(n, make_pair(0, ""));
	for(int i=0; i<n; i++){
		stringstream ss(teams[i]);
		for(int j=0; j<n+1; j++){
			if(j==0){
				ss >> v[i].second;
			}else{
				int t;
				ss >> t;
				if(j-1 != i){
					v[i].first += t*rounds;
					v[j-1].first += (100-t)*rounds;
				}
			}
		}
	}
	sort(v.begin(), v.end(), com);
	vector<string> a(n, "");
	for(int i=0; i<n; i++){
		a[i] += v[i].second + " ";
		stringstream ss;
		ss << int(v[i].first*1.0/100+0.5);
		a[i] += ss.str();
	}
	return a;
}

// 229 2.2
string Cafeteria::latestTime(vector <int> offset, vector <int> walkingTime, vector <int> drivingTime) {
	int n = offset.size();
	int a = -1;
	for(int i=870; i>=500; i--){
		for(int j=0; j<n; j++){
			int t = i;
			t += walkingTime[j];
			if((t%60)%10 == offset[j]){
				t += drivingTime[j];
				if(t <= 870){
					a = max(a, i);
				}
			}
		}
	}
	int m = a%60;
	int h = a/60;
	if(h==13){
		h = 1;
	}else if(h==14){
		h = 2;
	}
	stringstream ss;
	ss << setfill('0') << setw(2) << h << ':' << setfill('0') << setw(2) << m;
	return ss.str();
}

// 162 2.2
void back(double w, double h, int dw, int dh, int& ans, int n){
	if(w<=dw && h<=dh){
		ans = min(ans, n);
		return;
	}
	if(n == 8){
		return;
	}
	back(w*1.0, h*1.0/2, dw, dh, ans, n+1);
	back(w*1.0/2, h*1.0, dw, dh, ans, n+1);
	back(h*1.0, w*1.0/2, dw, dh, ans, n+1);
	back(h*1.0/2, w*1.0, dw, dh, ans, n+1);
}
int PaperFold::numFolds(vector <int> paper, vector <int> box) {
	int ans = 10;
	back(paper[0], paper[1], box[0], box[1], ans, 0);
	back(paper[1], paper[0], box[0], box[1], ans, 0);
	if(ans == 10){
		ans = -1;
	}
	return ans;
}

// 526 2.2
bool com(pair<int, int>& a, pair<int, int>& b){
	return a.second < b.second;
}
int DucksAlignment::minimumTime(vector <string> grid) {
	int n = grid.size();
	int m = grid[0].size();
	vector< pair<int, int> > v;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j] == 'o'){
				v.push_back(make_pair(i, j));
			}
		}
	}
	int ans = numeric_limits<int>::max();
	sort(v.begin(), v.end(), com);
	for(int i=0; i<n; i++){
		for(int j=0; j<m-v.size()+1; j++){
			int t = 0;
			for(int k=0; k<v.size(); k++){
				t += abs(v[k].first - i) + abs(v[k].second - (j+k));
			}
			ans = min(ans, t);
		}
	}
	sort(v.begin(), v.end());
	for(int i=0; i<m; i++){
		for(int j=0; j<n-v.size()+1; j++){
			int t = 0;
			for(int k=0; k<v.size(); k++){
				t += abs(v[k].second - i) + abs(v[k].first - (j+k));
			}
			ans = min(ans, t);
		}
	}
	return ans;
}
// seems better
int DucksAlignment::minimumTime(vector <string> grid) {
	int n = grid.size();
	int m = grid[0].size();
	vector<int> r, c;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j] == 'o'){
				r.push_back(i);
				c.push_back(j);
			}
		}
	}
	int s = r.size();
	int ans = numeric_limits<int>::max();
	sort(r.begin(), r.end());
	sort(c.begin(), c.end());
	for(int i=0; i<n; i++){
		for(int j=0; j<m-s+1; j++){
			int t = 0;
			for(int k=0; k<s; k++){
				t += abs(c[k] - (j+k));
			}
			for(int k=0; k<s; k++){
				t += abs(r[k] - i);
			}
			ans = min(ans, t);
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n-r.size()+1; j++){
			int t = 0;
			for(int k=0; k<s; k++){
				t += abs(r[k] - (j+k));
			}
			for(int k=0; k<s; k++){
				t += abs(c[k] - i);
			}
			ans = min(ans, t);
		}
	}
	return ans;
}

// 232 2.2
vector <string> WordFind::findWords(vector <string> grid, vector <string> wordList) {
	vector<string> a(wordList.size());
	int n = grid.size();
	int m = grid[0].size();
	for(int i=0; i<wordList.size(); i++){
		int o = wordList[i].size();
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				bool boo = false;
				if(j<n-o+1){
					bool bo = true;
					for(int p=0; p<o; p++){
						if(grid[j+p][k]!=wordList[i][p]){
							bo = false;
							break;
						}
					}
					if(bo){
						boo = true; 
					}
				}
				if(k<m-o+1){
					bool bo = true;
					for(int p=0; p<o; p++){
						if(grid[j][k+p]!=wordList[i][p]){
							bo = false;
							break;
						}
					}
					if(bo){
						boo = true; 
					}
				}
				if(k<m-o+1 && j<n-o+1){
					bool bo = true;
					for(int p=0; p<o; p++){
						if(grid[j+p][k+p]!=wordList[i][p]){
							bo = false;
							break;
						}
					}
					if(bo){
						boo = true; 
					}
				}
				if(boo){
					stringstream ss;
					ss << j << " " << k;
					a[i] = ss.str();
					goto next;
				}
			}
		}
	next:;
	}
	return a;
}
// better
vector <string> WordFind::findWords(vector <string> grid, vector <string> wordList) {
	vector<string> a(wordList.size());
	int n = grid.size();
	int m = grid[0].size();
	for(int i=0; i<wordList.size(); i++){
		int o = wordList[i].size();
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				int dx[] = {1, 0, 1};
				int dy[] = {0, 1, 1};
				bool bo = false;
				for(int p=0; p<3; p++){
					int c = 0;
					for(int q=j, r=k; q<n && r<m && grid[q][r]==wordList[i][c]; c++, q+=dx[p], r+=dy[p]);
					if(c == o){
						bo = true;
						break;
					}
				}
				if(bo){
					stringstream ss;
					ss << j << " " << k;
					a[i] = ss.str();
					goto next;
				}
			}
		}
	next:;
	}
	return a;
}

// 212 2.2
vector <int> WinningRecord::getBestAndWorst(string games) {
	int n = games.size();
	vector<double> v(n);
	int t = 0;
	for(int i=0; i<n; i++){
		if(games[i] == 'W'){
			t++;
		}
		v[i] = t*1.0/(i+1);
	}
	double a = numeric_limits<double>::max();
	double b = -1;
	int c = 0;
	int d = 0;
	for(int i=2; i<n; i++){
		if(v[i] <= a){
			a = v[i];
			c = i+1;
		}
		if(v[i] >= b){
			b = v[i];
			d = i+1;
		}
	}
	vector<int> ans(2);
	ans[0] = d;
	ans[1] = c;
	return ans;
}

// 331 2.2
// how many rows need for all cols to Y
// "YNN"
// "YNY"
// "YNY"
// "NYY"
// "NYY"
// "NYN"
int CarolsSinging::choose(vector <string> lyrics) {
	int n = lyrics.size();
	int m = lyrics[0].size();
	int ans = numeric_limits<int>::max();
	for(int i=1; i<1<<m; i++){
		bool bo = true;
		for(int j=0; j<n; j++){
			bool bb = false;
			for(int k=0; k<m; k++){
				if(((1<<k)&i) && lyrics[j][k]=='Y'){
					bb = true;
					break;
				}
			}
			if(!bb){
				bo = false;
				break;
			}
		}
		if(bo){
			ans = min(ans, __builtin_popcount(i));
		}
	}
	return ans;
}
// alternative
// in each loop, it remove the right most bit by bitwise and
// example:
// n    n-1  n&(n-1)    n        n-1      n&(n-1)
// 1011 1010 1010 1111110011 1111110010 1111110010
// 1010 1009 1008 1111110010 1111110001 1111110000
// 1008 1007 992  1111110000 1111101111 1111100000
// 992  991  960  1111100000 1111011111 1111000000
// 960  959  896  1111000000 1110111111 1110000000
// 896  895  768  1110000000 1101111111 1100000000
// 768  767  512  1100000000 1011111111 1000000000
// 512  511  0    1000000000 0111111111 0000000000
// two other function can do it
// int h(int n) {
// 	int ret = 0;
// 	while ( n != 0 ) {
// 		ret += n % 2;
// 		n  /= 2;
// 	}
// 	return ret;
// }
// int h(int n) {
// 	int ret = 0;
// 	while ( n != 0 ) {
// 		ret += (n & 1);
// 		n  >>= 1;
// 	}
// 	return ret;
// }
// int cbit(int arg){
// 	int ret=0;
// 	while(arg){
// 		if(arg & 1) ret++;
// 			arg >>=1;
// 		}
// 	return ret;
// }
int CarolsSinging::choose(vector <string> lyrics) {
	int n = lyrics.size();
	int m = lyrics[0].size();
	int ans = numeric_limits<int>::max();
	for(int i=1; i<1<<m; i++){
		bool bo = true;
		for(int j=0; j<n; j++){
			bool bb = false;
			for(int k=0; k<m; k++){
				if(((1<<k)&i) && lyrics[j][k]=='Y'){
					bb = true;
					break;
				}
			}
			if(!bb){
				bo = false;
				break;
			}
		}
		if(bo){
			int t = i;
			int c = 0;
			while(t > 0){
				c++;
				t &= t-1;
			}
			ans = min(ans, c);
		}
	}
	return ans;
}

// 489 2.2
int BuyingFlowers::buy(vector <int> roses, vector <int> lilies) {
	// this is the pre generated result for different rectangle
	int match[] = {-1,0,10 .. 98,40};
	int n = roses.size();
	int ans = 40000;
	for(int i=1; i<1<<n; i++){
		int r = 0;
		int l = 0;
		for(int j=0; j<n; j++){
			if((1<<j)&i){
				r += roses[j];
				l += lilies[j];
			}
		}
		if(abs(r-l)<=1){
			ans = min(ans, match[r+l]);
		}
	}
	if(ans == 40000){
		ans = -1;
	}
	return ans;
}
// generate online
int BuyingFlowers::buy(vector <int> roses, vector <int> lilies) {
	int n = roses.size();
	int ans = 40000;
	for(int i=1; i<1<<n; i++){
		int r = 0;
		int l = 0;
		for(int j=0; j<n; j++){
			if((1<<j)&i){
				r += roses[j];
				l += lilies[j];
			}
		}
		if(abs(r-l)<=1){
			int m = sqrt(r*1.0+l);
			for(int j=1; j<=m; j++){
				if((l+r)%j==0){
					ans = min(ans, abs(j-(l+r)/j));
				}
			}
		}
	}
	if(ans == 40000){
		ans = -1;
	}
	return ans;
}

// 344 2.2
// you can also use backtrack to gen password, but this is better
string SimpleRotationDecoder::decode(string cipherText) {
	for(int i='a'; i<='z'; i++){
		for(int j='a'; j<='z'; j++){
			for(int k='a'; k<='z'; k++){
				string p;
				p += i, p+=j, p+=k;
				string o;
				for(int m=0; m<cipherText.size(); m++){
					int a = isalpha(cipherText[m])? cipherText[m]-'a'+1: 0;
					int b = p[m%3]-'a'+1;
					int c = (a+27-b)%27;
					o += (c==0)? ' ': 'a'+c-1;
				}
				if(o[0]==' ' || o[o.size()-1]==' '){
					continue;
				}
				bool bo = true;
				for(int m=1; m<o.size(); m++){
					if(o[m]==' ' && o[m-1]==' '){
						bo = false;
						break;
					}
				}
				if(!bo) continue;
				stringstream ss(o);
				string t;
				while(ss >> t){
					if(t.size()<2 || t.size()>8){
						bo = false;
						break;
					}
					bool v = false;
					for(int m=0; m<t.size(); m++){
						if(t[m]=='a'||t[m]=='e'||t[m]=='i'||t[m]=='o'||t[m]=='u'){
							v = true;
							break;
						}
					}
					if(!v){
						bo = false;
						break;
					}
				}
				if(!bo) continue;
				return o;
			}
		}
	}
	return "";
}

// 274 2.2
string PalindromeMaker::make(string baseString) {
	int n = baseString.size();
	vector<int> v('Z'+1);
	for(int i=0; i<n; i++){
		v[baseString[i]]++;
	}
	int o = 0;
	for(int i='A'; i<='Z'; i++){
		if(v[i]%2 != 0){
			o++;
		}
	}
	if(o > 1){
		return "";
	}
	string a;
	for(int i='A'; i<='Z'; i++){
		for(int j=0; j<v[i]/2; j++){
			a += (char)i;
		}
	}
	string b;
	for(int i='A'; i<='Z'; i++){
		if(v[i]%2 != 0){
			b += (char)i;
		}
	}
	string t = a;
	reverse(t.begin(), t.end());
	a += b + t;
	return a;
}

// 439 2.2
// eg. 13 = 2^3 + 2^2 + 2^1
// initial .............
// after   ...
//          ..
//          ..
//          ..
//           .
//           .
//           .
//           .
// you can see that every vertical line is formed with 2^x number
// so we can simply turn eg. 13 into binary format, which is 1101 = 1 + 100 + 1000
// then we will know how many 2^x vertical line can it form
// so we just need to brute force a number that the num of vertical lines of that number is <= K
int PouringWater::getMinBottles(int N, int K) {
	int t = N;
	while(1){
		if(__builtin_popcount(t)<=K){
			break;
		}
		t++;
	}
	return t - N;
}
int PouringWater::getMinBottles(int N, int K) {
	int t = N;
	while(1){
		int a = 0;
		int b = t;
		while(b>0){
			a++;
			b &= b-1;
		}
		if(a<=K){
			break;
		}
		t++;
	}
	return t - N;
}

// 191 2.2
// you can also use string.find_first_of() to parse the string
// noticed that if the the same volume appeared in that box more that 1 time, that is the actual volume
int VolumeGuess::correctVolume(vector <string> queries, int numberOfBoxes, int ithBox) {
	set<int> s;
	for(int i=0; i<queries.size(); i++){
		int a, b, c;
		sscanf(queries[i].c_str(), "%d,%d,%d", &a, &b, &c);
		if(a==ithBox || b==ithBox){
			if(s.find(c) != s.end()){
				return c;
			}
			s.insert(c);
		}
	}
}
// noticed that if multiple volume have appeared in that box, the smaller one will not be the actual volume
// so by process of elimination, the actual volume will be the largest volume appeared
int VolumeGuess::correctVolume(vector <string> queries, int numberOfBoxes, int ithBox) {
	vector<int> v(numberOfBoxes+1);
	for(int i=0; i<queries.size(); i++){
		int a, b, c;
		sscanf(queries[i].c_str(), "%d,%d,%d", &a, &b, &c);
		v[a] = max(v[a], c);
		v[b] = max(v[b], c);
	}
	return v[ithBox];
}
// use brute force the find the volume arrangement that suit all the condition
int VolumeGuess::correctVolume(vector <string> queries, int numberOfBoxes, int ithBox) {
	vector< pair< pair<int, int>, int> > v;
	set<int> s;
	for(int i=0; i<queries.size(); i++){
		int a, b, c;
		sscanf(queries[i].c_str(), "%d,%d,%d", &a, &b, &c);
		v.push_back(make_pair(make_pair(a, b), c));
		s.insert(c);
	}
	vector<int> u(numberOfBoxes, 1000);
	copy(s.begin(), s.end(), u.begin());
	do{
		bool bo = true;
		for(int i=0; i<v.size(); i++){
			int a = v[i].first.first;
			int b = v[i].first.second;
			int c = v[i].second;
			if(!((u[a-1]==c && u[b-1]>c)||(u[b-1]==c && u[a-1]>c))){
				bo = false;
				break;
			}
		}
		if(bo){
			return u[ithBox-1];
		}
	}while(next_permutation(u.begin(), u.end()));
	return -1;
}

// 417 2.2
string TemplateMatching::bestMatch(string text, string prefix, string suffix) {
	string ans = "";
	int a = -1;
	int b = -1;
	for(int i=0; i<text.size(); i++){
		string t;
		for(int j=i; j<text.size(); j++){
			t += text[j];
			int c = 0;
			for(int k=0; k<=t.size(); k++){
				bool bo = true;
				int e = 0;
				for(int m=t.size()-1-k, n=prefix.size()-1; m>=0 && n>=0; m--, n--){
					if(t[m] != prefix[n]){
						bo = false;
						break;
					}
					e++;
				}
				if(bo && e==t.size()-k){
					c = t.size()-k;
					break;
				}
			}
			int d = 0;
			for(int k=0; k<=t.size(); k++){
				bool bo = true;
				int e = 0;
				for(int m=k, n=0; m<t.size() && n<suffix.size(); m++, n++){
					if(t[m] != suffix[n]){
						bo = false;
						break;
					}
					e++;
				}
				if(bo && e==t.size()-k){
					d = t.size()-k;
					break;
				}
			}
			if((c+d>b)||(c+d==b && c>a)||(c+d==b && c==a && t<ans)){
				ans = t;
				b = c+d;
				a = c;
			}
		}
	}
	return ans;
}
// better
int get(string& s, string& p){
	for(int i=min(s.size(), p.size()); i>0; i--){
		if(s.substr(0, i) == p.substr(p.size()-i)){
			return i;
		}
	}
	return 0;
}
string TemplateMatching::bestMatch(string text, string prefix, string suffix) {
	string ans;
	int a = -1;
	int b = -1;
	for(int i=0; i<text.size(); i++){
		for(int j=1; j<=text.size()-i; j++){
			string t = text.substr(i, j);
			int c = get(t, prefix);
			int d = get(suffix, t);
			if(c+d>a || (c+d==a && c>b) || (c+d==a && c==b && t<ans)){
				ans = t;
				a = c+d;
				b = c;
			}
		}
	}
	return ans;
}
// alternative, but not so clear
string TemplateMatching::bestMatch(string text, string prefix, string suffix) {
	string ans;
	int a = -1;
	int b = -1;
	for(int i=0; i<text.size(); i++){
		for(int j=1; j<=text.size()-i; j++){
			string t = text.substr(i, j);
			int c = min(t.size(), prefix.size());
			while(c>0 && prefix.substr(prefix.size()-c)!=t.substr(0, c)) c--;
			int d = min(suffix.size(), t.size());
			while(d>0 && suffix.substr(0, d)!=t.substr(t.size()-d)) d--;
			if(c+d>a || (c+d==a && c>b) || (c+d==a && c==b && t<ans)){
				ans = t;
				a = c+d;
				b = c;
			}
		}
	}
	return ans;
}

// 520 2.2
int SRMCodingPhase::countScore(vector <int> points, vector <int> skills, int luck) {
	int ans = 0;
	for(int i=0; i<=luck; i++){
		for(int j=0; j<=luck; j++){
			for(int k=0; k<=luck; k++){
				if(i+j+k > luck){
					continue;
				}
				vector<int> s = skills;
				s[0] = max(1, s[0]-i);
				s[1] = max(1, s[1]-j);
				s[2] = max(1, s[2]-k);
				for(int m=1; m<1<<3; m++){
					int t = 0;
					int u = 0;
					for(int n=0; n<3; n++){
						if((1<<n)&m){
							u += s[n];
							t += points[n]-(1<<(n+1))*s[n];
						}
					}
					if(u > 75){
						continue;
					}
					ans = max(ans, t);
				}
			}
		}
	}
	return ans;
}
// better
// there is still one greedy method, but still don't quite understand, todo, have to figure out
// brute force three numbers' sum in certain range
int SRMCodingPhase::countScore(vector <int> points, vector <int> skills, int luck) {
	int ans = 0;
	for(int i=0; i<=luck && i<skills[0]; i++){
		for(int j=0; i+j<=luck && j<skills[1]; j++){
			for(int k=0; i+j+k<=luck && k<skills[2]; k++){
				int s[] = {skills[0]-i, skills[1]-j, skills[2]-k};
				for(int m=1; m<1<<3; m++){
					int t = 0;
					int u = 0;
					for(int n=0; n<3; n++){
						if((1<<n)&m){
							u += s[n];
							t += points[n]-(1<<(n+1))*s[n];
						}
					}
					if(u <= 75){
						ans = max(ans, t);
					}
				}
			}
		}
	}
	return ans;
}

// 482 2.2
int LockersDivTwo::lastOpened(int N) {
	vector<int> b(N);
	for(int i=0; i<N; i++){
		b[i] = i+1;
	}
	int a = 2;
	while(b.size()>1){
		vector<int> c;
		vector<int> d(b.size());
		for(int i=0; i<b.size(); i+=a){
			d[i] = 1;
		}
		for(int i=0; i<b.size(); i++){
			if(d[i]==0){
				c.push_back(b[i]);
			}
		}
		b = c;
		a++;
	}
	return b[0];
}
// better
int LockersDivTwo::lastOpened(int N) {
	vector<int> b(N);
	for(int i=0; i<N; i++){
		b[i] = i+1;
	}
	int a = 2;
	while(b.size()>1){
		vector<int> c;
		for(int i=0; i<b.size(); i++){
			if(i%a!=0){
				c.push_back(b[i]);
			}
		}
		b = c;
		a++;
	}
	return b[0];
}

// 596 2.2
string r;
char d[] = {'G', 'B', 'R'};
int back(int c, int n, int m, int& ans, int& t){
	if(n==r.size()-1){
		ans = min(ans, c);
		t++;
	}
	for(int i=n+1; i<r.size(); i++){
		if(r[i] == d[m%3]){
			back(c+(i-n)*(i-n), i, m+1, ans, t);
		}
	}
}
int ColorfulRoad::getMin(string road) {
	r = road;
	int ans = numeric_limits<int>::max();
	int t = 0;
	back(0, 0, 0, ans, t);
	if(t == 0){
		return -1;
	}
	return ans;
}
// better, without using reference
string r;
char d[] = {'G', 'B', 'R'};
int back(int c, int n, int m){
	if(n==r.size()-1){
		return c;
	}
	int t = -1;
	for(int i=n+1; i<r.size(); i++){
		if(r[i] == d[m%3]){
			int re = back(c+(i-n)*(i-n), i, m+1);
			if(re != -1 && (t==-1||re<t)){
				t = re;
			}
		}
	}
	return t;
}
int ColorfulRoad::getMin(string road) {
	r = road;
	return back(0, 0, 0);
}
// better version of backtrack, because it can be improved to dp, previous cannot
string r;
char d[] = {'G', 'B', 'R'};
int back(int n, int m){
	if(n==r.size()-1){
		return 0;
	}
	int t = -1;
	for(int i=n+1; i<r.size(); i++){
		if(r[i] == d[m%3]){
			int re = back( i, m+1);
			if(re != -1){
				int a = (i-n)*(i-n) + re;
				if(t==-1 || a<t){
					t = a;
				}
			}
		}
	}
	return t;
}
int ColorfulRoad::getMin(string road) {
	r = road;
	return back(0, 0);
}
// memorization
string r;
char d[] = {'G', 'B', 'R'};
int f[16][3];
int back(int n, int m){
	if(n==r.size()-1){
		return 0;
	}
	if(f[n][m%3] != -2){
		return f[n][m%3];
	}
	int t = -1;
	for(int i=n+1; i<r.size(); i++){
		if(r[i] == d[m%3]){
			int re = back( i, m+1);
			if(re != -1){
				int a = (i-n)*(i-n) + re;
				if(t==-1 || a<t){
					t = a;
				}
			}
		}
	}
	f[n][m%3] = t;
	return t;
}
int ColorfulRoad::getMin(string road) {
	for(int i=0; i<16; i++){
		for(int j=0; j<3; j++){
			f[i][j] = -2;
		}
	}
	r = road;
	return back(0, 0);
}
// better and cleaner
int inf = 1e9;
int d[] = {'R', 'G', 'B'};
string r;
int go(int n, int k){
	if(n == r.size()-1){
		return 0;
	}
	int u = inf;
	for(int i=n+1; i<r.size(); i++){
		if(r[i] == d[k]){
			u = min(u, go(i, (k+1)%3) + (i-n)*(i-n));
		}
	}
	return u;
}
int ColorfulRoad::getMin(string road) {
	r = road;
	int ans = go(0, 1);
	if(ans == inf){
		ans = -1;
	}
	return ans;
}
// dp
int ColorfulRoad::getMin(string road) {
	char a[150];
	a['R'] = 'G';
	a['G'] = 'B';
	a['B'] = 'R';
	int inf = 1e9;
	int n = road.size();
	int dp[16];
	fill(dp, dp+16, inf);
	dp[0] = 0;
	for(int i=0; i<n; i++){
		if(dp[i] != inf){
			for(int j=i+1; j<n; j++){
				if(road[j] == a[road[i]]){
					dp[j] = min(dp[j], dp[i]+(j-i)*(j-i));
				}
			}
		}
	}
	int ans = dp[n-1];
	if(ans == inf){
		ans = -1;
	}
	return ans;
}

// 352 2.2
vector <int> NumberofFiboCalls::fiboCallsMade(int n) {
	vector<int> v(2);
	if(n == 0){
		v[0] = 1;
		v[1] = 0;
		return v;
	}
	if(n == 1){
		v[0] = 0;
		v[1] = 1;
		return v;
	}
	int a = 0;
	int b = 1;
	int i = 2;
	while(i<=n){
		int c = a+b;
		a = b;
		b = c;
		if(i == n-1){
			v[0] = c;
		}
		if(i == n){
			v[1] = c;
		}
		i++;
	}
	return v;
}

// 621 2.2
// given some numbers, find smallest posible num that is not subset sum of those nums
int NumbersChallenge::MinNumber(vector <int> S) {
	vector<int> v(2000001);
	int n = S.size();
	for(int i=0; i<1<<n; i++){
		int t = 0;
		for(int j=0; j<n; j++){
			if((1<<j)&i){
				t += S[j];
			}
		}
		v[t] = 1;
	}
	for(int i=1; i<v.size(); i++){
		if(v[i] == 0){
			return i;
		}
	}
	return -1;
}
// memorization, wrong approach, tle
#include <cstring>
int memo[21][2000001];
vector<int> s;
int dp(int n, int c, int t){
	if(c == t){
		return 1;
	}
	if(n == s.size()){
		return 0;
	}
	if(memo[n][c] != -1){
		return memo[n][c];
	}
	return memo[n][c] = dp(n+1, c, t) | dp(n+1, c+s[n], t);
}
int NumbersChallenge::MinNumber(vector <int> S) {
	s = S;
	for(int i=1; i<=2000000; i++){
		memset(memo, -1, sizeof(memo));
		if(dp(0, 0, i) == 0){
			return i;
		}
	}
	return -1;
}
// dp, but tle
// noted that use vector.swap is faster than vector = other vector
int NumbersChallenge::MinNumber(vector <int> S) {
	int dn = 2000001;
	vector<bool> dp(dn, false);
	dp[0] = true;
	for(int i=0; i<S.size(); i++){
		vector<bool> dpp(dn, false);
		for(int j=0; j<dn; j++){
			if(dp[j]){
				dpp[j] = true;
				dpp[j+S[i]] = true;
			}
		}
		dp.swap(dpp);
	}
	for(int i=0; i<dn; i++){
		if(!dp[i]){
			return i;
		}
	}
	return -1;
}
// dp optimized by avoiding extra vector dpp, still tle
int NumbersChallenge::MinNumber(vector <int> S) {
	int dn = 2000001;
	vector<bool> dp(dn, false);
	dp[0] = true;
	for(int i=0; i<S.size(); i++){
		for(int j=dn-1; j>=0; j--){
			if(dp[j]){
				dp[j+S[i]] = true;
			}
		}
	}
	for(int i=0; i<dn; i++){
		if(!dp[i]){
			return i;
		}
	}
	return dn;
}
// correct, further optimized by using native array
int NumbersChallenge::MinNumber(vector <int> S) {
	const int dn = 2000000;
	bool dp[dn+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	for(int i=0; i<S.size(); i++){
		for(int j=dn; j>=0; j--){
			if(dp[j]){
				dp[j+S[i]] = true;
			}
		}
	}
	for(int i=0; i<=dn; i++){
		if(!dp[i]){
			return i;
		}
	}
	return dn + 1;
}


// 619 2.2
// wrong
int ChooseTheBestOne::countNumber(int N) {
	vector<int> v(N);
	for(int i=0; i<N; i++){
		v[i] = i+1;
	}
	int p = 0;
	for(int i=1; i<=N-1; i++){
		int n = (p%v.size()+(i%v.size())*(i%v.size())*(i%v.size())-1%v.size())%v.size();
		p = n;
		v.erase(v.begin()+n);
	}
	return v[0];
}
// correct, in topcoder server long is equal to long long
int ChooseTheBestOne::countNumber(int N) {
	vector<int> v(N);
	for(int i=0; i<N; i++){
		v[i] = i+1;
	}
	int p = 0;
	for(long long i=1; i<=N-1; i++){
		int n = (p+i*i*i-1)%v.size();
		p = n;
		v.erase(v.begin()+n);
	}
	return v[0];
}

// 612 2.2
// wrong
int s;
int back(int n, int t){
	if(n == s){
		return 0;
	}
	if(n>s){
		return -1;
	}
	int a = back(n+t, t);
	int b = back(n+n, n);
	int c = a + 1;
	int d = b + 2;
	if(a!=-1 && b!=-1){
		return min(c, d);
	}
	if(a == -1){
		return d;
	}
	return c;
}
int EmoticonsDiv2::printSmiles(int smiles) {
	s = smiles;
	return back(1, 1) + 1;
}
// correct
int inf = 1e9;
int s;
int go(int a, int b){
	if(b == s){
		return 0;
	}
	int u = inf;
	int c[] = {a, b};
	int d[] = {b+a, b*2};
	int e[] = {1, 2};
	for(int i=0; i<2; i++){
		if(d[i] <= s){
			u = min(u, go(c[i], d[i]) + e[i]);
		}
	}
	return u;
}
int EmoticonsDiv2::printSmiles(int smiles) {
	s = smiles;
	return go(1, 1) + 1;
}
// dp tle
int EmoticonsDiv2::printSmiles(int smiles) {
	int inf = 1e9;
	vector< vector<int> > dp(1001, vector<int>(1001, inf));
	dp[1][1] = 1;
	int ans = inf;
	while(1){
		bool bo = true;
		vector< vector<int> > dd(1001, vector<int>(1001, inf));
		for(int i=0; i<=smiles; i++){
			for(int j=0; j<=smiles; j++){
				if(dp[i][j] != inf){
					if(j == smiles){
						ans = min(ans, dp[i][j]);
					}
					int a[] = {i, j};
					int b[] = {j+i, j*2};
					int c[] = {1, 2};
					for(int k=0; k<2; k++){
						if(b[k] <= smiles){
							bo = false;
							dd[a[k]][b[k]] = min(dd[a[k]][b[k]], dp[i][j]+c[k]);
						}
					}
				}
			}
		}
		if(bo){
			break;
		}
		dp.swap(dd);
	}
	return ans;
}

// 585 2.2
// dp
long long TrafficCongestionDivTwo::theMinCars(int treeHeight) {
	long long h[61];
	h[0] = 1;
	h[1] = 1;
	long long t = 1;
	for(int i=2; i<=treeHeight; i++){
		t += 2*h[i-2];
		h[i] = t;
	}
	return h[treeHeight];
}

// 223 1.1
int QuizShow::wager(vector <int> scores, int wager1, int wager2) {
	vector<int> w(3);
	w[1] = wager1;
	w[2] = wager2;
	int ans = -1;
	int b = -1;
	for(int i=0; i<=scores[0]; i++){
		w[0] = i;
		int t = 0;
		for(int j=0; j<1<<3; j++){
			vector<int> s = scores;
			for(int k=0; k<3; k++){
				if((1<<k)&j){
					s[k] += w[k];
				}else{
					s[k] -= w[k];
				}
			}
			if(s[0] > max(s[1], s[2])){
				t++;
			}
		}
		if(t > b){
			b = t;
			ans = i;
		}
	}
	return ans;
}

// 233 1.1
double PipeCuts::probability(vector <int> weldLocations, int L) {
	sort(weldLocations.begin(), weldLocations.end());
	int a = 0;
	int b = 0;
	for(int i=0; i<weldLocations.size(); i++){
		for(int j=i+1; j<weldLocations.size(); j++){
			a++;
			int c = weldLocations[i];
			int d = weldLocations[j] - weldLocations[i];
			int e = 100 - weldLocations[j];
			if(c>L || d>L || e>L){
				b++;
			}
		}
	}
	return b*1.0/a;
}

// 174 1.1
int BirthdayOdds::minPeople(int minOdds, int daysInYear) {
	int i = 0;
	double a = 1;
	while(1){
		a *= (daysInYear-i)*1.0/daysInYear;
		if(1*1.0-a >= minOdds*1.0/100){
			break;
		}
		i++;
	}
	return i+1;
}

// 153 1.2
// assignments: how many id assignments of each core in a day
// ids: how many ids in the pool
// system a: each system dont have memory of what ids they have assigned
// system b: each system have memory of what they have assigned
// both systems will synchronize their ids after each day 
// calculate probability for some client have same id for each system and return their difference
// approach:
// system a probability = 1 - p(all id not same)
// = 1 - p(1st not same)*p(2nd not same)*p(3rd not same)*...
// = 1 - n/n * (n-1)/n * (n-2)/n * ...
// or
// = 1 - no of combinations that all id not same / no of all combinations to assign id
// = 1 - nPk/n^k
// * k = sum of all cores assignments number
// system b probability = 1 - p(all id not same)
double Collision::probability(vector <int> assignments, int ids) {
	for(int i=0; i<assignments.size(); i++){
		if(assignments[i] > ids){
			return 0;
		}
	}
	double a = 1;
	int b = accumulate(assignments.begin(), assignments.end(), 0);
	for(int i=0; i<b; i++){
		a *= (ids-i)*1.0/ids;
	}
	a = 1.0 - a;
	double c = 1;
	int d = 0;
	for(int i=0; i<assignments.size(); i++){
		for(int j=0; j<assignments[i]; j++){
			c *= (ids-d-j)*1.0/(ids-j);
		}
		d += assignments[i];
	}
	c = 1.0 - c;
	return a - c;
}

// 422 2.2
vector<int> getp(int n){
	vector<int> v(n+1, 1);
	v[0] = 0;
	v[1] = 0;
	for(int i=2; i*i<=n; i++){
		if(v[i]){
			for(int j=i*i; j<=n; j+=i){
				v[j] = 0;
			}
		}
	}
	vector<int> a;
	for(int i=0; i<n+1; i++){
		if(v[i]){
			a.push_back(i);
		}
	}
	return a;
}
double PrimeSoccer::getProbability(int skillOfTeamA, int skillOfTeamB) {
	double s[] = {skillOfTeamA/100.0, skillOfTeamB/100.0};
	double a[] = {0, 0};
	vector<int> p = getp(18);
	for(int i=0; i<2; i++){
		for(int j=0; j<p.size(); j++){
			double t = 1;
			for(int k=0; k<p[j]; k++){
				t *= s[i];
			}
			for(int k=0; k<18-p[j]; k++){
				t *= 1-s[i];
			}
			for(int k=0; k<p[j]; k++){
				t *= (18-k)*1.0/(p[j]-k);
			}
			a[i] += t;
		}
	}
	return 1-(1-a[0])*(1-a[1]);
}
// alternative
double PrimeSoccer::getProbability(int skillOfTeamA, int skillOfTeamB) {
	vector<bool> r(19, true);
	r[0] = r[1] = false;
	for(int i=2; i*i<=18; i++){
		if(r[i]){
			for(int j=i*i; j<=18; j+=i){
				r[j] = false;
			}
		}
	}
	vector<int> p;
	for(int i=0; i<=18; i++){
		if(r[i]){
			p.push_back(i);
		}
	}
	int c[19][19];
	memset(c, 0, sizeof(c));
	c[0][0] = 1;
	for(int i=1; i<=18; i++){
		c[i][0] = 1;
		for(int j=1; j<=18; j++){
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	double sa = skillOfTeamA/100.;
	double sb = skillOfTeamB/100.;
	double pa = 0;
	double pb = 0;
	for(int i=0; i<p.size(); i++){
		double ta = c[18][p[i]];
		double tb = c[18][p[i]];
		for(int j=0; j<p[i]; j++){
			ta *= sa;
			tb *= sb;
		}
		for(int j=0; j<18-p[i]; j++){
			ta *= 1-sa;
			tb *= 1-sb;
		}
		pa += ta;
		pb += tb;
	}
	return 1-(1-pa)*(1-pb);
}

// 325 2.2
vector< vector<int> > h;
int back(int n, int l){
	if(n == h.size()){
		return 0;
	}
	int t = numeric_limits<int>::max();
	for(int i=0; i<3; i++){
		if(i!=l){
			t = min(t, back(n+1, i)+h[n][i]);
		}
	}
	return t;
}
int RGBStreet::estimateCost(vector <string> houses) {
	vector< vector<int> > hh(houses.size());
	for(int i=0; i<houses.size(); i++){
		stringstream ss(houses[i]);
		int t;
		while(ss >> t){
			hh[i].push_back(t);
		}
	}
	h = hh;
	int ans = back(0, -1);
	return ans;
}
// memorization but not necessary
vector< vector<int> > h;
int memo[21][3];
int back(int n, int l){
	if(n == h.size()){
		return 0;
	}
	if(l!=-1 && memo[n][l] != -1){
		return memo[n][l];
	}
	int t = numeric_limits<int>::max();
	for(int i=0; i<3; i++){
		if(i!=l){
			t = min(t, back(n+1, i)+h[n][i]);
		}
	}
	return memo[n][l] = t;
}
int RGBStreet::estimateCost(vector <string> houses) {
	vector< vector<int> > hh(houses.size());
	for(int i=0; i<houses.size(); i++){
		stringstream ss(houses[i]);
		int t;
		while(ss >> t){
			hh[i].push_back(t);
		}
	}
	h = hh;
	memset(memo, -1, sizeof(memo));
	int ans = back(0, -1);
	return ans;
}
// dp
int RGBStreet::estimateCost(vector <string> houses) {
	int n = houses.size();
	int h[20][3];
	for(int i=0; i<n; i++){
		stringstream ss(houses[i]);
		for(int j=0; j<3; j++){
			ss >> h[i][j];
		}
	}
	int inf = 1e9;
	int dp[21][3];
	for(int i=0; i<21; i++){
		for(int j=0; j<3; j++){
			dp[i][j] = inf;
		}
	}
	for(int i=0; i<3; i++){
		dp[0][i] = 0;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(k!=j){
					dp[i+1][j] = min(dp[i+1][j], dp[i][k]+h[i][k]);
				}
			}
		}
	}
	int ans = inf;
	for(int i=0; i<3; i++){
		ans = min(ans, dp[n][i]);
	}
	return ans;
}

// 534 2.2
string EllysCheckers::getWinner(string board) {
	int t = 0;
	int n = board.size();
	for(int i=0; i<n; i++){
		if(board[i] == 'o'){
			t += n-i+1;
		}
	}
	return (t%2==0)? "NO": "YES";
}

// 555 2.2
// good question, want more can check out egor answer
int memo[51][51];
string s;
bool good(string a){
	if(a[0] == '0'){
		return false;
	}
	long long t = 0;
	for(int i=0; i<a.size(); i++){
		t = t*2 + a[i]-'0';
	}
	while(t%5 == 0) t/=5;
	return t == 1;
}
int back(int a, int b){
	if(memo[a][b] != -1){
		return memo[a][b];
	}
	if(good(s.substr(a, b-a+1))){
		return memo[a][b] = 1;
	}
	int t = numeric_limits<int>::max()/2;
	for(int i=a; i<b; i++){
		t = min(t, back(a, i) + back(i+1, b));
	}
	return memo[a][b] = t;
}
int CuttingBitString::getmin(string S) {
	int n = S.size();
	memset(memo, -1, sizeof(memo));
	s = S;
	int ans = back(0, n-1);
	if(ans == numeric_limits<int>::max()/2){
		return -1;
	}
	return ans;
}
// other memorization approach
bool ok(string s){
	if(s[0] != '1'){
		return false;
	}
	long long t = 0;
	for(int i=0; i<s.size(); i++){
		t = t*2 + s[i]-'0';
	}
	while(t%5 == 0){
		t /= 5;
	}
	return t == 1;
}
int inf = 1e9;
string s;
int memo[51];
int go(int n){
	if(memo[n] != -1){
		return memo[n];
	}
	if(n == s.size()){
		return 0;
	}
	int u = inf;
	for(int i=n; i<s.size(); i++){
		if(ok(s.substr(n, i-n+1))){
			u = min(u, go(i+1) + 1);
		}
	}
	return memo[n] = u;
}
int CuttingBitString::getmin(string S) {
	s = S;
	memset(memo, -1, sizeof(memo));
	int ans = go(0);
	if(ans == inf){
		ans = -1;
	}
	return ans;
}
// dp
bool ok(string s){
	if(s[0] != '1'){
		return false;
	}
	long long t = 0;
	for(int i=0; i<s.size(); i++){
		t = t*2 + s[i]-'0';
	}
	while(t%5 == 0){
		t /= 5;
	}
	return t == 1;
}
int CuttingBitString::getmin(string S) {
	int inf = 1e9;
	int sn = S.size();
	vector<int> dp(sn+1, inf);
	dp[0] = 0;
	for(int i=0; i<sn; i++){
		if(dp[i] != inf){
			for(int j=i; j<sn; j++){
				if(ok(S.substr(i, j-i+1))){
					dp[j+1] = min(dp[j+1], dp[i]+1);
				}
			}
		}
	}
	int ans = dp[sn];
	if(ans == inf){
		ans = -1;
	}
	return ans;
}

// 363 2.2
long long HandsShaking::countPerfect(int n) {
	vector<long long> v(n+1);
	v[0] = 1;
	for(int i=2; i<=n; i+=2){
		for(int j=0; j<i; j+=2){
			v[i] += v[j]*v[i-j-2];
		}
	}
	return v[n];
}

// 411 2.2
vector<string> v;
vector<string> w;
string s;
int memo[51][51];
int cost(int a, int b){
	string t = s.substr(a, b-a+1);
	sort(t.begin(), t.end());
	int x = -1;
	for(int i=0; i<w.size(); i++){
		if(w[i] == t){
			int u = 0;
			for(int j=0; j<v[i].size(); j++){
				if(v[i][j] != s[a+j]){
					u++;
				}
			}
			if(x==-1 || u<x){
				x = u;
			}
		}
	}
	return x;
}
int back(int a, int b){
	if(memo[a][b] != -1){
		return memo[a][b];
	}
	int t = numeric_limits<int>::max()/2;
	int c = cost(a, b);
	if(c != -1){
		t = min(t, c);
	}
	for(int i=a; i<b; i++){
		t = min(t, back(a, i)+back(i+1, b));
	}
	return memo[a][b] = t;
}
int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {
	s = sentence;
	v = validWords;
	w = validWords;
	memset(memo, -1, sizeof(memo));
	for(int i=0; i<w.size(); i++){
		sort(w[i].begin(), w[i].end());
	}
	int ans = back(0, sentence.size()-1);
	if(ans == numeric_limits<int>::max()/2){
		return -1;
	}
	return ans;
}
// similar alternative
vector<string> v;
vector<string> w;
string s;
int memo[51][51];
int cost(int a, int b){
	string t = s.substr(a, b-a+1);
	sort(t.begin(), t.end());
	int x = -1;
	for(int i=0; i<w.size(); i++){
		if(w[i] == t){
			int u = 0;
			for(int j=0; j<v[i].size(); j++){
				if(v[i][j] != s[a+j]){
					u++;
				}
			}
			if(x==-1 || u<x){
				x = u;
			}
		}
	}
	return x;
}
int back(int a, int b){
	if(memo[a][b] != -2){
		return memo[a][b];
	}
	int t = -1;
	int c = cost(a, b);
	if(c != -1){
		t = c;
	}
	for(int i=a; i<b; i++){
		int d = back(a, i);
		int e = back(i+1, b);
		if(d!=-1 && e!=-1 && (t==-1 || d+e<t)){
			t = d+e;
		}
	}
	return memo[a][b] = t;
}
int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {
	s = sentence;
	v = validWords;
	w = validWords;
	for(int i=0; i<51; i++){
		for(int j=0; j<51; j++){
			memo[i][j] = -2;
		}
	}
	for(int i=0; i<w.size(); i++){
		sort(w[i].begin(), w[i].end());
	}
	return back(0, sentence.size()-1);
}
// similar
int inf = 1e9;
string s;
vector<string> v;
vector<string> w;
int memo[50][50];
int go(int a, int b){
	if(memo[a][b] != -1){
		return memo[a][b];
	}
	int u = inf;
	string t = s.substr(a, b-a+1);
	sort(t.begin(), t.end());
	for(int i=0; i<w.size(); i++){
		if(t == w[i]){
			int r = 0;
			for(int j=0; j<v[i].size(); j++){
				if(s[a+j] != v[i][j]){
					r++;
				}
			}
			u = min(u, r);
		}
	}
	for(int i=a; i<b; i++){
		u = min(u, go(a, i) + go(i+1, b));
	}
	return memo[a][b] = u;
}
int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {
	s = sentence;
	v = validWords;
	w = validWords;
	memset(memo, -1, sizeof(memo));
	for(int i=0; i<w.size(); i++){
		sort(w[i].begin(), w[i].end());
	}
	int ans = go(0, sentence.size()-1);
	if(ans == inf){
		ans = -1;
	}
	return ans;
}
// other approach
// different from above, above is first split string and check if substring match requirements
// this one is use the requirements to match left part of the string, if yes then split the string and continue to check with right substring
// pure backtrack, tle
vector<string> w;
vector<string> v;
string s;
int back(int a){
	if(a == s.size()){
		return 0;
	}
	int u = -1;
	for(int i=0; i<w.size(); i++){
		if(w[i].size() > s.size()-a){
			continue;
		}
		string r = s.substr(a, w[i].size());
		sort(r.begin(), r.end());
		if(r == w[i]){
			int t = 0;
			for(int j=0; j<v[i].size(); j++){
				if(v[i][j] != s[a+j]){
					t++;
				}
			}
			int x = back(a+v[i].size());
			if(x!=-1 && (u==-1 || x+t<u)){
				u = x+t;
			}
		}
	}
	return u;
}
int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {
	s = sentence;
	v = validWords;
	w = validWords;
	for(int i=0; i<w.size(); i++){
		sort(w[i].begin(), w[i].end());
	}
	return back(0);
}
// improve with memorization
vector<string> w;
vector<string> v;
string s;
int memo[51];
int back(int a){
	if(memo[a] != -2){
		return memo[a];
	}
	if(a == s.size()){
		return 0;
	}
	int u = -1;
	for(int i=0; i<w.size(); i++){
		if(w[i].size() > s.size()-a){
			continue;
		}
		string r = s.substr(a, w[i].size());
		sort(r.begin(), r.end());
		if(r == w[i]){
			int t = 0;
			for(int j=0; j<v[i].size(); j++){
				if(v[i][j] != s[a+j]){
					t++;
				}
			}
			int x = back(a+v[i].size());
			if(x!=-1 && (u==-1 || x+t<u)){
				u = x+t;
			}
		}
	}
	return memo[a] = u;
}
int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {
	s = sentence;
	v = validWords;
	w = validWords;
	for(int i=0; i<51; i++){
		memo[i] = -2;
	}
	for(int i=0; i<w.size(); i++){
		sort(w[i].begin(), w[i].end());
	}
	return back(0);
}
// memo similar
int inf = 1e9;
string s;
vector<string> v;
vector<string> w;
int memo[51];
int go(int n){
	if(memo[n] != -1){
		return memo[n];
	}
	if(n == s.size()){
		return 0;
	}
	int u = inf;
	for(int i=0; i<w.size(); i++){
		string t = s.substr(n, w[i].size());
		sort(t.begin(), t.end());
		if(t == w[i]){
			int r = 0;
			for(int j=0; j<v[i].size(); j++){
				if(s[n+j] != v[i][j]){
					r++;
				}
			}
			u = min(u, go(n+v[i].size())+r);
		}
	}
	return memo[n] = u;
}
int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {
	s = sentence;
	v = validWords;
	w = validWords;
	for(int i=0; i<w.size(); i++){
		sort(w[i].begin(), w[i].end());
	}
	memset(memo, -1, sizeof(memo));
	int ans = go(0);
	if(ans == inf){
		ans = -1;
	}
	return ans;
}
// dp
int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {
	int inf = 1e9;
	int vn = validWords.size();
	int sn = sentence.size();
	vector<string> w = validWords;
	for(int i=0; i<vn; i++){
		sort(w[i].begin(), w[i].end());
	}
	vector<int> dp(sn+1, inf);
	dp[0] = 0;
	for(int i=0; i<sn; i++){
		if(dp[i] != inf){
			for(int j=0; j<vn; j++){
				string t = sentence.substr(i, w[j].size());
				sort(t.begin(), t.end());
				if(t == w[j]){
					int u = 0;
					for(int k=0; k<validWords[j].size(); k++){
						if(sentence[i+k]!=validWords[j][k]){
							u++;
						}
					}
					dp[i+validWords[j].size()] = min(dp[i+validWords[j].size()], dp[i]+u);
				}
			}
		}
	}
	int ans = dp[sn];
	if(ans == inf){
		ans = -1;
	}
	return ans;
}

// 531 2.2
// correct logic but tle
int p;
int m;
int go(int t, int r, int n){
	if(n == p){
		if(t > 0){
			return 0;
		}else{
			return 1;
		}
	}
	int u = 0;
	if(t > 0){
		u += t*go(t-1, r+1, n+1);
	}
	int rr = max(r-m, 0);
	if(rr > 0){
		u += rr*go(t, r, n+1);
	}
	return u;
}
int NoRepeatPlaylist::numPlaylists(int N, int M, int P) {
	p = P;
	m = M;
	return go(N, 0, 0);
}
// memorization
int mod = 1000000007;
int p;
int m;
long long me[101][101][101];
long long go(int t, int r, int n){
	long long &re = me[t][r][n];
	if(re != -1){
		return re;
	}
	if(n == p){
		if(t > 0){
			return 0;
		}else{
			return 1;
		}
	}
	long long u = 0;
	if(t > 0){
		u += t*go(t-1, r+1, n+1);
	}
	int rr = max(r-m, 0);
	if(rr > 0){
		u += rr*go(t, r, n+1);
	}
	return re = u%mod;
}
int NoRepeatPlaylist::numPlaylists(int N, int M, int P) {
	p = P;
	m = M;
	memset(me, -1, sizeof(me));
	return go(N, 0, 0);
}
// improved by noticing we can get r by N-t, but above one looks more clear
int mod = 1000000007;
int p;
int m;
int n;
long long me[101][101];
long long go(int t, int k){
	long long &re = me[t][k];
	if(re != -1){
		return re;
	}
	if(k == p){
		if(t > 0){
			return 0;
		}else{
			return 1;
		}
	}
	long long u = 0;
	if(t > 0){
		u += t*go(t-1, k+1);
	}
	int rr = max(n-t-m, 0);
	if(rr > 0){
		u += rr*go(t, k+1);
	}
	return re = u % mod;
}
int NoRepeatPlaylist::numPlaylists(int N, int M, int P) {
	p = P;
	m = M;
	n = N;
	memset(me, -1, sizeof(me));
	return go(N, 0);
}
// dp
int NoRepeatPlaylist::numPlaylists(int N, int M, int P) {
	int mod = 1e9 + 7;
	long long dp[101][101] = {0};
	dp[0][0] = 1;
	for(int i=0; i<P; i++){
		for(int j=0; j<=N; j++){
			int t = max(j-M, 0);
			if(t > 0){
				dp[i+1][j] = (dp[i+1][j] + t*dp[i][j])%mod;
			}
			if(j+1 <= N){
				dp[i+1][j+1] = (dp[i+1][j+1] + (N-j)*dp[i][j])%mod;
			}
		}
	}
	return dp[P][N];
}
// math approach
// several point:
// 1. inclusion-exclusion principle
// 2. dynamic programming for combination
// 3. modular arithmetic
// wrong in some test case, but general concept is right
int mod = 1000000007;
int memo[101][101];
int c(int n, int k){
	int &re = memo[n][k];
	if(re != -1){
		return re;
	}
	if(k==0 || k==n){
		return 1;
	}
	return re = (c(n-1, k-1) + c(n-1, k))%mod;
}
int NoRepeatPlaylist::numPlaylists(int N, int M, int P) {
	memset(memo, -1, sizeof(memo));
	long long ans = 0;
	for(int i=0; i<N; i++){
		long long t = (i%2==0)? 1: -1;
		t = (t*c(N, i))%mod;
		for(int j=0; j<P-M; j++){
			t = (t*(N-i-M))%mod;
		}
		for(int j=0; j<M; j++){
			t = (t*(N-i-j))%mod;
		}
		ans = (ans + t)%mod;
	}
	return ans;
}

// 538 2.2
string EvenRoute::isItPossible(vector <int> x, vector <int> y, int wantedParity) {
	for(int i=0; i<x.size(); i++){
		int t = abs(x[i])+abs(y[i]);
		if(t%2 == wantedParity){
			return "CAN";
		}
	}
	return "CANNOT";
}

// 366 2.2
// this wont work, since you have to accumulate the value from left all the way to right
int m;
int b;
vector<int> c;
int back(int n){
	if(n == c.size()){
		return 0;
	}
	int a[] = {c[n], -c[n]};
	int u = -1;
	for(int i=0; i<2; i++){
		int t = back(n+1);
		if(t!=-1 && t+b+a[i]>=0 && t+b+a[i]<=m && (u==-1 || t+b+a[i]>u)){
			u = t+b+a[i];
		}
	}
	cout << n <<' '<<u << endl;
	return u;
}
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	b = beginLevel;
	c = changeIntervals;
	m = maxLevel;
	return back(0);
}
// pure backtrack, tle
int m;
vector<int> c;
int back(int n, int d){
	if(d<0 || d>m){
		return -1;
	}
	if(n == c.size()){
		return d;
	}
	int a[] = {c[n], -c[n]};
	int u = -1;
	for(int i=0; i<2; i++){
		int t = back(n+1, d+a[i]);
		if(t!=-1){
			u = max(u, t);
		}
	}
	return u;
}
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	c = changeIntervals;
	m = maxLevel;
	return back(0, beginLevel);
}
// memorization
int m;
vector<int> c;
int memo[51][1001];
int back(int n, int d){
	if(d<0 || d>m){
		return -1;
	}
	if(memo[n][d] != -2){
		return memo[n][d];
	}
	if(n == c.size()){
		return memo[n][d] = d;
	}
	int a[] = {c[n], -c[n]};
	int u = -1;
	for(int i=0; i<2; i++){
		int t = back(n+1, d+a[i]);
		if(t!=-1){
			u = max(u, t);
		}
	}
	return memo[n][d] = u;
}
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	c = changeIntervals;
	m = maxLevel;
	for(int i=0; i<51; i++){
		for(int j=0; j<1001; j++){
			memo[i][j] = -2;
		}
	}
	return back(0, beginLevel);
}
int m;
vector<int> c;
int memo[51][1001];
int back(int n, int d){
	if(d<0 || d>m){
		return -1;
	}
	if(memo[n][d] != -2){
		return memo[n][d];
	}
	if(n == c.size()){
		return memo[n][d] = d;
	}
	int u = -1;
	u = max(u, back(n+1, d+c[n]));
	u = max(u, back(n+1, d-c[n]));
	return memo[n][d] = u;
}
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	c = changeIntervals;
	m = maxLevel;
	for(int i=0; i<51; i++){
		for(int j=0; j<1001; j++){
			memo[i][j] = -2;
		}
	}
	return back(0, beginLevel);
}
// memorization alternative
vector<int> c;
int m;
int memo[1001][51];
int go(int a, int n){
	int &re = memo[a][n];
	if(re != -2){
		return re;
	}
	if(n == c.size()){
		return re = a;
	}
	int b[] = {c[n], -c[n]};
	int u = -1;
	for(int i=0; i<2; i++){
		int t = a + b[i];
		if(t<=m && t>=0){
			u = max(u, go(t, n+1));
		}
	}
	return re = u;
}
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	c = changeIntervals;
	m = maxLevel;
	for(int i=0; i<1001; i++){
		for(int j=0; j<51; j++){
			memo[i][j] = -2;
		}
	}
	return go(beginLevel, 0);
}
// dynamic programming, from editorial
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	bool a[51][1001] = {false};
	a[0][beginLevel] = true;
	for(int i=0; i<changeIntervals.size(); i++){
		for(int j=0; j<=maxLevel; j++){
			if(a[i][j]){
				int b = j+changeIntervals[i];
				int c = j-changeIntervals[i];
				if(b <= maxLevel){
					a[i+1][b] = true;
				}
				if(c >= 0){
					a[i+1][c] = true;
				}
			}
		}
	}
	int ans = -1;
	for(int i=0; i<=maxLevel; i++){
		if(a[changeIntervals.size()][i]){
			ans = max(ans, i);
		}
	}
	return ans;
}
// alternative
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	int n = changeIntervals.size();
	bool dp[51][1001] = {false};
	dp[0][beginLevel] = true;
	for(int i=0; i<n; i++){
		for(int j=0; j<=maxLevel; j++){
			if(dp[i][j]){
				int a[] = {changeIntervals[i], -changeIntervals[i]};
				for(int k=0; k<2; k++){
					int t = j + a[k];
					if(t>=0 && t<=maxLevel){
						dp[i+1][t] = true;
					}
				}
			}
		}
	}
	int ans = -1;
	for(int i=0; i<1001; i++){
		if(dp[n][i]){
			ans = max(ans, i);
		}
	}
	return ans;
}
// dp from egor petr
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	vector<bool> v(maxLevel+1, false);
	v[beginLevel] = true;
	for(int i=0; i<changeIntervals.size(); i++){
		vector<bool> vv(maxLevel+1, false);
		for(int j=0; j<=maxLevel; j++){
			if(v[j]){
				int a = j+changeIntervals[i];
				int b = j-changeIntervals[i];
				if(a <= maxLevel){
					vv[a] = true;
				}
				if(b >= 0){
					vv[b] = true;
				}
			}
		}
		vv.swap(v);
	}
	for(int i=maxLevel; i>=0; i--){
		if(v[i]){
			return i;
		}
	}
	return -1;
}
// this will not work, since the value of vector may overlap
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	vector<int> v;
	v.push_back(beginLevel);
	for(int i=0; i<changeIntervals.size(); i++){
		vector<int> vv;
		for(int j=0; j<v.size(); j++){
			int a = v[j]+changeIntervals[i];
			int b = v[j]-changeIntervals[i];
			if(a <= maxLevel){
				vv.push_back(a);
			}
			if(b >= 0){
				vv.push_back(b);
			}
		}
		v = vv;
	}
	int ans = -1;
	for(int i=0; i<v.size(); i++){
		ans = max(ans, v[i]);
	}
	return ans;
}

// 547 2.2
// pure backtrack, tle
// not so good, since this one cache the answer to next level, which dont need
int ww;
vector<int> h;
double go(double a, int n, int b){
	if(n == h.size()){
		return a;
	}
	int c;
	if(b == 1){
		c = h[n-1];
	}else{
		c = 1;
	}
	double t = -1;
	t = max(t, go(a+sqrt((c-h[n])*(c-h[n])+ww*ww), n+1, 1));
	t = max(t, go(a+sqrt((c-1)*(c-1)+ww*ww), n+1, 0));
	return t;
}
double PillarsDivTwo::maximalLength(vector <int> height, int w) {
	h = height;
	ww = w;
	return max(go(0, 1, 1), go(0, 1, 0));
}
// correct memorization
// noted that cannot use memset on double
vector<int> h;
int ww;
double memo[51][2];
double go(int n, int l){
	if(n == h.size()){
		return 0;
	}
	if(memo[n][l] != -1){
		return memo[n][l];
	}
	int a[] = {1, h[n]};
	int b[] = {1, h[n-1]};
	double u = 0;
	for(int i=0; i<2; i++){
		u = max(u, go(n+1, i)*1.0 + sqrt(ww*ww+(a[i]-b[l])*(a[i]-b[l])));
	}
	return memo[n][l] = u;
}
double PillarsDivTwo::maximalLength(vector <int> height, int w) {
	h = height;
	ww = w;
	for(int i=0; i<51; i++){
		for(int j=0; j<2; j++){
			memo[i][j] = -1;
		}
	}
	return max(go(1, 0), go(1, 1));
}
// dp
double PillarsDivTwo::maximalLength(vector <int> height, int w) {
	double a[51][2] = {{0}};
	int n = height.size();
	for(int i=1; i<n; i++){
		for(int j=0; j<2; j++){
			int c;
			if(j==0){
				c = 1;
			}else{
				c = height[i-1];
			}
			a[i][1] = max(a[i][1], a[i-1][j] + sqrt((c-height[i])*(c-height[i])+w*w));
			a[i][0] = max(a[i][0], a[i-1][j] + sqrt((c-1)*(c-1)+w*w));
		}
	}
	return max(a[n-1][1], a[n-1][0]);
}
// alternative
double PillarsDivTwo::maximalLength(vector <int> height, int w) {
	int n = height.size();
	double dp[n][2];
	for(int i=0; i<n; i++){
		for(int j=0; j<2; j++){
			dp[i][j] = 0;
		}
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				int a[] = {1, height[i]};
				int b[] = {1, height[i-1]};
				dp[i][j] = max(dp[i][j], dp[i-1][k]+sqrt(w*w+(a[j]-b[k])*(a[j]-b[k])));
			}
		}
	}
	return max(dp[n-1][0], dp[n-1][1]);
}

// 607 2.2
// tle
int PalindromicSubstringsDiv2::expectedPalindromes(vector <string> S1, vector <string> S2) {
	string s;
	for(int i=0; i<S1.size(); i++){
		s += S1[i];
	}
	for(int i=0; i<S2.size(); i++){
		s += S2[i];
	}
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		string t;
		for(int j=i; j<s.size(); j++){
			t += s[j];
			string u = t;
			reverse(u.begin(), u.end());
			if(u == t){
				ans++;
			}
		}
	}
	return ans;
}
// wrong
int memo[5000][5001];
int PalindromicSubstringsDiv2::expectedPalindromes(vector <string> S1, vector <string> S2) {
	string s;
	for(int i=0; i<S1.size(); i++){
		s += S1[i];
	}
	for(int i=0; i<S2.size(); i++){
		s += S2[i];
	}
	memset(memo, -1, sizeof(memo));
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		for(int j=i; j<s.size(); j++){
			if(memo[i][j] == 1){
				ans++;
				continue;
			}
			if(memo[i][j] == 0){
				continue;
			}
			bool bo = true;
			for(int k=i, m=j; k<=m; k++, m--){
				if(s[k]!=s[m]){
					memo[k][m] = 0;
					bo = false;
					break;
				}
				memo[k][m] = 1;
			}
			if(bo){
				ans++;
			}
		}
	}
	return ans;
}
// use recursion with dp to check and record the palindrome substring
string s;
int memo[5001][5001];
int isp(int i, int j){
	if(i == j || i == j-1){
		return memo[i][j] = 1;
	}
	if(memo[i][j] != -1){
		return memo[i][j];
	}
	if(s[i] != s[j]){
		return memo[i][j] = 0;
	}
	return memo[i][j] = isp(i+1, j-1);
}
int PalindromicSubstringsDiv2::expectedPalindromes(vector <string> S1, vector <string> S2) {
	s = "";
	for(int i=0; i<S1.size(); i++){
		s += S1[i];
	}
	for(int i=0; i<S2.size(); i++){
		s += S2[i];
	}
	memset(memo, -1, sizeof(memo));
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		for(int j=i; j<s.size(); j++){
			if(isp(i, j)){
				ans++;
			}
		}
	}
	return ans;
}
// better approach
int PalindromicSubstringsDiv2::count(vector <string> S1, vector <string> S2) {
	string s;
	for(int i=0; i<S1.size(); i++){
		s += S1[i];
	}
	for(int j=0; j<S2.size(); j++){
		s += S2[j];
	}
	int n = s.size();
	int ans = 0;
	for(int i=0; i<n; i++){
		ans++;
		for(int j=1; i-j>=0 && i+j<n; j++){
			if(s[i-j] != s[i+j]){
				break;
			}
			ans++;
		}
	}
	for(int i=1; i<n; i++){
		for(int j=0; i-j-1>=0 && i+j<n; j++){
			if(s[i-j-1] != s[i+j]){
				break;
			}
			ans++;
		}
	}
	return ans;
}
// alternative
int PalindromicSubstringsDiv2::count(vector <string> S1, vector <string> S2) {
	string s;
	for(int i=0; i<S1.size(); i++){
		s += S1[i];
	}
	for(int j=0; j<S2.size(); j++){
		s += S2[j];
	}
	int n = s.size();
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<2; j++){
			int l;
			int r;
			if(j==0){
				l = i-1;
				r = i+1;
				ans++;
			}else{
				l = i-1;
				r = i;
			}
			while(l>=0 && r<n){
				if(s[l] != s[r]){
					break;
				}
				ans++;
				l--;
				r++;
			}
		}
	}
	return ans;
}

// 545 2.2
// one important property:
// when there is a group of n characters left,
// then picking the i-th lexicographically one as the first character increases the number of inverted pairs by i,
// regardless of the positions of the previous or next characters. 
// this will not work, since just move the letter to front n times is not enough
string m;
int x;
string back(string s, int c, int n){
	if(n==s.size()){
		if(c>=x && s>=m){
			return s;
		}
		return "";
	}
	string t;
	for(int i=0; i<s.size(); i++){
		if(i == n){
			t = s[i] + t;
		}else{
			t += s[i];
		}
	}
	string re = "";
	string a = back(s, c, n+1);
	if(a!=""){
		re = a;
	}
	string b = back(t, c+n, n+1);
	if(b!="" && (re=="" || b<re)){
		re = b;
	}
	return re;
}
string StrIIRec::recovstr(int n, int minInv, string minStr) {
	m = minStr;
	x = minInv;
	string a;
	for(int i=0; i<n; i++){
		a += 'a'+i;
	}
	return back(a, 0, 0);
}
// wrong greedy approach, since total inversion count != sum of substring inversion count
string StrIIRec::recovstr(int n, int minInv, string minStr) {
	vector<int> u(n);
	string t;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!u[j]){
				string r = t + (char)('a'+j);
				int c = 0;
				for(int i=0; i<r.size(); i++){
					for(int j=i+1; j<r.size(); j++){
						if(r[i]>r[j]){
							c++;
						}
					}
				}
				if(c+(n-r.size())*(n-r.size()-1)/2 >= minInv && 'a'+j >= minStr[i]){
					t = r;
					u[j] = 1;
					break;
				}
			}
		}
	}
	return t;
}
// correct greedy method
string StrIIRec::recovstr(int n, int minInv, string minStr) {
	vector<int> u(n);
	string t;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!u[j]){
				string r = t + (char)('a'+j);
				string p = r;
				for(int k=n-1; k>=0; k--){
					if(!u[k] && k!=j){
						p += (char)('a'+k);
					}
				}
				int c = 0;
				for(int i=0; i<p.size(); i++){
					for(int j=i+1; j<p.size(); j++){
						if(p[i]>p[j]){
							c++;
						}
					}
				}
				if(c >= minInv && p >= minStr){
					t = r;
					u[j] = 1;
					break;
				}
			}
		}
	}
	return t;
}
// pure backtrack, tle
int mi;
string ms;
string go(string s, int c, int n){
	if(n == s.size()){
		if(c>=mi && s>=ms){
			return s;
		}
		return "";
	}
	string u;
	for(int i=n; i<s.size(); i++){
		string t = go(s.substr(0, n)+s[i]+s.substr(n, i-n)+s.substr(i+1), c+i-n, n+1);
		if(t!="" && (u=="" || t<u)){
			u = t;
		}
	}
	return u;
}
string StrIIRec::recovstr(int n, int minInv, string minStr) {
	mi = minInv;
	ms = minStr;
	string s;
	for(int i=0; i<n; i++){
		s += 'a'+i;
	}
	return go(s, 0, 0);
}
// backtrack with bound, still tle
int mi;
string ms;
string go(string s, int c, int n){
	if(n == s.size()){
		return s;
	}
	string u;
	string r = s.substr(0, n);
	string msp = ms.substr(0, n+1);
	for(int i=n; i<s.size(); i++){
		if(r+s[i]>=msp && c+i-n+(s.size()-n-1)*(s.size()-n-2)/2>=mi){
			string t = go(r+s[i]+s.substr(n, i-n)+s.substr(i+1), c+i-n, n+1);
			if(t!="" && (u=="" || t<u)){
				u = t;
			}
		}
	}
	return u;
}
string StrIIRec::recovstr(int n, int minInv, string minStr) {
	mi = minInv;
	ms = minStr;
	string s;
	for(int i=0; i<n; i++){
		s += 'a'+i;
	}
	return go(s, 0, 0);
}
// brute force
// search from right most position for pair which is not inversion, then change it to be inversion
// since we start from right, so for each action, we will just increase total inversion count by one (if all charactor different)
// eg. 1243 -> 1342, inversion count: 2 -> 3
// you may wonder why will always increase one,
// why wouldnt it cause more change in inversion but just the increase the inversion of the swapped pair
// because we start from right most, so in the process, all the things between the the pair will be larger than the pair,
// like 1243, because if they are smaller, they will be swapped previously
string StrIIRec::recovstr(int n, int minInv, string minStr) {
	string t = minStr;
	for(int i=0; i<n; i++){
		if(t.find('a'+i)==string::npos){
			t += 'a'+i;
		}
	}
	while(1){
		int u = 0;
		for(int i=0; i<t.size(); i++){
			for(int j=i+1; j<t.size(); j++){
				if(t[i]>t[j]){
					u++;
				}
			}
		}
		if(u>=minInv){
			return t;
		}
		for(int i=t.size()-2; i>=0; i--){
			for(int j=t.size()-1; j>i; j--){
				if(t[i]<t[j]){
					swap(t[i], t[j]);
					goto stop;
				}
			}
		}
	stop:;
	}
	return "";
}

// 311 2.2
// this problem remind us to be careful about details in memorization:
// which is whether we need to cache the progress to next level call stack
// noted that we did not use the isb() function since is wrong because it think "0"<=""
// something like this will be correct for this question, but still com() is better
// bool isb(string a, string b){
// 	if(a==""){
// 		return false;
// 	}
// 	if(b==""){
// 		return true;
// 	}
// 	int t = abs((int)a.size() - (int)b.size());
// 	if(a.size() < b.size()){
// 		a = string(t, '0') + a;
// 	}else{
// 		b = string(t, '0') + b;
// 	}
// 	return a > b;
// }
vector<int> m;
int nn;
string memo[51];
bool isb(string a, string b){
	int t = abs((int)a.size() - (int)b.size());
	if(a.size() < b.size()){
		a = string(t, '0') + a;
	}else{
		b = string(t, '0') + b;
	}
	return a > b;
}
bool com(string a, string b){
	if(a.size() == b.size()){
		return a > b;
	}
	return a.size() > b.size();
}
string go(int c){
	if(memo[c] != ""){
		return memo[c];
	}
	string u;
	for(int i=0; i<m.size(); i++){
		if(c+m[i] <= nn && (c!=0 || (c==0 && i!=0))){
			string t = char('0'+i) + go(c+m[i]);
			if(com(t, u)){
				u = t;
			}
		}
	}
	return memo[c] = u;
}
string MatchNumbersEasy::maxNumber(vector <int> matches, int n) {
	m = matches;
	nn = n;
	for(int i=0; i<51; i++){
		memo[i] = "";
	}
	string t = go(0);
	if(t=="" && m[0]<=n){
		return "0";
	}
	return t;
}
// dynamic programming
bool isb(string& a, string& b){
	if(a.size() == b.size()){
		return a > b;
	}
	return a.size() > b.size();
}
string MatchNumbersEasy::maxNumber(vector <int> matches, int n) {
	vector<string> v(51);
	for(int i=1; i<matches.size(); i++){
		if(matches[i] <= n){
			v[matches[i]] = char('0'+i);
		}
	}
	while(1){
		bool bo = false;
		vector<string> vv(51);
		for(int i=0; i<v.size(); i++){
			if(v[i] != ""){
				for(int j=0; j<matches.size(); j++){
					int a = i+matches[j];
					if(a <= n){
						string b = v[i] + char('0'+j);
						if(isb(b, vv[a])){
							vv[a] = b;
							bo = true;
						}
					}
				}
			}
		}
		if(!bo){
			break;
		}
		v = vv;
	}
	string ans = *max_element(v.begin(), v.end());
	if(ans=="" && matches[0]<=n){
		ans = "0";
	}
	return ans;
}
// seems better dp
bool isb(string a, string b){
	return a.size()==b.size()? a>b: a.size()>b.size();
}
string MatchNumbersEasy::maxNumber(vector <int> matches, int n) {
	string ans = "";
	vector<string> dp(n+1);
	for(int i=1; i<matches.size(); i++){
		if(matches[i] <= n && isb(string(1, char('0'+i)), dp[matches[i]])){
			dp[matches[i]] = char('0'+i);
		}
	}
	while(1){
		vector<string> dd(n+1);
		bool bo = true;
		for(int i=0; i<=n; i++){
			if(dp[i] != ""){
				bool co = true;
				for(int j=0; j<matches.size(); j++){
					int a = i+matches[j];
					string b = dp[i] + char('0'+j);
					if(a<=n && isb(b, dd[a])){
						co = false;
						bo = false;
						dd[a] = b;
					}
				}
				if(co && isb(dp[i], ans)){
					ans = dp[i];
				}
			}
		}
		if(bo){
			break;
		}
		dp = dd;
	}
	if(ans=="" && matches[0]<=n){
		ans = "0";
	}
	return ans;
}

// 558 2.2
// tle
void back(string& s, vector<int>& v, vector<string>& u, int n){
	if(n == v.size()){
		u.push_back(s);
		return;
	}
	s[v[n]] = 'R';
	back(s, v, u, n+1);
	s[v[n]] = 'G';
	back(s, v, u, n+1);
	s[v[n]] = 'B';
	back(s, v, u, n+1);
}
int Stamp::getMinimumCost(string desiredColor, int stampCost, int pushCost) {
	bool bo = false;
	vector<int> v;
	for(int i=0; i<desiredColor.size(); i++){
		if(desiredColor[i] == '*'){
			bo = true;
			v.push_back(i);
		}
	}
	vector<string> u;
	if(bo){
		back(desiredColor, v, u, 0);
	}else{
		u.push_back(desiredColor);
	}
	int ans = numeric_limits<int>::max();
	for(int i=0; i<u.size(); i++){
		vector<int> c(u[i].size()+1);
		int a = 1;
		for(int j=0; j<u[i].size(); j++){
			if(j==u[i].size()-1 || u[i][j]!=u[i][j+1]){
				c[a]++;
				a = 1;
			}else{
				a++;
			}
		}
		int l = -1;
		int t = 0;
		for(int j=0; j<c.size(); j++){
			if(c[j]!=0){
				if(l == -1){
					l = j;
				}
				t += pushCost*c[j]*((j+l-1)/l);
			}
		}
		t += stampCost*l;
		ans = min(ans, t);
	}
	return ans;
}
// from editorial
// 7 111
// 1 001
// 2 010
// 4 100
#define oo 1000000000
int Stamp::getMinimumCost(string desiredColor, int stampCost, int pushCost) {
	int n = desiredColor.size();
	int a[n];
	for(int i=0; i<n; i++){
		char c = desiredColor[i];
		if(c == '*') a[i] = 7;
		if(c == 'R') a[i] = 1;
		if(c == 'G') a[i] = 2;
		if(c == 'B') a[i] = 4;
	}
	int res = oo;
	// try all possible value of stamp length
	for(int len=1; len<=n; len++){
		vector<int> count(n+1, oo);
		count[0] = 0;
		// foreach i, we record down all the valid position +1 after i
		// eg. if j is valid, we mark j+1 for j+1 after i, so that when i becomes j+1, it can continue the count
		for(int i=0; i<n; i++){
			int color = 7;
			for(int j=i; j<n; j++){
				color &= a[j];
				if(!color) break;
				int seg = j-i+1;
				if(seg < len) continue;
				if(count[i] != oo){
					count[j+1] = min(count[j+1], count[i]+(seg+len-1)/len);
				}
			}
		}
		if(count[n] != oo){
			res = min(res, count[n]*pushCost + stampCost*len);
		}
	}
	return res;
}
// other implementation by me, dont know if better
int Stamp::getMinimumCost(string desiredColor, int stampCost, int pushCost) {
	int n = desiredColor.size();
	int ans = numeric_limits<int>::max()/2;
	for(int len=1; len<=n; len++){
		vector<int> dp(n+1, numeric_limits<int>::max()/2);
		dp[0] = 0;
		for(int i=0; i<n; i++){
			char c = '*';
			for(int j=i; j<n; j++){
				if(c=='*' || desiredColor[j]=='*' || desiredColor[j]==c){
					int x = j-i+1;
					if(x >= len){
						dp[j+1] = min(dp[j+1], dp[i]+(x+len-1)/len);
					}
					if(desiredColor[j]!='*'){
						c = desiredColor[j];
					}
				}else{
					break;
				}
			}
		}
		if(dp[n]!=numeric_limits<int>::max()/2){
			ans = min(ans, dp[n]*pushCost+len*stampCost);
		}
	}
	return ans;
}
// memorization
int inf = 1e9;
map<string, int> m;
int l;
int go(string s){
	if(m.find(s) != m.end()){
		return m[s];
	}
	vector<int> r('Z'+1);
	int t = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i]!='*' && r[s[i]]==0){
			t++;
			r[s[i]] = 1;
		}
	}
	int u = inf;
	if(t <= 1){
		u = (s.size()+l-1)/l;
	}
	for(int i=1; i<s.size(); i++){
		if(i>=l && s.size()-i>=l){
			u = min(u, go(s.substr(0, i)) + go(s.substr(i)));
		}
	}
	return m[s] = u;
}
int Stamp::getMinimumCost(string desiredColor, int stampCost, int pushCost) {
	int n = desiredColor.size();
	int ans = inf;
	for(int i=1; i<=n; i++){
		m.clear();
		l = i;
		int a = go(desiredColor);
		if(a != inf){
			ans = min(ans, a*pushCost+i*stampCost);
		}
	}
	return ans;
}

// 340 2.2
// pure backtrack, tle
vector<int> p;
int v;
int go(int a, int b, int n){
	if(a-b >= v){
		return 0;
	}
	if(n >= p.size()){
		return -1;
	}
	int c = max(a, p[n]);
	int d = min(b, p[n]);
	int t = -1;
	int e = go(c, d, n+1);
	if(e!=-1){
		t = e+1;
	}
	int f = go(c, d, n+2);
	if(f!=-1 && (t==-1 || f<t)){
		t = f+1;
	}
	return t;
}
int ProblemsToSolve::minNumber(vector <int> pleasantness, int variety) {
	p = pleasantness;
	v = variety;
	int ans = go(-1, numeric_limits<int>::max()/2, 0);
	if(ans == -1){
		ans = pleasantness.size();
	}
	return ans;
}
// memory too large
vector<int> p;
int v;
int memo[1002][1002][60];
int go(int a, int b, int n){
	if(memo[a][b][n] != -2){
		return memo[a][b][n];
	}
	if(a-b >= v){
		return 0;
	}
	if(n >= p.size()){
		return -1;
	}
	int c = max(a, p[n]);
	int d = min(b, p[n]);
	int t = -1;
	int e = go(c, d, n+1);
	if(e!=-1){
		t = e+1;
	}
	int f = go(c, d, n+2);
	if(f!=-1 && (t==-1 || f<t)){
		t = f+1;
	}
	return memo[a][b][n] = t;
}
int ProblemsToSolve::minNumber(vector <int> pleasantness, int variety) {
	p = pleasantness;
	v = variety;
	for(int i=0; i<1002; i++){
		for(int j=0; j<1002; j++){
			for(int k=0; k<60; k++){
				memo[i][j][k] = -2;
			}
		}
	}
	int ans = go(0, 1001, 0);
	if(ans == -1){
		ans = pleasantness.size();
	}
	return ans;
}
// cache array position to avoid large value
vector<int> p;
int v;
int memo[60][60][60];
int go(int a, int b, int n){
	if(memo[a][b][n] != -2){
		return memo[a][b][n];
	}
	if(p[a]-p[b] >= v){
		return 0;
	}
	if(n >= p.size()){
		return -1;
	}
	int c = a;
	if(p[n] > p[a]){
		c = n;
	}
	int d = b;
	if(p[n] < p[b]){
		d = n;
	}
	int t = -1;
	int e = go(c, d, n+1);
	if(e!=-1){
		t = e+1;
	}
	int f = go(c, d, n+2);
	if(f!=-1 && (t==-1 || f<t)){
		t = f+1;
	}
	return memo[a][b][n] = t;
}
int ProblemsToSolve::minNumber(vector <int> pleasantness, int variety) {
	p = pleasantness;
	v = variety;
	for(int i=0; i<60; i++){
		for(int j=0; j<60; j++){
			for(int k=0; k<60; k++){
				memo[i][j][k] = -2;
			}
		}
	}
	int ans = go(0, 0, 0);
	if(ans == -1){
		ans = pleasantness.size();
	}
	return ans;
}
// dp
int ProblemsToSolve::minNumber(vector <int> pleasantness, int variety) {
	int n = pleasantness.size();
	int inf = 1000000000;
	int dp[51][51][51];
	for(int i=0; i<51; i++){
		for(int j=0; j<51; j++){
			for(int k=0; k<51; k++){
				dp[i][j][k] = inf;
			}
		}
	}
	dp[0][0][0] = 1;
	int ans = inf;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			for(int k=0; k<=i; k++){
				if(dp[i][j][k] != inf){
					if(pleasantness[j]-pleasantness[k]>=variety){
						ans = min(ans, dp[i][j][k]);
					}
					for(int l=1; l<=2; l++){
						if(i+l < n){
							int a = (pleasantness[i+l]>pleasantness[j])? i+l: j;
							int b = (pleasantness[i+l]<pleasantness[k])? i+l: k;
							dp[i+l][a][b] = min(dp[i+l][a][b], dp[i][j][k]+1);
						}
					}
				}
			}
		}
	}
	if(ans == inf){
		ans = pleasantness.size();
	}
	return ans;
}

// 522 1.1
// greedy
string RowAndCoins::getWinner(string cells) {
	int n = cells.size();
	int a = 0;
	int b = 0;
	for(int i=1; i<n; i++){
		if((cells[i]=='B' && cells[i-1]=='A') || (cells[i]=='A' && i==n-1)){
			a++;
		}
		if((cells[i]=='A' && cells[i-1]=='B') || (cells[i]=='B' && i==n-1)){
			b++;
		}
	}
	if(a >= b){
		return "Alice";
	}
	return "Bob";
}
// more greedy
string RowAndCoins::getWinner(string cells) {
	int n = cells.size();
	if(cells[0]=='A' || cells[n-1]=='A'){
		return "Alice";
	}
	return "Bob";
}
// bitmask dp wrong
string c;
int cn;
int go(int m, int n){
	char a;
	int t = 0;
	for(int i=0; i<cn; i++){
		if(m & (1<<i)){
			t++;
			a = c[i];
		}
	}
	if(t == cn-1){
		return a=='A';
	}
	for(int i=0; i<cn; i++){
		for(int j=i+1; j<=cn; j++){
			int u = (1<<j) - (1<<i);
			if((u&m)==0 && __builtin_popcount(u+m)!=cn){
				return go(m+u, 1-n);
			}
		}
	}
}
string RowAndManyCoins::getWinner(string cells) {
	c = cells;
	cn = cells.size();
	return go(0, 0)? "Alice": "Bob";
}
// correct
// each player try every possible move until he can win
// if whatever action the first player do cannot make him win, he lose
string c;
int cn;
int me[(1<<14)+1][2];
bool go(int m, int p){ // we need p because we need it to determine the final winning result
	int &re = me[m][p];
	if(re != -1){
		return re;
	}
	if(__builtin_popcount(m) == cn-1){
		for(int i=0; i<cn; i++){
			if(((m>>i)&1)==0 && (c[i]=='A' && p==0 || c[i]=='B' && p==1)){
				return re = true;
			}
		}
		return re = false;
	}
	for(int i=1; i<cn; i++){
		int mm = (1<<i)-1;
		for(int j=0; j<cn-i+1; j++){
			if((m&mm)==0 && __builtin_popcount(m|mm)!=cn){
				if(!go(m|mm, 1-p)){
					return re = true;
				}
			}
			mm <<= 1;
		}
	}
	return re = false;
}
string RowAndCoins::getWinner(string cells) {
	c = cells;
	cn = cells.size();
	memset(me, -1, sizeof(me));
	return go(0, 0)? "Alice": "Bob";
}

// 596 1.1
// tle
int inf = 1e9;
vector<int> d;
int dn;
map<vector<int>, int> me;
int go(vector<int>& v){
	if(me.find(v) != me.end()){
		return me[v];
	}
	if(v == d){
		return me[v] = 0;
	}
	int u = inf;
	for(int i=0; i<dn; i++){
		if(v[i]+1 <= d[i]){
			v[i]++;
			u = min(u, go(v) + 1);
			v[i]--;
		}
	}
	bool bo = true;
	int a = 0;
	for(int i=0; i<dn; i++){
		a += v[i];
		if(v[i]*2 > d[i]){
			bo = false;
		}
		v[i] *= 2;
	}
	if(bo && a>0){
		u = min(u, go(v) + 1);
	}
	for(int i=0; i<dn; i++){
		v[i] /= 2;
	}
	return me[v] = u;
}
int IncrementAndDoubling::getMin(vector <int> desiredArray) {
	me.clear();
	d = desiredArray;
	dn = desiredArray.size();
	vector<int> v(dn);
	return go(v);
}
// correct
// need to think in binary
// add 1 = add 1 bit
// times 2 = left shift 1
// minimum num to construct 111010011 = popcount(=add 1) + length-1(=left shift)
int IncrementAndDoubling::getMin(vector <int> desiredArray) {
	int dn = desiredArray.size();
	int m = 1;
	int u = 0;
	for(int i=0; i<dn; i++){
		int t = desiredArray[i];
		int a = 0;
		while(t > 0){
			a++;
			u += t%2;
			t /= 2;
		}
		m = max(m, a);
	}
	return m - 1 + u;
}

// 602 1.1
// wrong, miss one requirement from probelm
vector<int> d;
int isc(long long a, long long b){
	long long c = max(a, b);
	long long d = min(a, b);
	return c>=2200 && d<2200;
}
int go(long long c, int n){
	if(n == d.size()){
		return 0;
	}
	int u = 0;
	long long a[] = {c+d[n], max(c-d[n], (long long)0)};
	for(int i=0; i<2; i++){
		u = max(u, go(a[i], n+1) + isc(c, a[i]));
	}
	return u;
}
int TypoCoderDiv1::getmax(vector <int> D, int X) {
	d = D;
	return go(X, 0);
}
// correct
vector<int> d;
int dz;
int me[2201][51];
int go(int c, int n){
	int &re = me[c][n];
	if(re != -1){
		return re;
	}
	if(n == dz){
		return 0;
	}
	int u = 0;
	if(n < dz-1){
		int a = c + d[n];
		int b = max(0, a-d[n+1]);
		if(a>=2200 && b<2200){
			u = max(u, go(b, n+2) + 2);
		}else if(a<2200){
			u = max(u, go(a, n+1));
		}
		u = max(u, go(max(0, c-d[n]), n+1));
	}else if(n == dz-1){
		int a = c + d[n];
		if(a >= 2200){
			u = max(u, 1);
		}
	}
	return re = u;
}
int TypoCoderDiv1::getmax(vector <int> D, int X) {
	d = D;
	dz = D.size();
	memset(me, -1, sizeof(me));
	return go(X, 0);
}
// dp
int TypoCoderDiv1::getmax(vector <int> D, int X) {
	int n = D.size();
	int dp[51][2201];
	memset(dp, -1, sizeof(dp));
	dp[0][X] = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<2201; j++){
			if(dp[i][j] != -1){
				int a = j+D[i];
				int b = max(0, j-D[i]);
				if(i < n-1){
					int c = max(0, a-D[i+1]);
					if(a>=2200 && c<2200){
						dp[i+2][c] = max(dp[i+2][c], dp[i][j]+2);
					}
				}
				if(i==n-1 && a>=2200){
					dp[i+1][2200] = max(dp[i+1][2200], dp[i][j]+1);
				}
				if(a < 2200){
					dp[i+1][a] = max(dp[i+1][a], dp[i][j]);
				}
				dp[i+1][b] = max(dp[i+1][b], dp[i][j]);
			}
		}
	}
	int ans = -1;
	for(int i=0; i<2201; i++){
		ans = max(ans, dp[n][i]);
	}
	return ans;
}

// 412 1.1
// memorization
// a = last one, b = last last one
long long memo[4][4][31];
long long go(int a, int b, int n){
	long long &re = memo[a][b][n];
	if(re != -1){
		return re;
	}
	if(n == 0){
		return 1;
	}
	long long u = 0;
	if(a==b || a==0 || b==0){
		for(int i=1; i<=3; i++){
			u += go(i, a, n-1);
		}
	}else{
		for(int i=1; i<=3; i++){
			if(i==a || i==b){
				u += go(i, a, n-1);
			}
		}
	}
	return re = u;
}
long long ForbiddenStrings::countNotForbidden(int n) {
	memset(memo, -1, sizeof(memo));
	return go(0, 0, n);
}

// 626 2.2
// conditional probability
// A has a sided dice, B has b sided dice, know that A won, what is the expected value of A score
// = E(A roll 1 | A won) + E(A roll 2 | A won) + E(A roll 3 | A won) + ...
// = 1*P(A roll 1 | A won) + 2*P(A roll 2 | A won) + 3*P(A roll 3 | A won) + ...
// P(A roll 3 | A won) = number of situation A roll 3 / number of situation that A won
// = (A roll 3 and B roll 1) and (A roll 3 and B roll 2) / (A roll 2 and B roll 1) and (A roll 3 and B roll 1) and (A roll 3 and B roll 2) ...
double FixedDiceGameDiv2::getExpectation(int a, int b) {
	double u = 0;
	int t = 0;
	for(int i=1; i<=a; i++){ // foreach winning number that a got
		int r = 0;
		for(int j=1; j<=b; j++){ // foreach losing number that b got
			if(j < i){
				r++;
				t++;
			}
		}
		u += i*r;
	}
	if(t > 0){
		u /= t;
	}
	return u;
}
// run faster
double FixedDiceGameDiv2::getExpectation(int a, int b) {
	double u = 0;
	int t = 0;
	for(int i=1; i<=a; i++){
		int r = 0;
		for(int j=1; j<min(b+1, i); j++){
			r++;
			t++;
		}
		u += i*r;
	}
	if(t > 0){
		u /= t;
	}
	return u;
}
// even better
// have some concept of dp
double FixedDiceGameDiv2::getExpectation(int a, int b) {
	double u = 0;
	int t = 0;
	int x = 0;
	for(int i=1; i<=a; i++){
		u += i*x;
		t += x;
		if(i <= b){
			x++;
		}
	}
	if(t > 0){
		u /= t;
	}
	return u;
}

// 626 1.1
// conditional probability, dynamic programming dice throw problem, double to store large value
// for details best view egor answer
// logic correct but exceed limit
vector<double> go(int a, int b){
	vector<double> dp(a*b+1);
	dp[0] = 1;
	for(int i=0; i<a; i++){
		vector<double> dd(a*b+1);
		for(int j=0; j<a*b+1; j++){
			for(int k=1; k<=b && j+k<a*b+1; k++){
				dd[j+k] += dp[j];
			}
		}
		dp.swap(dd);
	}
	return dp;
}
double FixedDiceGameDiv1::getExpectation(int a, int b, int c, int d) {
	if(a*b <= c){
		return -1;
	}
	vector<double> x = go(a, b);
	vector<double> y = go(c, d);
	double e = 0;
	double f = 0;
	for(int i=2; i<=a*b; i++){
		int t = x[i];
		for(int j=1; j<min(i, c*d+1); j++){
			t *= y[j];
		}
		f += t;
		e += t*i;
	}
	return e*1.0/f;
}
// correct and better, a bit dp concept in variable g
vector<double> go(int a, int b){
	vector<double> dp(a*b+1);
	dp[0] = 1;
	for(int i=0; i<a; i++){
		vector<double> dd(a*b+1);
		for(int j=0; j<a*b+1; j++){
			for(int k=1; k<=b && j+k<a*b+1; k++){
				dd[j+k] += dp[j];
			}
		}
		dp.swap(dd);
	}
	return dp;
}
double FixedDiceGameDiv1::getExpectation(int a, int b, int c, int d) {
	if(a*b <= c){
		return -1;
	}
	vector<double> x = go(a, b);
	vector<double> y = go(c, d);
	double e = 0;
	double f = 0;
	double g = 0;
	for(int i=1; i<=a*b; i++){
		f += x[i]*g;
		e += x[i]*g*i;
		if(i <= c*d){
			g += y[i];
		}
	}
	return e*1.0/f;
}

// 647 1.1
// good question
// tle
vector<int> xx;
vector<int> tt;
int nn;
vector<int> vv;
map< pair<int, int>, int> m;
int go(int c, int n){
	pair<int, int> p = make_pair(c, n);
	if(m.find(p) != m.end()){
		return m[p];
	}
	if(n == nn){
		return c;
	}
	int a[] = {1, 0, -1};
	int u = -1;
	for(int i=0; i<3; i++){
		int t = c + a[i];
		if((vv[n]==-1 || t<=vv[n]) && t>=0){
			int r = go(t, n+1);
			if(r != -1){
				u = max(u, max(c, r));
			}
		}
	}
	return m[p] = u;
}
int BuildingTowersEasy::maxHeight(int N, vector <int> x, vector <int> t) {
	m.clear();
	nn = N;
	xx = x;
	tt = t;
	vector<int> v(N, -1);
	for(int i=0; i<x.size(); i++){
		v[x[i]-1] = t[i];
	}
	v[0] = 0;
	vv = v;
	return go(0, 0);
}
// learn from tourist
// pure coding
int BuildingTowersEasy::maxHeight(int N, vector <int> x, vector <int> t) {
	vector<int> v(N);
	int xn = x.size();
	int a = -1;
	int j = 0;
	for(int i=0; i<N; i++){
		a++;
		if(j<xn && x[j]-1==i){
			a = min(a, t[j]);
			j++;
		}
		v[i] = a;
	}
	a = 1e9;
	j = xn-1;
	for(int i=N-1; i>=0; i--){
		a++;
		if(j>=0 && x[j]-1==i){
			a = min(a, t[j]);
			j--;
		}
		v[i] = min(v[i], a);
	}
	int ans = -1;
	for(int i=0; i<v.size(); i++){
		ans = max(ans, v[i]);
	}
	return ans;
}
// learn from egor
int BuildingTowersEasy::maxHeight(int N, vector <int> x, vector <int> t) {
	vector<int> v(N);
	int xn = x.size();
	int a = -1;
	int j = 0;
	for(int i=0; i<N; i++){
		a++;
		if(j<xn && x[j]-1==i){
			a = min(a, t[j]);
			j++;
		}
		v[i] = a;
	}
	a = 1e9;
	j = xn-1;
	for(int i=N-1; i>=0; i--){
		a++;
		a = min(a, v[i]);
		v[i] = min(v[i], a);
	}
	return *max_element(v.begin(), v.end());
}

// 619 1.1
// for dp approach can view petr answer
string SplitStoneGame::winOrLose(vector <int> number) {
	int n = number.size();
	if(n<3 || accumulate(number.begin(), number.end(), 0) == n){
		return "LOSE";
	}
	return n%2==0? "LOSE": "WIN";
}
// dp game
// tle
vector<int> n;
int nn;
map< vector<int>, bool > me;
bool go(){
	if(me.find(n) != me.end()){
		return me[n];
	}
	for(int i=0; i<nn; i++){
		if(n[i] >= 2){
			for(int j=0; j<nn; j++){
				for(int k=0; k<nn; k++){
					if(i!=j && j!=k && k!=i && n[j]>0 && n[k]>0){
						for(int l=1; l<n[i]; l++){
							int t = n[i];
							n[i] = 0;
							n[j] += l;
							n[k] += t-l;
							bool bo = !go();
							n[i] = t;
							n[j] -= l;
							n[k] -= t-l;
							if(bo){
								return me[n] = true;
							}
						}
					}
				}
			}
		}
	}
	return me[n] = false;
}
string SplitStoneGame::winOrLose(vector <int> number) {
	me.clear();
	n = number;
	nn = number.size();
	return go()? "WIN": "LOSE";
}
// correct
int me[51][51];
bool go(int a, int b){ // a is number of ones in vector, b is number of num that larger than one
	int &re = me[a][b];
	if(re != -1){
		return re;
	}
	if(b >= 3 && !go(a, b-1)){ // split 1 b and put 2 half to 2 b
		return re = true;
	}
	if(a > 0 && b >= 2 && !go(a-1, b)){ // split 1 b and put 1 half to 1 a, 1 half to 1 b
		return re = true;
	}
	if(a >= 2 && b > 0 && !go(a-2, b+1)){ // split 1 b and put 2 half to 2 a
		return re = true;
	}
	return re = false;
}
string SplitStoneGame::winOrLose(vector <int> number) {
	int a = 0, b = 0;
	for(int i=0; i<number.size(); i++){
		if(number[i] >= 2){
			b++;
		}else{
			a++;
		}
	}
	memset(me, -1, sizeof(me));
	return go(a, b)? "WIN": "LOSE";
}

// 402 1.1
// dp with expected value
// tle
vector<int> p;
double go(int a, int c){
	vector< pair<int, int> > v;
	for(int i=0; i<p.size(); i++){
		for(int j=i+1; j<p.size(); j++){
			if(p[i] > p[j]){
				v.push_back(make_pair(i, j));
			}
		}
	}
	if(v.empty()){
		return a*1.0/c;
	}
	double u = 0;
	for(int i=0; i<v.size(); i++){
		swap(p[v[i].first], p[v[i].second]);
		u += go(a+1, c*v.size());
		swap(p[v[i].first], p[v[i].second]);
	}
	return u;
}
double RandomSort::getExpected(vector <int> permutation) {
	p = permutation;
	return go(0, 1);
}
// correct
// - expected value of the subtree
// eg. string x can evenly devide into 3 substring a, b, c
// if the process is recursive
// E(x) = a/(a+b+c)*(1+E(a)) + b/(a+b+c)*(1+E(b)) + c/(a+b+c)*(1+E(c))
// in 1+E(a), the one means it has already swap one, and then add the expected value of the subpart
// so 1+E(a) is the value (expected) to finish string a
// please reference the expected value of dice throw
map< vector<int>, double> m;
double go(){
	if(m.find(p) != m.end()){
		return m[p];
	}
	vector< pair<int, int> > v;
	for(int i=0; i<p.size(); i++){
		for(int j=i+1; j<p.size(); j++){
			if(p[i] > p[j]){
				v.push_back(make_pair(i, j));
			}
		}
	}
	if(v.empty()){
		return 0;
	}
	double u = 0;
	for(int i=0; i<v.size(); i++){
		swap(p[v[i].first], p[v[i].second]);
		u += (go()+1)/v.size();
		swap(p[v[i].first], p[v[i].second]);
	}
	return m[p] = u;
}
double RandomSort::getExpected(vector <int> permutation) {
	m.clear();
	p = permutation;
	return go();
}
// alternative
vector<int> p;
map< vector<int>, double> me;
double go(){
	if(me.find(p) != me.end()){
		return me[p];
	}
	vector<int> a;
	vector<int> b;
	for(int i=0; i<p.size(); i++){
		for(int j=i+1; j<p.size(); j++){
			if(p[i] > p[j]){
				a.push_back(i);
				b.push_back(j);
			}
		}
	}
	int n = a.size();
	if(n == 0){
		return 0;
	}
	double u = 0;
	for(int i=0; i<a.size(); i++){
		swap(p[a[i]], p[b[i]]);
		u += (go()+1)/n;
		swap(p[a[i]], p[b[i]]);
	}
	return me[p] = u;
}
double RandomSort::getExpected(vector <int> permutation) {
	me.clear();
	p = permutation;
	return go();
}

// 607 1.1
// recursive expected value, palindrome substring
// correct logic but tle
string s;
double go(int a, int b){
	if(s[a]!='?' && s[b]!='?' && s[a] != s[b]){
		return 0;
	}
	if(a==b || a+1==b){
		double t = 1;
		if(a+1 == b){
			if(s[a]=='?' || s[b]=='?')){
				t /= 26;
			}
		}
		return t;
	}
	int t = 1;
	if(s[a]=='?' || s[b]=='?'){
		t *= 26;
	}
	return go(a+1, b-1)/t;
}
double PalindromicSubstringsDiv1::expectedPalindromes(vector <string> S1, vector <string> S2) {
	s = "";
	for(int i=0; i<S1.size(); i++){
		s += S1[i];
	}
	for(int i=0; i<S2.size(); i++){
		s += S2[i];
	}
	double ans = 0;
	for(int i=0; i<s.size(); i++){
		for(int j=i; j<s.size(); j++){
			ans += go(i, j);
		}
	}
	return ans;
}
// correct, details check egor
double PalindromicSubstringsDiv1::expectedPalindromes(vector <string> S1, vector <string> S2) {
	string s;
	for(int i=0; i<S1.size(); i++){
		s += S1[i];
	}
	for(int i=0; i<S2.size(); i++){
		s += S2[i];
	}
	int n = s.size();
	double ans = 0;
	for(int i=0; i<n; i++){
		double t = 1;
		ans++;
		for(int j=1; i-j>=0 && i+j<n; j++){
			if(s[i-j]=='?' || s[i+j]=='?'){
				t /= 26;
			}else{
				if(s[i-j] != s[i+j]){
					break;
				}
			}
			ans += t;
		}
	}
	for(int i=1; i<n; i++){
		double t = 1;
		for(int j=0; i-j-1>=0 && i+j<n; j++){
			if(s[i-j-1]=='?' || s[i+j]=='?'){
				t /= 26;
			}else{
				if(s[i-j-1] != s[i+j]){
					break;
				}
			}
			ans += t;
		}
	}
	return ans;
}
// alternative
double PalindromicSubstringsDiv1::expectedPalindromes(vector <string> S1, vector <string> S2) {
	string s;
	s += accumulate(S1.begin(), S1.end(), string());
	s += accumulate(S2.begin(), S2.end(), string());
	int n = s.size();
	double ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<2; j++){
			int l;
			int r;
			if(j==0){
				l = i-1;
				r = i+1;
				ans++;
			}else{
				l = i-1;
				r = i;
			}
			double t = 1;
			while(l>=0 && r<n){
				if(s[l]=='?' || s[r]=='?'){
					t /= 26;
				}else{
					if(s[l] != s[r]){
						break;
					}
				}
				ans += t;
				l--;
				r++;
			}
		}
	}
	return ans;
}

// 460 1.1
// wrong
int TheQuestionsAndAnswersDivOne::find(int questions, vector <string> answers) {
	sort(answers.begin(), answers.end());
	int ans = 0;
	do{
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		for(int i=0; i<answers.size(); i++){
			if(i < questions){
				if(answers[i] == "Yes"){
					a++;
				}else{
					b++;
				}
			}else{
				if(answers[i] == "Yes"){
					c++;
				}else{
					d++;
				}
			}
		}
		if(c>a || d>b){
			continue;
		}
		int e = 1;
		for(int i=0; i<c; i++){
			e *= a;
		}
		int f = 1;
		for(int i=0; i<d; i++){
			e *= b;
		}
		ans += a*b*e*f;
	}while(next_permutation(answers.begin(), answers.end()));
	return ans;
}
// correct
// we return 1 or 0 rather than use go()+1, because if use go()+1, no matter what, it will count 1
// but if return 1 or 0, we can rule out those unsuccess things
vector<string> a;
int go(int t, int y, int n, int k){
	if(k == a.size()){
		if(t > 0){
			return 0;
		}else{
			return 1;
		}
	}
	int u = 0;
	if(t > 0){
		if(a[k] == "Yes"){
			u += t*go(t-1, y+1, n, k+1);
		}else{
			u += t*go(t-1, y, n+1, k+1);
		}
	}
	if(y > 0 && a[k]=="Yes"){
		u += y*go(t, y, n, k+1);
	}
	if(n > 0 && a[k]=="No"){
		u += n*go(t, y, n, k+1);
	}
	return u;
}
int TheQuestionsAndAnswersDivOne::find(int questions, vector <string> answers) {
	a = answers;
	return go(questions, 0, 0, 0);
}
// dp
int TheQuestionsAndAnswersDivOne::find(int questions, vector <string> answers) {
	int n = answers.size();
	int dp[10][10][10] = {0};
	dp[0][0][0] = 1;
	for(int i=0; i<n; i++){
		for(int j=0; j<=questions; j++){
			for(int k=0; k<=questions; k++){
				int t = questions - j - k;
				if(t > 0){
					if(answers[i] == "Yes"){
						dp[i+1][j+1][k] += t*dp[i][j][k];
					}else{
						dp[i+1][j][k+1] += t*dp[i][j][k];
					}
				}
				if(answers[i] == "Yes" && j > 0){
					dp[i+1][j][k] += j*dp[i][j][k];
				}
				if(answers[i] == "No" && k > 0){
					dp[i+1][j][k] += k*dp[i][j][k];
				}
			}
		}
	}
	int ans = 0;
	for(int i=0; i<=questions; i++){
		for(int j=0; j<=questions; j++){
			if(i + j == questions){
				ans += dp[n][i][j];
			}
		}
	}
	return ans;
}

// 249 1.1
// dp bitmask expected value
// memorization
int n;
vector<int> p;
double memo[1<<12+1];
double go(int m){
	double &re = memo[m];
	if(re != -1){
		return re;
	}
	double x = 0;
	for(int i=0; i<p.size(); i++){
		if(p[i] > 0){
			int t = i+1;
			int mm = (1<<t) - 1;
			int c = 0;
			double u = 0;
			for(int j=0; j<=n-t; j++){
				if((m & mm) == 0){
					u += go(m | mm);
					c++;
				}
				mm <<= 1;
			}
			if(c > 0){
				x += (u/c + t)*(p[i]/100.0);
			}
		}
	}
	return re = x;
}
double TableSeating::getExpected(int numTables, vector <int> probs) {
	p = probs;
	n = numTables;
	for(int i=0; i<=1<<12; i++){
		memo[i] = -1;
	}
	return go(0);
}
// detail
int ntable;
vector<int> pro;
double memo[1<<12+1];
double go(int mask){
	double &re = memo[mask];
	if(re != -1){
		return re;
	}
	double result = 0;
	for(int i=0; i<pro.size(); i++){
		if(pro[i] > 0){
			int want = i+1;
			int wantmask = (1 << want) - 1;
			int count = 0;
			double rest = 0;
			for(int j=0; j<=ntable-want; j++){
				if((mask & wantmask) == 0){
					rest += go(mask | wantmask);
					count++;
				}
				wantmask <<= 1;
			}
			if(count > 0){
				result += (want*1.0 + rest/count) * (pro[i]/100.0);
			}
		}
	}
	return re = result;
}
double TableSeating::getExpected(int numTables, vector <int> probs) {
	ntable = numTables;
	pro = probs;
	for(int i=0; i<=1<<12; i++){
		memo[i] = -1;
	}
	return go(0);
}
// more clear
int n;
vector<int> p;
double me[(1<<12)+1];
double go(int m){
	if(me[m] != -1){
		return me[m];
	}
	double u = 0;
	for(int i=0; i<p.size(); i++){
		if(p[i] != 0){
			int t = i+1;
			int mm = (1<<t) - 1;
			vector<int> v;
			for(int j=0; j<n-t+1; j++){
				if((m & mm) == 0){
					v.push_back(m|mm);
				}
				mm <<= 1;
			}
			for(int j=0; j<v.size(); j++){
				u += (t*1. + go(v[j]))/v.size()*p[i]/100;
			}
		}
	}
	return me[m] = u;
}
double TableSeating::getExpected(int numTables, vector <int> probs) {
	p = probs;
	n = numTables;
	for(int i=0; i<=1<<12; i++){
		me[i] = -1;
	}
	return go(0);
}

// 325 1.1
double FenceRepairing::calculateCost(vector <string> boards) {
	string s = accumulate(boards.begin(), boards.end(), string());
	vector<int> a;
	for(int i=0; i<s.size(); i++){
		if(s[i] == 'X'){
			a.push_back(i);
		}
	}
	int n = a.size();
	int inf = 1e9;
	double dp[2501];
	fill(dp, dp+2501, inf);
	dp[0] = 0;
	for(int i=0; i<n; i++){
		if(dp[i] != inf){
			for(int j=i; j<n; j++){
				dp[j+1] = min(dp[j+1], dp[i]+sqrt(a[j]-a[i]+1));
			}
		}
	}
	return dp[n];
}

// 565 1.1
// uncaught exception in topcoder server
int inf = 1e9;
vector<long long> d;
vector<int> p;
map< pair<long long, int>, int > memo;
int go(long long s, int n){
	pair<long long, int> m(s, n);
	if(memo.find(m) != memo.end()){
		return memo[m];
	}
	if(n == d.size()){
		return 0;
	}
	int u = inf;
	if(s >= d[n]){
		u = min(u, go(s, n+1));
	}
	u = min(u, go(s+d[n], n+1) + p[n]);
	return memo[m] = u;
}
int MonstersValley::minimumPrice(vector<long long> dread, vector <int> price) {
	memo.clear();
	d = dread;
	p = price;
	return go(0, 0);
}
// dp
// change perspective in dp
// instead of keep track of min price for each scariness, we keep track of max scariness for each price
int MonstersValley::minimumPrice(vector<long long> dread, vector <int> price) {
	long long dp[51][101];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int n = dread.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<=n*2; j++){
			if(dp[i][j] >= 0){
				int t = j + price[i];
				dp[i+1][t] = max(dp[i+1][t], dp[i][j] + dread[i]);
				if(dp[i][j] >= dread[i]){
					dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				}
			}
		}
	}
	for(int i=0; i<=n*2; i++){
		if(dp[n][i] >= 0){
			return i;
		}
	}
	return -1;
}

// 533 1.1
// divide and conquer dp
// tle
map< vector<int>, int> m;
int go(vector<int> v){
	if(m.find(v) != m.end()){
		return m[v];
	}
	if(v.size() == 2){
		return 0;
	}
	int u = -1;
	for(int i=1; i<v.size()-1; i++){
		vector<int> t(v.size()-1);
		for(int j=0; j<v.size(); j++){
			if(j < i){
				t[j] = v[j];
			}else if(j > i){
				t[j-1] = v[j];
			}
		}
		u = max(u, go(t) + v[i-1]*v[i+1]);
	}
	return m[v] = u;
}
int CasketOfStar::maxEnergy(vector <int> weight) {
	m.clear();
	return go(weight);
}
// divide and conquer from egor
vector<int> w;
int memo[50][50];
int go(int from, int to){
	int &re = memo[from][to];
	if(re != -1){
		return re;
	}
	if(from+1 == to){
		return 0;
	}
	int result = 0;
	for(int i=from+1; i<to; i++){
		result = max(result, go(from, i) + go(i, to) + w[from]*w[to]);
	}
	return re = result;
}
int CasketOfStar::maxEnergy(vector <int> weight) {
	w = weight;
	memset(memo, -1, sizeof(memo));
	return go(0, w.size()-1);
}
// from petr
int CasketOfStar::maxEnergy(vector <int> weight) {
	int n = weight.size();
	int best[50][50];
	memset(best, 0, sizeof(best));
	for(int len=2; len<=n; len++){
		for(int start=0; start+len<=n; start++){
			int a = start;
			int b = start + len - 1;
			for(int c=a+1; c<b; c++){
				best[a][b] = max(best[a][b], best[a][c] + best[c][b] + weight[a]*weight[b]);
			}
		}
	}
	return best[0][n-1];
}

// 557 1.1
// if each step you can +1 or -1, can you reach from h0 to hn in n steps
string FoxAndMountainEasy::possible(int n, int h0, int hn, string history) {
	int t = 0;
	for(int i=0; i<history.size(); i++){
		if(history[i] == 'U'){
			h0++;
		}else{
			h0--;
		}
		if(h0 < 0){
			h0++;
			t++;
		}
	}
	n -= history.size();
	n -= t;
	if(n < 0 || (n == 0 && h0 != hn)){
		return "NO";
	}
	for(int i=0; i<n; i++){
		if(h0 <= hn){
			h0++;
		}else{
			h0--;
		}
	}
	if(h0 != hn){
		return "NO";
	}
	return "YES";
}

// 296 1.1
int inf = 1e9;
vector<int> w;
int memo[101];
int go(int s){
	int &re = memo[s];
	if(re != -1){
		return re;
	}
	if(s == 0){
		return 0;
	}
	int u = inf;
	for(int i=0; i<w.size(); i++){
		if(s < w[i] && s%13 == 0){
			continue;
		}
		u = min(u, go(max(s-w[i], 0)) + 1);
	}
	return re = u;
}
int NewAlbum::leastAmountOfCDs(int nSongs, int length, int cdCapacity) {
	int t = 0;
	int c = 0;
	while(t+length<=cdCapacity && c+1<=nSongs){
		t += length + 1;
		c++;
	}
	if(c!=0 && c%13 == 0){
		c--;
	}
	vector<int> v;
	for(int i=1; i<=c; i++){
		if(i%13 != 0){
			v.push_back(i);
		}
	}
	w = v;
	memset(memo, -1, sizeof(memo));
	return go(nSongs);
}
// seems better
int m;
int memo[101];
int go(int n){
	int &re = memo[n];
	if(re != -1){
		return re;
	}
	if(n == 0){
		return 0;
	}
	int u = 1e9;
	for(int i=1; i<=min(n, m); i++){
		if(i%13 != 0){
			u = min(u, go(n-i) + 1);
		}
	}
	return re = u;
}
int NewAlbum::leastAmountOfCDs(int nSongs, int length, int cdCapacity) {
	m = (cdCapacity+1)/(length+1);
	memset(memo, -1, sizeof(memo));
	return go(nSongs);
}
// dp
int NewAlbum::leastAmountOfCDs(int nSongs, int length, int cdCapacity) {
	int inf = 1e9;
	int dp[101];
	fill(dp, dp+101, inf);
	dp[0] = 0;
	int m = (cdCapacity+1)/(length+1);
	for(int i=0; i<nSongs; i++){
		if(dp[i] != inf){
			for(int j=1; j<=min(m, nSongs-i); j++){
				if(j%13 != 0){
					dp[i+j] = min(dp[i+j], dp[i]+1);
				}
			}
		}
	}
	return dp[nSongs];
}
// dp slightly different from editorial
// foreach nsongs, we calculate its min num needed, not quite get all yet..
int NewAlbum::leastAmountOfCDs(int nSongs, int length, int cdCapacity) {
	int dp[101];
	int maxcap = (cdCapacity+1)/(length+1);
	for(int i=1; i<=nSongs; i++){
		dp[i] = 1e9;
		for(int j=1; j<=min(maxcap, i); j++){
			if(j%13 != 0){
				dp[i] = min(dp[i], 1 + dp[i-j]);
			}
		}
	}
	return dp[nSongs];
}

// 327 1.1
// wrong
bool isv(char c){
	return c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}
bool isc(char c){
	return c!='?' && !isv(c);
}
bool iv(char c){
	return c=='?' || isv(c);
}
bool ic(char c){
	return c=='?' || isc(c);
}
string NiceOrUgly::describe(string s) {
	int c = 0, v = 0;
	for(int i=0; i<s.size(); i++){
		if(i>=4 && isc(s[i-4]) && isc(s[i-3]) && isc(s[i-2]) && isc(s[i-1]) && isc(s[i])){
			c++;
		}
		if(i>=2 && isv(s[i]) && isv(s[i-1]) && isv(s[i-2])){
			v++;
		}
	}
	if(c || v){
		return "UGLY";
	}
	for(int i=0; i<s.size(); i++){
		for(int j=i; j<s.size(); j++){
			if(j-i+1 >= 5){
				bool bo = true;
				for(int k=i; k<=j; k++){
					if(s[k] != '?'){
						bo = false;
						break;
					}
				}
				if(bo){
					return "42";
				}
			}
		}
	}
	for(int i=0; i<s.size(); i++){
		if(i>=4 && ic(s[i-4]) && ic(s[i-3]) && ic(s[i-2]) && ic(s[i-1]) && ic(s[i])){
			c++;
		}
		if(i>=2 && iv(s[i]) && iv(s[i-1]) && iv(s[i-2])){
			v++;
		}
	}
	if(c>0 && v>0){
		return "UGLY";
	}else if(c>0 || v>0){
		return "42";
	}
	return "NICE";
}

// tco08 qual 1 div 1
// - first need to know the probability to get a head in toss until it get a head
// p(h) = p(t) + p(t)*p(h)
// - by the way, what is the expected value to get a head in coin tosses
// e(h) = p(t)*1 + p(t)*(1 + e(h))
// - so to deal with infinite recurring relation in recursion function, we can use the above technique
// 
// - explanation from topcoder forum
// from http://apps.topcoder.com/forums/?module=Thread&threadID=602003&start=0&mc=78
// It is possible to get a solution to work with a 2D memoized approach without making the assumption that the bunnies don't matter, you just have to be a little careful about the fact that if 2 bunnies meet (or if you meet a bunny and decide not to kill it), then you end up in the same state you're in at the moment. Your solution does something a little funny when 2 bunnies meet. The function logic should be something like:
// f(0,B) = 1.0 // no monsters left, so we survive
// f(1,B) = 0.0 // 1 monster left, so we always die
// f(M,0) = p(2 monsters) * f(M-2,0) // No bunnies left, so only consider monsters
// Now assume that if we meet a bunny at this step we will kill it
// fkill(M,B) = p(2 monsters)*f(M-2,B) + p(monster/bunny)*f(M,B-1) + p(us/bunny)*f(M,B-1) + p(2 bunnies)*f(M,B)
// Here we have f(M,B) on both sides of the equation, so we have to solve for it. I.e,
// fkill(M,B) = [ p(2 monsters)*f(M-2,B) + p(monster/bunny)*f(M,B-1) + p(us/bunny)*f(M,B-1) ] / [1.0 - p(2 bunnies)]
// Similarly,
// fdon't-kill(M,B) = [ p(2 monsters)*f(M-2,B) + p(monster/bunny)*f(M,B-1) ] / [1.0 - p(2 bunnies) - p(us/bunny)]
// and clearly
// f(M,B) = max(fdon't-kill , fkill)
// I think I would also have fluffed this problem if I had met it in the match. My intuition would have told me that the bunnies don't matter, but I never trust my intuition and would probably have tried to implement the above solution and made a mistake somewhere.
// Nasty problem for a 250! I think I would have rated this one at 350 and the 600-pointer at 500 (I don't really see what's hard about the 600).
// implementation of this idea
// other answer from antimatter http://community.topcoder.com/stat?c=problem_solution&rm=268829&rd=12007&pm=8595&cr=275071
// http://community.topcoder.com/stat?c=problem_solution&rm=268822&rd=12007&pm=8595&cr=22686851
// http://community.topcoder.com/stat?c=problem_solution&rm=268823&rd=12007&pm=8595&cr=22677785
double memo[1001][1001];
double go(int m, int b){
	if(m < 0 || b < 0){
		return 0;
	}
	if(m == 0){
		return 1;
	}
	if(memo[m][b] != -1){
		return memo[m][b];
	}
	int all = (m+b+1)*(m+b)/2;
	// the case we not kill bunny
	double x = 0;
	// 2 monsters
	x += m*(m-1)/2./all*go(m-2, b);
	// monster bunny
	x += m*b*1./all*go(m, b-1);
	// 2 bunnies and me bunny
	// because f(m, b) = p(2 monsters)*f(m-2, b) + p(monster bunny)*f(m, b-1) + p(2 bunnies)*f(m, b) + p(me bunny)*f(m, b)
	// so f(m, b) = [p(2 monsters)*f(m-2, b) + p(monster bunny)*f(m, b-1)] / (1 - p(2 bunnies) - p(me bunny))
	x /= 1. - b*(b-1)/2./all - b*1./all;
	// the case we kill bunny
	double y = 0;
	// 2 monsters
	y += m*(m-1)/2./all*go(m-2, b);
	// monster bunny
	y += m*b*1./all*go(m, b-1);
	// me bunny
	y += b*1./all*go(m, b-1);
	// bunny bunny
	y /= 1. - b*(b-1)/2./all;
	// choose better one
	return memo[m][b] = max(x, y);
}
double MonstersAndBunnies::survivalProbability(int M, int B) {
	for(int i=0; i<=M; i++){
		for(int j=0; j<=B; j++){
			memo[i][j] = -1;
		}
	}
	return go(M, B);
}

// TCCC '04 Wildcard
vector<string> a;
vector<string> d;
vector<bool> v;
string t;
map< pair<string, string>, bool > mok;
bool ok(string a, string b){
	if(a < b){
		swap(a, b);
	}
	pair<string, string> p(a, b);
	if(mok.find(p) != mok.end()){
		return mok[p];
	}
	vector<int> d;
	for(int i=0; i<a.size(); i++){
		if(a[i] != b[i]){
			d.push_back(i);
		}
	}
	if(d.size() == 1){
		return mok[p] = true;
	}
	if(d.size()==2 && a[d[0]]==b[d[1]] && a[d[1]]==b[d[0]]){
		return mok[p] = true;
	}
	return mok[p] = false;
}
map< vector<string>, vector<string> > mgo;
vector<string> go(){
	if(mgo.find(a) != mgo.end()){
		return mgo[a];
	}
	if(a.back() == t){
		return mgo[a] = a;
	}
	vector<string> u;
	for(int i=0; i<d.size(); i++){
		if(!v[i] && ok(a.back(), d[i])){
			a.push_back(d[i]);
			v[i] = 1;
			vector<string> t = go();
			if(u.empty() || t.size() < u.size() || t < u){
				u = t;
			}
			v[i] = false;
			a.pop_back();
		}
	}
	return mgo[a] = u;
}
vector <string> WordPuzzle::getConversions(vector <string> dictionary, string source, string target) {
	mok.clear();
	mgo.clear();
	dictionary.push_back(target);
	d = dictionary;
	a.clear();
	a.push_back(source);
	vector<bool> vv(d.size(), false);
	v = vv;
	t = target;
	vector<string> ans = go();
	return ans;
}
// top submission
bool cango(string &a, string &b){
	int x = -1;
	int y = -1;
	for(int i=0; i<a.size(); i++){
		if(a[i] != b[i]){
			if(x < 0){
				x = i;
			}else if(y < 0){
				y = i;
			}else{
				return false;
			}
		}
	}
	if(y < 0 || (a[x]==b[y] && a[y]==b[x])){
		return true;
	}
	return false;
}
vector <string> WordPuzzle::getConversions(vector <string> dictionary, string source, string target) {
	map< string, vector<string> > vr;
	sort(dictionary.begin(), dictionary.end());
	dictionary.push_back(source);
	vr[source].push_back(source);
	queue<string> qu;
	qu.push(source);
	while(!qu.empty()){
		string s = qu.front();
		qu.pop();
		if(cango(s, target)){
			vector<string> r = vr[s];
			r.push_back(target);
			return r;
		}
		for(int i=0; i<dictionary.size(); i++){
			if(!vr.count(dictionary[i]) && cango(s, dictionary[i])){
				qu.push(dictionary[i]);
				vr[dictionary[i]] = vr[s];
				vr[dictionary[i]].push_back(dictionary[i]);
			}
		}
	}
	return vector<string>();
}

// 501 1.1
// wrong, the outter loop is not needed
double dp[101][51][51];
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double sa = paramA/1000.;
	double sb = paramB/1000.;
	for(int i=0; i<=nA+nB; i++){
		for(int j=0; j<=nA; j++){
			for(int k=0; k<=nB; k++){
				dp[i][j][k] = -1e20;
			}
		}
	}
	dp[0][0][0] = 0;
	for(int i=0; i<nA+nB; i++){
		for(int j=0; j<nA; j++){
			for(int k=0; k<nB; k++){
				if(dp[i][j][k] != -1){
					if(i+1 <= nA){
						dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]+sa);
					}
					if(j+1 <=nB){
						dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]*sb);
					}
				}
			}
		}
	}
	return dp[nA+nB][nA][nB];
}
// also wrong, because the dp[i][j] with never reach dp[nA][nB]
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double sa = paramA/1000.;
	double sb = paramB/1000.;
	double dp[51][51];
	for(int i=0; i<=nA; i++){
		for(int j=0; j<=nB; j++){
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for(int i=0; i<nA; i++){
		for(int j=0; j<nB; j++){
			if(dp[i][j] != -1){
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]+sa);
				dp[i][j+1] = max(dp[i][j+1], dp[i][j]*sb);
			}
		}
	}
	return dp[nA][nB];
}
// wrong, not because of above two reason, but because the paramB may be negative value,
// so if you choose the max number in the middle state, the number you denied may become the maximum later on
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double sa = paramA/1000.;
	double sb = paramB/1000.;
	double dp[51][51];
	for(int i=0; i<=nA; i++){
		for(int j=0; j<=nB; j++){
			dp[i][j] = -1e20;
		}
	}
	dp[0][0] = 0;
	for(int i=0; i<=nA; i++){
		for(int j=0; j<=nB; j++){
			if(dp[i][j] != -1){ // acutally dont really need to initialize the dp to be -1 and also check whether is -1
				if(i+1 <= nA){
					dp[i+1][j] = max(dp[i+1][j], dp[i][j]+sa);
				}
				if(j+1 <= nB){
					dp[i][j+1] = max(dp[i][j+1], dp[i][j]*sb);
				}
			}
		}
	}
	return dp[nA][nB];
}
// wrong with similar approach, it is lazyly fill in dp table, like dp get binomial coef, previous we add value ahead of our current index
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double sa = paramA/1000.;
	double sb = paramB/1000.;
	double dp[51][51];
	for(int i=0; i<=nA; i++){
		for(int j=0; j<=nB; j++){
			dp[i][j] = -1e20;
		}
	}
	for(int i=0; i<=nB; i++){
		dp[0][i] = 0; // ensure the first column is all 0, since all of them is just the product of 0
	}
	for(int i=1; i<=nA; i++){
		dp[i][0] = dp[i-1][0] + sa; // fill int the first element in column, which is add by left row first element
		for(int j=1; j<=nB; j++){
			dp[i][j] = max(dp[i][j], dp[i-1][j]+sa);
			dp[i][j] = max(dp[i][j], dp[i][j-1]*sb);
		}
	}
	return dp[nA][nB];
}
// wrong, same reason with above one
int na;
int nb;
double sa;
double sb;
double me[51][51];
double go(int a, int b){
	double &re = me[a][b];
	if(re != -1){
		return re;
	}
	if(a==na && b==nb){
		return 0;
	}
	double u = -1e20;
	if(a+1 <= na){
		u = max(u, go(a+1, b)+sa);
	}
	if(b+1 <= nb){
		u = max(u, go(a, b+1)*sb);
	}
	return re = u;
}
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	for(int i=0; i<=nA; i++){
		for(int j=0; j<=nB; j++){
			me[i][j] = -1;
		}
	}
	sa = paramA/1000.;
	sb = paramB/1000.;
	na = nA;
	nb = nB;
	return go(0, 0);
}
// correct but tle
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double sa = paramA/1000.;
	double sb = paramB/1000.;
	set<double> dp[51][51];
	dp[0][0].insert(0);
	for(int i=0; i<=nA; i++){
		for(int j=0; j<=nB; j++){
			if(!dp[i][j].empty()){
				for(set<double>::iterator it=dp[i][j].begin(); it!=dp[i][j].end(); it++){
					if(i+1 <= nA){
						dp[i+1][j].insert(*it+sa);
					}
					if(j+1 <= nB){
						dp[i][j+1].insert(*it*sb);
					}
				}
			}
		}
	}
	return *max_element(dp[nA][nB].begin(), dp[nA][nB].end());
}
// correct
// approach 1
// a bit similar to IncrementAndDoubling
// first observed that it is better to add all together instead of all little and multiply
// second observed that you can multiply not exactly nB times, since multiply zero at first means nothing
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double sa = paramA/1000.;
	double sb = paramB/1000.;
	double t = sa*nA;
	double ans = t;
	for(int i=1; i<=nB; i++){
		t *= sb;
		ans = max(ans, t);
	}
	return ans;
}
// approach 2
// since if paramB is negative, the max value must be multiply by the previous max positive value or multiply by the previous min negative value
// so if we keep track of max and min for each state, we will be correct
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double inf = 1e20;
	double sa = paramA/1000.;
	double sb = paramB/1000.;
	double dpma[51][51]; // keep track of max
	double dpmi[51][51]; // keep track of min
	for(int i=0; i<=nA; i++){
		for(int j=0; j<=nB; j++){
			dpma[i][j] = -inf;
			dpmi[i][j] = inf;
		}
	}
	dpma[0][0] = 0;
	dpmi[0][0] = 0;
	for(int i=0; i<=nA; i++){
		for(int j=0; j<=nB; j++){
			if(dpma[i][j] != -inf && dpmi[i][j] != inf){
				if(i+1 <= nA){
					dpma[i+1][j] = max(dpma[i+1][j], dpma[i][j]+sa); // update max by previous max
					dpma[i+1][j] = max(dpma[i+1][j], dpmi[i][j]+sa); // update max by previous min
					dpmi[i+1][j] = min(dpmi[i+1][j], dpma[i][j]+sa); // update min by previous max
					dpmi[i+1][j] = min(dpmi[i+1][j], dpmi[i][j]+sa); // update min by previous min
				}
				if(j+1 <= nB){
					dpma[i][j+1] = max(dpma[i][j+1], dpma[i][j]*sb); // update max by previous max
					dpma[i][j+1] = max(dpma[i][j+1], dpmi[i][j]*sb); // update max by previous min
					dpmi[i][j+1] = min(dpmi[i][j+1], dpma[i][j]*sb); // update min by previous max
					dpmi[i][j+1] = min(dpmi[i][j+1], dpmi[i][j]*sb); // update min by previous min
				}
			}
		}
	}
	return dpma[nA][nB];
}
// alternative dp implementation
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double inf = 1e20;
	double sa = paramA/1000.;
	double sb = paramB/1000.;
	double dpma[51][51];
	double dpmi[51][51];
	for(int i=0; i<=nA; i++){
		for(int j=0; j<=nB; j++){
			dpma[i][j] = -inf;
			dpmi[i][j] = inf;
		}
	}
	for(int i=0; i<=nB; i++){
		dpma[0][i] = 0;
		dpmi[0][i] = 0;
	}
	for(int i=1; i<=nA; i++){
		dpma[i][0] = max(dpma[i-1][0]+sa, dpmi[i-1][0]+sa);
		dpmi[i][0] = min(dpma[i-1][0]+sa, dpmi[i-1][0]+sa);
		for(int j=1; j<=nB; j++){
			dpma[i][j] = max(dpma[i][j], dpma[i-1][j]+sa);
			dpma[i][j] = max(dpma[i][j], dpmi[i-1][j]+sa);
			dpmi[i][j] = min(dpmi[i][j], dpma[i-1][j]+sa);
			dpmi[i][j] = min(dpmi[i][j], dpmi[i-1][j]+sa);
			dpma[i][j] = max(dpma[i][j], dpma[i][j-1]*sb);
			dpma[i][j] = max(dpma[i][j], dpmi[i][j-1]*sb);
			dpmi[i][j] = min(dpmi[i][j], dpma[i][j-1]*sb);
			dpmi[i][j] = min(dpmi[i][j], dpmi[i][j-1]*sb);
		}
	}
	return dpma[nA][nB];
}
// similar but even better, just like the previous wrong approach that mentioned binomial coef
double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
	double inf = 1e20;
	double sa = paramA/1000.;
	double sb = paramB/1000.;
	double dpma[51][51];
	double dpmi[51][51];
	for(int i=0; i<=nB; i++){
		dpma[0][i] = 0;
		dpmi[0][i] = 0;
	}
	for(int i=1; i<=nA; i++){
		dpma[i][0] = max(dpma[i-1][0]+sa, dpmi[i-1][0]+sa);
		dpmi[i][0] = min(dpma[i-1][0]+sa, dpmi[i-1][0]+sa);
		for(int j=1; j<=nB; j++){
			dpma[i][j] = max(dpma[i-1][j]+sa, dpmi[i-1][j]+sa);
			dpmi[i][j] = min(dpma[i-1][j]+sa, dpmi[i-1][j]+sa);
			dpma[i][j] = max(dpma[i][j-1]*sb, dpmi[i][j-1]*sb);
			dpmi[i][j] = min(dpma[i][j-1]*sb, dpmi[i][j-1]*sb);
		}
	}
	return dpma[nA][nB];
}

// TCO06 Semi 2 1.1
// correct in test case, wrong on system test
int xx;
map< pair<string, string>, int > me;
int go(string a, string b) {
	pair<string, string> pa(a, b);
	if (me.find(pa) != me.end()) {
		return me[pa];
	}
	if (a.empty() || b.empty()) {
		return max(a.size(), b.size()) + xx;
	}
	if (a.empty() && b.empty()) {
		return 0;
	}
	int u = 1e9;
	int t = 0;
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		if (a[i] != b[i]) {
			break;
		}
		t++;
	}
	if (t > 0) {
		u = min(u, go(a.substr(t), b.substr(t)));
	} else {
		for (int i = 0; i < a.size(); i++) {
			if (b[0] == a[i]) {
				u = min(u, go(a.substr(i), b) + xx + i);
			}
		}
		u = min(u, go(string(), b) + xx + (int)a.size());
		for (int i = 0; i < b.size(); i++) {
			if (a[0] == b[i]) {
				u = min(u, go(a, b.substr(i)) + xx + i);
			}
		}
		u = min(u, go(a, string()) + xx + (int)b.size());
	}
	return me[pa] = u;
}
int Alignment::align(string A, string B, int x) {
	me.clear();
	xx = x;
	return go(A, B);
}
// correct
// from misof
int xx;
map< pair<string, string>, int > me;
int go(string a, string b){
	pair<string, string> p(a, b);
	if(me.find(p) != me.end()){
		return me[p];
	}
	if(a.empty()){
		return xx + b.size();
	}
	if(b.empty()){
		return xx + a.size();
	}
	if(a == b){
		return 0;
	}
	int u = 1e9;
	for(int i=1; i<=a.size(); i++){
		u = min(u, go(a.substr(i), b) + xx + i);
	}
	for(int i=1; i<=b.size(); i++){
		u = min(u, go(a, b.substr(i)) + xx + i);
	}
	for(int i=0; i<a.size() && i<b.size() && a[i]==b[i]; i++){
		u = min(u, go(a.substr(i+1), b.substr(i+1)));
	}
	return me[p] = u;
}
int Alignment::align(string A, string B, int x) {
	me.clear();
	xx = x;
	return go(A, B);
}

// TCO '03 Semifinals 3 1.1
string o;
string r;
string s;
bool is(string &a, string &b){
	int c = a.size();
	int d = -1;
	int e = b.size();
	int f = -1;
	for(int i=0; i<a.size(); i++){
		if(a[i] != '.'){
			c = min(c, i);
			d = max(d, i);
		}
	}
	for(int i=0; i<b.size(); i++){
		if(b[i] != '.'){
			e = min(e, i);
			f = max(f, i);
		}
	}
	if(d-c != f-e){
		return d-c < f-e;
	}
	return a < b;
}
string go(int n){
	if(n == r.size()){
		return s;
	}
	string u;
	for(int i=o.size()-1; i>=0 && s[i]=='.'; i--){
		if(o[i] == r[n]){
			s[i] = r[n];
			string t = go(n+1);
			if(u.empty() || is(t, u)){
				u = t;
			}
			s[i] = '.';
		}
	}
	return u;
}
string MakeUnique::eliminated(string original) {
	o = original;
	r = original;
	sort(r.begin(), r.end());
	r.erase(unique(r.begin(), r.end()), r.end());
	s = string(original.size(), '.');
	return go(0);
}

// TCO 2014 Semifinal 2 1.1
// wrong
int h;
int w;
int mod = 1e9 + 7;
vector< vector<bool> > v;
map< vector< vector<bool> >, int> me;
int go(int c){
	if(me.find(v) != me.end()){
		return me[v];
	}
	if(c == 0){
		return 1;
	}
	int u = 0;
	for(int i=0; i<2*h-1; i++){
		for(int j=0; j<w; j++){
			bool bo = true;
			int b = 0;
			for(int k=0; k<h && i+k<2*h-1; k++){
				if(v[i+k][j]){
					bo = false;
					break;
				}
				b++;
			}
			if(bo && b==h){
				for(int k=0; k<h && i+k<2*h-1; k++){
					v[i+k][j] = true;
				}
				u = (u + go(c-h)) % mod;
				for(int k=0; k<h && i+k<2*h-1; k++){
					v[i+k][j] = false;
				}
			}
			bo = true;
			b = 0;
			for(int k=0; k<h && j+k<w; k++){
				if(v[i][j+k]){
					bo = false;
					break;
				}
				b++;
			}
			if(bo && b==h){
				for(int k=0; k<h && j+k<w; k++){
					v[i][j+k] = true;
				}
				u = (u + go(c-h)) % mod;
				for(int k=0; k<h && j+k<w; k++){
					v[i][j+k] = false;
				}
			}
		}
	}
	return me[v] = u;
}
int PlankTiling::sumup(int H, int W) {
	me.clear();
	v = vector< vector<bool> >(2*H-1, vector<bool>(W));
	h = H;
	w = W;
	return go((2*H-1)*W);
}

// TCCC05 Wildcard 1.1
// wrong
// missing something in if condition
map<string, string> me;
string go(string s){
	if(me.find(s) != me.end()){
		return me[s];
	}
	int n = s.size();
	if(n == 1){
		return s;
	}
	string u;
	for(int i=1; i<n; i++){
		if(n%i == 0){
			bool bo = true;
			for(int j=0; j<n; j++){
				if(s[j] != s[j%i]){
					bo = false;
					break;
				}
			}
			if(bo){
				stringstream ss;
				string r = go(s.substr(0, i));
				if(r.size() > 1){
					r = "(" + r + ")";
				}
				ss << n/i << r;
				string t = ss.str();
				if(u.empty() || t.size()<u.size() || t<u){ // miss something here
					u = t;
				}
			}
		}
	}
	if(u.empty()){
		for(int i=1; i<n; i++){
			string t = go(s.substr(0, i)) + go(s.substr(i));
			if(u.empty() || t.size()<u.size() || t<u){ // miss something here
				u = t;
			}
		}
	}
	return me[s] = u;
}
string RunLengthPlus::compress(string s) {
	me.clear();
	return go(s);
}
// correct
map<string, string> me;
string go(string s){
	if(me.find(s) != me.end()){
		return me[s];
	}
	int n = s.size();
	if(n == 1){
		return s;
	}
	string u;
	for(int i=1; i<n; i++){
		if(n%i == 0){
			bool bo = true;
			for(int j=0; j<n; j++){
				if(s[j] != s[j%i]){
					bo = false;
					break;
				}
			}
			if(bo){
				stringstream ss;
				string r = go(s.substr(0, i));
				if(r.size() > 1){
					r = "(" + r + ")";
				}
				ss << n/i << r;
				string t = ss.str();
				if(u.empty() || t.size()<u.size() || (t.size()==u.size() && t<u)){
					u = t;
				}
			}
		}
	}
	if(u.empty()){
		for(int i=1; i<n; i++){
			string t = go(s.substr(0, i)) + go(s.substr(i));
			if(u.empty() || t.size()<u.size() || (t.size()==u.size() && t<u)){
				u = t;
			}
		}
	}
	return me[s] = u;
}
string RunLengthPlus::compress(string s) {
	me.clear();
	return go(s);
}

// TCO10 Wildcard 1.1
// wrong and tle
int SequencePermutation::determineConfigurations(int N, int M) {
	int mod = 1e9 + 9;
	vector<int> v(N);
	for(int i=0; i<N; i++){
		v[i] = i;
	}
	map< vector<int>, int> dp;
	dp[v] = 1;
	for(int i=0; i<M; i++){
		map< vector<int>, int> next;
		for(map< vector<int>, int>::iterator it=dp.begin(); it!=dp.end(); it++){
			vector<int> t = it->first;
			for(int i=1; i<N; i++){
				swap(t[i], t[i-1]);
				if(next.find(t) == next.end()){
					next[t] = 0;
				}
				next[t] = (next[t] + it->second) % mod;
				swap(t[i], t[i-1]);
			}
		}
		dp.swap(next);
	}
	int ans = 0;
	for(map< vector<int>, int>::iterator it=dp.begin(); it!=dp.end(); it++){
		ans = (ans + it->second) % mod;
	}
	return ans;
}

// TCO10 Round 4 1.1
// correct but tle
int w;
double go(int a, int b, int c){
	if(c == 0){
		return 0;
	}
	double u = 0;
	u += (w*1. + go(a+w, b, c-1))*a/(a+b);
	u += go(a, b+w, c-1)*b/(a+b);
	return u;
}
double BankLottery::expectedAmount(vector <int> accountBalance, int weeklyJackpot, int weekCount) {
	w = weeklyJackpot;
	int b = 0;
	for(int i=1; i<accountBalance.size(); i++){
		b += accountBalance[i];
	}
	return accountBalance[0]*1. + go(accountBalance[0], b, weekCount);
}
// correct but poor structured
int w;
int all;
int cc;
int aa;
double me[1001][1001];
double go(int a, int c){
	double &re = me[a][c];
	if(re != -1){
		return re;
	}
	if(c == cc){
		return 0;
	}
	double u = 0;
	int al = all + c*w;
	int aaa = aa + w*a;
	u += (w*1. + go(a+1, c+1))*aaa/al;
	u += go(a, c+1)*(al-aaa)/al;
	return re = u;
}
double BankLottery::expectedAmount(vector <int> accountBalance, int weeklyJackpot, int weekCount) {
	w = weeklyJackpot;
	cc = weekCount;
	all = accumulate(accountBalance.begin(), accountBalance.end(), 0);
	aa = accountBalance[0];
	for(int i=0; i<=1000; i++){
		for(int j=0; j<=1000; j++){
			me[i][j] = -1;
		}
	}
	return accountBalance[0]*1. + go(0, 0);
}
// detail
int weekc;
int weekj;
int total;
int me;
double memo[1001][1001];
double go(int numwin, int numweek){
	double &re = memo[numwin][numweek];
	if(re != -1){
		return re;
	}
	if(numweek == weekc){
		return 0;
	}
	int ntotal = total + numweek*weekj;
	int nme = me + numwin*weekj;
	int other = ntotal - nme;
	double res = 0;
	res += (weekj*1. + go(numwin+1, numweek+1))*nme/ntotal; // case i win
	res += go(numwin, numweek+1)*other/ntotal; // case other win
	return re = res;
}
double BankLottery::expectedAmount(vector <int> accountBalance, int weeklyJackpot, int weekCount) {
	weekj = weeklyJackpot;
	weekc = weekCount;
	total = accumulate(accountBalance.begin(), accountBalance.end(), 0);
	me = accountBalance[0];
	for(int i=0; i<=1000; i++){
		for(int j=0; j<=1000; j++){
			memo[i][j] = -1;
		}
	}
	return me*1. + go(0, 0);
}

// TCCC '04 Round 4 1.1
// tle
// because ajacent is not allowed, so this kind of dp has looped many unused elements, unlike normal knapsack style one
vector<int> d;
int dn;
vector<bool> v;
map< vector<bool>, int > me;
int go(){
	if(me.find(v) != me.end()){
		return me[v];
	}
	int u = -1;
	int c = 0;
	for(int i=0; i<dn; i++){
		if(!v[(i+dn-1)%dn] && !v[(i+1)%dn] && !v[i]){
			v[i] = true;
			u = max(u, go() + d[i]);
			v[i] = false;
			c++;
		}
	}
	if(c == 0){
		return 0;
	}
	return me[v] = u;
}
int BadNeighbors::maxDonations(vector <int> donations) {
	me.clear();
	d = donations;
	dn = donations.size();
	v = vector<bool>(dn);
	return go();
}
// correct
int me[40][2];
int go(vector<int> &d, int n, bool last){
	int &re = me[n][last];
	if(re != -1){
		return re;
	}
	if(n == d.size()){
		return 0;
	}
	int u = -1;
	if(!last){
		u = max(u, go(d, n+1, true) + d[n]);
	}
	u = max(u, go(d, n+1, false));
	return re = u;
}
int BadNeighbors::maxDonations(vector <int> donations) {
	vector<int> a(donations.begin(), donations.end()-1); // produce 2 vector because of circular
	vector<int> b(donations.begin()+1, donations.end());
	memset(me, -1, sizeof(me));
	int c = go(a, 0, false);
	memset(me, -1, sizeof(me));
	int d = go(b, 0, false);
	return max(c, d);
}
// similar
vector<int> d;
int me[40][2];
int go(int n, bool last){
	int &re = me[n][last];
	if(re != -1){
		return re;
	}
	if(n == d.size()){
		return 0;
	}
	int u = -1;
	if(!last){
		u = max(u, go(n+1, true) + d[n]);
	}
	u = max(u, go(n+1, false));
	return re = u;
}
int BadNeighbors::maxDonations(vector <int> donations) {
	d = vector<int>(donations.begin(), donations.end()-1);
	memset(me, -1, sizeof(me));
	int ans = go(0, false);
	d = vector<int>(donations.begin()+1, donations.end());
	memset(me, -1, sizeof(me));
	ans = max(ans, go(0, false));
	return ans;
}

// TCO07 Round 4
map<string, long long> me;
bool iso(char c){
	return c=='+'||c=='-'||c=='/'||c=='*';
}
bool isnum(string &s){
	for(int i=1; i<s.size(); i++){
		if(!isdigit(s[i])){
			return false;
		}
	}
	if(isdigit(s[0]) || (s[0]=='-' && s.size()!=1)){
		return true;
	}
	return false;
}
long long go(string s){
	if(me.find(s) != me.end()){
		return me[s];
	}
	long long u = 0;
	if(isnum(s)){
		u++;
	}
	if(s.size() >= 3 && iso(s[0])){
		for(int i=1; i<s.size()-1; i++){
			u += go(s.substr(1, i))*go(s.substr(i+1));
		}
	}
	return me[s] = u;
}
long long PolishNotation::waysToDecode(string expression) {
	me.clear();
	return go(expression);
}
// better
string e;
long long me[50][50];
long long go(int a, int b){
	long long &re = me[a][b];
	if(re != -1){
		return re;
	}
	long long u = 0;
	bool bo = true;
	for(int i=a+1; i<=b; i++){
		if(!isdigit(e[i])){
			bo = false;
			break;
		}
	}
	if(bo && (isdigit(e[a]) || (e[a]=='-' && a<b))){
		u++;
	}
	if(b-a+1>=3 && (e[a]=='+' || e[a]=='-' || e[a]=='*' || e[a]=='/')){
		for(int i=a+1; i<b; i++){
			u += go(a+1, i) * go(i+1, b);
		}
	}
	return re = u;
}
long long PolishNotation::waysToDecode(string expression) {
	e = expression;
	memset(me, -1, sizeof(me));
	return go(0, expression.size()-1);
}

// TCO06 Round 3 1.1
// dp game
vector<int> t;
int me[100001];
bool go(int c){
	int &re = me[c];
	if(re != -1){
		return re;
	}
	if(c == 0){
		return re = false;
	}
	for(int i=0; i<t.size(); i++){
		if(t[i] <= c && !go(c-t[i])){
			return re = true;
		}
	}
	return re = false;
}
int LastStone::numWins(vector <int> turns, int m, int n) {
	t = turns;
	memset(me, -1, sizeof(me));
	int ans = 0;
	for(int i=m; i<=n; i++){
		if(go(i)){
			ans++;
		}
	}
	return ans;
}

// TCCC '04 Semifinals 1 1.1
// recursion memorization, not so good and uncaught exception
// this type of question dp is better
int wei;
vector<int> cw;
vector<int> cv;
set<int> me[2501][101];
set<int> go(int v, int w){
	set<int> &re = me[v][w];
	if(!re.empty()){
		return re;
	}
	if(w == wei){
		set<int> s;
		s.insert(v);
		return s;
	}
	set<int> u;
	for(int i=0; i<cw.size(); i++){
		if(w+cw[i] <= wei){
			set<int> t = go(v+cv[i], w+cw[i]);
			u.insert(t.begin(), t.end());
		}
	}
	return re = u;
}
int CoinWeight::possibleValues(int weight, vector <string> coins) {
	cw.clear();
	cv.clear();
	wei = weight;
	for(int i=0; i<=2500; i++){
		for(int j=0; j<=100; j++){
			me[i][j].clear();
		}
	}
	for(int i=0; i<coins.size(); i++){
		int a, b, c;
		stringstream ss(coins[i]);
		ss >> a >> b >> c;
		for(int j=b; j<=c; j++){
			cw.push_back(j);
			cv.push_back(a);
		}
	}
	return go(0, 0).size();
}
// dp bottom up
int CoinWeight::possibleValues(int weight, vector <string> coins) {
	vector<int> w;
	vector<int> v;
	for(int i=0; i<coins.size(); i++){
		int a, b, c;
		stringstream ss(coins[i]);
		ss >> a >> b >> c;
		for(int j=b; j<=c; j++){
			w.push_back(j);
			v.push_back(a);
		}
	}
	int n = w.size();
	bool dp[2501][101];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = true;
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
	int ans = 0;
	for(int i=0; i<=2500; i++){
		if(dp[i][weight]){
			ans++;
		}
	}
	return ans;
}
// dp bottom up alternative
int CoinWeight::possibleValues(int weight, vector <string> coins) {
	vector<int> w;
	vector<int> v;
	for(int i=0; i<coins.size(); i++){
		int a, b, c;
		stringstream ss(coins[i]);
		ss >> a >> b >> c;
		for(int j=b; j<=c; j++){
			w.push_back(j);
			v.push_back(a);
		}
	}
	int n = w.size();
	bool dp[2501][101];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = true;
	for(int i=0; i<=2500; i++){
		for(int j=0; j<=weight; j++){
			for(int k=0; k<n; k++){
				if(i-v[k]>=0 && j-w[k]>=0 && dp[i-v[k]][j-w[k]]){
					dp[i][j] = true;
				}
			}
		}
	}
	int ans = 0;
	for(int i=0; i<=2500; i++){
		if(dp[i][weight]){
			ans++;
		}
	}
	return ans;
}
// dp alternative, similar to the first one, but the while one loop is not nessasary
int CoinWeight::possibleValues(int weight, vector <string> coins) {
	vector<int> w;
	vector<int> v;
	for(int i=0; i<coins.size(); i++){
		int a, b, c;
		stringstream ss(coins[i]);
		ss >> a >> b >> c;
		for(int j=b; j<=c; j++){
			w.push_back(j);
			v.push_back(a);
		}
	}
	int n = w.size();
	vector< set<int> > dp(weight + 1);
	dp[0].insert(0);
	while(1){
		bool bo = true;
		for(int i=0; i<=weight; i++){
			for(set<int>::iterator it=dp[i].begin(); it!=dp[i].end(); it++){
				for(int j=0; j<n; j++){
					int nw = i+w[j];
					int nv = *it+v[j];
					if(nw <= weight && dp[nw].find(nv) == dp[nw].end()){
						dp[nw].insert(nv);
						bo = false;
					}
				}
			}
		}
		if(bo){
			break;
		}
	}
	return dp[weight].size();
}
// previous alternative
int CoinWeight::possibleValues(int weight, vector <string> coins) {
	vector<int> w;
	vector<int> v;
	for(int i=0; i<coins.size(); i++){
		int a, b, c;
		stringstream ss(coins[i]);
		ss >> a >> b >> c;
		for(int j=b; j<=c; j++){
			w.push_back(j);
			v.push_back(a);
		}
	}
	int n = w.size();
	set<int> dp[101];
	dp[0].insert(0);
	for(int i=0; i<weight; i++){
		for(set<int>::iterator it=dp[i].begin(); it!=dp[i].end(); it++){
			for(int j=0; j<n; j++){
				int nw = i + w[j];
				int nv = *it + v[j];
				if(nw <= weight){
					dp[nw].insert(nv);
				}
			}
		}
	}
	return dp[weight].size();
}

// TCO11 Round 5
// normal dp game
string w;
vector<bool> v;
int n;
map< pair< vector<bool>, int>, bool> me;
bool go(int p){
	pair< vector<bool>, int> pa(v, p);
	if(me.find(pa) != me.end()){
		return me[pa];
	}
	bool &re = me[pa];
	if(v[n-1]){
		string t = w;
		for(int i=n-1; i>=0; i--){
			if(v[i]){
				t.erase(i, 1); // erase is faster than plainly add character by experiment
			}
		}
		if(t > w && p==0 || t<=w && p==1){
			return re = true;
		}else{
			return re = false;
		}
	}
	for(int i=n-1; i>=0 && !v[i]; i--){
		v[i] = true;
		if(!go(1-p)){
			v[i] = false;
			return re = true;
		}
		v[i] = false;
	}
	return re = false;
}
string SistersErasingLetters::whoWins(string word) {
	me.clear();
	w = word;
	n = word.size();
	v = vector<bool>(word.size());
	return go(0)? "Camomile": "Romashka";
}
// seems better, idea from editorial
// in memorization, you can concat them as key
string w;
map<string, bool> me;
bool go(string p, string s, bool f){
	string ke = p + " " + s + " " + (f?"1":"2"); // remember to add brackets
	if(me.find(ke) != me.end()){
		return me[ke];
	}
	bool &re = me[ke];
	bool bo = true;
	for(int i=0; i<p.size(); i++){
		if(p[i] != w[i]){
			bo = false;
			break;
		}
	}
	if(s.empty() || !bo){
		if(f && p>w || !f && p<=w){
			return re = true;
		}
		return re = false;
	}
	for(int i=0; i<s.size(); i++){
		if(!go(p+s.substr(0, i), s.substr(i+1), !f)){
			return re = true;
		}
	}
	return re = false;
}
string SistersErasingLetters::whoWins(string word) {
	w = word;
	return go("", word, true)? "Camomile": "Romashka";
}
// detail
string w;
map<string, bool> memo;
bool go(string prefix, string suffix, bool player){
	string key = prefix + " " + suffix + " " + (player?"1":"2");
	if(memo.find(key) != memo.end()){
		return memo[key];
	}
	bool &re = memo[key];
	bool match = true;
	for(int i=0; i<prefix.size(); i++){
		if(prefix[i] != w[i]){
			match = false;
			break;
		}
	}
	if(!match || suffix.empty()){
		if(player && prefix > w || !player && prefix <= w){
			return re = true;
		}
		return re = false;
	}
	for(int i=0; i<suffix.size(); i++){
		if(!go(prefix + suffix.substr(0, i), suffix.substr(i+1), !player)){
			return re = true;
		}
	}
	return re = false;
}
string SistersErasingLetters::whoWins(string word) {
	w = word;
	return go("", word, true)? "Camomile": "Romashka";
}

// TCCC '03 Semifinals 1 1.1
vector <int> TCU::majors(vector <string> percentages, vector <int> start, int years) {
	int n = start.size();
	vector< vector<int> > p(n, vector<int>(n));
	for(int i=0; i<n; i++){
		stringstream ss(percentages[i]);
		for(int j=0; j<n; j++){
			ss >> p[i][j];
		}
	}
	for(int i=0; i<years; i++){
		vector<int> v(n);
		for(int j=0; j<n; j++){ // foreach major j
			int t = start[j];
			for(int k=0; k<n; k++){ // foreach major k
				int r = start[j]*p[j][k]/100;
				v[k] += r; // trans from j to k
				t -= r; // r left j
			}
			v[j] += t; // add remaining back to j
		}
		start.swap(v);
	}
	return start;
}

// TCCC '03 Semifinals 3 1.1
// similar to dp classic problem longest increasing subsequence
int ZigZag::longestZigZag(vector <int> sequence) {
	int n = sequence.size();
	int dp[51][2];
	for(int i=0; i<n; i++){
		for(int j=0; j<2; j++){
			dp[i][j] = 1;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(sequence[j]-sequence[i] > 0){
				dp[j][0] = max(dp[j][0], dp[i][1]+1);
			}
			if(sequence[j]-sequence[i] < 0){
				dp[j][1] = max(dp[j][1], dp[i][0]+1);
			}
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<2; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}

// TCCC05 Finals 1.1
// main logic
// tle
string a;
string b;
long long go(string s, int n){
	if(s.find(a) != string::npos || s.find(b) != string::npos){
		return 0;
	}
	if(n == 0){
		return 1;
	}
	return go(s+"A", n-1) + go(s+"B", n-1) + go(s+"C", n-1);
}
long long BadSubstrings::howMany(int N, string bad1, string bad2) {
	a = bad1;
	b = bad2;
	return go("", N);
}
// concept should be almost correct, but tle
// used the concept of kmp, which keep track of the longest prefix suffix
string a;
string b;
map< pair<string, int>, long long > me;
string lps(string &x, string &y) {
	for (int i = min(x.size(), y.size()); i >= 0; i--) {
		if (x.substr(x.size() - i) == y.substr(0, i)) {
			return y.substr(0, i);
		}
	}
	return "";
}
long long go(string s, int n) {
	pair<string, int> pa(s, n);
	if (me.find(pa) != me.end()) {
		return me[pa];
	}
	if (s == a || s == b) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	long long u = 0;
	string c[] = {"A", "B", "C"};
	for (int i = 0; i < 3; i++) {
		string t = s + c[i];
		string p = lps(t, a);
		string q = lps(t, b);
		u += go(a.size() - p.size() < b.size() - q.size()? p: q, n - 1);
	}
	return me[pa] = u;
}
long long BadSubstrings::howMany(int N, string bad1, string bad2) {
	me.clear();
	a = bad1;
	b = bad2;
	return go("", N);
}

// TCO11 Championship Round 1.1
// dp game winning probability
// idea from acrush
int n;
int m;
int b[21][21];
double memo[41][1000];
bool visited[41][1000];
double go(int r, int diff) { // if r % 2 == 0, it is the probability of Dick win, otherwise is Jane
	if (r == 0) {
		if (diff == 0) {
			return 0.5;
		}
		if (diff > 0) {
			return 1;
		}
		return 0;
	}
	if (visited[r][diff + 500]) { // plus 500 just for prevent negative index
		return memo[r][diff + 500];
	}
	visited[r][diff + 500] = true;
	double res = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			double temp = 0;
			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					temp += (1. - go(r - 1, -(diff + b[i+k][j+l]))) / 9;
				}
			}
			res = max(res, temp);
		}
	}
	return memo[r][diff + 500] = res;
}
double PerfectlyFairGame::winChance(vector <string> board, int darts) {
	n = board.size();
	m = board[0].size();
	for (int i = 0; i< n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = board[i][j] - '0';
		}
	}
	memset(visited, 0, sizeof(visited));
	return 1. - go(darts*2, 0); // 1 - max probability of opponent's win
}

// 435 2.2
vector< vector<int> > c;
int go(int n) {
	if (c[n].empty()) {
		return 1;
	}
	int u = 0;
	for (int i = 0; i < c[n].size(); i++) {
		u += go(c[n][i]);
	}
	return u;
}
int CellRemoval::cellsLeft(vector <int> parent, int deletedCell) {
	int n = parent.size();
	vector< vector<int> > c(n, vector<int>());
	for (int i = 0; i < n; i++) {
		if (parent[i] != -1 && i != deletedCell) {
			c[parent[i]].push_back(i);
		}
	}
	::c = c;
	int z = find(parent.begin(), parent.end(), -1) - parent.begin();
	if (z == deletedCell) {
		return 0;
	}
	return go(z);
}
// alternative
int CellRemoval::cellsLeft(vector <int> parent, int deletedCell) {
	int ans = 0;
	int n = parent.size();
	for (int i = 0; i < n; i++) {
		bool bo = true;
		int j = i;
		while (j != -1) {
			if (j == deletedCell) {
				bo = false;
			}
			j = parent[j];
		}
		for (int j = 0; j < n; j++) {
			if (parent[j] == i) {
				bo = false;
			}
		}
		if (bo) {
			ans++;
		}
	}
	return ans;
}

// 612 1.1
// we can notice that the number of smiles will never need to exceed the target smiles
// we cannot use memorization just with 2 states, since it has a loop
// dp shortest path, tle
int inf = 0x40404040;
int dp[1001][1001];
int EmoticonsDiv1::printSmiles(int smiles) {
	memset(dp, 0x40, sizeof(dp));
	dp[0][1] = 0;
	while (1) {
		bool bo = true;
		for (int i = 0; i < smiles; i++) {
			for (int j = 0; j < smiles; j++) {
				if (dp[i][j] != inf) {
					int t = dp[i][j] + 1;
					if (t < dp[j][j]) {
						bo = false;
						dp[j][j] = t;
					}
					if (j + i <= smiles && t < dp[i][j + i]) {
						bo = false;
						dp[i][j + i] = t;
					}
					if (j - 1 >= 0 && t < dp[i][j - 1]) {
						bo = false;
						dp[i][j - 1] = t;
					}
				}
			}
		}
		if (bo) {
			break;
		}
	}
	int ans = inf;
	for (int i = 0; i < smiles; i++) {
		ans = min(ans, dp[i][smiles]);
	}
	return ans;
}
// bfs
int v[1001][1001];
int EmoticonsDiv1::printSmiles(int smiles) {
	memset(v, -1, sizeof(v));
	queue< pair<int, int> > q;
	v[0][1] = 0;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int c = q.front().first;
		int t = q.front().second;
		q.pop();
		if (t == smiles) {
			return v[c][t];
		}
		if (v[t][t] == -1) {
			v[t][t] = v[c][t] + 1;
			q.push(make_pair(t, t));
		}
		if (t + c <= smiles && v[c][t + c] == -1) {
			v[c][t + c] = v[c][t] + 1;
			q.push(make_pair(c, t + c));
		}
		if (t - 1 >= 0 && v[c][t - 1] == -1) {
			v[c][t - 1] = v[c][t] + 1;
			q.push(make_pair(c, t - 1));
		}
	}
	return -1;
}
// alternative
int v[1001][1001];
int EmoticonsDiv1::printSmiles(int smiles) {
	memset(v, -1, sizeof(v));
	queue<int> q;
	v[0][1] = 0;
	q.push(0);
	q.push(1);
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		int t = q.front();
		q.pop();
		if (t == smiles) {
			return v[c][t];
		}
		if (v[t][t] == -1) {
			v[t][t] = v[c][t] + 1;
			q.push(t);
			q.push(t);
		}
		if (t + c <= smiles && v[c][t + c] == -1) {
			v[c][t + c] = v[c][t] + 1;
			q.push(c);
			q.push(t + c);
		}
		if (t - 1 >= 0 && v[c][t - 1] == -1) {
			v[c][t - 1] = v[c][t] + 1;
			q.push(c);
			q.push(t - 1);
		}
	}
	return -1;
}

// 519 2.2
// dp find shortest path in graph
// wrong because it is the case that the teleport is only one direction
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	vector< vector<int> > t(3, vector<int>(4));
	for (int i = 0; i < 3; i++) {
		sscanf(teleports[i].c_str(), "%d %d %d %d", &t[i][0], &t[i][1], &t[i][2], &t[i][3]);
	}
	int g[5][5];
	memset(g, -1, sizeof(g));
	g[3][4] = abs(xMe - xHome) + abs(yMe - yHome);
	for (int i = 0; i < 3; i++) {
		g[3][i] = abs(xMe - t[i][0]) + abs(yMe - t[i][1]);
	}
	for (int i = 0; i < 3; i++) {
		g[i][4] = abs(t[i][2] - xHome) + abs(t[i][3] - yHome) + 10;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) {
				g[i][j] = abs(t[i][2] - t[j][0]) + abs(t[i][3] - t[j][1]) + 10;
			}
		}
	}
	int inf = 0x40404040;
	int dp[5];
	memset(dp, 0x40, sizeof(dp));
	dp[3] = 0;
	while (1) {
		bool bo = true;
		for (int i = 0; i < 5; i++) {
			if (dp[i] != inf) {
				for (int j = 0; j < 5; j++) {
					if (g[i][j] != -1) {
						int t = dp[i] + g[i][j];
						if (t < dp[j]) {
							bo = false;
							dp[j] = t;
						}
					}
				}
			}
		}
		if (bo) {
			break;
		}
	}
	return dp[4];
}
// dp shortest path, but then i found that it is bellman ford algorithm
// wrong, should be something wrong with constructing graph
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	int t[3][4];
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		for (int j = 0; j < 4; j++) {
			ss >> t[i][j];
		}
	}
	int g[8][8];
	memset(g, -1, sizeof(g));
	g[6][7] = d(xMe, yMe, xHome, yHome);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			g[6][i * 2 + j] = d(xMe, yMe, t[i][2 * j], t[i][2 * j + 1]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			g[i * 2 + j][7] = d(t[i][2 * j], t[i][2 * j + 1], xHome, yHome);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[i * 2][i * 2 + 1] = 10;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 2; l++) {
					if (i != k) {
						g[i * 2 + j][k * 2 + l] = d(t[i][2 * j], t[i][2 * j + 1], t[k][2 * l], t[k][2 * l + 1]);
					}
				}
			}
		}
	}
	long long inf = 0x4040404040404040;
	long long dp[8];
	memset(dp, 0x40, sizeof(dp));
	dp[6] = 0;
	while (1) {
		bool bo = true;
		for (int i = 0; i < 8; i++) {
			if (dp[i] != inf) {
				for (int j = 0; j < 8; j++) {
					if (g[i][j] != -1) {
						int t = dp[i] + g[i][j];
						if (t < dp[j]) {
							bo = false;
							dp[j] = t;
						}
					}
				}
			}
		}
		if (bo) {
			break;
		}
	}
	return dp[7];
}
// dp shortest path (bellman ford algorithm), but this time construct graph correct
int d(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	long long inf = 0x1010101010101010;
	long long dp[8];
	memset(dp, 0x10, sizeof(dp));
	dp[0] = 0;
	while (1) { // this can be improved to do at most 8 - 1 operations
		bool bo = true;
		for (int i = 0; i < 8; i++) {
			if (dp[i] != inf) {
				for (int j = 0; j < 8; j++) {
					long long t = dp[i] + g[i][j];
					if (t < dp[j]) {
						bo = false;
						dp[j] = t;
					}
				}
			}
		}
		if (bo) {
			break;
		}
	}
	return dp[1];
}
// floyd warshall shortest path algorithm
int d(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	for (int k = 0; k < 8; k++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	return g[0][1];
}
// dijkstra algorithm without priority queue
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	long long inf = 0x1010101010101010;
	bool v[8];
	memset(v, 0, sizeof(v));
	long long d[8];
	memset(d, 0x10, sizeof(d));
	d[0] = 0;
	for (int i = 0; i < 7; i++) {
		int n = -1;
		for (int j = 0; j < 8; j++) {
			if ((n == -1 || d[j] < d[n]) && !v[j]) {
				m = d[j];
				n = j;
			}
		}
		if (n == -1) {
			break;
		}
		v[n] = true;
		for (int j = 0; j < 8; j++) {
			d[j] = min(d[j], d[n] + g[n][j]);
		}
	}
	return d[1];
}
// dijkstra with set
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
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
				if (d[i] != inf) {
					s.erase(s.find(make_pair(d[i], i)));
				}
				d[i] = t;
				s.insert(make_pair(t, i));
			}
		}
	}
	return d[1];
}
// dijkstra with set alternative, i think is cleaner
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	long long inf = 0x1010101010101010;
	long long d[8];
	memset(d, 0x10, sizeof(d));
	d[0] = 0;
	set< pair<long long, int> > s;
	s.insert(make_pair(0, 0));
	while (!s.empty()) {
		int n = s.begin()->second;
		int nd = s.begin()->first;
		s.erase(s.begin());
		if (nd <= d[n]) {
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
}
// bellman ford
int d(int a, int b, int x, int y){
	return abs(a - x) + abs(b - y);
}
int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
	pair<int, int> p[8];
	p[0].first = xMe;
	p[0].second = yMe;
	p[1].first = xHome;
	p[1].second = yHome;
	for (int i = 0; i < 3; i++) {
		stringstream ss(teleports[i]);
		ss >> p[2 * i + 2].first >> p[2 * i + 2].second;
		ss >> p[2 * i + 3].first >> p[2 * i + 3].second;
	}
	long long g[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			g[i][j] = d(p[i], p[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		g[2 * i + 2][2 * i + 3] = g[2 * i + 3][2 * i + 2] = min(10LL, g[2 * i + 2][2 * i + 3]);
	}
	long long inf = 0x1010101010101010;
	long long d[8];
	memset(d, 0x10, sizeof(d));
	d[0] = 0;
	for (int i = 0; i < 8 - 1; i++) {
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
}

// 397 2.2
// dp, similar to bellman ford
int SortingGame::fewestMoves(vector <int> board, int k) {
	vector<int> f(board);
	sort(f.begin(), f.end());
	if (f == board) {
		return 0;
	}
	map< vector<int>, int> dp;
	dp[board] = 0;
	int n = board.size();
	while (true) {
		bool bo = true;
		for (map< vector<int>, int>::iterator it = dp.begin(); it != dp.end(); it++) {
			vector<int> t(it->first);
			for (int i = 0; i < n - k + 1; i++) {
				reverse(t.begin() + i, t.begin() + i + k);
				if (dp.find(t) != dp.end()) {
					int r = it->second + 1;
					if (r < dp[t]) {
						dp[t] = r;
						bo = false;
					}
				} else {
					bo = false;
					dp[t] = it->second + 1;
				}
				reverse(t.begin() + i, t.begin() + i + k);
			}
		}
		if (bo) {
			break;
		}
	}
	int ans = -1;
	if (dp.find(f) != dp.end()) {
		ans = dp[f];
	}
	return ans;
}
// bfs
int SortingGame::fewestMoves(vector <int> board, int k) {
	vector<int> f(board);
	sort(f.begin(), f.end());
	if (f == board) {
		return 0;
	}
	int n = board.size();
	map< vector<int>, int> m;
	queue< vector<int> > q;
	m[board] = 0;
	q.push(board);
	while (!q.empty()) {
		vector<int> v(q.front());
		q.pop();
		if (v == f) {
			return m[v];
		}
		vector<int> t(v);
		for (int i = 0; i < n - k + 1; i++) {
			reverse(t.begin() + i, t.begin() + i + k);
			if (m.find(t) == m.end()) {
				m[t] = m[v] + 1;
				q.push(t);
			}
			reverse(t.begin() + i, t.begin() + i + k);
		}
	}
	return -1;
}

// 440 2.2
// backtrack
vector<string> a;
bool v[50][50];
int n;
int m;
int go(int x, int y, int c) {
	if (a[x][y] == '*') {
		return c;
	}
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	int t = 0;
	for (int j = 0; j < 4; j++) {
		int e = x + dx[j];
		int f = y + dy[j];
		if (e >= 0 && e < n && f >= 0 && f < m && a[e][f] != 'X' && !v[e][f]) {
			t++;
		}
	}
	int d = (t > 1)? c + 1: c;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !v[nx][ny] && a[nx][ny] != 'X') {
			v[nx][ny] = true;
			int r = go(nx, ny, d);
			if (r != -1) {
				return r;
			}
			v[nx][ny] = false;
		}
	}
	return -1;
}
int MazeWanderingEasy::decisions(vector <string> maze) {
	memset(v, 0, sizeof(v));
	a = maze;
	n = maze.size();
	m = maze[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 'M') {
				v[i][j] = true;
				return go(i, j, 0);
			}
		}
	}
	return -1;
}






int ArcadeManao::shortestLadder(vector <string> level, int coinRow, int coinColumn) {
	int cr = coinRow - 1;
	int cc = coinColumn - 1;
	int n = level.size();
	int m = level[0].size();
	int inf = 1e9;
	vector< vector<int> > v(n, vector<int>(m, inf));
	for (int i = 0; i < m; i++) {
		v[n - 1][i] = 0;
	}
	while (true) {
		bool bo = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (level[i][j] == 'X' && v[i][j] != inf) {
					for (int k = 0; k < n - 1; k++) {
						if (level[k][j] == 'X') {
							int t = level[i][j] + abs(k - i);
							if () {
							
							}
						}
					}
				}
			}
		}
	}
}