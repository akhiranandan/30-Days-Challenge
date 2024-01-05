class DataStream {
private:
    int kk;
    int valuee;
    int count = 0;
public:
    DataStream(int value, int k) {
        valuee = value;
        kk = k;
    }
    
    bool consec(int num) {
        if(num == valuee)
        {
            count++;
            if(count >= kk) return true;
            else return false;
        }
        else 
        {
            count = 0;
            return false;
        }
    }
};