// 701 2.1
// recursion, which is not neccessary
string ss;
int c[51][51];
bool run(int start, int end) {
	if (c[start][end] != -1) {
		return c[start][end];
	}
	if ((end - start) % 2 == 0) {
		int m = (start + end) / 2;
		if (ss.substr(start, m - start) == ss.substr(m, end - m)) {
			return c[start][end] = true;
		}
	}
	for (int i = start + 1; i < end; ++i) {
		if (run(start, i) || run(i, end)) {
			return c[start][end] = true;
		}
	}
	return c[start][end] = false;
}
string SquareFreeString::isSquareFree(string s) {
	ss = s;
	for (int i = 0; i < 51; ++i) {
		for (int j = 0; j < 51; ++j) {
			c[i][j] = -1;
		}
	}
	return run(0, s.size())? "not square-free": "square-free";
}
// all substring
string SquareFreeString::isSquareFree(string s) {
	
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i; j < s.size(); ++j) {
			if ((j - i + 1) % 2 == 1) {
				continue;
			}
			int n = (j + 1 + i) / 2;
			if (s.substr(i, n - i) == s.substr(n, j + 1 - n)) {
				return "not square-free";
			}
		}
	}
	return "square-free";
}


string Ropestring::makerope(string s) {
	int c = 0;
	vector<int> ens;
	vector<int> ons;
	int ds = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '-') {
			++c;
		} else {
			if (c != 0) {
				if ((c % 2) == 0) {
					ens.push_back(c);
				} else {
					ons.push_back(c);
				}
			}
			c = 0;
			++ds;
		}
	}
	if (c != 0) {
		if ((c % 2) == 0) {
			ens.push_back(c);
		} else {
			ons.push_back(c);
		}
	}
	sort(ens.rbegin(), ens.rend());
	sort(ons.rbegin(), ons.rend());
	string ans;
	for (int i = 0; i < ens.size(); ++i) {
		ans += string("-", ens[i]);
		if (ds > 0) {
			ans += ".";
			--ds;
		}
	}
	for (int i = 0; i < ons.size(); ++i) {
		ans += string("-", ons[i]);
		if (ds > 0) {
			ans += ".";
			--ds;
		}
	}
	ans += string(".", ds);
	return ans;
}


int EqualSubstrings2::get(string s) {
	map<string, vector<pair<int, int> > > m;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i; j < s.size(); ++j) {
			pair<int, int> p = make_pair(i, j + 1);
			string ss = s.substr(i, j + 1 - i);
			map<string, vector<pair<int, int> > >::iterator it = m.find(ss);
			if (it != m.end()) {
				it->second.push_back(p);
			} else {
				vector<pair<int, int> > v;
				v.push_back(p);
				m.insert(make_pair(ss, v));
			}
		}
	}
	int ans = 0;
	for (map<string, vector<pair<int, int> > >::iterator it = m.begin(); it != m.end(); ++it) {
		vector<pair<int, int> > &v = it->second;
		for (int i = 0; i < v.size(); ++i) {
			for (int j = i + 1; j < v.size(); ++j) {
				if (v[i].first >= v[j].second || v[i].second <= v[j].first) {
					++ans;
				}
			}
		}
	}
	return ans;
}

// 628 2.2
// you can also use stack data structure for checking matching brackets, which is the classic application
string s;
bool p(char a, char b) {
	return (a == 'X' && b == 'X') || (a == 'X' && (b == ']' || b == ')' || b == '}')) || ((a == '{' || a == '(' || a == '[') && b == 'X') || (a == '[' && b == ']') || (a == '(' && b == ')') || (a == '{' && b == '}');
}
bool run(int a, int b) {
	if (a == b) {
		return true;
	}
	if ((b - a) % 2 != 0) {
		return false;
	}
	for (int i = a + 1; i < b; ++i) {
		if (p(s[a], s[i]) && run(a + 1, i) && run(i + 1, b)) {
			return true;
		}
	}
	return false;
}
string BracketExpressions::ifPossible(string expression) {
	s = expression;
	return run(0, s.size())? "possible": "impossible";
}

// 
string s;
char next(char a) {
	return a == 'R'? 'G': a == 'G'? 'B': a == 'B'? 'R': -1;
}
int run(int a) {
	if (a == s.size() - 1) {
		return 0;
	}
	int c = 999999999;
	for (int i = a + 1; i < s.size(); ++i) {
		if (s[i] == next(s[a])) {
			c = min(c, (i - a) * (i - a) + run(i));
		}
	}
	return c;
}
int ColorfulRoad::getMin(string road) {
	s = road;
	int ans = run(0);
	if (ans == 999999999) {
		return -1;
	}
	return ans;
}


vector<string> a;
int run(int t, int y, int n, int k) {
	if (k == a.size()) {
		if (t == 0) {
			return 1;
		} else {
			return 0;
		}
	}
	bool yes = a[k] == "Yes";
	int u = 0;
	if (t > 0) {
		u += t * run(t - 1, y + yes, n + !yes, k + 1);
	}
	if (y > 0 && yes) {
		u += y * run(t, y, n, k + 1);
	}
	if (n > 0 && !yes) {
		u += n * run(t, y, n, k + 1);
	}
	return u;
}
int TheQuestionsAndAnswersDivOne::find(int questions, vector <string> answers) {
	a = answers;
	return run(questions, 0, 0, 0);
}

// 422 2.2
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
double go(int n, int g, double s) {
	if (n == 0) {
		if (isp(g)) {
			return 1;
		} else {
			return 0;
		}
	}
	double u = 0;
	u += s * go(n - 1, g + 1, s);
	u += (1 - s) * go(n - 1, g, s);
	return u;
}
double PrimeSoccer::getProbability(int skillOfTeamA, int skillOfTeamB) {
	return 1 - (1 - go(18, 0, skillOfTeamA / 100.)) * (1 - go(18, 0, skillOfTeamB / 100.));
}

// 612 2.2
int inf = 1e9;
int s;
int go(int c, int n) {
	if (n == s) {
		return 0;
	}
	if (n > s) {
		return inf;
	}
	int u = inf;
	u = min(u, go(n, n + n) + 2);
	u = min(u, go(c, n + c) + 1);
	return u;
}
int EmoticonsDiv2::printSmiles(int smiles) {
	s = smiles;
	return go(1, 1) + 1;
}

// 557 1.1
string FoxAndMountainEasy::possible(int n, int h0, int hn, string history) {
	int hs = history.size();
	int climb = 0;
	int low = 0;
	for (int i = 0; i < hs; ++i) {
		climb += (history[i] == 'D')? -1: 1;
		low = min(low, climb);
	}
	int start = -low;
	int end = climb - low;
	for (int i = 0; i < n - hs + 1; ++i) {
		for (int j = 0, new_start = j + start, new_end = j + end; new_start <= i || new_end <= n - i - hs + 1; ++j) {
			if () {
			
			}
		}
	}
	
	n -= history.size();
	h0 += climb;
	cout << n << ' ' << h0 << ' ' << hn << endl;
	int height = abs(hn - h0);
	cout << height << ' ' << n << endl;
	if (height > n || (n + height) % 2 != 0) {
		return "NO";
	}
	return "YES";
}

// 533 1.1
// this is wrong, but hard to notice
// problem is, we use "function call stack" to cashe the answer, ie. not pass value to final loop, instead use "go() + something"
// but we terminate it base on next loop, so sometimes "something" should not be added, so will result in wrong answer
vector<int> w;
int go(int start, int end) {
	if (end - start == 1) {
		return 0;
	}
	int u = 0;
	for (int i = start + 1; i < end; ++i) {
		u = max(u, go(start, i) + go(i, end) + w[start] * w[i] + w[i] * w[end]);
	}
	return u;
}
int CasketOfStar::maxEnergy(vector <int> weight) {
	w = weight;
	return go(0, w.size() - 1) + w[0] * w[w.size() - 1];
}


int inf = 1e9;
int bound;
int go(int left, int cds) {
	if (left < 0) {
		return inf;
	} else if (left == 0) {
		if (cds % 13 == 0) {
			return inf;
		} else {
			return cds;
		}
	}
	int u = inf;
	for (int i = 1; i <= bound; ++i) {
		u = min(u, go(left - i, cds + 1));
	}
	return u;
}
int leastAmountOfCDs(int nSongs, int length, int cdCapacity) {
	bound = min(0, nSongs - length) / (length + 1) + 1;
	return go(nSongs, 0);
}