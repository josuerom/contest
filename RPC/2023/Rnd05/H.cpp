#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_peak_height(const vector<int>& h) {
    int n = h.size();
    int i = 0;
    int j = n - 1;
    while (i < n - 1 && h[i] <= h[i+1]) {
        i++;
    }
    while (j > 0 && h[j] <= h[j-1]) {
        j--;
    }
    int max_altura = 0;
    if (i != j) {
        int max_derecha = *max_element(h.begin()+i+1, h.end());
        int min_izquierda = *min_element(h.begin(), h.begin()+j);
        max_altura = max(0, max_derecha - min_izquierda);
    }
    return max_altura;
}

int main() {
    int n1, n2;
    cin >> n1;
    vector<int> h1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> h1[i];
    }
    cin >> n2;
    vector<int> h2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> h2[i];
    }
    int max_peak1 = calculate_peak_height(h1);
    int max_peak2 = calculate_peak_height(h2);
    cout << max_peak1 " " << max_peak2 << '\n';
    return 0;
}