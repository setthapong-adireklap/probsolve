#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &bookPrice, int target){
    
    int i = 0 , j = bookPrice.size();
    int currPos = i + (j-i)/2, lastPos = -1 , target_pos = 0;

    while(currPos!=lastPos){
        if(target > bookPrice[currPos]){
            target_pos = currPos;
            i = currPos;
        }
        else if(target < bookPrice[currPos]){
            j = currPos;
        }
        else{
            return currPos+1;
        }
        lastPos = currPos;
        currPos = i + (j-i)/2;
    }
    return (target >= bookPrice[currPos])? target_pos+1 : currPos;
}

int main(){

    int n,k;
    cin >> n >> k;
    
    int temp;
    vector<int> bookPrice;
    for(int i = 0 ; i<n ; i++){
        cin >> temp;
        if(i==0){
            bookPrice.push_back(temp);
        }
        else{
            bookPrice.push_back(temp+bookPrice[i-1]);
        }
    }
    
    int target;
    for(int i = 0 ; i<k ; i++){
        cin >> target;
        cout << binarySearch(bookPrice,target) << endl;
    }
    
    return 0;
}