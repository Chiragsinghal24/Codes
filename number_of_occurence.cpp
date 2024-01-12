//coding ninjas

int leftmost(vector<int>&arr, int n ,int x, int low, int high){
	int ans=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==x){
			ans=mid;
			high=mid-1;
		}
		else if(arr[mid]<x){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
}

int rightmost(vector<int>&arr, int n ,int x, int low, int high){
	int ans=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==x){
			ans=mid;
			low=mid+1;
		}
		else if(arr[mid]<x){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
}


int count(vector<int>& arr, int n, int x) {
	//here for finding the total number of occurence we have to use the binary search
	//find the leftmost element
	//find the rightmost element
	//then minus the rightmost-leftmost gives the total number of occurence

	int low=0;
	int high=n-1;

	int value1=leftmost(arr,n,x,low,high);
	int value2=rightmost(arr,n,x,low,high);
	return value2-value1;
}
