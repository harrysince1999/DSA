class BrowserHistory {
public:
    vector<string> v;
    int c;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        c=0;
    }
    
    void visit(string url) {
        int l = v.size()-1;
        while(l>c)
        {
            v.pop_back();
            l--;
        }
        c++;
        v.push_back(url);
    }
    
    string back(int steps) {
        c-= steps;
        if(c<0) c=0;
        return v[c];
    }
    
    string forward(int steps) {
        c+= steps;
        if(c>=v.size()) c= v.size()-1;
        return v[c];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */