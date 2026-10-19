class RecentCounter {

    int[] a = new int[10001]; 
    int l = 0, r = 0;

    public RecentCounter() {
        
    }
    
    public int ping(int t) {
        a[r++] = t;

        while(a[l] < t - 3000){
            l++;
        }
        return r - l;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */