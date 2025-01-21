#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> w;
    int n;

    cout << "Podaj rozmiar wektora: ";
    cin >> n;
    w.resize(n, 0);

    cout << "vector w: \n";
    for (int i = 0; i < w.size(); i++) {
        w[i]=i;
        cout << w[i] << " ";
    }
w.push_back(14);
cout<<"\n po dodaniu elementu: \n";
for(int i =0; i<w.size();i++){
    cout<<w[i]<<" ";
}
    cout<<"\n"<<w.back();
    return 0;
}
