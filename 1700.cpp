class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches){
        while(helper(students,sandwiches)){
            if (sandwiches[0] == students[0]){
                sandwiches.erase(sandwiches.begin()+0);
                students.erase(students.begin()+0);
            }
            else{
                students.push_back(students[0]);
                students.erase(students.begin()+0);
            }            
        }
        return students.size();
    }
    
    bool helper(vector<int>& students, vector<int>& sandwiches){
        if (students.size() == 0 or sandwiches.size() == 0) return false;
        for (auto student:students){
            if (student == sandwiches[0]){
                return true;
            }
        }
        return false;
    }
};