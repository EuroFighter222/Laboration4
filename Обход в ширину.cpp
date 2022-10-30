#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

int** array_of_cotiguity(int** arr, int m) {
	cout << "Enter edge (not oriented):  " << endl;
	int v = 0;
	int u = 0;
	for (int i = 0; i < m; i++) {
		cin >> v >> u;
		arr[v - 1][u - 1] = 1;
		arr[u - 1][v - 1] = 1;
	}
	return arr;
}

int** create_array_2d(int n) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	return arr;
}

int* create_array_1d(int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	return arr;
}

void print_queue(queue<int> queue) {
	while (!queue.empty()) {
		int val = queue.front();
		cout << val + 1 << " ";
		queue.pop();
	}
	cout << endl;
}

void print_stack(stack<int> stack) {
	while (!stack.empty()) {
		int val = stack.top();
		cout << val + 1 << " ";
		stack.pop();
	}
	cout << endl;
}

void bfs(int** arr, int n) {
	int first_node = 0;
	cout << "Enter a pick to start with: ";
	cin >> first_node;
	cout << "Pick" << setw(15) << "BFS-number" << setw(10) << "Queue" << endl;
	int* used = create_array_1d(n);
	int k = 1;
	queue <int> q;
	used[--first_node] = 1;
	q.push(first_node);
	while (!q.empty()) {
		int node = q.front();
		for (int j = 0; j < n; j++) {
			if (arr[node][j] == 1 && used[j] == 0) {
				q.push(j);
				cout << j + 1 << setw(12) << ++k << setw(12);
				used[j] = 1;
				print_queue(q);
			}
		}
		q.pop();
		cout << "-" << setw(12) << "-" << setw(12);
		print_queue(q);
	}
}

void dfs(int** arr, int n) {
	int first_node = 0;
	cout << "Enter a pick to start with: ";
	cin >> first_node;
	cout << "Pick" << setw(15) << "DFS-number" << setw(10) << "Stack" << endl;
	int* used = create_array_1d(n);
	int k = 1;
	stack <int> stack;
	used[--first_node] = 1;
	stack.push(first_node);
	while (!stack.empty()) {
		int node = stack.top();
		for (int j = 0; j < n; j++) {
			if (arr[node][j] == 1 && used[j] == 0) {
				stack.push(j);
				cout << j + 1 << setw(12) << ++k << setw(12);
				used[j] = 1;
				print_stack(stack);
			}
		}
		stack.pop();
		cout << "-" << setw(12) << "-" << setw(12);
		print_stack(stack);
	}
}

int main() {
	int n = 0;
	int m = 0;
	cout << "Enter number of picks: ";
	cin >> n;
	cout << "Enter number of edges: ";
	cin >> m;

	int** arr = create_array_2d(n);
	array_of_cotiguity(arr, m);

	cout << "Wedth: " << endl;
	bfs(arr, n);
	cout << endl << endl;
	cout << "Depth: " << endl;
	dfs(arr, n);

	return 0;
}
