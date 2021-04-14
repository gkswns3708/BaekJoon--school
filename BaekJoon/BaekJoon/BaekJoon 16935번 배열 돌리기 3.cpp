#include<iostream>
#include<vector>

#define endl "\n"
#define MAX 100
using namespace std;

int N, M, K;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
vector<int> V;

void Input()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int a; cin >> a;
        V.push_back(a);
    }
}

void Print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}

void Copy_MAP(int A[][MAX], int B[][MAX])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = B[i][j];
        }
    }
}

void Cmd_One()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            C_MAP[N - i - 1][j] = MAP[i][j];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

void Cmd_Two()
{
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            C_MAP[i][M - 1 - j] = MAP[i][j];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

void Cmd_Three()
{
    int NN = N;
    swap(N, M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            C_MAP[i][j] = MAP[NN - 1 - j][i];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

void Cmd_Four()
{
    int MM = M;
    swap(N, M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            C_MAP[i][j] = MAP[j][MM - 1 - i];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

void Cmd_Five()
{
    int Half_N = N / 2;
    int Half_M = M / 2;

    /* 1번을 2번으로 */
    for (int i = 0; i < Half_N; i++)
    {
        for (int j = 0; j < Half_M; j++)
        {
            C_MAP[i][j + Half_M] = MAP[i][j];
        }
    }

    /* 2번을 3번으로 */
    for (int i = 0; i < Half_N; i++)
    {
        for (int j = Half_M; j < M; j++)
        {
            C_MAP[i + Half_N][j] = MAP[i][j];
        }
    }

    /* 3번을 4번으로 */
    for (int i = Half_N; i < N; i++)
    {
        for (int j = Half_M; j < M; j++)
        {
            C_MAP[i][j - Half_M] = MAP[i][j];
        }
    }

    for (int i = Half_N; i < N; i++)
    {
        for (int j = 0; j < Half_M; j++)
        {
            C_MAP[i - Half_N][j] = MAP[i][j];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

void Cmd_Six()
{
    int Half_N = N / 2;
    int Half_M = M / 2;

    /* 1번을 4번으로 */
    for (int i = 0; i < Half_N; i++)
    {
        for (int j = 0; j < Half_M; j++)
        {
            C_MAP[i + Half_N][j] = MAP[i][j];
        }
    }

    /* 4번을 3번으로 */
    for (int i = Half_N; i < N; i++)
    {
        for (int j = 0; j < Half_M; j++)
        {
            C_MAP[i][j + Half_M] = MAP[i][j];
        }
    }

    /* 3번을 2번으로 */
    for (int i = Half_N; i < N; i++)
    {
        for (int j = Half_M; j < M; j++)
        {
            C_MAP[i - Half_N][j] = MAP[i][j];
        }
    }

    /* 2번을 1번으로 */
    for (int i = 0; i < Half_N; i++)
    {
        for (int j = Half_M; j < M; j++)
        {
            C_MAP[i][j - Half_M] = MAP[i][j];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

void Solution()
{
    for (int i = 0; i < V.size(); i++)
    {
        int Cmd = V[i];
        if (Cmd == 1) Cmd_One();
        else if (Cmd == 2) Cmd_Two();
        else if (Cmd == 3) Cmd_Three();
        else if (Cmd == 4) Cmd_Four();
        else if (Cmd == 5) Cmd_Five();
        else Cmd_Six();
    }
    Print();
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
//얍문에게 엄지척
