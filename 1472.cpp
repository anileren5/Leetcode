class BrowserHistory {
public:
    BrowserHistory(string homepage){
        current_page = homepage;
    }
    
    void visit(string url) {
        make_empty(forward_history);
        back_history.push(current_page);
        current_page = url;
    }
    
    string back(int steps) {
        int l = back_history.size();
        int n = (steps>l) ? l : steps;
        for (int i=0;i<n;i++) back_one(back_history,forward_history);
        return current_page;
    }
    
    string forward(int steps) {
        int l = forward_history.size();
        int n = (steps>l) ? l : steps;
        for (int i=0;i<n;i++) forward_one(back_history,forward_history);
        return current_page;
    }
    
    void make_empty(stack<string>& history){
        while (history.size() != 0) history.pop();
    }
    
    void back_one(stack<string>& back_history,stack<string>& forward_history){
        if (back_history.size() != 0){
            forward_history.push(current_page);
            current_page = back_history.top();
            back_history.pop();
        }
    }
    
    void forward_one(stack<string>& back_history,stack<string>& forward_history){
        if (forward_history.size() != 0){
            back_history.push(current_page);
            current_page = forward_history.top();
            forward_history.pop();
        }
    }
    
    
private:
    string current_page;
    stack<string> back_history;
    stack<string> forward_history;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */