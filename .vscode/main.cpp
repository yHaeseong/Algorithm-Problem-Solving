#include <bits/stdc++.h>

using namespace std;



struct Practice{
    int a, b;
    double c, d, e;
};

void print(Practice prac){
    cout << prac.a << " " << prac.b << " " << prac.c << " " << prac.d << " " << prac.e << "\n";
}

int main(){
    Practice prac = {1, 1, 1, 1, 1};
    print(prac);
    vector<Practice> ret;
    ret.push_back({1,2,3,4,5});
    ret.push_back({1,2,3,4,6});
    ret.push_back({});
    ret.push_back({1,3});
    for (Practice prac : ret){
        print(prac);
    }
    return 0;
}

struct Point{
    int y, x;
    Point(int y, int x) : y(y), x(x){}
    Point(){y = -1; x = -1; }
    bool operator < (const Point & a) const{
        if ( x == a.x) return y < a.y;
        return x < a.x;
    }
}

// String 배열 정렬

bool compare(string a, string b){
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a[3] = {"111", "222", "33"};
    sort(a, a+3, compare);
    for(string b:a) cout << b << " ";
    return 0;
}

//Practice Struct sorting with Compare function

struct Practice{
    int a, b;
};

bool compare(Practice A, Practice B){
    if (A.a == B.b) return A.a < B.b;
    return A.a < B.b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Practice a[3] = {{1, 2}, {1, 3}, {0, 4}};
    sort(a, a + 3, compare);

    for (Practice A : a) cout << A.a << " : " << A.b << "\n";
    return 0;
}

//3 values sorting
struct Point{
    int y, x, z;
    Point(int y, int x, int z) : y(y), x(x), z(z){}
    Point(){y = -1; x = -1; z = -1;
    bool operator < (const Point & a) const{
        if ( x == a.x) {
            if ( y == a.y) return z < a.z;
            return y > a.y;
        }
        return x < a.x;
    }
}


//Sorting vector with struct 
struct Point{
    int y, x;
};

bool cmp(const Point &a, const Point &b){
    return a.x > b.x;
}

vector<Point> v;

int main(){
    for (int i = 10; i >= 1; i--){
        v.push_back({i, 10- i });
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v) cout << it.y << " : " << it.x << "\n";
        return 0;
}

// Priority Queue

priority_queue<int, vector<int>, greater<int> > pq; // Increasing Order
priority_queue<int> pq2; // decreasing order
priority_queue<int, vector<int>, less<int>> pq3; // decreasing order


int main(){
    for (int i = 5; i >= 1; i--){
        pq.push(i), pq2.push(i), pq3.push(i);
    }

    while (pq.size()){
        cout << pq.top() << " : " << pq2.top() << " : " << pq3.top() << "\n";
        pq.pop(); pq2.pop(); pq3.pop();
    }
    return 0;
}


// Priority Queue with Struct
struct Point{
    int y, x;
    Point(int y, int x) : y(y), x(x){}
    Point(){y = -1; x = -1;}
    bool operator < (const Point & a) const{
        return x > a.x;
    }
};

priority_queue<Point> pq;
int main(){
    pq.push({1, 1});
    pq.push({2, 2});
    pq.push({3, 3});
    pq.push({4, 4});
    pq.push({5, 5});
    pq.push({6, 6});
    cout << pq.top().x << "\n";
    return 0;
}

// 2차원 배열 수정하기

vector<vector<int>> v;
vector<vector<int>> v2(10, vector<int>(10, 0));
vector<int> v3[10];

void go(vector<vector<int>> &v){
    v[0][0] = 100;
}

void go2(vector<vector<int>> &v){
    v[0][0] = 100;
}

void go3(vector<int> v[10]){
    v[0][0] = 100;
}

int main(){
    vector<int> temp;
    temp.push_back(0);
    v.push_back(temp);

    v3[0].push_back(0);

    go(v); go1(v2) ; go3(v3);
    cout << v[0][0] << " : " << v2[0][0] << " : " << v3[0][0] << "\n";
    return 0;
}

// 1차원 배열은 rotate 활용
// 2차원 배열은 array로는 만만치 않음 -> vector로 해야함

const int n = 3;
const int m = 4;

void rotate_left_90(vector<vector<int>> &key){
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> temp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            temp[i][j] = key[j][i-m-1];
        }
    }
    key.resize(m);
    key[0].resize(n);

    key = temp;
    return;
}

void rotate_right_90(vector<vector<int>> &key){
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> temp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            temp[i][j] = key[n-j-1][i];
        }
    }
    key.resize(m);
    key[0].resize(n);

    key = temp;
    return;
}


// Map : 고유한 키를 기반으로 키 - 값 정렬된(삽입할때마다 자동 정렬된) 
// 레드 블랙 트리로 구현 -> 삽입, 삭제, 수정, 탐색 O(logN) 시간 복잡도

// 고유한 키를 갖기 때문에 하나의 키에 중복된 값이 들어갈수 없음
// 자동으로 오름차순 정렬 -> 순서대로 탐색 불가능 -> 아스키코드순 정렬 탐색




// mp에 해당 키가 없다면 0으로 초기화되어 할당됨 -> mp에 해당 키 유무 확인, 0으로 할당 x 
// Find 사용

class Node{
    public:
    
    int data;
    Node* next;
    Node(){
        data = 0;
        next = 0;
    }

    Node(int data){
        this -> data = data;
        this -> next = 0;
    }
}

// Doubly Linked List with list

#include <bits/stdc++.h>

using namespace std;

list<int> a;

void print(list <int> a){
    for (auto it : a) cout << it << " ";
    cout << "\n";
}

int main(){
    for (int i = 1; i <= 3; i++) a.push_back(i);
    for (int i = 1; i <= 3; i++) a.push_front(i);

    auto it = a.begin(); it++;
    a.insert(it, 1000);
    print(a);

    it = a.begin(); it++;
    a.erase(it);
    print(a);


    a.pop_front();
    a.pop_back();
    print(a);

    cout << a.front() << ":" << a.back() << "\n";
    a.clear();
    return 0; 
}

map<string, int> mp;
string a[] = {"주홍철", "이승철", "박종선"};

int main(){
    for (int i = 0; i < 3; i++){
        mp.insert({a[i], i+1});
        mp[a[i]] = i+1; 
    }

    cout << mp["kundol"] << "\n";
    mp["kundol"] = 4;

    cout << mp.size() << "\n";
    mp.erase("kundol");

    auto it = mp.find("kundol");
    if (it == mp.end()){
        cout << "There does not exists what you want. \n"; 
    }

    mp["kundol"] = 100;

    it = mp.find("kundol");

    if(it != mp.end()){
        cout << (*it).first << " : " << (*it).second << "\n";
    }

    for (auto it:mp){
        cout << (it).first << " : " << (it).second << "\n";
    }

    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << (*it).first << " : " << (*it).second << "\n";
    }
    return 0;
}

//Stack
stack<string> stk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stk.push("A");
    stk.push("B");
    stk.push("C");
    stk.push("D");
    stk.push("E");
    stk.push("F");

    while(stk.size()){
        cout << stk.top() << "\n";
        stk.pop(); 
    }
}


queue<int> q;

int main(){
    for (int i = 1; i <= 10; i++){
        q.push(i);
    }

    while(q.size()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}


int main(){
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);
    cout << dq.front() << "\n";
    cout << dq.end() << "\n";
    cout << dq.size() << "\n";
    dq.pop_back();
    dq.pop_front();
    cout << dq.size() << "\n";
    return 0;
}



// 큰돌 2주차 복습 노트

// Q1) 3 -> 5번으로 가는 경로
a[3][5] = 1;

// Q2) 3 <-> 5 양방향 경로
a[3][5] = 1;
a[5][3] = 1;

// Q3) 정점의 갯수 20개인 graph, 메모리 최소로 사용 -> 인접행렬
bool a[20][20];

// Q4) 1 -> 2, 1 -> 3, 3 -> 4 그래프, 
// 1. 0번 부터 탐색, 2. 0번 부터 방문 안한 노드 찾고, 연결된 노드 이어서 방문하고 출력, 재귀함수, 방문한 노드 다시 방문 x


#include <bits/stdc++.h>

using namespace std;

const int v = 10;
bool a[v][v], visited[v];

void go(int from){
    visited[from] = 1;
    for (int i = 0; i < v; i++){
        if (visited[i]) continue;
        if (a[from]) go(i);
    }
    return;
}

int main(){
    a[1][2] = 1;
    a[1][3] = 1;
    a[3][4] = 1;

    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if (a[i][j] && visited[i] == 0){
                go[i];
            }
        }
    }
}


// 2-5) 인접리스트 Vector로 구현!, list와 비교해서 복사해야 하기 때문에, n번째 인덱스 삽입, 삭제는 O(n)이 걸림
// 하지만 그래프 문제는 대부분 '참조'를 해야하기 때문에, n번째 요소 탐색 O(1)인 vector를 사용

const int v = 4;
vector<int> adj[v];

int main(void){
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(1);
    adj[2].push_back(0);

    adj[3].push_back(0);

    for (int i = 0; i < 4; i++){
        cout << i << "\n";
        for (int there:adj[i]){
            cout << there << " ";
        }
        cout << "\n";
    }
}



