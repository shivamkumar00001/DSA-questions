pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	
        int l=0;
		int r=n-1;

        int mid ; 
        
		int floor=-1;
		int ceil=-1;
        while(l<=r){

			 mid=(l+r)/2;
             
			 if(x==a[mid]){
				 floor=x;
				 ceil=x;
				 break;
			 }
			 else if(x<a[mid]){
				 ceil=a[mid];
				 r=mid-1;
			 }
			 else if(x>a[mid]){
				 floor=a[mid];
				 l=mid+1;
			 }
		}  


		return make_pair(floor, ceil); 

	
} 
