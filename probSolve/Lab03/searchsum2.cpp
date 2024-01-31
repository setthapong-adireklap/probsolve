#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findMinPrice(vector<int> &minPrice ,vector<int> &bookPrice, int n){
    int minP;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n-i ; j++){
            if(j == 0){
                minP = bookPrice[j+i];
            }
            else{
                minP = min(bookPrice[j+i]-bookPrice[j-1],minP);
            }
        }
        minPrice.push_back(minP);
    }
}

int findMaxBook(vector<int> &minPrice,int target){
    
    vector<int>::iterator it = lower_bound(minPrice.begin(),minPrice.end(),target);
    int maxBook = it - minPrice.begin();
    
    if(it == minPrice.end()){
        return maxBook;
    }
    else{
        if(target >= *it){
            return maxBook+1;
        }
    }
    return maxBook;
}

int main(){

    int n,k;
    cin >> n >> k;
    
    int temp, sumPrice = 0;
    vector<int> bookPrice;
    for(int i = 0 ; i<n ; i++){
        cin >> temp;
        sumPrice += temp;
        bookPrice.push_back(sumPrice);
    }

    int target;
    vector<int> minPrice;

    findMinPrice(minPrice,bookPrice,n);

    for(int i = 0 ; i<k ; i++){
        cin >> target;
        cout << findMaxBook(minPrice,target) << endl;
    }
    
    return 0;
}