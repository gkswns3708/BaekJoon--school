#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int SZ = 1 << 20;

class INPUT {
private:
	char read_buf[SZ];
	int read_idx, next_idx;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
	bool is_blank(char c) { return c == ' ' || c == '\n'; }
	bool is_end(char c) { return c == '\0'; }
	char _readChar() {
		if (read_idx == next_idx) {
			next_idx = fread(read_buf, sizeof(char), SZ, stdin);
			if (next_idx == 0) return 0;
			read_idx = 0;
		}
		return read_buf[read_idx++];
	}
	char readChar() {
		char ret = _readChar();
		while (is_blank(ret)) ret = _readChar();
		return ret;
	}
	template<typename T>
	T _readInt() {
		T ret = 0;
		char cur = _readChar();
		bool flag = 0;
		while (is_blank(cur)) cur = _readChar();
		if (cur == '-') flag = 1, cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret = 10 * ret + cur - '0', cur = _readChar();
		if (is_end(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	int readInt() { return _readInt<int>(); }
	long long readLL() { return _readInt<long long>(); }
	string readString() {
		string ret;
		char cur = _readChar();
		while (is_blank(cur)) cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret.push_back(cur), cur = _readChar();
		if (is_end(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double readDouble() {
		string ret = readString();
		return stod(ret);
	}
	string getline() {
		string ret;
		char cur = _readChar();
		while (cur != '\n' && !is_end(cur)) ret.push_back(cur), cur = _readChar();
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (is_end(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { bflush(); }
	template<typename T>
	int getSize(T n) {
		int ret = 1;
		if (n < 0) n = -n;
		while (n >= 10) ret++, n /= 10;
		return ret;
	}
	void bflush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	void writeChar(char c) {
		if (write_idx == SZ) bflush();
		write_buf[write_idx++] = c;
	}
	void newLine() { writeChar('\n'); }
	template<typename T>
	void _writeInt(T n) {
		int sz = getSize(n);
		if (write_idx + sz >= SZ) bflush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz - 1; i >= 0; i--) write_buf[write_idx + i] = n % 10 + '0', n /= 10;
		write_idx += sz;
	}
	void writeInt(int n) { _writeInt<int>(n); }
	void writeLL(long long n) { _writeInt<long long>(n); }
	void writeString(string s) { for (auto& c : s) writeChar(c); }
	void writeDouble(double d) { writeString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.readChar(); return in; }
INPUT& operator>> (INPUT& in, int& i) { i = in.readInt(); return in; }
INPUT& operator>> (INPUT& in, long long& i) { i = in.readLL(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.readString(); return in; }
INPUT& operator>> (INPUT& in, double& i) { i = in.readDouble(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.writeChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, int i) { out.writeInt(i); return out; }
OUTPUT& operator<< (OUTPUT& out, long long i) { out.writeLL(i); return out; }
OUTPUT& operator<< (OUTPUT& out, size_t i) { out.writeInt(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.writeString(i); return out; }
OUTPUT& operator<< (OUTPUT& out, double i) { out.writeDouble(i); return out; }

/* macros */
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT

vector<int> edge[10000 + 1];
int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < M;i++) {
		int from, to; cin >> from >> to;
		edge[to].push_back(from);
	}

	auto BFS = [&](int st) -> int {
		bool visited[10000 + 1] = { 0, };
		int cnt = 1;
		queue<int> que;
		visited[st] = 1;
		que.push(st);
		while (!que.empty()) {
			auto now = que.front();
			que.pop();
			for (auto nxt : edge[now]) {
				if (visited[nxt]) continue;
				que.push(nxt);
				visited[nxt] = 1;
				cnt++;
			}
		}
		return cnt;
	};
	vector<int> vec;
	int ans = 0;
	for (int i = 1; i <= N;i++) {
		int now = BFS(i);
		if (ans < now) vec.clear(), vec.push_back(i), ans = now;
		else if (ans == now) vec.push_back(i);
	}
	sort(vec.begin(), vec.end());
	for (auto now : vec) cout << now << " ";
	return 0;
}