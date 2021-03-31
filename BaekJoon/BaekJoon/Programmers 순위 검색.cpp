#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

map<string, int> lang, job, year, food;
map<string, int> qlang, qjob, qyear, qfood;

vector<int> solution(vector<string> info, vector<string> query) {
    lang["cpp"] = 0, lang["java"] = 1, lang["python"] = 2;
    job["backend"] = 0, job["frontend"] = 1;
    year["junior"] = 0, year["senior"] = 1;
    food["chicken"] = 0, food["pizza"] = 1;
    qlang["-"] = -1,qlang["cpp"] = 0, qlang["java"] = 1, qlang["python"] = 2;
    qjob["-"] = -1,qjob["backend"] = 0, qjob["frontend"] = 1;
    qyear["-"] = -1,qyear["junior"] = 0, qyear["senior"] = 1;
    qfood["-"] = -1,qfood["chicken"] = 0, qfood["pizza"] = 1;
    vector<int> answer;
    struct Info { int l, j, y, f; int score; };
    struct Query { int l, j, y, f; int score; };
    vector<Info> v;
    for (auto& now : info) {
        Info cur;
        stringstream ss;
        string nl, nj, ny, nf;
        ss << now;
        string nows[4];
        int i = 0;
        ss >> nl >> nj >> ny >> nf;
        cur.l = lang[nl]; 
        cur.j =  job[nj]; 
        cur.y = year[ny];
        cur.f = food[nf];
        ss >> cur.score;
        v.push_back(cur);
    }

    vector<Query> q;
    for (auto& now : query) {
        Query cur;
        stringstream ss;
        string nl, nj, ny, nf;
        ss << now;
        string nows[6];
        int i = 0;
        while (ss >> nows[i]) {
            if (nows[i] == "and") continue;
            else i++;
        }
        cur.l = qlang[nows[0]];
        cur.j =  qjob[nows[1]];
        cur.y = qyear[nows[2]];
        cur.f = qfood[nows[3]];
        cur.score = stoi(nows[4]);
        q.push_back(cur);
    }
    vector<int> ans[3][2][2][2];
    for (auto& now : v) ans[now.l][now.j][now.y][now.f].push_back(now.score);
    for (int l = 0; l < 3;l++)for (int j = 0; j < 2;j++)for (int y = 0; y < 2;y++)for (int f = 0; f < 2;f++) {
        sort(ans[l][j][y][f].begin(), ans[l][j][y][f].end());
    }
    for (auto& now : q) {
        int answer1 = 0;
        for (int l = (now.l == -1 ? 0 : now.l); l <= (now.l == -1 ? 2 : now.l);l++) {
            for (int j = (now.j == -1 ? 0 : now.j);j <= (now.j == -1 ? 1 : now.j);j++) {
                for (int y = (now.y == -1 ? 0 : now.y); y <= (now.y == -1 ? 1 : now.y);y++) {
                    for (int f = (now.f == -1 ? 0 : now.f); f <= (now.f == -1 ? 1 : now.f);f++) {
                        answer1 += ans[l][j][y][f].size() - (lower_bound(ans[l][j][y][f].begin(), ans[l][j][y][f].end(), now.score) - ans[l][j][y][f].begin());
                    }
                }
            }
        }
        answer.push_back(answer1);        
    }
    for (auto now : answer) cout << now << " ";
    return answer;
}

int main() {
    //vector<int> solution(vector<string> info, vector<string> query) 
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    solution(info, query);
    return 0;
}